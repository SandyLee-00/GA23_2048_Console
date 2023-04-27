#include "Sound.h"

void playSoundEffect(int soundIdx)
{

	// -1 -> SOUND_ERROR
	// 0 -> SOUND_MOVE
	// > 0 -> SOUND_MERGE
	// 9999 -> SOUND_WIN
	// 9998 -> SOUND_LOSE

	if (soundIdx == SOUND_ERROR)
	{
		PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return;
	}
	else if (soundIdx == SOUND_MOVE)
	{
		PlaySound(TEXT("move.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return;
	}
	else if (soundIdx > 0 && soundIdx < 8000)
	{
		PlaySound(TEXT("merge.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return;
	}
	else if (soundIdx == SOUND_WIN)
	{
		PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return;
	}
	else if (soundIdx == SOUND_LOSE)
	{
		PlaySound(TEXT("lose.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return;
	}

}

void playSoundBGM()
{
	PlaySound(TEXT("bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}