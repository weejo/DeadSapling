// ©2022 The Icecream Connection


#include "Lighting/RouteLighting.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
ARouteLighting::ARouteLighting()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void ARouteLighting::BeginPlay()
{
	Super::BeginPlay();
	
}

