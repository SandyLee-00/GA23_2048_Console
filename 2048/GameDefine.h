///
/// ��� ���Ͽ��� ���������� ���Ǵ� �������
///
/// 2023.04.21 J
/// 
#pragma once
#pragma comment(lib, "Winmm.lib")

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>

// ���� ������ ũ��
#define SIZE 4

#define MAX_USERS 100

/// <summary>
/// ���� �������� ��򰡿� �����Ƿ� �װ��� �����ٰ� ���ڴ�.
/// extern�� ���� �� ���ǰ� �ƴϰ� �׳� �ܺ� ��⿡�� �����ٰ� ���ڴٴ� �ǹ̴�.
/// </summary>
extern int g_Board[SIZE][SIZE]; // ���� ����
extern int g_bestScore;
extern int g_playerScore;
extern int g_moveScore;
extern char g_nextCommand;
extern int g_RankScore[MAX_USERS];

enum SOUND_EFFECT
{
	SOUND_ERROR = -1,
	SOUND_MOVE = 0,
	SOUND_MERGE,
	SOUND_WIN = 9999,
	SOUND_LOSE = 9998
};