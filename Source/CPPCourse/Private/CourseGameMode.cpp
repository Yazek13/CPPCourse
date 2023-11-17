// Copyright Epic Games, Inc. All Rights Reserved.

#include "CourseGameMode.h"
#include "CourseCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACourseGameMode::ACourseGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
