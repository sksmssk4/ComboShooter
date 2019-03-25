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

public:
	bool check = true;
	void Shot();
	void HitShot();
};
#endif
