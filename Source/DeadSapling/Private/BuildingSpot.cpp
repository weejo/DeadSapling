// ©2022 The Icecream Connection


#include "BuildingSpot.h"

#include "Engine/Engine.h"


// Sets default values
ABuildingSpot::ABuildingSpot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;
	RootComponent->SetVisibility(false);
}

// Called when the game starts or when spawned
void ABuildingSpot::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABuildingSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuildingSpot::ToggleBuildMode()
{
	GEngine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("TOGGLE FUCKING WORKS WORKS"));
	RootComponent->SetVisibility(!RootComponent->GetVisibleFlag());
}

void ABuildingSpot::Interact_Implementation()
{
	//TODO: Here we should get the Mesh from GameState
	GEngine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Interact WORKS"));
}

void ABuildingSpot::OnTrace_Implementation()
{
	// TODO: Here activate particle effects / display of tower before building
}

