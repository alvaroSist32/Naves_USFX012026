#include "Naves_USFX012026GameMode.h"
#include "Enemigos.h"

void ANaves_USFX012026GameMode::BeginPlay()
{
	Super::BeginPlay();

	// Vector espacial inicial de spawn
	FVector PosicionInicio = FVector(150.0f, 0.0f, 250.0f);
	FRotator RotacionInicio = FRotator::ZeroRotator;

	// Instanciación dinámica directa en la memoria del mundo
	GetWorld()->SpawnActor<AEnemigos>(AEnemigos::StaticClass(), PosicionInicio, RotacionInicio);
}
