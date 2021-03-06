// ©2022 The Icecream Connection

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "InteractiveActor.h"
#include "Components/StaticMeshComponent.h"

#include "../LogMacros.h"
#include "DataStructures/DA_TowerInfo.h"
#include "Tower.h"
#include "../Settings/DeadSaplingGameInstance.h"
#include "../Player/DeadSaplingPlayerController.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>

#include "BuildingSpot.generated.h"

UCLASS()
class DEADSAPLING_API ABuildingSpot : public AActor, public IInteractiveActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ABuildingSpot();

	UPROPERTY(EditDefaultsOnly, Category = "BuildingSpot")
	UStaticMesh* DefaultMesh;

	UPROPERTY(EditDefaultsOnly, Category = "BuildingSpot")
	class UStaticMeshComponent* BaseMesh;


	UPROPERTY(EditDefaultsOnly, Category = "BuildingSpot")
		TSubclassOf<ATower> TowerBase;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/// <summary>
	/// Whether or not the build mode is active
	/// </summary>
	UPROPERTY()
	bool IsInBuildMode = false;

	/// <summary>
	/// Whether or not the object was looked at by the player
	/// </summary>
	UPROPERTY()
	bool IsTraced = false;

	UPROPERTY()
	bool IsBuilt = false;

	ATower* Building;

	int32 Weight = 0;

	FTimerHandle TriggerTraceLeave;

	ADeadSaplingPlayerController* Controller; 
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void ToggleBuildMode();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interact")
	void Interact(); //prototype
	virtual void Interact_Implementation() override; //actual impl.

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interact")
	void OnTrace(); //prototype
	virtual void OnTrace_Implementation() override; //actual impl.

	UFUNCTION()
	void OnLeaveTrace();
};
