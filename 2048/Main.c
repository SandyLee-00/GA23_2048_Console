#include <stdio.h>
#include <Windows.h>
#include "Main.h"

/// <summary>
/// 전역 변수들의 선언 및 정의
/// </summary>
int g_Board[SIZE][SIZE] = { 0, };
int g_bestScore = 0;
int g_playerScore = 0;
int g_moveScore = 0;
char g_nextCommand = 0;

int main()
{
	initBoard();
	ScreenInit();

	// 랭킹 배열
	sortRanking();
	setBestScore();
	/// 버퍼 관련 초기화
	g_numOfFrame = 0;
	FPSTextInfo = (char*)malloc(sizeof(char) * 128); //
	memset(FPSTextInfo, '\0', 128);
	OldTime = clock(); // 시간을 측정한다. 1초마다 갱신한다.
	
	// playSoundBGM();

	while (1)
	{
		CurTime = clock(); // 매초 시간을 갱신한다

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			// UP 키 누르기 
			// 이동 X 합치기 X -> -1점
			g_moveScore = moveUp();
			g_playerScore += g_moveScore;
			if (g_moveScore != -1) 
			{
				addTile(); 
			}
			playSoundEffect(g_moveScore);
			setNextCommand();
			Sleep(200);
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			// DOWN 키 누르기
			// 이동 X 합치기 X -> -1점
			g_moveScore = moveDown();
			g_playerScore += g_moveScore;
			if (g_moveScore != -1)
			{
				addTile();
			}
			playSoundEffect(g_moveScore);
			setNextCommand();
			Sleep(200);
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			// LEFT 키 누르기
			// 이동 X 합치기 X -> -1점
			g_moveScore = moveLeft();
			g_playerScore += g_moveScore;
			if (g_moveScore != -1)
			{
				addTile();
			}
			playSoundEffect(g_moveScore);
			setNextCommand();
			Sleep(200);
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			// RIGHT 키 누르기
			// 이동 X 합치기 X -> -1점
			g_moveScore = moveRight();
			g_playerScore += g_moveScore;
			if (g_moveScore != -1)
			{
				addTile();
			}
			playSoundEffect(g_moveScore);
			setNextCommand();
			Sleep(200);
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			// ESC 키 누르기
			initBoard();
		}
		
		if (isGameOver() == true)
		{
			// 게임 오버
			
			//printf("Game Over!\n");
			//printf("Press ESC to restart\n");
			playSoundEffect(SOUND_LOSE);
			saveScore(g_playerScore);
			sortRanking();
			setBestScore();
			printUI();
			while (1)
			{
				/*printUI();*/
				if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
				{
					initBoard();
					break;
				}
			}
		} 

		if (isGameWin() == true)
		{
			// 게임 승리
			// printf("Game Win!\n");
			// printf("Press ESC to restart\n");
			playSoundEffect(SOUND_WIN);
			saveScore(g_playerScore);
			sortRanking();
			setBestScore();
			printUI();
			while (1)
			{
				if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
				{
					initBoard();
					break;
				}
			}
		}
		printUI(); // 안하면 게임오버 했을 때 안나온다 
		Sleep(10);
	}

	// 할당 해제 - 열심히 일했어 이제 놓아줄께
	Release();
	ScreenRelease();
}
