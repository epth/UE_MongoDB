#pragma once

#include "CoreMinimal.h"

#include <cstdint>
#include <iostream>
#include <vector>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

#include "MongoGlobal.generated.h"


/**
* 
*/

USTRUCT(BlueprintType)
struct FMongo_ClientHandle
{
	GENERATED_USTRUCT_BODY()

	mongocxx::client Data={mongocxx::uri{}};

	FMongo_ClientHandle()
	{
	}

	FMongo_ClientHandle(const mongocxx::uri URI)
	{
		Data={URI};
	}
	

	FMongo_ClientHandle& operator=(const FMongo_ClientHandle& ClientHandle2)
	{
		return (FMongo_ClientHandle&)ClientHandle2;
	}
	
};

USTRUCT(BlueprintType)
struct FMongo_DocumentValueHandle
{
	GENERATED_USTRUCT_BODY()

	bsoncxx::document::value Data = bsoncxx::builder::stream::document{}<< bsoncxx::builder::stream::finalize;

	
};