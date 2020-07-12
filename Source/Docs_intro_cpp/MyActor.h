// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class DOCS_INTRO_CPP_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	// The UPROPERTY macro exposes a variable in the editor. A list of specifiers:
	// https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Properties/Specifiers/index.html
	//
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Damage")
		int32 TotalDamage;	// {150};	// Looks like brace init might work.

	// Sadly, UPROPERTY is needed for every variable you expose??
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Damage")
		int32 ScratchyPlantsDamage;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Damage")
		int32 DamageTimeInSeconds;
	
	UPROPERTY(BluePrintReadOnly, VisibleAnywhere, Transient, Category = "Damage")
		float DamagePerSecond;
	
	// Sets default values for this actor's properties
	AMyActor();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitProperties() override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	void CalculatePostInitValues();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
