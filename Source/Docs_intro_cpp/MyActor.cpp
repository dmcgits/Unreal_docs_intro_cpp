// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// You can set default values in constructor (unlike unity) but keep in mind
// these are then overwritten if values are set in the editor (UPROPERTY).
// You get first access to any set-in-the-editor values in PostInitProperties().
AMyActor::AMyActor() :
  TotalDamage(180),
  DamageTimeInSeconds(1.0f) //Iniitaliser lists are all good.
{
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
  // You're allowed to init variables here, unlike Unity which prefers you
  // override its waking functions. Initialiser lists, brace init in header and init in constructor body are fine.
  ScratchyPlantsDamage = 30;
}

// Any initialization involving UPROPERTY variables that can have values set in the editor
// can be done here. Remember to add virtual void override to header.
// ONLY WORKS when running game. Does not notify editor.Use PostEditChangeProperty.
void AMyActor::PostInitProperties()
{
  Super::PostInitProperties();
  CalculatePostInitValues();
}

#if WITH_EDITOR
// This feels dangerously redundant. I'd try to keep the contents of this and 
// PostInitProperties to a single function they both call, and let that have any
// extra complexity. Less duplication, less human error. Extra function call is only
// going to be once per spawn.
void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
  CalculatePostInitValues();
  Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void AMyActor::CalculatePostInitValues()
{
  DamagePerSecond = TotalDamage / DamageTimeInSeconds;
}


// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
  // Actor is now playable. Hooked into engine and can make api calls.
  // I'm assuming this function will run before the first tick.
  // Unlike Unity, you're allowed to init variables in the constructor too.
  Super::BeginPlay();
  
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
  // If you don't need to run any custom code each frame, first
  // COMMENT OUT bCanEverTick in the constructor, then comment out
  // or delete this function. 

  Super::Tick(DeltaTime);

}



// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

