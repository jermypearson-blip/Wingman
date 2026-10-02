// All Rights Reserved @Picasso Rayne Studios LLC 2026.
#include "WMGameInstance.h"

void UWMGameInstance::AddXP(double Amount)
{
	// Only add XP if the amount is positive
	if (Amount > 0.0)
	{
		XP += Amount;
	}
}

void UWMGameInstance::SubtractXP(double Amount)
{
	// Only subtract XP if the amount is positive, and clamp to 0
	if (Amount > 0.0)
	{
		XP = FMath::Max(0.0, XP - Amount);
	}
}

void UWMGameInstance::SetXP(double Amount)
{
	// Set XP directly, ensuring it never goes below 0
	XP = FMath::Max(0.0, Amount);
}

void UWMGameInstance::ResetXP()
{
	// Reset XP to zero
	XP = 0.0;
}