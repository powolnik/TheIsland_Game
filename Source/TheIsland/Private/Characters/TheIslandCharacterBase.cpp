// RW&MH
#include "Characters/TheIslandCharacterBase.h"

ATheIslandCharacterBase::ATheIslandCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	RandomMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SomeComp");
	RandomMesh->SetupAttachment(GetMesh(), FName("SomeCompSocket"));
	RandomMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void ATheIslandCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}


