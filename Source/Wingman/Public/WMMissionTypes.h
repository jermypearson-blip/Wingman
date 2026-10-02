// All Rights Reserved @Picasso Rayne Studios LLC 2026.

#pragma once

#include "CoreMinimal.h"
#include "WMMissionTypes.generated.h"

// Mission type enumeration
UENUM(BlueprintType)
enum class EMissionType : uint8
{
	Collect UMETA(DisplayName = "Collect"),
	Eliminate UMETA(DisplayName = "Eliminate"),
	Explore UMETA(DisplayName = "Explore"),
	Escort UMETA(DisplayName = "Escort"),
	Defend UMETA(DisplayName = "Defend")
};

// Mission data structure
USTRUCT(BlueprintType)
struct FMissionData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	FString MissionName = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	FString MissionDescription = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	EMissionType MissionType = EMissionType::Collect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	int32 Difficulty = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	int32 RewardXP = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	int32 MissionScore = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	int32 MissionKills = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	int32 MissionDeaths = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	int32 MissionObjectivesCompleted = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	bool bIsActive = false;

	// Standard C++ member methods (UFUNCTION is omitted here)
	void ActivateMission()
	{
		bIsActive = true;
	}

	void DeactivateMission()
	{
		bIsActive = false;
	}

	void SetMissionDetails(const FString& Name, const FString& Description, EMissionType Type, int32 InDifficulty, int32 InRewardXP)
	{
		MissionName = Name;
		MissionDescription = Description;
		MissionType = Type;
		Difficulty = InDifficulty;
		RewardXP = InRewardXP;
	}

	void GetMissionDetails(FString& OutName, FString& OutDescription, EMissionType& OutType, int32& OutDifficulty, int32& OutRewardXP) const
	{
		OutName = MissionName;
		OutDescription = MissionDescription;
		OutType = MissionType;
		OutDifficulty = Difficulty;
		OutRewardXP = RewardXP;
	}
};