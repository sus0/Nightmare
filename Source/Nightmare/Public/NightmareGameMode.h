// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "NightmareGameMode.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTMARE_API ANightmareGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	ANightmareGameMode();
	// AActor interface - begin
	void BeginPlay() override;
	// AActor interface - end
	
	UPROPERTY(EditDefaultsOnly, Category = Borders)
	FVector2D VerticalGameBorder;
	FVector2D GetVerticalViewportBorder() const { return VerticalGameBorder; }
};
