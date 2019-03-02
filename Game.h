#ifndef GAME_H
#define GAME_H

#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <stdlib.h>

#include <stdio.h>

#include "Entity.h"
#include "Hero.h"
#include "Enemy.h"
#include "Bullet.h"
// define the screen resolution and keyboard macros
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
	LPDIRECT3DTEXTURE9 sprite_hero;    
	LPDIRECT3DTEXTURE9 sprite_enemy;    
	LPDIRECT3DTEXTURE9 sprite_bullet;    

	Hero hero;
	Enemy enemy;
	Bullet bullet;

	int score = 0;
	
public:
	void initD3D(HWND hWnd);    // sets up and initializes Direct3D
	void render_frame(void);    // renders a single frame
	void cleanD3D(void);		// closes Direct3D and releases memory

	void init_game(void);
	void do_game_logic(void);
	
};


#endif GAME_H