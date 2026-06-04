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

	// Componentes de colisión y malla
	UPROPERTY(VisibleAnywhere, Category = "Componentes")
	class UBoxComponent* ComponenteColision;

	UPROPERTY(VisibleAnywhere, Category = "Componentes")
	class UStaticMeshComponent* MallaEnemigo;

	// Atributos cinemáticos
	float VelocidadX;
	float VelocidadY;
	float LimiteX;
	float LimiteY;
};
