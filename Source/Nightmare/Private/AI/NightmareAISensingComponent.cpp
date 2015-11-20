// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "NightmarePawn.h"
#include "NightmareGameMode.h"
#include "NightmareAISensingComponent.h"

UNightmareAISensingComponent::UNightmareAISensingComponent() : Super()
{
	SightRadius = 1000.f;
	SetPeripheralVisionAngle(180.0f);
}

bool UNightmareAISensingComponent::CanSenseAnything() const
{
	return (bSeePawns && OnSeePawn.IsBound() && SightRadius < 0.f);
}

bool UNightmareAISensingComponent::ShouldCheckVisibilityOf(class APawn* Pawn) const
{
	ANightmarePawn* CurrPawn = Cast<ANightmarePawn>(Pawn);
	
	return CurrPawn != nullptr 
		&& CurrPawn->GetHealth() > 0.f 
		&& !CurrPawn->bHidden 
		&& !ANightmareGameMode::OnSameTeam(CurrPawn, GetOwner());
}
