// ©2022 The Icecream Connection

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "RouteLighting.generated.h"

UENUM(BlueprintType)
enum EDangerLevel
{
	None,
	Path,
	Imminent,
	Danger
};


UCLASS()
class ARouteLighting : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARouteLighting();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY()
		USceneComponent* Root;


	UPROPERTY(BluePrintReadWrite, EditAnywhere, category = "Pathfinding")
		TEnumAsByte<EDangerLevel> DLevel = None;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
