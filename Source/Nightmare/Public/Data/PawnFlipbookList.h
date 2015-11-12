// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "NightmareTypes.h"
#include "PawnFlipbookList.generated.h"


/**
 * 
 */
USTRUCT()
struct FPawnFlipbookEntry
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = Animations)
	EAnimationStates PawnState;

	UPROPERTY(EditAnywhere, Category = Animations)
	class UPaperFlipbook* Flipbook;
};

UCLASS(BlueprintType)
class NIGHTMARE_API UPawnFlipbookList : public UDataAsset
{
	GENERATED_BODY()
public:
	UPawnFlipbookList(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(EditAnywhere,Category = Animations)
	TArray<FPawnFlipbookEntry> PawnFlipBooks;
	
	// UObject Interface - begin
	virtual void PostLoad() override;
	// UObject interface - end
	void InitMap();

	UPaperFlipbook* FindFlipbook(EAnimationStates PawnAnimationState);

private:
	TMap<int, class UPaperFlipbook*> PawnFlipBookMap;
};
