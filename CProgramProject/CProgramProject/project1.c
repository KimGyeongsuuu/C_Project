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
		t = clock(); //���۽ð� ����
		if (menu == 1) 
		{
			for (j = 0; j < rows; j++) 
			{
				len = strlen(str[j]);
				printf("%s\n", str[j]);
				for (i = 0; i < len + 1; i++) 
				{	 //���̸� len+1�����Ͽ� �ִ����+1(�齺���̽� ��ȸ)������ �Է�
					c[i] = _getch();
					printf("%c", c[i]);
					if (i > 0 && c[i] == 8) 
					{
						c[i - 1] = ' '; //�齺���̽��� �����Է� ����
						printf("%c\b", c[i - 1]);
						i -= 2; //�������� -1�� �ƴ� -2
					}
					else if ((c[i] != '\r') && (i == len)) 
					{
						str[j][len + 1] = NULL;
						printf("\b%c", str[j][len + 1]);
						printf("\n\n"); //�������� �ٸ� ���� �Է½� �ٷ� �齺���̽� ��ȸ���� \n(�����ι��ٲپ����)
					}
					else if ((c[i] == '\r') && (i == len)) 
					{ //�����Է½�(i==len�� �������� ǥ��)
						printf("\n\n"); //�����ι��ٲپ����
						break; //break for i
					}
					else if (c[i] == '\r') 
					{ //�߰��� ���͸� ������� 
						for (k = 0; k < i; k++)
							printf("%c", c[k]);
						i--; //�ݺ������� ���� -1(�Է¹��ڰ��������Ƿ�)
					}
					else if ((c[i] != str[j][i]) && (i != len)) 
					{//�ٸ����(���������� �ٷ� \n�̹Ƿ� ����)
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
						wnum++;//��Ÿ�ϰ�� 
					}
				}
			}
			t = clock() - t;
			t /= 1000;

			// %�����ڴ� �ǿ����ڰ� �������̾���� �׷��� ��µ� %d
			printf("%s���� �������\n\n���Ÿ�� : %.fŸ\n�����ð� : %.f�� %.d��\n��Ȯ��   : %.f%%",
				name, (60 / t) * 30, t / 60, (int)t % 60, ((30 - (float)wnum) / 30) * 100);

			_getch();
			system("cls");
		}

		if (menu == 2) {
			break;
		}
	}

	printf("\n���α׷� ����..\n");

	return 0;
}