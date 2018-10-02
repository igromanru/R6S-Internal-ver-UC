//          _                          _          __ ___   ___   ___  
//    /\   | |                        | |        /_ |__ \ / _ \ / _ \ 
//   /  \  | | _____  ____ _ _ __   __| | ___ _ __| |  ) | | | | (_) |
//  / /\ \ | |/ _ \ \/ / _` | '_ \ / _` |/ _ \ '__| | / /| | | |> _ < 
// / ____ \| |  __/>  < (_| | | | | (_| |  __/ |  | |/ /_| |_| | (_) |
///_/    \_\_|\___/_/\_\__,_|_| |_|\__,_|\___|_|  |_|____|\___/ \___/ 

#include <windows.h>
#include "Offsets.h"
#include "Memory.h"
#include "WeaponManager.h"
#include "Entity.h"

namespace Engine {
	WeaponManager* WeaponManager::GetInstance() {
		return *reinterpret_cast<WeaponManager**>(ADDRESS_WEAPONMANAGER + reinterpret_cast<uint64_t>(GetModuleHandle(NULL)));
	}

	void WeaponManager::NoSpread() {
		auto base = GetAddress(ADDRESS_WEAPONMANAGER);

		if (!Engine::Memory::IsValidPtr(base))
			return;

		auto ptr1 = *Engine::Memory::Ptr<void**>(base, 0x20);

		if (!Engine::Memory::IsValidPtr(ptr1))
			return;

		auto ptr2 = *Engine::Memory::Ptr<void**>(ptr1, 0xC8);

		if (!Engine::Memory::IsValidPtr(ptr2))
			return;

		auto ptr3 = *Engine::Memory::Ptr<void**>(ptr2, 0x110);

		if (!Engine::Memory::IsValidPtr(ptr3))
			return;

		*Engine::Memory::Ptr<float*>(ptr3, 0x70) = 0.0f;
	}

	void WeaponManager::NoRecoil() {
		auto base = GetAddress(ADDRESS_WEAPONMANAGER);

		if (!Engine::Memory::IsValidPtr(base))
			return;

		auto ptr1 = *Engine::Memory::Ptr<void**>(base, 0x20);

		if (!Engine::Memory::IsValidPtr(ptr1))
			return;

		auto ptr2 = *Engine::Memory::Ptr<void**>(ptr1, 0xC8);

		if (!Engine::Memory::IsValidPtr(ptr2))
			return;

		auto ptr3 = *Engine::Memory::Ptr<void**>(ptr2, 0x110);

		if (!Engine::Memory::IsValidPtr(ptr3))
			return;

		*Engine::Memory::Ptr<float*>(ptr3, 0xA8) = 0.0f;
	}

	float WeaponManager::FireMode() {
		auto base = GetAddress(0x36D9FB8);

		auto ptr1 = *Engine::Memory::Ptr<void**>(base, 0x20);

		auto ptr2 = *Engine::Memory::Ptr<void**>(ptr1, 0xC8);

		return *Engine::Memory::Ptr<float*>(ptr2, 0x190);
	}

	int WeaponManager::FireState() {
		auto base = GetAddress(ADDRESS_WEAPONMANAGER);

		auto ptr1 = *Engine::Memory::Ptr<void**>(base, 0x20);

		auto ptr2 = *Engine::Memory::Ptr<void**>(ptr1, 0xC8);

		auto ptr3 = *Engine::Memory::Ptr<void**>(ptr2, 190);

		return *Engine::Memory::Ptr<int*>(ptr3, 0x150);
	}

	void WeaponManager::ForceFire(int state) {
		auto base = GetAddress(0x4A26380);

		if (!Engine::Memory::IsValidPtr(base))
			return;

		auto ptr1 = *Engine::Memory::Ptr<void**>(base, 0xB0);

		if (!Engine::Memory::IsValidPtr(ptr1))
			return;

		auto ptr2 = *Engine::Memory::Ptr<void**>(ptr1, 0x8);

		if (!Engine::Memory::IsValidPtr(ptr2))
			return;

		auto ptr3 = *Engine::Memory::Ptr<void**>(ptr2, 0x30);

		if (!Engine::Memory::IsValidPtr(ptr3))
			return;

		auto ptr4 = *Engine::Memory::Ptr<void**>(ptr3, 0x90);

		if (!Engine::Memory::IsValidPtr(ptr4))
			return;

		auto ptr5 = *Engine::Memory::Ptr<void**>(ptr4, 0x518);

		if (!Engine::Memory::IsValidPtr(ptr5))
			return;

		*Engine::Memory::Ptr<int*>(ptr5, 0x5A0) = state;
	}

	int WeaponManager::CrosshairID() {
		auto base = GetAddress(0x4A26380);

		auto ptr1 = *Engine::Memory::Ptr<void**>(base, 0x400);

		auto ptr2 = *Engine::Memory::Ptr<void**>(ptr1, 0x398);

		return *Engine::Memory::Ptr<int*>(ptr2, 0x1C8);
	}

	uintptr_t* WeaponManager::GetAddress(uintptr_t address)
	{
		return *reinterpret_cast<uintptr_t**>(address + reinterpret_cast<uint64_t>(GetModuleHandle(NULL)));
	}
}