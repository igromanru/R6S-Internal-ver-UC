//          _                          _          __ ___   ___   ___  
//    /\   | |                        | |        /_ |__ \ / _ \ / _ \ 
//   /  \  | | _____  ____ _ _ __   __| | ___ _ __| |  ) | | | | (_) |
//  / /\ \ | |/ _ \ \/ / _` | '_ \ / _` |/ _ \ '__| | / /| | | |> _ < 
// / ____ \| |  __/>  < (_| | | | | (_| |  __/ |  | |/ /_| |_| | (_) |
///_/    \_\_|\___/_/\_\__,_|_| |_|\__,_|\___|_|  |_|____|\___/ \___/ 

#pragma once
#define ADDRESS_GAMEMANAGER 0x4ECDD40 // 48 8B 0D ? ? ? ? 83 B9 ? ? ? ? ? 77 07 33 D2 E8 ? ? ? ? 48 8D 05
#define ADDRESS_GAMERENDERER 0x4DB3CF0 // 4C 89 0D ? ? ? ? 48 8D 0D ? ? ? ? 45 33 C9 BA ? ? ? ? 41 B8 ? ? ? ? E8 ? ? ? ?
#define ADDRESS_NETWORKMANAGER 0x4DA6EB8 // 48 8B 05 ? ? ? ? 48 85 C0 74 37
#define ADDRESS_INTERFACEMANAGER 0x4ECC710 // 48 8B 0D ? ? ? ? 48 8B D0 C6 44 24 ? ? E8 ? ? ? ? 48 8B 47 ? 48 8D 55 ?
#define ADDRESS_STATUSMANAGER 0x4E91190 // 48 89 35 ? ? ? ? 48 8B CF
#define ADDRESS_WEAPONMANAGER 0x36D9FB8 // no pattern
#define ADDRESS_VAULTMAXHEIGHT 0x000000 // 48 8D 15 ? ? ? ? 48 8B CE FF 90 ? ? ? ? 48 8B 06 49 8D 56 ? 48 8B CE FF 50 ? 48 8B 06 48 8D 15 ? ? ? ? 48 8B CE FF 90 ? ? ? ? 48 8B 06 49 8D 56 ? 48 8B CE FF 50 ? 48 8B 06 48 8D 15 ? ? ? ? 48 8B CE FF 90 ? ? ? ? 48 8B 06 49 8D 56 ? 48 8B CE FF 50 ? 48 8B 06 48 8D 15 ? ? ? ? 48 8B CE FF 90 ? ? ? ? 48 8B 06 49 8D 56 ? 48 8B CE FF 50 ? 48 8B 06 48 8D 15 ? ? ? ? 48 8B CE FF 90 ? ? ? ? 48 8B 06 49 8D 56 ? 48 8B CE FF 50 ? 48 8B 06 48 8D 15 ? ? ? ? 48 8B CE FF 90 ? ? ? ? 48 8B 06 49 8D 56 ? 48 8B CE FF 50 ? 48 8B 06 48 8D 15 ? ? ? ? 48 8B CE FF 90 ? ? ? ? 48 8B 06 49 8D 56 ? 48 8B CE FF 50 ? 48 8B 06 48 8D 15 ? ? ? ? 48 8B CE FF 90 ? ? ? ? 48 8B 06 49 8D 56 ? 48 8B CE FF 50 ? 48 8B 06 48 8D 15 ? ? ? ? 48 8B CE FF 90 ? ? ? ? 48 8B 06 49 8D 56 ? 48 8B CE FF 50 ? 48 8B 06

#define OFFSET_MISC_INGAME 0x334 

#define OFFSET_MISC_PLAYER_VIEWANGLE_1 0x620
#define OFFSET_MISC_PLAYER_VIEWANGLE_2 0x498
#define OFFSET_MISC_PLAYER_VIEWANGLE_3 0x10

#define OFFSET_GAMERENDERER_ENGINELINK 0x120
#define OFFSET_ENGINELINK_ENGINE 0x230
#define OFFSET_ENGINE_CAMERA 0x40
#define OFFSET_GAMERENDERER_DEREF 0x0

#define OFFSET_CAMERA_VIEWRIGHT 0xB0
#define OFFSET_CAMERA_VIEWUP 0xC0
#define OFFSET_CAMERA_VIEFORWARD 0xD0
#define OFFSET_CAMERA_VIEWTRANSLATION 0xE0
#define OFFSET_CAMERA_VIEWFOVX 0xF0
#define OFFSET_CAMERA_VIEWFOVY 0x104

#define OFFSET_GAMEMANAGER_ENTITYLIST 0xC8

#define OFFSET_ENTITY_ENTITYINFO 0x18
#define OFFSET_ENTITY_PLAYERINFO 0x2B8
#define OFFSET_ENTITY_PLAYERINFODEREF 0x0
#define OFFSET_ENTITYINFO_MAINCOMPONENT 0xA8 
#define OFFSET_MAINCOMPONENT_CHILDCOMPONENT 0x8
#define OFFSET_CHILDCOMPONENT_HEALTH 0x148

#define OFFSET_PLAYERINFO_COMPONENT_TEAM 0x146
#define OFFSET_PLAYERINFO_COMPONENT_NAME 0x178 

#define OFFSET_ENTITY_POSITION 0x1D0
#define OFFSET_ENTITY_NECK 0x2E0
#define OFFSET_ENTITY_HEAD 0x180

#define OFFSET_MAINCOMPONENT_ESPCHAIN1 0x30
#define OFFSET_ESPCHAIN1_ESPCHAIN2 0x78
#define OFFSET_ESPCHAIN2_ESPCHAIN3 0x2E4

#define OFFSET_NETMANAGER1 0xB0
#define OFFSET_NETMANAGER2 0x8
#define OFFSET_NETMANAGER3 0x118
#define OFFSET_NETOBJECTSIZE 0x0080

//btw game + 0x36D9FB8->0x20->0xC8->0x94 (std::uint32_t)
//should be like this
//'None (0), Reloading (1), Equipping (2), Pickup (3), Gadget (4), Post Shoot Action (5), Addon (9)', 0
//add action + 1 to get true action
//Current state of the weapon : Idle(0), Empty(1), Reload(2), TacticalReload(3), Shoot(4), ShootAlt(5),
//PostShootAction(6), ReloadCycle(7), EndReloadCycle(8), EndTacticalReloadCycle(9), TacticalReloadPaused(10),
//ReloadPaused(11), Equip(12), Unequip(13), BarrelSwap(20), BarrelSwapPaused(21)