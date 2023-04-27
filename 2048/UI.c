#include "UI.h"

// �ܼ� Ŀ���� ����� ���� �Լ�
void hideCursor() {
	CONSOLE_CURSOR_INFO cursor_info = { 0 };
	cursor_info.dwSize = sizeof(cursor_info);
	cursor_info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void ScreenInit()
{
	// Ŀ���� �����
	hideCursor();

	// ���۸� �ʱ�ȭ �Ѵ�
	g_screenBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_screenBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

}

void ScreenClear()
{
	COORD Coor = { 0, 0 }; // �ܼ� ��ǥ��� �Ѵ�
	DWORD dw; //  unsigned long ���� ���� Ÿ��, ������ API���� ���ǵ� ���� �𸣴� �ڷ���
	FillConsoleOutputCharacter(g_screenBuffer[g_currentBufferIndex], ' ', SCREEN_WIDTH * SCREEN_HEIGHT, Coor, &dw); // �ϴ� �������� ä���
}


// ���� ������ �� ���� ȭ���� ��ȯ�ϴ� �Լ�
void swapScreenBuffer() {
	SetConsoleActiveScreenBuffer(g_screenBuffer[g_currentBufferIndex]);
	g_currentBufferIndex = !g_currentBufferIndex;
}

// ȭ�鿡 ���ڸ� ����ϴ� �Լ�
void ScreenPrint(int x, int y, char* string)//x, y��ǥ�� string�� ����Ѵ� 
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(g_screenBuffer[g_currentBufferIndex], CursorPosition);
	WriteFile(g_screenBuffer[g_currentBufferIndex], string, strlen(string), &dw, NULL);
}


void printUI() // ���� ����������Render()
{
	g_numOfFrame++;

	ScreenClear();
	if (CurTime - OldTime >= 50)
	{
		printBoard();
		OldTime = CurTime; // �ð� ����
		g_numOfFrame = 0; //�� �� ������ �� �ʱ�ȭ
	}
}

