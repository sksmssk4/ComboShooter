// include the basic windows header files and the Direct3D header file
#include <windows.h>
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

#define ENEMY_NUM 10 

// include the Direct3D Library file
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

using namespace std;

// global declarations
LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
LPD3DXSPRITE d3dspt;    // the pointer to our Direct3D Sprite interface



						// sprite declarations
LPDIRECT3DTEXTURE9 sprite;    // the pointer to the sprite
LPDIRECT3DTEXTURE9 sprite_hero;    // the pointer to the sprite
LPDIRECT3DTEXTURE9 sprite_enemy;    // the pointer to the sprite
LPDIRECT3DTEXTURE9 sprite_bullet;    // the pointer to the sprite



									 // function prototypes
void initD3D(HWND hWnd);    // sets up and initializes Direct3D
void render_frame(void);    // renders a single frame
void cleanD3D(void);		// closes Direct3D and releases memory

void init_game(void);
void do_game_logic(void);
bool sphere_collision_check(float x0, float y0, float size0, float x1, float y1, float size1);


// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


enum { MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT };





bool sphere_collision_check(float x0, float y0, float size0, float x1, float y1, float size1)
{

	if ((x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1) < (size0 + size1) * (size0 + size1))
		return true;
	else
		return false;

}


//��ü ���� 
Hero hero;
Enemy enemy[ENEMY_NUM];
Bullet bullet;



// the entry point for any Windows program
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = L"WindowClass";

	RegisterClassEx(&wc);

	hWnd = CreateWindowEx(NULL, L"WindowClass", L"Genocide",
		WS_EX_DLGMODALFRAME | WS_BORDER, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, //TOPMOST->DLGMODALFRAME, POPUP -> BORDER
		NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	// set up and initialize Direct3D
	initD3D(hWnd);


	//���� ������Ʈ �ʱ�ȭ 
	init_game();

	// enter the main loop:

	MSG msg;

	while (TRUE)
	{
		DWORD starting_point = GetTickCount();

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		do_game_logic();

		render_frame();

		// check the 'escape' key
		if (KEY_DOWN(VK_ESCAPE))
			PostMessage(hWnd, WM_DESTROY, 0, 0);




		while ((GetTickCount() - starting_point) < 25);
	}

	// clean up DirectX and COM
	cleanD3D();

	return msg.wParam;
}


// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	} break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}


// this function initializes and prepares Direct3D for use
void initD3D(HWND hWnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE; //â���
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;


	// create a device class using this information and the info from the d3dpp stuct
	d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddev);

	D3DXCreateSprite(d3ddev, &d3dspt);    // create the Direct3D Sprite object

	D3DXCreateTextureFromFileEx(d3ddev,    // the device pointer
		L"Panel3.png",    // the file name
		D3DX_DEFAULT,    // default width
		D3DX_DEFAULT,    // default height
		D3DX_DEFAULT,    // no mip mapping
		NULL,    // regular usage
		D3DFMT_A8R8G8B8,    // 32-bit pixels with alpha
		D3DPOOL_MANAGED,    // typical memory handling
		D3DX_DEFAULT,    // no filtering
		D3DX_DEFAULT,    // no mip filtering
		D3DCOLOR_XRGB(255, 0, 255),    // the hot-pink color key
		NULL,    // no image info struct
		NULL,    // not using 256 colors
		&sprite);    // load to sprite


	D3DXCreateTextureFromFileEx(d3ddev,    // the device pointer
		L"hero.png",    // the file name
		D3DX_DEFAULT,    // default width
		D3DX_DEFAULT,    // default height
		D3DX_DEFAULT,    // no mip mapping
		NULL,    // regular usage
		D3DFMT_A8R8G8B8,    // 32-bit pixels with alpha
		D3DPOOL_MANAGED,    // typical memory handling
		D3DX_DEFAULT,    // no filtering
		D3DX_DEFAULT,    // no mip filtering
		D3DCOLOR_XRGB(255, 0, 255),    // the hot-pink color key
		NULL,    // no image info struct
		NULL,    // not using 256 colors
		&sprite_hero);    // load to sprite

	D3DXCreateTextureFromFileEx(d3ddev,    // the device pointer
		L"enemy.png",    // the file name
		D3DX_DEFAULT,    // default width
		D3DX_DEFAULT,    // default height
		D3DX_DEFAULT,    // no mip mapping
		NULL,    // regular usage
		D3DFMT_A8R8G8B8,    // 32-bit pixels with alpha
		D3DPOOL_MANAGED,    // typical memory handling
		D3DX_DEFAULT,    // no filtering
		D3DX_DEFAULT,    // no mip filtering
		D3DCOLOR_XRGB(255, 0, 255),    // the hot-pink color key
		NULL,    // no image info struct
		NULL,    // not using 256 colors
		&sprite_enemy);    // load to sprite


	D3DXCreateTextureFromFileEx(d3ddev,    // the device pointer
		L"bullet.png",    // the file name
		D3DX_DEFAULT,    // default width
		D3DX_DEFAULT,    // default height
		D3DX_DEFAULT,    // no mip mapping
		NULL,    // regular usage
		D3DFMT_A8R8G8B8,    // 32-bit pixels with alpha
		D3DPOOL_MANAGED,    // typical memory handling
		D3DX_DEFAULT,    // no filtering
		D3DX_DEFAULT,    // no mip filtering
		D3DCOLOR_XRGB(255, 0, 255),    // the hot-pink color key
		NULL,    // no image info struct
		NULL,    // not using 256 colors
		&sprite_bullet);    // load to sprite

	return;
}

