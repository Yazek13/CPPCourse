// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPPCourseGameMode.h"
#include "CPPCourseCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACPPCourseGameMode::ACPPCourseGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
