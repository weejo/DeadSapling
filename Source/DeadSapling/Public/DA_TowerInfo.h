// ©2022 The Icecream Connection

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Runtime/CoreUObject/Public/UObject/SoftObjectPtr.h"
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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TowerInfo")
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TowerInfo", meta=(AllowedClasses="StaticMesh"))
	FSoftObjectPath TowerMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TowerInfo")
	float baseDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TowerInfo")
	float baseRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "TowerInfo | DamageType")
	TEnumAsByte<DamageType> damageType;
};
