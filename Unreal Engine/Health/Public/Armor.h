// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Armor.generated.h"


UENUM(BlueprintType)
enum class EArmorStates : uint8
{
	// UENUM Must be declared outside of any class. Can be accessed from anywhere.
	NoArmor		UMETA(DisplayName = "Zero"),
	LevelOne	UMETA(DisplayName = "One"),
	LevelTwo	UMETA(DisplayName = "Two"),
	LevelTre	UMETA(DisplayName = "Tre")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SAVETEST_API UArmor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UArmor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EArmorStates State;

	UFUNCTION(BlueprintCallable)
	void NextState();

	UFUNCTION(BlueprintCallable)
	void SwitchArmorState(int stat);
	UPROPERTY()
	int CurentState;
};
