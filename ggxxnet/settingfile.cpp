/* for Visual Studio 8.0 */
#ifdef _MSC_VER
#if (_MSC_VER >= 1400)
#define POINTER_64 __ptr64
#endif
#endif

//******************************************************************
// include
//******************************************************************
#include "ggxxnet.h"
#include "netMgr.h"
#include "settingfile.h"
#include "zlib.h"
#include "util.h"
#include "md5.h"

#include <locale.h>
#include <mbstring.h>
#include <string>
#include <vector>
#include "internet.h"
#include <sstream>
#include <fstream>
#include "dto/Config.cpp"
#include "dto/EnterCommand.cpp"
#include "dto/PlayerConfig.cpp"

//******************************************************************
// function
//******************************************************************



std::vector<std::string> split(std::string s, std::string delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	std::string token;
	std::vector<std::string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		if (token.compare("null") == 0) {
			res.push_back("");
		}
		else {
			res.push_back(token);
		}
	}

	res.push_back(s.substr(pos_start));
	res.pop_back();
	return res;
}

void getSettings(void) {
	char response[1024];
	Config config = Config::getConfig();
	EnterCommand enterCommand = EnterCommand(config.playerId, g_setting.port);
	string enterCommandJson = enterCommand.toJson();
	char* command = &enterCommandJson[0];
	std::string address = config.path + "/get-config";
	int responseSize = makePost(command, strlen(command), 1024, config.server, address, response);
	PlayerConfig playerConfig = playerConfig.fromJson(response, responseSize);
	g_setting.watchMaxNodes = int(playerConfig.watchMaxNodesEnable);
	g_setting.watchSaveReplay = int(playerConfig.watchReplayEnable);
	g_setting.watchIntrusion = int(playerConfig.intrusionEnable);
	g_setting.watchBroadcast = int(playerConfig.broadcastEnable);
	strcpy(g_setting.msg, playerConfig.message.c_str());
	g_setting.rounds = playerConfig.rounds;
	g_setting.slowRate = playerConfig.slowRate;
	g_setting.totalError = playerConfig.totalError;
	g_setting.totalDraw = playerConfig.totalDraw;
	g_setting.totalLose = playerConfig.totalLose;
	g_setting.totalWin = playerConfig.totalWin;
	g_setting.totalBattle = playerConfig.totalBattle;
	g_setting.score = playerConfig.score;
	g_setting.rank = playerConfig.rank;
	g_setting.wins = playerConfig.wins;
	g_setting.showfps = int(playerConfig.fpsEnable);
	g_setting.dispInvCombo = playerConfig.dispInvCombo;
	g_setting.useEx = int(playerConfig.useEx);
	g_setting.wait = playerConfig.waitTime;
	g_setting.ignoreSlow = int(playerConfig.ignoreSlow);
	g_setting.ignoreMisNode = int(playerConfig.ignoreMissNode);
	g_setting.delay = playerConfig.delay;
	g_setting.enableNet = int(playerConfig.enableNet);
	strcpy(g_setting.trip, "");
	strcpy(g_setting.userName, playerConfig.userName.c_str());
	strcpy(g_setting.scriptAddress, playerConfig.scriptAddress.c_str());
	g_setting.ver = playerConfig.version;
}