#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include <time.h>
#include<string.h>
#include <stdlib.h>
#include <process.h>

const int BLUE = 1;
const int WHITE = 7;
const int RED = 4;
const int GREEN = 2;
const int LIGHTPurple = 13;
const int YELLOW = 6;
const int LightAqua = 11;
const int GRAY = 8;
void border()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	for (int i = 0; i < 26; i++)
	{
		printf("■");
		for (int j = 0; j < 110; j++)
		{
			printf(" ");
		}
		printf("■\n");
	}
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

}
void HideCursor() //커서를 숨김
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
void Gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void fullscreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}
int main()
{	
	char selecting = 0; // NULL로 지정
	char Macro = 0;   // NULL로 지정
	HideCursor();
	border();
	Gotoxy(48, 5);
	puts("긴 글 선택");

	Gotoxy(78, 29);
	puts("* 뒤로 가려면 'b'를 눌러 뒤로 가세요.");
	while (1)
	{
		// 긴 글 연습
		if (selecting == 0) // 선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else // 미선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
		}
		Gotoxy(24, 9);
		puts("|");
		Gotoxy(24, 10);
		puts("|");
		Gotoxy(24, 8);
		puts("+-----------------------------------------------------------+");
		Gotoxy(84, 9);
		puts("|");
		Gotoxy(84, 10);
		puts("|");
		Gotoxy(24, 11);
		puts("+-----------------------------------------------------------+");
		Gotoxy(45, 9);
		puts("제목 : seoul");
		Gotoxy(45, 10);
		puts("가수 : 볼빨간사춘기");


		// 짧은 글 연습
		if (selecting == 1) // 선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else  // 미선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
		}
		Gotoxy(24, 14);
		puts("|");
		Gotoxy(24, 15);
		puts("|");
		Gotoxy(24, 13);
		puts("+-----------------------------------------------------------+");
		Gotoxy(84, 14);
		puts("|");
		Gotoxy(84, 15);
		puts("|");
		Gotoxy(24, 16);
		puts("+-----------------------------------------------------------+");
		Gotoxy(45, 14);
		puts("제목 : 바람기억");
		Gotoxy(45, 15);
		puts("가수 : 나얼");

		
		if (selecting == 2)  // 선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else  // 미선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
		}
		Gotoxy(24, 19);
		puts("|");
		Gotoxy(24, 20);
		puts("|");
		Gotoxy(24, 18);
		puts("+-----------------------------------------------------------+");
		Gotoxy(84, 19);
		puts("|");
		Gotoxy(84, 20);
		puts("|");
		Gotoxy(24, 21);
		puts("+-----------------------------------------------------------+");
		Gotoxy(45, 19);
		puts("제목 : 신호등");
		Gotoxy(45, 20);
		puts("가수 : 이무진");

		if (selecting == 3)  // 선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else  // 미선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
		}
		Gotoxy(24, 24);
		puts("|");
		Gotoxy(24, 25);
		puts("|");
		Gotoxy(24, 23);
		puts("+-----------------------------------------------------------+");
		Gotoxy(84, 24);
		puts("|");
		Gotoxy(84, 25);
		puts("|");
		Gotoxy(24, 26);
		puts("+-----------------------------------------------------------+");
		Gotoxy(45, 24);
		puts("제목 : TOMBOY");
		Gotoxy(45, 25);
		puts("가수 : 혁오");



		Macro = _getch();
		if (Macro == 0x00 || Macro == 0xE0)
		{
			Macro = _getch();
		}
		if (Macro == 80 || Macro == 72)
		{
			switch (Macro)
			{
			case 72:// 매크로를 UP했을때
			{
				if (selecting > 0)
				{
					selecting--;
				}
				else if (selecting == 0)
				{
					selecting = 3;
				}
				break;
			}
			case 80: // 매크로를 DOWN 했을때
			{
				if (selecting < 3)
				{
					selecting++;
				}
				else if (selecting == 3)
				{
					selecting = 0;
				}
				break;
			}
			}
			continue;
		}
		else if (Macro == 13)
		{
			break;
		}
	}
	return 0;



}