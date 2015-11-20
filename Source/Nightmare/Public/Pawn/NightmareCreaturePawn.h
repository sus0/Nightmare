// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NightmarePawn.h"
#include "NightmareCreaturePawn.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTMARE_API ANightmareCreaturePawn : public ANightmarePawn
{
	GENERATED_BODY()
public:
	ANightmareCreaturePawn();

	virtual uint8 GetTeamNum() const final;

	UPROPERTY(Category = Actions, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* PatrolRegion;
	FVector GeneratePatrolDestination() const;
};
