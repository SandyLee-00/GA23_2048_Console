#include "Game.h"

int moveUp()
{
	// 열 별로 타일을 위로 이동
	// -1 : 이동 X, 합치기 X
	// 0 : 이동 O, 합치기 X
	// cntScore : 합치기 O
	int cntScore = -1;
	int tmpIdx;

	for (int j = 0; j < SIZE; j++)
	{
		for (int i = 1; i < SIZE; i++)
		{
			// i idx 1, 2, 3
			if (g_Board[i][j] != 0) 
			{
				tmpIdx = i;

				// tmpIdx -> 0
				while (tmpIdx > 0 && g_Board[tmpIdx - 1][j] == 0)
				{
					g_Board[tmpIdx - 1][j] = g_Board[tmpIdx][j];
					g_Board[tmpIdx][j] = 0;
					tmpIdx--;
					if (cntScore == -1)
					{
						cntScore = 0;
					}
				}
				
				// tmpIdx-1에 *2한 값 저장하기
				if (tmpIdx > 0 && g_Board[tmpIdx - 1][j] == g_Board[tmpIdx][j]) 
				{
					g_Board[tmpIdx - 1][j] *= 2;
					g_Board[tmpIdx][j] = 0;
					if (cntScore == -1)
					{
						cntScore = 0;
					}
					cntScore += g_Board[tmpIdx - 1][j];
				}
			}
		}
	}
	return cntScore;
}

int moveDown()
{
	// 열 별로 타일을 아래로 이동
	// -1 : 이동 X, 합치기 X
	// 0 : 이동 O, 합치기 X
	// cntScore : 합치기 O
	int cntScore = -1;
	int tmpIdx;

	for (int j = 0; j < SIZE; j++)
	{
		for (int i = SIZE - 2; i >= 0; i--)
		{
			// idx 2, 1, 0
			if (g_Board[i][j] != 0)
			{
				tmpIdx = i;
				// tmpIdx -> SIZE-1
				while (tmpIdx < SIZE - 1 && g_Board[tmpIdx + 1][j] == 0)
				{
					g_Board[tmpIdx + 1][j] = g_Board[tmpIdx][j];
					g_Board[tmpIdx][j] = 0;
					tmpIdx++;
					if (cntScore == -1)
					{
						cntScore = 0;
					}
				}

				// tmpIdx+1에 *2한 값 저장하기
				if (tmpIdx < SIZE - 1 && g_Board[tmpIdx + 1][j] == g_Board[tmpIdx][j])
				{
					g_Board[tmpIdx + 1][j] *= 2;
					g_Board[tmpIdx][j] = 0;

					if (cntScore == -1)
					{
						cntScore = 0;
					}
					cntScore += g_Board[tmpIdx + 1][j];
				}
			}
		}
	}
	return cntScore;
}

int moveLeft()
{
	// 행 별로 타일을 왼쪽로 이동
	// -1 : 이동 X, 합치기 X
	// 0 : 이동 O, 합치기 X
	// cntScore : 합치기 O
	int cntScore = -1;
	int tmp;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 1; j < SIZE; j++)
		{
			// i idx 1, 2, 3
			if (g_Board[i][j] != 0)
			{
				tmp = j;
				// tmp -> 0
				while (tmp > 0 && g_Board[i][tmp - 1] == 0)
				{
					g_Board[i][tmp - 1] = g_Board[i][tmp];
					g_Board[i][tmp] = 0;
					tmp--;
					if (cntScore == -1)
					{
						cntScore = 0;
					}
				}
				// tmp-1에 *2한 값 저장하기
				if (tmp > 0 && g_Board[i][tmp - 1] == g_Board[i][tmp])
				{
					g_Board[i][tmp - 1] *= 2;
					g_Board[i][tmp] = 0;
					if (cntScore == -1)
					{
						cntScore = 0;
					}
					cntScore += g_Board[i][tmp - 1];
				}
			}
		}
	}
	return cntScore;
}

int moveRight()
{
	// 행 별로 타일을 오른쪽으로 이동
	// -1 : 이동 X, 합치기 X
	// 0 : 이동 O, 합치기 X
	// cntScore : 합치기 O
	int cntScore = -1;
	int tmp;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = SIZE - 2; j >= 0; j--)
		{
			// idx 2, 1, 0
			if (g_Board[i][j] != 0)
			{
				tmp = j;
				// tmp -> SIZE-1
				while (tmp < SIZE - 1 && g_Board[i][tmp + 1] == 0)
				{
					g_Board[i][tmp + 1] = g_Board[i][tmp];
					g_Board[i][tmp] = 0;
					tmp++;
					if (cntScore == -1)
					{
						cntScore = 0;
					}
				}
				// tmp+1에 *2한 값 저장하기
				if (tmp < SIZE - 1 && g_Board[i][tmp + 1] == g_Board[i][tmp])
				{
					g_Board[i][tmp + 1] *= 2;
					g_Board[i][tmp] = 0;
					if (cntScore == -1)
					{
						cntScore = 0;
					}
					cntScore += g_Board[i][tmp + 1];
				}
			}
		}
	}
	return cntScore;
}

bool isGameOver()
{
	// 0이 있는지 확인
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (g_Board[i][j] == 0)
			{
				return false;
			}
		}
	}

	// 가로로 같은 값이 있는지 확인
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			if (g_Board[i][j] == g_Board[i][j + 1])
			{
				return false;
			}
		}
	}

	// 세로로 같은 값이 있는지 확인
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (g_Board[i][j] == g_Board[i + 1][j])
			{
				return false;
			}
		}
	}

	return true;
}

bool isGameWin()
{
	// 2048이 있는지 확인
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (g_Board[i][j] >= 2048)
			{
				return true;
			}
		}
	}

	return false;
}

void setNextCommand()
{
	// nextMove greedy하게 UDRL로 g_nextCommand 바꾸기

	int tmpBoard[SIZE][SIZE];
	int maxScore = -2;
	int tmpMoveScore = 0;
	g_nextCommand = 'U';

	// 원본 보드 저장하기
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			tmpBoard[i][j] = g_Board[i][j];
		}
	}

	// 위로 이동하기
	tmpMoveScore = moveUp();
	if (tmpMoveScore > maxScore)
	{
		maxScore = tmpMoveScore;
		g_nextCommand = 'U';
	}

	// 아래로 이동하기
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			g_Board[i][j] = tmpBoard[i][j];
		}
	}

	tmpMoveScore = moveDown();
	if (tmpMoveScore > maxScore)
	{
		maxScore = tmpMoveScore;
		g_nextCommand = 'D';
	}

	// 왼쪽으로 이동하기
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			g_Board[i][j] = tmpBoard[i][j];
		}
	}

	tmpMoveScore = moveLeft();

	if (tmpMoveScore > maxScore)
	{
		maxScore = tmpMoveScore;
		g_nextCommand = 'L';
	}

	// 오른쪽으로 이동하기

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			g_Board[i][j] = tmpBoard[i][j];
		}
	}

	tmpMoveScore = moveRight();

	if (tmpMoveScore > maxScore)
	{
		maxScore = tmpMoveScore;
		g_nextCommand = 'R';
	}

	// 원본 보드 복구하기
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			g_Board[i][j] = tmpBoard[i][j];
		}
	}

}