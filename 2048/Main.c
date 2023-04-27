#include <stdio.h>
#include <Windows.h>
#include "Main.h"

/// <summary>
/// ���� �������� ���� �� ����
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

	// ��ŷ �迭
	sortRanking();
	setBestScore();
	/// ���� ���� �ʱ�ȭ
	g_numOfFrame = 0;
	FPSTextInfo = (char*)malloc(sizeof(char) * 128); //
	memset(FPSTextInfo, '\0', 128);
	OldTime = clock(); // �ð��� �����Ѵ�. 1�ʸ��� �����Ѵ�.
	
	// playSoundBGM();

	while (1)
	{
		CurTime = clock(); // ���� �ð��� �����Ѵ�

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			// UP Ű ������ 
			// �̵� X ��ġ�� X -> -1��
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
			// DOWN Ű ������
			// �̵� X ��ġ�� X -> -1��
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
			// LEFT Ű ������
			// �̵� X ��ġ�� X -> -1��
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
			// RIGHT Ű ������
			// �̵� X ��ġ�� X -> -1��
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
			// ESC Ű ������
			initBoard();
		}
		
		if (isGameOver() == true)
		{
			// ���� ����
			
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
			// ���� �¸�
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
		printUI(); // ���ϸ� ���ӿ��� ���� �� �ȳ��´� 
		Sleep(10);
	}

	// �Ҵ� ���� - ������ ���߾� ���� �����ٲ�
	Release();
	ScreenRelease();
}
