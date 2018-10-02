//          _                          _          __ ___   ___   ___  
//    /\   | |                        | |        /_ |__ \ / _ \ / _ \ 
//   /  \  | | _____  ____ _ _ __   __| | ___ _ __| |  ) | | | | (_) |
//  / /\ \ | |/ _ \ \/ / _` | '_ \ / _` |/ _ \ '__| | / /| | | |> _ < 
// / ____ \| |  __/>  < (_| | | | | (_| |  __/ |  | |/ /_| |_| | (_) |
///_/    \_\_|\___/_/\_\__,_|_| |_|\__,_|\___|_|  |_|____|\___/ \___/ 

#pragma once
#include "stdafx.h"
#include "Entity.h"
#include "GameManager.h"
#include "GameRenderer.h"
#include "Settings.h"
#include "Renderer.h"

class Visuals
{
public:
	void DrawESP();
	void DrawVisuals();
	void VisualsMain();
	void Effects();
	void Glaz();
	Vector3* GetGlowColorPointers(void* GlowBase);
	float* GetGlowZeroPointer1(void* GlowBase);
	float* GetGlowZeroPointer2(void* GlowBase);
	float* GetGlowZeroPointer3(void* GlowBase);
	Vector2* GetGlowDistancePointer(void* GlowBase);
	float* GetGlowOpacityPointer(void* GlowBase);

	static Visuals* GetInstance();

private:
	Visuals();
	~Visuals();

	static Visuals* m_pInstance;
};