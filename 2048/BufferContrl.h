#pragma once

#include "GameDefine.h"
#include "UI.h"
#include "BufferContrl.h"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

static int g_currentBufferIndex;
static HANDLE g_screenBuffer[2];
clock_t CurTime, OldTime;

int g_numOfFrame;
char* FPSTextInfo;

void ScreenInit();
void ScreenClear();
void ScreenPrint(int x, int y, char* string);
void swapScreenBuffer();