#include "CEngineSubsystem_Mongo.h"
#include <mongocxx/instance.hpp>


void UCEngineSubsystem_Mongo::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	mongocxx::instance inst{};

	
}