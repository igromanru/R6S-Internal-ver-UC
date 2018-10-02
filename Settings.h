//          _                          _          __ ___   ___   ___  
//    /\   | |                        | |        /_ |__ \ / _ \ / _ \ 
//   /  \  | | _____  ____ _ _ __   __| | ___ _ __| |  ) | | | | (_) |
//  / /\ \ | |/ _ \ \/ / _` | '_ \ / _` |/ _ \ '__| | / /| | | |> _ < 
// / ____ \| |  __/>  < (_| | | | | (_| |  __/ |  | |/ /_| |_| | (_) |
///_/    \_\_|\___/_/\_\__,_|_| |_|\__,_|\___|_|  |_|____|\___/ \___/ 

#pragma once
#include "stdafx.h"

namespace Settings {
	extern bool bESPEnabled;

	extern bool bESPHead;
	extern bool bESPEnemyOnly;
	extern bool bESPLockedEnnemy;
	extern bool bESPSnapline;
	extern bool bESPHasArmor;
	extern bool bESP2DBox;
	extern bool bESP3DBox;
	extern bool bESPHealth;
	extern bool bESPHealthText;
	extern bool bESPName;
	extern bool bESPDistance;
	extern bool bESPFlashed;
	extern bool bESPHostage;
	extern bool bESPTeamOnly;
	extern bool bESPSpotted;

	extern bool bNoSmoke;
	extern bool bNoEffects;
	extern bool bGlaz;

	extern float fGlaz1;
	extern float fGlaz2;
	extern float fGlaz3;

	extern bool bESPTeam;
	extern bool bESPEnemy;

	extern bool bGadget;
	extern bool bGadgetDebug;

	extern int AimbotKey;

	extern uint32_t ColorFov;

	extern uint32_t ColorEnemyHead;
	extern uint32_t ColorEnemy2DBox;
	extern uint32_t ColorEnemy3DBox;
	extern uint32_t ColorEnemyDistance;
	extern uint32_t ColorEnemySnapline;
	extern uint32_t ColorEnemyName;

	extern uint32_t ColorTeamHead;
	extern uint32_t ColorTeam2DBox;
	extern uint32_t ColorTeam3DBox;
	extern uint32_t ColorTeamDistance;
	extern uint32_t ColorTeamSnapline;
	extern uint32_t ColorTeamName;

	extern uint32_t ColorConfused;

	extern uint32_t ColorCrosshair;
	extern uint32_t ColorFps;

	extern  uint32_t ColorAimbotLock;
	extern  uint32_t ColorTeleportLock;

	extern bool bUnload;

	extern bool bVisualsCrosshair;
	extern bool bVisualsFPS;

	extern bool bAccuracyNoSpread;
	extern bool bAccuracyNoRecoil;

	extern bool bAccuracyAimbot;
	extern bool bAccuracyAimShowFOV;
	extern bool bAimLock;
	extern bool bAccuracyTrigger;

	extern bool bTeleport;

	extern bool Menu;

	extern int aimbotTarget;
	extern int teleportTarget;

	extern int aimFov;
	extern int aimDist;
	extern int aimSmooth;
}