// RW&MH

#pragma once

#include "CoreMinimal.h"
#include "HighlightActorInterface.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UHighlightActorInterface
{
	GENERATED_BODY()
};


class THEISLAND_API IEnemyInterface
{
	GENERATED_BODY()

public:
	virtual void HighlightActor(bool bHighlight = false) = 0;
};
