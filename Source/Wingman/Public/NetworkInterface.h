// All Rights Reserved @Picasso Rayne Studios LLC 2026. 

#pragma once

#include "CoreMinimal.h"
#include "WMGameInstance.h"
#include "UObject/Interface.h"

#include "NetworkInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UNetworkInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WINGMAN_API INetworkInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	UFUNCTION(BlueprintPure, Category = "Player Stats")
	double GetXP() const { return XP; }
public:
	
	
};
