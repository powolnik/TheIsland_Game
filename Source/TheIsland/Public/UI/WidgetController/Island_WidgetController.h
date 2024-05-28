// RW&MH

#pragma once

#include "CoreMinimal.h"
#include "Island_WidgetController.generated.h"


UCLASS()
class THEISLAND_API UIsland_WidgetController : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Island|WidgetController|Dependencies")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category = "Island|WidgetController|Dependencies")
	TObjectPtr<APlayerState> PlayerState;

	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
