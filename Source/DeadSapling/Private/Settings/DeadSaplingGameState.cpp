// ©2022 The Icecream Connection


#include "DeadSaplingGameState.h"

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
		if(RoutePoint->Neighbors.Num() > 0)
		{
			RoutePoint = RoutePoint->Neighbors[FMath::RandRange(0, RoutePoint->Neighbors.Num() - 1)];
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
