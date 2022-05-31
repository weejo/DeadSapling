// ©2022 The Icecream Connection


#include "BaseAmmunition.h"

UENUM(BlueprintType)
enum class EAmmunitionType : uint8
{
	E_Flower	UMETA(DisplayName = "FLOWER")
};


// Sets default values
ABaseAmmunition::ABaseAmmunition()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseAmmunition::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseAmmunition::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