void init_game(void)
{
	//��ü �ʱ�ȭ 
	hero.init(150, 300);

	//���� �ʱ�ȭ 
	for (int i = 0; i<ENEMY_NUM; i++)
	{

		enemy[i].init((float)(rand() % 300), rand() % 900);
	}

	//�Ѿ� �ʱ�ȭ 
	bullet.init(hero.x_pos, hero.y_pos);

}


void do_game_logic(void)
{

	//���ΰ� ó�� 
	if (KEY_DOWN(0x57))
		hero.move(MOVE_UP);

	if (KEY_DOWN(0x53))
		hero.move(MOVE_DOWN);

	if (KEY_DOWN(0x41))
		hero.move(MOVE_LEFT);

	if (KEY_DOWN(0x44))
		hero.move(MOVE_RIGHT);


	//���� ó�� 
	for (int i = 0; i<ENEMY_NUM; i++)
	{
		if (enemy[i].y_pos < 0)
			enemy[i].init((float)(rand() % 300), rand() % 900);
		else
			enemy[i].move();
	}


	//�Ѿ� ó�� 
	if (bullet.show() == false)
	{
		if (KEY_DOWN(VK_LBUTTON))
		{
			bullet.active();
			bullet.init(hero.x_pos, hero.y_pos);
		}


	}


	if (bullet.show() == true)
	{
		if (bullet.x_pos > SCREEN_WIDTH)
			bullet.hide();
		else
			bullet.move();


		//�浹 ó�� 
		for (int i = 0; i<ENEMY_NUM; i++)
		{
			if (bullet.check_collision(enemy[i].x_pos, enemy[i].y_pos) == true)
			{
				enemy[i].init((float)(rand() % 300), rand() % 900);

			}
		}



	}



}

// this is the function used to render a single frame
void render_frame(void)
{
	// clear the window to a deep blue
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	d3ddev->BeginScene();    // begins the 3D scene

	d3dspt->Begin(D3DXSPRITE_ALPHABLEND);    // // begin sprite drawing with transparency

											 //UI â ������ 


											 /*
											 static int frame = 21;    // start the program on the final frame
											 if(KEY_DOWN(VK_SPACE)) frame=0;     // when the space key is pressed, start at frame 0
											 if(frame < 21) frame++;     // if we aren't on the last frame, go to the next frame

											 // calculate the x-position
											 int xpos = frame * 182 + 1;

											 RECT part;
											 SetRect(&part, xpos, 0, xpos + 181, 128);
											 D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
											 D3DXVECTOR3 position(150.0f, 50.0f, 0.0f);    // position at 50, 50 with no depth
											 d3dspt->Draw(sprite, &part, &center, &position, D3DCOLOR_ARGB(127, 255, 255, 255));
											 */

											 //���ΰ� 
	RECT part;
	SetRect(&part, 0, 0, 64, 64);
	D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	D3DXVECTOR3 position(hero.x_pos, hero.y_pos, 0.0f);    // position at 50, 50 with no depth
	d3dspt->Draw(sprite_hero, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));

	////�Ѿ� 
	if (bullet.bShow == true)
	{
		RECT part1;
		SetRect(&part1, 0, 0, 64, 64);
		D3DXVECTOR3 center1(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
		D3DXVECTOR3 position1(bullet.x_pos, bullet.y_pos, 0.0f);    // position at 50, 50 with no depth
		d3dspt->Draw(sprite_bullet, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
	}


	////���׹� 
	RECT part2;
	SetRect(&part2, 0, 0, 64, 64);
	D3DXVECTOR3 center2(0.0f, 0.0f, 0.0f);    // center at the upper-left corner

	for (int i = 0; i<ENEMY_NUM; i++)
	{

		D3DXVECTOR3 position2(enemy[i].x_pos, enemy[i].y_pos, 0.0f);    // position at 50, 50 with no depth
		d3dspt->Draw(sprite_enemy, &part2, &center2, &position2, D3DCOLOR_ARGB(255, 255, 255, 255));
	}



	d3dspt->End();    // end sprite drawing

	d3ddev->EndScene();    // ends the 3D scene

	d3ddev->Present(NULL, NULL, NULL, NULL);

	return;
}
// this is the function that cleans up Direct3D and COM
// this is the function that cleans up Direct3D and COM
// this is the function that cleans up Direct3D and COM
void cleanD3D(void)
{
	sprite->Release();
	d3ddev->Release();
	d3d->Release();

	//��ü ���� 
	sprite_hero->Release();
	sprite_enemy->Release();
	sprite_bullet->Release();

	return;
}
