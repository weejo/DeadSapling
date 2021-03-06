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
	BaseMesh->SetHiddenInGame(!IsInBuildMode);
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
	RootComponent->SetHiddenInGame(!IsInBuildMode);
}

void ABuildingSpot::Interact_Implementation()
{
	// Don't do stuff if not in build mode
	if (IsInBuildMode && !IsBuilt) {
		if (UDA_TowerInfo* TowerInfo = Cast<UDA_TowerInfo>(Cast<UDeadSaplingGameInstance>(GetGameInstance())->tower_data.GetData()[0])) {
			Building = GetWorld()->SpawnActor<ATower>(TowerBase, GetActorLocation(), GetActorRotation());
			Building->Initialize(TowerInfo, GetActorLocation(), GetActorRotation());
			IsBuilt = true;
		}
		else {
			LOG_ERROR(LogInit, "TowerInfo doesn't exist.");
		}
	}
}

void ABuildingSpot::OnTrace_Implementation()
{
	// TODO: Right now we can only buy somewhere once. this should be fixed at some point
	if (IsBuilt) return;
	// Don't do stuff if not in build mode
	if (IsInBuildMode) {
		
		GetWorldTimerManager().ClearTimer(TriggerTraceLeave);
		// TODO: Here activate particle effects / display of tower before building
		if (!IsTraced) {
			IsTraced = true;

			if (UDA_TowerInfo* TowerInfo = Cast<UDA_TowerInfo>(Cast<UDeadSaplingGameInstance>(GetGameInstance())->tower_data.GetData()[0])) {
				Building = GetWorld()->SpawnActor<ATower>(TowerBase, GetActorLocation(), GetActorRotation());
				Building->Initialize(TowerInfo, GetActorLocation(), GetActorRotation());
			}
			else {
				LOG_ERROR(LogInit, "TowerInfo doesn't exist.");
			}
		}
		//Set a call to on leaveTrace if there was no trace for 0.2s
		GetWorldTimerManager().SetTimer(TriggerTraceLeave, this, &ABuildingSpot::OnLeaveTrace, 1.0f, false);
	}
}

void ABuildingSpot::OnLeaveTrace()
{
	if (IsTraced) {
		IsTraced = false;
		Building->Destroy();
	}
}

