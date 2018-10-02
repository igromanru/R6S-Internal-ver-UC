//          _                          _          __ ___   ___   ___  
//    /\   | |                        | |        /_ |__ \ / _ \ / _ \ 
//   /  \  | | _____  ____ _ _ __   __| | ___ _ __| |  ) | | | | (_) |
//  / /\ \ | |/ _ \ \/ / _` | '_ \ / _` |/ _ \ '__| | / /| | | |> _ < 
// / ____ \| |  __/>  < (_| | | | | (_| |  __/ |  | |/ /_| |_| | (_) |
///_/    \_\_|\___/_/\_\__,_|_| |_|\__,_|\___|_|  |_|____|\___/ \___/ 

#include "UserInterface.h"
#include "Settings.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_internal.h"
#include "GameManager.h"

UserInterface* UserInterface::m_pInstance;

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
}

void UserInterface::SetStyle()
{
	ImGuiStyle& style = ImGui::GetStyle();

	style.WindowPadding = ImVec2(15, 15);
	style.WindowRounding = 5.0f;
	style.FramePadding = ImVec2(5, 5);
	style.FrameRounding = 4.0f;
	style.ItemSpacing = ImVec2(12, 8);
	style.ItemInnerSpacing = ImVec2(8, 6);
	style.IndentSpacing = 25.0f;
	style.ScrollbarSize = 15.0f;
	style.ScrollbarRounding = 9.0f;
	style.GrabMinSize = 5.0f;
	style.GrabRounding = 3.0f;

	style.Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style.Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style.Colors[ImGuiCol_ComboBg] = ImVec4(0.19f, 0.18f, 0.21f, 1.00f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style.Colors[ImGuiCol_Column] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style.Colors[ImGuiCol_CloseButton] = ImVec4(0.40f, 0.39f, 0.38f, 0.16f);
	style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.40f, 0.39f, 0.38f, 0.39f);
	style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.40f, 0.39f, 0.38f, 1.00f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
}

void UserInterface::TextColor(bool active)
{
	auto& style = ImGui::GetStyle();

	if (active)
	{
		style.Colors[ImGuiCol_Text] = ImVec4(0.98f, 0.98f, 0.98f, 1.f);
	}
	else
		style.Colors[ImGuiCol_Text] = ImVec4(0.39f, 0.39f, 0.39f, 1.f);
}

void UserInterface::BtnNormal()
{
	auto& style = ImGui::GetStyle();

	style.Colors[ImGuiCol_Button] = ImVec4(0.10, 0.10, 0.10, .98f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.13f, 0.13f, 0.13f, 1.f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.f);
}

void UserInterface::BtnActive()
{
	auto& style = ImGui::GetStyle();

	style.Colors[ImGuiCol_Button] = ImVec4(0.15f, 0.15f, 0.15f, .98f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.15f, 0.15f, 0.15f, 1.f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.15f, 0.15f, 0.15f, 1.f);
}

