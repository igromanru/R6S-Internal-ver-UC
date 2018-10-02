//          _                          _          __ ___   ___   ___  
//    /\   | |                        | |        /_ |__ \ / _ \ / _ \ 
//   /  \  | | _____  ____ _ _ __   __| | ___ _ __| |  ) | | | | (_) |
//  / /\ \ | |/ _ \ \/ / _` | '_ \ / _` |/ _ \ '__| | / /| | | |> _ < 
// / ____ \| |  __/>  < (_| | | | | (_| |  __/ |  | |/ /_| |_| | (_) |
///_/    \_\_|\___/_/\_\__,_|_| |_|\__,_|\___|_|  |_|____|\___/ \___/ 

#include "Settings.h"
#include "Entity.h"

#include "ImGui/imgui.h"

namespace Settings
{
	bool bESPEnabled = false;
	bool bAccuracyAimShowFOV = false;
	bool bAccuracyTrigger = false;
	bool bESP2DBox = false;
	bool bESP3DBox = false;
	bool bESPHealth = false;
	bool bESPName = false;
	bool bESPDistance = false;
	bool bESPHead = false;
	bool bESPSnapline = false;
	bool bUnload = false;
	bool bVisualsCrosshair = false;
	bool bVisualsFPS = false;
	bool bAccuracyAimbot = false;
	bool bAccuracyNoSpread = false;
	bool bAccuracyNoRecoil = false;
	bool bESPFlashed = false;
	bool bESPTeamOnly = false;
	bool bESPHostage = false;
	bool bESPSpotted = false;
	bool bESPEnemyOnly = false;
	bool Menu = true;
	bool bESPLockedEnnemy = false;

	bool bNoSmoke = false;
	bool bNoEffects = false;
	bool bGlaz = false;

	float fGlaz1 = 102;
	float fGlaz2 = 255;
	float fGlaz3 = 0;

	bool bESPTeam = false;
	bool bESPEnemy = false;

	bool bGadget = false;
	bool bGadgetDebug = false;

	int AimbotKey = 1; // 1 = CAPSLOCK 2 = MOUSE 1 3 = MOUSE 2

	bool bTeleport = false;

	uint32_t ColorFov = 0xFFfffffd;

	uint32_t ColorEnemyHead = 0xFFff0000;
	uint32_t ColorEnemy2DBox = 0xFFff0000;
	uint32_t ColorEnemy3DBox = 0xFFff0000;
	uint32_t ColorEnemyDistance = 0xFFff0000;
	uint32_t ColorEnemySnapline = 0xFFff0000;
	uint32_t ColorEnemyName = 0xFFff0000;

	uint32_t ColorTeamHead = 0xFF02ff00;
	uint32_t ColorTeam2DBox = 0xFF02ff00;
	uint32_t ColorTeam3DBox = 0xFF02ff00;
	uint32_t ColorTeamDistance = 0xFF02ff00;
	uint32_t ColorTeamSnapline = 0xFF02ff00;
	uint32_t ColorTeamName = 0xFF02ff00;

	uint32_t ColorConfused = 0xFFfbae00;

	uint32_t ColorCrosshair = 0xFF02ff00;
	uint32_t ColorFps = 0xFF02ff00;

	uint32_t ColorAimbotLock = 0xFF02ff00;
	uint32_t ColorTeleportLock = 0xFFfbae00;

	int aimbotTarget = -1;
	int teleportTarget = -1;

	int aimFov = 180;
	int aimDist = 200;
	int aimSmooth = 10;
}