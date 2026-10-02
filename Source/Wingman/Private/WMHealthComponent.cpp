// All Rights Reserved @Picasso Rayne Studios LLC 2026.

#include "WMHealthComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UWMHealthComponent::UWMHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.TickInterval = 0.0f;

	// Enable replication
	SetIsReplicated(true);
}

// Called when the game starts
void UWMHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// Clamp health to valid range
	CurrentHealth = FMath::Clamp(CurrentHealth, 0.0f, MaxHealth);
}

// Called every frame
void UWMHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// Replication setup
void UWMHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate CurrentHealth to all clients
	DOREPLIFETIME(UWMHealthComponent, CurrentHealth);
}

// Function to handle taking damage
void UWMHealthComponent::TakeDamage(float DamageAmount)
{
	// Only the server processes damage
	if (GetOwnerRole() == ROLE_Authority)
	{
		ServerSetHealth(CurrentHealth - DamageAmount);
	}
}

// Server function to set health
void UWMHealthComponent::ServerSetHealth_Implementation(float NewHealth)
{
	SetHealth(NewHealth);
}

// Internal function to set health and clamp it between 0 and MaxHealth
void UWMHealthComponent::SetHealth(float NewHealth)
{
	float OldHealth = CurrentHealth;
	CurrentHealth = FMath::Clamp(NewHealth, 0.0f, MaxHealth);

	// Broadcast to all listeners if health actually changed
	if (OldHealth != CurrentHealth)
	{
		OnHealthChanged.Broadcast(OldHealth, CurrentHealth);
	}
}

// Function to heal the actor
void UWMHealthComponent::Heal(float HealAmount)
{
	if (HealAmount > 0.0f)
	{
		SetHealth(CurrentHealth + HealAmount);
	}
}

// Function called when CurrentHealth is replicated to clients
void UWMHealthComponent::OnRep_Health()
{
	// OnRep_Health is automatically called on clients when CurrentHealth changes
	// Broadcast the change to UI or other systems
	OnHealthChanged.Broadcast(0.0f, CurrentHealth);
}
