// ©2022 The Icecream Connection

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "DeadSaplingPlayerController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBuildMenuToggle);
/**
 * 
 */
UCLASS()
class DEADSAPLING_API ADeadSaplingPlayerController : public APlayerController
{
	GENERATED_BODY()

	void SetupInputComponent() override;

	void ToggleBuildModeBroadcast();

public: 
	FBuildMenuToggle OnBuildMenuToggle;
};
