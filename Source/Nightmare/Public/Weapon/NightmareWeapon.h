// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NightmareInventory.h"
#include "NightmareWeapon.generated.h"


USTRUCT()
struct FInstantHitDamageInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	int32 InstantDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	FVector TraceDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	float TraceDistance;

	FInstantHitDamageInfo(int32 In_InstantDamage, FVector In_TraceDirection, float In_TraceDistance) :
		InstantDamage(In_InstantDamage),
		TraceDirection(In_TraceDirection),
		TraceDistance(In_TraceDistance) {}
	FInstantHitDamageInfo() :
		InstantDamage(10),
		TraceDirection(FVector(1.f, 0.f, 0.f)),
		TraceDistance(100.f) {}

};

UCLASS()
class NIGHTMARE_API ANightmareWeapon : public ANightmareInventory
{
	GENERATED_BODY()
public:
	ANightmareWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MuzzleFlash)
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MuzzleFlash)
	FName MuzzleFlashAttachSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	FInstantHitDamageInfo InstantDamageInfo;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponDamage)
	uint8 bIsInstantDamageWeapon:1;

	virtual void FireHit();
protected:
	virtual void FireInstantHit();
	virtual void FireProjectile();
	virtual void DoFireEffects();
};
