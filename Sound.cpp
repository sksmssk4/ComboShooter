#include "Sound.h"

//����ȭ�� �����
void Sound::startBgm()
{
	//�����
	mci_open3.lpstrElementName = L"startbgm.mp3";
	mci_open3.lpstrDeviceType = L"MPEGvideo";//wav ������ ��� WaveAudio
											//����� ���
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mci_open3);
	dwID3 = mci_open3.wDeviceID;
	mciSendCommand(dwID3, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mci_play3); // MCI_NOTIFY (������������)
	//�����������//mciSendCommand(3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
void Sound::startBgmEnd()
{
	mciSendCommand(dwID3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
//�ΰ��� �����
void Sound::Bgm()
{
	//�����
	mci_open.lpstrElementName = L"bgm1.mp3";
	mci_open.lpstrDeviceType = L"MPEGvideo";//wav ������ ��� WaveAudio
	//����� ���
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mci_open);
	dwID = mci_open.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mci_play); // MCI_NOTIFY (������������)
	//�����������//mciSendCommand(3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
void Sound::bgmEnd()
{
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
//�����
void Sound::Shot()
{
	sndPlaySoundA("..\\Genocide\\sound\\gun2", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//���߼�
void Sound::HitShot()
{	
	sndPlaySoundA("..\\Genocide\\sound\\gun1", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//�Ѿ� ���� �� �߻�
void Sound::Gird()
{
	sndPlaySoundA("..\\Genocide\\sound\\gird", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//������
void Sound::Reload()
{
	sndPlaySoundA("..\\Genocide\\sound\\reload", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
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
void Sound::SkillEnd()
{
	mciSendCommand(dwID2, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
//��ų�ߵ���
void Sound::SkillSound()
{
	//�������� �ߵ�
	mci_open4.lpstrElementName = L"death.mp3";
	mci_open4.lpstrDeviceType = L"MPEGvideo";//wav ������ ��� WaveAudio
	//�������� ���										
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mci_open4);
	dwID4 = mci_open4.wDeviceID;
	mciSendCommand(dwID4, MCI_PLAY,  MCI_NOTIFY, (DWORD)(LPVOID)&mci_play4); //MCI_DGV_PLAY_REPEAT(����)
}
void Sound::SkillSoundEnd()
{
	//�����������//
	mciSendCommand(dwID4, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
//�������
void Sound::SupportShoot()
{
	//�������
	mci_open5.lpstrElementName = L"supportshoot.mp3";
	mci_open5.lpstrDeviceType = L"MPEGvideo";									
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mci_open5);
	dwID5 = mci_open5.wDeviceID;
	mciSendCommand(dwID5, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mci_play5);
}
void Sound::SupportShootEnd()
{
	mciSendCommand(dwID5, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
//Ŀ���Ҹ�
void Sound::Cursor()
{
	sndPlaySoundA("..\\Genocide\\sound\\cursor", SND_ASYNC);
}
//���üҸ�
void Sound::Decision()
{
	sndPlaySoundA("..\\Genocide\\sound\\decision", SND_SYNC | SND_NODEFAULT | SND_SYNC);
}
//�����Ͼ�
void Sound::ScaleUp()
{
	sndPlaySoundA("..\\Genocide\\sound\\scale_up", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//�����ϴٿ�
void Sound::ScaleDown()
{
	sndPlaySoundA("..\\Genocide\\sound\\scale_down", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//�ð�����
void Sound::TimeAdd()
{
	sndPlaySoundA("..\\Genocide\\sound\\timeadd", SND_SYNC | SND_NODEFAULT | SND_SYNC);
}
//�÷��̾� ��Ʈ
void Sound::PlayerHit()
{
	sndPlaySoundA("..\\Genocide\\sound\\player_hit", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//����ź������
void Sound::Grenade()
{
	sndPlaySoundA("..\\Genocide\\sound\\grenade", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//����ź������
void Sound::GrenadeGet()
{
	sndPlaySoundA("..\\Genocide\\sound\\grenade_get", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//enemy3
void Sound::Enemy3()
{
	sndPlaySoundA("..\\Genocide\\sound\\enemy3", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);

}