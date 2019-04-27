#include "Game.h"
POINT pt; //마우스 포인트
int scale = 1;


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
	int iScale = 0;
	if (summonitem2.Giantization == false)
		iScale = 1;
	else if(summonitem2.Giantization == true)
		iScale = 2;
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
		640,							// default height
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
	D3DXCreateTextureFromFileEx(d3ddev,L"bg2.png",960,640,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED, 
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_bg2);
	D3DXCreateTextureFromFileEx(d3ddev, L"scaffolding.png", 960, 140, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_scaffolding);
	//스테이지 종료
	D3DXCreateTextureFromFileEx(d3ddev,L"clear.png",D3DX_DEFAULT,D3DX_DEFAULT,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_ending);
	//타이머
	D3DXCreateTextureFromFileEx(d3ddev,L"dz.png",500,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_dz);
	D3DXCreateTextureFromFileEx(d3ddev,L"dz2.png",440,22, D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_dz2);
	D3DXCreateTextureFromFileEx(d3ddev, L"dz3.png", 14, 30, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_dz3);
	//플레이어 idle 
	D3DXCreateTextureFromFileEx(d3ddev, L"player1.png", 200, 184, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_player1);
	D3DXCreateTextureFromFileEx(d3ddev, L"player2.png", 200, 184, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_player2);
	D3DXCreateTextureFromFileEx(d3ddev, L"player3.png", 200, 184, D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), NULL, NULL, &sprite_player3);
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
	//////////////////////////pistol item
	D3DXCreateTextureFromFileEx(d3ddev,L"pistol.png", D3DX_DEFAULT,D3DX_DEFAULT,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_pistol);   
	D3DXCreateTextureFromFileEx(d3ddev,L"pistol2.png",D3DX_DEFAULT,D3DX_DEFAULT,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_pistol2);	
	//////////////////////////enemy1_left
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_left1.png",60,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_lenemy1);
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_left2.png",60,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_lenemy2);
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_left3.png",60,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_lenemy3);
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_left4.png",60,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_lenemy4);
	//////////////////////////enemy1_right
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_right1.png",60 ,86 ,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy1); 
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_right2.png",60,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy2);
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_right3.png",60,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy3);
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy1_right4.png",60,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy4);
	//////////////////////////enemy2_right
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy2_right1.png",60,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy2_1);
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy2_right2.png",60,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy2_2);
	//////////////////////////enemy3_right
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy3_right1.png",60,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy3_1);
	D3DXCreateTextureFromFileEx(d3ddev,L"enemy3_right2.png",60,86,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_enemy3_2);
	//////////////////////////enemy breaking animation
	D3DXCreateTextureFromFileEx(d3ddev,L"bBreak.png",150,150,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_bBreak);	
	D3DXCreateTextureFromFileEx(d3ddev,L"bBreak2.png",150,150,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_bBreak2);	
	D3DXCreateTextureFromFileEx(d3ddev,L"bBreak3.png",150,150,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_bBreak3);	
	D3DXCreateTextureFromFileEx(d3ddev,L"bBreak4.png",150,150,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
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
	//////////////////////////blind animation
	D3DXCreateTextureFromFileEx(d3ddev,L"blind1.png",960,640,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_blind1);
	D3DXCreateTextureFromFileEx(d3ddev,L"blind2.png",960,640,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_blind2);
	D3DXCreateTextureFromFileEx(d3ddev,L"blind3.png",960,640,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_blind3);
	D3DXCreateTextureFromFileEx(d3ddev,L"blind4.png",960,640,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_blind4);
	//////////////////////////총알갯수판
	D3DXCreateTextureFromFileEx(d3ddev,L"line.png",80,50,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_line);
	//////////////////////////총 아이템 
	D3DXCreateTextureFromFileEx(d3ddev,L"itemG.png",64,64,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_itemG);
	//////////////////////////증가 아이템
	D3DXCreateTextureFromFileEx(d3ddev,L"itemP.png",64,64,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_itemP);
	//////////////////////////감소 아이템
	D3DXCreateTextureFromFileEx(d3ddev,L"itemM.png",64,64,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_itemM);
	//총알 스프라이트
	D3DXCreateTextureFromFileEx(d3ddev,L"bullet.png",D3DX_DEFAULT,D3DX_DEFAULT,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_bullet);   
	/////////////////////////.스킬발동애니메이션
	D3DXCreateTextureFromFileEx(d3ddev,L"death_shower.png",400,400,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_deathshower1);
	D3DXCreateTextureFromFileEx(d3ddev,L"death_shower2.png",400,400,D3DX_DEFAULT,NULL,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,
		D3DX_DEFAULT,D3DX_DEFAULT,D3DCOLOR_XRGB(255, 0, 255),NULL,NULL,&sprite_deathshower2);
	return;
}
void Game::render_frame(void)
{
	if (ingame == true)
	{
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

		//배경
		RECT part0; SetRect(&part0, 0, 0, 960, 640); D3DXVECTOR3 center0(0.0f, 0.0f, 0.0f);
		static int bCounter = 0;
		bCounter += 1;
		if (bCounter >= 10) bCounter = 0;
		for (int i = 0; i < BG_NUM; i++)
		{
			D3DXVECTOR3 position0(bg[i].x_pos, bg[i].y_pos, 0.0f);
			
			switch (bCounter / 5)
			{
			case 0:
				d3dspt->Draw(sprite_bg, &part0, &center0, &position0, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				d3dspt->Draw(sprite_bg2, &part0, &center0, &position0, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		RECT part1; SetRect(&part1, 0, 0, 960, 140); D3DXVECTOR3 center1(0.0f, 0.0f, 0.0f);
		for (int i = 0; i < BG_NUM; i++)
		{
			D3DXVECTOR3 position1(bg[i].x_pos, 500.0f, 0.0f);
			d3dspt->Draw(sprite_scaffolding, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		//플레이어 idle
		RECT Ppart; SetRect(&Ppart, 0, 0, 200, 184); D3DXVECTOR3 Pcenter(0.0f, 0.0f, 0.0f); D3DXVECTOR3 Pposition(390.0f, 500.0f, 0.0f);
		static int pCounter = 0;
		pCounter += 1;
		if (pCounter >= 15) pCounter = 0;
		switch (pCounter/5)
		{
		case 0:
			d3dspt->Draw(sprite_player1, &Ppart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 1:
			d3dspt->Draw(sprite_player2, &Ppart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		case 2:
			d3dspt->Draw(sprite_player3, &Ppart, &Pcenter, &Pposition, D3DCOLOR_ARGB(255, 255, 255, 255));
			break;
		}
		//타이머
		RECT dpart0;SetRect(&dpart0, 0, 0, 500, 86);D3DXVECTOR3 dcenter0(0.0f, 0.0f, 0.0f);D3DXVECTOR3 dposition0(50.0f, 30.0f, 0.0f);
		d3dspt->Draw(sprite_dz, &dpart0, &dcenter0, &dposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		//타이머(깎이는)
		RECT dpart1;SetRect(&dpart1, 0, 0, 420-(timer.rst1), 22);D3DXVECTOR3 dcenter1(0.0f, 0.0f, 0.0f);D3DXVECTOR3 dposition1(125.0f, 60.0f, 0.0f);
		d3dspt->Draw(sprite_dz2, &dpart1, &dcenter1, &dposition1, D3DCOLOR_ARGB(255, 255, 255, 255));
		//타이머(움직이는)
		RECT dpart2;SetRect(&dpart2, 0, 0, 14, 30);D3DXVECTOR3 dcenter2(0.0f, 0.0f, 0.0f);D3DXVECTOR3 dposition2(timer.x_pos, 55.0f, 0.0f);
		d3dspt->Draw(sprite_dz3, &dpart2, &dcenter2, &dposition2, D3DCOLOR_ARGB(255, 255, 255, 255));
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
		//총알갯수판
		RECT Bpart0;SetRect(&Bpart0, 0, 0, 80, 50);D3DXVECTOR3 Bcenter0(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Bposition0(310, 520, 0.0f);
		d3dspt->Draw(sprite_line, &Bpart0, &Bcenter0, &Bposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
		//총알 갯수
		RECT Bpart;SetRect(&Bpart, 0, 0, 25, 40);D3DXVECTOR3 Bcenter(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Bposition(315, 525, 0.0f);
		RECT Bpart1;SetRect(&Bpart1, 0, 0, 25, 40);D3DXVECTOR3 Bcenter1(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Bposition1(355, 525, 0.0f);
		//Max bullet
		d3dspt->Draw(sprite_score5, &Bpart1, &Bcenter1, &Bposition1, D3DCOLOR_ARGB(255, 255, 255, 255));
		//Remain bullet
		if (remainbullet.GetCounter() == 0)
		{
			d3dspt->Draw(sprite_score0, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		else if (remainbullet.GetCounter() == 1)
		{
			d3dspt->Draw(sprite_score1, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		else if (remainbullet.GetCounter() == 2)
		{
			d3dspt->Draw(sprite_score2, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		else if (remainbullet.GetCounter() == 3)
		{
			d3dspt->Draw(sprite_score3, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		else if (remainbullet.GetCounter() == 4)
		{
			d3dspt->Draw(sprite_score4, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		else if (remainbullet.GetCounter() == 5)
		{
			d3dspt->Draw(sprite_score5, &Bpart, &Bcenter, &Bposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////스코어
		if (score.GetNum() % 10 == 0)
			d3dspt->Draw(sprite_score0, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
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

		if (score.GetNum() >= 10 && score.GetNum() < 20)
			d3dspt->Draw(sprite_score1, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 20 && score.GetNum() < 30)
			d3dspt->Draw(sprite_score2, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 30 && score.GetNum() < 40)
			d3dspt->Draw(sprite_score3, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 40 && score.GetNum() < 50)
			d3dspt->Draw(sprite_score4, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 50 && score.GetNum() < 60)
			d3dspt->Draw(sprite_score5, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 60 && score.GetNum() < 70)
			d3dspt->Draw(sprite_score6, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 70 && score.GetNum() < 80)
			d3dspt->Draw(sprite_score7, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 80 && score.GetNum() < 90)
			d3dspt->Draw(sprite_score8, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 90 && score.GetNum() < 100)
			d3dspt->Draw(sprite_score9, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		
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

			if (combo.GetNum() >= 10 && combo.GetNum() < 20)
				d3dspt->Draw(sprite_combo1, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() >= 20 && combo.GetNum() < 30)
				d3dspt->Draw(sprite_combo2, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() >= 30 && combo.GetNum() < 40)
				d3dspt->Draw(sprite_combo3, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() >= 40 && combo.GetNum() < 50)
				d3dspt->Draw(sprite_combo4, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() >= 50 && combo.GetNum() < 60)
				d3dspt->Draw(sprite_combo5, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() >= 60 && combo.GetNum() < 70)
				d3dspt->Draw(sprite_combo6, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() >= 70 && combo.GetNum() < 80)
				d3dspt->Draw(sprite_combo7, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() >= 80 && combo.GetNum() < 90)
				d3dspt->Draw(sprite_combo8, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
			else if (combo.GetNum() >= 90 && combo.GetNum() < 100)
				d3dspt->Draw(sprite_combo9, &Cpart10, &Ccenter10, &Cposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
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
		//이펙트 애니메이션
		if (effecting == true)
		{
			RECT Epart;SetRect(&Epart, 0, 0, 150, 150);D3DXVECTOR3 Ecenter(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Eposition(pt.x - 60, pt.y - 75, 0.0f);
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
		//P(pistol)아이템 먹음
		if (pistol.pCheck == true)
		{
			//P(pistol)이 나옴
			if (pistol.pShow == true)
			{
				RECT part;SetRect(&part, 0, 0, 100, 63);D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);D3DXVECTOR3 position(pistol.x_pos, pistol.y_pos, 0.0f);
				d3dspt->Draw(sprite_pistol, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
			}
			//Pistol Fire!
			if (pistol.pShow == false)
			{
				RECT part;SetRect(&part, 0, 0, 115, 63);D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);D3DXVECTOR3 position(pistol.x_pos, pistol.y_pos, 0.0f);
				d3dspt->Draw(sprite_pistol2, &part, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
				pistol.pShow = true;
			}
			//bullet
			if (bullet.bShow == true)
			{
				RECT part1;SetRect(&part1, 0, 0, 30, 14);D3DXVECTOR3 center1(0.0f, 0.0f, 0.0f);D3DXVECTOR3 position1(bullet.x_pos, bullet.y_pos, 0.0f);
				d3dspt->Draw(sprite_bullet, &part1, &center1, &position1, D3DCOLOR_ARGB(255, 255, 255, 255));
			}
		}
		//P(pistol) 소환아이템 등장
		if (summonitem.Appear == true)
		{
			RECT rc;
			SetRect(&rc, 0, 0, 64, 64);
			D3DXVECTOR2 spriteCenter = D3DXVECTOR2(32, 32);
			D3DXVECTOR2 translate = D3DXVECTOR2(summonitem.x_pos, summonitem.y_pos);
			//회전 속도
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
		//크기증가 아이템
		if (summonitem2.Appear == true)
		{
			RECT rc;
			SetRect(&rc, 0, 0, 64, 64);
			D3DXVECTOR2 spriteCenter = D3DXVECTOR2(32, 32);
			D3DXVECTOR2 translate = D3DXVECTOR2(summonitem2.x_pos, summonitem2.y_pos);

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
			espt->Draw(sprite_itemP, NULL, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
		}
		//enemy3_right
		if (enemy3.attack == false && enemy3.appear == true)
		{
			static int eAcounter3 = 0;
			eAcounter3 += 1;
			if (eAcounter3 >= 2)
				eAcounter3 = 0;
			RECT Rpart3;SetRect(&Rpart3, 0, 0, 60 * (int)scale, 86 * (int)scale);D3DXVECTOR3 Rcenter3(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Rposition3(enemy3.x_pos, enemy3.y_pos, 0.0f);
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
			if (aAcounter >= 15)
			{
				aAcounter = 0;
				enemy3.attack = false;
				enemy3.blind = true;
			}
			
			switch (aAcounter)
			{
			case 1:case 2:case 3:
				d3dspt->Draw(sprite_attack1, &Apart1, &Acenter, &Aposition1, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 4:case 5:case 6:
				d3dspt->Draw(sprite_attack2, &Apart2, &Acenter, &Aposition2, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 7:case 8:case 9:
				d3dspt->Draw(sprite_attack3, &Apart3, &Acenter, &Aposition3, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 10:case 11:case 12:case 13:case 14:
				d3dspt->Draw(sprite_attack4, &Apart4, &Acenter, &Aposition4, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
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
				SetRect(&rc, 0, 0, 64, 64);

				D3DXVECTOR2 spriteCenter = D3DXVECTOR2(32, 32);
				// Screen position of the sprite
				D3DXVECTOR2 translate = D3DXVECTOR2(enemy2[i].x_pos, enemy2[i].y_pos);
				// Scaling X,Y

				iTime = timeGetTime() % 500;
				if (enemy2[i].miss == false)
					angle = 0;
				else if (enemy2[i].miss == true)
					angle = iTime * (2.0f * D3DX_PI) / 500.0f;
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
		static int eAcounter = 0;
		eAcounter += 1;
		if (eAcounter >= 4)
			eAcounter = 0;
		////enemy1_left
		for (int i = 0; i < LENEMY1_NUM - dNum; i++)
		{
			RECT Lpart;
			SetRect(&Lpart, 0, 0, 60 * (int)scale, 86 * (int)scale);
			D3DXVECTOR3 Lcenter(0.0f, 0.0f, 0.0f);
			D3DXVECTOR3 Lposition(lenemy1[i].x_pos, lenemy1[i].y_pos, 0.0f);
			switch (eAcounter)
			{
			case 0:
				d3dspt->Draw(sprite_lenemy1, &Lpart, &Lcenter, &Lposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				d3dspt->Draw(sprite_lenemy2, &Lpart, &Lcenter, &Lposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 2:
				d3dspt->Draw(sprite_lenemy3, &Lpart, &Lcenter, &Lposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 3:
				d3dspt->Draw(sprite_lenemy4, &Lpart, &Lcenter, &Lposition, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
		}
		////enemy1_right
		for (int i = 0; i < ENEMY1_NUM - dNum; i++)
		{
			RECT Rpart;
			SetRect(&Rpart, 0, 0, 60 * (int)scale, 86 * (int)scale);
			D3DXVECTOR3 center(0.0f, 0.0f, 0.0f);
			D3DXVECTOR3 position(enemy1[i].x_pos, enemy1[i].y_pos, 0.0f);
			switch (eAcounter)
			{
			case 0:
				d3dspt->Draw(sprite_enemy1, &Rpart, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 1:
				d3dspt->Draw(sprite_enemy2, &Rpart, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 2:
				d3dspt->Draw(sprite_enemy3, &Rpart, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 3:
				d3dspt->Draw(sprite_enemy4, &Rpart, &center, &position, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			}
			//enemy1_breaking animation;
			if (breaking == true && effecting == false)
			{
				RECT part1;
				SetRect(&part1, 0, 0, 150 * (int)scale, 150 * (int)scale);
				D3DXVECTOR3 center1(0.0f, 0.0f, 0.0f);
				D3DXVECTOR3 position1(pt.x - 60, pt.y - 75, 0.0f); //애니메이션 좌표 = 마우스좌표

				static int acounter = 0;
				acounter++;
				if (acounter >= 4)
				{
					acounter = 0;
					breaking = false;
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
		}
		if (enemy3.blind == true)
		{
			static int aAcounter2 = 0;
			aAcounter2++;
			if (aAcounter2 >= 8)
				aAcounter2 = 0;
			RECT Apart3;
			SetRect(&Apart3, 0, 0, 960, 640);
			D3DXVECTOR3 Acenter(0.0f, 0.0f, 0.0f);
			D3DXVECTOR3 Aposition3(0.0f, 0.0f, 0.0f);
			switch (aAcounter2)
			{
			case 0: case 1:
				d3dspt->Draw(sprite_blind1, &Apart3, &Acenter, &Aposition3, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 2: case 3:
				d3dspt->Draw(sprite_blind2, &Apart3, &Acenter, &Aposition3, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 4: case 5:
				d3dspt->Draw(sprite_blind3, &Apart3, &Acenter, &Aposition3, D3DCOLOR_ARGB(255, 255, 255, 255));
				break;
			case 6: case 7:
				d3dspt->Draw(sprite_blind4, &Apart3, &Acenter, &Aposition3, D3DCOLOR_ARGB(255, 255, 255, 255));
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
	if (ending == true)
	{
		sound.bgmEnd();
		sound.SkillEnd();
		d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), -1.0f, 0);
		d3ddev->BeginScene();
		d3dspt->Begin(D3DXSPRITE_ALPHABLEND);
		// clear 배경
		RECT ipart;SetRect(&ipart, 0, 0, 960, 640);D3DXVECTOR3 icenter(0.0f, 0.0f, 0.0f);D3DXVECTOR3 iposition(0.0f, 0.0f, 0.0f);
		d3dspt->Draw(sprite_ending, &ipart, &icenter, &iposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		//기본
		RECT Spart;SetRect(&Spart, 0, 0, 85, 120);D3DXVECTOR3 Scenter(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Sposition(670, 350, 0.0f);
		d3dspt->Draw(sprite_combo0, &Spart, &Scenter, &Sposition, D3DCOLOR_ARGB(255, 255, 255, 255));
		//10의자리
		RECT Spart0;SetRect(&Spart0, 0, 0, 85, 120);D3DXVECTOR3 Scenter0(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Sposition0(585, 350, 0.0f);
		//100의 자리
		RECT Spart10;SetRect(&Spart10, 0, 0, 85, 120);D3DXVECTOR3 Scenter10(0.0f, 0.0f, 0.0f);D3DXVECTOR3 Sposition10(500, 350, 0.0f);
		
		//스코어
		if (score.GetNum() % 10 == 0)
			d3dspt->Draw(sprite_combo0, &Spart0, &Scenter0, &Sposition0, D3DCOLOR_ARGB(255, 255, 255, 255));
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

		if (score.GetNum() >= 10 && score.GetNum() < 20)
			d3dspt->Draw(sprite_combo1, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 20 && score.GetNum() < 30)
			d3dspt->Draw(sprite_combo2, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 30 && score.GetNum() < 40)
			d3dspt->Draw(sprite_combo3, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 40 && score.GetNum() < 50)
			d3dspt->Draw(sprite_combo4, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 50 && score.GetNum() < 60)
			d3dspt->Draw(sprite_combo5, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 60 && score.GetNum() < 70)
			d3dspt->Draw(sprite_combo6, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 70 && score.GetNum() < 80)
			d3dspt->Draw(sprite_combo7, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 80 && score.GetNum() < 90)
			d3dspt->Draw(sprite_combo8, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));
		else if (score.GetNum() >= 90 && score.GetNum() < 100)
			d3dspt->Draw(sprite_combo9, &Spart10, &Scenter10, &Sposition10, D3DCOLOR_ARGB(255, 255, 255, 255));

		d3dspt->End();

		d3ddev->EndScene();

		d3ddev->Present(NULL, NULL, NULL, NULL);
		return;
	}
}
void Game::init_game(void)
{
	//배경 초기화
	bg[0].init(0.0f, 0.0f);
	bg[1].init(0.0f,SCREEN_HEIGHT);
	//타이머 오브젝트 초기화
	timer.init(300,50);
	//스코어 초기화
	score.init(880, 40);
	//콤보 초기화
	combo.init(800, 100);
	//P(pistol)아이템 초기화
	pistol.init(80, 60);
	//오브젝트 초기화
	for (int i = 0; i < ENEMY1_NUM - dNum; i++)
		enemy1[i].init((float)(960 + rand() % 100),(float)(300 + rand() % 200));
	for (int i = 0; i < LENEMY1_NUM - dNum; i++)
		lenemy1[i].init((float)(0 - rand() % 100), (float)(300 + rand() % 200));
	for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
	{
		if(enemy2[i].appear == true)enemy2[i].init((float)(950 + rand() % 200), (float)(200 + rand() % 200));
	}
	if(enemy3.appear == true)enemy3.init((float)(960 + rand() % 100), (float)(300 + rand() % 200));

	//P(pistol)아이템의 총알
	bullet.init(pistol.x_pos, pistol.y_pos);
	//P(pistol) 소환 아이템
	summonitem.init(600, 750);
	//summonitem2.init(650, 750);
}
void Game::do_game_logic(void)
{
	if (ending == true)
	{
		ingame = false;
	}
	if (ingame == true)
	{
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
				bg[i].shake();
			bg[i].init(bg[i].x_pos, bg[i].y_pos);
			bg[i].y_pos;
			bg[i].move();
		}

		//콤보
		if (hitCombo == true)
			combo.shake();
		
		//점수에 따른 오브젝트 갯수변화
		if (score.GetNum() == 5)dNum = 5;
		else if (score.GetNum() == 20)
		{
			for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
				enemy2[i].appear = true;
			dNum2 = 4;
			dNum = 4;
		}
		else if (score.GetNum() == 50)
		{
			enemy3.appear = true;
			dNum2 = 3;
			dNum = 3;
		}
		else if (score.GetNum() == 70)dNum = 2;
		else if (score.GetNum() == 90)dNum = 1;
		//총알 개수 0일 때
		if (remainbullet.GetCounter() == 0)
		{
			if (KEY_DOWN(VK_LBUTTON))
				sound.Gird();
		}
		if (KEY_DOWN(VK_SPACE))
		{
			sound.Reload();
			remainbullet.SetCounter(5);
		}
		if (KEY_DOWN(VK_DELETE))
		{
			sound.SkillSound();
			skill = true;
		}
		//enemy1
		for (int i = 0; i < ENEMY1_NUM - dNum; i++)
		{
			if (enemy1[i].x_pos <= 0 || enemy1[i].y_pos > 755)
				enemy1[i].init((float)(950 + rand() % 200), (float)(200 + rand() % 300));
			else
				enemy1[i].move();
		}
		for (int i = 0; i < LENEMY1_NUM - dNum; i++)
		{
			if (lenemy1[i].x_pos >= 960 || lenemy1[i].y_pos > 755 || lenemy1[i].x_pos == 0)
				lenemy1[i].init((float)(1 + rand() % 50), (float)(200 + rand() % 300));
			else
				lenemy1[i].move();
		}
		//enemy2
		for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
		{
			enemy2[i].movePattern();
			if (enemy2[i].x_pos <= 0 || enemy2[i].y_pos > 755)
				enemy2[i].init((float)(950 + rand() % 200), (float)(200 + rand() % 200));
			else if (enemy2[i].miss == false)
				enemy2[i].move();
			else if (enemy2[i].miss == true)
				enemy2[i].move2();
		}
		//enemy3
		if (enemy3.x_pos <= 0 || enemy3.y_pos > 755)
			enemy3.init((float)(940 + rand() % 100), (float)(300 + rand() % 100));
		else
			enemy3.move();
		//총아이템 처리
		if (pistol.pCheck == true)
		{
			pistol.move();
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
			for (int i = 0; i < ENEMY1_NUM - dNum; i++)
			{
				//충돌 처리 
				if (bullet.check_collision(enemy1[i].x_pos, enemy1[i].y_pos) == true)
				{
					sound.HitShot();
					breaking = true;
					enemy1[i].init((float)(960 + rand() % 100), (float)(300 + rand() % 200));
					score.SetNum(score.GetNum() + 1);
				}
			}
		}
		//마우스 좌표얻기
		GetCursorPos(&pt);
		//윈도우화면 마우스 좌표
		ScreenToClient(hWnd, &pt);
		//마우스 충돌 구현
		if (machinegun == false) // gun_mode
		{
			//총아이템 처리
			if (score.GetNum() == 5)
			{
				summonitem.Appear = true;
			}
			else if (score.GetNum() == 15)
			{
				summonitem.Appear = true;
				summonitem.init(600, 750);
			}
			if (summonitem.Appear == true)
			{
				if (summonitem.x_pos < 0 || summonitem.y_pos > 755)
					summonitem.Appear = false;
				else
				{
					summonitem.Update(1.0);
					summonitem.Jump();
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
					combo.SetNum(0);
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
						if (pt.x >= enemy1[i].x_pos && pt.x <= enemy1[i].x_pos + 60 && pt.y >= enemy1[i].y_pos && pt.y <= enemy1[i].y_pos + 86)
						{
							timer.x_pos += 2;
							sound.HitShot();
							hitCombo = true;
							effecting = false;
							breaking = true;
							enemy1[i].init((float)(960 + rand() % 100), (float)(300 + rand() % 200));
							combo.init(800, 100);
							score.SetNum(score.GetNum() + 1);
							combo.SetNum(combo.GetNum() + 1);
						}
					}
					//왼쪽enemy1 충돌처리
					for (int i = 0; i < LENEMY1_NUM - dNum; i++)
					{
						if (pt.x >= lenemy1[i].x_pos && pt.x <= lenemy1[i].x_pos + 60 && pt.y >= lenemy1[i].y_pos && pt.y <= lenemy1[i].y_pos + 86)
						{
							timer.x_pos += 2;
							sound.HitShot();
							hitCombo = true;
							effecting = false;
							breaking = true;
							lenemy1[i].init((float)(0 - rand() % 100), (float)(300 + rand() % 200));
							combo.init(800, 100);
							score.SetNum(score.GetNum() + 1);
							combo.SetNum(combo.GetNum() + 1);
						}
					}
					//enemy2 충돌처리
					for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
					{
						if (pt.x >= enemy2[i].x_pos && pt.x <= enemy2[i].x_pos + 60 && pt.y >= enemy2[i].y_pos && pt.y <= enemy2[i].y_pos + 86)
						{
							timer.x_pos += 2;
							sound.HitShot();
							hitCombo = true;
							effecting = false;
							breaking = true;
							enemy2[i].init((float)(950 + rand() % 200), (float)(200 + rand() % 200));
							combo.init(800, 100);
							score.SetNum(score.GetNum() + 1);
							combo.SetNum(combo.GetNum() + 1);
						}
					}
					if (pt.x >= summonitem.x_pos && pt.x <= summonitem.x_pos + 64 && pt.y >= summonitem.y_pos && pt.y <= summonitem.y_pos + 64)
					{
						summonitem.Appear = false;
						summonitem.init(600, 750);
					}
					//enemy3 충돌처리
					if (pt.x >= enemy3.x_pos && pt.x <= enemy3.x_pos + 60 && pt.y >= enemy3.y_pos && pt.y <= enemy3.y_pos + 86)
					{
						sound.HitShot();
						enemy3.attack = true;
						enemy3.init((float)(940 + rand() % 100), (float)(300 + rand() % 100));
					}
					static int HP = 3;
					if (enemy3.blind == true)
					{
						sound.HitShot();
						if (pt.x >= 320 && pt.x <= 640 && pt.y >= 0 && pt.y <= 600)
						{
							HP -= 1;
						}
						if (HP == 0)
						{
							enemy3.blind = false;
							HP = 3;
						}
					}
				}
			}
		}
		else if (machinegun == true) // machine gun_mode, 아이템 소환 없음
		{	
			sound.SkillShot();
			if (KEY_UP(VK_LBUTTON))
			{
				effecting = true;
				//enemy1 충돌처리
				for (int i = 0; i < ENEMY1_NUM - dNum; i++)
				{
					if (pt.x >= enemy1[i].x_pos && pt.x <= enemy1[i].x_pos + 60 && pt.y >= enemy1[i].y_pos && pt.y <= enemy1[i].y_pos + 86)
					{
						sound.HitShot();
						hitCombo = true;
						effecting = false;
						breaking = true;
						enemy1[i].init((float)(960 + rand() % 100), (float)(300 + rand() % 200));
						score.SetNum(score.GetNum() + 1);
						combo.SetNum(combo.GetNum() + 1);
						combo.init(800, 100);
					}
					
				}
				//왼쪽 enemy1 충돌처리
				for (int i = 0; i < LENEMY1_NUM - dNum; i++)
				{
					if (pt.x >= lenemy1[i].x_pos && pt.x <= lenemy1[i].x_pos + 60 && pt.y >= lenemy1[i].y_pos && pt.y <= lenemy1[i].y_pos + 86)
					{
						sound.HitShot();
						hitCombo = true;
						effecting = false;
						breaking = true;
						lenemy1[i].init((float)(0 - rand() % 100), (float)(300 + rand() % 200));
						score.SetNum(score.GetNum() + 1);
						combo.SetNum(combo.GetNum() + 1);
						combo.init(800, 100);
					}
				}
				//enemy2 충돌처리
				for (int i = 0; i < ENEMY2_NUM - dNum2; i++)
				{
					if (pt.x >= enemy2[i].x_pos && pt.x <= enemy2[i].x_pos + 60 && pt.y >= enemy2[i].y_pos && pt.y <= enemy2[i].y_pos + 86)
					{
						sound.HitShot();
						hitCombo = true;
						effecting = false;
						breaking = true;
						enemy2[i].init((float)(950 + rand() % 200), (float)(200 + rand() % 200));
						score.SetNum(score.GetNum() + 1);
						combo.SetNum(combo.GetNum() + 1);
						combo.init(800, 100);
					}
				}
				//enemy3 충돌처리
				if (pt.x >= enemy3.x_pos && pt.x <= enemy3.x_pos + 60 && pt.y >= enemy3.y_pos && pt.y <= enemy3.y_pos + 86)
				{
					sound.HitShot();
					enemy3.attack = true;
					enemy3.init((float)(940 + rand() % 100), (float)(300 + rand() % 100));
				}

				if (enemy3.blind == true)
				{
					
					sound.HitShot();
					static int HP = 3;
					if (pt.x >= 320 && pt.x <= 640 && pt.y >= 0 && pt.y <= 600)
						HP -= 1;
					if (HP == 0)
					{
						enemy3.blind = false;
						HP = 3;
					}
				}
			}
		}
	}
}


void Game::cleanD3D(void)
{
	return;
}


