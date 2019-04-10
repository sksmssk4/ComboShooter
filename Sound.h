#ifndef SOUND_H
#define SOUND_H
#include <windows.h>
#include <mmsystem.h>
#include <Digitalv.h>

#pragma comment(lib, "Winmm.lib")

class Sound
{
private:
	MCI_OPEN_PARMS mci_open; // 배경음전용
	MCI_PLAY_PARMS mci_play; // 배경음전용
	int dwID;

public:
	void Bgm();
	void bgmEnd();
	void Shot();
	void HitShot();
	void Gird();
	void Reload();
};
#endif
