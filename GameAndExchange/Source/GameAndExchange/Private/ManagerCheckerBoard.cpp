// Fill out your copyright notice in the Description page of Project Settings.


#include "ManagerCheckerBoard.h"
#include "Runtime/Engine/Classes/Engine/World.h"

// Sets default values
AManagerCheckerBoard::AManagerCheckerBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AManagerCheckerBoard::BeginPlay()
{
	Super::BeginPlay();
	this->SetActorEnableCollision(false);
	FVector loc = FVector();
	FRotator rot = FRotator();
	//Box=GetWorld()->SpawnActor<ABoxActor>(ABoxActor::StaticClass(), loc, rot);
	Box = NewObject<ABoxActor>();
	if (Box)
	{
		Box->InitCheckerBoard(CubePath, MaterialsPath,this);
	}
	
}

// Called every frame
void AManagerCheckerBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AManagerCheckerBoard::ExcuteInputEvent(EMoveDir inEnum)
{
	bCanMove = false;
	if (Box) {
		this->CallBoxEvent.Broadcast(inEnum);
		if (bCanMove)
		{
			Box->CreateNewBox(1);
		}
	}
}

