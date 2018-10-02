//          _                          _          __ ___   ___   ___  
//    /\   | |                        | |        /_ |__ \ / _ \ / _ \ 
//   /  \  | | _____  ____ _ _ __   __| | ___ _ __| |  ) | | | | (_) |
//  / /\ \ | |/ _ \ \/ / _` | '_ \ / _` |/ _ \ '__| | / /| | | |> _ < 
// / ____ \| |  __/>  < (_| | | | | (_| |  __/ |  | |/ /_| |_| | (_) |
///_/    \_\_|\___/_/\_\__,_|_| |_|\__,_|\___|_|  |_|____|\___/ \___/ 

#pragma once
#include "Array.h"
#include "Entity.h"
#include "Offsets.h"

namespace Engine
{
	class WeaponManager
	{
	public:
		uintptr_t * GetAddress(uintptr_t address);
		void NoSpread();
		void NoRecoil();
		float FireMode();
		int FireState();
		void ForceFire(int state);
		int CrosshairID();
		static WeaponManager* GetInstance();
	};
}