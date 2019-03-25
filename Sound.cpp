#include "Sound.h"

//허공샷
void Sound::Shot()
{
	sndPlaySoundA("C:\\Users\\이명현\\Desktop\\졸작파이팅!\\sound\\gun1", SND_ASYNC | SND_NODEFAULT | SND_ASYNC );		
}
//명중샷
void Sound::HitShot()
{	
	sndPlaySoundA("C:\\Users\\이명현\\Desktop\\졸작파이팅!\\sound\\gun2", SND_ASYNC | SND_NODEFAULT | SND_ASYNC);
}
