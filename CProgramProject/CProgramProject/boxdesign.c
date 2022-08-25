#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include <time.h>
#include<string.h>
void boxdesign(int x1,int y1,int x2, int y2);
void Gotoxy(int x, int y);
int main()
{

	int x,y,x1,y1;
	scanf("%d %d %d %d", &x,&y,&x1,&y1);
	boxdesign(x,y,x1,y1);
}
void Gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void boxdesign(int x1,int y1,int x2, int y2)
{
	//         박스의 설계
	//  x1                    x2
	//  ┌──────────┐
	//  │                    │
	//  │                    │ 
	//  │                    │
	//  │                    │
	//  │                    │
	//  └──────────┘
	//  y1                     y2
	//
	printf("┌");
	for (int i = 0; i < (x2 - x1)-1; i++)
	{
		printf("─");
	}
	printf("┐\n");
	for (int i = 0; i < (y1 - x1); i++)
	{
		printf("│");
		for (int i = 0; i < (x2 - x1)-1; i++)
		{
			printf(" ");
		}
		printf("│\n");
	}
	printf("└");
	for (int i=0;i<(y2-y1)-1;i++)
	{
		printf("─");
	}
	printf("┘");

}