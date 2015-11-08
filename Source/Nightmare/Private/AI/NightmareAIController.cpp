// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "NightmarePawn.h"
#include "NightmareAIController.h"
#include "NightmareAIAction.h"
#include "NightmareAIAction_Patrol.h"

ANightmareAIController::ANightmareAIController() : Super()
{
	AllowedActions.Add(UNightmareAIAction_Patrol::StaticClass());
}

void ANightmareAIController::Possess(APawn* inPawn)
{
	Super::Possess(inPawn);
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
		return;
	}
	Super::Tick(DeltaTime);
	if (CurrentAction != nullptr)
	{
		CurrentAction->TickAIAction(DeltaTime);
	}
}

