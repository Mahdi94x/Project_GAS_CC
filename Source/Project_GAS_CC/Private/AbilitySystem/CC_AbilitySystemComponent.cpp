// Copyrights to Mahdi94x based on Course Make exciting multiplayer and single player games with the Gameplay Ability System in UE5 By Stephen Ulibarri

#include "AbilitySystem/CC_AbilitySystemComponent.h"

UCC_AbilitySystemComponent::UCC_AbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UCC_AbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UCC_AbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

