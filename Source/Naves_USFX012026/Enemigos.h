#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigos.generated.h"

UCLASS()
class NAVES_USFX012026_API AEnemigos : public AActor
{
	GENERATED_BODY()

public:
	AEnemigos();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	// Componente de colisión física (Caja)
	UPROPERTY(VisibleAnywhere, Category = "Componentes")
	class UBoxComponent* ComponenteColision;

	UPROPERTY(VisibleAnywhere, Category = "Componentes")
	class UStaticMeshComponent* MallaEnemigo;

	// Variables de control de movimiento y límites
	float VelocidadX;
	float VelocidadY;
	float LimiteX;
	float LimiteY;
};