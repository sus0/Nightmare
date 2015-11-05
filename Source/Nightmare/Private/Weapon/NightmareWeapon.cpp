// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "NightmarePawn.h"
#include "NightmareWeapon.h"

ANightmareWeapon::ANightmareWeapon() 
	: Super(), bIsInstantDamageWeapon(false)
{

}

void ANightmareWeapon::FireHit()
{
	if (bIsInstantDamageWeapon)
	{
		FireInstantHit();
	}
	else 
	{
		// shoot a projectile and let the project handle itself
	}
	DoFireEffects();
}

void ANightmareWeapon::FireInstantHit()
{
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		ANightmarePawn* OwnerPawn = GetInventoryOwner();
		FVector DirectionToUse = OwnerPawn->GetTransform().Rotator().RotateVector(InstantDamageInfo.TraceDirection);

		FVector TraceStart = GetActorLocation();
		FVector TraceEnd = TraceStart + DirectionToUse * InstantDamageInfo.TraceDistance;
		FHitResult HitResult;
		// Ignore the owner for now
		FCollisionQueryParams Params(TEXT("LineTraceSingle"), false, GetInventoryOwner());
		Params.bReturnPhysicalMaterial = true;
		Params.bTraceAsyncScene = true;
		World->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Pawn, Params);
		if (HitResult.bBlockingHit && HitResult.Actor != nullptr && HitResult.Actor->bCanBeDamaged)
		{
			TWeakObjectPtr<AActor> HitActor = HitResult.Actor;
			if (HitActor->IsA(APawn::StaticClass()))
			{
				FPointDamageEvent PointDamageEvent(InstantDamageInfo.InstantDamage, HitResult, (TraceEnd - TraceStart), InstantDamageInfo.DamageType);
				// For debugging purposes
				HitActor->TakeDamage(InstantDamageInfo.InstantDamage, PointDamageEvent, World->GetFirstPlayerController(), this);
				UE_LOG(NightmareWeapon, Warning, TEXT("Hit Actor: %s , Weapon Name: %s"), *HitActor->GetName(), *GetName());

			}
		}
		else
		{
			UE_LOG(NightmareWeapon, Warning, TEXT("%s attempt to attack but didn't hit anything."), *GetName());
		}
	}
	else
	{
		UE_LOG(NightmareWeapon, Warning, TEXT("%s no world exists"), *GetName());
	}
}

void ANightmareWeapon::FireProjectile()
{

}

void ANightmareWeapon::DoFireEffects()
{
// depending on damage type, do the proper effects
}