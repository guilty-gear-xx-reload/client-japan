#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "JsonUtils.cpp"
using namespace std;
class Config {
public:
	string playerId;
	string path;
	string server;

	Config::Config(string playerId, string path, string server) {
		this->playerId = playerId;
		this->path = path;
		this->server = server;
	}

static	Config getConfig() {
		ifstream configFile("config.txt");
		vector<string> configTxt;
		string line;
		while (getline(configFile, line))
		{
			configTxt.push_back(line);
		}
		configFile.close();
		string playerId = configTxt.back();
		configTxt.pop_back();
		string path = configTxt.back();
		configTxt.pop_back();
		string server = configTxt.back();
		configTxt.pop_back();
		Config config = Config(playerId, path, server);
		return config;
	}

};