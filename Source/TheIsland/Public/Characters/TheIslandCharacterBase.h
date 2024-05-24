// RW&MH
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TheIslandCharacterBase.generated.h"

UCLASS(Abstract)
class THEISLAND_API ATheIslandCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ATheIslandCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Character")
	TObjectPtr<USkeletalMeshComponent> RandomMesh;
	
};
