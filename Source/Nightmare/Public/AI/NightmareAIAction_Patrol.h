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
	virtual bool TickAIAction(float DeltaTime) override;
	virtual void ExecuteAIAction() override;
private:
	FVector Destination;
};
