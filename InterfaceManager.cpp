//          _                          _          __ ___   ___   ___  
//    /\   | |                        | |        /_ |__ \ / _ \ / _ \ 
//   /  \  | | _____  ____ _ _ __   __| | ___ _ __| |  ) | | | | (_) |
//  / /\ \ | |/ _ \ \/ / _` | '_ \ / _` |/ _ \ '__| | / /| | | |> _ < 
// / ____ \| |  __/>  < (_| | | | | (_| |  __/ |  | |/ /_| |_| | (_) |
///_/    \_\_|\___/_/\_\__,_|_| |_|\__,_|\___|_|  |_|____|\___/ \___/ 

#include <windows.h>
#include "Offsets.h"
#include "Memory.h"
#include "InterfaceManager.h"
#include "Entity.h"

namespace Engine {
	InterfaceManager* InterfaceManager::GetInstance() {
		return *reinterpret_cast<InterfaceManager**>(ADDRESS_INTERFACEMANAGER + reinterpret_cast<uint64_t>(GetModuleHandle(NULL)));
	}

	int InterfaceManager::IsInCross()
	{
		auto base = GetAddress(0x04EA8A60);

		if (!Memory::IsValidPtr(base))
			return false;

		auto ptr1 = *Memory::Ptr<void**>(base, 0x1C8);

		if (!Memory::IsValidPtr(ptr1))
			return false;

		auto ptr2 = *Memory::Ptr<void**>(base, 0x398);

		if (!Memory::IsValidPtr(ptr2))
			return false;

		return *Memory::Ptr<int*>(base, 0x400);
	}

	uintptr_t* InterfaceManager::GetAddress(uintptr_t address)
	{
		return *reinterpret_cast<uintptr_t**>(address + reinterpret_cast<uint64_t>(GetModuleHandle(NULL)));
	}
}