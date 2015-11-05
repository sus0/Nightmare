// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "NightmarePawn.h"
#include "NightmareWeapon.h"
#include "PawnFlipbookList.h"
#include "PaperFlipbookComponent.h"

ANightmarePawn::ANightmarePawn() : 
	Super(),
	Health(100)
{
	if (PawnFlipbookList != nullptr)
	{
		PawnFlipbookList->InitMap();
	}
}

void ANightmarePawn::UpdateAnimation()
{
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