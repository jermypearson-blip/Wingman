// All Rights Reserved @Picasso Rayne Studios LLC 2026. 

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WMPlayerHUDWidget.generated.h"

/**
 * 
 */

class UProgressBar;
class UTextBlock;
class UWMHealthComponent;

UCLASS()
class WINGMAN_API UWMPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	// 1. Lifecycle hook: Runs when the widget is constructed
	virtual void NativeConstruct() override;

	// 2. The Listener: Must be a UFUNCTION snd takes two floats
	UFUNCTION()
	void OnHealthChanged(float OldHealth, float NewHealth);

	UFUNCTION(BlueprintCallable)
	void UpdateAmmo();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	TObjectPtr<UprogressBar> HealthBar;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	TObjectPtr<UprogressBar> HealthText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	TObjectPtr<UprogressBar> AmmoText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	TObjectPtr<UprogressBar> ScoreText;
	
	
}
