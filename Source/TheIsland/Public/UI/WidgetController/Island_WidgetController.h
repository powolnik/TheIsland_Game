// RW&MH

#pragma once

#include "CoreMinimal.h"
#include "Island_WidgetController.generated.h"

class UAbilitySystemComponent;


USTRUCT(BlueprintType)
struct FWidgetControllerParameters
{
	GENERATED_BODY()

	FWidgetControllerParameters() {}
	FWidgetControllerParameters(APlayerController* PController, APlayerState* PState)
	: PlayerController(PController), PlayerState(PState) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite/*, Category = "Island|WidgetController|Parameters"*/)
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite/*, Category = "Island|WidgetController|Parameters"*/)
	TObjectPtr<APlayerState> PlayerState = nullptr; 
};


UCLASS()
class THEISLAND_API UIsland_WidgetController : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable/*, Category = "Island|WidgetController|Functions"*/)
	void SetWidgetControllerParameters(const FWidgetControllerParameters& WCParameters);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Island|WidgetController|Dependencies")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category = "Island|WidgetController|Dependencies")
	TObjectPtr<APlayerState> PlayerState;

	//UPROPERTY(BlueprintReadOnly, Category = "Island|WidgetController|Dependencies")
	//TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	//UPROPERTY(BlueprintReadOnly, Category = "Island|WidgetController|Dependencies")
	//TObjectPtr<>
};
