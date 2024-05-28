// RW&MH

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HighlightActorInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHighlightActorInterface : public UInterface
{
	GENERATED_BODY()
};


class THEISLAND_API IHighlightActorInterface
{
	GENERATED_BODY()

public:
	/*virtual void HighlightActor(bool bHighlight = false) = 0;*/
	virtual void HighlightActor(bool bHighlight = false) = 0;
	/*virtual void UnHighlightActor(bool bHighlight) = 0;*/
};
