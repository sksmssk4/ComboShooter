#include "Sound.h"
//�����

void Sound::Bgm()
{
	//�����
	mci_open.lpstrElementName = L"bgm1.mp3";
	mci_open.lpstrDeviceType = L"MPEGvideo";//wav ������ ��� WaveAudio
	//����� ���
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mci_open);
	dwID = mci_open.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mci_play); // MCI_NOTIFY (������������)
	//�����������//mciSendCommand(3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
void Sound::bgmEnd()
{
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
//�����
void Sound::Shot()
{
	sndPlaySoundA("C:\\Users\\�̸���\\Desktop\\����������!\\Shooting-Master-master\\sound\\gun2", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
		
}
//���߼�
void Sound::HitShot()
{	
	sndPlaySoundA("C:\\Users\\�̸���\\Desktop\\����������!\\Shooting-Master-master\\sound\\glass_break", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//�Ѿ� ���� �� �߻�
void Sound::Gird()
{
	sndPlaySoundA("C:\\Users\\�̸���\\Desktop\\����������!\\Shooting-Master-master\\sound\\gird", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//������
void Sound::Reload()
{
	sndPlaySoundA("C:\\Users\\�̸���\\Desktop\\����������!\\Shooting-Master-master\\sound\\reload", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//��ų �߻�
void Sound::SkillShot()
{
	//�ӽŰ�
	mci_open2.lpstrElementName = L"machinegun.mp3";
	mci_open2.lpstrDeviceType = L"MPEGvideo";//wav ������ ��� WaveAudio
	//�ӽŰ� ���										
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mci_open2);
	dwID2 = mci_open2.wDeviceID;
	mciSendCommand(dwID2, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mci_play2); // MCI_DGV_PLAY_REPEAT(����)
	//�����������//mciSendCommand(3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
//��ų�ߵ���
void Sound::SkillSound()
{
	sndPlaySoundA("C:\\Users\\�̸���\\Desktop\\����������!\\Shooting-Master-master\\sound\\skillsound", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}