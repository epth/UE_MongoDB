#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "CEngineSubsystem_Mongo.generated.h"

/**
* 
*/
UCLASS()
class LIBMONGO_API UCEngineSubsystem_Mongo : public UEngineSubsystem
{
	GENERATED_BODY()
	
	public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
};