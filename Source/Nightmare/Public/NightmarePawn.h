// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperCharacter.h"
#include "NightmareTypes.h"
#include "NightmarePawn.generated.h"

class ANightmareInventory;
/**
 * 
 */
UCLASS(Config = Game)
class NIGHTMARE_API ANightmarePawn : public APaperCharacter
{
	GENERATED_BODY()
public:
	ANightmarePawn();

	virtual void TakeInventory(ANightmareInventory* Inventory);
	
	virtual void UpdateAnimation();

	virtual uint8 GetTeamNum() const;

	UPROPERTY(EditDefaultsOnly, Category = Animation)
	class UPawnFlipbookList* PawnFlipbookList;
	
	int GetHealth() const { return Health; }

	UPROPERTY(EditDefaultsOnly, Category = Sensing)
	float SightRadius;
	
	UPROPERTY(EditDefaultsOnly, Category = Sensing)
	float PeripheralVisionAngle;
	
	UPROPERTY(EditDefaultsOnly, Category = Sensing)
	float SensingTimeInterval;

	inline float GetSightRadius() const { return SightRadius; }
	inline float GetPeripheralVisionAngle() const { return PeripheralVisionAngle; }
	inline float GetSensingTimeInterval() const { return SensingTimeInterval; }

protected:
	//UPROPERTY(Config, EditDefaultOnly)
	static const int TotalHealth = 100;
	
	int Health;
};
