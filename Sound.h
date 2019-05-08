#ifndef SOUND_H
#define SOUND_H
#include <windows.h>
#include <mmsystem.h>
#include <Digitalv.h>

#pragma comment(lib, "Winmm.lib")

class Sound
{
private:
	MCI_OPEN_PARMS mci_open; // 인게임배경음
	MCI_PLAY_PARMS mci_play; // 인게임배경음
	int dwID; // 인게임배경음
	MCI_OPEN_PARMS mci_open2; // 머신건배경음
	MCI_PLAY_PARMS mci_play2; // 머신건배경음
	int dwID2; // 머신건배경음
	MCI_OPEN_PARMS mci_open3; // 시작화면배경음
	MCI_PLAY_PARMS mci_play3; // 시작화면배경음
	int dwID3; // 시작화면배경음

	MCI_OPEN_PARMS mci_open4; // 스킬배경음
	MCI_PLAY_PARMS mci_play4; // 스킬배경음
	int dwID4; // 스킬배경음

	MCI_OPEN_PARMS mci_open5; // 지원사격
	MCI_PLAY_PARMS mci_play5; // 지원사격
	int dwID5; // 지원사격

	MCI_OPEN_PARMS mci_open6; // 클리어배경음
	MCI_PLAY_PARMS mci_play6; // 클리어배경음
	int dwID6; // 클리어배경음

	MCI_OPEN_PARMS mci_open7; 
	MCI_PLAY_PARMS mci_play7; 
	int dwID7; 

public:
	void startBgm();
	void startBgmEnd();
	void Bgm();
	void bgmEnd();
	void clearBgm();
	void clearBgmEnd();
	void Enemy3();
	void Shot();
	void HitShot();
	void SkillShot();
	void SkillEnd();
	void Gird();
	void Reload();
	void SkillSound();
	void SkillSoundEnd();
	void ScaleUp();
	void ScaleDown();
	void TimeAdd();
	void Cursor();
	void Decision();
	void PlayerHit();
	void Grenade();
	void GrenadeGet();
	void SupportShoot();
	void SupportShootEnd();
	void Cytus();
	void CytusEnd();
};
#endif
