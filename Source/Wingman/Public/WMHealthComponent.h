// All Rights Reserved @Picasso Rayne Studios LLC 2026.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WMHealthComponent.generated.h"

// Delegate for health changes
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float, OldHealth, float, NewHealth);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WINGMAN_API UWMHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UWMHealthComponent();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Health management functions
	UFUNCTION(BlueprintCallable, Category = "Health")
	void TakeDamage(float DamageAmount);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void Heal(float HealAmount);

	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetHealth() const { return CurrentHealth; }

	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetMaxHealth() const { return MaxHealth; }

	// Delegate broadcast when health changes
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthChanged OnHealthChanged;

protected:
	// Replicated health value
	UPROPERTY(ReplicatedUsing = OnRep_Health, BlueprintReadOnly, Category = "Health")
	float CurrentHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float MaxHealth = 100.0f;

	// Called on clients when health is replicated
	UFUNCTION()
	void OnRep_Health();

	// Server RPC to set health
	UFUNCTION(Server, Reliable)
	void ServerSetHealth(float NewHealth);

	void ServerSetHealth_Implementation(float NewHealth);

	// Internal function to set health
	void SetHealth(float NewHealth);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};