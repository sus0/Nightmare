// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperCharacter.h"
#include "NightmarePawn.generated.h"

class ANightmareWeapon;
/**
 * 
 */
UCLASS()
class NIGHTMARE_API ANightmarePawn : public APaperCharacter
{
	GENERATED_BODY()

public:
	ANightmarePawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	FName WeaponSocketAttach;

	UPROPERTY(Transient)
	ANightmareWeapon* Weapon;

	UFUNCTION(BlueprintCallable, Category = Weapon)
	void FireWeapon();
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void EquipWeapon(ANightmareWeapon* NewWeapon);
	UFUNCTION(BlueprintCallable, Category = Weapon)
	FName GetWeaponSocketName() const { return WeaponSocketAttach; }
	
	//void UnEquipWeapon();
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

};
