// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "MongoGlobal.h"

#include "CMongo_BlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class LIBMONGO_API UCMongo_BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable)
	static FMongo_ClientHandle Connect(FString Url, FString Username, FString Password, FString Database);

	UFUNCTION(BlueprintCallable)
	static void Write(const FMongo_ClientHandle& Client, const FMongo_DocumentValueHandle& Document);

	static const char* Serialize_Uid(const FGuid& Uid);
};
