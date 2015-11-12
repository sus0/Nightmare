// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "NightmareHumanPawn.h"
#include "NightmareWeapon.h"
#include "PawnFlipbookList.h"
#include "PaperFlipbookComponent.h"

ANightmareHumanPawn::ANightmareHumanPawn() : Super()
{
	Weapon = nullptr;
	CurrentAnimState = EAnimationStates::IDLE;
}

void ANightmareHumanPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	//Hook up every-frame handling for our four axes
	InputComponent->BindAxis("MoveRight", this, &ANightmareHumanPawn::MoveRight);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ANightmareHumanPawn::OnBeginJump);
	InputComponent->BindAction("Jump", IE_Released, this, &ANightmareHumanPawn::OnEndJump);
}

void ANightmareHumanPawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);


	if (bIsJumping)
	{

	}
	else
	{

	}
}

void ANightmareHumanPawn::UpdateAnimation()
{
	EAnimationStates NewState = EAnimationStates::IDLE;
	if (GetVelocity().Size() > 0.f)
	{
		NewState = EAnimationStates::RUNNING;
	}

	if (NewState != CurrentAnimState)
	{
		if (PawnFlipbookList != nullptr && GetSprite()->SetFlipbook(PawnFlipbookList->FindFlipbook(NewState)))
		{
			CurrentAnimState = NewState;
		}
		else
		{
		}
	}
}

void ANightmareHumanPawn::MoveRight(float AxisValue)
{
	HorizontalMovementInput = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
	AddMovementInput(FVector(1.f, 0.f, 0.f), HorizontalMovementInput, false);
	UpdateAnimation();
	AController* PawnController = GetController();
	if (HorizontalMovementInput > 0.f)
	{
		PawnController->SetControlRotation(FRotator::ZeroRotator);
	}
	else if (HorizontalMovementInput < 0.f)
	{
		PawnController->SetControlRotation(FRotator(0.f, 180.f, 0.f));
	}
}

void ANightmareHumanPawn::OnBeginJump()
{
	bIsJumping = true;
	Jump();
}

void ANightmareHumanPawn::OnEndJump()
{
	bIsJumping = false;
	StopJumping();
}

float ANightmareHumanPawn::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	return DamageAmount;
}

void ANightmareHumanPawn::FireWeapon()
{
	UE_LOG(NightmarePawn, Warning, TEXT("NightmarePawn %s is trying to attack."), *GetName());
	if (Weapon != nullptr)
	{
		Weapon->FireHit();
	}
}

void ANightmareHumanPawn::EquipWeapon(ANightmareWeapon* NewWeapon)
{
	if (NewWeapon != nullptr)
	{
		NewWeapon->AttachRootComponentTo(GetSprite(), GetWeaponSocketName(), EAttachLocation::SnapToTarget);
	}
	else
	{
		UE_LOG(NightmarePawn, Warning, TEXT("NightmarePawn %s attempted to equip a non-exsiting weapon."), *GetName());
	}
}

void ANightmareHumanPawn::TakeInventory(ANightmareInventory* Inventory)
{
	ANightmareWeapon* WeaponInventory = Cast<ANightmareWeapon>(Inventory);
	if (WeaponInventory != nullptr)
	{
		if (WeaponInventory != Weapon)
		{
			EquipWeapon(WeaponInventory);
		}
	}
}