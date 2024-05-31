// RW&MH

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "EnemyCharacter.generated.h"


UCLASS()
class THEISLAND_API AEnemyCharacter : public ACharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

	/** Enemy Interface */		
	virtual void HighlightActor(bool bHighlight) override;

protected:
	virtual void BeginPlay() override;
};
