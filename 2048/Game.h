#pragma once

#include "GameDefine.h"
///#define SIZE 4 // 게임 보드의 크기

int moveUp();
int moveDown();
int moveLeft();
int moveRight();

bool isGameOver();
bool isGameWin();

void setNextCommand();