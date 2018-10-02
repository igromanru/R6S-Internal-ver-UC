//          _                          _          __ ___   ___   ___  
//    /\   | |                        | |        /_ |__ \ / _ \ / _ \ 
//   /  \  | | _____  ____ _ _ __   __| | ___ _ __| |  ) | | | | (_) |
//  / /\ \ | |/ _ \ \/ / _` | '_ \ / _` |/ _ \ '__| | / /| | | |> _ < 
// / ____ \| |  __/>  < (_| | | | | (_| |  __/ |  | |/ /_| |_| | (_) |
///_/    \_\_|\___/_/\_\__,_|_| |_|\__,_|\___|_|  |_|____|\___/ \___/ 

#pragma once
#include "stdafx.h"

class UserInterface
{
public:
	void SetStyle();
	void Render();

	bool rage;
	bool legit;
	bool visuals;
	bool misc;
	bool skins;
	bool colors;
	int MenuTab;
	int RageSubTab;
	int VisSubTab;
	int LegitSubTab;
	int curLil;
	int curR;
	int curG;
	int curB;

	static UserInterface* GetInstance();

private:
	void TextColor(bool active);
	void BtnNormal();
	void BtnActive();
	UserInterface();
	~UserInterface();

	static UserInterface* m_pInstance;
};