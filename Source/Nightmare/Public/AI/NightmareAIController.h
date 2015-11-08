// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "NightmareAIController.generated.h"

class UNightmareAIAction;
/**
 * 
 */
UCLASS()
class NIGHTMARE_API ANightmareAIController : public AAIController
{
	GENERATED_BODY()
public:
	ANightmareAIController();
	// AActor interface - begin
	virtual void Tick(float DeltaTime) override;
	// AActor interface - end

	// AController interface - begin
	virtual void Possess(APawn* inPawn) override;
	virtual void UnPossess() override;
	// AController interface - end

protected:
	UNightmareAIAction* CurrentAction;
	TArray<TSubclassOf<UNightmareAIAction>> AllowedActions;
	TArray<UNightmareAIAction*> AllActions;
};
