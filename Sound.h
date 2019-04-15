#ifndef SOUND_H
#define SOUND_H
#include <windows.h>
#include <mmsystem.h>
#include <Digitalv.h>

#pragma comment(lib, "Winmm.lib")

class Sound
{
private:
	MCI_OPEN_PARMS mci_open; // �ΰ��ӹ����
	MCI_PLAY_PARMS mci_play; // �ΰ��ӹ����
	int dwID; // �ΰ��ӹ����
	MCI_OPEN_PARMS mci_open2; // �ӽŰǹ����
	MCI_PLAY_PARMS mci_play2; // �ӽŰǹ����
	int dwID2; // �ӽŰǹ����

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
