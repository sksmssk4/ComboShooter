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

#include "BulletMove.h"
#include "LockMove.h"
#include "LockMove2.h"
#include "LockMove3.h"

#include "Front.h"
#include "Back.h"
#include "Bg.h"
#include "Timer.h"
#include "Remaingrenade.h"
#include "Remainbullet.h"
#include "Score.h"
#include "Combo.h"
#include "Sound.h"
#include "SummonItem.h"
#include "SummonItem2.h"
#include "SummonItem3.h"
#include "Entity.h"
#include "Soldier.h"
#include "Soldier2.h"
#include "lEnemy1.h"
#include "Enemy1.h"
#include "lEnemy2.h"
#include "Enemy2.h"
#include "lEnemy3.h"
#include "Enemy3.h"
#include "Boss.h"
#include "Bullet.h"
#include "Bazooka.h"
#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 720
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

	LPDIRECT3DTEXTURE9 sprite_opening;
	LPDIRECT3DTEXTURE9 sprite_bgEffect;
	LPDIRECT3DTEXTURE9 sprite_play;
	LPDIRECT3DTEXTURE9 sprite_quit;

	LPDIRECT3DTEXTURE9 sprite_ending;
	LPDIRECT3DTEXTURE9 sprite_gomain;
	LPDIRECT3DTEXTURE9 sprite_nextstage;

	LPDIRECT3DTEXTURE9 sprite_dz;
	LPDIRECT3DTEXTURE9 sprite_dz2;

	LPDIRECT3DTEXTURE9 sprite_frontbg;
	LPDIRECT3DTEXTURE9 sprite_backbg;
	LPDIRECT3DTEXTURE9 sprite_backbg2;
	LPDIRECT3DTEXTURE9 sprite_bg; 
	LPDIRECT3DTEXTURE9 sprite_bg2;
	LPDIRECT3DTEXTURE9 sprite_scaffolding;

	LPDIRECT3DTEXTURE9 sprite_ui;
	LPDIRECT3DTEXTURE9 sprite_lock;
	LPDIRECT3DTEXTURE9 sprite_scorebox;
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

	LPDIRECT3DTEXTURE9 sprite_combo_gage;
	LPDIRECT3DTEXTURE9 sprite_combo_text;
	LPDIRECT3DTEXTURE9 sprite_combo0;
	LPDIRECT3DTEXTURE9 sprite_combo1;
	LPDIRECT3DTEXTURE9 sprite_combo2;
	LPDIRECT3DTEXTURE9 sprite_combo3;
	LPDIRECT3DTEXTURE9 sprite_combo4;
	LPDIRECT3DTEXTURE9 sprite_combo5;
	LPDIRECT3DTEXTURE9 sprite_combo6;
	LPDIRECT3DTEXTURE9 sprite_combo7;
	LPDIRECT3DTEXTURE9 sprite_combo8;
	LPDIRECT3DTEXTURE9 sprite_combo9;

	LPDIRECT3DTEXTURE9 sprite;
	//player idle animation
	LPDIRECT3DTEXTURE9 sprite_lplayer_idle1;
	LPDIRECT3DTEXTURE9 sprite_lplayer_idle2;
	LPDIRECT3DTEXTURE9 sprite_lplayer_idle3;
	LPDIRECT3DTEXTURE9 sprite_player_idle1;
	LPDIRECT3DTEXTURE9 sprite_player_idle2;
	LPDIRECT3DTEXTURE9 sprite_rplayer_idle1;
	LPDIRECT3DTEXTURE9 sprite_rplayer_idle2;
	LPDIRECT3DTEXTURE9 sprite_rplayer_idle3;
	//player shoot animation
	LPDIRECT3DTEXTURE9 sprite_lplayer_shot;
	LPDIRECT3DTEXTURE9 sprite_player_shot;
	LPDIRECT3DTEXTURE9 sprite_rplayer_shot;
	//player skill animation
	LPDIRECT3DTEXTURE9 sprite_lplayer_skill;
	LPDIRECT3DTEXTURE9 sprite_player_skill;
	LPDIRECT3DTEXTURE9 sprite_rplayer_skill;
	//soldier animation
	LPDIRECT3DTEXTURE9 sprite_soldier1;   
	LPDIRECT3DTEXTURE9 sprite_soldier2; 
	LPDIRECT3DTEXTURE9 sprite_soldier3;
	LPDIRECT3DTEXTURE9 sprite_soldier4;
	LPDIRECT3DTEXTURE9 sprite_soldier5;
	LPDIRECT3DTEXTURE9 sprite_support;
	//soldier animation2
	LPDIRECT3DTEXTURE9 sprite_soldier2_idle;
	LPDIRECT3DTEXTURE9 sprite_soldier2_fire;
	LPDIRECT3DTEXTURE9 sprite_bazooka;
	///////////////////////////enemy1
	LPDIRECT3DTEXTURE9 sprite_enemy1;
	LPDIRECT3DTEXTURE9 sprite_enemy2;
	LPDIRECT3DTEXTURE9 sprite_enemy3;
	LPDIRECT3DTEXTURE9 sprite_enemy4;
	///////////////////////////왼쪽enemy1
	LPDIRECT3DTEXTURE9 sprite_lenemy1;
	LPDIRECT3DTEXTURE9 sprite_lenemy2;
	LPDIRECT3DTEXTURE9 sprite_lenemy3;
	LPDIRECT3DTEXTURE9 sprite_lenemy4;
	///////////////////////////enemy2
	LPDIRECT3DTEXTURE9 sprite_enemy2_1;
	LPDIRECT3DTEXTURE9 sprite_enemy2_2;
	///////////////////////////왼쪽enemy2
	LPDIRECT3DTEXTURE9 sprite_lenemy2_1;
	LPDIRECT3DTEXTURE9 sprite_lenemy2_2;
	///////////////////////////enemy3
	LPDIRECT3DTEXTURE9 sprite_enemy3_1;
	LPDIRECT3DTEXTURE9 sprite_enemy3_2;
	///////////////////////////왼쪽enemy3
	LPDIRECT3DTEXTURE9 sprite_lenemy3_1;
	LPDIRECT3DTEXTURE9 sprite_lenemy3_2;
	//bottle breaking animation
	LPDIRECT3DTEXTURE9 sprite_bBreak2;
	LPDIRECT3DTEXTURE9 sprite_bBreak;	
	LPDIRECT3DTEXTURE9 sprite_bBreak3;
	LPDIRECT3DTEXTURE9 sprite_bBreak4;
	//effect animation
	LPDIRECT3DTEXTURE9 sprite_effect1; 
	LPDIRECT3DTEXTURE9 sprite_effect2;
	LPDIRECT3DTEXTURE9 sprite_effect3;
	LPDIRECT3DTEXTURE9 sprite_effect4;
	//attack animation
	LPDIRECT3DTEXTURE9 sprite_attack1;
	LPDIRECT3DTEXTURE9 sprite_attack2;
	LPDIRECT3DTEXTURE9 sprite_attack3;
	LPDIRECT3DTEXTURE9 sprite_attack4;
	LPDIRECT3DTEXTURE9 sprite_attack5;
	//boss animation
	LPDIRECT3DTEXTURE9 sprite_boss_idle;
	LPDIRECT3DTEXTURE9 sprite_boss_hit;
	//skill animation
	LPDIRECT3DTEXTURE9 sprite_deathshower1;
	LPDIRECT3DTEXTURE9 sprite_deathshower2;
	//총알갯수판
	LPDIRECT3DTEXTURE9 sprite_bullet_full;
	LPDIRECT3DTEXTURE9 sprite_bullet_empty;
	LPDIRECT3DTEXTURE9 sprite_infinity;
	//아이템
	LPDIRECT3DTEXTURE9 sprite_itemG;
	LPDIRECT3DTEXTURE9 sprite_itemP;
	LPDIRECT3DTEXTURE9 sprite_itemM;
	//수류탄 폭발애니메이션
	LPDIRECT3DTEXTURE9 sprite_grenade;
	LPDIRECT3DTEXTURE9 sprite_grenade_num;
	LPDIRECT3DTEXTURE9 sprite_bullet;    

	UINT iTime;
	FLOAT angle;

	LockMove lockmove;
	LockMove2 lockmove2;
	LockMove3 lockmove3;

	Front front[FRONT_NUM];
	Back back[BACK_NUM];
	Bg bg[BG_NUM];
	Timer timer;
	Soldier soldier;
	Soldier2 soldier2;
	lEnemy1 lenemy1[ENEMY1_NUM];
	Enemy1 enemy1[ENEMY1_NUM];
	lEnemy2 lenemy2[ENEMY2_NUM];
	Enemy2 enemy2[ENEMY2_NUM];
	Enemy3 enemy3;
	lEnemy3 lenemy3;
	Boss boss;
	Bullet bullet;
	Bazooka bazooka;
	Sound sound;
	SummonItem summonitem;
	SummonItem2 summonitem2;
	SummonItem3 summonitem3;
	Score score;
	Combo combo;
	BulletMove bulletmove;
	Remainbullet remainbullet;
	Remaingrenade remaingrenade;
	HWND hWnd;
	float scale = 1.1f;
	int dNum = 5; //enemy1
	int dNum2 = 5; //enemy2
	bool effecting = false; //이펙트 애니메이션
	bool effecting2 = false; //이펙트 애니메이션
	bool grenading = false; //수류탄 애니메이션
	bool breaking = false; //폭발 애니메이션
	bool hitCombo = false; //콤보 출현
	bool quake = false; // 흔들림
	bool skill = false;//스킬 사운드
	bool machinegun = false;//머신건 모드
	bool support = false;
	bool support2 = false;
	bool opening = true; //opening scene
	bool ingame = false; //ingame scene1
	bool ending = false;//ending scene
public:

	void initD3D(HWND hWnd);    // sets up and initializes Direct3D
	void render_frame(void);    // renders a single frame
	void cleanD3D(void);		// closes Direct3D and releases memory

	void init_game(void);
	void do_game_logic(void);
	
};


#endif GAME_H