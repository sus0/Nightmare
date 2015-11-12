// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "NightmareGameMode.h"
#include "Pawn/NightmareHumanPawn.h"

ANightmareGameMode::ANightmareGameMode() : Super()
{
	PlayerControllerClass = APlayerController::StaticClass();
	DefaultPawnClass = ANightmareHumanPawn::StaticClass();
	GameStateClass = AGameState::StaticClass();
	HUDClass = AHUD::StaticClass();
}

void ANightmareGameMode::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine != nullptr && GEngine->GameViewport != nullptr)
	{
		APlayerController* LocalController = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
		if (LocalController != nullptr)
		{
			LocalController->ConsoleCommand(TEXT("viewmode unlit"));
		}
		const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
		//GEngine->screenview
		//FVector WorldLocUpperLeftCorner;
		//FVector WorldLocLowerLeftCorner;
		//FVector Dummy;
		//FVector MyScale = LocalController->GetControlledPawn()->ActorToWorld().GetScale3D();
		//LocalController->DeprojectScreenPositionToWorld(0.f, 0.f, WorldLocLowerLeftCorner, Dummy);
		//LocalController->DeprojectScreenPositionToWorld(0.f, ViewportSize.Y, WorldLocUpperLeftCorner, Dummy);
		// Min
		VerticalGameBorder.X = 1000.f;
		// Max
		VerticalGameBorder.Y = 0.f;
	}
}


