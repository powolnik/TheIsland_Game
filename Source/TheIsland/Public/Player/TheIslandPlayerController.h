// RW&MH

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "Interaction/EnemyInterface.h"
#include "TheIslandPlayerController.generated.h"

#pragma region ForwardDeclarations
	class UInputMappingContext;
	class UEnhancedInputLocalPlayerSubsystem;
	class UInputAction;

	struct FInputActionsValue;
#pragma endregion 


UCLASS()
class THEISLAND_API ATheIslandPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATheIslandPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

private:
  	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> PlayerInputContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;

	
	UFUNCTION()
	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	void SetupInputSubsystem();
	void SetupMouseCursorProperties();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
};
