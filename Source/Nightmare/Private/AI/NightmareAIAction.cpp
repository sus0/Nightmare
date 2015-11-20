// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "NightmareTypes.h"
#include "NightmareAIAction.h"
#include "NightmareAIController.h"

bool UNightmareAIAction::TickAIAction(float DeltaTime)
{
	return true;
}

void UNightmareAIAction::SetController(ANightmareAIController* InController)
{
	MyAIController = InController;
}

void UNightmareAIAction::ExecuteAIAction()
{
}

uint8 UNightmareAIAction::GetAIActionPriority() const
{
	return EAIActionTypes::AI_Default;
}

bool UNightmareAIAction::IsSafeToAbort()
{
	return true;
}

void UNightmareAIAction::OnActionComplete()
{
}

void UNightmareAIAction::AbortAction()
{
}