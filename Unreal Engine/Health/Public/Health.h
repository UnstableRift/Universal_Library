// Eeli Rutanen


#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Health.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SAVETEST_API UHealth : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealth();

	// Curent health as float
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Health")
	float HealthPoints;
	
	// The maximum limit for healing health.
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Health")
	float MaxHealth;

	// If set true player will ignore damage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	bool bIgnoreDamage;

	// 
	UFUNCTION(BlueprintCallable)
	void ReduceHealth(float DamageTaken);

	UFUNCTION(BlueprintCallable)
	void RestoreHealth(float RestoreHealthAmount);
private:
	UFUNCTION()
	virtual bool GetArmorComponent();

	UFUNCTION()
	void GetArmorvalue();

	UPROPERTY()
	float ArmorPoints;

	UFUNCTION(BlueprintCallable)
	void ClaculateHealth(float PassDamage, float Armor);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
