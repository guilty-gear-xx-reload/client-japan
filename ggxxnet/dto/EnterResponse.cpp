#include <iostream>
#include <sstream>
#include "JsonUtils.cpp"
#include <vector>

using namespace std;
class EnterResponse {
public:
	string scriptAddress;
	int port;
	string fromJson(char* data, int responseSize) {
		string json = JsonUtils::convertToString(data, responseSize);
		JsonUtils::eraseSubStr(json, '{');
		JsonUtils::eraseSubStr(json, '}');

		JsonUtils::eraseSubStr(json, '"');
		JsonUtils::eraseSubStr(json, '\\');

		vector < string > parameters;
		string segment;
		stringstream dataStringStream;
		dataStringStream << json;

		while (getline(dataStringStream, segment, ',')) {
			parameters.push_back(segment);
		}
		return JsonUtils::getValue(parameters, "scriptAddress") + ":" + JsonUtils::getValue(parameters, "port");
	}


};