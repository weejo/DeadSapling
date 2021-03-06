// ©2022 The Icecream Connection

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "../LogMacros.h"
#include "../DataStructures/DA_TowerInfo.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"

#include "Tower.generated.h"

UCLASS()
class DEADSAPLING_API ATower : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Tower")
		TSubclassOf<ABaseAmmunition> BaseAmmunition;

	UPROPERTY(BlueprintReadOnly)
		float BaseDamage;

	UPROPERTY(BlueprintReadOnly)
		float BaseSpeed;

	UPROPERTY(BlueprintReadOnly)
		float BaseRange;
	UPROPERTY(BlueprintReadOnly)
		TEnumAsByte<Element> DamageType;
public:	
	// Sets default values for this actor's properties
	ATower();

	UFUNCTION()
		void Initialize(UDA_TowerInfo* TowerInfo, FVector Location, FRotator Rotation);

	void ToggleDisplayRange();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tower")
		UStaticMeshComponent* TowerMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tower")
		USphereComponent* SphereComponent;

	UPROPERTY()
	bool IsInitialized = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
