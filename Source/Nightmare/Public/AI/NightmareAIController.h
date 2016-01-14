// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "NightmareAIController.generated.h"

class UNightmareAIAction;
class UNightmareAISensingComponent;
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
	virtual void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result) override;
	// AController interface - end

	// Called wht our AI sees an enemy pawn
	UFUNCTION()
	virtual void OnSeeEnemyPawn(APawn* SeenPawn);

	virtual void InitializeMovement();
	virtual void InitializeSensing();
	virtual void SenseAndSelectTartget();
protected:
	virtual UNightmareAIAction* PickBestAction();
	virtual void ConstructStandardActions();
	
	UPROPERTY()
	UNightmareAIAction* CurrentAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AIController)
	TArray<TSubclassOf<UNightmareAIAction>> StandardActions;
	
	UPROPERTY()
	TArray<UNightmareAIAction*> AllActions;
	
	UPROPERTY()
	UNightmareAISensingComponent* SensingComponent;

};
