// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "NightmarePawn.h"
#include "Weapon/NightmareWeapon.h"
#include "Data/PawnFlipbookList.h"
#include "PaperFlipbookComponent.h"

ANightmarePawn::ANightmarePawn() : 
	Super(),
	SightRadius(0.f),
	SensingTimeInterval(0.f),
	PeripheralVisionAngle(0.f),
	Health(100)
{
	UCharacterMovementComponent* PawnMovement = GetCharacterMovement();
	ensure(PawnMovement != nullptr);
	PawnMovement->SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::Y);
	PawnMovement->bConstrainToPlane = true;

	if (PawnFlipbookList != nullptr)
	{
		PawnFlipbookList->InitMap();
	}
}

void ANightmarePawn::UpdateAnimation()
{
}

uint8 ANightmarePawn::GetTeamNum() const
{
	return ENightmareTeam::Team_Default;
}

//
//float ANightmarePawn::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
//{
//	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
//	return DamageAmount;
//}
//
//void ANightmarePawn::FireWeapon()
//{
//	UE_LOG(NightmarePawn, Warning, TEXT("NightmarePawn %s is trying to attack."), *GetName());
//	if (Weapon != nullptr)
//	{
//		Weapon->FireHit();
//	}
//}
//
//void ANightmarePawn::EquipWeapon(ANightmareWeapon* NewWeapon)
//{
//	if (NewWeapon != nullptr)
//	{
//		//UnEquipWeapon();
//		if (NewWeapon->PickedUp(this))
//		{
//			Weapon = NewWeapon;
//		}
//	}
//	else
//	{
//		UE_LOG(NightmarePawn, Warning, TEXT("NightmarePawn %s attempted to equip a non-exsiting weapon."), *GetName());
//	}
//}

void ANightmarePawn::TakeInventory(ANightmareInventory* Inventory)
{
}