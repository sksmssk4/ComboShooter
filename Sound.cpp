#include "Sound.h"

//�����
void Sound::Shot()
{
	sndPlaySoundA("C:\\Users\\�̸���\\Desktop\\����������!\\sound\\gun1", SND_ASYNC | SND_NODEFAULT | SND_ASYNC );		
}
//���߼�
void Sound::HitShot()
{	
	sndPlaySoundA("C:\\Users\\�̸���\\Desktop\\����������!\\sound\\gun2", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
