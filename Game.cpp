#include "Game.h"
POINT pt; //마우스 포인트

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
	//배경
	D3DXCreateTextureFromFileEx(d3ddev, // the device pointer
		L"bg1.png",						// the file name
		960,							// default width
		720,							// default height
		D3DX_DEFAULT,					// no mip mapping
		NULL,							// regular usage
		D3DFMT_A8R8G8B8,				// 32-bit pixels with alpha
		D3DPOOL_MANAGED,				// typical memory handling
		D3DX_DEFAULT,					// no filtering
		D3DX_DEFAULT,					// no mip filtering
		D3DCOLOR_XRGB(255, 0, 255),		// the hot-pink color key
		NULL,							// no image info struct
		NULL,							// not using 256 colors
		&sprite_bg);					// load to sprite
	D3DXCreateTextureFromFileEx(d3ddev,L"bg2.png",960,720,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED, 
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_bg2);
	D3DXCreateTextureFromFileEx(d3ddev, L"backbg1.png", 960, 500, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_backbg);
	D3DXCreateTextureFromFileEx(d3ddev, L"backbg2.png", 960, 500, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_backbg2);
	D3DXCreateTextureFromFileEx(d3ddev, L"scaffolding.png", 960, 140, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_scaffolding);
	D3DXCreateTextureFromFileEx(d3ddev, L"frontbg.png", 960, 720, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(247, 0, 247), NULL, NULL, &sprite_frontbg);
	D3DXCreateTextureFromFileEx(d3ddev, L"ui.png", 960, 80, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_ui);
	D3DXCreateTextureFromFileEx(d3ddev, L"lock.png", 40, 40, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_lock);
	D3DXCreateTextureFromFileEx(d3ddev, L"combo_gage.png", 400, 38, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_combo_gage);
	//시작화면
	D3DXCreateTextureFromFileEx(d3ddev, L"start.png", 960, 720, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_opening);
	D3DXCreateTextureFromFileEx(d3ddev, L"bg_effect.png", 320, 150, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_bgEffect);
	D3DXCreateTextureFromFileEx(d3ddev, L"Play.png", 120, 80, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_play);
	D3DXCreateTextureFromFileEx(d3ddev, L"Quit.png", 120, 80, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_quit);
	//스테이지 종료
	D3DXCreateTextureFromFileEx(d3ddev,L"clear.png",D3DX_DEFAULT,D3DX_DEFAULT,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_ending);
	D3DXCreateTextureFromFileEx(d3ddev, L"gomain.png",300, 60, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_gomain);
	D3DXCreateTextureFromFileEx(d3ddev, L"nextstage.png", 300, 60, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_nextstage);
	//타이머
	D3DXCreateTextureFromFileEx(d3ddev,L"dz.png",500,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_dz);
	D3DXCreateTextureFromFileEx(d3ddev,L"dz2.png",440,22, D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_dz2);
	D3DXCreateTextureFromFileEx(d3ddev, L"bullet.png", 14, 30, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_bullet);
	//플레이어 idle 
	D3DXCreateTextureFromFileEx(d3ddev, L"lplayer_idle1.png", 240, 291, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_lplayer_idle1);
	D3DXCreateTextureFromFileEx(d3ddev, L"lplayer_idle2.png", 240, 291, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_lplayer_idle2);
	D3DXCreateTextureFromFileEx(d3ddev, L"lplayer_idle3.png", 240, 291, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_lplayer_idle3);
	D3DXCreateTextureFromFileEx(d3ddev, L"player_idle1.png", 152, 293, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_player_idle1);
	D3DXCreateTextureFromFileEx(d3ddev, L"player_idle2.png", 152, 293, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_player_idle2);
	D3DXCreateTextureFromFileEx(d3ddev, L"rplayer_idle1.png", 240, 291, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_rplayer_idle1);
	D3DXCreateTextureFromFileEx(d3ddev, L"rplayer_idle2.png", 240, 291, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_rplayer_idle2);
	D3DXCreateTextureFromFileEx(d3ddev, L"rplayer_idle3.png", 240, 291, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_rplayer_idle3);
	//플레이어 shot
	D3DXCreateTextureFromFileEx(d3ddev, L"lplayer_shot.png", 1400, 291, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_lplayer_shot);
	D3DXCreateTextureFromFileEx(d3ddev, L"player_shot.png", 750, 293, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_player_shot);
	D3DXCreateTextureFromFileEx(d3ddev, L"rplayer_shot.png", 1400, 291, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_rplayer_shot);
	//플레이어 skill
	D3DXCreateTextureFromFileEx(d3ddev, L"lplayer_skill.png", 1400, 291, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_lplayer_skill);
	D3DXCreateTextureFromFileEx(d3ddev, L"player_skill.png", 750, 293, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_player_skill);
	D3DXCreateTextureFromFileEx(d3ddev, L"rplayer_skill.png", 1400, 291, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_rplayer_skill);
	//스코어 박스
	D3DXCreateTextureFromFileEx(d3ddev, L"score_box.png", 300, 60, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_scorebox);
	//스코어
	D3DXCreateTextureFromFileEx(d3ddev,L"score0.png",25,40,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_score0);
	D3DXCreateTextureFromFileEx(d3ddev,L"score1.png",25,40,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_score1);
	D3DXCreateTextureFromFileEx(d3ddev,L"score2.png",25,40,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_score2);
	D3DXCreateTextureFromFileEx(d3ddev,L"score3.png",25,40,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_score3);
	D3DXCreateTextureFromFileEx(d3ddev,L"score4.png",25,40,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_score4);
	D3DXCreateTextureFromFileEx(d3ddev,L"score5.png",25,40,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_score5);
	D3DXCreateTextureFromFileEx(d3ddev,L"score6.png",25,40,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_score6);
	D3DXCreateTextureFromFileEx(d3ddev,L"score7.png",25,40,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_score7);
	D3DXCreateTextureFromFileEx(d3ddev,L"score8.png",25,40,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_score8);
	D3DXCreateTextureFromFileEx(d3ddev,L"score9.png",25,40,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_score9);
	//콤보
	D3DXCreateTextureFromFileEx(d3ddev, L"combo_text.png", 250, 80, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_combo_text);
	D3DXCreateTextureFromFileEx(d3ddev, L"combo0.png", 85, 120, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_combo0);
	D3DXCreateTextureFromFileEx(d3ddev, L"combo1.png", 85, 120, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_combo1);
	D3DXCreateTextureFromFileEx(d3ddev, L"combo2.png", 85, 120, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_combo2);
	D3DXCreateTextureFromFileEx(d3ddev, L"combo3.png", 85, 120, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_combo3);
	D3DXCreateTextureFromFileEx(d3ddev, L"combo4.png", 85, 120, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_combo4);
	D3DXCreateTextureFromFileEx(d3ddev, L"combo5.png", 85, 120, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_combo5);
	D3DXCreateTextureFromFileEx(d3ddev, L"combo6.png", 85, 120, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_combo6);
	D3DXCreateTextureFromFileEx(d3ddev, L"combo7.png", 85, 120, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_combo7);
	D3DXCreateTextureFromFileEx(d3ddev, L"combo8.png", 85, 120, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_combo8);
	D3DXCreateTextureFromFileEx(d3ddev, L"combo9.png", 85, 120, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_combo9);
	//////////////////////////grenade animation
	D3DXCreateTextureFromFileEx(d3ddev, L"grenade.png", 2880, 360, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_grenade);
	//////////////////////////how much grenade
	D3DXCreateTextureFromFileEx(d3ddev, L"grenade_num.png", 120, 30, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_grenade_num);
	//////////////////////////soldier animation
	D3DXCreateTextureFromFileEx(d3ddev, L"supportfire.png", 530, 100, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_support);
	D3DXCreateTextureFromFileEx(d3ddev,L"soldier1.png", 77, 200, D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_soldier1);   
	D3DXCreateTextureFromFileEx(d3ddev,L"soldier2.png",77, 200,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_soldier2);
	D3DXCreateTextureFromFileEx(d3ddev, L"soldier3.png", 77, 200, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_soldier3);
	D3DXCreateTextureFromFileEx(d3ddev, L"soldier4.png", 77, 200, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_soldier4);
	D3DXCreateTextureFromFileEx(d3ddev, L"soldier5.png", 77, 200, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_soldier5);
	//////////////////////////soldier2 animation
	D3DXCreateTextureFromFileEx(d3ddev, L"bazooka_idle.png", 600, 140, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(148, 148, 138), NULL, NULL, &sprite_soldier2_idle);
	D3DXCreateTextureFromFileEx(d3ddev, L"bazooka_fire.png", 500, 140, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_soldier2_fire);
	D3DXCreateTextureFromFileEx(d3ddev, L"bazooka.png", 40, 40, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_bazooka);
	//////////////////////////enemy1_left
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_left1.png",60 * (float)scale,86 * (float)scale,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_lenemy1);
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_left2.png",60 * (float)scale,86 * (float)scale,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_lenemy2);
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_left3.png",60 * (float)scale,86 * (float)scale,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_lenemy3);
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_left4.png",60 * (float)scale,86 * (float)scale,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_lenemy4);
	//////////////////////////enemy1_right
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_right1.png",60 * (float)scale, 86 * (float)scale,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy1); 
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_right2.png",60 * (float)scale, 86 * (float)scale,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy2);
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_right3.png",60 * (float)scale, 86 * (float)scale,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy3);
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_right4.png",60 * (float)scale, 86 * (float)scale,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy4);
	//////////////////////////enemy2_left
	D3DXCreateTextureFromFileEx(d3ddev, L"enemy2_left1.png", 60 * (float)scale, 86 * (float)scale, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_lenemy2_1);
	D3DXCreateTextureFromFileEx(d3ddev, L"enemy2_left2.png", 60 * (float)scale, 86 * (float)scale, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_lenemy2_2);
	//////////////////////////enemy2_right
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy2_right1.png",60 * (float)scale, 86 * (float)scale,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy2_1);
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy2_right2.png",60 * (float)scale, 86 * (float)scale,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy2_2);
	//////////////////////////enemy3_left
	D3DXCreateTextureFromFileEx(d3ddev, L"enemy3_left1.png", 60, 86, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_lenemy3_1);
	D3DXCreateTextureFromFileEx(d3ddev, L"enemy3_left2.png", 60, 86, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_lenemy3_2);
	//////////////////////////enemy3_right
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy3_right1.png",60,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy3_1);
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy3_right2.png",60,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy3_2);
	//////////////////////////enemy breaking animation
	D3DXCreateTextureFromFileEx(d3ddev,L"bBreak.png",150 * (float)scale,150 * (float)scale,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_bBreak);	
	D3DXCreateTextureFromFileEx(d3ddev,L"bBreak2.png",150 * (float)scale,150 * (float)scale,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_bBreak2);	
	D3DXCreateTextureFromFileEx(d3ddev,L"bBreak3.png",150 * (float)scale,150 * (float)scale,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_bBreak3);	
	D3DXCreateTextureFromFileEx(d3ddev,L"bBreak4.png",150 * (float)scale,150 * (float)scale,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_bBreak4);	
	//////////////////////////effect animation
	D3DXCreateTextureFromFileEx(d3ddev,L"effect1.png",150,150,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_effect1);
	D3DXCreateTextureFromFileEx(d3ddev,L"effect2.png",150,150,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_effect2);
	D3DXCreateTextureFromFileEx(d3ddev,L"effect3.png",150,150,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_effect3);
	D3DXCreateTextureFromFileEx(d3ddev,L"effect4.png",150,150,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_effect4);
	//////////////////////////attack animation
	D3DXCreateTextureFromFileEx(d3ddev,L"attack1.png",80,80,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_attack1);
	D3DXCreateTextureFromFileEx(d3ddev,L"attack2.png",160,160,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_attack2);
	D3DXCreateTextureFromFileEx(d3ddev,L"attack3.png",320,320,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_attack3);
	D3DXCreateTextureFromFileEx(d3ddev,L"attack4.png",960,640,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_attack4);
	D3DXCreateTextureFromFileEx(d3ddev,L"attack5.png",960,640,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_attack5);
	//////////////////////////boss animation
	D3DXCreateTextureFromFileEx(d3ddev, L"boss_idle.png", 600, 96, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_boss_idle);
	D3DXCreateTextureFromFileEx(d3ddev, L"boss_hit.png", 600, 96, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_boss_hit);
	//////////////////////////총알갯수판
	D3DXCreateTextureFromFileEx(d3ddev,L"bullet_full.png",100,40,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_bullet_full);
	D3DXCreateTextureFromFileEx(d3ddev, L"bullet_empty.png", 100, 40, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_bullet_empty);
	D3DXCreateTextureFromFileEx(d3ddev, L"infinity.png", 100, 40, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_infinity);
	//////////////////////////수류탄 아이템 
	D3DXCreateTextureFromFileEx(d3ddev,L"itemG.png",64,64,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_itemG);
	//////////////////////////증가 아이템
	D3DXCreateTextureFromFileEx(d3ddev,L"itemP.png",64,64,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_itemP);
	//////////////////////////감소 아이템
	D3DXCreateTextureFromFileEx(d3ddev,L"itemM.png",64,64,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_itemM); 
	/////////////////////////.스킬발동애니메이션
	D3DXCreateTextureFromFileEx(d3ddev,L"death_shower.png",400,400,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_deathshower1);
	D3DXCreateTextureFromFileEx(d3ddev,L"death_shower2.png",400,400,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_deathshower2);
	return;
}
void Game::render_frame(void)
{
	if (opening == true)
	{
		//마우스 좌표얻기
		GetCursorPos(&pt);
		//윈도우화면 마우스 좌표
		ScreenToClient(hWnd, &pt);
		//배경음악 켜기
		sound.startBgm();
		d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), -1.0f, 0);
		d3ddev->BeginScene();
		d3dspt->Begin(D3DXSPRITE_ALPHABLEND);
		//배경화면
		RECT part; SetRect(&part, 0, 0, 960, 720); D3DXVECTOR3 center(0.0f, 0.0f, 0.0f); D3DXVECTOR3 position(0.0f, 0.0f, 0.0f);
		d3dspt->Draw(sprite_opening, &part, &center, &position, D3DCOLOR_XRGB(255, 255, 255, 255));
		//Play,Quit
		RECT bPart; SetRect(&bPart, 0, 0, 120, 80); 
		D3DXVECTOR3 bPosition1(420.0f, 410.0f, 0.0f); D3DXVECTOR3 bPosition2(420.0f, 510.0f, 0.0f); D3DXVECTOR3 bPosition3(410.0f, 410.0f, 0.0f); D3DXVECTOR3 bPosition4(410.0f, 510.0f, 0.0f);	
		if (pt.x >= 420 && pt.x <= 540 && pt.y >= 410 && pt.y <= 490)
		{
			sound.Cursor();
			d3dspt->Draw(sprite_quit, &bPart, &center, &bPosition2, D3DCOLOR_ARGB(255, 255, 255, 255));
			d3dspt->Draw(sprite_play, &bPart, &center, &bPosition3, D3DCOLOR_ARGB(255, 255, 255, 255));
			if (KEY_DOWN(VK_LBUTTON))
			{
				sound.Decision();
				opening = false;
				ingame = true;
			}
		}

		else if (pt.x >= 420 && pt.x <= 540 && pt.y >= 510 && pt.y <= 590)
		{
			sound.Cursor();
			d3dspt->Draw(sprite_play, &bPart, &center, &bPosition1, D3DCOLOR_ARGB(255, 255, 255, 255));
			d3dspt->Draw(sprite_quit, &bPart, &center, &bPosition4, D3DCOLOR_ARGB(255, 255, 255, 255));
			if (KEY_DOWN(VK_LBUTTON))
			{
				sound.Decision();
				PostQuitMessage(0);
			}
		}
		else
		{
			d3dspt->Draw(sprite_play, &bPart, &center, &bPosition1, D3DCOLOR_ARGB(255, 255, 255, 255));
			d3dspt->Draw(sprite_quit, &bPart, &center, &bPosition2, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		//이펙트
		RECT part1; SetRect(&part1, 0, 0, 40, 150); RECT part2; SetRect(&part2, 40, 0, 80, 150); RECT part3; SetRect(&part3, 80, 0, 120, 150); RECT part4; SetRect(&part4, 120, 0, 160, 150);
		RECT part5; SetRect(&part5, 160, 0, 200, 150); RECT part6; SetRect(&part6, 200, 0, 240, 150); RECT part7; SetRect(&part7, 240, 0, 280, 150); RECT part8; SetRect(&part8, 280, 0, 320, 150);
		D3DXVECTOR3 position1(350.0f,420.0f, 0.0f); D3DXVECTOR3 position2(100.0f, 380.0f, 0.0f); D3DXVECTOR3 position3(800.0f, 480.0f, 0.0f); D3DXVECTOR3 center1(0.0f, 0.0f, 0.0f);
		static int oCounter = 0;
		oCounter += 1;
		if (oCounter >= 30) oCounter = 0;
		switch (oCounter/2)
		{
		case 0:
			d3dspt->Draw(sprite_bgEffect, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 1:
			d3dspt->Draw(sprite_bgEffect, &part2, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 2:
			d3dspt->Draw(sprite_bgEffect, &part3, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 3:
			d3dspt->Draw(sprite_bgEffect, &part4, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 4:
			d3dspt->Draw(sprite_bgEffect, &part5, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 5:
			d3dspt->Draw(sprite_bgEffect, &part6, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 6:
			d3dspt->Draw(sprite_bgEffect, &part7, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 7:
			d3dspt->Draw(sprite_bgEffect, &part8, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		}
		switch (oCounter)
		{
		case 0:
			d3dspt->Draw(sprite_bgEffect, &part1, &center1, &position2, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 1:
			d3dspt->Draw(sprite_bgEffect, &part2, &center1, &position2, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 2:
			d3dspt->Draw(sprite_bgEffect, &part3, &center1, &position2, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 3:
			d3dspt->Draw(sprite_bgEffect, &part4, &center1, &position2, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 4:
			d3dspt->Draw(sprite_bgEffect, &part5, &center1, &position2, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 5:
			d3dspt->Draw(sprite_bgEffect, &part6, &center1, &position2, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 6:
			d3dspt->Draw(sprite_bgEffect, &part7, &center1, &position2, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 7:
			d3dspt->Draw(sprite_bgEffect, &part8, &center1, &position2, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		}
		switch (oCounter/3)
		{
		case 0:
			d3dspt->Draw(sprite_bgEffect, &part1, &center1, &position3, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 1:
			d3dspt->Draw(sprite_bgEffect, &part2, &center1, &position3, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 2:
			d3dspt->Draw(sprite_bgEffect, &part3, &center1, &position3, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 3:
			d3dspt->Draw(sprite_bgEffect, &part4, &center1, &position3, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 4:
			d3dspt->Draw(sprite_bgEffect, &part5, &center1, &position3, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 5:
			d3dspt->Draw(sprite_bgEffect, &part6, &center1, &position3, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 6:
			d3dspt->Draw(sprite_bgEffect, &part7, &center1, &position3, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 7:
			d3dspt->Draw(sprite_bgEffect, &part8, &center1, &position3, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		}
		d3dspt->End();
		d3ddev->EndScene();
		d3ddev->Present(NULL, NULL, NULL, NULL);
	}
	else if (ingame == true)
	{
		sound.startBgmEnd();
		//배경음악 켜기
		sound.Bgm();
		//마우스 좌표얻기
		GetCursorPos(&pt);
		//윈도우화면 마우스 좌표
		ScreenToClient(hWnd, &pt);

		// clear the window to a deep blue
		d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), -1.0f, 0);
		d3ddev->BeginScene();
		espt->Begin(D3DXSPRITE_ALPHABLEND);
		d3dspt->Begin(D3DXSPRITE_ALPHABLEND);
		//뒷배경
		RECT part00; SetRect(&part00, 0, 0, 960, 500); D3DXVECTOR3 center00(0.0f, 0.0f, 0.0f);
		static int bCounter = 0;
		bCounter += 1;
		if (bCounter >= 8) bCounter = 0;
		for (int i = 0; i < BACK_NUM; i++)
		{
			D3DXVECTOR3 position00(back[i].x_pos, back[i].y_pos, 0.0f);

			switch (bCounter / 4)
			{
			case 0:
				d3dspt->Draw(sprite_backbg, &part00, &center00, &position00, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				d3dspt->Draw(sprite_backbg2, &part00, &center00, &position00, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		//배경
		RECT part0; SetRect(&part0, 0, 0, 960, 720); D3DXVECTOR3 center0(0.0f, 0.0f, 0.0f);
		static int bCounter2 = 0;
		bCounter2 += 1;
		if (bCounter2 >= 10) bCounter2 = 0;
		for (int i = 0; i < BG_NUM; i++)
		{
			D3DXVECTOR3 position0(bg[i].x_pos, bg[i].y_pos, 0.0f);
			
			switch (bCounter2 / 5)
			{
			case 0:
				d3dspt->Draw(sprite_bg, &part0, &center0, &position0, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				d3dspt->Draw(sprite_bg2, &part0, &center0, &position0, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		//front_bg
		RECT part01; SetRect(&part01, 0, 0, 960, 720); D3DXVECTOR3 center01(0.0f, 0.0f, 0.0f);
		for (int i = 0; i < FRONT_NUM; i++)
		{
			D3DXVECTOR3 position01(front[i].x_pos, front[i].y_pos, 0.0f);
			d3dspt->Draw(sprite_frontbg, &part01, &center01, &position01, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		//발판
		RECT part1; SetRect(&part1, 0, 0, 960, 140); D3DXVECTOR3 center1(0.0f, 0.0f, 0.0f);
		for (int i = 0; i < BG_NUM; i++)
		{
			D3DXVECTOR3 position1(bg[i].x_pos, 500.0f, 0.0f);
			d3dspt->Draw(sprite_scaffolding, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		
		if (pt.x >= 0 && pt.x < 320)
		{
			RECT lPlpart; SetRect(&lPlpart, 0, 0, 240, 291);
			RECT Ppart; SetRect(&Ppart, 0, 0, 280, 291); RECT Ppart2; SetRect(&Ppart2, 280, 0, 560, 291); RECT Ppart3; SetRect(&Ppart3, 560, 0, 840, 291); RECT Ppart4; SetRect(&Ppart4, 840, 0, 1120, 291); RECT Ppart5; SetRect(&Ppart5, 1120, 0, 1400, 291);
			D3DXVECTOR3 Pcenter(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Pposition(390.0f, 350.0f, 0.0f);
			if (machinegun == false)
			{
				if (KEY_UP(VK_LBUTTON))
				{
					//플레이어 idle
					static int pCounter = 0;
					pCounter += 1;
					if (pCounter >= 12) pCounter = 0;
					switch (pCounter / 4)
					{
					case 0:
						d3dspt->Draw(sprite_lplayer_idle1, &lPlpart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 1:
						d3dspt->Draw(sprite_lplayer_idle2, &lPlpart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 2:
						d3dspt->Draw(sprite_lplayer_idle3, &lPlpart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					}
				}
				//플레이어 shot
				else if (KEY_DOWN(VK_LBUTTON))
				{
					static int pCounter2 = 0;
					pCounter2 += 1;
					if (pCounter2 >= 5) pCounter2 = 0;
					switch (pCounter2)
					{
					case 0:
						d3dspt->Draw(sprite_lplayer_shot, &Ppart5, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 1:
						d3dspt->Draw(sprite_lplayer_shot, &Ppart4, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 2:
						d3dspt->Draw(sprite_lplayer_shot, &Ppart3, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 3:
						d3dspt->Draw(sprite_lplayer_shot, &Ppart2, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 4:
						d3dspt->Draw(sprite_lplayer_shot, &Ppart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					}
				}
			}
			//플레이어 스킬
			else if (machinegun == true)
			{
				//플레이어 skill
				static int pCounter = 0;
				pCounter += 1;
				if (pCounter >= 9) pCounter = 0;
				switch (pCounter / 2)
				{
				case 0:
					d3dspt->Draw(sprite_lplayer_skill, &Ppart5, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					d3dspt->Draw(sprite_lplayer_skill, &Ppart4, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					d3dspt->Draw(sprite_lplayer_skill, &Ppart3, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 3:
					d3dspt->Draw(sprite_lplayer_skill, &Ppart2, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 4:
					d3dspt->Draw(sprite_lplayer_skill, &Ppart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
		}
		else if (pt.x >= 320 && pt.x <= 640)
		{
			RECT Plpart; SetRect(&Plpart, 0, 0, 152, 293);
			RECT Ppart; SetRect(&Ppart, 0, 0, 152, 293); RECT Ppart2; SetRect(&Ppart2, 152, 0, 304, 293); RECT Ppart3; SetRect(&Ppart3, 304, 0, 456, 293); RECT Ppart4; SetRect(&Ppart4, 456, 0, 608, 293); RECT Ppart5; SetRect(&Ppart5, 608, 0, 760, 293);
			D3DXVECTOR3 Pcenter(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Pposition(400.0f, 350.0f, 0.0f);
			if (machinegun == false)
			{

				if (KEY_UP(VK_LBUTTON))
				{
					//플레이어 idle
					static int pCounter = 0;
					pCounter += 1;
					if (pCounter >= 8) pCounter = 0;
					switch (pCounter / 4)
					{
					case 0:
						d3dspt->Draw(sprite_player_idle1, &Plpart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 1:
						d3dspt->Draw(sprite_player_idle2, &Plpart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					}
				}
				//플레이어 shot
				else if (KEY_DOWN(VK_LBUTTON))
				{
					static int pCounter2 = 0;
					pCounter2 += 1;
					if (pCounter2 >= 5) pCounter2 = 0;
					switch (pCounter2)
					{
					case 0:
						d3dspt->Draw(sprite_player_shot, &Ppart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 1:
						d3dspt->Draw(sprite_player_shot, &Ppart2, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 2:
						d3dspt->Draw(sprite_player_shot, &Ppart3, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 3:
						d3dspt->Draw(sprite_player_shot, &Ppart4, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 4:
						d3dspt->Draw(sprite_player_shot, &Ppart5, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					}
				}
			}
			//플레이어 스킬
			else if (machinegun == true)
			{
				//플레이어 skill
				static int pCounter = 0;
				pCounter += 1;
				if (pCounter >= 9) pCounter = 0;
				switch (pCounter / 2)
				{
				case 0:
					d3dspt->Draw(sprite_player_skill, &Ppart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					d3dspt->Draw(sprite_player_skill, &Ppart2, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					d3dspt->Draw(sprite_player_skill, &Ppart3, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 3:
					d3dspt->Draw(sprite_player_skill, &Ppart4, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 4:
					d3dspt->Draw(sprite_player_skill, &Ppart5, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
		}
		else if (pt.x > 640)
		{
			RECT rPlpart; SetRect(&rPlpart, 0, 0, 240, 291);
			RECT Ppart; SetRect(&Ppart, 0, 0, 280, 291); RECT Ppart2; SetRect(&Ppart2, 280, 0, 560, 291); RECT Ppart3; SetRect(&Ppart3, 560, 0, 840, 291); RECT Ppart4; SetRect(&Ppart4, 840, 0, 1120, 291); RECT Ppart5; SetRect(&Ppart5, 1120, 0, 1400, 291);
			D3DXVECTOR3 Pcenter(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Pposition(380.0f, 350.0f, 0.0f);
			if (machinegun == false)
			{
				if (KEY_UP(VK_LBUTTON))
				{
					//플레이어 idle
					static int pCounter = 0;
					pCounter += 1;
					if (pCounter >= 12) pCounter = 0;
					switch (pCounter / 4)
					{
					case 0:
						d3dspt->Draw(sprite_rplayer_idle1, &rPlpart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 1:
						d3dspt->Draw(sprite_rplayer_idle2, &rPlpart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 2:
						d3dspt->Draw(sprite_rplayer_idle3, &rPlpart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					}
				}
				//플레이어 shot
				else if (KEY_DOWN(VK_LBUTTON))
				{
					static int pCounter2 = 0;
					pCounter2 += 1;
					if (pCounter2 >= 5) pCounter2 = 0;
					switch (pCounter2)
					{
					case 0:
						d3dspt->Draw(sprite_rplayer_shot, &Ppart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 1:
						d3dspt->Draw(sprite_rplayer_shot, &Ppart2, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 2:
						d3dspt->Draw(sprite_rplayer_shot, &Ppart3, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 3:
						d3dspt->Draw(sprite_rplayer_shot, &Ppart4, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					case 4:
						d3dspt->Draw(sprite_rplayer_shot, &Ppart5, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
						break;
					}
				}
			}
			//플레이어 스킬
			else if (machinegun == true)
			{
				//플레이어 skill
				static int pCounter = 0;
				pCounter += 1;
				if (pCounter >= 9) pCounter = 0;
				switch (pCounter / 2)
				{
				case 0:
					d3dspt->Draw(sprite_rplayer_skill, &Ppart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					d3dspt->Draw(sprite_rplayer_skill, &Ppart2, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					d3dspt->Draw(sprite_rplayer_skill, &Ppart3, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 3:
					d3dspt->Draw(sprite_rplayer_skill, &Ppart4, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 4:
					d3dspt->Draw(sprite_rplayer_skill, &Ppart5, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
		}
		//하단 ui
		RECT part2; SetRect(&part2, 0, 0, 960, 80); D3DXVECTOR3 center2(0.0f, 0.0f, 0.0f); D3DXVECTOR3 position2(0.0f, 640.0f, 0.0f);
		d3dspt->Draw(sprite_ui, &part2, &center2, &position2, D3DCOLOR_ARGB(255, 255, 255, 255));
		//하단 콤보게이지
		RECT part3; SetRect(&part3, 0, 0, 0+((combo.GetNum())*2.5), 38); D3DXVECTOR3 center3(0.0f, 0.0f, 0.0f); D3DXVECTOR3 position3(111.0f, 663.0f, 0.0f); //수정
		d3dspt->Draw(sprite_combo_gage, &part3, &center3, &position3, D3DCOLOR_ARGB(255, 255, 255, 255));
		//잠금(데스샤워)
		RECT lock1; SetRect(&lock1, 0, 0, 40, 40); 
		RECT shower; SetRect(&shower, 0, 0, 40, 0+(lockmove.y_pos)); D3DXVECTOR3 lcenter1(0.0f, 0.0f, 0.0f); D3DXVECTOR3 lposition1(715.0f, 660.0f, 0.0f);
		if(machinegun == false)
			d3dspt->Draw(sprite_lock, &lock1, &lcenter1, &lposition1, D3DCOLOR_ARGB(200, 255, 255, 255));
		else if (machinegun == true && skill == false)
		{
			d3dspt->Draw(sprite_lock, &shower, &lcenter1, &lposition1, D3DCOLOR_ARGB(200, 255, 255, 255));
			lockmove.move();
			if (lockmove.y_pos >= 40)
			{
				machinegun = false;
				lockmove.y_pos = 0;
			}
		}
		//잠금(스케일증가)
		RECT lock2; SetRect(&lock2, 0, 0, 40, 40);
		RECT up; SetRect(&up, 0, 0, 40, 0+(lockmove2.y_pos)); D3DXVECTOR3 lcenter2(0.0f, 0.0f, 0.0f); D3DXVECTOR3 lposition2(775.0f, 660.0f, 0.0f);
		if(summonitem2.Giantization == false)
			d3dspt->Draw(sprite_lock, &lock2, &lcenter2, &lposition2, D3DCOLOR_ARGB(200, 255, 255, 255));
		else if (summonitem2.Giantization == true)
		{
			d3dspt->Draw(sprite_lock, &up, &lcenter2, &lposition2, D3DCOLOR_ARGB(200, 255, 255, 255));
			lockmove2.move();
			if (lockmove2.y_pos >= 40)
			{
				summonitem2.Giantization = false;
				lockmove2.y_pos = 0;
			}
		}
		//잠금(스케일감소)
		RECT lock3; SetRect(&lock3, 0, 0, 40, 40);
		RECT down; SetRect(&down, 0, 0, 40, 0 + (lockmove3.y_pos)); D3DXVECTOR3 lcenter3(0.0f, 0.0f, 0.0f); D3DXVECTOR3 lposition3(835.0f, 660.0f, 0.0f);
		if (summonitem3.Reduction == false)
			d3dspt->Draw(sprite_lock, &lock3, &lcenter3, &lposition3, D3DCOLOR_ARGB(200, 255, 255, 255));
		else if (summonitem3.Reduction == true)
		{
			d3dspt->Draw(sprite_lock, &down, &lcenter3, &lposition3, D3DCOLOR_ARGB(200, 255, 255, 255));
			lockmove3.move();
			if (lockmove3.y_pos >= 40)
			{
				summonitem3.Reduction = false;
				lockmove3.y_pos = 0;
			}
		}
		//타이머
		RECT dpart0;SetRect(&dpart0, 0, 0, 500, 86);D3DXVECTOR3 dcenter0(0.0f, 0.0f, 0.0f);D3DXVECTOR3 dposition0(50.0f, 30.0f, 0.0f);
		d3dspt->Draw(sprite_dz, &dpart0, &dcenter0, &dposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		//타이머(깎이는)
		RECT dpart1;SetRect(&dpart1, 0, 0, timer.x_pos-115, 22);D3DXVECTOR3 dcenter1(0.0f, 0.0f, 0.0f);D3DXVECTOR3 dposition1(125.0f, 60.0f, 0.0f);
		d3dspt->Draw(sprite_dz2, &dpart1, &dcenter1, &dposition1, D3DCOLOR_ARGB(255, 255, 255, 255));
		//타이머(움직이는)
		RECT dpart2;SetRect(&dpart2, 0, 0, 14, 30);D3DXVECTOR3 dcenter2(0.0f, 0.0f, 0.0f);D3DXVECTOR3 dposition2(timer.x_pos, 55.0f, 0.0f);
		d3dspt->Draw(sprite_bullet, &dpart2, &dcenter2, &dposition2, D3DCOLOR_ARGB(255, 255, 255, 255));
		//스코어 레벨
		RECT Slpart; SetRect(&Slpart, 0, 0, 25, 40); D3DXVECTOR3 Slcenter(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Slposition(score.x_pos - 160, score.y_pos, 0.0f);
		//스코어 박스
		RECT Sbpart; SetRect(&Sbpart, 0, 0, 300, 60); D3DXVECTOR3 Sbcenter(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Sbposition(score.x_pos - 220, score.y_pos-10, 0.0f);
		d3dspt->Draw(sprite_scorebox, &Sbpart, &Sbcenter, &Sbposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		//스코어 기본
		RECT Spart;SetRect(&Spart, 0, 0, 25, 40);D3DXVECTOR3 Scenter(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Sposition(score.x_pos + 25, score.y_pos, 0.0f);
		d3dspt->Draw(sprite_score0, &Spart, &Scenter, &Sposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		//스코어 10의자리
		RECT Spart0;SetRect(&Spart0, 0, 0, 25, 40);D3DXVECTOR3 Scenter0(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Sposition0(score.x_pos, score.y_pos, 0.0f);
		//스코어 100의 자리
		RECT Spart10;SetRect(&Spart10, 0, 0, 25, 40);D3DXVECTOR3 Scenter10(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Sposition10(score.x_pos - 25, score.y_pos, 0.0f);
		//스코어 1000의 자리
		RECT Spart100; SetRect(&Spart100, 0, 0, 25, 40); D3DXVECTOR3 Scenter100(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Sposition100(score.x_pos - 50, score.y_pos, 0.0f);
		//수류탄 갯수
		RECT Gpart0; SetRect(&Gpart0, 0, 0, 30, 30); RECT Gpart1; SetRect(&Gpart1, 30, 0, 60, 30); RECT Gpart2; SetRect(&Gpart2, 60, 0, 90, 30); RECT Gpart3; SetRect(&Gpart3, 90, 0, 120, 30);
		D3DXVECTOR3 Gcenter(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Gposition(640, 663, 0.0f);
		if (remaingrenade.GetCounter() == 0)
			d3dspt->Draw(sprite_grenade_num, &Gpart0, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (remaingrenade.GetCounter() == 1)
			d3dspt->Draw(sprite_grenade_num, &Gpart1, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (remaingrenade.GetCounter() == 2)
			d3dspt->Draw(sprite_grenade_num, &Gpart2, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (remaingrenade.GetCounter() == 3)
			d3dspt->Draw(sprite_grenade_num, &Gpart3, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		//총알갯수
		RECT Bpart1;SetRect(&Bpart1, 0, 0, 20, 40); RECT Bpart2; SetRect(&Bpart2, 0, 0, 40, 40); RECT Bpart3; SetRect(&Bpart3, 0, 0, 60, 40); RECT Bpart4; SetRect(&Bpart4, 0, 0, 80, 40); RECT Bpart5; SetRect(&Bpart5, 0, 0, 100, 40);
		D3DXVECTOR3 Bcenter(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Bposition(430, 600, 0.0f); D3DXVECTOR3 Bcenter1(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Bposition1(bulletmove.x_pos, bulletmove.y_pos, 0.0f);
		//Remain bullet
		if (machinegun == false)
		{
			if (remainbullet.GetCounter() == 0)
			{
				d3dspt->Draw(sprite_bullet_empty, &Bpart5, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			}
			else if (remainbullet.GetCounter() == 1)
			{
				d3dspt->Draw(sprite_bullet_empty, &Bpart5, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				d3dspt->Draw(sprite_bullet_full, &Bpart1, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			}
			else if (remainbullet.GetCounter() == 2)
			{
				d3dspt->Draw(sprite_bullet_empty, &Bpart5, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				d3dspt->Draw(sprite_bullet_full, &Bpart2, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			}
			else if (remainbullet.GetCounter() == 3)
			{
				d3dspt->Draw(sprite_bullet_empty, &Bpart5, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				d3dspt->Draw(sprite_bullet_full, &Bpart3, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			}
			else if (remainbullet.GetCounter() == 4)
			{
				d3dspt->Draw(sprite_bullet_empty, &Bpart5, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				d3dspt->Draw(sprite_bullet_full, &Bpart4, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			}
			else if (remainbullet.GetCounter() == 5)
			{
				d3dspt->Draw(sprite_bullet_empty, &Bpart5, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				d3dspt->Draw(sprite_bullet_full, &Bpart5, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			}
			if (KEY_DOWN(VK_SPACE))	bulletmove.init(430, 400);
			if (bulletmove.show == true)
			{
				d3dspt->Draw(sprite_bullet_full, &Bpart5, &Bcenter1, &Bposition1, D3DCOLOR_ARGB(255, 255, 255, 255));
				bulletmove.move();
			}
		}
		else if (machinegun == true)
		{
			d3dspt->Draw(sprite_bullet_empty, &Bpart5, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			d3dspt->Draw(sprite_infinity, &Bpart5, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		////////////////////////////////////////////////////////////////////////////////////////////////스코어레벨
		if (score.GetNum() >= 0 && score.GetNum() <= 30 ) 
			d3dspt->Draw(sprite_score1, &Slpart, &Slcenter, &Slposition, D3DCOLOR_ARGB(255, 255, 255, 255)); // 1단계
		else if (score.GetNum() > 30 && score.GetNum() <= 60)
			d3dspt->Draw(sprite_score2, &Slpart, &Slcenter, &Slposition, D3DCOLOR_ARGB(255, 255, 255, 255)); // 2단계
		else if (score.GetNum() > 60 && score.GetNum() <= 90)
			d3dspt->Draw(sprite_score3, &Slpart, &Slcenter, &Slposition, D3DCOLOR_ARGB(255, 255, 255, 255)); // 3단계
		else if (score.GetNum() > 90 && score.GetNum() <= 120)
			d3dspt->Draw(sprite_score4, &Slpart, &Slcenter, &Slposition, D3DCOLOR_ARGB(255, 255, 255, 255)); // 4단계
		else if (score.GetNum() > 120 )
			d3dspt->Draw(sprite_score5, &Slpart, &Slcenter, &Slposition, D3DCOLOR_ARGB(255, 255, 255, 255)); // 5단계
		////////////////////////////////////////////////////////////////////////////////////////////////////스코어
		if (score.GetNum() % 10 == 0)
			d3dspt->Draw(sprite_score0, &Spart10, &Scenter10, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 1)
			d3dspt->Draw(sprite_score1, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if(score.GetNum() % 10 == 2)
			d3dspt->Draw(sprite_score2, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 3)
			d3dspt->Draw(sprite_score3, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 4)
			d3dspt->Draw(sprite_score4, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 5)
			d3dspt->Draw(sprite_score5, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 6)
			d3dspt->Draw(sprite_score6, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 7)
			d3dspt->Draw(sprite_score7, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 8)
			d3dspt->Draw(sprite_score8, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 9)
			d3dspt->Draw(sprite_score9, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));

		if (((score.GetNum() / 10) % 10 == 0) && score.GetNum() >= 100)
			d3dspt->Draw(sprite_score0, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 1)
			d3dspt->Draw(sprite_score1, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 2)
			d3dspt->Draw(sprite_score2, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 3)
			d3dspt->Draw(sprite_score3, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 4)
			d3dspt->Draw(sprite_score4, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 5)
			d3dspt->Draw(sprite_score5, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 6)
			d3dspt->Draw(sprite_score6, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 7)
			d3dspt->Draw(sprite_score7, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 8)
			d3dspt->Draw(sprite_score8, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 9)
			d3dspt->Draw(sprite_score9, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		if (score.GetNum() >= 100 && score.GetNum() < 200)
			d3dspt->Draw(sprite_score1, &Spart100, &Scenter100, &Sposition100, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 200 && score.GetNum() < 300)
			d3dspt->Draw(sprite_score2, &Spart100, &Scenter100, &Sposition100, D3DCOLOR_ARGB(255, 255, 255, 255));
		////////////////////////////////////////////////////////////////////////////////////////////////////콤보
		if (hitCombo == true)
		{
			//콤보 기본
			RECT Cpart; SetRect(&Cpart, 0, 0, 250, 80); D3DXVECTOR3 Ccenter(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Cposition(combo.x_pos - 110, combo.y_pos+120, 0.0f);
			d3dspt->Draw(sprite_combo_text, &Cpart, &Ccenter, &Cposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			//콤보 1의자리
			RECT Cpart0; SetRect(&Cpart0, 0, 0, 85, 120); D3DXVECTOR3 Ccenter0(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Cposition0(combo.x_pos, combo.y_pos, 0.0f);
			//콤보 10의 자리
			RECT Cpart10; SetRect(&Cpart10, 0, 0, 85, 120); D3DXVECTOR3 Ccenter10(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Cposition10(combo.x_pos - 85, combo.y_pos, 0.0f);
			//콤보 100의 자리
			RECT Cpart100; SetRect(&Cpart100, 0, 0, 85, 120); D3DXVECTOR3 Ccenter100(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Cposition100(combo.x_pos - 170, combo.y_pos, 0.0f);
			if (combo.GetNum() % 10 == 0)
				d3dspt->Draw(sprite_combo0, &Cpart0, &Ccenter0, &Cposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() % 10 == 1)
				d3dspt->Draw(sprite_combo1, &Cpart0, &Ccenter0, &Cposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() % 10 == 2)
				d3dspt->Draw(sprite_combo2, &Cpart0, &Ccenter0, &Cposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() % 10 == 3)
				d3dspt->Draw(sprite_combo3, &Cpart0, &Ccenter0, &Cposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() % 10 == 4)
				d3dspt->Draw(sprite_combo4, &Cpart0, &Ccenter0, &Cposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() % 10 == 5)
				d3dspt->Draw(sprite_combo5, &Cpart0, &Ccenter0, &Cposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() % 10 == 6)
				d3dspt->Draw(sprite_combo6, &Cpart0, &Ccenter0, &Cposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() % 10 == 7)
				d3dspt->Draw(sprite_combo7, &Cpart0, &Ccenter0, &Cposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() % 10 == 8)
				d3dspt->Draw(sprite_combo8, &Cpart0, &Ccenter0, &Cposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() % 10 == 9)
				d3dspt->Draw(sprite_combo9, &Cpart0, &Ccenter0, &Cposition0, D3DCOLOR_ARGB(255, 255, 255, 255));

			if (((combo.GetNum() / 10) % 10 == 0)&& combo.GetNum() >= 100)
				d3dspt->Draw(sprite_combo0, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if((combo.GetNum() / 10) % 10 == 1)
				d3dspt->Draw(sprite_combo1, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if ((combo.GetNum() / 10) % 10 == 2)
				d3dspt->Draw(sprite_combo2, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if ((combo.GetNum() / 10) % 10 == 3)
				d3dspt->Draw(sprite_combo3, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if ((combo.GetNum() / 10) % 10 == 4)
				d3dspt->Draw(sprite_combo4, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if ((combo.GetNum() / 10) % 10 == 5)
				d3dspt->Draw(sprite_combo5, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if ((combo.GetNum() / 10) % 10 == 6)
				d3dspt->Draw(sprite_combo6, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if ((combo.GetNum() / 10) % 10 == 7)
				d3dspt->Draw(sprite_combo7, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if ((combo.GetNum() / 10) % 10 == 8)
				d3dspt->Draw(sprite_combo8, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if ((combo.GetNum() / 10) % 10 == 9)
				d3dspt->Draw(sprite_combo9, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		
			if (combo.GetNum() >= 100 && combo.GetNum() < 200)
				d3dspt->Draw(sprite_combo1, &Cpart100, &Ccenter100, &Cposition100, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() >= 200 && combo.GetNum() < 300)
				d3dspt->Draw(sprite_combo2, &Cpart100, &Ccenter100, &Cposition100, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		//is SKill
		if (skill == true )
		{
			RECT Spart;SetRect(&Spart, 0, 0, 400, 400);D3DXVECTOR3 Scenter(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Sposition(260.0f, 0.0f, 0.0f);
			static int sEcounter = 0;
			sEcounter++;
			if (sEcounter >= 50)
			{
				sEcounter = 0;
				skill = false;
				machinegun = true;
			}
				switch (sEcounter)
				{
				case 1:case 5:
					d3dspt->Draw(sprite_deathshower1, &Spart, &Scenter, &Sposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 10:case 15:
					d3dspt->Draw(sprite_deathshower2, &Spart, &Scenter, &Sposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 20:case 25:
					d3dspt->Draw(sprite_deathshower1, &Spart, &Scenter, &Sposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 30:case 35:
					d3dspt->Draw(sprite_deathshower2, &Spart, &Scenter, &Sposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 40:case 45:
					d3dspt->Draw(sprite_deathshower1, &Spart, &Scenter, &Sposition, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 46:case 49:
					d3dspt->Draw(sprite_deathshower2, &Spart, &Scenter, &Sposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				}

		}
		//machinegun mode
		if(machinegun == true)
		{
			RECT Mpart;SetRect(&Mpart, 0, 0, 960, 640);D3DXVECTOR3 Mcenter(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Mposition(0.0f, 0.0f, 0.0f);
			d3dspt->Draw(sprite_attack5, &Mpart, &Mcenter, &Mposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		//수류탄 애니메이션
		if (grenading== true)
		{
			RECT Gpart1; SetRect(&Gpart1, 0, 0, 360, 360); RECT Gpart2; SetRect(&Gpart2, 360, 0, 720, 360); RECT Gpart3; SetRect(&Gpart3, 720, 0, 1080, 360); RECT Gpart4; SetRect(&Gpart4, 1080, 0, 1440, 360);
			RECT Gpart5; SetRect(&Gpart5, 1440, 0, 1800, 360); RECT Gpart6; SetRect(&Gpart6, 1800, 0, 2160, 360); RECT Gpart7; SetRect(&Gpart7, 2160, 0, 2520, 360); RECT Gpart8; SetRect(&Gpart8, 2520, 0, 2880, 360);
			D3DXVECTOR3 Gcenter(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Gposition(pt.x - 130, pt.y - 175, 0.0f);
			static int gcounter = 0;
			gcounter++;
			if (gcounter >= 15)
			{
				gcounter = 0;
				grenading = false;
			}
			switch (gcounter/2)
			{
			case 0:
				d3dspt->Draw(sprite_grenade, &Gpart1, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				d3dspt->Draw(sprite_grenade, &Gpart2, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 2:
				d3dspt->Draw(sprite_grenade, &Gpart3, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 3:
				d3dspt->Draw(sprite_grenade, &Gpart4, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 4:
				d3dspt->Draw(sprite_grenade, &Gpart5, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 5:
				d3dspt->Draw(sprite_grenade, &Gpart6, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 6:
				d3dspt->Draw(sprite_grenade, &Gpart7, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 7:
				d3dspt->Draw(sprite_grenade, &Gpart8, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		//이펙트 애니메이션
		if (effecting == true)
		{
			RECT Epart;SetRect(&Epart, 0, 0, 150, 150);D3DXVECTOR3 Ecenter(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Eposition(pt.x - 60, pt.y - 75, 0.0f);
			static int ecounter = 0;
			ecounter++;
			if (ecounter >= 8)
			{
				ecounter = 0;
				effecting = false;
			}
			switch (ecounter/2)
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
		if (effecting2 == true)
		{
			RECT Epart; SetRect(&Epart, 0, 0, 150, 150); D3DXVECTOR3 Ecenter(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Eposition(pt.x - 60, pt.y - 75, 0.0f);
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
		if (support == true)
		{
			RECT part10; SetRect(&part10, 0, 0, 530, 100); RECT part11; SetRect(&part11, 0, 0, 0, 0); D3DXVECTOR3 center10(0.0f, 0.0f, 0.0f); D3DXVECTOR3 position10(205, 100.0f, 0.0f);
			static int sCounter2 = 0;
			sCounter2++;
			if (sCounter2 >= 16)
			{
				sCounter2 = 0;
				support = false;
				soldier.Show = true;
			}
			switch (sCounter2 / 4)
			{
			case 0:
				d3dspt->Draw(sprite_support, &part10, &center10, &position10, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				d3dspt->Draw(sprite_support, &part11, &center10, &position10, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 2:
				d3dspt->Draw(sprite_support, &part10, &center10, &position10, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 3:
				d3dspt->Draw(sprite_support, &part11, &center10, &position10, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		if (support2 == true)
		{
			RECT part10; SetRect(&part10, 0, 0, 530, 100); RECT part11; SetRect(&part11, 0, 0, 0, 0); D3DXVECTOR3 center10(0.0f, 0.0f, 0.0f); D3DXVECTOR3 position10(205, 100.0f, 0.0f);
			static int sCounter2 = 0;
			sCounter2++;
			if (sCounter2 >= 16)
			{
				sCounter2 = 0;
				support2 = false;
				soldier2.Show = true;
			}
			switch (sCounter2 / 4)
			{
			case 0:
				d3dspt->Draw(sprite_support, &part10, &center10, &position10, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				d3dspt->Draw(sprite_support, &part11, &center10, &position10, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 2:
				d3dspt->Draw(sprite_support, &part10, &center10, &position10, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 3:
				d3dspt->Draw(sprite_support, &part11, &center10, &position10, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		//soldier 소환
		if (soldier.Show == true)
		{
			RECT part; SetRect(&part, 0, 0, 77, 200); D3DXVECTOR3 center(0.0f, 0.0f, 0.0f); D3DXVECTOR3 position(soldier.x_pos, 440.0f, 0.0f);
			static int sCounter = 0;
			sCounter++;
			if (sCounter >= 24)sCounter = 0;
			else if (sCounter == 12)soldier.Fire = true;
			else soldier.Fire = false;
			switch (sCounter / 4)
			{
			case 0:
				d3dspt->Draw(sprite_soldier1, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				d3dspt->Draw(sprite_soldier2, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 2:
				d3dspt->Draw(sprite_soldier1, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 3:
				d3dspt->Draw(sprite_soldier3, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 4:
				d3dspt->Draw(sprite_soldier4, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 5:
				d3dspt->Draw(sprite_soldier5, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		if (bullet.bShow == true)
		{
			RECT part1; SetRect(&part1, 0, 0, 14, 30); D3DXVECTOR3 center1(0.0f, 0.0f, 0.0f); D3DXVECTOR3 position1(bullet.x_pos, bullet.y_pos, 0.0f);
			d3dspt->Draw(sprite_bullet, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		//soldier2 소환
		if (soldier2.Show == true)
		{
			//soldier2_idle
			RECT part1; SetRect(&part1, 0, 0, 100, 140); RECT part2; SetRect(&part2, 100, 0, 200, 140); RECT part3; SetRect(&part3, 200, 0, 300, 140);
			RECT part4; SetRect(&part4, 300, 0, 400, 140); RECT part5; SetRect(&part5, 400, 0, 500, 140); RECT part6; SetRect(&part6, 500, 0, 600, 140);
			RECT fart1; SetRect(&fart1, 0, 0, 113, 140); RECT fart2; SetRect(&fart2, 113, 0, 213, 140); RECT fart3; SetRect(&fart3, 213, 0, 313, 140);
			RECT fart4; SetRect(&fart4, 313, 0, 413, 140); RECT fart5; SetRect(&fart5, 413, 0, 500, 140);
			D3DXVECTOR3 center(0.0f, 0.0f, 0.0f); D3DXVECTOR3 position(soldier2.x_pos, soldier2.y_pos, 0.0f);
			static int sCounter = 0;
			sCounter++;
			if (sCounter >= 24)sCounter = 0;
			static int sCounter2 = 0;
			sCounter2++;
			if (sCounter2 >= 30)sCounter2 = 0;
			if (bazooka.bShow == true && soldier2.Fire == false)
			{
				switch (sCounter / 5)
				{
				case 0:
					d3dspt->Draw(sprite_soldier2_idle, &part1, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					d3dspt->Draw(sprite_soldier2_idle, &part2, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					d3dspt->Draw(sprite_soldier2_idle, &part3, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 3:
					d3dspt->Draw(sprite_soldier2_idle, &part4, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 4:
					d3dspt->Draw(sprite_soldier2_idle, &part5, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 5:
					d3dspt->Draw(sprite_soldier2_idle, &part6, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
			if (bazooka.bShow == false || soldier2.Fire == true)
			{
				switch (sCounter2 / 4)
				{
				case 0:
					d3dspt->Draw(sprite_soldier2_fire, &fart1, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					d3dspt->Draw(sprite_soldier2_fire, &fart1, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					d3dspt->Draw(sprite_soldier2_fire, &fart2, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					soldier2.Fire = true;
					break;
				case 3:
					d3dspt->Draw(sprite_soldier2_fire, &fart3, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 4:
					d3dspt->Draw(sprite_soldier2_fire, &fart4, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 5:
					d3dspt->Draw(sprite_soldier2_fire, &fart5, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					soldier2.Fire = false;
					break;
				}
			}
		}
		if (bazooka.bShow == true)
		{
			RECT part1; SetRect(&part1, 0, 0, 40, 40); D3DXVECTOR3 center1(0.0f, 0.0f, 0.0f); D3DXVECTOR3 position1(bazooka.x_pos, bazooka.y_pos, 0.0f);
			d3dspt->Draw(sprite_bazooka, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		//수류탄 아이템 등장
		if (summonitem.Appear == true)
		{
			RECT rc; SetRect(&rc, 0, 0, 64, 64); D3DXVECTOR2 spriteCenter = D3DXVECTOR2(32, 32); D3DXVECTOR2 translate = D3DXVECTOR2(summonitem.x_pos, summonitem.y_pos);
			//회전 속도
			iTime = timeGetTime() % 1000;
			angle = iTime * (2.0f * D3DX_PI) / 1000.0f;
			D3DXVECTOR2 scaling(1, 1); D3DXMATRIX matrix;
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
		//크기증가 아이템
		if (summonitem2.Appear == true)
		{
			RECT rc; SetRect(&rc, 0, 0, 64, 64); D3DXVECTOR2 spriteCenter = D3DXVECTOR2(32, 32); D3DXVECTOR2 translate = D3DXVECTOR2(summonitem2.x_pos, summonitem2.y_pos);
			iTime = timeGetTime() % 1000;
			angle = iTime * (2.0f * D3DX_PI) / 1000.0f;
			D3DXVECTOR2 scaling(1, 1); D3DXMATRIX matrix;

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
			espt->Draw(sprite_itemP, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		//크기 감소 아이템
		if (summonitem3.Appear == true)
		{
			RECT rc; SetRect(&rc, 0, 0, 64, 64); D3DXVECTOR2 spriteCenter = D3DXVECTOR2(32, 32); D3DXVECTOR2 translate = D3DXVECTOR2(summonitem3.x_pos, summonitem3.y_pos);
			iTime = timeGetTime() % 1000;
			angle = iTime * (2.0f * D3DX_PI) / 1000.0f;
			D3DXVECTOR2 scaling(1, 1); D3DXMATRIX matrix;

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
			espt->Draw(sprite_itemM, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		//보스
		if (boss.Appear == true)
		{
			//boss_idle
			RECT part1; SetRect(&part1, 0, 0, 100, 96); RECT part2; SetRect(&part2, 100, 0, 200, 96); RECT part3; SetRect(&part3, 200, 0, 300, 96);
			RECT part4; SetRect(&part4, 300, 0, 400, 96); RECT part5; SetRect(&part5, 400, 0, 500, 96); RECT part6; SetRect(&part6, 500, 0, 600, 96);
			D3DXVECTOR3 center(0.0f, 0.0f, 0.0f); D3DXVECTOR3 position(boss.x_pos, boss.y_pos, 0.0f);
			static int sCounter = 0;
			sCounter++;
			if (sCounter >= 18)sCounter = 0;
			if (boss.hit == false)
			{
				switch (sCounter / 3)
				{
				case 0:
					d3dspt->Draw(sprite_boss_idle, &part1, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					d3dspt->Draw(sprite_boss_idle, &part2, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					d3dspt->Draw(sprite_boss_idle, &part3, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 3:
					d3dspt->Draw(sprite_boss_idle, &part4, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 4:
					d3dspt->Draw(sprite_boss_idle, &part5, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 5:
					d3dspt->Draw(sprite_boss_idle, &part6, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
			else if (boss.hit == true)
			{
				switch (sCounter / 3)
				{
				case 0:
					d3dspt->Draw(sprite_boss_hit, &part1, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					d3dspt->Draw(sprite_boss_hit, &part2, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					d3dspt->Draw(sprite_boss_hit, &part3, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 3:
					d3dspt->Draw(sprite_boss_hit, &part4, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 4:
					d3dspt->Draw(sprite_boss_hit, &part5, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 5:
					d3dspt->Draw(sprite_boss_hit, &part6, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
		}
		if (boss.breaking == true)
		{
			RECT Gpart1; SetRect(&Gpart1, 0, 0, 360, 360); RECT Gpart2; SetRect(&Gpart2, 360, 0, 720, 360); RECT Gpart3; SetRect(&Gpart3, 720, 0, 1080, 360); RECT Gpart4; SetRect(&Gpart4, 1080, 0, 1440, 360);
			RECT Gpart5; SetRect(&Gpart5, 1440, 0, 1800, 360); RECT Gpart6; SetRect(&Gpart6, 1800, 0, 2160, 360); RECT Gpart7; SetRect(&Gpart7, 2160, 0, 2520, 360); RECT Gpart8; SetRect(&Gpart8, 2520, 0, 2880, 360);
			D3DXVECTOR3 Gcenter(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Gposition(pt.x - 130, pt.y - 175, 0.0f);
			static int gcounter = 0;
			gcounter++;
			if (gcounter >= 15)
			{
				gcounter = 0;
				boss.breaking = false;
			}
			switch (gcounter / 2)
			{
			case 0:
				d3dspt->Draw(sprite_grenade, &Gpart1, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				d3dspt->Draw(sprite_grenade, &Gpart2, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 2:
				d3dspt->Draw(sprite_grenade, &Gpart3, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 3:
				d3dspt->Draw(sprite_grenade, &Gpart4, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 4:
				d3dspt->Draw(sprite_grenade, &Gpart5, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 5:
				d3dspt->Draw(sprite_grenade, &Gpart6, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 6:
				d3dspt->Draw(sprite_grenade, &Gpart7, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 7:
				d3dspt->Draw(sprite_grenade, &Gpart8, &Gcenter, &Gposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		static int eAcounter = 0;
		eAcounter += 1;
		if (eAcounter >= 4)
			eAcounter = 0;
		////enemy1_left
		for (int i = 0; i < ENEMY1_NUM - dNum; i++)
		{	
			RECT rc;
			SetRect(&rc, 0, 0, 60 * (float)scale, 86 * (float)scale);
			D3DXVECTOR2 spriteCenter = D3DXVECTOR2(30 * (float)scale, 43 * (float)scale);
			// Screen position of the sprite
			D3DXVECTOR2 translate = D3DXVECTOR2(lenemy1[i].x_pos, lenemy1[i].y_pos);
			// Scaling X,Y
			angle = 0;
			D3DXVECTOR2 scaling((float)scale, (float)scale);
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
			switch (eAcounter)
			{
			case 0:
				espt->Draw(sprite_lenemy1, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				espt->Draw(sprite_lenemy2, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 2:
				espt->Draw(sprite_lenemy3, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 3:
				espt->Draw(sprite_lenemy4, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		//lenemy1_breaking animation;
		for (int i = 0; i < ENEMY1_NUM - dNum; i++)
		{
			RECT rc2;
			SetRect(&rc2, 0, 0, 150 * (float)scale, 150 * (float)scale);
			D3DXVECTOR2 spriteCenter2 = D3DXVECTOR2(30 * (float)scale, 43 * (float)scale);
			if (lenemy1[i].breaking == true && effecting == false)
			{
				// Screen position of the sprite
				D3DXVECTOR2 translate2 = D3DXVECTOR2(pt.x - (60 * (float)scale), pt.y - (75 * (float)scale));//애니메이션 좌표 = 마우스좌표
																										// Scaling X,Y
				angle = 0;
				D3DXVECTOR2 scaling((float)scale, (float)scale);
				D3DXMATRIX matrix;

				D3DXMatrixTransformation2D(
					&matrix,                // 행렬
					NULL,                   // 크기를 조정할 때 기준을 왼쪽 상단으로 유지
					0.0f,                   // 크기 조정 회전 없음
					&scaling,               // 크기 조정 값
					&spriteCenter2,          // 회전 중심
					(float)(angle),			// 회전 각도
					&translate2);            // X,Y위치

				espt->SetTransform(&matrix);
				// Draw the sprite
				static int acounter = 0;
				acounter++;
				if (acounter >= 8)
				{
					acounter = 0;
					lenemy1[i].breaking = false;
				}
				switch (acounter / 2)
				{
				case 0:
					espt->Draw(sprite_bBreak, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					espt->Draw(sprite_bBreak2, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					espt->Draw(sprite_bBreak3, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 3:
					espt->Draw(sprite_bBreak4, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
			else if (lenemy1[i].bBreaking == true && effecting == false)
			{
				// Screen position of the sprite
				D3DXVECTOR2 translate2 = D3DXVECTOR2(bullet.x_pos - (60 * (float)scale), bullet.y_pos - (75 * (float)scale));//애니메이션 좌표 = 마우스좌표
				angle = 0;
				D3DXVECTOR2 scaling((float)scale, (float)scale);
				D3DXMATRIX matrix;

				D3DXMatrixTransformation2D(
					&matrix,                // 행렬
					NULL,                   // 크기를 조정할 때 기준을 왼쪽 상단으로 유지
					0.0f,                   // 크기 조정 회전 없음
					&scaling,               // 크기 조정 값
					&spriteCenter2,          // 회전 중심
					(float)(angle),			// 회전 각도
					&translate2);            // X,Y위치

				espt->SetTransform(&matrix);
				// Draw the sprite
				static int acounter = 0;
				acounter++;
				if (acounter >= 8)
				{
					acounter = 0;
					lenemy1[i].bBreaking = false;
				}
				switch (acounter / 2)
				{
				case 0:
					espt->Draw(sprite_bBreak, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					espt->Draw(sprite_bBreak2, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					espt->Draw(sprite_bBreak3, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 3:
					espt->Draw(sprite_bBreak4, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
		}
		////enemy1_right
		for (int i = 0; i < ENEMY1_NUM - dNum; i++)
		{
			RECT rc;
			SetRect(&rc, 0, 0, 60 * (float)scale, 86 * (float)scale);

			D3DXVECTOR2 spriteCenter = D3DXVECTOR2(30 * (float)scale, 43 * (float)scale);
			// Screen position of the sprite
			D3DXVECTOR2 translate = D3DXVECTOR2(enemy1[i].x_pos, enemy1[i].y_pos);
			// Scaling X,Y
			angle = 0;
			D3DXVECTOR2 scaling((float)scale, (float)scale);
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
			switch (eAcounter)
			{
			case 0:
				espt->Draw(sprite_enemy1, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				espt->Draw(sprite_enemy2, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 2:
				espt->Draw(sprite_enemy3, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 3:
				espt->Draw(sprite_enemy4, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		//enemy1_breaking animation;
		for (int i = 0; i < ENEMY1_NUM - dNum; i++)
		{
			RECT rc3;
			SetRect(&rc3, 0, 0, 150 * (float)scale, 150 * (float)scale);
			D3DXVECTOR2 spriteCenter3 = D3DXVECTOR2(30 * (float)scale, 43 * (float)scale);
			if (enemy1[i].breaking == true && effecting == false)
			{
				// Screen position of the sprite
				D3DXVECTOR2 translate3 = D3DXVECTOR2(pt.x - (60 * (float)scale), pt.y - (75 * (float)scale));//애니메이션 좌표 = 마우스좌표																				 
				angle = 0;
				D3DXVECTOR2 scaling((float)scale,(float)scale );
				D3DXMATRIX matrix;

				D3DXMatrixTransformation2D(
					&matrix,                // 행렬
					NULL,                   // 크기를 조정할 때 기준을 왼쪽 상단으로 유지
					0.0f,                   // 크기 조정 회전 없음
					&scaling,               // 크기 조정 값
					&spriteCenter3,          // 회전 중심
					(float)(angle),			// 회전 각도
					&translate3);            // X,Y위치

				espt->SetTransform(&matrix);
				// Draw the sprite
				static int acounter = 0;
				acounter++;
				if (acounter >= 8)
				{
					acounter = 0;
					enemy1[i].breaking = false;
				}
				switch (acounter / 2)
				{
				case 0:
					espt->Draw(sprite_bBreak, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					espt->Draw(sprite_bBreak2, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					espt->Draw(sprite_bBreak3, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 3:
					espt->Draw(sprite_bBreak4, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
			else if (enemy1[i].bBreaking == true && effecting == false)
			{
				// Screen position of the sprite
				D3DXVECTOR2 translate3 = D3DXVECTOR2(bullet.x_pos - (60 * (float)scale), bullet.y_pos - (75 * (float)scale));//애니메이션 좌표 = 마우스좌표
				angle = 0;
				D3DXVECTOR2 scaling((float)scale, (float)scale);
				D3DXMATRIX matrix;

				D3DXMatrixTransformation2D(
					&matrix,                // 행렬
					NULL,                   // 크기를 조정할 때 기준을 왼쪽 상단으로 유지
					0.0f,                   // 크기 조정 회전 없음
					&scaling,               // 크기 조정 값
					&spriteCenter3,          // 회전 중심
					(float)(angle),			// 회전 각도
					&translate3);            // X,Y위치

				espt->SetTransform(&matrix);
				// Draw the sprite
				static int acounter = 0;
				acounter++;
				if (acounter >= 8)
				{
					acounter = 0;
					enemy1[i].bBreaking = false;
				}
				switch (acounter / 2)
				{
				case 0:
					espt->Draw(sprite_bBreak, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					espt->Draw(sprite_bBreak2, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					espt->Draw(sprite_bBreak3, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 3:
					espt->Draw(sprite_bBreak4, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
		}
		//enemy2_left
		for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
		{
			if (lenemy2[i].appear == true)
			{
				static int eAcounter2 = 0;
				eAcounter2 += 1;
				if (eAcounter2 >= 2)
					eAcounter2 = 0;
				RECT rc;
				SetRect(&rc, 0, 0, 60, 86);

				D3DXVECTOR2 spriteCenter = D3DXVECTOR2(30, 43);
				// Screen position of the sprite
				D3DXVECTOR2 translate = D3DXVECTOR2(lenemy2[i].x_pos, lenemy2[i].y_pos);
				// Scaling X,Y

				iTime = timeGetTime() % 500;
				if (lenemy2[i].miss == false)
					angle = 0;
				else if (lenemy2[i].miss == true)
					angle = iTime * (2.0f * D3DX_PI) / 500.0f;
				D3DXVECTOR2 scaling((float)scale, (float)scale);
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
				switch (eAcounter2)
				{
				case 0:
					espt->Draw(sprite_lenemy2_1, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					espt->Draw(sprite_lenemy2_2, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
		}
		//lenemy2 breaking animation
		for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
		{
			RECT rc4;
			SetRect(&rc4, 0, 0, 150 * (float)scale, 150 * (float)scale);
			D3DXVECTOR2 spriteCenter4 = D3DXVECTOR2(30 * (float)scale, 43 * (float)scale);
			if (lenemy2[i].breaking == true && effecting == false)
			{
				// Screen position of the sprite
				D3DXVECTOR2 translate4 = D3DXVECTOR2(pt.x - (60 * (float)scale), pt.y - (75 * (float)scale));//애니메이션 좌표 = 마우스좌표																				 
				angle = 0;
				D3DXVECTOR2 scaling((float)scale, (float)scale);
				D3DXMATRIX matrix;

				D3DXMatrixTransformation2D(
					&matrix,                // 행렬
					NULL,                   // 크기를 조정할 때 기준을 왼쪽 상단으로 유지
					0.0f,                   // 크기 조정 회전 없음
					&scaling,               // 크기 조정 값
					&spriteCenter4,          // 회전 중심
					(float)(angle),			// 회전 각도
					&translate4);            // X,Y위치

				espt->SetTransform(&matrix);
				static int acounter = 0;
				acounter++;
				if (acounter >= 8)
				{
					acounter = 0;
					lenemy2[i].breaking = false;
				}
				switch (acounter / 2)
				{
				case 0:
					espt->Draw(sprite_bBreak, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					espt->Draw(sprite_bBreak2, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					espt->Draw(sprite_bBreak3, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 3:
					espt->Draw(sprite_bBreak4, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
			else if (lenemy2[i].bBreaking == true && effecting == false)
			{
				// Screen position of the sprite
				D3DXVECTOR2 translate4 = D3DXVECTOR2(bullet.x_pos - (60 * (float)scale), bullet.y_pos - (75 * (float)scale));																		 
				angle = 0;
				D3DXVECTOR2 scaling((float)scale, (float)scale);
				D3DXMATRIX matrix;

				D3DXMatrixTransformation2D(
					&matrix,                // 행렬
					NULL,                   // 크기를 조정할 때 기준을 왼쪽 상단으로 유지
					0.0f,                   // 크기 조정 회전 없음
					&scaling,               // 크기 조정 값
					&spriteCenter4,          // 회전 중심
					(float)(angle),			// 회전 각도
					&translate4);            // X,Y위치

				espt->SetTransform(&matrix);
				static int acounter = 0;
				acounter++;
				if (acounter >= 8)
				{
					acounter = 0;
					lenemy2[i].bBreaking = false;
				}
				switch (acounter / 2)
				{
				case 0:
					espt->Draw(sprite_bBreak, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					espt->Draw(sprite_bBreak2, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					espt->Draw(sprite_bBreak3, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 3:
					espt->Draw(sprite_bBreak4, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
		}
		//enemy2_right
		for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
		{
			if (enemy2[i].appear == true)
			{
				static int eAcounter2 = 0;
				eAcounter2 += 1;
				if (eAcounter2 >= 2)
					eAcounter2 = 0;
				RECT rc;
				SetRect(&rc, 0, 0, 60, 86);

				D3DXVECTOR2 spriteCenter = D3DXVECTOR2(30, 43);
				// Screen position of the sprite
				D3DXVECTOR2 translate = D3DXVECTOR2(enemy2[i].x_pos, enemy2[i].y_pos);
				// Scaling X,Y

				iTime = timeGetTime() % 500;
				if (enemy2[i].miss == false)
					angle = 0;
				else if (enemy2[i].miss == true)
					angle = iTime * (2.0f * D3DX_PI) / 500.0f;
				D3DXVECTOR2 scaling((float)scale, (float)scale);
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
				switch (eAcounter2)
				{
				case 0:
					espt->Draw(sprite_enemy2_1, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					espt->Draw(sprite_enemy2_2, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
		}
		//enemy2 breaking animation
		for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
		{
			RECT rc5;
			SetRect(&rc5, 0, 0, 150 * (float)scale, 150 * (float)scale);
			D3DXVECTOR2 spriteCenter5 = D3DXVECTOR2(30 * (float)scale, 43 * (float)scale);
			if (enemy2[i].breaking == true && effecting == false)
			{
				// Screen position of the sprite
				D3DXVECTOR2 translate5 = D3DXVECTOR2(pt.x - (60 * (float)scale), pt.y - (75 * (float)scale));//애니메이션 좌표 = 마우스좌표																				 
				angle = 0;
				D3DXVECTOR2 scaling((float)scale, (float)scale);
				D3DXMATRIX matrix;

				D3DXMatrixTransformation2D(
					&matrix,                // 행렬
					NULL,                   // 크기를 조정할 때 기준을 왼쪽 상단으로 유지
					0.0f,                   // 크기 조정 회전 없음
					&scaling,               // 크기 조정 값
					&spriteCenter5,          // 회전 중심
					(float)(angle),			// 회전 각도
					&translate5);            // X,Y위치

				espt->SetTransform(&matrix);
				static int acounter = 0;
				acounter++;
				if (acounter >= 8)
				{
					acounter = 0;
					enemy2[i].breaking = false;
				}
				switch (acounter / 2)
				{
				case 0:
					espt->Draw(sprite_bBreak, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					espt->Draw(sprite_bBreak2, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					espt->Draw(sprite_bBreak3, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 3:
					espt->Draw(sprite_bBreak4, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
			else if (enemy2[i].bBreaking == true && effecting == false)
			{
				D3DXVECTOR2 translate5 = D3DXVECTOR2(bullet.x_pos - (60 * (float)scale), bullet.y_pos - (75 * (float)scale));//애니메이션 좌표 = 마우스좌표																				 
				angle = 0;
				D3DXVECTOR2 scaling((float)scale, (float)scale);
				D3DXMATRIX matrix;

				D3DXMatrixTransformation2D(
					&matrix,                // 행렬
					NULL,                   // 크기를 조정할 때 기준을 왼쪽 상단으로 유지
					0.0f,                   // 크기 조정 회전 없음
					&scaling,               // 크기 조정 값
					&spriteCenter5,          // 회전 중심
					(float)(angle),			// 회전 각도
					&translate5);            // X,Y위치

				espt->SetTransform(&matrix);
				static int acounter = 0;
				acounter++;
				if (acounter >= 8)
				{
					acounter = 0;
					enemy2[i].bBreaking = false;
				}
				switch (acounter / 2)
				{
				case 0:
					espt->Draw(sprite_bBreak, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 1:
					espt->Draw(sprite_bBreak2, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 2:
					espt->Draw(sprite_bBreak3, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				case 3:
					espt->Draw(sprite_bBreak4, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
					break;
				}
			}
		}
		//enemy3_left
		if (lenemy3.attack == false && lenemy3.appear == true)
		{
			static int eAcounter3 = 0;
			eAcounter3 += 1;
			if (eAcounter3 >= 2)
				eAcounter3 = 0;
			RECT Rpart3; SetRect(&Rpart3, 0, 0, 60, 86); D3DXVECTOR3 Rcenter3(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Rposition3(lenemy3.x_pos, lenemy3.y_pos, 0.0f);
			switch (eAcounter3)
			{
			case 0:
				d3dspt->Draw(sprite_lenemy3_1, &Rpart3, &Rcenter3, &Rposition3, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				d3dspt->Draw(sprite_lenemy3_2, &Rpart3, &Rcenter3, &Rposition3, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		//enemy3_right
		if (enemy3.attack == false && enemy3.appear == true)
		{
			static int eAcounter3 = 0;
			eAcounter3 += 1;
			if (eAcounter3 >= 2)
				eAcounter3 = 0;
			RECT Rpart3;SetRect(&Rpart3, 0, 0, 60 , 86);D3DXVECTOR3 Rcenter3(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Rposition3(enemy3.x_pos, enemy3.y_pos, 0.0f);
			switch (eAcounter3)
			{
			case 0:
				d3dspt->Draw(sprite_enemy3_1, &Rpart3, &Rcenter3, &Rposition3, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				d3dspt->Draw(sprite_enemy3_2, &Rpart3, &Rcenter3, &Rposition3, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		//lenemy3_attack animation
		if (lenemy3.attack == true && lenemy3.appear == true)
		{
			RECT Apart1, Apart2, Apart3, Apart4;
			SetRect(&Apart1, 0, 0, 80, 80);
			SetRect(&Apart2, 0, 0, 160, 160);
			SetRect(&Apart3, 0, 0, 320, 320);
			SetRect(&Apart4, 0, 0, 960, 640);
			D3DXVECTOR3 Acenter(0.0f, 0.0f, 0.0f);
			D3DXVECTOR3 Aposition1(440.0f, 240.0f, 0.0f);
			D3DXVECTOR3 Aposition2(400.0f, 160.0f, 0.0f);
			D3DXVECTOR3 Aposition3(320.0f, 0.0f, 0.0f);
			D3DXVECTOR3 Aposition4(0.0f, 0.0f, 0.0f);
			static int aAcounter = 0;
			aAcounter++;
			if (aAcounter >= 30)
			{
				sound.PlayerHit();
				aAcounter = 0;
				lenemy3.attack = false;
			}

			switch (aAcounter / 5)
			{
			case 1:
				d3dspt->Draw(sprite_attack1, &Apart1, &Acenter, &Aposition1, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 2:
				d3dspt->Draw(sprite_attack2, &Apart2, &Acenter, &Aposition2, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 3:
				d3dspt->Draw(sprite_attack3, &Apart3, &Acenter, &Aposition3, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 4: case 5:
				d3dspt->Draw(sprite_attack4, &Apart4, &Acenter, &Aposition4, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		//enemy3_attack animation
		if (enemy3.attack == true && enemy3.appear == true)
		{
			RECT Apart1, Apart2, Apart3, Apart4;
			SetRect(&Apart1, 0, 0, 80, 80);
			SetRect(&Apart2, 0, 0, 160, 160);
			SetRect(&Apart3, 0, 0, 320, 320);
			SetRect(&Apart4, 0, 0, 960, 640);
			D3DXVECTOR3 Acenter(0.0f, 0.0f, 0.0f);
			D3DXVECTOR3 Aposition1(440.0f, 240.0f, 0.0f);
			D3DXVECTOR3 Aposition2(400.0f, 160.0f, 0.0f);
			D3DXVECTOR3 Aposition3(320.0f, 0.0f, 0.0f);
			D3DXVECTOR3 Aposition4(0.0f, 0.0f, 0.0f);
			static int aAcounter = 0;
			aAcounter++;
			if (aAcounter >= 30)
			{
				sound.PlayerHit();
				aAcounter = 0;
				enemy3.attack = false;
			}
			
			switch (aAcounter/5)
			{
			case 1:
				d3dspt->Draw(sprite_attack1, &Apart1, &Acenter, &Aposition1, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 2:
				d3dspt->Draw(sprite_attack2, &Apart2, &Acenter, &Aposition2, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 3:
				d3dspt->Draw(sprite_attack3, &Apart3, &Acenter, &Aposition3, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 4: case 5:
				d3dspt->Draw(sprite_attack4, &Apart4, &Acenter, &Aposition4, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		d3dspt->End();
		espt->End();
		d3ddev->EndScene();

		d3ddev->Present(NULL, NULL, NULL, NULL);
		return;
	}
	//스테이지 끝날 경우
	else if (ending == true)
	{
		//마우스 좌표얻기
		GetCursorPos(&pt);
		//윈도우화면 마우스 좌표
		ScreenToClient(hWnd, &pt);

		sound.bgmEnd();
		sound.SkillEnd();
		d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), -1.0f, 0);
		d3ddev->BeginScene();
		d3dspt->Begin(D3DXSPRITE_ALPHABLEND);
		// clear 배경
		RECT ipart;SetRect(&ipart, 0, 0, 960, 720);D3DXVECTOR3 icenter(0.0f, 0.0f, 0.0f);D3DXVECTOR3 iposition(0.0f, 0.0f, 0.0f);
		d3dspt->Draw(sprite_ending, &ipart, &icenter, &iposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		RECT ipart2; SetRect(&ipart2, 0, 0, 300, 60); D3DXVECTOR3 icenter2(0.0f, 0.0f, 0.0f); D3DXVECTOR3 iposition2(350.0f, 500.0f, 0.0f);
		d3dspt->Draw(sprite_nextstage, &ipart2, &icenter2, &iposition2, D3DCOLOR_ARGB(255, 255, 255, 255));
		RECT ipart3; SetRect(&ipart3, 0, 0, 300, 60); D3DXVECTOR3 icenter3(0.0f, 0.0f, 0.0f); D3DXVECTOR3 iposition3(350.0f, 600.0f, 0.0f);
		d3dspt->Draw(sprite_gomain, &ipart3, &icenter3, &iposition3, D3DCOLOR_ARGB(255, 255, 255, 255));
		if (pt.x >= 350 && pt.x <= 650 && pt.y >= 600 && pt.y <= 660)
		{
			if (KEY_DOWN(VK_LBUTTON))
			{
				ending = false;
				opening = true;
			}
		}

		//기본
		RECT Spart;SetRect(&Spart, 0, 0, 85, 120);D3DXVECTOR3 Scenter(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Sposition(755, 330, 0.0f);
		d3dspt->Draw(sprite_combo0, &Spart, &Scenter, &Sposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		//10의자리
		RECT Spart0;SetRect(&Spart0, 0, 0, 85, 120);D3DXVECTOR3 Scenter0(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Sposition0(670, 330, 0.0f);
		//100의 자리
		RECT Spart10;SetRect(&Spart10, 0, 0, 85, 120);D3DXVECTOR3 Scenter10(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Sposition10(585, 330, 0.0f);
		//1000의자리
		RECT Spart100; SetRect(&Spart100, 0, 0, 85, 120); D3DXVECTOR3 Scenter100(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Sposition100(500, 330, 0.0f);
		//스코어
		if (score.GetNum() % 10 == 0)
			d3dspt->Draw(sprite_combo0, &Spart10, &Scenter10, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 1)
			d3dspt->Draw(sprite_combo1, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 2)
			d3dspt->Draw(sprite_combo2, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 3)
			d3dspt->Draw(sprite_combo3, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 4)
			d3dspt->Draw(sprite_combo4, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 5)
			d3dspt->Draw(sprite_combo5, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 6)
			d3dspt->Draw(sprite_combo6, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 7)
			d3dspt->Draw(sprite_combo7, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 8)
			d3dspt->Draw(sprite_combo8, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() % 10 == 9)
			d3dspt->Draw(sprite_combo9, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));

		if (((score.GetNum() / 10) % 10 == 0) && score.GetNum() >= 100)
			d3dspt->Draw(sprite_combo0, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 1)
			d3dspt->Draw(sprite_combo1, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 2)
			d3dspt->Draw(sprite_combo2, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 3)
			d3dspt->Draw(sprite_combo3, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 4)
			d3dspt->Draw(sprite_combo4, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 5)
			d3dspt->Draw(sprite_combo5, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 6)
			d3dspt->Draw(sprite_combo6, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 7)
			d3dspt->Draw(sprite_combo7, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 8)
			d3dspt->Draw(sprite_combo8, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if ((score.GetNum() / 10) % 10 == 9)
			d3dspt->Draw(sprite_combo9, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));

		if (score.GetNum() >= 100 && score.GetNum() < 200)
			d3dspt->Draw(sprite_combo1, &Spart100, &Scenter100, &Sposition100, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 200 && score.GetNum() < 300)
			d3dspt->Draw(sprite_combo2, &Spart100, &Scenter100, &Sposition100, D3DCOLOR_ARGB(255, 255, 255, 255));

		d3dspt->End();

		d3ddev->EndScene();

		d3ddev->Present(NULL, NULL, NULL, NULL);
		return;
	}
}
void Game::init_game(void)
{
	//앞배경 초기화
	front[0].init(0.0f, 0.0f);
	front[1].init(0.0f, SCREEN_HEIGHT);
	//뒷배경 초기화
	back[0].init(0.0f, 0.0f);
	back[1].init(0.0f, 500.0f);
	//배경 초기화
	bg[0].init(0.0f, 0.0f);
	bg[1].init(0.0f,SCREEN_HEIGHT);
	//타이머 오브젝트 초기화
	timer.init(535, 40);
	//스코어 초기화
	score.init(880, 40);
	//콤보 초기화
	combo.init(800, 100);
	//soldier 초기화
	soldier.init(1, 440);
	//soldier2 초기화
	soldier2.init(800, 500);
	//오브젝트 초기화
	for (int i = 0; i < ENEMY1_NUM - dNum; i++)
	{
		enemy1[i].init((float)(960 + rand() % 100), (float)(250 + rand() % 300));
		lenemy1[i].init((float)(0 - rand() % 100), (float)(250 + rand() % 300));
	}	
	for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
	{
		if (enemy2[i].appear == true)enemy2[i].init((float)(960 + rand() % 200), (float)(300 + rand() % 200));
		if (lenemy2[i].appear == true)lenemy2[i].init((float)(0 - rand() % 200), (float)(300 + rand() % 200));
	}
	if (enemy3.appear == true)enemy3.init((float)(960 + rand() % 100), (float)(300 + rand() % 100));
	if (lenemy3.appear == true)lenemy3.init((float)(0 - rand() % 100), (float)(300 + rand() % 100));

	//soldier의 총알
	bullet.init(soldier.x_pos, soldier.y_pos);
	//soldier2의 바주카볼
	bazooka.init(soldier2.x_pos, 500);
	//수류탄 아이템
	summonitem.init(950, 750);
	//크기증가 아이템
	summonitem2.init(900, 750);
	//크기감소 아이템
	summonitem3.init(1000, 700);
	boss.init(-100, 0);
}
void Game::do_game_logic(void)
{
	if (ingame == true)
	{
		
		if (KEY_DOWN(VK_DELETE))
		{
			skill = true;
			sound.SkillSound();
		}
		//보스 소환시 타이머 가속
		if (boss.Appear == true)
		{
			timer.x_pos -= 0.3;
			clock_t begin3;
			begin3 = clock();
			if ((begin3/CLOCKS_PER_SEC)%3 == 0)
				boss.init((float)(100 + rand() % 600), (float)(100 + rand() % 400));

		}
		
		timer.move();
		//엔딩조건
		if (timer.x_pos < 120)
		{
			ingame = false;
			ending = true;
		}
		for (int i = 0; i < BG_NUM; i++)
		{
			if (machinegun == true)
			{
				front[i].shake();
				back[i].shake();
				bg[i].shake();
			}
			bg[i].init(bg[i].x_pos, bg[i].y_pos);
			bg[i].move();
			back[i].init(back[i].x_pos, back[i].y_pos);
			back[i].move();
			front[i].init(back[i].x_pos, front[i].y_pos);
			front[i].move();
		}
		//콤보
		if (hitCombo == true) combo.shake();
		//총알 개수 0일 때
		if (remainbullet.GetCounter() == 0)
		{
			if (KEY_DOWN(VK_LBUTTON))
				sound.Gird();
		} 
		if (KEY_DOWN(VK_SPACE))
		{
			if (bulletmove.show == true)
				remainbullet.SetCounter(0);
		}
		if (bulletmove.y_pos == 600)
		{
			sound.Reload();
			remainbullet.SetCounter(5);
		}
		//enemy1
		for (int i = 0; i < ENEMY1_NUM - dNum; i++)
		{
			if (enemy1[i].x_pos <= 0 || enemy1[i].y_pos > 755)
				enemy1[i].init((float)(960 + rand() % 100), (float)(250 + rand() % 300));
			else
				enemy1[i].move();
		}
		for (int i = 0; i < ENEMY1_NUM - dNum; i++)
		{
			if (lenemy1[i].x_pos >= 960 || lenemy1[i].y_pos > 755 ) 
				lenemy1[i].init((float)(0 - rand() % 100), (float)(250 + rand() % 300));
			else
				lenemy1[i].move();
		}
		//enemy2
		for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
		{
			enemy2[i].movePattern();
			if (enemy2[i].x_pos <= 0 || enemy2[i].y_pos > 755)
				enemy2[i].init((float)(960 + rand() % 200), (float)(300 + rand() % 200));
			else if (enemy2[i].miss == false)
				enemy2[i].move();
			else if (enemy2[i].miss == true)
				enemy2[i].move2();
		}
		for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
		{
			lenemy2[i].movePattern();
			if (lenemy2[i].x_pos >= 960 || lenemy2[i].y_pos > 755)
				lenemy2[i].init((float)(0 - rand() % 100), (float)(300 + rand() % 200));
			else if (lenemy2[i].miss == false)
				lenemy2[i].move();
			else if (lenemy2[i].miss == true)
				lenemy2[i].move2();
		}
		//enemy3
		if (enemy3.x_pos <= 0 || enemy3.y_pos > 755)
			enemy3.init((float)(960 + rand() % 100), (float)(300 + rand() % 100));
		else
			enemy3.move();
		if (lenemy3.x_pos >= 960 || lenemy3.y_pos > 755)
			lenemy3.init((float)(0 - rand() % 100), (float)(300 + rand() % 100));
		else
			lenemy3.move();

		//solider 처리
		soldier.change();
		soldier.move();

		if (soldier.Show == true)
		{
			sound.SupportShoot();
			if (bullet.show() == false) 
			{
				if (soldier.Fire == true)
				{
					bullet.active();
					bullet.init(soldier.x_pos, 440);
				}
			}
		}
		if (soldier.Show == false)sound.SupportShootEnd();
		if (combo.GetNum() == 40)
			support = true;
		if (combo.GetNum() == 80 || combo.GetNum() == 160)
		{
			sound.SkillSound();
			skill = true;
		}
		if (combo.GetNum() == 120)
			support2 = true;
		//solider의 총알 처리
		if (bullet.show() == true)
		{
			if (bullet.y_pos < 0)
				bullet.hide();
			else
				bullet.move();
			for (int i = 0; i < ENEMY1_NUM - dNum; i++)
			{
				//solider의 총알 충돌 처리 
				if (bullet.check_collision(enemy1[i].x_pos, enemy1[i].y_pos) == true)
				{
					timer.x_pos += 1;
					sound.HitShot();
					hitCombo = true;
					effecting = false;
					enemy1[i].bBreaking = true;
					enemy1[i].init((float)(960 + rand() % 100), (float)(250 + rand() % 300));
					combo.init(800, 100);
					score.SetNum(score.GetNum() + 1);
					combo.SetNum(combo.GetNum() + 1);
				}
				else if (bullet.check_collision(lenemy1[i].x_pos, lenemy1[i].y_pos) == true)
				{
					timer.x_pos += 1;
					sound.HitShot();
					hitCombo = true;
					effecting = false;
					lenemy1[i].bBreaking = true;
					lenemy1[i].init((float)(0 - rand() % 100), (float)(250 + rand() % 300));
					combo.init(800, 100);
					score.SetNum(score.GetNum() + 1);
					combo.SetNum(combo.GetNum() + 1);
				}
			}
			for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
			{
				if (bullet.check_collision(enemy2[i].x_pos, enemy2[i].y_pos) == true)
				{
					timer.x_pos += 1.3;
					sound.HitShot();
					hitCombo = true;
					effecting = false;
					enemy2[i].bBreaking = true;
					enemy2[i].init((float)(950 + rand() % 200), (float)(200 + rand() % 200));
					combo.init(800, 100);
					score.SetNum(score.GetNum() + 1);
					combo.SetNum(combo.GetNum() + 1);
				}
				else if (bullet.check_collision(lenemy2[i].x_pos, lenemy2[i].y_pos) == true)
				{
					timer.x_pos += 1.3;
					sound.HitShot();
					hitCombo = true;
					effecting = false;
					lenemy2[i].bBreaking = true;
					lenemy2[i].init((float)(950 + rand() % 200), (float)(200 + rand() % 200));
					combo.init(800, 100);
					score.SetNum(score.GetNum() + 1);
					combo.SetNum(combo.GetNum() + 1);
				}
			}
		}

		if (soldier2.Show == true) // 바주카병 소환시
		{
			//sound.SupportShoot();
			if (bazooka.show() == false) // 바주카볼이 없을떄
			{
				if (soldier2.Fire == true)// 바주카병 파이어일때
				{
					bazooka.active();
					bazooka.init(soldier2.x_pos, 500);
				}
			}
		}
		//if (soldier2.Show == false)sound.SupportShootEnd();
		//solider2의 바주카볼 처리
		if (bazooka.show() == true)
		{
			if (bazooka.x_pos <= 0)
				bazooka.hide();
			else
			{
				bazooka.Update(1.0);
				bazooka.Jump();
			}
			for (int i = 0; i < ENEMY1_NUM - dNum; i++)
			{
				//solider2의 바주카볼 충돌 처리 
				if (bazooka.check_collision(enemy1[i].x_pos, enemy1[i].y_pos) == true)
				{
					timer.x_pos += 1;
					sound.HitShot();
					hitCombo = true;
					effecting = false;
					enemy1[i].init((float)(960 + rand() % 100), (float)(250 + rand() % 300));
					combo.init(800, 100);
					score.SetNum(score.GetNum() + 1);
					combo.SetNum(combo.GetNum() + 1);
				}
				else if (bazooka.check_collision(lenemy1[i].x_pos, lenemy1[i].y_pos) == true)
				{
					timer.x_pos += 1;
					sound.HitShot();
					hitCombo = true;
					effecting = false;
					lenemy1[i].init((float)(0 - rand() % 100), (float)(250 + rand() % 300));
					combo.init(800, 100);
					score.SetNum(score.GetNum() + 1);
					combo.SetNum(combo.GetNum() + 1);
				}
			}
			for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
			{
				if (bazooka.check_collision(enemy2[i].x_pos, enemy2[i].y_pos) == true)
				{
					timer.x_pos += 1.3;
					sound.HitShot();
					hitCombo = true;
					effecting = false;
					enemy2[i].init((float)(950 + rand() % 200), (float)(200 + rand() % 200));
					combo.init(800, 100);
					score.SetNum(score.GetNum() + 1);
					combo.SetNum(combo.GetNum() + 1);
				}
				else if (bazooka.check_collision(lenemy2[i].x_pos, lenemy2[i].y_pos) == true)
				{
					timer.x_pos += 1.3;
					sound.HitShot();
					hitCombo = true;
					effecting = false;
					lenemy2[i].init((float)(950 + rand() % 200), (float)(200 + rand() % 200));
					combo.init(800, 100);
					score.SetNum(score.GetNum() + 1);
					combo.SetNum(combo.GetNum() + 1);
				}
			}
		}
		if (remaingrenade.GetCounter() > 0)
		{
			if (KEY_UP(VK_RBUTTON))
			{
				clock_t begin2;
				begin2 = clock();
				double i = 100;
				double j = 1000;
				double rst = 0.5;
				if ((begin2 / i) - (begin2 / j) > rst)
				{
					remaingrenade.isShooting = false;
				}
			}
			//수류탄 충돌처리
			if (KEY_DOWN(VK_RBUTTON) && remaingrenade.isShooting == false)
			{
				grenading = true;
				remaingrenade.isShooting = true;
				remaingrenade.SetCounter(remaingrenade.GetCounter() - 1);
				sound.Grenade();
				//enemy1 충돌처리
				for (int i = 0; i < ENEMY1_NUM - dNum; i++)
				{
					if (pt.x >= (enemy1[i].x_pos - 180) && pt.x <= (enemy1[i].x_pos + 240) && pt.y >= (enemy1[i].y_pos - 180) && pt.y <= (enemy1[i].y_pos +266))
					{
						timer.x_pos += 1;
						hitCombo = true;
						effecting = false;
						enemy1[i].init((float)(960 + rand() % 100), (float)(250 + rand() % 300));
						combo.init(800, 100);
						score.SetNum(score.GetNum() + 1);
						combo.SetNum(combo.GetNum() + 1);
					}
					if (pt.x >= (lenemy1[i].x_pos - 180) && pt.x <= (lenemy1[i].x_pos + 240) && pt.y >= (lenemy1[i].y_pos - 180) && pt.y <= (lenemy1[i].y_pos + 266))
					{
						timer.x_pos += 1;
						hitCombo = true;
						effecting = false;
						lenemy1[i].init((float)(0 - rand() % 100), (float)(250 + rand() % 300));
						combo.init(800, 100);
						score.SetNum(score.GetNum() + 1);
						combo.SetNum(combo.GetNum() + 1);
					}
				}
				//enemy2 충돌처리
				for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
				{
					if (pt.x >= (enemy2[i].x_pos - 180) && pt.x <= (enemy2[i].x_pos + 240) && pt.y >= (enemy2[i].y_pos - 180) && pt.y <= (enemy2[i].y_pos + 266))
					{
						timer.x_pos += 1;
						hitCombo = true;
						effecting = false;
						enemy2[i].init((float)(960 + rand() % 200), (float)(300 + rand() % 200));
						combo.init(800, 100);
						score.SetNum(score.GetNum() + 1);
						combo.SetNum(combo.GetNum() + 1);
					}
					if (pt.x >= (lenemy2[i].x_pos - 180) && pt.x <= (lenemy2[i].x_pos + 240) && pt.y >= (lenemy2[i].y_pos - 180) && pt.y <= (lenemy2[i].y_pos + 266))
					{
						timer.x_pos += 1;
						hitCombo = true;
						effecting = false;
						lenemy2[i].init((float)(0 - rand() % 100), (float)(300 + rand() % 200));
						combo.init(800, 100);
						score.SetNum(score.GetNum() + 1);
						combo.SetNum(combo.GetNum() + 1);
					}
				}
			}
		}
		//점수에 따른 enemy 등장
		if (score.GetNum() == 31)
		{
			for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
			{
				enemy2[i].appear = true;
				lenemy2[i].appear = true;
			}
		}
		else if (score.GetNum() >= 61)enemy3.appear = true;
		else if (score.GetNum() >= 91)lenemy3.appear = true;
		else if (score.GetNum() == 30)boss.Appear = true;
		//마우스 좌표얻기
		GetCursorPos(&pt);
		//윈도우화면 마우스 좌표
		ScreenToClient(hWnd, &pt);
		//마우스 충돌 구현
		if (machinegun == false) // gun_mode
		{
			//점수에 따른 오브젝트 갯수변화
			if (score.GetNum() >= 0 && score.GetNum() <= 10 )
				dNum = 5;
			else if (score.GetNum() > 10 && score.GetNum() <= 30)
				dNum = 4;
			else if (score.GetNum() > 30 && score.GetNum() <= 60)
			{
				dNum = 4;
				dNum2 = 5;
			}
			else if (score.GetNum() > 60 )
			{
				dNum = 4;
				dNum2 = 4;
			}
			effecting2 = false;
			sound.SkillEnd();
			//수류탄 아이템
			//summonitem.init(950, 750);
			//크기증가 아이템
			//summonitem2.init(900, 750);
			//크기감소 아이템
			//summonitem3.init(1000, 700);
			//총아이템 처리
			if (score.GetNum() == 20)
				summonitem.Appear = true;
			else if (score.GetNum() == 31)
				summonitem2.Appear = true;
			else if (score.GetNum() == 51)
			{
				summonitem.Appear = true;
				summonitem.init(950, 750);
			}
			else if (score.GetNum() == 61)
			{
				summonitem3.Appear = true;
				summonitem3.init(1000, 700);

			}
			else if (score.GetNum() == 71)
			{
				summonitem.Appear = true;
				summonitem.init(950, 750);
				summonitem2.Appear = true;
				summonitem2.init(900, 750);
			}
			else if (score.GetNum() == 91)
			{
				summonitem3.Appear = true;
				summonitem3.init(1000, 700);
				summonitem.Appear = true;
				summonitem.init(950, 750);
			}

			if (summonitem.Appear == true)
			{
				if (summonitem.x_pos <= 0 || summonitem.y_pos > 765)
					summonitem.Appear = false;
				else
				{
					summonitem.Update(1.0);
					summonitem.Jump();
				}
			}
			if (summonitem2.Appear == true)
			{
				if (summonitem2.x_pos <= 0 || summonitem2.y_pos > 765)
					summonitem2.Appear = false;
				else
				{
					summonitem2.Update(1.0);
					summonitem2.Jump();
				}
			}
			if (summonitem3.Appear == true)
			{
				if (summonitem3.x_pos <= 0 || summonitem3.y_pos > 765)
					summonitem3.Appear = false;
				else
				{
					summonitem3.Update(1.0);
					summonitem3.Jump();
				}
			}
			if (remainbullet.GetCounter() > 0)
			{
				if (KEY_UP(VK_LBUTTON))
				{
					clock_t begin2;
					begin2 = clock();
					double i = 100;
					double j = 1000;
					double rst = 0.5;
					if ((begin2 / i) - (begin2 / j) > rst)
					{
						remainbullet.isShooting = false;
					}
				}
				//빗맞추면 콤보 0으로 초기화
				if (effecting == true)
				{
					soldier.Show = false;
					soldier2.Show = false;
					combo.SetNum(0);
				}
				if (KEY_DOWN(VK_LBUTTON) && remainbullet.isShooting == false)
				{
					hitCombo = false;
					effecting = true;
					remainbullet.isShooting = true;
					remainbullet.SetCounter(remainbullet.GetCounter() - 1);
					sound.Shot();
					//enemy1 충돌처리
					for (int i = 0; i < ENEMY1_NUM - dNum; i++)
					{
						if (pt.x >= enemy1[i].x_pos && pt.x <= enemy1[i].x_pos + (60 * (float)scale) && pt.y >= enemy1[i].y_pos && pt.y <= enemy1[i].y_pos + (86 * (float)scale))
						{
							timer.x_pos += 1;
							sound.HitShot();
							hitCombo = true;
							effecting = false;
							enemy1[i].breaking = true;
							enemy1[i].init((float)(960 + rand() % 100), (float)(250 + rand() % 300));
							combo.init(800, 100);
							score.SetNum(score.GetNum() + 1);
							combo.SetNum(combo.GetNum() + 1);
						}
						else if (pt.x >= lenemy1[i].x_pos && pt.x <= lenemy1[i].x_pos + (60 * (float)scale) && pt.y >= lenemy1[i].y_pos && pt.y <= lenemy1[i].y_pos + (86 * (float)scale))
						{
							timer.x_pos += 1;
							sound.HitShot();
							hitCombo = true;
							effecting = false;
							lenemy1[i].breaking = true;
							lenemy1[i].init((float)(0 - rand() % 100), (float)(250 + rand() % 300));
							combo.init(800, 100);
							score.SetNum(score.GetNum() + 1);
							combo.SetNum(combo.GetNum() + 1);
						}
					}
					//enemy2 충돌처리
					for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
					{
						if (pt.x >= enemy2[i].x_pos && pt.x <= enemy2[i].x_pos + (60 * (float)scale) && pt.y >= enemy2[i].y_pos && pt.y <= enemy2[i].y_pos + (86 * (float)scale))
						{
							timer.x_pos += 1.3;
							sound.HitShot();
							hitCombo = true;
							effecting = false;
							enemy2[i].breaking = true;
							enemy2[i].init((float)(960 + rand() % 200), (float)(300 + rand() % 200));
							combo.init(800, 100);
							score.SetNum(score.GetNum() + 1);
							combo.SetNum(combo.GetNum() + 1);
						}
						else if (pt.x >= lenemy2[i].x_pos && pt.x <= lenemy2[i].x_pos + (60 * (float)scale) && pt.y >= lenemy2[i].y_pos && pt.y <= lenemy2[i].y_pos + (86 * (float)scale))
						{
							timer.x_pos += 1.3;
							sound.HitShot();
							hitCombo = true;
							effecting = false;
							lenemy2[i].breaking = true;
							lenemy2[i].init((float)(0 - rand() % 100), (float)(300 + rand() % 200));
							combo.init(800, 100);
							score.SetNum(score.GetNum() + 1);
							combo.SetNum(combo.GetNum() + 1);
						}
					}
					//수류탄 아이템 충돌처리
					if (pt.x >= summonitem.x_pos && pt.x <= summonitem.x_pos + 64 && pt.y >= summonitem.y_pos && pt.y <= summonitem.y_pos + 64)
					{
						sound.GrenadeGet();
						hitCombo = true;
						effecting = false;
						summonitem.Appear = false;
						summonitem.init(-10, 755);
						combo.init(800, 100);
						combo.SetNum(combo.GetNum() + 1);
						remaingrenade.SetCounter(remaingrenade.GetCounter() + 1);
					}
					//크기증가 아이템 충돌처리
					if (pt.x >= summonitem2.x_pos && pt.x <= summonitem2.x_pos + 64 && pt.y >= summonitem2.y_pos && pt.y <= summonitem2.y_pos + 64)
					{
						hitCombo = true;
						effecting = false;
						sound.ScaleUp();
						summonitem2.Appear = false;
						summonitem2.init(-10, 755);
						summonitem2.Giantization = true;
						combo.init(800, 100);
						combo.SetNum(combo.GetNum() + 1);
					}
					if (summonitem2.Giantization == true)
						scale = 1.4f;
					//크기감소 아이템 충돌처리
					if (pt.x >= summonitem3.x_pos && pt.x <= summonitem3.x_pos + 64 && pt.y >= summonitem3.y_pos && pt.y <= summonitem3.y_pos + 64)
					{
						hitCombo = true;
						effecting = false;
						sound.ScaleDown();
						summonitem3.Appear = false;
						summonitem3.init(-10, 755);
						summonitem3.Reduction = true;
						combo.init(800, 100);
						combo.SetNum(combo.GetNum() + 1);
					}
					if (summonitem3.Reduction == true)
						scale = 0.8f;
					else if(summonitem3.Reduction == false && summonitem2.Giantization == false)
						scale = 1.1f;
					//enemy3 충돌처리
					if (pt.x >= enemy3.x_pos && pt.x <= enemy3.x_pos + 60 && pt.y >= enemy3.y_pos && pt.y <= enemy3.y_pos + 86)
					{
						timer.x_pos -= 5;
						sound.Enemy3();
						enemy3.attack = true;
						enemy3.init((float)(960 + rand() % 100), (float)(300 + rand() % 100));
					}
					else if (pt.x >= lenemy3.x_pos && pt.x <= lenemy3.x_pos + 60 && pt.y >= lenemy3.y_pos && pt.y <= lenemy3.y_pos + 86)
					{
						timer.x_pos -= 5;
						sound.Enemy3();
						lenemy3.attack = true;
						lenemy3.init((float)(0 - rand() % 100), (float)(300 + rand() % 100));
					}
					static int hp = 10;
					//보스충돌
					if (pt.x >= boss.x_pos && pt.x <= boss.x_pos + 100 && pt.y >= boss.y_pos && pt.y <= boss.y_pos + 96)
					{
						
						hitCombo = true;
						effecting = false;
						sound.PlayerHit();
						hp -= 1;
						boss.hit = true;
						combo.init(800, 100);
						combo.SetNum(combo.GetNum() + 1);
						if (hp == 0)
						{
							boss.init(-100, 0);
							timer.x_pos += 30;
							sound.Grenade();
							boss.breaking = true;
							boss.Appear = false;
						}
					}
				}
			}
		}
		else if (machinegun == true) // machine gun_mode, 아이템 소환 없음
		{	
			sound.SkillSoundEnd();
			summonitem.Appear = false;
			summonitem2.Appear = false;
			summonitem3.Appear = false;
			scale = 1.1f;
			dNum = 2;
			dNum2 = 2;
			sound.SkillShot();
			if (KEY_UP(VK_LBUTTON))
			{
				effecting2 = true;
				//enemy1 충돌처리
				for (int i = 0; i < ENEMY1_NUM - dNum; i++)
				{
					if (pt.x >= enemy1[i].x_pos && pt.x <= enemy1[i].x_pos + (60 * (float)scale) && pt.y >= enemy1[i].y_pos && pt.y <= enemy1[i].y_pos + (86 * (float)scale))
					{
						timer.x_pos += 1;
						sound.HitShot();
						hitCombo = true;
						effecting = false;
						enemy1[i].breaking = true;
						enemy1[i].init((float)(960 + rand() % 100), (float)(250 + rand() % 300));
						score.SetNum(score.GetNum() + 1);
						combo.SetNum(combo.GetNum() + 1);
						combo.init(800, 100);
					}
					else if (pt.x >= lenemy1[i].x_pos && pt.x <= lenemy1[i].x_pos + (60 * (float)scale) && pt.y >= lenemy1[i].y_pos && pt.y <= lenemy1[i].y_pos + (86 * (float)scale))
					{
						timer.x_pos += 1;
						sound.HitShot();
						hitCombo = true;
						effecting = false;
						lenemy1[i].breaking = true;
						lenemy1[i].init((float)(0 - rand() % 100), (float)(250 + rand() % 300));
						score.SetNum(score.GetNum() + 1);
						combo.SetNum(combo.GetNum() + 1);
						combo.init(800, 100);
					}
				}
				//enemy2 충돌처리
				for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
				{
					if (pt.x >= enemy2[i].x_pos && pt.x <= enemy2[i].x_pos + (60 * (float)scale) && pt.y >= enemy2[i].y_pos && pt.y <= enemy2[i].y_pos + (86 * (float)scale))
					{
						timer.x_pos += 1.3;
						sound.HitShot();
						hitCombo = true;
						effecting = false;
						enemy2[i].breaking = true;
						enemy2[i].init((float)(950 + rand() % 200), (float)(200 + rand() % 200));
						score.SetNum(score.GetNum() + 1);
						combo.SetNum(combo.GetNum() + 1);
						combo.init(800, 100);
					}
					else if (pt.x >= lenemy2[i].x_pos && pt.x <= lenemy2[i].x_pos + (60 * (float)scale) && pt.y >= lenemy2[i].y_pos && pt.y <= lenemy2[i].y_pos + (86 * (float)scale))
					{
						timer.x_pos += 1.3;
						sound.HitShot();
						hitCombo = true;
						effecting = false;
						lenemy2[i].breaking = true;
						lenemy2[i].init((float)(950 + rand() % 200), (float)(200 + rand() % 200));
						score.SetNum(score.GetNum() + 1);
						combo.SetNum(combo.GetNum() + 1);
						combo.init(800, 100);
					}
				}
				//enemy3 충돌처리
				if (pt.x >= enemy3.x_pos && pt.x <= enemy3.x_pos + 60 && pt.y >= enemy3.y_pos && pt.y <= enemy3.y_pos + 86)
				{
					timer.x_pos -= 5;
					sound.Enemy3();
					enemy3.attack = true;
					enemy3.init((float)(940 + rand() % 100), (float)(300 + rand() % 100));
				}
				else if (pt.x >= lenemy3.x_pos && pt.x <= lenemy3.x_pos + 60 && pt.y >= lenemy3.y_pos && pt.y <= lenemy3.y_pos + 86)
				{
					timer.x_pos -= 5;
					sound.Enemy3();
					lenemy3.attack = true;
					lenemy3.init((float)(940 + rand() % 100), (float)(300 + rand() % 100));
				}
			}
		}
	}
}

void Game::cleanD3D(void)
{
	return;
}


