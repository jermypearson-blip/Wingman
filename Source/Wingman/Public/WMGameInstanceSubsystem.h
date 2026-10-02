// All Rights Reserved @Picasso Rayne Studios LLC 2026.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WMGameInstance.h" // Contains FMissionData definition
#include "WMGameInstanceSubsystem.generated.h"

// Dynamic Multicast Delegates for Blueprint UI / Event Listening
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnXPChangedSignature, double, NewXP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMissionStateChangedSignature, const FMissionData&, MissionData);

UCLASS()
class WINGMAN_API UWMGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UWMGameInstanceSubsystem();

	// Lifecycle Overrides
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// Active Mission Operations
	UFUNCTION(BlueprintCallable, Category = "Wingman|Mission Management")
	void SetActiveMission(const FMissionData& MissionData);

	UFUNCTION(BlueprintCallable, Category = "Wingman|Mission Management")
	void CompleteActiveMission();

	UFUNCTION(BlueprintPure, Category = "Wingman|Mission Management")
	FMissionData GetActiveMission() const { return ActiveMission; }

	UFUNCTION(BlueprintPure, Category = "Wingman|Mission Management")
	bool HasActiveMission() const { return bHasActiveMission; }

	// Meta Progression (XP)
	UFUNCTION(BlueprintCallable, Category = "Wingman|Progression")
	void AddXP(double Amount);

	UFUNCTION(BlueprintCallable, Category = "Wingman|Progression")
	void SetXP(double Amount);

	UFUNCTION(BlueprintPure, Category = "Wingman|Progression")
	double GetXP() const { return TotalXP; }

public:
	// Event Dispatchers for UI / Blueprints
	UPROPERTY(BlueprintAssignable, Category = "Wingman|Events")
	FOnXPChangedSignature OnXPChanged;

	UPROPERTY(BlueprintAssignable, Category = "Wingman|Events")
	FOnMissionStateChangedSignature OnMissionStarted;

	UPROPERTY(BlueprintAssignable, Category = "Wingman|Events")
	FOnMissionStateChangedSignature OnMissionCompleted;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wingman|Mission")
	FMissionData ActiveMission;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wingman|Mission")
	bool bHasActiveMission = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wingman|Progression")
	double TotalXP = 0.0;
};