// ©2022 The Icecream Connection

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "InteractiveActor.h"
#include "Components/StaticMeshComponent.h"
#include "../DeadSaplingCharacter.h"

#include "BuildingSpot.generated.h"

UCLASS()
class DEADSAPLING_API ABuildingSpot : public AActor, public IInteractiveActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingSpot();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Interact")
	class UStaticMeshComponent* BaseMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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
};
