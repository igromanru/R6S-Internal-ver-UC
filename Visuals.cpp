//          _                          _          __ ___   ___   ___  
//    /\   | |                        | |        /_ |__ \ / _ \ / _ \ 
//   /  \  | | _____  ____ _ _ __   __| | ___ _ __| |  ) | | | | (_) |
//  / /\ \ | |/ _ \ \/ / _` | '_ \ / _` |/ _ \ '__| | / /| | | |> _ < 
// / ____ \| |  __/>  < (_| | | | | (_| |  __/ |  | |/ /_| |_| | (_) |
///_/    \_\_|\___/_/\_\__,_|_| |_|\__,_|\___|_|  |_|____|\___/ \___/ 

#include "Visuals.h"
#include "GameManager.h"
#include "InterfaceManager.h"
#include "GameRenderer.h"
#include "WeaponManager.h"
#include "NetworkManager.h"
#include "StatusManager.h"
#include "GadgetManager.h"
#include <vector>
#include "Offsets.h"

Visuals* Visuals::m_pInstance;

Visuals::Visuals()
{
}
Visuals::~Visuals()
{
}

void Visuals::VisualsMain()
{
	auto pStatusManager = Engine::StatusManager::GetInstance();
	if (pStatusManager->IsInGame()) {
		Visuals::DrawESP();
		Visuals::DrawVisuals();
		Visuals::Glaz();
		Visuals::Effects();
	}
}

