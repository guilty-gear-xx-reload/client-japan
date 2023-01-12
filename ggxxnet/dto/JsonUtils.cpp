#pragma once
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class JsonUtils {
public:
	static string quoteString(string str) {
		return "\"" + str + "\"";
	}

	static void eraseSubStr(string& mainStr, char toErase)
	{
		mainStr.erase(remove(mainStr.begin(), mainStr.end(), toErase), mainStr.end());
	}
	static string convertToString(char* a, int size)
	{
		int i;
		string s = "";
		for (i = 0; i < size; i++) {
			s = s + a[i];
		}
		return s;
	}

	static string getValue(vector<string> parameters, string parameterName) {
		for (string parameter : parameters) {
			string characterWithColon = parameterName + ":";
			std::size_t found = parameter.find(characterWithColon);
			if (found != string::npos) {
				return parameter.substr(parameter.find(":") + 1);
			}
		}
		return "";
	}

};

