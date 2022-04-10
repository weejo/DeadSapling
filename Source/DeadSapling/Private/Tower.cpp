// ©2022 The Icecream Connection


#include "Tower.h"

// Sets default values
ATower::ATower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

void ATower::Initialize(UDA_TowerInfo* TowerInfo, FVector Location, FRotator Rotation)
{
	if (!IsInitialized) {
		
		UStaticMesh* newMesh = Cast<UStaticMesh>(TowerInfo->TowerMesh.ResolveObject());

		if (newMesh == nullptr) {
			newMesh = Cast<UStaticMesh>(TowerInfo->TowerMesh.TryLoad());
		}

		if (newMesh) {
			TowerMesh = NewObject<UStaticMeshComponent>(this, NAME_None);

			/*FAttachmentTransformRules(EAttachmentRule->KeepRelative, true);
			TowerMesh->RegisterComponent();
			TowerMesh->SetRelativeLocation(Location);
			TowerMesh->SetRelativeRotation(Rotation);
			TowerMesh->AttachToComponent(RootComponent, , EAttachLocation::KeepRelativeOffset);
			TowerMesh->SetStaticMesh(newMesh);*/
		}
		else {
			LOG_ERROR(LogInit, "TowerMesh couldn't be instantiated");
		}
	}
}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

