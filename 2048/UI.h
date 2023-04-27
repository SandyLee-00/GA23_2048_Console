#pragma once

#include "GameDefine.h"
#include "Game.h"

// ȭ�� �ʺ� ���� 
#define SCREEN_WIDTH 120
#define SCREEN_HEIGHT 30

//ȭ�� �� ����
#define INDENT 35

// ���� ����� ȭ�� ���� ��ȣ
static int g_currentBufferIndex;
// ���� ���۸��� ���� �� ���� ȭ�� ����
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