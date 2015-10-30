// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "NightmareInventory.generated.h"

class ANightmarePawn;
class UPaperFlipbookComponent;
UCLASS()
class NIGHTMARE_API ANightmareInventory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANightmareInventory();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	UFUNCTION(BlueprintCallable, Category = Weapon)
	virtual bool PickedUp(ANightmarePawn* PickingUpActor);

	void SetInventoryOwner(ANightmarePawn* InNightmarePawn) { InventoryOwner = InNightmarePawn; }
	ANightmarePawn* GetInventoryOwner() const { return InventoryOwner; }


private:
	ANightmarePawn*  InventoryOwner;
};
