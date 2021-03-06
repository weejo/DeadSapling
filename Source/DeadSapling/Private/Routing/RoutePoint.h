// ©2022 The Icecream Connection

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"

#include "Interactive/BuildingSpot.h"

#include "RoutePoint.generated.h"

USTRUCT(BlueprintType)
struct FNeighborhood
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
		TArray<ABuildingSpot*> NeighboringTowers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
		ATargetPoint* Direction;
};

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
		TMap<ARoutePoint*, int32> NeighborWeightMap;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, category = "Pathfinding")
		TArray<FNeighborhood> Neighborhoods;
};
