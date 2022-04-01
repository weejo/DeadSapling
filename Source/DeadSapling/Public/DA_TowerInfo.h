// ©2022 The Icecream Connection

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/StaticMesh.h"
#include "DA_TowerInfo.generated.h"


UENUM(BlueprintType)
enum DamageType
{
	Normal,
	Fire,
	Electro,
};


/**
 * 
 */
UCLASS(BlueprintType)
class DEADSAPLING_API UDA_TowerInfo : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMesh* mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float baseDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float baseRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DamageType")
	TEnumAsByte<DamageType> damageType;
};
