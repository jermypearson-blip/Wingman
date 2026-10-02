// All Rights Reserved @Picasso Rayne Studios LLC 2026.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "WMMissionTypes.h"
#include "WMGameInstance.generated.h"

UCLASS()
class WINGMAN_API UWMGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	// XP getter - returns current experience points
	UFUNCTION(BlueprintPure, Category = "Player Stats")
	double GetXP() const { return XP; }

	// Add experience points
	UFUNCTION(BlueprintCallable, Category = "Player Stats")
	void AddXP(double Amount);

	// Subtract experience points
	UFUNCTION(BlueprintCallable, Category = "Player Stats")
	void SubtractXP(double Amount);

	// Set experience points directly
	UFUNCTION(BlueprintCallable, Category = "Player Stats")
	void SetXP(double Amount);

	// Reset experience points to zero
	UFUNCTION(BlueprintCallable, Category = "Player Stats")
	void ResetXP();

protected:
	// Player's experience points
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	double XP = 0.0;

	// Latest mission data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	FMissionData LastMissionData;
};