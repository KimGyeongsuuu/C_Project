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
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");

}
int main()
{
	border();
	Gotoxy(30, 5);
	printf("+------------------------------------------------------+\n");
	Gotoxy(30, 6);
	printf("|");
	Gotoxy(85, 6);
	printf("|");
	Gotoxy(30, 7);
	printf("|");
	Gotoxy(85, 7);
	printf("|");
	Gotoxy(30, 8);
	printf("+------------------------------------------------------+");
	Gotoxy(42, 6); printf("광");
	Gotoxy(44, 6); printf("주");
	Gotoxy(46, 6); printf("소");
	Gotoxy(48, 6); printf("프");
	Gotoxy(50, 6); printf("트");
	Gotoxy(52, 6); printf("웨");
	Gotoxy(54, 6); printf("어");
	Gotoxy(56, 6); printf("마");
	Gotoxy(58, 6); printf("이");
	Gotoxy(60, 6); printf("스");
	Gotoxy(62, 6); printf("터");
	Gotoxy(64, 6); printf("고");
	Gotoxy(66, 6); printf("등");
	Gotoxy(68, 6); printf("학");
	Gotoxy(70, 6); printf("교");
	Gotoxy(48, 7); printf("타");
	Gotoxy(53, 7); printf("자");
	Gotoxy(58, 7); printf("연");
	Gotoxy(63, 7); printf("습");
	Gotoxy(15, 10);
	printf("┌─────────────────────┐");
	Gotoxy(15, 11);
	printf("│");
	Gotoxy(15, 12);
	printf("│");
	Gotoxy(15, 13);
	printf("│");
	Gotoxy(15, 14);
	printf("│");
	Gotoxy(37, 11);
	printf("│");
	Gotoxy(37, 12);
	printf("│");
	Gotoxy(37, 13);
	printf("│");
	Gotoxy(37, 14);
	printf("│");
	Gotoxy(15, 15);
	printf("└─────────────────────┘");
	
}