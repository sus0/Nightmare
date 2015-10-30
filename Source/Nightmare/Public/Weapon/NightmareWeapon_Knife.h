// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Weapon/NightmareWeapon.h"
#include "NightmareWeapon_Knife.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTMARE_API ANightmareWeapon_Knife : public ANightmareWeapon
{
	GENERATED_BODY()
	virtual void FireHit() override;
	
	
	
};
