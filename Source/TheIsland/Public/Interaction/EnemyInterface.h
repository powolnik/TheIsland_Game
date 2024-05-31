// RW&MH

#pragma once

#include "CoreMinimal.h"
#include "HighlightActorInterface.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"


UINTERFACE(MinimalAPI)
class UEnemyInterface : public UHighlightActorInterface
{
	GENERATED_BODY()
};


class THEISLAND_API IEnemyInterface : public IHighlightActorInterface
{
	GENERATED_BODY()
};
