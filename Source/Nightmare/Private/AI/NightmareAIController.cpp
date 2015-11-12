// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "NightmarePawn.h"
#include "AI/NightmareAIController.h"
#include "AI/NightmareAIAction.h"
#include "AI/NightmareAIAction_Patrol.h"
#include "AI/NightmareAISensingComponent.h"
#include "Pawn/NightmareCreaturePawn.h"
#include "GameFramework/CharacterMovementComponent.h"

ANightmareAIController::ANightmareAIController() : Super()
{
	// Construct Allowed Actions
	ConstructStandardActions();
	CurrentAction = nullptr;
	AllActions.Reserve(2);
	// Currently does nothing - we are deaf for now
	SensingComponent = CreateDefaultSubobject<UNightmareAISensingComponent>(TEXT("Sensing Component"));
}

void ANightmareAIController::ConstructStandardActions()
{
	// TODO - Move this to subclasses
	// Base class should do nothing!
	StandardActions.Add(UNightmareAIAction_Patrol::StaticClass());
}

void ANightmareAIController::Possess(APawn* inPawn)
{
	Super::Possess(inPawn);
	// Create the actual actions
	AllActions.Reset();
	for (auto ActionClass : StandardActions)
	{
		UNightmareAIAction* Action = NewObject<UNightmareAIAction>(this, ActionClass);
		ensure(Action);
		Action->SetController(this);
		AllActions.Add(Action);
	}
	InitialzieMovement(GetPawn());
	// Hack to test
	CurrentAction = AllActions[0];
	if (CurrentAction != nullptr)
	{
		CurrentAction->ExecuteAIAction();
	}

	// Start ticking
	SetActorTickEnabled(true);
}

void ANightmareAIController::InitialzieMovement(APawn* InPawn)
{
	ANightmareCreaturePawn* CreaturePawn = Cast<ANightmareCreaturePawn>(InPawn);
	if (CreaturePawn != nullptr)
	{
		UCharacterMovementComponent* PawnMovement = CreaturePawn->GetCharacterMovement();
		if (PawnMovement != nullptr)
		{
			PawnMovement->SetMovementMode(MOVE_Flying);
		}
	}

}

void ANightmareAIController::UnPossess()
{
	Super::UnPossess();
}

void ANightmareAIController::Tick(float DeltaTime)
{
	ANightmarePawn* MyPawn = Cast<ANightmarePawn>(GetPawn());
	if (MyPawn == nullptr || MyPawn->GetHealth() < 0.f)
	{
		SetActorTickEnabled(false);
		return;
	}

	Super::Tick(DeltaTime);

	UNightmareAIAction* NewAction = PickBestAction();

	if (!NewAction->IsValidLowLevel())
	{
		UE_LOG( NightmareAI, Warning, TEXT("My action suddenly becomes invlid at %f"), GetWorld()->GetTimeSeconds());
	}

	if (NewAction != nullptr && NewAction->IsValidLowLevel())
	{
		// If we just finished the previous action
		if (CurrentAction == nullptr || !CurrentAction->IsValidLowLevelFast())
		{
			CurrentAction = NewAction;
			CurrentAction->ExecuteAIAction();
		}
		else if (CurrentAction->GetAIActionPriority() < NewAction->GetAIActionPriority())
		{
			if (CurrentAction->IsSafeToAbort())
			{
				CurrentAction->AbortAction();
				CurrentAction = NewAction;
				CurrentAction->ExecuteAIAction();
			}
		}
	}

	//if (CurrentAction != nullptr && !CurrentAction->TickAIAction(DeltaTime))
	//{
	//	// Abort this action
	//	CurrentAction = nullptr;
	//}
	//// Set up new action
	//if (true)
	//{
	//	PickNewAction();
	//}
	//// What to do next?
	//SenseAndSelectTartget();
}

void ANightmareAIController::SenseAndSelectTartget()
{

}

UNightmareAIAction* ANightmareAIController::PickBestAction()
{
	UNightmareAIAction* BestAction = nullptr;
	for (auto Action : AllActions)
	{
		BestAction = Action;
	}
	return BestAction;
}

void ANightmareAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (CurrentAction != nullptr)
	{
		if (Result == EPathFollowingResult::Aborted)
		{
			UE_LOG(NightmareAI, Warning, TEXT("Nightmare AI Action %s failed."), *CurrentAction->GetName());
		}
		CurrentAction->OnActionComplete();
		CurrentAction = nullptr;
	}
	else
	{
		UE_LOG(NightmareAI, Warning, TEXT("Nightmare AI Action finished but was set back to nullptr somewhere else."));
	}
}