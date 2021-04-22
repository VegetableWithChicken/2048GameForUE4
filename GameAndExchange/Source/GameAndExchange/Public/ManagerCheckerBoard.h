// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BoxActor.h"
#include "GameFramework/Actor.h"
#include "ManagerCheckerBoard.generated.h"




DECLARE_MULTICAST_DELEGATE_OneParam(FCallBoxEvent, EMoveDir);

UCLASS()
class GAMEANDEXCHANGE_API AManagerCheckerBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AManagerCheckerBoard();
public:
	FCallBoxEvent CallBoxEvent;
	UFUNCTION(BlueprintCallable, Category = "CheckerBorad")
		void ExcuteInputEvent(EMoveDir inEnum);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "CheckerBorad")
		FString CubePath;
	UPROPERTY(EditAnywhere, Category = "CheckerBorad")
		FString MaterialsPath;
	UPROPERTY(EditAnywhere, Category = "CheckerBorad")
	/**set Init Box Numbers*/
		int InitBoxNumber=2;
	UPROPERTY(EditAnywhere, Category = "CheckerBorad")
	/**set how many row and yaw in checkboard*/
		int wd = 4;
	void SetCanMove() { bCanMove = true; }

private:
	ABoxActor* Box = nullptr;
	bool bCanMove = false;

};
