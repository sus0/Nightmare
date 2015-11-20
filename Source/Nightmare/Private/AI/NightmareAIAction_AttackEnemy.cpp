// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "NightmareTypes.h"
#include "NightmareAIAction_AttackEnemy.h"

UNightmareAIAction_AttackEnemy::UNightmareAIAction_AttackEnemy() : Super()
{
}

bool UNightmareAIAction_AttackEnemy::TickAIAction(float DeltaTime)
{
	return true;
}

void UNightmareAIAction_AttackEnemy::ExecuteAIAction()
{
	ensure(MyAIController.IsValid());
}

uint8 UNightmareAIAction_AttackEnemy::GetAIActionPriority() const
{
	return EAIActionTypes::AI_Attack;
}

void UNightmareAIAction_AttackEnemy::OnActionComplete()
{
}

void UNightmareAIAction_AttackEnemy::AbortAction()
{
}


