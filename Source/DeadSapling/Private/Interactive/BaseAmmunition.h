// ©2022 The Icecream Connection

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseAmmunition.generated.h"

UCLASS()
class DEADSAPLING_API ABaseAmmunition : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseAmmunition();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