void UserInterface::Render()
{
	if (!Settings::Menu)
		return;

	ImGui::Begin(XorStr("Developer: AlexB#8495"), nullptr, ImGuiWindowFlags_NoResize);
	ImGuiStyle& style = ImGui::GetStyle();
	ImVec2 itemSpacing = style.ItemSpacing;
	style.ItemSpacing.y = 15;
	ImGui::SetWindowSize(ImVec2(430, 600));
	ImGui::CaptureMouseFromApp(true);
	ImGui::CaptureKeyboardFromApp(true);
	static int currentTab = 0;
	ImGui::PushFont(Renderer::GetInstance()->m_pDefault);

	if (ImGui::CollapsingHeader(XorStr("AIMBOT")))
	{
		ImGui::SetWindowSize(ImVec2(430, 600));

		ImGui::Text(XorStr("Aim Assistance"));
		ImGui::Separator();
		ImGui::Columns(2, XorStr("Test"), false);
		{
			ImGui::Text(XorStr("Aimbot - Main"));
			ImGui::Checkbox(XorStr("Aimbot"), &Settings::bAccuracyAimbot);

			ImGui::NextColumn();

			ImGui::Text(XorStr("Aimbot - Others"));
			ImGui::Checkbox(XorStr("Show FOV"), &Settings::bAccuracyAimShowFOV);
		}
		ImGui::Columns(1);

		ImGui::Text(XorStr("Aim Settings"));
		ImGui::Separator();
		ImGui::SliderInt(XorStr("Aimbot Fov"), &Settings::aimFov, 1, 720);
		ImGui::SliderInt(XorStr("Aimbot Distance"), &Settings::aimDist, 1, 300);
		ImGui::SliderInt(XorStr("Aimbot Smooth"), &Settings::aimSmooth, 1, 15);
		static int iAimbotKey = 0;
		const char* AimbotKey[] = { "CAPSLOCK", "MOUSE 1", "MOUSE 2" };
		ImGui::Combo(XorStr("Aimbot Key"), &iAimbotKey, AimbotKey, 3);
		switch (iAimbotKey)
		{
			//CAPSLOCK
		case 0: Settings::AimbotKey = 1; break;
			//MOUSE 1
		case 1: Settings::AimbotKey = 2; break;
			//MOUSE 2
		case 2: Settings::AimbotKey = 3; break;
		}
	}

	if (ImGui::CollapsingHeader(XorStr("VISUALS")))
	{
		ImGui::SetWindowSize(ImVec2(430, 600));

		ImGui::Text(XorStr("Visuals Team"));
		ImGui::Separator();
		ImGui::Columns(2, XorStr("Test"), false);
		{
			ImGui::Checkbox(XorStr("Ally"), &Settings::bESPTeam);

			ImGui::NextColumn();

			ImGui::Checkbox(XorStr("Enemy"), &Settings::bESPEnemy);
		}
		ImGui::Columns(1);

		ImGui::Text(XorStr("Visuals Assistance"));
		ImGui::Separator();
		ImGui::Columns(2, XorStr("Test"), false);
		{
			ImGui::Text(XorStr("Visuals - Main"));
			ImGui::Checkbox(XorStr("2D Box"), &Settings::bESP2DBox);
			ImGui::Checkbox(XorStr("3D Box"), &Settings::bESP3DBox);
			ImGui::Checkbox(XorStr("Head"), &Settings::bESPHead);
			ImGui::Checkbox(XorStr("Health"), &Settings::bESPHealth);
			/*ImGui::Checkbox(XorStr("Name"), &Settings::bESPName);*/
			ImGui::Checkbox(XorStr("No Smoke"), &Settings::bNoSmoke);
			ImGui::Checkbox(XorStr("No Effects"), &Settings::bNoEffects);
			
			ImGui::NextColumn();

			ImGui::Text(XorStr("Visuals - Others"));
			ImGui::Checkbox(XorStr("Confused"), &Settings::bESPFlashed);
			ImGui::Checkbox(XorStr("Distance"), &Settings::bESPDistance);
			ImGui::Checkbox(XorStr("Snaplines"), &Settings::bESPSnapline);
			ImGui::Checkbox(XorStr("Spotted Esp"), &Settings::bESPSpotted);
			ImGui::Checkbox(XorStr("Glaz"), &Settings::bGlaz);
			ImGui::Checkbox(XorStr("Gadgets"), &Settings::bGadget);
			ImGui::Checkbox(XorStr("Gadgets-Debug"), &Settings::bGadgetDebug);
		}
		ImGui::Columns(1);
		
	}
	if (ImGui::CollapsingHeader(XorStr("MISCELLANEOUS")))
	{
		ImGui::SetWindowSize(ImVec2(430, 600));

		ImGui::Text(XorStr("Misc Assistance"));
		ImGui::Separator();
		ImGui::Columns(2, XorStr("Test"), false);
		{
			ImGui::Text(XorStr("Misc - Main"));
			ImGui::Checkbox(XorStr("No Spread"), &Settings::bAccuracyNoRecoil);
			ImGui::Checkbox(XorStr("No Recoil"), &Settings::bAccuracyNoSpread);
			ImGui::Checkbox(XorStr("Teleport"), &Settings::bTeleport);

			ImGui::NextColumn();

			ImGui::Text(XorStr("Misc - Others"));
			ImGui::Checkbox(XorStr("FPS Counter"), &Settings::bVisualsFPS);
			ImGui::Checkbox(XorStr("Crosshair"), &Settings::bVisualsCrosshair);
			ImGui::Checkbox(XorStr("Triggerbot"), &Settings::bAccuracyTrigger);
		}
		ImGui::Columns(1);
	}

	static int ColorFov = 5;
	static int ColorConfused = 7;
	static int ColorFps = 1;
	static int ColorCrosshair = 1;

	static int ColorTeamHead = 1;
	static int ColorTeam2DBox = 1;
	static int ColorTeam3DBox = 1;
	static int ColorTeamDistance = 1;
	static int ColorTeamSnapline = 1;
	static int ColorTeamName = 1;

	static int ColorEnemyHead = 0;
	static int ColorEnemy2DBox = 0;
	static int ColorEnemy3DBox = 0;
	static int ColorEnemyDistance = 0;
	static int ColorEnemySnapline = 0;
	static int ColorEnemyName = 0;

	static int ColorTeleportLock = 8;
	static int ColorAimbotLock = 3;

	const char* EspColor[] = { "Red", "Green", "Purple", "Blue", "Black", "White", "Pink", "Yellow", "Orange" };
	if (ImGui::CollapsingHeader(XorStr("COLORS")))
	{
		ImGui::SetWindowSize(ImVec2(430, 600));

		ImGui::Text(XorStr("Color Options"));
		ImGui::Separator();
		ImGui::Columns(2, XorStr("Test"), false);
		{
			ImGui::Text(XorStr("Color - Team"));
			ImGui::Combo(XorStr("T-Head"), &ColorTeamHead, EspColor, 9);
			switch (ColorTeamHead)
			{
				//Red
			case 0: Settings::ColorTeamHead = 0xFFff0000; break;
				//Green
			case 1: Settings::ColorTeamHead = 0xFF02ff00; break;
				//Purple
			case 2: Settings::ColorTeamHead = 0xFF9400d3; break;
				//Blue
			case 3: Settings::ColorTeamHead = 0xFF0000ff; break;
				//Black
			case 4: Settings::ColorTeamHead = 0xFF000000; break;
				//White
			case 5: Settings::ColorTeamHead = 0xFFfffffd; break;
				//Pink
			case 6: Settings::ColorTeamHead = 0xFFfd69ed; break;
				//Yellow
			case 7: Settings::ColorTeamHead = 0xFFfff904; break;
				//Orange
			case 8: Settings::ColorTeamHead = 0xFFfbae00; break;
			}

			ImGui::Combo(XorStr("T-2D Box"), &ColorTeam2DBox, EspColor, 9);
			switch (ColorTeam2DBox)
			{
			case 0: Settings::ColorTeam2DBox = 0xFFff0000; break;
			case 1: Settings::ColorTeam2DBox = 0xFF02ff00; break;
			case 2: Settings::ColorTeam2DBox = 0xFF9400d3; break;
			case 3: Settings::ColorTeam2DBox = 0xFF0000ff; break;
			case 4: Settings::ColorTeam2DBox = 0xFF000000; break;
			case 5: Settings::ColorTeam2DBox = 0xFFfffffd; break;
			case 6: Settings::ColorTeam2DBox = 0xFFfd69ed; break;
			case 7: Settings::ColorTeam2DBox = 0xFFfff904; break;
			case 8: Settings::ColorTeam2DBox = 0xFFfbae00; break;
			}

			ImGui::Combo(XorStr("T-3D Box"), &ColorTeam3DBox, EspColor, 9);
			switch (ColorTeam3DBox)
			{
			case 0: Settings::ColorTeam3DBox = 0xFFff0000; break;
			case 1: Settings::ColorTeam3DBox = 0xFF02ff00; break;
			case 2: Settings::ColorTeam3DBox = 0xFF9400d3; break;
			case 3: Settings::ColorTeam3DBox = 0xFF0000ff; break;
			case 4: Settings::ColorTeam3DBox = 0xFF000000; break;
			case 5: Settings::ColorTeam3DBox = 0xFFfffffd; break;
			case 6: Settings::ColorTeam3DBox = 0xFFfd69ed; break;
			case 7: Settings::ColorTeam3DBox = 0xFFfff904; break;
			case 8: Settings::ColorTeam3DBox = 0xFFfbae00; break;
			}

			ImGui::Combo(XorStr("T-Distance"), &ColorTeamDistance, EspColor, 9);
			switch (ColorTeamDistance)
			{
			case 0: Settings::ColorTeamDistance = 0xFFff0000; break;
			case 1: Settings::ColorTeamDistance = 0xFF02ff00; break;
			case 2: Settings::ColorTeamDistance = 0xFF9400d3; break;
			case 3: Settings::ColorTeamDistance = 0xFF0000ff; break;
			case 4: Settings::ColorTeamDistance = 0xFF000000; break;
			case 5: Settings::ColorTeamDistance = 0xFFfffffd; break;
			case 6: Settings::ColorTeamDistance = 0xFFfd69ed; break;
			case 7: Settings::ColorTeamDistance = 0xFFfff904; break;
			case 8: Settings::ColorTeamDistance = 0xFFfbae00; break;
			}

			ImGui::Combo(XorStr("T-Snapline"), &ColorTeamSnapline, EspColor, 9);
			switch (ColorTeamSnapline)
			{
			case 0: Settings::ColorTeamSnapline = 0xFFff0000; break;
			case 1: Settings::ColorTeamSnapline = 0xFF02ff00; break;
			case 2: Settings::ColorTeamSnapline = 0xFF9400d3; break;
			case 3: Settings::ColorTeamSnapline = 0xFF0000ff; break;
			case 4: Settings::ColorTeamSnapline = 0xFF000000; break;
			case 5: Settings::ColorTeamSnapline = 0xFFfffffd; break;
			case 6: Settings::ColorTeamSnapline = 0xFFfd69ed; break;
			case 7: Settings::ColorTeamSnapline = 0xFFfff904; break;
			case 8: Settings::ColorTeamSnapline = 0xFFfbae00; break;
			}

			//ImGui::Combo(XorStr("Name"), &ColorTeamName, EspColor, 9);
			//switch (ColorTeamName)
			//{
			//case 0: Settings::ColorTeamName = 0xFFff0000; break;
			//case 1: Settings::ColorTeamName = 0xFF02ff00; break;
			//case 2: Settings::ColorTeamName = 0xFF9400d3; break;
			//case 3: Settings::ColorTeamName = 0xFF0000ff; break;
			//case 4: Settings::ColorTeamName = 0xFF000000; break;
			//case 5: Settings::ColorTeamName = 0xFFfffffd; break;
			//case 6: Settings::ColorTeamName = 0xFFfd69ed; break;
			//case 7: Settings::ColorTeamName = 0xFFfff904; break;
			//case 8: Settings::ColorTeamName = 0xFFfbae00; break;
			//}

			ImGui::NextColumn();

			ImGui::Text(XorStr("Color - Enemy"));
			ImGui::Combo(XorStr("E-Head"), &ColorEnemyHead, EspColor, 9);
			switch (ColorEnemyHead)
			{
				//Red
			case 0: Settings::ColorEnemyHead = 0xFFff0000; break;
				//Green
			case 1: Settings::ColorEnemyHead = 0xFF02ff00; break;
				//Purple
			case 2: Settings::ColorEnemyHead = 0xFF9400d3; break;
				//Blue
			case 3: Settings::ColorEnemyHead = 0xFF0000ff; break;
				//Black
			case 4: Settings::ColorEnemyHead = 0xFF000000; break;
				//White
			case 5: Settings::ColorEnemyHead = 0xFFfffffd; break;
				//Pink
			case 6: Settings::ColorEnemyHead = 0xFFfd69ed; break;
				//Yellow
			case 7: Settings::ColorEnemyHead = 0xFFfff904; break;
				//Orange
			case 8: Settings::ColorEnemyHead = 0xFFfbae00; break;
			}

			ImGui::Combo(XorStr("E-2D Box"), &ColorEnemy2DBox, EspColor, 9);
			switch (ColorEnemy2DBox)
			{
			case 0: Settings::ColorEnemy2DBox = 0xFFff0000; break;
			case 1: Settings::ColorEnemy2DBox = 0xFF02ff00; break;
			case 2: Settings::ColorEnemy2DBox = 0xFF9400d3; break;
			case 3: Settings::ColorEnemy2DBox = 0xFF0000ff; break;
			case 4: Settings::ColorEnemy2DBox = 0xFF000000; break;
			case 5: Settings::ColorEnemy2DBox = 0xFFfffffd; break;
			case 6: Settings::ColorEnemy2DBox = 0xFFfd69ed; break;
			case 7: Settings::ColorEnemy2DBox = 0xFFfff904; break;
			case 8: Settings::ColorEnemy2DBox = 0xFFfbae00; break;
			}

			ImGui::Combo(XorStr("E-3D Box"), &ColorEnemy3DBox, EspColor, 9);
			switch (ColorEnemy3DBox)
			{
			case 0: Settings::ColorEnemy3DBox = 0xFFff0000; break;
			case 1: Settings::ColorEnemy3DBox = 0xFF02ff00; break;
			case 2: Settings::ColorEnemy3DBox = 0xFF9400d3; break;
			case 3: Settings::ColorEnemy3DBox = 0xFF0000ff; break;
			case 4: Settings::ColorEnemy3DBox = 0xFF000000; break;
			case 5: Settings::ColorEnemy3DBox = 0xFFfffffd; break;
			case 6: Settings::ColorEnemy3DBox = 0xFFfd69ed; break;
			case 7: Settings::ColorEnemy3DBox = 0xFFfff904; break;
			case 8: Settings::ColorEnemy3DBox = 0xFFfbae00; break;
			}

			ImGui::Combo(XorStr("E-Distance"), &ColorEnemyDistance, EspColor, 9);
			switch (ColorEnemyDistance)
			{
			case 0: Settings::ColorEnemyDistance = 0xFFff0000; break;
			case 1: Settings::ColorEnemyDistance = 0xFF02ff00; break;
			case 2: Settings::ColorEnemyDistance = 0xFF9400d3; break;
			case 3: Settings::ColorEnemyDistance = 0xFF0000ff; break;
			case 4: Settings::ColorEnemyDistance = 0xFF000000; break;
			case 5: Settings::ColorEnemyDistance = 0xFFfffffd; break;
			case 6: Settings::ColorEnemyDistance = 0xFFfd69ed; break;
			case 7: Settings::ColorEnemyDistance = 0xFFfff904; break;
			case 8: Settings::ColorEnemyDistance = 0xFFfbae00; break;
			}

			ImGui::Combo(XorStr("E-Snapline"), &ColorEnemySnapline, EspColor, 9);
			switch (ColorEnemySnapline)
			{
			case 0: Settings::ColorEnemySnapline = 0xFFff0000; break;
			case 1: Settings::ColorEnemySnapline = 0xFF02ff00; break;
			case 2: Settings::ColorEnemySnapline = 0xFF9400d3; break;
			case 3: Settings::ColorEnemySnapline = 0xFF0000ff; break;
			case 4: Settings::ColorEnemySnapline = 0xFF000000; break;
			case 5: Settings::ColorEnemySnapline = 0xFFfffffd; break;
			case 6: Settings::ColorEnemySnapline = 0xFFfd69ed; break;
			case 7: Settings::ColorEnemySnapline = 0xFFfff904; break;
			case 8: Settings::ColorEnemySnapline = 0xFFfbae00; break;
			}

			/*ImGui::Combo(XorStr("Name"), &ColorEnemyName, EspColor, 9);
			switch (ColorEnemyName)
			{
			case 0: Settings::ColorEnemyName = 0xFFff0000; break;
			case 1: Settings::ColorEnemyName = 0xFF02ff00; break;
			case 2: Settings::ColorEnemyName = 0xFF9400d3; break;
			case 3: Settings::ColorEnemyName = 0xFF0000ff; break;
			case 4: Settings::ColorEnemyName = 0xFF000000; break;
			case 5: Settings::ColorEnemyName = 0xFFfffffd; break;
			case 6: Settings::ColorEnemyName = 0xFFfd69ed; break;
			case 7: Settings::ColorEnemyName = 0xFFfff904; break;
			case 8: Settings::ColorEnemyName = 0xFFfbae00; break;
			}*/
		}
		ImGui::Columns(1);

		ImGui::Text(XorStr("Other Colors Options"));
		ImGui::Separator();
		ImGui::Columns(2, XorStr("Test"), false);
		{
			ImGui::Combo(XorStr("Fov"), &ColorFov, EspColor, 9);
			switch (ColorFov)
			{
			case 0: Settings::ColorFov = 0xFFff0000; break;
			case 1: Settings::ColorFov = 0xFF02ff00; break;
			case 2: Settings::ColorFov = 0xFF9400d3; break;
			case 3: Settings::ColorFov = 0xFF0000ff; break;
			case 4: Settings::ColorFov = 0xFF000000; break;
			case 5: Settings::ColorFov = 0xFFfffffd; break;
			case 6: Settings::ColorFov = 0xFFfd69ed; break;
			case 7: Settings::ColorFov = 0xFFfff904; break;
			case 8: Settings::ColorFov = 0xFFfbae00; break;
			}

			ImGui::Combo(XorStr("Crosshair"), &ColorCrosshair, EspColor, 9);
			switch (ColorCrosshair)
			{
			case 0: Settings::ColorCrosshair = 0xFFff0000; break;
			case 1: Settings::ColorCrosshair = 0xFF02ff00; break;
			case 2: Settings::ColorCrosshair = 0xFF9400d3; break;
			case 3: Settings::ColorCrosshair = 0xFF0000ff; break;
			case 4: Settings::ColorCrosshair = 0xFF000000; break;
			case 5: Settings::ColorCrosshair = 0xFFfffffd; break;
			case 6: Settings::ColorCrosshair = 0xFFfd69ed; break;
			case 7: Settings::ColorCrosshair = 0xFFfff904; break;
			case 8: Settings::ColorCrosshair = 0xFFfbae00; break;
			}

			ImGui::Combo(XorStr("TP Lock"), &ColorTeleportLock, EspColor, 9);
			switch (ColorTeleportLock)
			{
			case 0: Settings::ColorTeleportLock = 0xFFff0000; break;
			case 1: Settings::ColorTeleportLock = 0xFF02ff00; break;
			case 2: Settings::ColorTeleportLock = 0xFF9400d3; break;
			case 3: Settings::ColorTeleportLock = 0xFF0000ff; break;
			case 4: Settings::ColorTeleportLock = 0xFF000000; break;
			case 5: Settings::ColorTeleportLock = 0xFFfffffd; break;
			case 6: Settings::ColorTeleportLock = 0xFFfd69ed; break;
			case 7: Settings::ColorTeleportLock = 0xFFfff904; break;
			case 8: Settings::ColorTeleportLock = 0xFFfbae00; break;
			}

			ImGui::NextColumn();

			ImGui::Combo(XorStr("Confused"), &ColorConfused, EspColor, 9);
			switch (ColorConfused)
			{
			case 0: Settings::ColorConfused = 0xFFff0000; break;
			case 1: Settings::ColorConfused = 0xFF02ff00; break;
			case 2: Settings::ColorConfused = 0xFF9400d3; break;
			case 3: Settings::ColorConfused = 0xFF0000ff; break;
			case 4: Settings::ColorConfused = 0xFF000000; break;
			case 5: Settings::ColorConfused = 0xFFfffffd; break;
			case 6: Settings::ColorConfused = 0xFFfd69ed; break;
			case 7: Settings::ColorConfused = 0xFFfff904; break;
			case 8: Settings::ColorConfused = 0xFFfbae00; break;
			}

			ImGui::Combo(XorStr("Fps"), &ColorFps, EspColor, 9);
			switch (ColorFps)
			{
			case 0: Settings::ColorFps = 0xFFff0000; break;
			case 1: Settings::ColorFps = 0xFF02ff00; break;
			case 2: Settings::ColorFps = 0xFF9400d3; break;
			case 3: Settings::ColorFps = 0xFF0000ff; break;
			case 4: Settings::ColorFps = 0xFF000000; break;
			case 5: Settings::ColorFps = 0xFFfffffd; break;
			case 6: Settings::ColorFps = 0xFFfd69ed; break;
			case 7: Settings::ColorFps = 0xFFfff904; break;
			case 8: Settings::ColorFps = 0xFFfbae00; break;
			}

			ImGui::Combo(XorStr("Aimbot Lock"), &ColorAimbotLock, EspColor, 9);
			switch (ColorAimbotLock)
			{
			case 0: Settings::ColorAimbotLock = 0xFFff0000; break;
			case 1: Settings::ColorAimbotLock = 0xFF02ff00; break;
			case 2: Settings::ColorAimbotLock = 0xFF9400d3; break;
			case 3: Settings::ColorAimbotLock = 0xFF0000ff; break;
			case 4: Settings::ColorAimbotLock = 0xFF000000; break;
			case 5: Settings::ColorAimbotLock = 0xFFfffffd; break;
			case 6: Settings::ColorAimbotLock = 0xFFfd69ed; break;
			case 7: Settings::ColorAimbotLock = 0xFFfff904; break;
			case 8: Settings::ColorAimbotLock = 0xFFfbae00; break;
			}
		}
		ImGui::Columns(1);
		ImGui::Text(XorStr("Glaz color"));
		ImGui::Separator();
		ImGui::SliderFloat(XorStr("R"), &Settings::fGlaz1, 0, 255);
		ImGui::SliderFloat(XorStr("G"), &Settings::fGlaz2, 0, 255);
		ImGui::SliderFloat(XorStr("B"), &Settings::fGlaz3, 0, 255);
	}
	ImGui::Checkbox(XorStr("Eject cheat"), &Settings::bUnload);
	ImGui::End();
}

UserInterface* UserInterface::GetInstance()
{
	if (!m_pInstance)
		m_pInstance = new UserInterface();

	return m_pInstance;
}