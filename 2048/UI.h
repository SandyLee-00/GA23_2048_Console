#pragma once

#include "GameDefine.h"
#include "Game.h"

// 화면 너비 높이 
#define SCREEN_WIDTH 120
#define SCREEN_HEIGHT 30

//화면 줄 정렬
#define INDENT 35

// 현재 출력할 화면 버퍼 번호
static int g_currentBufferIndex;
// 더블 버퍼링을 위한 두 개의 화면 버퍼
static HANDLE g_screenBuffer[2];

int g_numOfFrame;

clock_t CurTime, OldTime;
char* FPSTextInfo;

void hideCursor();
void ScreenInit();
void swapScreenBuffer();
void ScreenPrint(int x, int y, char* string);

void printUI();

void printBoard();
void printPlayerScore();
void printMoveScore();
void printBestScore();

extern bool isGameOver();
extern bool isGameWin();