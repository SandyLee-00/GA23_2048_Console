#include "UI.h"

// 콘솔 커서를 숨기기 위한 함수
void hideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 0 };
	cursor_info.dwSize = sizeof(cursor_info);
	cursor_info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void ScreenInit()
{
	// 커서를 숨긴다
	hideCursor();

	// 버퍼를 초기화 한다
	g_screenBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_screenBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

}

void ScreenClear()
{
	COORD Coor = { 0, 0 }; // 콘솔 좌표라고 한다
	DWORD dw; //  unsigned long 형의 정수 타입, 윈도우 API에서 정의된 내가 모르는 자료형
	FillConsoleOutputCharacter(g_screenBuffer[g_currentBufferIndex], ' ', SCREEN_WIDTH * SCREEN_HEIGHT, Coor, &dw); // 싹다 공백으로 채운다
}


// 더블 버퍼의 두 개의 화면을 교환하는 함수
void swapScreenBuffer() {
	SetConsoleActiveScreenBuffer(g_screenBuffer[g_currentBufferIndex]);
	g_currentBufferIndex = !g_currentBufferIndex;
}

// 화면에 문자를 출력하는 함수
void ScreenPrint(int x, int y, char* string)//x, y좌표에 string을 출력한다 
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(g_screenBuffer[g_currentBufferIndex], CursorPosition);
	WriteFile(g_screenBuffer[g_currentBufferIndex], string, strlen(string), &dw, NULL);
}


void printUI() // 참고 예제에서는Render()
{
	g_numOfFrame++;

	ScreenClear();
	if (CurTime - OldTime >= 50)
	{
		printBoard();
		OldTime = CurTime; // 시간 갱신
		g_numOfFrame = 0; //매 초 프레임 수 초기화
	}
}

