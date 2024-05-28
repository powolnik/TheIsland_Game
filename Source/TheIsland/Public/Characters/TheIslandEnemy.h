// RW&MH

#pragma once

#include "CoreMinimal.h"
#include "Characters/TheIslandCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "TheIslandEnemy.generated.h"


UCLASS()
class THEISLAND_API ATheIslandEnemy : public ATheIslandCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	ATheIslandEnemy();
	virtual void HighlightActor(bool bHighlight) override;
};
