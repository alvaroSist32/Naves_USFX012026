#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Naves_USFX012026GameMode.generated.h"

UCLASS()
class NAVES_USFX012026_API ANaves_USFX012026GameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};