// 텍스트 컬러
void ScreenColorPrint(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void printBoard()
{
	//fps 표시
	// sprintf_s(FPSTextInfo, 128, "FPS: %d", g_numOfFrame); ScreenPrint(4, 1, FPSTextInfo);

	// 게임 보드 출력하기 - 아몰라 그냥 무식하게 할래
	ScreenPrint(INDENT + 1, 0, "   _____  ___ ________  __   ______________     \n");
	ScreenPrint(INDENT + 1, 1, "  /  __ \\/  //_____  / /  | /  /_  _  __/ /_    \n");
	ScreenPrint(INDENT + 1, 2, " /  / / /  /___--_/_/ /   |/  /_/ // /_/  _/____\n");
	ScreenPrint(INDENT + 1, 3, "/  /_/ /  //________// /| |  _/________/_// ___/\n");
	ScreenPrint(INDENT + 1, 4, "\\_____/  / / ____ `//_/ |_| / /======  | / /___ \n");
	ScreenPrint(INDENT + 1, 5, "     /__/  \\______/     /__/  \\__======(_)____/ \n");

	ScreenPrint(INDENT - 1, 7,  "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(INDENT - 1, 8,  "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 9,  "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 10, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 11, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 12, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 13, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 14, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 15, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 16, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 17, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 18, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 19, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 20, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 21, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 22, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 23, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 24, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 25, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 26, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 27, "┃                                                  ┃");
	ScreenPrint(INDENT - 1, 28, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

	// 만든 사람들
	ScreenPrint(13, 2, "        만든 사람들");
	ScreenPrint(13, 3, "-------------------");
	ScreenPrint(13, 4, " 로직 구현 - 이서영");
	ScreenPrint(13, 5, "        UI - 김주영");

	//조작법
	ScreenPrint(88, 2, "조작법");
	ScreenPrint(88, 3, "-------------------");
	ScreenPrint(88, 4, "방향키 : ↑ ↓ ← →");
	ScreenPrint(88, 5, "디시 시작 : ESC");

	ScreenPrint(88, 16, "┌----------------------┐");
	ScreenPrint(88, 17, "│ 최고 점수:           │ ");
	ScreenPrint(88, 18, "│                      │ ");
	ScreenPrint(88, 19, "└----------------------┘");
	ScreenPrint(88, 20, "┌----------------------┐");
	ScreenPrint(88, 21, "│ 현재 점수:           │ ");
	ScreenPrint(88, 22, "│                      │ ");
	ScreenPrint(88, 23, "└----------------------┘");
	ScreenPrint(88, 24, "┌----------------------┐");
	ScreenPrint(88, 25, "│ 이동 점수:           │ ");
	ScreenPrint(88, 26, "│                      │ ");
	ScreenPrint(88, 27, "└----------------------┘");

	// 점수 표시 및 기타 수치
	sprintf_s(FPSTextInfo, 128, "%-10d", g_bestScore);	ScreenPrint(100, 18, FPSTextInfo);
	sprintf_s(FPSTextInfo, 128, "%-10d", g_playerScore);	ScreenPrint(100, 22, FPSTextInfo);
	sprintf_s(FPSTextInfo, 128, "%-4d", g_moveScore);	ScreenPrint(100, 26, FPSTextInfo);
				
	ScreenPrint(88, 8, "┌--→ H I N T ←--┐");
	ScreenPrint(88, 9, "│ +-----------+ │");
	ScreenPrint(88, 10, "│ |     △     | │");
	ScreenPrint(88, 11, "│ |  ◁  ○  ▷  | │");
	ScreenPrint(88, 12, "│ |     ▽     | │");
	ScreenPrint(88, 13, "│ +_ _ _ _ _ _+ │");
	ScreenPrint(88, 14, "└---------------┘");
	
	ScreenPrint(7, 8, "}---- R A N K I N G ----{");
	ScreenPrint(8, 9,  "│  1.                 │");
	ScreenPrint(8, 10, "│                     │");
	ScreenPrint(8, 11, "│  2.                 │");
	ScreenPrint(8, 12, "│                     │");
	ScreenPrint(8, 13, "│  3.                 │");
	ScreenPrint(8, 14, "│                     │");
	ScreenPrint(8, 15, "│  4.                 │");
	ScreenPrint(8, 16, "│                     │");
	ScreenPrint(8, 17, "│  5.                 │");
	ScreenPrint(8, 18, "│                     │");
	ScreenPrint(8, 19, "│  6.                 │");
	ScreenPrint(8, 20, "│                     │");
	ScreenPrint(8, 21, "│  7.                 │");
	ScreenPrint(8, 22, "│                     │");
	ScreenPrint(8, 23, "│  8.                 │");
	ScreenPrint(8, 24, "│                     │");
	ScreenPrint(8, 25, "│  9.                 │");
	ScreenPrint(8, 26, "|                     |");
	ScreenPrint(7, 27,"}======================={");

	// 랭킹 출력
	for (int i = 0; i < 9; i++)
	{
		sprintf_s(FPSTextInfo, 128, "%d", g_RankScore[i]);	ScreenPrint(14, 10 + i * 2, FPSTextInfo);
	}

	// 추천 방향키
	switch (g_nextCommand)
	{
	case 'U':
		ScreenPrint(96, 11, "↑");
		// 깜박이게 함 - 이게 그 프레임 제어인가
		if (g_numOfFrame % 2 == 0)
			ScreenPrint(96, 10, "▲");
		break;
	case 'D':
		ScreenPrint(96, 11, "↓");
		if (g_numOfFrame % 2 == 0)
			ScreenPrint(96, 12, "▼");
		break;
	case 'L':
		ScreenPrint(96, 11, "←");
		if (g_numOfFrame % 2 == 0)
			ScreenPrint(93, 11, "◀");
		break;
	case 'R':
		ScreenPrint(96, 11, "→");
		if (g_numOfFrame % 2 == 0)
			ScreenPrint(99, 11, "▶");
		break;
	}

	//보드 타일
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			//숫자가 있으면
			if (g_Board[i][j] != 0)
			{
				// 타일 츨력
				ScreenPrint(j * 12 + (INDENT + 1), i * 5 + 8, "┌──────────┐");
				ScreenPrint(j * 12 + (INDENT + 1), i * 5 + 9, "│          │");
				ScreenPrint(j * 12 + (INDENT + 1), i * 5 + 10, "│          │");
				ScreenPrint(j * 12 + (INDENT + 1), i * 5 + 11, "│          │");
				ScreenPrint(j * 12 + (INDENT + 1), i * 5 + 12, "└──────────┘");

				//숫자 출력
				sprintf_s(FPSTextInfo, 128, "%4d", g_Board[i][j]);
				ScreenPrint(j * 12 + (INDENT + 3), i * 5 + 10, FPSTextInfo);
			}
		}
	}

	// 게임 오버라면?
	if (isGameOver() == true)
	{
		ScreenPrint(46, 16, " ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓ ");
		ScreenPrint(46, 17, " ┃  = G A M E  O V E R =   ┃ ");
		ScreenPrint(46, 18, " ┗━━━━━━━━━━━━━━━━━━━━━━━━━┛ ");
	}		

	// 2048이 완성되면?
	if (isGameWin() == true)
	{
		if (g_numOfFrame % 2 == 0)
		{
			ScreenPrint(46, 16, " ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓");
			ScreenPrint(46, 17, " ┃     2 0 4 0   W I N     ┃");
			ScreenPrint(46, 18, " ┗━━━━━━━━━━━━━━━━━━━━━━━━━┛ ");
		}
	}

	swapScreenBuffer();
}

void printMoveScore()
{
	// 이동 점수 출력하기
	printf("Move Score: %d\n", g_moveScore);
}

void printPlayerScore()
{
	// 플레이어 점수 출력하기
	printf("Player Score: %d\n", g_playerScore);
}

void printBestScore()
{
	// 최고 점수 출력하기
	printf("Best Score: %d\n", g_bestScore);
}

// 난이도 4, 5, 6 받아서 현재 난이도 출력


// fps 를 나타내는 문자열아 열심히 일했어 이제 보내줄게
void Release()
{
	free(FPSTextInfo);
}
// 버퍼들이 열심히 일했어 이제 놓아줄께
void ScreenRelease()
{
	CloseHandle(g_screenBuffer[0]);
	CloseHandle(g_screenBuffer[1]);
}