#ifndef GAME_H
#define GAME_H

#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>

#include "Entity.h"
#include "Hero.h"
#include "Enemy.h"
#include "Bullet.h"
// define the screen resolution and keyboard macros
#define SCREEN_WIDTH  960
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
	LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
	LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
	LPD3DXSPRITE d3dspt;    // the pointer to our Direct3D Sprite interface

							// sprite declarations
	LPDIRECT3DTEXTURE9 sprite;    // the pointer to the sprite
	LPDIRECT3DTEXTURE9 sprite_hero;    // the pointer to the sprite
	LPDIRECT3DTEXTURE9 sprite_enemy;    // the pointer to the sprite
	LPDIRECT3DTEXTURE9 sprite_bullet;    // the pointer to the sprite

	Hero hero;
	Enemy enemy;
	Bullet bullet;
	
public:
	void initD3D(HWND hWnd);    // sets up and initializes Direct3D
	void render_frame(void);    // renders a single frame
	void cleanD3D(void);		// closes Direct3D and releases memory

	void init_game(void);
	void do_game_logic(void);
};


#endif GAME_H