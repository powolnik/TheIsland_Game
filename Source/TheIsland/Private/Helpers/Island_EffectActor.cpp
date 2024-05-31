// RW&MH

#include "Helpers/Island_EffectActor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/Island_AttributeSet.h"
#include "Components/SphereComponent.h"


AIsland_EffectActor::AIsland_EffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

void AIsland_EffectActor::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* ASInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UIsland_AttributeSet* Island_AttributeSet = Cast<UIsland_AttributeSet>(ASInterface->GetAbilitySystemComponent()->GetAttributeSet(UIsland_AttributeSet::StaticClass()));
		UIsland_AttributeSet* MutableIsland_AttributeSet = const_cast<UIsland_AttributeSet*>(Island_AttributeSet);
		MutableIsland_AttributeSet->SetHealth(Island_AttributeSet->GetHealth() + 20.f);
		Destroy();
	}
}

void AIsland_EffectActor::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void AIsland_EffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AIsland_EffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AIsland_EffectActor::EndOverlap);
}

