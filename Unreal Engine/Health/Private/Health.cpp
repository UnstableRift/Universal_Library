// Fill out your copyright notice in the Description page of Project Settings.


#include "Health.h"
#include "Armor.h"

// Sets default values for this component's properties
UHealth::UHealth()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Decrease health by float. Checks for armor.
void UHealth::ReduceHealth(float DamageTaken)
{
	if (!bIgnoreDamage)
	{
		if (GetArmorComponent() == false)
		{
			ClaculateHealth(DamageTaken, 0);
		}
		else
		{
			ClaculateHealth(DamageTaken, ArmorPoints);
		}
	}
}

// Add to HealthPoints, limited by MaxHealth.
void UHealth::RestoreHealth(float RestoreHealthAmount)
{
	HealthPoints = HealthPoints + RestoreHealthAmount;
	if (HealthPoints >= MaxHealth)
	{
		HealthPoints = MaxHealth;
	}
}

bool UHealth::GetArmorComponent()
{
	AActor* ParentActor = this->GetOwner();
	if (!ParentActor)
	{
		return 0;
	}
	UArmor* ArmorComponent = ParentActor->GetComponentByClass<UArmor>();
	if (ArmorComponent == nullptr)
	{
		return false;
	}
	else
	{
		GetArmorvalue();
		return true;
	}
}

void UHealth::GetArmorvalue()
{
	AActor* ParentActor = this->GetOwner();
	UArmor* ArmorComponent = ParentActor->GetComponentByClass<UArmor>();
	if (ArmorComponent->State == EArmorStates::NoArmor)
	{
		ArmorPoints = 0;
	}
	else if (ArmorComponent->State == EArmorStates::LevelOne)
	{
		ArmorPoints = 1;
	}
	else if (ArmorComponent->State == EArmorStates::LevelTwo)
	{
		ArmorPoints = 1.5;
	}
	else if (ArmorComponent->State == EArmorStates::LevelTre)
	{
		ArmorPoints = 2.5;
	}
	else
	{
		ArmorPoints = 0;
	}
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("%f"), ArmorPoints));
}


void UHealth::ClaculateHealth(float PassDamage, float Armor)
{
	if (PassDamage <= Armor)
	{
		// Do nothing.
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Damage Negated")));
	}
	else if (HealthPoints >= 0.0f)
	{
		HealthPoints = HealthPoints + (ArmorPoints - PassDamage);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("%f"), PassDamage));
	}
	else if (HealthPoints <= 0.0f)
	{
		// Implement custom death functionality...
	}
}

// Called when the game starts
void UHealth::BeginPlay()
{
	Super::BeginPlay();
	// This sets health back to max limit if healing goes over.
	if (HealthPoints >= MaxHealth)
	{
		HealthPoints = MaxHealth;
	}
}


// Called every frame
void UHealth::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

