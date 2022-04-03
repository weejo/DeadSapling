// Copyright Epic Games, Inc. All Rights Reserved.

#include "DeadSaplingGameMode.h"
#include "DeadSaplingCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADeadSaplingGameMode::ADeadSaplingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	//set custom PlayerControllerClass...
	//PlayerControllerClass = ADeadSaplingPlayerController::StaticClass();
}
