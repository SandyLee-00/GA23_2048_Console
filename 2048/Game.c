#include "Game.h"

int moveUp()
{
	// �� ���� Ÿ���� ���� �̵�
	// -1 : �̵� X, ��ġ�� X
	// 0 : �̵� O, ��ġ�� X
	// cntScore : ��ġ�� O
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
				
				// tmpIdx-1�� *2�� �� �����ϱ�
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
	// �� ���� Ÿ���� �Ʒ��� �̵�
	// -1 : �̵� X, ��ġ�� X
	// 0 : �̵� O, ��ġ�� X
	// cntScore : ��ġ�� O
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

				// tmpIdx+1�� *2�� �� �����ϱ�
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
	// �� ���� Ÿ���� ���ʷ� �̵�
	// -1 : �̵� X, ��ġ�� X
	// 0 : �̵� O, ��ġ�� X
	// cntScore : ��ġ�� O
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
				// tmp-1�� *2�� �� �����ϱ�
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
	// �� ���� Ÿ���� ���������� �̵�
	// -1 : �̵� X, ��ġ�� X
	// 0 : �̵� O, ��ġ�� X
	// cntScore : ��ġ�� O
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
				// tmp+1�� *2�� �� �����ϱ�
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
	// 0�� �ִ��� Ȯ��
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

	// ���η� ���� ���� �ִ��� Ȯ��
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

	// ���η� ���� ���� �ִ��� Ȯ��
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
	// 2048�� �ִ��� Ȯ��
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
	// nextMove greedy�ϰ� UDRL�� g_nextCommand �ٲٱ�

	int tmpBoard[SIZE][SIZE];
	int maxScore = -2;
	int tmpMoveScore = 0;
	g_nextCommand = 'U';

	// ���� ���� �����ϱ�
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			tmpBoard[i][j] = g_Board[i][j];
		}
	}

	// ���� �̵��ϱ�
	tmpMoveScore = moveUp();
	if (tmpMoveScore > maxScore)
	{
		maxScore = tmpMoveScore;
		g_nextCommand = 'U';
	}

	// �Ʒ��� �̵��ϱ�
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

	// �������� �̵��ϱ�
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

	// ���������� �̵��ϱ�

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

	// ���� ���� �����ϱ�
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			g_Board[i][j] = tmpBoard[i][j];
		}
	}

}