void Visuals::DrawESP()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	auto pGameManager = Engine::GameManager::GetInstance();
	auto pCameraManager = Engine::GameRenderer::GetInstance()->GetCamera();

	for (uint64_t i = 0; i < pGameManager->GetEntities().GetSize(); i++)
	{
		Engine::Entity* pEntity = pGameManager->GetEntities()[i];
		Engine::Entity* pLocal = pGameManager->GetLocalPlayer();

		if (pEntity == nullptr)
			return;

		float Health = pEntity->GetHealth();

		if (Health > 0)
		{
			if (pEntity)
			{
				Vector3 Position = pCameraManager->WorldToScreen(pEntity->GetPosition());
				Vector3 HeadPosition = pCameraManager->WorldToScreen(pEntity->GetHead());
				Vector3 lPosition = pCameraManager->WorldToScreen(pLocal->GetPosition());
				Vector3 lHeadPosition = pCameraManager->WorldToScreen(pLocal->GetHead());

				if (Position.z >= 1.5f)
				{
					if (pLocal->GetTeam() != pEntity->GetTeam()) {
						if (Settings::bESPEnemy) {
							if (Settings::bESP2DBox)
							{
								Renderer::GetInstance()->DrawBox(ImVec2(Position.x, Position.y), ImVec2(HeadPosition.x, HeadPosition.y), Settings::ColorEnemy2DBox);
							}
							if (Settings::bESP3DBox)
							{
								float distance = pCameraManager->GetViewTranslation().Distance(pEntity->GetPosition());
								float drawW = 245 / distance;
								float drawW2 = 135 / distance;
								float drawW3 = 55 / distance;

								Renderer::GetInstance()->DrawLine(ImVec2(Position.x - drawW, Position.y), ImVec2(Position.x + drawW, Position.y), 1, Settings::ColorEnemy3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(HeadPosition.x - drawW, HeadPosition.y), ImVec2(HeadPosition.x + drawW, HeadPosition.y), 1, Settings::ColorEnemy3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(HeadPosition.x - drawW, HeadPosition.y), ImVec2(Position.x - drawW, Position.y), 1, Settings::ColorEnemy3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(HeadPosition.x + drawW, HeadPosition.y), ImVec2(Position.x + drawW, Position.y), 1, Settings::ColorEnemy3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(HeadPosition.x - drawW2, HeadPosition.y - drawW3), ImVec2(Position.x - drawW2, Position.y - drawW3), 1, Settings::ColorEnemy3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(Position.x - drawW, Position.y), ImVec2(Position.x - drawW2, Position.y - drawW3), 1, Settings::ColorEnemy3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(HeadPosition.x - drawW, HeadPosition.y), ImVec2(HeadPosition.x - drawW2, HeadPosition.y - drawW3), 1, Settings::ColorEnemy3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2((HeadPosition.x + drawW) + drawW2, HeadPosition.y - drawW3), ImVec2((Position.x + drawW) + drawW2, Position.y - drawW3), 1, Settings::ColorEnemy3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(Position.x + drawW, Position.y), ImVec2((Position.x + drawW) + drawW2, Position.y - drawW3), 1, Settings::ColorEnemy3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(HeadPosition.x + drawW, HeadPosition.y), ImVec2((HeadPosition.x + drawW) + drawW2, HeadPosition.y - drawW3), 1, Settings::ColorEnemy3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(HeadPosition.x - drawW2, HeadPosition.y - drawW3), ImVec2((HeadPosition.x + drawW) + drawW2, HeadPosition.y - drawW3), 1, Settings::ColorEnemy3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(Position.x - drawW2, Position.y - drawW3), ImVec2((Position.x + drawW) + drawW2, Position.y - drawW3), 1, Settings::ColorEnemy3DBox);
							}
							if (Settings::bESPHead)
							{
								Renderer::GetInstance()->DrawCircleScale(ImVec2(HeadPosition.x, HeadPosition.y), 5.f, Settings::ColorEnemyHead, ImVec2(Position.x, Position.y), ImVec2(HeadPosition.x, HeadPosition.y));
							}
							if (Settings::bESPDistance)
							{
								float distance = pCameraManager->GetViewTranslation().Distance(pEntity->GetPosition());
								Renderer::GetInstance()->DrawOutlinedText(Renderer::GetInstance()->m_pDefault, Helpers::VariableText(XorStr("[%.1fm]"), distance), ImVec2(Position.x, Position.y), 12.f, Settings::ColorEnemyDistance, true);
							}
							if (Settings::bESPSnapline)
							{
								Renderer::GetInstance()->DrawLine(ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y), ImVec2(Position.x, Position.y), Settings::ColorEnemySnapline);
							}
							if (Settings::bESPName) {
								Renderer::GetInstance()->DrawOutlinedText(Renderer::GetInstance()->m_pDefault, pEntity->GetName(), ImVec2(Position.x, Position.y + 10), 12.f, Settings::ColorEnemyName, true);
							}
							if (Settings::bESPHealth)
							{
								ImGuiWindow* window = ImGui::GetCurrentWindow();
								ImVec2 scalepos(Position.x, Position.y);
								ImVec2 scaleheadPosition(HeadPosition.x, HeadPosition.y);

								uint32_t backcolor = 0xFF555656;

								float width = (scaleheadPosition.y + 15 - scalepos.y) / 4.5f;
								float healthwidth1 = (scalepos.y - scaleheadPosition.y);
								float healthwidth2 = healthwidth1 / 120;
								float defhealthwidth = healthwidth2 * Health;

								if (Health > 120.0f) {
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scaleheadPosition.y), ImVec2(scalepos.x - width + 5, scalepos.y), backcolor, 2.5f);
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scalepos.y - defhealthwidth), ImVec2(scalepos.x - width + 5, scalepos.y), 0xFF0000ff, 2.5f);
								}
								else if (Health > 90.0f) {
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scaleheadPosition.y), ImVec2(scalepos.x - width + 5, scalepos.y), backcolor, 2.5f);
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scalepos.y - defhealthwidth), ImVec2(scalepos.x - width + 5, scalepos.y), 0xFF02ff00, 2.5f);
								}
								else if (Health > 60.0f) {
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scaleheadPosition.y), ImVec2(scalepos.x - width + 5, scalepos.y), backcolor, 2.5f);
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scalepos.y - defhealthwidth), ImVec2(scalepos.x - width + 5, scalepos.y), 0xFFfff904, 2.5f);
								}
								else if (Health > 30.0f) {
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scaleheadPosition.y), ImVec2(scalepos.x - width + 5, scalepos.y), backcolor, 2.5f);
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scalepos.y - defhealthwidth), ImVec2(scalepos.x - width + 5, scalepos.y), 0xFFfbae00, 2.5f);
								}
								else {
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scaleheadPosition.y), ImVec2(scalepos.x - width + 5, scalepos.y), backcolor, 2.5f);
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scalepos.y - defhealthwidth), ImVec2(scalepos.x - width + 5, scalepos.y), 0xFFff0000, 2.5f);
								}
							}
							if (Settings::bESPFlashed)
							{
								auto IsFlashed = pEntity->IsFlashed();
								if (IsFlashed == 1)
								{
									float posoffset = Position.y - HeadPosition.y;
									float posoffset2 = Position.y - posoffset - 15;

									Renderer::GetInstance()->DrawOutlinedText(Renderer::GetInstance()->m_pDefault, XorStr("CONFUSED!"), ImVec2(Position.x, posoffset2), 12.f, Settings::ColorConfused, true);
								}
							}
							if (Settings::bESPSpotted) {
								pEntity->SpottedEsp();
							}
						}
					}
					else {
						if (Settings::bESPTeam) {
							if (Settings::bESP2DBox)
							{
								Renderer::GetInstance()->DrawBox(ImVec2(Position.x, Position.y), ImVec2(HeadPosition.x, HeadPosition.y), Settings::ColorTeam2DBox);
							}
							if (Settings::bESP3DBox)
							{
								float distance = pCameraManager->GetViewTranslation().Distance(pEntity->GetPosition());
								float drawW = 245 / distance;
								float drawW2 = 135 / distance;
								float drawW3 = 55 / distance;

								Renderer::GetInstance()->DrawLine(ImVec2(Position.x - drawW, Position.y), ImVec2(Position.x + drawW, Position.y), 1, Settings::ColorTeam3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(HeadPosition.x - drawW, HeadPosition.y), ImVec2(HeadPosition.x + drawW, HeadPosition.y), 1, Settings::ColorTeam3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(HeadPosition.x - drawW, HeadPosition.y), ImVec2(Position.x - drawW, Position.y), 1, Settings::ColorTeam3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(HeadPosition.x + drawW, HeadPosition.y), ImVec2(Position.x + drawW, Position.y), 1, Settings::ColorTeam3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(HeadPosition.x - drawW2, HeadPosition.y - drawW3), ImVec2(Position.x - drawW2, Position.y - drawW3), 1, Settings::ColorTeam3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(Position.x - drawW, Position.y), ImVec2(Position.x - drawW2, Position.y - drawW3), 1, Settings::ColorTeam3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(HeadPosition.x - drawW, HeadPosition.y), ImVec2(HeadPosition.x - drawW2, HeadPosition.y - drawW3), 1, Settings::ColorTeam3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2((HeadPosition.x + drawW) + drawW2, HeadPosition.y - drawW3), ImVec2((Position.x + drawW) + drawW2, Position.y - drawW3), 1, Settings::ColorTeam3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(Position.x + drawW, Position.y), ImVec2((Position.x + drawW) + drawW2, Position.y - drawW3), 1, Settings::ColorTeam3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(HeadPosition.x + drawW, HeadPosition.y), ImVec2((HeadPosition.x + drawW) + drawW2, HeadPosition.y - drawW3), 1, Settings::ColorTeam3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(HeadPosition.x - drawW2, HeadPosition.y - drawW3), ImVec2((HeadPosition.x + drawW) + drawW2, HeadPosition.y - drawW3), 1, Settings::ColorTeam3DBox);
								Renderer::GetInstance()->DrawLine(ImVec2(Position.x - drawW2, Position.y - drawW3), ImVec2((Position.x + drawW) + drawW2, Position.y - drawW3), 1, Settings::ColorTeam3DBox);
							}
							if (Settings::bESPHead)
							{
								Renderer::GetInstance()->DrawCircleScale(ImVec2(HeadPosition.x, HeadPosition.y), 5.f, Settings::ColorTeamHead, ImVec2(Position.x, Position.y), ImVec2(HeadPosition.x, HeadPosition.y));
							}
							if (Settings::bESPDistance)
							{
								float distance = pCameraManager->GetViewTranslation().Distance(pEntity->GetPosition());
								Renderer::GetInstance()->DrawOutlinedText(Renderer::GetInstance()->m_pDefault, Helpers::VariableText(XorStr("[%.1fm]"), distance), ImVec2(Position.x, Position.y), 12.f, Settings::ColorTeamDistance, true);
							}
							if (Settings::bESPSnapline)
							{
								Renderer::GetInstance()->DrawLine(ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y), ImVec2(Position.x, Position.y), Settings::ColorTeamSnapline);
							}
							if (Settings::bESPName)
							{
								Renderer::GetInstance()->DrawOutlinedText(Renderer::GetInstance()->m_pDefault, pEntity->GetName(), ImVec2(Position.x, Position.y + 10), 12.f, Settings::ColorTeamName, true);
							}
							if (Settings::bESPHealth)
							{
								ImGuiWindow* window = ImGui::GetCurrentWindow();
								ImVec2 scalepos(Position.x, Position.y);
								ImVec2 scaleheadPosition(HeadPosition.x, HeadPosition.y);

								uint32_t backcolor = 0xFF555656;

								float width = (scaleheadPosition.y + 15 - scalepos.y) / 4.5f;
								float healthwidth1 = (scalepos.y - scaleheadPosition.y);
								float healthwidth2 = healthwidth1 / 120;
								float defhealthwidth = healthwidth2 * Health;

								if (Health > 120.0f) {
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scaleheadPosition.y), ImVec2(scalepos.x - width + 5, scalepos.y), backcolor, 2.5f);
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scalepos.y - defhealthwidth), ImVec2(scalepos.x - width + 5, scalepos.y), 0xFF0000ff, 2.5f);
								}
								else if (Health > 90.0f) {
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scaleheadPosition.y), ImVec2(scalepos.x - width + 5, scalepos.y), backcolor, 2.5f);
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scalepos.y - defhealthwidth), ImVec2(scalepos.x - width + 5, scalepos.y), 0xFF02ff00, 2.5f);
								}
								else if (Health > 60.0f) {
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scaleheadPosition.y), ImVec2(scalepos.x - width + 5, scalepos.y), backcolor, 2.5f);
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scalepos.y - defhealthwidth), ImVec2(scalepos.x - width + 5, scalepos.y), 0xFFfff904, 2.5f);
								}
								else if (Health > 30.0f) {
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scaleheadPosition.y), ImVec2(scalepos.x - width + 5, scalepos.y), backcolor, 2.5f);
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scalepos.y - defhealthwidth), ImVec2(scalepos.x - width + 5, scalepos.y), 0xFFfbae00, 2.5f);
								}
								else {
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scaleheadPosition.y), ImVec2(scalepos.x - width + 5, scalepos.y), backcolor, 2.5f);
									Renderer::GetInstance()->DrawLine(ImVec2(scalepos.x - width + 5, scalepos.y - defhealthwidth), ImVec2(scalepos.x - width + 5, scalepos.y), 0xFFff0000, 2.5f);
								}
							}
							if (Settings::bESPFlashed)
							{
								auto IsFlashed = pEntity->IsFlashed();
								if (IsFlashed == 1)
								{
									float posoffset = Position.y - HeadPosition.y;
									float posoffset2 = Position.y - posoffset - 15;

									Renderer::GetInstance()->DrawOutlinedText(Renderer::GetInstance()->m_pDefault, XorStr("CONFUSED!"), ImVec2(Position.x, posoffset2), 12.f, Settings::ColorConfused, true);
								}
							}
							if (Settings::bESPSpotted) {
								pEntity->SpottedEsp();
							}
						}
					}
					if (Settings::bAccuracyAimbot && Settings::aimbotTarget == i && GetAsyncKeyState(VK_CAPITAL)) {
						Renderer::GetInstance()->DrawBox(ImVec2(Position.x, Position.y), ImVec2(HeadPosition.x, HeadPosition.y), Settings::ColorAimbotLock);
					}
					if (Settings::bTeleport && Settings::teleportTarget == i) {
						Renderer::GetInstance()->DrawBox(ImVec2(Position.x, Position.y), ImVec2(HeadPosition.x, HeadPosition.y), Settings::ColorTeleportLock);
					}
				}
				if (Settings::bAccuracyAimShowFOV)
				{
					Renderer::GetInstance()->DrawCircle(ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y / 2), Settings::aimFov, Settings::ColorFov, 1.0f);
				}
			}
		}
	}
}

