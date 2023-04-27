#include "Board.h"

void initBoard()
{
	int cnt, x, y;

	g_playerScore = 0;
	g_moveScore = 0;
	srand((unsigned int)time(NULL)); // 시드 값을 현재 시간으로 설정

	// 게임 보드의 모든 칸을 0으로 초기화
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			g_Board[i][j] = 0;
		}
	}

	// 무작위로 두 개의 2 또는 4 타일 생성
	cnt = 0;
	while (cnt < 2)
	{
		x = rand() % SIZE;
		y = rand() % SIZE;

		if (g_Board[x][y] == 0)
		{
			g_Board[x][y] = (rand() % 2 + 1) * 2;
			cnt++;
		}
	}
	
	return;
}

bool addTile()
{
	// 0이 있는지 확인
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (g_Board[i][j] == 0)
			{
				count++;
			}
		}
	}
	if (count == 0)
	{
		return false;
	}

	int x, y;
	while (1)
	{
		x = rand() % SIZE;
		y = rand() % SIZE;
		if (g_Board[x][y] == 0)
		{
			break;
		}
	}
	g_Board[x][y] = ((rand() % 2) + 1) * 2;

	return true;
}