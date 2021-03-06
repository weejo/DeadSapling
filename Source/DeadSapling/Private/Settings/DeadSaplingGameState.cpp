// ©2022 The Icecream Connection


#include "DeadSaplingGameState.h"

ARoutePoint* ADeadSaplingGameState::GetSpawnPoint()
{
	if (CurrentPath.IsEmpty())
	{
		return nullptr;
	} else
	{
		return CurrentPath[0];
	}
}

void ADeadSaplingGameState::CalculatePath()
{
	CurrentPath.Empty();

	TArray<AActor*> StartPoints;
	const FName StartTag = "Start";
	const FName EndTag = "End";
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), ARoutePoint::StaticClass(), StartTag, StartPoints);

	if (StartPoints.IsEmpty())
	{
		LOG_FATAL(LogInit, "No AI Starting Point found! Add a Route Point with \"Start\"-Tag!");
		return;
	}
	ARoutePoint* RoutePoint = Cast<ARoutePoint>(StartPoints[FMath::RandRange(0, StartPoints.Num()-1)]);
	CurrentPath.Add(RoutePoint);

	bool IsEnd = false;
	while(!IsEnd)
	{
		TArray<ARoutePoint*> keys;
		auto numKeys = RoutePoint->NeighborWeightMap.GetKeys(keys);

		if (numKeys > 0)
		{
			RoutePoint = keys[FMath::RandRange(0, keys.Num() - 1)];
			CurrentPath.Add(RoutePoint);
		} else
		{
			IsEnd = true;
		}

		if (RoutePoint->ActorHasTag(EndTag))
		{
			IsEnd = true;
		}
	}
}
