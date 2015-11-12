// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "Pawn/NightmareCreaturePawn.h"
#include "NightmareGameMode.h"

ANightmareCreaturePawn::ANightmareCreaturePawn() : Super()
{
	PatrolRegion = CreateOptionalDefaultSubobject<UBoxComponent>(TEXT("Patrol Region"));
	if (PatrolRegion)
	{
		PatrolRegion->AlwaysLoadOnClient = true;
		PatrolRegion->AlwaysLoadOnServer = true;
		PatrolRegion->bOwnerNoSee = false;
		PatrolRegion->bAffectDynamicIndirectLighting = true;
		PatrolRegion->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		PatrolRegion->AttachParent = GetRootComponent();
		static FName CollisionProfileName(TEXT("NoCollision"));
		PatrolRegion->SetCollisionProfileName(CollisionProfileName);
		PatrolRegion->bGenerateOverlapEvents = false;
		// This should never tick
		PatrolRegion->SetComponentTickEnabled(false);
	}
}

FVector ANightmareCreaturePawn::GeneratePatrolDestination() const
{
	const FVector Origin = PatrolRegion->GetComponentTransform().GetLocation();
	const FVector BoxExtent = PatrolRegion->GetScaledBoxExtent();
	const FVector RegionMin = Origin - BoxExtent;
	const FVector RegionMax = Origin + BoxExtent;
	FVector Result = FMath::RandPointInBox(FBox(RegionMin, RegionMax));
	// This is a 2D game and thus we don't care about Y
	Result.Y = 0.f;

	ANightmareGameMode* CurrGameMomde = Cast<ANightmareGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (CurrGameMomde != nullptr)
	{
		FVector2D VerticalRange = CurrGameMomde->GetVerticalViewportBorder();
		Result.Z = FMath::Clamp(Result.Z, VerticalRange.X, VerticalRange.Y);
	}

	return Result;
}

