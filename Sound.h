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
	MCI_OPEN_PARMS mci_open3; // ����ȭ������
	MCI_PLAY_PARMS mci_play3; // ����ȭ������
	int dwID3; // ����ȭ������

	MCI_OPEN_PARMS mci_open4; // ��ų�����
	MCI_PLAY_PARMS mci_play4; // ��ų�����
	int dwID4; // ��ų�����

	MCI_OPEN_PARMS mci_open5; // �������
	MCI_PLAY_PARMS mci_play5; // �������
	int dwID5; // �������

	MCI_OPEN_PARMS mci_open6; // Ŭ��������
	MCI_PLAY_PARMS mci_play6; // Ŭ��������
	int dwID6; // Ŭ��������

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
