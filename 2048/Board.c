#include "Board.h"

void initBoard()
{
	int cnt, x, y;

	g_playerScore = 0;
	g_moveScore = 0;
	srand((unsigned int)time(NULL)); // �õ� ���� ���� �ð����� ����

	// ���� ������ ��� ĭ�� 0���� �ʱ�ȭ
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			g_Board[i][j] = 0;
		}
	}

	// �������� �� ���� 2 �Ǵ� 4 Ÿ�� ����
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
	// 0�� �ִ��� Ȯ��
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