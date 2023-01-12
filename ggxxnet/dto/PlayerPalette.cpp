#include <iostream>
#include <sstream>
#include "JsonUtils.cpp"
#include <vector>
#include "../base64.h"

using namespace std;
class PlayerPalette {
public:
	string characterName;
	int port;
	    vector<char>  fromJson(char* data, int responseSize, string characterName) {
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
		string result = JsonUtils::getValue(parameters, characterName);
		if (result == "") {
			return vector<char>();
		}
		return base64_decode(result); 
	}


};