// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/NightmareAIAction.h"
#include "NightmareAIAction_AttackEnemy.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTMARE_API UNightmareAIAction_AttackEnemy : public UNightmareAIAction
{
	GENERATED_BODY()
public:
	UNightmareAIAction_AttackEnemy();
	// Begin UNightmareAIAction Interface
	virtual uint8 GetAIActionPriority() const override;
	virtual bool TickAIAction(float DeltaTime) override;
	virtual void AbortAction() override;
	virtual void ExecuteAIAction() override;
	virtual void OnActionComplete() override;
	// End UNightmareAIAction Interface
	
};
