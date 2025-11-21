// Copyrights to Mahdi94x based on Course Make exciting multiplayer and single player games with the Gameplay Ability System in UE5 By Stephen Ulibarri

#include "UI/CC_WidgetComponent.h"

#include "AbilitySystem/CC_AbilitySystemComponent.h"
#include "AbilitySystem/CC_AttributeSet.h"
#include "Characters/CC_BaseCharacter.h"

void UCC_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();
	
	InitAbilitySystemData();
	
	if (!IsASCInitialized())
	{
		CrashCharacter->OnASCInitialized.AddDynamic(this, &ThisClass::OnASCInitialized);
		return;
	}
	InitializeAttributeDelegate();
}

void UCC_WidgetComponent::InitAbilitySystemData()
{
	CrashCharacter = Cast<ACC_BaseCharacter>(GetOwner());
	AttributeSet = Cast<UCC_AttributeSet>(CrashCharacter->GetAttributeSet());
	AbilitySystemComponent = Cast<UCC_AbilitySystemComponent>(CrashCharacter->GetAbilitySystemComponent());
}

bool UCC_WidgetComponent::IsASCInitialized() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}

void UCC_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AttributeSet = Cast<UCC_AttributeSet>(AS);
	AbilitySystemComponent = Cast<UCC_AbilitySystemComponent>(ASC);
	
	if (!IsASCInitialized()) return;
	InitializeAttributeDelegate();
}

void UCC_WidgetComponent::InitializeAttributeDelegate()
{
	if (!AttributeSet->bAttributeInitialized)
	{
		AttributeSet->OnAttributeInitialized.AddDynamic(this, &ThisClass::BindToAttributeChanged);
	}
	else
	{
		BindToAttributeChanged();
	}
}

void UCC_WidgetComponent::BindToAttributeChanged()
{
	// TODO: Listen for changed to gameplay attributes and update our widget accordingly
	
}



