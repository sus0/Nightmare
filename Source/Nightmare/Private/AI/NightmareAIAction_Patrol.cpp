// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "NightmareTypes.h"
#include "Pawn/NightmareCreaturePawn.h"
#include "AI/NightmareAIController.h"
#include "AI/NightmareAIAction.h"
#include "AI/NightmareAIAction_Patrol.h"
//#include "PathFollowingComponent.h"

UNightmareAIAction_Patrol::UNightmareAIAction_Patrol() : Super()
{
	bIsExecuting = false;
}

bool UNightmareAIAction_Patrol::TickAIAction(float DeltaTime)
{
	return true;
}

void UNightmareAIAction_Patrol::ExecuteAIAction()
{
	ensure(MyAIController.IsValid());
	bIsExecuting = false;
	const APawn* ControlledPawn = MyAIController->GetPawn();
	const ANightmareCreaturePawn* CreaturePawn = Cast<ANightmareCreaturePawn>(ControlledPawn);
	ensure(CreaturePawn != nullptr);
	Destination = CreaturePawn->GeneratePatrolDestination();
	
	MyAIController->MoveToLocation(Destination, 10.f, true, false);
	bIsExecuting = true;
}

int UNightmareAIAction_Patrol::GetAIActionPriority() const
{
	return static_cast<int>(EAIActionTypes::AI_Patrol);
}

void UNightmareAIAction_Patrol::OnActionComplete()
{
	bIsExecuting = false;
}

void UNightmareAIAction_Patrol::AbortAction()
{
	bIsExecuting = false;
}