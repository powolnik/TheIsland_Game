#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TheIslandPlayerController.generated.h"

/**
 * @file TheIslandPlayerController.h RANDOMWORDS
 * RANDOM WORDSRANDOM WORDSRANDOM WORDSRANDOM WORDSRANDOM WORDS
 * 
 * in the meanwhile, it will demonstrate usage of Doxygen-style comments
 * and `#pragma region` for organizing code
 */

/**
 * @brief ForwardDeclarations
 * 
 * This region contains forward declarations of classes and structs.
 * These declarations are used to inform the compiler about the existence
 * of these types before they are fully defined.
 * 
 * @note You can use `#pragma region` to create named regions of code that
 *       are foldable in supporting IDEs, enhancing code organization and readability.
 */

/*#ifndef*/
#pragma region ForwardDeclaration

	/**
	 * @class UInputMappingContext
	 * @brief Forward declaration of UInputMappingContext class.
	 *
	 * UInputMappingContext is used for mapping input actions within the input system.
	 *	DUPA
	 */
class UInputMappingContext; ///hover over class name too see how it works in tooltips

	/**
	 * @class UEnhancedInputLocalPlayerSubsystem
	 * @brief Forward declaration of UEnhancedInputLocalPlayerSubsystem class.
	 *
	 * UEnhancedInputLocalPlayerSubsystem manages enhanced input handling for a local player.
	 */
class UEnhancedInputLocalPlayerSubsystem;

	/**
	* @struct FInputActionsValue
	* @brief Forward declaration of FInputActionsValue struct.
	*
	* FInputActionsValue holds values related to input actions.
	*/
struct FInputActionsValue;

/*#endif*/
#pragma endregion ForwardDeclaration 

UCLASS()
class THEISLAND_API ATheIslandPlayerController : public APlayerController
{
	GENERATED_BODY()	
public:
	ATheIslandPlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> PlayerInputContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> InputSubsystem;



private:
	void Move(const FInputActionsValue& InputActionValue);
	void SetupInputSubsystem();
	void SetupMouseCursorProperties();

};
