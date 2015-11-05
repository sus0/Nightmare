// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "NightmarePawn.h"
#include "NightmareAIController.h"
#include "NightmareAIAction.h"
//ANightmareAIController::ANightmareAIController : Super()
//{
//
//}

void ANightmareAIController::Tick(float DeltaTime)
{
	ANightmarePawn* MyPawn = Cast<ANightmarePawn>(GetPawn());
	if (MyPawn == nullptr || MyPawn->GetHealth() < 0.f)
	{
		return;
	}
	Super::Tick(DeltaTime);
	if (CurrentAction != nullptr)
	{
		CurrentAction->TickAIAction(DeltaTime);
	}
}

