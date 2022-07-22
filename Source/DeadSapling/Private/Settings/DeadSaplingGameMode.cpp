// Copyright Epic Games, Inc. All Rights Reserved.

#include "DeadSaplingGameMode.h"
#include "../Player/DeadSaplingCharacter.h"
#include "../Settings/DeadSaplingGameState.h"
#include "../Player/DeadSaplingPlayerController.h"
#include "UObject/ConstructorHelpers.h"

ADeadSaplingGameMode::ADeadSaplingGameMode()
{
	//set custom PlayerControllerClass...
	PlayerControllerClass = ADeadSaplingPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/DeadSapling/Scripts/BP_MainCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	//Set custom gamestate class
	static ConstructorHelpers::FClassFinder<AGameStateBase> GameStateBPClass(TEXT("/Game/DeadSapling/Scripts/BP_GameState"));
	GameStateClass = GameStateBPClass.Class;
}