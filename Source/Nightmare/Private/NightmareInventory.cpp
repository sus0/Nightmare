// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "NightmarePawn.h"
#include "NightmareInventory.h"
#include "PaperSpriteComponent.h"

// Sets default values
ANightmareInventory::ANightmareInventory()
{
	Sprite = CreateOptionalDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	if (Sprite)
	{
		Sprite->AlwaysLoadOnClient = true;
		Sprite->AlwaysLoadOnServer = true;
		Sprite->bOwnerNoSee = false;
		Sprite->bAffectDynamicIndirectLighting = true;
		Sprite->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		Sprite->AttachParent = GetRootComponent();
		static FName CollisionProfileName(TEXT("OverlapAllDynamic"));
		Sprite->SetCollisionProfileName(CollisionProfileName);
		Sprite->bGenerateOverlapEvents = true;
	}

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	InventoryOwner = nullptr;
}

// Called when the game starts or when spawned
void ANightmareInventory::BeginPlay()
{
	Super::BeginPlay();
	// Adding necessary callback
	Sprite->OnComponentBeginOverlap.AddUniqueDynamic(this, &ANightmareInventory::PickedUp);
}

// Called every frame
void ANightmareInventory::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

//bool ANightmareInventory::PickedUp(ANightmarePawn*  PickingUpActor)
//{
//	if (PickingUpActor == nullptr || !PickingUpActor->IsA(ANightmareHumanPawn::StaticClass()))
//	{
//		return false;
//	}
//	if (PickingUpActor->IsA(ANightmareHumanPawn::StaticClass()))
//	{
//		InventoryOwner = PickingUpActor;
//		AttachRootComponentTo(InventoryOwner->GetSprite(), PickingUpActor->GetWeaponSocketName(), EAttachLocation::SnapToTarget);
//		return true;
//	}
//	return true;
//}
void ANightmareInventory::PickedUp(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor == nullptr)
	{
		return;
	}
	ANightmarePawn* Pawn = Cast<ANightmarePawn>(OtherActor);
	if (Pawn != nullptr)
	{
		InventoryOwner = Pawn;
		Pawn->TakeInventory(this);
	}
}