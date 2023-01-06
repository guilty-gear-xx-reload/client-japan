#include <string>
#include "JsonUtils.cpp"
using namespace std;

class PlayerConfig
{
public:
	int version;
	string scriptAddress;
	string userName;
	string trip;
	int port;
	int delay;
	int waitTime;
	int dispInvCombo;
	int slowRate;
	int rounds;
	string message;
	long lastActivity;
	bool enableNet;
	bool ignoreMissNode;
	bool ignoreSlow;
	bool useEx;
	bool fpsEnable;
	bool broadcastEnable;
	bool intrusionEnable;
	bool watchReplayEnable;
	bool watchMaxNodesEnable;
	bool active;
	int wins;
	int rank;
	int score;
	int totalBattle;
	int totalWin;
	int totalLose;
	int totalDraw;
	int totalError;

	PlayerConfig(
		int version,
		string scriptAddress,
		string userName,
		string trip,
		int port,
		int delay,
		int waitTime,
		int dispInvCombo,
		int slowRate,
		int rounds,
		string message,
		long lastActivity,
		bool enableNet,
		bool ignoreMissNode,
		bool ignoreSlow,
		bool useEx,
		bool fpsEnable,
		bool broadcastEnable,
		bool intrusionEnable,
		bool watchReplayEnable,
		bool watchMaxNodesEnable,
		bool active,
		int wins,
		int rank,
		int score,
		int totalBattle,
		int totalWin,
		int totalLose,
		int totalDraw,
		int totalError):
	version(version),
		scriptAddress(scriptAddress),
		userName(userName),
		trip(trip), //todo could be null
		port(port),
		delay(delay),
		waitTime(waitTime),
		dispInvCombo(dispInvCombo),
		slowRate(slowRate),
		rounds(rounds),
		message(message),
		lastActivity(lastActivity),
		enableNet(enableNet),
		ignoreMissNode(ignoreMissNode),
		ignoreSlow(ignoreSlow),
		useEx(useEx),
		fpsEnable(fpsEnable),
		broadcastEnable(broadcastEnable),
		intrusionEnable(intrusionEnable),
		watchReplayEnable(watchReplayEnable),
		watchMaxNodesEnable(watchMaxNodesEnable),
		active(active),
		wins(wins),
		rank(rank),
		score(score),
		totalBattle(totalBattle),
		totalWin(totalWin),
		totalLose(totalLose),
		totalDraw(totalDraw),
		totalError(totalError) {}

	PlayerConfig fromJson(char* data, int responseSize) {
		string json = JsonUtils::convertToString(data, responseSize);
		JsonUtils::eraseSubStr(json, '{');
		JsonUtils::eraseSubStr(json, '}');

		JsonUtils::eraseSubStr(json, '"');
		JsonUtils::eraseSubStr(json, '\\');

		vector<string> parameters;
		string segment;
		stringstream dataStringStream;
		dataStringStream << json;

		while (getline(dataStringStream, segment, ','))
		{
			parameters.push_back(segment);
		}

		PlayerConfig playerConfig = PlayerConfig(
			stoi(JsonUtils::getValue(parameters, "version")),
			JsonUtils::getValue(parameters, "scriptAddress"),
			JsonUtils::getValue(parameters, "userName"),
			JsonUtils::getValue(parameters, "trip"),
			stoi(JsonUtils::getValue(parameters, "port")),
			stoi(JsonUtils::getValue(parameters, "delay")),
			stoi(JsonUtils::getValue(parameters, "waitTime")),
			stoi(JsonUtils::getValue(parameters, "dispInvCombo")),
			stoi(JsonUtils::getValue(parameters, "slowRate")),
			stoi(JsonUtils::getValue(parameters, "rounds")),
			JsonUtils::getValue(parameters, "message"),
			stol(JsonUtils::getValue(parameters, "lastActivity")),
			to_bool(JsonUtils::getValue(parameters, "enableNet")),
			to_bool(JsonUtils::getValue(parameters, "ignoreMissNode")),
			to_bool(JsonUtils::getValue(parameters, "ignoreSlow")),
			to_bool(JsonUtils::getValue(parameters, "useEx")),
			to_bool(JsonUtils::getValue(parameters, "fpsEnable")),
			to_bool(JsonUtils::getValue(parameters, "broadcastEnable")),
			to_bool(JsonUtils::getValue(parameters, "intrusionEnable")),
			to_bool(JsonUtils::getValue(parameters, "watchReplayEnable")),
			to_bool(JsonUtils::getValue(parameters, "watchMaxNodesEnable")),
			to_bool(JsonUtils::getValue(parameters, "active")),
			stoi(JsonUtils::getValue(parameters, "wins")),
			stoi(JsonUtils::getValue(parameters, "rank")),
			stoi(JsonUtils::getValue(parameters, "score")),
			stoi(JsonUtils::getValue(parameters, "totalBattle")),
			stoi(JsonUtils::getValue(parameters, "totalWin")),
			stoi(JsonUtils::getValue(parameters, "totalLose")),
			stoi(JsonUtils::getValue(parameters, "totalDraw")),
			stoi(JsonUtils::getValue(parameters, "totalError")));

		return playerConfig;
	}

	bool to_bool(std::string const& s) {
		return s != "false";
	}
};
