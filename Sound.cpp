#include "Sound.h"

//시작화면 배경음
void Sound::startBgm()
{
	//배경음
	mci_open3.lpstrElementName = L"startbgm.mp3";
	mci_open3.lpstrDeviceType = L"MPEGvideo";//wav 파일일 경우 WaveAudio
											//배경음 재생
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mci_open3);
	dwID3 = mci_open3.wDeviceID;
	mciSendCommand(dwID3, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mci_play3); // MCI_NOTIFY (루프하지않음)
	//음악재생끄기//mciSendCommand(3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
void Sound::startBgmEnd()
{
	mciSendCommand(dwID3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
//인게임 배경음
void Sound::Bgm()
{
	//배경음
	mci_open.lpstrElementName = L"bgm1.mp3";
	mci_open.lpstrDeviceType = L"MPEGvideo";//wav 파일일 경우 WaveAudio
	//배경음 재생
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mci_open);
	dwID = mci_open.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mci_play); // MCI_NOTIFY (루프하지않음)
	//음악재생끄기//mciSendCommand(3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
void Sound::bgmEnd()
{
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
//허공샷
void Sound::Shot()
{
	sndPlaySoundA("..\\Genocide\\sound\\gun2", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//명중샷
void Sound::HitShot()
{	
	sndPlaySoundA("..\\Genocide\\sound\\gun1", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//총알 없을 때 발사
void Sound::Gird()
{
	sndPlaySoundA("..\\Genocide\\sound\\gird", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//재장전
void Sound::Reload()
{
	sndPlaySoundA("..\\Genocide\\sound\\reload", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//스킬 발사
void Sound::SkillShot()
{
	//머신건
	mci_open2.lpstrElementName = L"machinegun.mp3";
	mci_open2.lpstrDeviceType = L"MPEGvideo";//wav 파일일 경우 WaveAudio
	//머신건 재생										
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mci_open2);
	dwID2 = mci_open2.wDeviceID;
	mciSendCommand(dwID2, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mci_play2); // MCI_DGV_PLAY_REPEAT(루프)
	//음악재생끄기//mciSendCommand(3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
void Sound::SkillEnd()
{
	mciSendCommand(dwID2, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
//스킬발동음
void Sound::SkillSound()
{
	//데스샤워 발동
	mci_open4.lpstrElementName = L"death.mp3";
	mci_open4.lpstrDeviceType = L"MPEGvideo";//wav 파일일 경우 WaveAudio
	//데스샤워 재생										
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mci_open4);
	dwID4 = mci_open4.wDeviceID;
	mciSendCommand(dwID4, MCI_PLAY,  MCI_NOTIFY, (DWORD)(LPVOID)&mci_play4); //MCI_DGV_PLAY_REPEAT(루프)
}
void Sound::SkillSoundEnd()
{
	//음악재생끄기//
	mciSendCommand(dwID4, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
}
//지원사격
void Sound::SupportShoot()
{
	//지원사격
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
//커서소리
void Sound::Cursor()
{
	sndPlaySoundA("..\\Genocide\\sound\\cursor", SND_ASYNC);
}
//선택소리
void Sound::Decision()
{
	sndPlaySoundA("..\\Genocide\\sound\\decision", SND_SYNC | SND_NODEFAULT | SND_SYNC);
}
//스케일업
void Sound::ScaleUp()
{
	sndPlaySoundA("..\\Genocide\\sound\\scale_up", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//스케일다운
void Sound::ScaleDown()
{
	sndPlaySoundA("..\\Genocide\\sound\\scale_down", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//시간증가
void Sound::TimeAdd()
{
	sndPlaySoundA("..\\Genocide\\sound\\timeadd", SND_SYNC | SND_NODEFAULT | SND_SYNC);
}
//플레이어 히트
void Sound::PlayerHit()
{
	sndPlaySoundA("..\\Genocide\\sound\\player_hit", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//수류탄폭발음
void Sound::Grenade()
{
	sndPlaySoundA("..\\Genocide\\sound\\grenade", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//수류탄폭발음
void Sound::GrenadeGet()
{
	sndPlaySoundA("..\\Genocide\\sound\\grenade_get", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
//enemy3
void Sound::Enemy3()
{
	sndPlaySoundA("..\\Genocide\\sound\\enemy3", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);

}