#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "JsonUtils.cpp"

using namespace std;
class EnterCommand {
public: string playerId;
      int port;
public: string toJson() {
    string json = "{";
    json = json + JsonUtils::quoteString("playerId") + ":" + JsonUtils::quoteString(playerId) + ",";
    json = json + JsonUtils::quoteString("port") + ":" + to_string(port);
    json = json + "}";
    return json;
}
};