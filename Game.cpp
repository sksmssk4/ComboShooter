#include "Game.h"
POINT pt; //마우스 포인트

enum { MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT };


bool sphere_collision_check(float x0, float y0, float size0, float x1, float y1, float size1);

bool sphere_collision_check(float x0, float y0, float size0, float x1, float y1, float size1)
{
	if ((x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1) < (size0 + size1) * (size0 + size1))
		return true;
	else
		return false;
}


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
	D3DXCreateSprite(d3ddev, &espt);
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
		L"pistol.png", 
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
		&sprite_pistol);   
	
	D3DXCreateTextureFromFileEx(d3ddev,
		L"pistol2.png",	
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
		&sprite_pistol2);	//pistol animation

	D3DXCreateTextureFromFileEx(d3ddev,   
		L"bottle.png",    
		64,    
		64,    
		D3DX_DEFAULT,    
		NULL,    
		D3DFMT_A8R8G8B8, 
		D3DPOOL_MANAGED, 
		D3DX_DEFAULT,    
		D3DX_DEFAULT,    
		D3DCOLOR_XRGB(255, 0, 255),   
		NULL,   
		NULL,   
		&sprite_bottle);  

	D3DXCreateTextureFromFileEx(d3ddev,
		L"bBreak.png",
		64,
		64,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_bBreak);	//bottle breaking animation

	D3DXCreateTextureFromFileEx(d3ddev,
		L"bBreak2.png",
		64,
		64,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_bBreak2);	//bottle breaking animation

	D3DXCreateTextureFromFileEx(d3ddev,
		L"bBreak3.png",
		64,
		64,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_bBreak3);	//bottle breaking animation

	D3DXCreateTextureFromFileEx(d3ddev,
		L"bBreak4.png",
		64,
		64,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_bBreak4);	//bottle breaking animation

	//이펙트 애니메이션
	D3DXCreateTextureFromFileEx(d3ddev,
		L"effect1.png",
		150,
		150,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_effect1);

	D3DXCreateTextureFromFileEx(d3ddev,
		L"effect2.png",
		150,
		150,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_effect2);

	D3DXCreateTextureFromFileEx(d3ddev,
		L"effect3.png",
		150,
		150,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_effect3);

	D3DXCreateTextureFromFileEx(d3ddev,
		L"effect4.png",
		150,
		150,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_effect4);

	//총알갯수판
	D3DXCreateTextureFromFileEx(d3ddev,
		L"line.png",
		80,
		50,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_line);

	//총 아이템 
	D3DXCreateTextureFromFileEx(d3ddev,
		L"itemG.png",
		64,
		64,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_itemG);
	//증가 아이템
	D3DXCreateTextureFromFileEx(d3ddev,
		L"itemP.png",
		64,
		64,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_itemP);
	//감소 아이템
	D3DXCreateTextureFromFileEx(d3ddev,
		L"itemM.png",
		64,
		64,
		D3DX_DEFAULT,
		NULL,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		NULL,
		NULL,
		&sprite_itemM);

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
	//마우스 좌표얻기
	GetCursorPos(&pt);
	//윈도우화면 마우스 좌표
	ScreenToClient(hWnd, &pt);

	// clear the window to a deep blue
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), -1.0f, 0);

	d3ddev->BeginScene();   
	espt->Begin(D3DXSPRITE_ALPHABLEND);
	d3dspt->Begin(D3DXSPRITE_ALPHABLEND);
	
	//배경
	RECT part0;
	SetRect(&part0, 0, 0, 960, 490);
	D3DXVECTOR3 center0(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 position0(0.0f, 150.0f, 0.0f);
	d3dspt->Draw(sprite_bg, &part0, &center0, &position0, D3DCOLOR_ARGB(255, 255, 255, 255));
	//기본
	RECT Spart;
	SetRect(&Spart, 0, 0, 25, 40);
	D3DXVECTOR3 Scenter(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Sposition(score.x_pos+25, score.y_pos, 0.0f);
	d3dspt->Draw(sprite_score0, &Spart, &Scenter, &Sposition, D3DCOLOR_ARGB(255, 255, 255, 255));
	//1의자리
	RECT Spart0;
	SetRect(&Spart0, 0, 0, 25, 40);
	D3DXVECTOR3 Scenter0(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Sposition0(score.x_pos, score.y_pos, 0.0f);
	//10의 자리
	RECT Spart10;
	SetRect(&Spart10, 0, 0, 25, 40);
	D3DXVECTOR3 Scenter10(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Sposition10(score.x_pos-25, score.y_pos, 0.0f);
	//총알갯수판
	RECT Bpart0;
	SetRect(&Bpart0, 0, 0, 80, 50);
	D3DXVECTOR3 Bcenter0(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Bposition0(410, 520, 0.0f);
	d3dspt->Draw(sprite_line, &Bpart0, &Bcenter0, &Bposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
	//총알 갯수
	RECT Bpart;
	SetRect(&Bpart, 0, 0, 25, 40);
	D3DXVECTOR3 Bcenter(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Bposition(415, 525, 0.0f);

	RECT Bpart1;
	SetRect(&Bpart1, 0, 0, 25, 40);
	D3DXVECTOR3 Bcenter1(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 Bposition1(455, 525, 0.0f);
	d3dspt->Draw(sprite_score5, &Bpart1, &Bcenter1, &Bposition1, D3DCOLOR_ARGB(255, 255, 255, 255));
	//switch (remainbullet.GetCounter())
	//{
	//case 0:
	//	d3dspt->Draw(sprite_score0, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
	//	break;
	//case 2:
	//	d3dspt->Draw(sprite_score1, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
	//	break;
	//case 4:
	//	d3dspt->Draw(sprite_score2, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
	//	break;
	//case 6:
	//	d3dspt->Draw(sprite_score3, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
	//	break;
	//case 8:
	//	d3dspt->Draw(sprite_score4, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
	//	break;
	//case 10:
	//	d3dspt->Draw(sprite_score5, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
	//	break;
	//}
	if (remainbullet.GetCounter() == 0)
	{
		d3dspt->Draw(sprite_score0, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	else if (remainbullet.GetCounter() > 0 && remainbullet.GetCounter() <= 2)
	{
		d3dspt->Draw(sprite_score1, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	else if (remainbullet.GetCounter() > 2 && remainbullet.GetCounter() <= 4)
	{
		d3dspt->Draw(sprite_score2, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	else if (remainbullet.GetCounter() > 4 && remainbullet.GetCounter() <= 6)
	{
		d3dspt->Draw(sprite_score3, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	else if (remainbullet.GetCounter() > 6 && remainbullet.GetCounter() <= 8)
	{
		d3dspt->Draw(sprite_score4, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	else if (remainbullet.GetCounter() > 8 && remainbullet.GetCounter() <= 10)
	{
		d3dspt->Draw(sprite_score5, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	
	switch (score.GetNum())
	{
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
	case 10:
		d3dspt->Draw(sprite_score0, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score1, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 11:
		d3dspt->Draw(sprite_score1, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score1, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 12:
		d3dspt->Draw(sprite_score2, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score1, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 13:
		d3dspt->Draw(sprite_score3, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score1, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 14:
		d3dspt->Draw(sprite_score4, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score1, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 15:
		d3dspt->Draw(sprite_score5, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score1, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 16:
		d3dspt->Draw(sprite_score6, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score1, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 17:
		d3dspt->Draw(sprite_score7, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score1, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 18:
		d3dspt->Draw(sprite_score8, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score1, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 19:
		d3dspt->Draw(sprite_score9, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score1, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 20:
		d3dspt->Draw(sprite_score0, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score2, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 21:
		d3dspt->Draw(sprite_score1, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score2, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 22:
		d3dspt->Draw(sprite_score2, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score2, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 23:
		d3dspt->Draw(sprite_score3, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score2, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 24:
		d3dspt->Draw(sprite_score4, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score2, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 25:
		d3dspt->Draw(sprite_score5, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score2, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 26:
		d3dspt->Draw(sprite_score6, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score2, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 27:
		d3dspt->Draw(sprite_score7, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score2, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 28:
		d3dspt->Draw(sprite_score8, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score2, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 29:
		d3dspt->Draw(sprite_score9, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score2, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 30:
		d3dspt->Draw(sprite_score0, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score3, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 31:
		d3dspt->Draw(sprite_score1, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score3, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 32:
		d3dspt->Draw(sprite_score2, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score3, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 33:
		d3dspt->Draw(sprite_score3, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score3, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 34:
		d3dspt->Draw(sprite_score4, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score3, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 35:
		d3dspt->Draw(sprite_score5, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score3, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 36:
		d3dspt->Draw(sprite_score6, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score3, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 37:
		d3dspt->Draw(sprite_score7, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score3, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 38:
		d3dspt->Draw(sprite_score8, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score3, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 39:
		d3dspt->Draw(sprite_score9, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score3, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 40:
		d3dspt->Draw(sprite_score0, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score4, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 41:
		d3dspt->Draw(sprite_score1, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score4, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 42:
		d3dspt->Draw(sprite_score2, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score4, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 43:
		d3dspt->Draw(sprite_score3, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score4, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 44:
		d3dspt->Draw(sprite_score4, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score4, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 45:
		d3dspt->Draw(sprite_score5, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score4, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 46:
		d3dspt->Draw(sprite_score6, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score4, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 47:
		d3dspt->Draw(sprite_score7, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score4, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 48:
		d3dspt->Draw(sprite_score8, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score4, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 49:
		d3dspt->Draw(sprite_score9, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score4, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 50:
		d3dspt->Draw(sprite_score0, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score5, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 51:
		d3dspt->Draw(sprite_score1, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score5, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 52:
		d3dspt->Draw(sprite_score2, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score5, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case 53:
		d3dspt->Draw(sprite_score3, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		d3dspt->Draw(sprite_score5, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	}

	//이펙트 애니메이션
	if (effecting == true)
	{
		RECT Epart;
		SetRect(&Epart, 0, 0, 150, 150);
		D3DXVECTOR3 Ecenter(0.0f, 0.0f, 0.0f);
		D3DXVECTOR3 Eposition(pt.x-60, pt.y-75, 0.0f);
		static int ecounter = 0;
		ecounter++;
		if (ecounter >= 4)
		{
			ecounter = 0;
			effecting = false;
		}
		switch (ecounter)
		{
		case 0:
			d3dspt->Draw(sprite_effect1, &Epart, &Ecenter, &Eposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 1:
			d3dspt->Draw(sprite_effect2, &Epart, &Ecenter, &Eposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 2:
			d3dspt->Draw(sprite_effect3, &Epart, &Ecenter, &Eposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 3:
			d3dspt->Draw(sprite_effect4, &Epart, &Ecenter, &Eposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		}
	}
	if (pistol.pCheck == true)
	{
		//Pistol
		if (pistol.pShow == true)
		{
			RECT part;
			SetRect(&part, 0, 0, 100, 63);
			D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);
			D3DXVECTOR3 position(pistol.x_pos, pistol.y_pos, 0.0f);
			d3dspt->Draw(sprite_pistol, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		//Pistol Fire!
		if (pistol.pShow == false)
		{
			RECT part;
			SetRect(&part, 0, 0, 115, 63);
			D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);
			D3DXVECTOR3 position(pistol.x_pos, pistol.y_pos, 0.0f);
			d3dspt->Draw(sprite_pistol2, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
			pistol.pShow = true;
		}
		////bullet
		if (bullet.bShow == true)
		{
			RECT part1;
			SetRect(&part1, 0, 0, 30, 14);
			D3DXVECTOR3 center1(0.0f, 0.0f, 0.0f);
			D3DXVECTOR3 position1(bullet.x_pos, bullet.y_pos, 0.0f);
			d3dspt->Draw(sprite_bullet, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
	}
	////Item
	if (summonitem.Appear == true)
	{
		RECT rc;
		SetRect(&rc, 0, 0, 64, 64);

		D3DXVECTOR2 spriteCenter = D3DXVECTOR2(32, 32);
		// Screen position of the sprite
		D3DXVECTOR2 translate = D3DXVECTOR2(summonitem.x_pos, summonitem.y_pos);
		// Scaling X,Y

		iTime = timeGetTime() % 1000;
		angle = iTime * (2.0f * D3DX_PI) / 1000.0f;

		D3DXVECTOR2 scaling(1, 1);
		D3DXMATRIX matrix;

		D3DXMatrixTransformation2D(
			&matrix,                // 행렬
			NULL,                   // 크기를 조정할 때 기준을 왼쪽 상단으로 유지
			0.0f,                   // 크기 조정 회전 없음
			&scaling,               // 크기 조정 값
			&spriteCenter,          // 회전 중심
			(float)(angle),			// 회전 각도
			&translate);            // X,Y위치


		espt->SetTransform(&matrix);
		// Draw the sprite
		espt->Draw(sprite_itemG, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	

	//bottle animation;
	for (int i = 0; i < BOTTLE_NUM-dNum; i++)
	{
		if (bottle[i].breaking == true)
		{
			RECT part1;
			SetRect(&part1, 0, 0, 64*(bottle[i].scale), 64 * (bottle[i].scale));
			D3DXVECTOR3 center1(0.0f,0.0f, 0.0f);
			D3DXVECTOR3 position1(pt.x, pt.y, 0.0f); //애니메이션 좌표 = 마우스좌표

			static int acounter = 0;
			acounter++;
			if (acounter >= 4)
			{
				acounter = 0;
				bottle[i].breaking = false;
			}
			switch (acounter)
			{
			case 0:
				d3dspt->Draw(sprite_bBreak, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				d3dspt->Draw(sprite_bBreak2, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 2:
				d3dspt->Draw(sprite_bBreak3, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 3:
				d3dspt->Draw(sprite_bBreak4, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}

		}
		////bottle	
		RECT rc;
		SetRect(&rc, 0, 0, 64*(bottle[i].scale), 64 * (bottle[i].scale));

		D3DXVECTOR2 spriteCenter = D3DXVECTOR2(32 * (bottle[i].scale) / bottle[i].scale* (bottle[i].scale), 32 * (bottle[i].scale) / bottle[i].scale* (bottle[i].scale));
		// Screen position of the sprite
		D3DXVECTOR2 translate = D3DXVECTOR2(bottle[i].x_pos, bottle[i].y_pos);
		// Scaling X,Y

		iTime = timeGetTime() % 1000;
		angle = iTime * (2.0f * D3DX_PI) / 1000.0f;

		D3DXVECTOR2 scaling(bottle[i].scale, bottle[i].scale);
		D3DXMATRIX matrix;

		D3DXMatrixTransformation2D(
			&matrix,                // 행렬
			NULL,                   // 크기를 조정할 때 기준을 왼쪽 상단으로 유지
			0.0f,                   // 크기 조정 회전 없음
			&scaling,               // 크기 조정 값
			&spriteCenter,          // 회전 중심
			(float)(angle),			// 회전 각도
			&translate);            // X,Y위치


		espt->SetTransform(&matrix);
		// Draw the sprite
		espt->Draw(sprite_bottle, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	d3dspt->End();    
	espt->End();
	d3ddev->EndScene();

	d3ddev->Present(NULL, NULL, NULL, NULL);

	return;
}

void Game::init_game(void)
{
	//스코어 초기화
	score.init(900, 100);
	pistol.init(80, 60);
	for (int i = 0; i < BOTTLE_NUM-dNum; i++)
	{
		//오브젝트 초기화
		bottle[i].init((float)(200 + rand() % 600), 650);
	}
	//총알 초기화 
	bullet.init(pistol.x_pos, pistol.y_pos);

	summonitem.init(600, 750);
}
void Game::do_game_logic(void)
{
	//배경음악 켜기
	sound.Bgm();
	//점수에 따른 오브젝트 갯수변화
	if (score.GetNum() == 3)
		dNum = 8;
	else if (score.GetNum() == 5)
		dNum = 7;
	else if (score.GetNum() == 10)
		dNum = 6;
	else if (score.GetNum() == 15)
		dNum = 5;
	else if (score.GetNum() == 20)
		dNum = 4;
	else if (score.GetNum() == 25)
		dNum = 3;
	else if (score.GetNum() == 30)
		dNum = 2;
	else if (score.GetNum() == 35)
		dNum = 1;

	//총알 개수 0일 때
	if (remainbullet.GetCounter() == 0)
	{
		if (KEY_DOWN(VK_LBUTTON))
		{
			sound.Gird();
		}
	}
	if (KEY_DOWN(VK_SPACE))
	{
		sound.Reload();
		remainbullet.SetCounter(10);
	}
	//총아이템 처리
	if (score.GetNum() >= 5)
	{
		summonitem.Appear = true;
	}
	else if (score.GetNum() >= 15 && summonitem.Appear == false)
	{
		summonitem.Appear = true;
		summonitem.init(600, 750);
	}
	
	if (summonitem.Appear == true)
	{
		if (summonitem.x_pos < 0 || summonitem.y_pos > 755)
		{
			summonitem.Appear = false;
		}
		else
		{
			summonitem.Update(1.0);
			summonitem.Jump();
		}
	}
	
	
	
	for (int i = 0; i < BOTTLE_NUM-dNum; i++)
	{
		//오브젝트 처리
		if (bottle[i].x_pos < 0 || bottle[i].y_pos > 755)
		{
			bottle[i].init((float)(200 + rand() % 600), 750);
		}
		else
		{
			bottle[i].breaking = false;
			bottle[i].Update(1.0);
			bottle[i].Jump();
		}
	}

	//총아이템 처리
	if (pistol.pCheck == true)
	{
		pistol.move(MOVE_DOWN);
		if (bullet.show() == false)
		{
			if (KEY_UP(VK_TAB))
			{
				pistol.pShow = false;
				bullet.active();
				bullet.init(pistol.x_pos, pistol.y_pos);
			}
		}
	}
	if (pistol.y_pos >= 750)
		pistol.pCheck = false;

	//총아이템 총알 처리
	if (bullet.show() == true)
	{
		if (bullet.x_pos > SCREEN_WIDTH)
			bullet.hide();
		else
			bullet.move();
		for (int i = 0; i < BOTTLE_NUM-dNum; i++)
		{
			//충돌 처리 
			if (bullet.check_collision(bottle[i].x_pos, bottle[i].y_pos) == true)
			{
				sound.HitShot();
				bottle[i].breaking = true;
				bottle[i].init((float)(200 + rand() % 300), 750);
				
				score.SetNum(score.GetNum() + 1);
			}
		}
	}
	//마우스 좌표얻기
	GetCursorPos(&pt);
	//윈도우화면 마우스 좌표
	ScreenToClient(hWnd, &pt);

	//마우스 충돌 구현
	if (remainbullet.GetCounter() > 0)
	{
		if (KEY_DOWN(VK_LBUTTON))
		{
			remainbullet.SetCounter(remainbullet.GetCounter()-1);
			sound.Shot();
			for (int i = 0; i < BOTTLE_NUM - dNum; i++)
			{
				if (pt.x >= bottle[i].x_pos && pt.x <= bottle[i].x_pos + (64 * bottle[i].scale) && pt.y >= bottle[i].y_pos && pt.y <= bottle[i].y_pos + (64 * bottle[i].scale))
				{
					effecting = false;
					bottle[i].breaking = true;
					bottle[i].init((float)(200 + rand() % 300), 750);
					score.SetNum(score.GetNum() + 1);
				}
				else if (pt.x >= summonitem.x_pos && pt.x <= summonitem.x_pos + 64 && pt.y >= summonitem.y_pos && pt.y <= summonitem.y_pos + 64)
				{
					summonitem.Appear = false;
					summonitem.init(600, 900);
					pistol.pCheck = true;
					pistol.init(80, 60);
				}
				else
					effecting = true;
			}
		}
	}

}


void Game::cleanD3D(void)
{
	return;
}
