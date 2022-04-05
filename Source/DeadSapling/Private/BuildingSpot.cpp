// ©2022 The Icecream Connection


#include "BuildingSpot.h"

#include "Engine/Engine.h"

// Sets default values
ABuildingSpot::ABuildingSpot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	
	BaseMesh->SetupAttachment(RootComponent);

	// Hide Until BuildMenu is active
	BaseMesh->SetVisibility(IsInBuildMode);
}

// Called when the game starts or when spawned
void ABuildingSpot::BeginPlay()
{
	Super::BeginPlay();
	// Listen to OnBuildMenuToggle
	Controller = Cast<ADeadSaplingPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	Controller->OnBuildMenuToggle.AddDynamic(this, &ABuildingSpot::ToggleBuildMode);
}

// Called every frame
void ABuildingSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABuildingSpot::ToggleBuildMode()
{
	IsInBuildMode = !IsInBuildMode;
	RootComponent->SetVisibility(IsInBuildMode);
}

void ABuildingSpot::Interact_Implementation()
{
	// Don't do stuff if not in build mode
	if (IsInBuildMode) {
		UDA_TowerInfo* TowerInfo = Cast<UDA_TowerInfo>(Cast<UDeadSaplingGameInstance>(GetGameInstance())->tower_data.GetData()[0]);

		if (TowerInfo) {
			ATower* NewTower = GetWorld()->SpawnActor<ATower>(GetActorLocation(), GetActorRotation());
			NewTower->Initialize(TowerInfo, GetActorLocation(), GetActorRotation());
		}
		else {
			LOG_ERROR(LogInit, "TowerInfo doesn't exist.");
		}
	}
}

void ABuildingSpot::OnTrace_Implementation()
{
	// Don't do stuff if not in build mode
	if (IsInBuildMode) {
		GetWorldTimerManager().ClearTimer(TriggerTraceLeave);
		// TODO: Here activate particle effects / display of tower before building
		if (!IsTraced) {
			IsTraced = true;

			UDA_TowerInfo* TowerInfo = Cast<UDA_TowerInfo>(Cast<UDeadSaplingGameInstance>(GetGameInstance())->tower_data.GetData()[0]);

			if (TowerInfo) {
				UStaticMesh* NewMesh = Cast<UStaticMesh>(TowerInfo->TowerMesh.ResolveObject());

				if (NewMesh == nullptr) {
					NewMesh = Cast<UStaticMesh>(TowerInfo->TowerMesh.TryLoad());
				}

				if (NewMesh) {
					BaseMesh->SetStaticMesh(NewMesh);
				}
				else {
					LOG_ERROR(LogInit, "TowerMesh couldn't be instantiated");
				}
			}
			else {
				LOG_ERROR(LogInit, "TowerInfo doesn't exist.");
			}
		}
		//Set a call to on leaveTrace if there was no trace for 0.2s
		GetWorldTimerManager().SetTimer(TriggerTraceLeave, this, &ABuildingSpot::OnLeaveTrace, 0.5f, false);
	}
}

void ABuildingSpot::OnLeaveTrace()
{
	LOG_SCREENMSG("OnLeaveTrace - BuildingSpot");
	if (IsTraced) {
		IsTraced = false;
		LOG_SCREENMSG("OnLeaveTrace - BuildingSpot");
		BaseMesh->SetStaticMesh(DefaultMesh);
	}
}

