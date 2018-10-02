//          _                          _          __ ___   ___   ___  
//    /\   | |                        | |        /_ |__ \ / _ \ / _ \ 
//   /  \  | | _____  ____ _ _ __   __| | ___ _ __| |  ) | | | | (_) |
//  / /\ \ | |/ _ \ \/ / _` | '_ \ / _` |/ _ \ '__| | / /| | | |> _ < 
// / ____ \| |  __/>  < (_| | | | | (_| |  __/ |  | |/ /_| |_| | (_) |
///_/    \_\_|\___/_/\_\__,_|_| |_|\__,_|\___|_|  |_|____|\___/ \___/ 

#include <windows.h>
#include "Offsets.h"
#include "Memory.h"
#include "StatusManager.h"
#include "Entity.h"

namespace Engine {
	StatusManager* StatusManager::GetInstance() {
		return *reinterpret_cast<StatusManager**>(ADDRESS_STATUSMANAGER + reinterpret_cast<uint64_t>(GetModuleHandle(NULL)));
	}

	bool StatusManager::IsInGame()
	{
		auto base = GetAddress(ADDRESS_STATUSMANAGER);

		if (!Memory::IsValidPtr(base))
			return false;

		auto check = *Memory::Ptr<bool*>(base, OFFSET_MISC_INGAME);

		return check;
	}

	uintptr_t* StatusManager::GetAddress(uintptr_t address)
	{
		return *reinterpret_cast<uintptr_t**>(address + reinterpret_cast<uint64_t>(GetModuleHandle(NULL)));
	}
}