// �ؽ�Ʈ �÷�
void ScreenColorPrint(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void printBoard()
{
	//fps ǥ��
	// sprintf_s(FPSTextInfo, 128, "FPS: %d", g_numOfFrame); ScreenPrint(4, 1, FPSTextInfo);

	// ���� ���� ����ϱ� - �Ƹ��� �׳� �����ϰ� �ҷ�
	ScreenPrint(INDENT + 1, 0, "   _____  ___ ________  __   ______________     \n");
	ScreenPrint(INDENT + 1, 1, "  /  __ \\/  //_____  / /  | /  /_  _  __/ /_    \n");
	ScreenPrint(INDENT + 1, 2, " /  / / /  /___--_/_/ /   |/  /_/ // /_/  _/____\n");
	ScreenPrint(INDENT + 1, 3, "/  /_/ /  //________// /| |  _/________/_// ___/\n");
	ScreenPrint(INDENT + 1, 4, "\\_____/  / / ____ `//_/ |_| / /======  | / /___ \n");
	ScreenPrint(INDENT + 1, 5, "     /__/  \\______/     /__/  \\__======(_)____/ \n");

	ScreenPrint(INDENT - 1, 7,  "��������������������������������������������������������������������������������������������������������");
	ScreenPrint(INDENT - 1, 8,  "��                                                  ��");
	ScreenPrint(INDENT - 1, 9,  "��                                                  ��");
	ScreenPrint(INDENT - 1, 10, "��                                                  ��");
	ScreenPrint(INDENT - 1, 11, "��                                                  ��");
	ScreenPrint(INDENT - 1, 12, "��                                                  ��");
	ScreenPrint(INDENT - 1, 13, "��                                                  ��");
	ScreenPrint(INDENT - 1, 14, "��                                                  ��");
	ScreenPrint(INDENT - 1, 15, "��                                                  ��");
	ScreenPrint(INDENT - 1, 16, "��                                                  ��");
	ScreenPrint(INDENT - 1, 17, "��                                                  ��");
	ScreenPrint(INDENT - 1, 18, "��                                                  ��");
	ScreenPrint(INDENT - 1, 19, "��                                                  ��");
	ScreenPrint(INDENT - 1, 20, "��                                                  ��");
	ScreenPrint(INDENT - 1, 21, "��                                                  ��");
	ScreenPrint(INDENT - 1, 22, "��                                                  ��");
	ScreenPrint(INDENT - 1, 23, "��                                                  ��");
	ScreenPrint(INDENT - 1, 24, "��                                                  ��");
	ScreenPrint(INDENT - 1, 25, "��                                                  ��");
	ScreenPrint(INDENT - 1, 26, "��                                                  ��");
	ScreenPrint(INDENT - 1, 27, "��                                                  ��");
	ScreenPrint(INDENT - 1, 28, "��������������������������������������������������������������������������������������������������������");

	// ���� �����
	ScreenPrint(13, 2, "        ���� �����");
	ScreenPrint(13, 3, "-------------------");
	ScreenPrint(13, 4, " ���� ���� - �̼���");
	ScreenPrint(13, 5, "        UI - ���ֿ�");

	//���۹�
	ScreenPrint(88, 2, "���۹�");
	ScreenPrint(88, 3, "-------------------");
	ScreenPrint(88, 4, "����Ű : �� �� �� ��");
	ScreenPrint(88, 5, "��� ���� : ESC");

	ScreenPrint(88, 16, "��----------------------��");
	ScreenPrint(88, 17, "�� �ְ� ����:           �� ");
	ScreenPrint(88, 18, "��                      �� ");
	ScreenPrint(88, 19, "��----------------------��");
	ScreenPrint(88, 20, "��----------------------��");
	ScreenPrint(88, 21, "�� ���� ����:           �� ");
	ScreenPrint(88, 22, "��                      �� ");
	ScreenPrint(88, 23, "��----------------------��");
	ScreenPrint(88, 24, "��----------------------��");
	ScreenPrint(88, 25, "�� �̵� ����:           �� ");
	ScreenPrint(88, 26, "��                      �� ");
	ScreenPrint(88, 27, "��----------------------��");

	// ���� ǥ�� �� ��Ÿ ��ġ
	sprintf_s(FPSTextInfo, 128, "%-10d", g_bestScore);	ScreenPrint(100, 18, FPSTextInfo);
	sprintf_s(FPSTextInfo, 128, "%-10d", g_playerScore);	ScreenPrint(100, 22, FPSTextInfo);
	sprintf_s(FPSTextInfo, 128, "%-4d", g_moveScore);	ScreenPrint(100, 26, FPSTextInfo);
				
	ScreenPrint(88, 8, "��--�� H I N T ��--��");
	ScreenPrint(88, 9, "�� +-----------+ ��");
	ScreenPrint(88, 10, "�� |     ��     | ��");
	ScreenPrint(88, 11, "�� |  ��  ��  ��  | ��");
	ScreenPrint(88, 12, "�� |     ��     | ��");
	ScreenPrint(88, 13, "�� +_ _ _ _ _ _+ ��");
	ScreenPrint(88, 14, "��---------------��");
	
	ScreenPrint(7, 8, "}---- R A N K I N G ----{");
	ScreenPrint(8, 9,  "��  1.                 ��");
	ScreenPrint(8, 10, "��                     ��");
	ScreenPrint(8, 11, "��  2.                 ��");
	ScreenPrint(8, 12, "��                     ��");
	ScreenPrint(8, 13, "��  3.                 ��");
	ScreenPrint(8, 14, "��                     ��");
	ScreenPrint(8, 15, "��  4.                 ��");
	ScreenPrint(8, 16, "��                     ��");
	ScreenPrint(8, 17, "��  5.                 ��");
	ScreenPrint(8, 18, "��                     ��");
	ScreenPrint(8, 19, "��  6.                 ��");
	ScreenPrint(8, 20, "��                     ��");
	ScreenPrint(8, 21, "��  7.                 ��");
	ScreenPrint(8, 22, "��                     ��");
	ScreenPrint(8, 23, "��  8.                 ��");
	ScreenPrint(8, 24, "��                     ��");
	ScreenPrint(8, 25, "��  9.                 ��");
	ScreenPrint(8, 26, "|                     |");
	ScreenPrint(7, 27,"}======================={");

	// ��ŷ ���
	for (int i = 0; i < 9; i++)
	{
		sprintf_s(FPSTextInfo, 128, "%d", g_RankScore[i]);	ScreenPrint(14, 10 + i * 2, FPSTextInfo);
	}

	// ��õ ����Ű
	switch (g_nextCommand)
	{
	case 'U':
		ScreenPrint(96, 11, "��");
		// �����̰� �� - �̰� �� ������ �����ΰ�
		if (g_numOfFrame % 2 == 0)
			ScreenPrint(96, 10, "��");
		break;
	case 'D':
		ScreenPrint(96, 11, "��");
		if (g_numOfFrame % 2 == 0)
			ScreenPrint(96, 12, "��");
		break;
	case 'L':
		ScreenPrint(96, 11, "��");
		if (g_numOfFrame % 2 == 0)
			ScreenPrint(93, 11, "��");
		break;
	case 'R':
		ScreenPrint(96, 11, "��");
		if (g_numOfFrame % 2 == 0)
			ScreenPrint(99, 11, "��");
		break;
	}

	//���� Ÿ��
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			//���ڰ� ������
			if (g_Board[i][j] != 0)
			{
				// Ÿ�� ����
				ScreenPrint(j * 12 + (INDENT + 1), i * 5 + 8, "������������������������");
				ScreenPrint(j * 12 + (INDENT + 1), i * 5 + 9, "��          ��");
				ScreenPrint(j * 12 + (INDENT + 1), i * 5 + 10, "��          ��");
				ScreenPrint(j * 12 + (INDENT + 1), i * 5 + 11, "��          ��");
				ScreenPrint(j * 12 + (INDENT + 1), i * 5 + 12, "������������������������");

				//���� ���
				sprintf_s(FPSTextInfo, 128, "%4d", g_Board[i][j]);
				ScreenPrint(j * 12 + (INDENT + 3), i * 5 + 10, FPSTextInfo);
			}
		}
	}

	// ���� �������?
	if (isGameOver() == true)
	{
		ScreenPrint(46, 16, " ������������������������������������������������������ ");
		ScreenPrint(46, 17, " ��  = G A M E  O V E R =   �� ");
		ScreenPrint(46, 18, " ������������������������������������������������������ ");
	}		

	// 2048�� �ϼ��Ǹ�?
	if (isGameWin() == true)
	{
		if (g_numOfFrame % 2 == 0)
		{
			ScreenPrint(46, 16, " ������������������������������������������������������");
			ScreenPrint(46, 17, " ��     2 0 4 0   W I N     ��");
			ScreenPrint(46, 18, " ������������������������������������������������������ ");
		}
	}

	swapScreenBuffer();
}

void printMoveScore()
{
	// �̵� ���� ����ϱ�
	printf("Move Score: %d\n", g_moveScore);
}

void printPlayerScore()
{
	// �÷��̾� ���� ����ϱ�
	printf("Player Score: %d\n", g_playerScore);
}

void printBestScore()
{
	// �ְ� ���� ����ϱ�
	printf("Best Score: %d\n", g_bestScore);
}

// ���̵� 4, 5, 6 �޾Ƽ� ���� ���̵� ���


// fps �� ��Ÿ���� ���ڿ��� ������ ���߾� ���� �����ٰ�
void Release()
{
	free(FPSTextInfo);
}
// ���۵��� ������ ���߾� ���� �����ٲ�
void ScreenRelease()
{
	CloseHandle(g_screenBuffer[0]);
	CloseHandle(g_screenBuffer[1]);
}