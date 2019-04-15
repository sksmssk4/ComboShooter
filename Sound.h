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

public:
	void Bgm();
	void bgmEnd();
	void Shot();
	void HitShot();
	void SkillShot();
	void Gird();
	void Reload();
	void SkillSound();
	
};
#endif
