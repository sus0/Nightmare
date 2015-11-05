// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "NightmareTypes.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EAnimationStates : uint8
{
		IDLE,
		RUNNING,
		ATTACKING,
		MAX
};


