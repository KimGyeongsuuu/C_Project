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
		case 1:  // 한글타자연습하러가기
		{
			while (1)
			{
				selectedMenu = Menu(First); // 긴글 짧은 글 선택
				if (selectedMenu == 2) // 2번째 화면에서 1번째 화면으로 뒤로가기
				{
					break;
				}
				switch (selectedMenu)
				{
				/*
				case 0:	// 긴글을 선택 했을때
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
				case 0:// 짧은글을 선택 했을때
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
				case 1:  // 설정
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

