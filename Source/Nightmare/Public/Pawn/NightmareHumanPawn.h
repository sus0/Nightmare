// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NightmarePawn.h"
#include "NightmareTypes.h"
#include "NightmareHumanPawn.generated.h"

class ANightmareWeapon;
class UPawnFlipbookList;
/**
 * 
 */
UCLASS()
class NIGHTMARE_API ANightmareHumanPawn : public ANightmarePawn
{
	GENERATED_BODY()

public:
	ANightmareHumanPawn();

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

	virtual void TakeInventory(ANightmareInventory* Inventory) override;

	//void UnEquipWeapon();
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	
	virtual void UpdateAnimation() override;
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

protected:
	// Inputs - begin
	float HorizontalMovementInput;
	bool bIsJumping;
	void MoveRight(float AxisValue);
	void OnBeginJump();
	void OnEndJump();
	// Inputs - end
	EAnimationStates CurrentAnimState;
	
};
