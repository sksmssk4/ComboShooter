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
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mci_play);
	//�����������//mciSendCommand(3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
void Sound::bgmEnd()
{
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
//�����
void Sound::Shot()
{
	sndPlaySoundA("C:\\Users\\Administrator.MSDN-SPECIAL\\Downloads\\Shooting-Master-master\\sound\\gun2", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
		
}
//���߼�
void Sound::HitShot()
{	
	sndPlaySoundA("C:\\Users\\Administrator.MSDN-SPECIAL\\Downloads\\Shooting-Master-master\\sound\\glass_break", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//�Ѿ� ���� �� �߻�
void Sound::Gird()
{
	sndPlaySoundA("C:\\Users\\Administrator.MSDN-SPECIAL\\Downloads\\Shooting-Master-master\\sound\\gird", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//������
void Sound::Reload()
{
	sndPlaySoundA("C:\\Users\\Administrator.MSDN-SPECIAL\\Downloads\\Shooting-Master-master\\sound\\reload", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}