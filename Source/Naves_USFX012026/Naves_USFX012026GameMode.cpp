#include "Naves_USFX012026GameMode.h"
#include "Enemigos.h" // Inclusión de tu Actor

void ANaves_USFX012026GameMode::BeginPlay()
{
	Super::BeginPlay();

	// Definir coordenadas de aparición
	FVector PosicionInicio = FVector(200.0f, 0.0f, 300.0f);
	FRotator RotacionInicio = FRotator::ZeroRotator;

	// Colocar en la escena por código C++
	GetWorld()->SpawnActor<AEnemigos>(AEnemigos::StaticClass(), PosicionInicio, RotacionInicio);
}