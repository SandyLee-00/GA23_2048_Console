///
/// 모든 파일에서 공통적으로 사용되는 헤더파일
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

// 게임 보드의 크기
#define SIZE 4

#define MAX_USERS 100

/// <summary>
/// 전역 변수들이 어딘가에 있으므로 그것을 가져다가 쓰겠다.
/// extern은 선언 및 정의가 아니고 그냥 외부 모듈에서 가져다가 쓰겠다는 의미다.
/// </summary>
extern int g_Board[SIZE][SIZE]; // 게임 보드
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