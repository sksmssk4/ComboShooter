#include "Game.h"

enum { MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT };


void Game::initD3D(HWND hWnd)
{

	d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE; //창모드
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
		L"bg.png",    // the file name
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
		&sprite_bg);    // load to sprite

	D3DXCreateTextureFromFileEx(d3ddev,
		L"score0.png",
		25,
		40,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_score0);

	D3DXCreateTextureFromFileEx(d3ddev,
		L"score1.png",
		25,
		40,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_score1);

	D3DXCreateTextureFromFileEx(d3ddev,
		L"score2.png",
		25,
		40,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_score2);

	D3DXCreateTextureFromFileEx(d3ddev,
		L"score3.png",
		25,
		40,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_score3);

	D3DXCreateTextureFromFileEx(d3ddev,
		L"score4.png",
		25,
		40,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_score4);

	D3DXCreateTextureFromFileEx(d3ddev,
		L"score5.png",
		25,
		40,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_score5);

	D3DXCreateTextureFromFileEx(d3ddev,
		L"score6.png",
		25,
		40,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_score6);

	D3DXCreateTextureFromFileEx(d3ddev,
		L"score7.png",
		25,
		40,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_score7);

	D3DXCreateTextureFromFileEx(d3ddev,
		L"score8.png",
		25,
		40,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_score8);

	D3DXCreateTextureFromFileEx(d3ddev,
		L"score9.png",
		25,
		40,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_score9);

	D3DXCreateTextureFromFileEx(d3ddev,   
		L"hero.png", 
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		NULL,   
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,   
		D3DX_DEFAULT,   
		D3DCOLOR_XRGB(255, 0, 255), 
		NULL,  
		NULL,  
		&sprite_hero);   

	D3DXCreateTextureFromFileEx(d3ddev,   
		L"enemy.png",    
		D3DX_DEFAULT,    
		D3DX_DEFAULT,    
		D3DX_DEFAULT,    
		NULL,    
		D3DFMT_A8R8G8B8, 
		D3DPOOL_MANAGED, 
		D3DX_DEFAULT,    
		D3DX_DEFAULT,    
		D3DCOLOR_XRGB(255, 0, 255),   
		NULL,   
		NULL,   
		&sprite_enemy);  


	D3DXCreateTextureFromFileEx(d3ddev,   
		L"bullet.png",  
		D3DX_DEFAULT,   
		D3DX_DEFAULT,   
		D3DX_DEFAULT,   
		NULL,   
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,   
		D3DX_DEFAULT,   
		D3DCOLOR_XRGB(255, 0, 255),   
		NULL,    
		NULL,    
		&sprite_bullet);   

	return;
}
void Game::render_frame(void)
{

	// clear the window to a deep blue
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), -1.0f, 0);

	d3ddev->BeginScene();    // begins the 3D scene

	d3dspt->Begin(D3DXSPRITE_ALPHABLEND);    // // begin sprite drawing with transparency
	//배경
	RECT part0;
	SetRect(&part0, 0, 0, 960, 640);
	D3DXVECTOR3 center0(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 position0(0.0f, 0.0f, 0.0f);
	d3dspt->Draw(sprite_bg, &part0, &center0, &position0, D3DCOLOR_ARGB(255, 255, 255, 255));
	//1의자리
	RECT Spart0;
	SetRect(&Spart0, 0, 0, 25, 40);
	D3DXVECTOR3 Scenter0(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Sposition0(900, 100, 0.0f);
	switch (score)
	{
	case 0:
		d3dspt->Draw(sprite_score0, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 1:
		d3dspt->Draw(sprite_score1, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 2:
		d3dspt->Draw(sprite_score2, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 3:
		d3dspt->Draw(sprite_score3, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 4:
		d3dspt->Draw(sprite_score4, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 5:
		d3dspt->Draw(sprite_score5, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 6:
		d3dspt->Draw(sprite_score6, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 7:
		d3dspt->Draw(sprite_score7, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 8:
		d3dspt->Draw(sprite_score8, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 9:
		d3dspt->Draw(sprite_score9, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	}
	//주인공 
	RECT part;
	SetRect(&part, 0, 0, 64, 64);
	D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);    // center at the upper-left corner
	D3DXVECTOR3 position(hero.x_pos, hero.y_pos, 0.0f);    // position at 50, 50 with no depth
	d3dspt->Draw(sprite_hero, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));

	////총알 
	if (bullet.bShow == true)
	{
		RECT part1;
		SetRect(&part1, 0, 0, 64, 64);
		D3DXVECTOR3 center1(0.0f, 0.0f, 0.0f);   
		D3DXVECTOR3 position1(bullet.x_pos, bullet.y_pos, 0.0f);   
		d3dspt->Draw(sprite_bullet, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
	}


	////에네미 
	RECT part2;
	SetRect(&part2, 0, 0, 64, 64);
	D3DXVECTOR3 center2(0.0f, 0.0f, 0.0f);  
	D3DXVECTOR3 position2(enemy.x_pos, enemy.y_pos, 0.0f);   
	d3dspt->Draw(sprite_enemy, &part2, &center2, &position2, D3DCOLOR_ARGB(255, 255, 255, 255));




	d3dspt->End();    // end sprite drawing

	d3ddev->EndScene();    // ends the 3D scene

	d3ddev->Present(NULL, NULL, NULL, NULL);

	return;
}

void Game::init_game(void)
{

	//객체 초기화 
	hero.init(150, 300);

	//적들 초기화
	enemy.init((float)(200 + rand() % 600), 650);


	//총알 초기화 
	bullet.init(hero.x_pos, hero.y_pos);
}
void Game::do_game_logic(void)
{

	//주인공 처리 
	if (KEY_DOWN(0x57))
		hero.move(MOVE_UP);


	if (KEY_DOWN(0x53))
		hero.move(MOVE_DOWN);

	if (KEY_DOWN(0x41))
		hero.move(MOVE_LEFT);

	if (KEY_DOWN(0x44))
		hero.move(MOVE_RIGHT);


	//적들 처리 
	enemy.Update(1.0);
	enemy.Jump();


	//총알 처리 
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


		//충돌 처리 
		if (bullet.check_collision(enemy.x_pos, enemy.y_pos) == true)
		{
			enemy.init((float)(200 + rand() % 300), 650);
			score++;
		}
	}
}

void Game::cleanD3D(void)
{
	sprite->Release();
	d3ddev->Release();
	d3d->Release();

	//객체 해제 
	sprite_hero->Release();
	sprite_enemy->Release();
	sprite_bullet->Release();

	return;
}
