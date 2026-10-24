// All Rights Reserved @Picasso Rayne Studios LLC 2026. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "DamageInterface.generated.h"

USTRUCT(BlueprintType)
struct FWMDamageContext
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damage")"
	float DamageAmount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damage")
	AActor* DamageCauser;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damage")
	AActor* DamageInstigator;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damage")
	FVector HitLocation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damage")
	FVector HitNormal;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damage")
	FName BoneName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Damage")
	TSubclassOf<UDamageType> DamageTypeClass;
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDamageInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WINGMAN_API IDamageInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Allows both C++ and Blueprint classes to implement this function
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Damage")
	void ApplyDamage(const FWMDamageContext& DamageContext);

	
};
