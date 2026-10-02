// All Rights Reserved @Picasso Rayne Studios LLC 2026.

#include "WMGameModeBase.h"
#include "WMCharacter.h"
#include "WMPlayerController.h"
#include "WMPlayerState.h"      // Added
#include "WMGameStateBase.h"   // Added
#include "WMGameInstance.h"    // Added
#include "TimerManager.h"
#include "Engine/World.h"

AWMGameModeBase::AWMGameModeBase()
{
	DefaultPawnClass = AWMCharacter::StaticClass();
	PlayerControllerClass = AWMPlayerController::StaticClass();
	PlayerStateClass = AWMPlayerState::StaticClass();
	GameStateClass = AWMGameStateBase::StaticClass();
	// REMOVED: GameInstanceClass = UWMGameInstance::StaticClass(); 
	// (Set GameInstance in Project Settings -> Maps & Modes instead)

	RespawnDelay = 5.0f;
	CurrentMissionName = TEXT("None");
	PlayerScore = 0;
	bIsPlayerAlive = true;
	bIsPlayerInMission = false;
	bIsPlayerInCombat = false;
	bIsCausingAttention = false;

	MissionScoreDuringMission = 0;
	MissionKillsDuringMission = 0;
	MissionDeathsDuringMission = 0;
	MissionObjectivesCompletedDuringMission = 0;
}

void AWMGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void AWMGameModeBase::OnPlayerDied(AWMCharacter* DeadCharacter)
{
	if (!DeadCharacter)
	{
		return;
	}

	bIsPlayerAlive = false;
	MissionDeathsDuringMission++;

	AWMPlayerController* PC = Cast<AWMPlayerController>(DeadCharacter->GetController());
	if (PC)
	{
		FTimerHandle RespawnTimerHandle;
		FTimerDelegate RespawnDelegate;
		RespawnDelegate.BindUFunction(this, FName("RespawnPlayer"), PC);

		GetWorldTimerManager().SetTimer(RespawnTimerHandle, RespawnDelegate, RespawnDelay, false);
	}
}

void AWMGameModeBase::StartCurrentMission(const FMissionData& MissionData)
{
	CurrentMissionName = MissionData.MissionName;
	bIsPlayerInMission = true;

	MissionScoreDuringMission = 0;
	MissionKillsDuringMission = 0;
	MissionDeathsDuringMission = 0;
	MissionObjectivesCompletedDuringMission = 0;

	switch (MissionData.MissionType)
	{
	case EMissionType::Collect:
		break;

	case EMissionType::Eliminate:
		break;

	case EMissionType::Explore:
		break;

	case EMissionType::Escort:
		break;

	case EMissionType::Defend:
		break;

	default:
		break;
	}
}

void AWMGameModeBase::CompleteCurrentMission(AWMPlayerController* InstigatorController)
{
	bIsPlayerInMission = false;
	bIsPlayerInCombat = false;
	bIsCausingAttention = false;

	UpdatePlayerScore(PlayerScore + MissionScoreDuringMission);
}

void AWMGameModeBase::UpdatePlayerScore(int32 NewScore)
{
	PlayerScore = NewScore;

	if (GetWorld() && GetWorld()->GetFirstPlayerController())
	{
		if (AWMPlayerState* PS = Cast<AWMPlayerState>(GetWorld()->GetFirstPlayerController()->PlayerState))
		{
			PS->SetScore(NewScore);
		}
	}

	CheckWinCondition();
}

void AWMGameModeBase::CheckWinCondition()
{
	// Win condition is mission completion for co-op games!
	if (!bIsPlayerInMission)
	{
		UE_LOG(LogTemp, Warning, TEXT("Mission Complete!"));
	}
}

void AWMGameModeBase::RespawnPlayer(AWMPlayerController* Controller)
{
	if (!Controller)
	{
		return;
	}

	bIsPlayerAlive = true;
	RestartPlayer(Controller);
}

void AWMGameModeBase::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	AWMPlayerController* ExitingPlayerController = Cast<AWMPlayerController>(Exiting);
	if (ExitingPlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player left the co-op session!"));
	}
}




void AWMGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (!NewPlayer)
	{
		return;
	}

	AWMPlayerController* WMPlayerController = Cast<AWMPlayerController>(NewPlayer);
	if (WMPlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player joined co-op session!"));

		bIsPlayerAlive = true;
		PlayerScore = 0;
		bIsPlayerInMission = false;
		bIsPlayerInCombat = false;
		bIsCausingAttention = false;
	}
}