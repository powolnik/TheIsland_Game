// RW&MH

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HighlightActorInterface.generated.h"


UINTERFACE(MinimalAPI)
class UHighlightActorInterface : public UInterface
{
	GENERATED_BODY()
};


class THEISLAND_API IHighlightActorInterface
{
	GENERATED_BODY()

public:
	virtual void HighlightActor(bool bHighlight = false) = 0;
};
