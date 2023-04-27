#include "Score.h"


int g_RankScore[MAX_USERS];

void setBestScore()
{
	g_bestScore = g_RankScore[0];
}

void saveScore(int score) 
{
	FILE* fp;
	fopen_s(&fp, "scores.txt", "a"); // ���� ���Ͽ� append mode �� ����
	fprintf_s(fp, "%d\n", score); // ���� ���� ���� ���
	fclose(fp); // ���� ������ ����
}

void sortRanking() 
{
	FILE* fp;
	int num_index = 0;
	fopen_s(&fp, "scores.txt", "r"); // ���� ������ �б� ���� ����
	while (fscanf_s(fp, "%d\n", &g_RankScore[num_index]) != EOF) { // ���� ������ �д´�
		num_index++;
	}
	fclose(fp); // ���� �ݱ�

	for (int i = 0; i < num_index; i++) // ���� ���ķ� ���� ������������ ����
	{ 
		for (int j = i + 1; j < num_index; j++) 
		{
			if (g_RankScore[i] < g_RankScore[j]) 
			{
				int temp = g_RankScore[i];
				g_RankScore[i] = g_RankScore[j];
				g_RankScore[j] = temp;
			}
		}
	}
}
\