// ©2022 The Icecream Connection

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "RouteLighting.generated.h"

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

	UPROPERTY(BlueprintReadWrite, EditAnywhere, category ="Pathfinding")
	TMap<int32, FLinearColor> DangerColorMap;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:


};
