// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "PaperFlipbookComponent.h"
#include "PawnFlipbookList.generated.h"

/**
 * 
 */
UCLASS()
class NIGHTMARE_API UPawnFlipbookList : public UDataAsset
{
	GENERATED_BODY()


	void Init();
private:
	TMap<FName, UPaperFlipbookComponent*> PawnFlipBookMap;
};
