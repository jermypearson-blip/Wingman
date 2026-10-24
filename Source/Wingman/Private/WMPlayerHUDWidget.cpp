// All Rights Reserved @Picasso Rayne Studios LLC 2026. 


#include "WMPlayerHUDWidget.h"
#include "Components/ProgressBar.h"
#include "WMHealthComponent.h"
#include "WMCharacter.h"
#include "WMHealthComponent.h"

void UWMPlayerHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	// Step A: Find the player character that owns this widget
	if (AWMCharacter* Character = Cast<AWMCharacter>(GetOwningPlayerPawn)))
	{
		if (UWMHealthComponent* HealthComp = Character->GetHealthComponnet())
		{
			HealthComp->OnHealthChanged.AddDynamic(this, &UWMPlayerHUDWidget::OnHealthChanged);
	
			OnHealthChanged(HealthComp->GetHealth(), HealthComp->GetHealth());
		}

	}
}


void UWMPlayerHUDWidget::OnHealthChanged(float OldHealth, float NewHealth)
{
	if HealthBar)
	{
		HealthBar->SetPercent(NewHealth);
	}
}

