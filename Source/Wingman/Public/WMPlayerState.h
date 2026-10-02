// All Rights Reserved @Picasso Rayne Studios LLC 2026.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "WMPlayerState.generated.h"

UCLASS()
class WINGMAN_API AWMPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AWMPlayerState();

	// Stat Modification Methods
	UFUNCTION(BlueprintCallable, Category = "Player Stats")
	void AddScoreAmount(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Player Stats")
	void AddKill();

	UFUNCTION(BlueprintCallable, Category = "Player Stats")
	void AddDeath();

	UFUNCTION(BlueprintCallable, Category = "Player Stats")
	void AddObjectiveCompleted();

	UFUNCTION(BlueprintCallable, Category = "Player Stats")
	void ResetMissionStats();

	// Inline Getters
	UFUNCTION(BlueprintPure, Category = "Player Stats")
	FORCEINLINE int32 GetKills() const { return Kills; }

	UFUNCTION(BlueprintPure, Category = "Player Stats")
	FORCEINLINE int32 GetDeaths() const { return Deaths; }

	UFUNCTION(BlueprintPure, Category = "Player Stats")
	FORCEINLINE int32 GetObjectivesCompleted() const { return ObjectivesCompleted; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Stats")
	int32 Kills = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Stats")
	int32 Deaths = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Stats")
	int32 ObjectivesCompleted = 0;
};