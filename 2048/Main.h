#pragma once

#include "GameDefine.h"

#include "Board.h"
#include "Game.h"
#include "Sound.h"
#include "UI.h"
#include "Score.h"

//
//Score 에서 가져온 것
extern void setBestScore();
extern void saveScore(int);
extern void sortRanking();

//
extern bool isGameOver();
extern bool isGameWin();

// UI 에서 가져온 것
extern void Release();
extern void ScreenRelease();