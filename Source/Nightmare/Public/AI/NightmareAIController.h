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
	//ANightmareAIController();
	virtual void Tick(float DeltaTime) override;


protected:
	UNightmareAIAction* CurrentAction;
};
