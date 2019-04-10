#ifndef GAME_H
#define GAME_H

#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "Timer.h"
#include "Remainbullet.h"
#include "Score.h"
#include "Sound.h"
#include "SummonItem.h"
#include "SummonItem2.h"
#include "Entity.h"
#include "Pistol.h"
#include "Bottle.h"
#include "Bullet.h"
#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)


// include the Direct3D Library file
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

using namespace std;

// global declarations

class Game
{
private:

	LPDIRECT3D9 d3d;    // LP_3D
	LPDIRECT3DDEVICE9 d3ddev;    // LP_3DDEVICE
	LPD3DXSPRITE d3dspt;    // LP_SPRITE
	LPD3DXSPRITE espt;

	LPDIRECT3DTEXTURE9 sprite_ending;

	LPDIRECT3DTEXTURE9 sprite_dz;
	LPDIRECT3DTEXTURE9 sprite_dz2;

	LPDIRECT3DTEXTURE9 sprite_bg; //LP_TEXTURE
	LPDIRECT3DTEXTURE9 sprite_score0;
	LPDIRECT3DTEXTURE9 sprite_score1;
	LPDIRECT3DTEXTURE9 sprite_score2;
	LPDIRECT3DTEXTURE9 sprite_score3;
	LPDIRECT3DTEXTURE9 sprite_score4;
	LPDIRECT3DTEXTURE9 sprite_score5;
	LPDIRECT3DTEXTURE9 sprite_score6;
	LPDIRECT3DTEXTURE9 sprite_score7;
	LPDIRECT3DTEXTURE9 sprite_score8;
	LPDIRECT3DTEXTURE9 sprite_score9;

	LPDIRECT3DTEXTURE9 sprite;
	
	LPDIRECT3DTEXTURE9 sprite_pistol;   
	LPDIRECT3DTEXTURE9 sprite_pistol2;	//pistol animation 
	LPDIRECT3DTEXTURE9 sprite_bottle;
	LPDIRECT3DTEXTURE9 sprite_bBreak;	//bottle breaking animation
	LPDIRECT3DTEXTURE9 sprite_bBreak2;
	LPDIRECT3DTEXTURE9 sprite_bBreak3;
	LPDIRECT3DTEXTURE9 sprite_bBreak4;

	LPDIRECT3DTEXTURE9 sprite_effect1; //effect animation
	LPDIRECT3DTEXTURE9 sprite_effect2;
	LPDIRECT3DTEXTURE9 sprite_effect3;
	LPDIRECT3DTEXTURE9 sprite_effect4;

	LPDIRECT3DTEXTURE9 sprite_line; //√—æÀ∞πºˆ∆«

	LPDIRECT3DTEXTURE9 sprite_itemG; //æ∆¿Ã≈€
	LPDIRECT3DTEXTURE9 sprite_itemP;
	LPDIRECT3DTEXTURE9 sprite_itemM;

	LPDIRECT3DTEXTURE9 sprite_bullet;    

	UINT iTime;
	FLOAT angle;

	Timer timer;
	Pistol pistol;
	Bottle bottle[BOTTLE_NUM];
	Bullet bullet;
	Sound sound;
	SummonItem summonitem;
	SummonItem2 summonitem2;
	Score score;
	Remainbullet remainbullet;
	HWND hWnd;
	int dNum = 9;
	bool effecting = false;
	bool ingame = true;
	bool ending = false;
	

public:
	
	void initD3D(HWND hWnd);    // sets up and initializes Direct3D
	void render_frame(void);    // renders a single frame
	void cleanD3D(void);		// closes Direct3D and releases memory

	void init_game(void);
	void do_game_logic(void);
	
};


#endif GAME_H