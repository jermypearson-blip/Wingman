// All Rights Reserved @Picasso Rayne Studios LLC 2026.

#include "WMGameInstanceSubsystem.h"

UWMGameInstanceSubsystem::UWMGameInstanceSubsystem()
{
	TotalXP = 0.0;
	bHasActiveMission = false;
}

void UWMGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// Put initial loading logic here (e.g., loading saved stats from SaveGame)
	UE_LOG(LogTemp, Log, TEXT("WMGameInstanceSubsystem Initialized."));
}

void UWMGameInstanceSubsystem::Deinitialize()
{
	// Clean up logic on GameInstance shutdown
	Super::Deinitialize();
}

void UWMGameInstanceSubsystem::SetActiveMission(const FMissionData& MissionData)
{
	ActiveMission = MissionData;
	bHasActiveMission = true;

	// Broadcast mission start to UI or other listening Blueprints
	OnMissionStarted.Broadcast(ActiveMission);
}

void UWMGameInstanceSubsystem::CompleteActiveMission()
{
	if (!bHasActiveMission)
	{
		return;
	}

	bHasActiveMission = false;

	// Automatically reward XP based on mission score
	AddXP(static_cast<double>(ActiveMission.MissionScore));

	// Broadcast completion event
	OnMissionCompleted.Broadcast(ActiveMission);
}

void UWMGameInstanceSubsystem::AddXP(double Amount)
{
	if (Amount <= 0.0)
	{
		return;
	}

	TotalXP += Amount;

	// Broadcast updated XP total to UI widgets
	OnXPChanged.Broadcast(TotalXP);
}

void UWMGameInstanceSubsystem::SetXP(double Amount)
{
	TotalXP = FMath::Max(0.0, Amount);
	OnXPChanged.Broadcast(TotalXP);
}