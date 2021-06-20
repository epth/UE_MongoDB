// Fill out your copyright notice in the Description page of Project Settings.


#include "CMongo_BlueprintFunctionLibrary.h"
#include "MongoGlobal.h"

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

//...

FMongo_ClientHandle UCMongo_BlueprintFunctionLibrary::Connect(FString Url, FString Username, FString Password, FString Database)
{
	auto username=TCHAR_TO_ANSI(*Username);
	auto url=TCHAR_TO_ANSI(*Url);
	auto password=TCHAR_TO_ANSI(*Password);
	auto database=TCHAR_TO_ANSI(*Database);
	auto c=(std::string("mongodb+srv://")+ username + password + std::string(":@")+ url + std::string("/test?retryWrites=true&w=majority"));
	auto d=(std::string("mongodb://")+ username + password + std::string(":@")+ url + std::string("/test?retryWrites=true&w=majority")).c_str();
	
	return {mongocxx::uri(
		(std::string()+ "mongodb://" + username + password + (Username.Len()>0?":@":"") + url + "/"+ database+ "?retryWrites=true&w=majority").c_str()
		// "mongodb://localhost:27017"
		)};
}
void UCMongo_BlueprintFunctionLibrary::Write(const struct FMongo_ClientHandle& Client, const FMongo_DocumentValueHandle& Document)
{
	mongocxx::database db = Client.Data["test"];

	mongocxx::collection coll = db["col"];

	auto builder = bsoncxx::builder::stream::document{};
	bsoncxx::document::value doc_value = builder
	<< "name" << "MongoDB"
	<< "type" << "database"
	<< "count" << 1
	<< "versions" << bsoncxx::builder::stream::open_array
		<< "v3.2" << "v3.0" << "v2.6"
	<< close_array
	<< "info" << bsoncxx::builder::stream::open_document
		<< "x" << 203
		<< "y" << 102
	<< bsoncxx::builder::stream::close_document
	<< bsoncxx::builder::stream::finalize;

	bsoncxx::document::view view = Document.Data.view();
	
	bsoncxx::stdx::optional<mongocxx::result::insert_one> result =
	coll.insert_one(view);

	// mongocxx::cursor cursor = coll.find({});
	// for(auto doc : cursor) {
	// 	std::cout << bsoncxx::to_json(doc) << "\n";
	// }
}

const char* UCMongo_BlueprintFunctionLibrary::Serialize_Uid(const FGuid& Uid)
{
	return TCHAR_TO_ANSI(*Uid.ToString());
}
