// ©2022 The Icecream Connection

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"

#include "Lighting/RouteLighting.h"

#include "RoutePoint.generated.h"

/**
 * Those are the RoutePoints that make up the movement system.
 * call markPath() on each in the path to make it shiny,
 * call increaseLighting() to increment through the danger stages
 * call un
 */
UCLASS()
class ARoutePoint : public ATargetPoint
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, category="Pathfinding")
	int32 Weight = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, category="Pathfinding")
	TArray<ARoutePoint*> Neighbors;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, category = "Pathfinding")
	TArray<ARouteLighting*> Lights;


	UFUNCTION(BlueprintCallable)
	void LightPath();
};
