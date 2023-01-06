#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "JsonUtils.cpp"

using namespace std;
class EnterCommand {
public:
	string playerId;
	int port;
	EnterCommand::EnterCommand(string playerId, int port) {
		this->playerId = playerId;
		this->port = port;
	}
	string toJson() {
		string json = "{";
		json = json + JsonUtils::quoteString("playerId") + ":" + JsonUtils::quoteString(playerId) + ",";
		json = json + JsonUtils::quoteString("port") + ":" + to_string(port);
		json = json + "}";
		return json;
	}
};