void Visuals::DrawVisuals()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	if (Settings::bVisualsCrosshair)
	{
		Renderer::GetInstance()->DrawLine(ImVec2(io.DisplaySize.x / 2 - 15, io.DisplaySize.y / 2), ImVec2(io.DisplaySize.x / 2 - 5, io.DisplaySize.y / 2), Settings::ColorCrosshair, 3.f);
		Renderer::GetInstance()->DrawLine(ImVec2(io.DisplaySize.x / 2 + 16, io.DisplaySize.y / 2), ImVec2(io.DisplaySize.x / 2 + 6, io.DisplaySize.y / 2), Settings::ColorCrosshair, 3.f);
		Renderer::GetInstance()->DrawLine(ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y / 2 - 15), ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y / 2 - 5), Settings::ColorCrosshair, 3.f);
		Renderer::GetInstance()->DrawLine(ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y / 2 + 16), ImVec2(io.DisplaySize.x / 2, io.DisplaySize.y / 2 + 6), Settings::ColorCrosshair, 3.f);
	}
	if (Settings::bVisualsFPS)
	{
		Renderer::GetInstance()->DrawOutlinedText(Renderer::GetInstance()->m_pDefault, Helpers::VariableText(XorStr("%.1f"), io.Framerate), ImVec2(20, 20), 26.f, Settings::ColorFov, false);
	}
}

