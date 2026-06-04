#include "Enemigos.h"
#include "Components/BoxComponent.h" // Inclusión obligatoria para la colisión
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AEnemigos::AEnemigos()
{
	PrimaryActorTick.bCanEverTick = true;

	// Configuración de movimiento y bordes del escenario
	VelocidadX = 300.0f;
	VelocidadY = 250.0f;
	LimiteX = 1500.0f; // Distancia máxima permitida en X
	LimiteY = 1200.0f; // Distancia máxima permitida en Y

	// 1. Instanciar componente de colisión y definirlo como Raíz (Root)
	ComponenteColision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxColisionComponent"));
	ComponenteColision->SetBoxExtent(FVector(60.0f, 60.0f, 60.0f)); // Tamaño del área de colisión
	ComponenteColision->SetCollisionProfileName(TEXT("BlockAll"));  // Bloquea físicamente contra todo
	RootComponent = ComponenteColision;

	// 2. Crear la malla visual y adjuntarla a la colisión raíz
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

	// Aplicar traslación temporal por cuadro
	NuevaPosicion.X += VelocidadX * DeltaTime;
	NuevaPosicion.Y += VelocidadY * DeltaTime;

	// SISTEMA ANTIESCAPE: Si la nave toca el límite virtual de la escena, invierte dirección (rebota)
	if (NuevaPosicion.X > LimiteX || NuevaPosicion.X < -LimiteX)
	{
		VelocidadX *= -1.0f; // Cambia el sentido en X
	}

	if (NuevaPosicion.Y > LimiteY || NuevaPosicion.Y < -LimiteY)
	{
		VelocidadY *= -1.0f; // Cambia el sentido en Y
	}

	SetActorLocation(NuevaPosicion);
}