// Fill out your copyright notice in the Description page of Project Settings.

#include "Nightmare.h"
#include "PaperFlipbookComponent.h"
#include "PawnFlipbookList.h"

UPawnFlipbookList::UPawnFlipbookList(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PawnFlipBookMap.Empty();
	PawnFlipBookMap.Reserve(static_cast<int>(EAnimationStates::MAX));
}

void UPawnFlipbookList::PostLoad()
{
	Super::PostLoad();
	InitMap();
}

void UPawnFlipbookList::InitMap()
{
	if (PawnFlipBooks.Num() != 0)
	{
		for (FPawnFlipbookEntry FlipbookEntry : PawnFlipBooks)
		{
			if (FlipbookEntry.Flipbook != nullptr)
			{
				PawnFlipBookMap.Add(static_cast<int>(FlipbookEntry.PawnState), FlipbookEntry.Flipbook);
			}
		}
	}
}

UPaperFlipbook* UPawnFlipbookList::FindFlipbook(EAnimationStates PawnAnimationState)
{
	UPaperFlipbook** FlipBook = PawnFlipBookMap.Find(static_cast<int>(PawnAnimationState));
	return FlipBook == nullptr ? nullptr : *FlipBook;
}

