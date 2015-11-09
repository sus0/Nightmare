// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/NightmareAIAction.h"
#include "NightmareAIAction_Patrol.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTMARE_API UNightmareAIAction_Patrol : public UNightmareAIAction
{
	GENERATED_BODY()
	
public:
	UNightmareAIAction_Patrol();
	virtual int GetAIActionPriority() const override;
	virtual bool TickAIAction(float DeltaTime) override;
	virtual void AbortAction() override;
	virtual void ExecuteAIAction() override;
	virtual void OnActionComplete() override;
private:
	FVector Destination;
private:
	bool bIsExecuting;
};
