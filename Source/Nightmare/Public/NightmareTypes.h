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
 
// The order reflects priorities
namespace EAIActionTypes
{
	UENUM(BlueprintType)
	enum Type
	{
		AI_Default,
		AI_Patrol,
		AI_Attack
	};
}

namespace ENightmareTeam
{
	UENUM(BlueprintType)
	enum Type
	{
		Team_Default,
		Team_Human,
		Team_Creature
	};
}