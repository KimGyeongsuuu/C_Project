#define _CRT_SECURE_NO_WARNINGS
#include "MY Project Header.h"
char First = 0;
int main()
{
	int flag = 0;
	char selectedMenu = 0;
	char keep = 0;
	char FirstselectedMenu = 0;
	char LongTextSelect = 0;
	char ShortTextSelect = 0;
	int Music = 0;
	int Rule = 0;
	system("title Typing Of Legend");
	system("cls");
	HideCursor();
	int id, password, result;
	while(1)
	{
		First = FirstPage();
		switch (First)
		{
		case 1:  // �ѱ�Ÿ�ڿ����Ϸ�����
		{
			while (1)
			{
				selectedMenu = Menu(First); // ��� ª�� �� ����
				if (selectedMenu == 2) // 2��° ȭ�鿡�� 1��° ȭ������ �ڷΰ���
				{
					break;
				}
				switch (selectedMenu)
				{
				/*
				case 0:	// ����� ���� ������
				{
					LongTextSelect = English_Selected(First);
					
					if (LongTextSelect == -1)
					{
						break;
					}
					while (1)
					{
						keep = English_LongText(LongTextSelect);
						if (keep != 1)
						{
							break;
						}
					}
				}
					break;
				*/
				case 0:// ª������ ���� ������
				{
					ShortTextSelect = English_Selected2(First);
					if (ShortTextSelect == -1)
					{
						break;
					}
					while (1)
					{
						keep = ShortText(ShortTextSelect);
						if (keep == -1)
						{

						}
						else if (keep != 1)
						{
							break;
						}
					}
					break;
				}
				case 1:  // ����
				{
					Music = Music_Setting();
				}
				}
			}
			break;
		}
		case 2:
			while (1)
			{
				Rule = GameRule();
				if (Rule == -1)
				{
					break;
				}
			}
		}
	}
}

