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
	virtual uint8 GetAIActionPriority() const;
	virtual bool TickAIAction(float DeltaTime);
	virtual void ExecuteAIAction();
	virtual bool IsSafeToAbort();
	virtual void AbortAction();
	virtual void OnActionComplete();

	void SetController(ANightmareAIController* InController);
protected:
	UPROPERTY()
	TWeakObjectPtr<ANightmareAIController>	MyAIController;
};