void Visuals::Effects() {
	if (Settings::bNoEffects || Settings::bNoSmoke || Settings::bGlaz) {
		auto pGameManager = Engine::GameManager::GetInstance();
		Engine::Entity* pLocal = pGameManager->GetLocalPlayer();
		if (pLocal->GetHealth() > 0) {
			DWORD64 Effectstuff[] = { 0x4A263E8,0x18,0x590,0x5F8 };

			int* TempWriteInt;
			if (Settings::bNoEffects) {
				// No Effects
				void* PA = *Engine::Memory::Ptr<void**>((void*)GetModuleHandle("RainbowSix.exe"), Effectstuff[0]);

				for (int i = 1; i < 4; i++) {
					PA = *Engine::Memory::Ptr<void**>(PA, Effectstuff[i]);
				}

				TempWriteInt = Engine::Memory::Ptr<int*>(PA, 0x7C0);
				*TempWriteInt = 0;
			}

			if (Settings::bNoSmoke) {
				// No Smoke
				void* PA = *Engine::Memory::Ptr<void**>((void*)GetModuleHandle("RainbowSix.exe"), Effectstuff[0]);

				for (int i = 1; i < 4; i++) {
					PA = *Engine::Memory::Ptr<void**>(PA, Effectstuff[i]);
				}

				TempWriteInt = Engine::Memory::Ptr<int*>(PA, 0x7B0);
				*TempWriteInt = 1;
			}

			if (Settings::bGlaz) {
				// Glaz
				void* PA = *Engine::Memory::Ptr<void**>((void*)GetModuleHandle("RainbowSix.exe"), Effectstuff[0]);

				for (int i = 1; i < 4; i++) {
					PA = *Engine::Memory::Ptr<void**>(PA, Effectstuff[i]);
				}

				TempWriteInt = Engine::Memory::Ptr<int*>(PA, 0x764);
				*TempWriteInt = 1;

				// Glaz Size
				float* TempWriteFloat = Engine::Memory::Ptr<float*>(PA, 0x7A0);
				*TempWriteFloat = 1000000;
			}
		}
	}
}

