// ©2022 The Icecream Connection

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "DataStructures/DA_TowerInfo.h"

#include "DeadSaplingGameInstance.generated.h"

/**
 * This is the GameInstance Class - here all information about the game, that will be used throughout and don't change over time are stored!
 * Keep it as lightweight as possible, because it will be loaded at the start of the game - he said and aded tower data, but i think it is not feasible in GameState /GameMode.
 *
 */
UCLASS()
class DEADSAPLING_API UDeadSaplingGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	//void Init() override;

public:
	// Changes to the tower (upgrades) have to be def. placed in GameState. The DA_TowerInfo is not to be changed!!
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tower")
	TArray<UDA_TowerInfo*> tower_data;
};
