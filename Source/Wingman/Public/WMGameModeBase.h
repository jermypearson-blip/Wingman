// All Rights Reserved @Picasso Rayne Studios LLC 2026.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WMGameInstance.h" // Provides FMissionData & EMissionType
#include "WMGameModeBase.generated.h"

class AWMCharacter;
class AWMPlayerController;

UCLASS()
class WINGMAN_API AWMGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AWMGameModeBase();

	// Called when a player joins
	UFUNCTION(BlueprintCallable, Category = "Game Rules")
	virtual void PostLogin(APlayerController* NewPlayer) override;

	// Called when a player leaves
	UFUNCTION(BlueprintCallable, Category = "Game Rules")
	virtual void Logout(AController* Exiting) override; 

	UFUNCTION(BlueprintCallable, Category = "Game Rules")
	void OnPlayerDied(AWMCharacter* DeadCharacter);

	UFUNCTION(BlueprintCallable, Category = "Game Rules")
	void StartCurrentMission(const FMissionData& MissionData);

	UFUNCTION(BlueprintCallable, Category = "Game Rules")
	void CompleteCurrentMission(AWMPlayerController* InstigatorController);

	UFUNCTION(BlueprintCallable, Category = "Player Stats")
	void UpdatePlayerScore(int32 NewScore);

	FORCEINLINE int32 GetScoreToWin() const { return ScoreToWin; }

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void RespawnPlayer(AWMPlayerController* Controller);

	UFUNCTION()
	void CheckWinCondition();

	UPROPERTY(EditDefaultsOnly, Category = "Multiplayer")
	int32 MaxPlayers = 4;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Multiplayer")
	bool bIsNetworkGame = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Multiplayer")
	bool bIsSplitScreen = false;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Rules")
	int32 ScoreToWin = 100;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Rules")
	float RespawnDelay = 5.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Rules")
	FString CurrentMissionName = TEXT("");

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats")
	int32 PlayerScore = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Stats")
	FString PlayerName = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Stats")
	bool bIsPlayerAlive = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Stats")
	bool bIsPlayerInMission = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Stats")
	bool bIsPlayerInCombat = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Stats")
	bool bIsCausingAttention = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	int32 MissionScoreDuringMission = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	int32 MissionKillsDuringMission = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	int32 MissionDeathsDuringMission = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	int32 MissionObjectivesCompletedDuringMission = 0;
};