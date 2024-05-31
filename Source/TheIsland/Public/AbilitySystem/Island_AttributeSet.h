// RW&MH

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Island_AttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class THEISLAND_API UIsland_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UIsland_AttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "BaseAttributes|Health")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UIsland_AttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "BaseAttributes|Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UIsland_AttributeSet, MaxHealth);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "BaseAttributes|Mana")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UIsland_AttributeSet, Mana);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "BaseAttributes|Mana")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UIsland_AttributeSet, MaxMana);


#pragma region BaseAttributes_OnRep
	UFUNCTION(Category = "BaseAttributes|Health")
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION(Category = "BaseAttributes|Health")
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION(Category = "BaseAttributes|Mana")
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION(Category = "BaseAttributes|Mana")
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
#pragma endregion BaseAttributes_OnRep
};
