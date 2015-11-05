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

	UPROPERTY(EditDefaultsOnly, Category = Animation)
	class UPawnFlipbookList* PawnFlipbookList;
	int GetHealth() const { return Health; }
protected:
	//UPROPERTY(Config, EditDefaultOnly)
	static const int TotalHealth = 100;
	int Health;
};
