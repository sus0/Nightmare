// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "NightmareInventory.h"
#include "NightmarePawn.h"
#include "PaperFlipbookComponent.h"
// Sets default values
ANightmareInventory::ANightmareInventory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InventoryOwner = nullptr;
}

// Called when the game starts or when spawned
void ANightmareInventory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANightmareInventory::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool ANightmareInventory::PickedUp(ANightmarePawn*  PickingUpActor)
{
	if (PickingUpActor == nullptr)
	{
		return false;
	}
	InventoryOwner = PickingUpActor;
	AttachRootComponentTo(InventoryOwner->GetSprite(), PickingUpActor->GetWeaponSocketName(), EAttachLocation::SnapToTarget);
	return true;
}
