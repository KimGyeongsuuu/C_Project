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
	printf("����������������������������������������������������������\n");
	for (int i = 0; i < 26; i++)
	{
		printf("��");
		for (int j = 0; j < 110; j++)
		{
			printf(" ");
		}
		printf("��\n");
	}
	printf("����������������������������������������������������������\n");

}
void HideCursor() //Ŀ���� ����
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
	char selecting = 0; // NULL�� ����
	char Macro = 0;   // NULL�� ����
	HideCursor();
	border();
	Gotoxy(48, 5);
	puts("�� �� ����");

	Gotoxy(78, 29);
	puts("* �ڷ� ������ 'b'�� ���� �ڷ� ������.");
	while (1)
	{
		// �� �� ����
		if (selecting == 0) // ����
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else // �̼���
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
		puts("���� : seoul");
		Gotoxy(45, 10);
		puts("���� : �����������");


		// ª�� �� ����
		if (selecting == 1) // ����
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else  // �̼���
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
		puts("���� : �ٶ����");
		Gotoxy(45, 15);
		puts("���� : ����");

		
		if (selecting == 2)  // ����
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else  // �̼���
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
		puts("���� : ��ȣ��");
		Gotoxy(45, 20);
		puts("���� : �̹���");

		if (selecting == 3)  // ����
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else  // �̼���
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
		puts("���� : TOMBOY");
		Gotoxy(45, 25);
		puts("���� : ����");



		Macro = _getch();
		if (Macro == 0x00 || Macro == 0xE0)
		{
			Macro = _getch();
		}
		if (Macro == 80 || Macro == 72)
		{
			switch (Macro)
			{
			case 72:// ��ũ�θ� UP������
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
			case 80: // ��ũ�θ� DOWN ������
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