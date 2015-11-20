// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Perception/PawnSensingComponent.h"
#include "NightmareAISensingComponent.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTMARE_API UNightmareAISensingComponent : public UPawnSensingComponent
{
	GENERATED_BODY()
public:
	UNightmareAISensingComponent();

	// Begin UPawnSensingComponent interface
	virtual bool ShouldCheckVisibilityOf(class APawn* Pawn) const override;
	virtual bool CanSenseAnything() const override;
	// End UPawnSensingComponent interface
};