void Visuals::Glaz() {
	if (Settings::bGlaz) {
		auto pGameManager = Engine::GameManager::GetInstance();
		Engine::Entity* pLocal = pGameManager->GetLocalPlayer();
		if (pLocal->GetHealth() > 0) {
			Vector3* GlowColorPointers;
			Vector2* GlowDistancePointers;
			float* GlowOpacityPointer;
			float* GlowZeroPointers[3];
			void* GlowBase;
			Vector3 GlowColors = Vector3(Settings::fGlaz1, Settings::fGlaz2, Settings::fGlaz3);
			Vector2 GlowDistance = Vector2(2, 2);
			float GlowOpacity = 0;

			GlowBase = *Engine::Memory::Ptr<void**>(*Engine::Memory::Ptr<void**>((void*)GetModuleHandle("RainbowSix.exe"), 0x4A263A8), 0x90);
			if (Engine::Memory::IsValidPtr(GlowBase)) {
				GlowColorPointers = GetGlowColorPointers(GlowBase);
				GlowDistancePointers = GetGlowDistancePointer(GlowBase);
				GlowOpacityPointer = GetGlowOpacityPointer(GlowBase);
				GlowZeroPointers[0] = GetGlowZeroPointer1(GlowBase);
				GlowZeroPointers[1] = GetGlowZeroPointer2(GlowBase);
				GlowZeroPointers[2] = GetGlowZeroPointer3(GlowBase);
				*GlowZeroPointers[0] = 0;
				*GlowZeroPointers[1] = 0;
				*GlowZeroPointers[2] = 0;
				*GlowDistancePointers = GlowDistance;
				*GlowOpacityPointer = GlowOpacity;
				if (GlowColors.x == 0 && GlowColors.y == 0 && GlowColors.z == 0) {
					GlowColors.x = 20;
				}
				else if (GlowColors.x != 0 && GlowColors.z == 0) {
					GlowColors.x--;
					GlowColors.y++;
				}
				else if (GlowColors.x == 0 && GlowColors.y != 0) {
					GlowColors.y--;
					GlowColors.z++;
				}
				else if (GlowColors.z != 0 && GlowColors.y == 0) {
					GlowColors.z--;
					GlowColors.x++;
				}
				*GlowColorPointers = GlowColors;
			}
		}
	}
}

