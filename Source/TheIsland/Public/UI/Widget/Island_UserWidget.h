// RW&MH

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Island_UserWidget.generated.h"


UCLASS()
class THEISLAND_API UIsland_UserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Island|Widgets|Functions")
	void SetWidgetController(UObject* InWidgetController);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Island|Widgets")
	void WidgetControllerSet();

public:
	UPROPERTY(BlueprintReadOnly, Category = "Island|Widgets")
	TObjectPtr<UObject> WidgetController;
	
};
