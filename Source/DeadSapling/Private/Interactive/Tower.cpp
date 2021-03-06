// ©2022 The Icecream Connection


#include "Tower.h"

// Sets default values
ATower::ATower()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TowerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TowerMesh"));
	TowerMesh->SetupAttachment(RootComponent);
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RangeSphere"));
	SphereComponent->SetupAttachment(RootComponent);
}

void ATower::Initialize(UDA_TowerInfo* TowerInfo, FVector Location, FRotator Rotation)
{
	if (!IsInitialized)
	{
		// This whole part is dirty as fuck, but tbh: if the turret data is broken the game will crash sooner or later anyhow.
		TowerMesh->SetStaticMesh(Cast<UStaticMesh>(TowerInfo->TowerMesh.ResolveObject()));
		TowerMesh->SetWorldLocation(Location);
		TowerMesh->SetRelativeRotation(Rotation);
		TowerMesh->SetCollisionProfileName(TEXT("Pawn"));

		BaseDamage = TowerInfo->BaseDamage;
		DamageType = TowerInfo->DamageType;
		BaseRange = TowerInfo->BaseRange;
		BaseSpeed = TowerInfo->BaseSpeed;
		BaseAmmunition = TowerInfo->BaseAmmunition;

		// This Sphere also visually indicates the range of the Tower
		SphereComponent->SetSphereRadius(BaseRange);
		SphereComponent->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
		SphereComponent->SetWorldLocation(Location);
		SphereComponent->SetRelativeRotation(Rotation);
	}
}

void ATower::ToggleDisplayRange()
{
	// TODO Doesn't work get rid of this...
	SphereComponent->ToggleVisibility();
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
