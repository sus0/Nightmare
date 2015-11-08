// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "NightmareAIAction.generated.h"

class ANightmareAIController;
/**
 * 
 */
UCLASS()
class NIGHTMARE_API UNightmareAIAction : public UObject
{
	GENERATED_BODY()
public:
	virtual bool TickAIAction(float DeltaTime);
	virtual void ExecuteAIAction();
	void SetController(ANightmareAIController* InController);
protected:
	TWeakObjectPtr<ANightmareAIController>	MyAIController;
};
