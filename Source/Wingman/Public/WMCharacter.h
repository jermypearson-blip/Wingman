// All Rights Reserved @Picasso Rayne Studios LLC 2026.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WMCharacter.generated.h"

class UWMHealthComponent;

UCLASS()
class WINGMAN_API AWMCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWMCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Getter for Health Component */
	FORCEINLINE class UWMHealthComponent* GetHealthComponent() const { return HealthComponent; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// === THIS WAS MISSING ===
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UWMHealthComponent* HealthComponent;
};