#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TheIslandPlayerController.generated.h"

class UInputMappingContext;

UCLASS()
class THEISLAND_API ATheIslandPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATheIslandPlayerController();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> TheIslandPlayerContext;

};
