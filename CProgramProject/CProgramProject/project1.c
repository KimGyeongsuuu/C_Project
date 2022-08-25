#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h> 

#define rows 5
#define column 80

int main()
{
	int i, j, k, len, wnum, menu;
	float t;

	char str[rows][column] = { "apple is sweet","expensive banana","hello world","i want go home","soccer is fun"};
	char c[column], name[column];

	printf("Input your name : ");
	gets(name);
	system("cls");
	while (1) 
	{
		while (1) 
		{
			printf("Menu Option\n1.English 2.Exit\n");
			scanf_s("%d", &menu);
			if ((menu > 0) && (menu < 3))
				break;
			printf("\bError!\n");
		}
		system("cls");
		wnum = 0;
		t = clock(); //시작시간 저장
		if (menu == 1) 
		{
			for (j = 0; j < rows; j++) 
			{
				len = strlen(str[j]);
				printf("%s\n", str[j]);
				for (i = 0; i < len + 1; i++) 
				{	 //길이를 len+1까지하여 최대길이+1(백스페이스 기회)까지만 입력
					c[i] = _getch();
					printf("%c", c[i]);
					if (i > 0 && c[i] == 8) 
					{
						c[i - 1] = ' '; //백스페이스로 이전입력 지움
						printf("%c\b", c[i - 1]);
						i -= 2; //지움으로 -1이 아닌 -2
					}
					else if ((c[i] != '\r') && (i == len)) 
					{
						str[j][len + 1] = NULL;
						printf("\b%c", str[j][len + 1]);
						printf("\n\n"); //마지막에 다른 문자 입력시 바로 백스페이스 기회없이 \n(행을두번바꾸어야함)
					}
					else if ((c[i] == '\r') && (i == len)) 
					{ //엔터입력시(i==len은 마지막을 표현)
						printf("\n\n"); //행을두번바꾸어야함
						break; //break for i
					}
					else if (c[i] == '\r') 
					{ //중간에 엔터를 누를경우 
						for (k = 0; k < i; k++)
							printf("%c", c[k]);
						i--; //반복문으로 인해 -1(입력문자가없었으므로)
					}
					else if ((c[i] != str[j][i]) && (i != len)) 
					{//다를경우(마지막줄은 바로 \n이므로 제외)
						printf("\a");
					}
					else 
					{
						;
					}

				}//for i
				for (k = 0; k < len; k++) 
				{
					if (c[k] != str[j][k]) 
					{
						wnum++;//오타일경우 
					}
				}
			}
			t = clock() - t;
			t /= 1000;

			// %연산자는 피연산자가 정수형이어야함 그래서 출력도 %d
			printf("%s님의 연습결과\n\n평균타수 : %.f타\n연습시간 : %.f분 %.d초\n정확도   : %.f%%",
				name, (60 / t) * 30, t / 60, (int)t % 60, ((30 - (float)wnum) / 30) * 100);

			_getch();
			system("cls");
		}

		if (menu == 2) {
			break;
		}
	}

	printf("\n프로그램 종료..\n");

	return 0;
}