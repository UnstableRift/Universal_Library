// Eeli Rutanen


#include "DamageAppier.h"
#include "Health.h"

// Sets default values
ADamageAppier::ADamageAppier()
{
	PrimaryActorTick.bCanEverTick = false;
	HitBox = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	HitBox->SetupAttachment(this->GetRootComponent());
}

void ADamageAppier::BeginPlay()
{
	Super::BeginPlay();

	// Allways aplly damage.
	if (Damage == 0)
	{
		Damage = 1;
	}
	
	HitBox->OnComponentBeginOverlap.AddDynamic(this, &ADamageAppier::OnBeginOverlap);
	HitBox->OnComponentEndOverlap.AddDynamic(this, &ADamageAppier::OnEndOverlap);

	//HitBox->SetRelativeScale3D(BoxScale);
}

void ADamageAppier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADamageAppier::OnBeginOverlap(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UHealth* HealthComponent = OtherActor->GetComponentByClass<UHealth>();
	HealthComponent->ReduceHealth(Damage);
}

void ADamageAppier::OnEndOverlap(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{

}

