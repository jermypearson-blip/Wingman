// All Rights Reserved @Picasso Rayne Studios LLC 2026.

#include "WMCharacter.h"
#include "WMHealthComponent.h" // <--- Include header here to access component functions/methods


// Sets default values
AWMCharacter::AWMCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create and attach the health component
	HealthComponent = CreateDefaultSubobject<UWMHealthComponent>(TEXT("HealthComponent"));
}

// Called when the game starts or when spawned
void AWMCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWMCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWMCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

