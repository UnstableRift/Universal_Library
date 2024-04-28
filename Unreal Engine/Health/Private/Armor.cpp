// Fill out your copyright notice in the Description page of Project Settings.


#include "Armor.h"

// Sets default values for this component's properties
UArmor::UArmor()
{
	PrimaryComponentTick.bCanEverTick = false;

	// By deafult the state is zero.
	CurentState = 0;
	State = EArmorStates::NoArmor;
}


// Called when the game starts
void UArmor::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UArmor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// Move to next state. Stops at final state.
void UArmor::NextState()
{
	CurentState++;
	if (CurentState == 1)
	{
		State = EArmorStates::LevelOne;
	}
	else if (CurentState == 2)
	{
		State = EArmorStates::LevelTwo;
	}
	else if (CurentState == 3)
	{
		State = EArmorStates::LevelTre;
	}
}

// Choose state freely based on int. Ints out of range do nothing.
void UArmor::SwitchArmorState(int stat)
{
	if (stat == 0)
	{
		State = EArmorStates::NoArmor;
	}
	if (stat == 1)
	{
		State = EArmorStates::LevelOne;
	}
	else if (stat == 2)
	{
		State = EArmorStates::LevelTwo;
	}
	else if (stat == 3)
	{
		State = EArmorStates::LevelTre;
	}
	else {}
}