Vector3* Visuals::GetGlowColorPointers(void* GlowBase) {
	return Engine::Memory::Ptr<Vector3*>(GlowBase, 0x140);
}
float* Visuals::GetGlowZeroPointer1(void* GlowBase) {
	if (!Engine::Memory::IsValidPtr(GlowBase)) {
		return nullptr;
	}
	return Engine::Memory::Ptr<float*>(GlowBase, 0x14C);
}
float* Visuals::GetGlowZeroPointer2(void* GlowBase) {
	if (!Engine::Memory::IsValidPtr(GlowBase)) {
		return nullptr;
	}
	return Engine::Memory::Ptr<float*>(GlowBase, 0x158);
}
float* Visuals::GetGlowZeroPointer3(void* GlowBase) {
	if (!Engine::Memory::IsValidPtr(GlowBase)) {
		return nullptr;
	}
	return Engine::Memory::Ptr<float*>(GlowBase, 0x164);
}

Vector2* Visuals::GetGlowDistancePointer(void* GlowBase) {
	if (!Engine::Memory::IsValidPtr(GlowBase)) {
		return nullptr;
	}
	return Engine::Memory::Ptr<Vector2*>(GlowBase, 0x15C);
}
float* Visuals::GetGlowOpacityPointer(void* GlowBase) {
	if (!Engine::Memory::IsValidPtr(GlowBase)) {
		return nullptr;
	}
	return Engine::Memory::Ptr<float*>(GlowBase, 0x168);
}

Visuals* Visuals::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new Visuals();

	return m_pInstance;
}