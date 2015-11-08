// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "Pawn/NightmareCreaturePawn.h"
#include "NightmareAIController.h"
#include "NightmareAIAction.h"
#include "NightmareAIAction_Patrol.h"

bool UNightmareAIAction_Patrol::TickAIAction(float DeltaTime)
{
	return true;
}

void UNightmareAIAction_Patrol::ExecuteAIAction()
{
	ensure(MyAIController.IsValid());
	const APawn* ControlledPawn = MyAIController->GetPawn();
	const ANightmareCreaturePawn* CreaturePawn = Cast<ANightmareCreaturePawn>(ControlledPawn);
	ensure(CreaturePawn != nullptr);
	Destination = CreaturePawn->GeneratePatrolDestination();

	MyAIController->MoveToLocation(Destination, 10.f, true, false);
	//if (TeamData != NULL && TeamData->Brewery != NULL && TeamData->Brewery->GetAIDirector() != NULL)
	//{
	//	const AActor* Actor = TeamData->Brewery->GetAIDirector()->GetEnemyBrewery();
	//	if (Actor != NULL)
	//	{
	//		bIsMoving = true;
	//		Destination = Actor->GetActorLocation();
	//		MyAIController->MoveToLocation(Destination, TargetAcceptanceRadius, true, true, true);
	//	}
	//}

	//FOnMovementEvent MovementDelegate;
	//MovementDelegate.BindUObject(this, &UStrategyAIAction_MoveToBrewery::OnMoveCompleted);
	//MyAIController->RegisterMovementEventDelegate(MovementDelegate);

}
