#include "Score.h"


int g_RankScore[MAX_USERS];

void setBestScore()
{
	g_bestScore = g_RankScore[0];
}

void saveScore(int score) 
{
	FILE* fp;
	fopen_s(&fp, "scores.txt", "a"); // 점수 파일에 append mode 로 연다
	fprintf_s(fp, "%d\n", score); // 점수 파일 내용 출력
	fclose(fp); // 열린 파일을 닫음
}

void sortRanking() 
{
	FILE* fp;
	int num_index = 0;
	fopen_s(&fp, "scores.txt", "r"); // 점수 파일을 읽기 모드로 연다
	while (fscanf_s(fp, "%d\n", &g_RankScore[num_index]) != EOF) { // 점수 파일을 읽는다
		num_index++;
	}
	fclose(fp); // 파일 닫기

	for (int i = 0; i < num_index; i++) // 버블 정렬로 점수 내림차순으로 정렬
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