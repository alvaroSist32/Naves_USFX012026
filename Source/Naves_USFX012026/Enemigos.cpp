#include "Enemigos.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Math/UnrealMathUtility.h" // Librería para generación aleatoria

AEnemigos::AEnemigos()
{
	PrimaryActorTick.bCanEverTick = true;

	// Valores iniciales base
	VelocidadX = 350.0f;
	VelocidadY = 280.0f;
	LimiteX = 1400.0f;
	LimiteY = 1100.0f;

	// Inicialización del componente de colisión (Raíz)
	ComponenteColision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxColisionComponent"));
	ComponenteColision->SetBoxExtent(FVector(60.0f, 60.0f, 60.0f));
	ComponenteColision->SetCollisionProfileName(TEXT("BlockAll"));
	RootComponent = ComponenteColision;

	// Inicialización de la malla estética (Cono)
	MallaEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigo"));
	MallaEnemigo->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("/Engine/BasicShapes/Cone.Cone"));
	if (MallaAsset.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(MallaAsset.Object);
	}
}

void AEnemigos::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemigos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NuevaPosicion = GetActorLocation();

	// Desplazamiento lineal
	NuevaPosicion.X += VelocidadX * DeltaTime;
	NuevaPosicion.Y += VelocidadY * DeltaTime;

	// CONTROL DE BORDES CON REBOTE CAÓTICO ALEATORIO
	if (NuevaPosicion.X > LimiteX)
	{
		NuevaPosicion.X = LimiteX;
		VelocidadX = FMath::RandRange(250.0f, 450.0f) * -1.0f; // Invierte sentido a la izquierda
		VelocidadY += FMath::RandRange(-150.0f, 150.0f);        // Altera el ángulo en Y
	}
	else if (NuevaPosicion.X < -LimiteX)
	{
		NuevaPosicion.X = -LimiteX;
		VelocidadX = FMath::RandRange(250.0f, 450.0f) * 1.0f;  // Invierte sentido a la derecha
		VelocidadY += FMath::RandRange(-150.0f, 150.0f);
	}

	if (NuevaPosicion.Y > LimiteY)
	{
		NuevaPosicion.Y = LimiteY;
		VelocidadY = FMath::RandRange(250.0f, 450.0f) * -1.0f; // Invierte sentido hacia abajo
		VelocidadX += FMath::RandRange(-150.0f, 150.0f);        // Altera el ángulo en X
	}
	else if (NuevaPosicion.Y < -LimiteY)
	{
		NuevaPosicion.Y = -LimiteY;
		VelocidadY = FMath::RandRange(250.0f, 450.0f) * 1.0f;  // Invierte sentido hacia arriba
		VelocidadX += FMath::RandRange(-150.0f, 150.0f);
	}

	// Restrictores de seguridad (Evitan que el objeto se detenga o escape)
	VelocidadX = FMath::Clamp(VelocidadX, -500.0f, 500.0f);
	VelocidadY = FMath::Clamp(VelocidadY, -500.0f, 500.0f);

	if (FMath::Abs(VelocidadX) < 50.0f) VelocidadX = (VelocidadX < 0) ? -300.0f : 300.0f;
	if (FMath::Abs(VelocidadY) < 50.0f) VelocidadY = (VelocidadY < 0) ? -300.0f : 300.0f;

	SetActorLocation(NuevaPosicion);
}
