// Copyright Epic Games, Inc. All Rights Reserved.

#include "DeadSaplingGameMode.h"
#include "DeadSaplingCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADeadSaplingGameMode::ADeadSaplingGameMode()
{
	//set custom PlayerControllerClass...
	PlayerControllerClass = ADeadSaplingPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/DeadSapling/Scripts/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

}
