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
	FVector RegionMin = Origin - BoxExtent;
	FVector RegionMax = Origin + BoxExtent;
	FVector Result = FVector::ZeroVector;

	ANightmareGameMode* CurrGameMomde = Cast<ANightmareGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (CurrGameMomde != nullptr)
	{
		FVector2D VerticalRange = CurrGameMomde->GetVerticalViewportBorder();
		// Check if we are too close to border
		if (RegionMax.Z > VerticalRange.Y)
		{
			RegionMax = Origin + FVector(BoxExtent.X, BoxExtent.Y, 0.f);
		}
		else if (RegionMin.Z < VerticalRange.X)
		{
			RegionMin = Origin - FVector(BoxExtent.X, BoxExtent.Y, 0.f);
		}
		Result = FMath::RandPointInBox(FBox(RegionMin, RegionMax));
	}
	else
	{
		UE_LOG(NightmarePawn, Warning, TEXT("Bad Destination returning"));
	}
	// This is a 2D game and thus we don't care about Y
	Result.Y = 0.f;
	return Result;
}

uint8 ANightmareCreaturePawn::GetTeamNum() const
{
	return ENightmareTeam::Team_Creature;
}