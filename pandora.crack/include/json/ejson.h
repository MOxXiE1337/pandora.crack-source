#pragma once
#include <string>
#include <fstream>
#include <json/json.h>

namespace Json
{
	static Json::Value ReadJsonFile(const std::string& file_name, bool& succeeded)
	{
		std::ifstream stream;
		stream.open(file_name);

		Json::CharReaderBuilder read_builder;
		read_builder["emitUTF8"] = true;

		Json::Value root;
		std::string strerr;
		succeeded = Json::parseFromStream(read_builder, stream, &root, &strerr);
		return root;
	}
}
