#include "MY Project Header.h"
const int BLUE = 1;
const int WHITE = 7;
const int RED = 4;
const int GREEN = 2;
const int LIGHTPurple = 13;
const int YELLOW = 6;
const int LightAqua = 11;
const int GRAY = 8;
int FirstPageCount = 0;
int i = 0;
int k = 0;
int score = 0;
int q = 0; // 선정된 노래
int noracountdown = 0; // 노래 카운트다운
int MusicCount = 0;
int TimeCounter = 0;
int Page_Count = 1;
int PlaySound_Select=0;
int MusicSelect = 0;int music = 0;
int time_count = 0;  // 시간 스타트는 처음에만 하기위해 만든 카운트
int timeout = 0;
int total_time = 0;
int ScoreCount = 0; // 점수
void Gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void HideCursor() // 커서를 숨김
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
unsigned _stdcall Thread_A(void* arg) // 긴 글 연습 시간
{
	int Mcount = 1;
	int Scount=0;
	while (1)
	{
		Gotoxy(93,22);
		if (Mcount < 9)
		{
			if (Scount < 9)
			{
				printf("0%d:0%d", Scount, ++Mcount);
				total_time++;
			}
			else
			{
			printf("%d:%d", Scount, ++Mcount);
			total_time++;
			}
		}
		else
		{
			if (Scount < 9)
			{
				printf("0%d:%d", Scount, ++Mcount);
				total_time++;
			}
			else
			{
				printf("%d:%d", Scount, ++Mcount);
				total_time++;
			}
		}
		if (Mcount == 60)
		{
			Mcount = 0;
			Scount += 1;
		}
		Sleep(1000);	
	}
}
unsigned _stdcall Thread_B(void* arg)
{
	switch(k)
	{
		case 0:
			while (1)
			{
				PlaySound(TEXT("BAD.wav"), NULL, SND_ASYNC);
			}
			break;
		case 1:
			while (1)
			{
				PlaySound(TEXT("para.wav"), NULL, SND_ASYNC);
			}
			break;
		case 2:
			while (1)
			{
				PlaySound(TEXT("2002.wav"), NULL, SND_ASYNC);
			}
			break;
		case 3:
			while (1)
			{
				PlaySound(TEXT("payphone.wav"), NULL, SND_ASYNC);
			}
	}
}
unsigned _stdcall Thread_C(void* arg) // 짧은 글 연습 시간
{

	int BadMcount = 3;
	int BadScount = 10;
	int ParachuteMcount = 2;
	int ParachuteScount = 32;
	int AnnaMcount = 3;
	int AnnaScount = 9;
	int PayphoneMcount = 3;
	int PayphoneScount = 52;
	while (1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		Gotoxy(68, 6);
		if (q == 0)
		{
			if (BadScount < 10)
			{
				printf("0%d:0%d", BadMcount, BadScount--);
				noracountdown++;
			}
			else
			{
				printf("0%d:%d", BadMcount, BadScount--);
				noracountdown++;
			}
			if (BadScount == -1)
			{
				BadMcount=BadMcount-1;
				BadScount = 59;
			}
			Sleep(1000);
		}
		else if (q == 1)
		{
			if (ParachuteScount < 10)
			{
				printf("0%d:0%d", ParachuteMcount, ParachuteScount--);
				noracountdown++;
			}
			else
			{
				printf("0%d:%d", ParachuteMcount, ParachuteScount--);
				noracountdown++;
			}
			if (ParachuteScount == -1)
			{
				ParachuteMcount = ParachuteMcount - 1;
				ParachuteScount = 59;
			}
			Sleep(1000);
		}
		else if (q == 2)
		{
			if (AnnaScount < 10)
			{
				printf("0%d:0%d", AnnaMcount, AnnaScount--);
				noracountdown++;
			}
			else
			{
				printf("0%d:%d", AnnaMcount, AnnaScount--);
				noracountdown++;
			}
			if (AnnaScount == -1)
			{
				AnnaMcount = AnnaMcount - 1;
				AnnaScount = 59;
			}
			Sleep(1000);
		}
		else if (q == 3)
		{
			if (PayphoneScount < 10)
			{
				printf("0%d:0%d", PayphoneMcount, PayphoneScount--);
				noracountdown++;
			}
			else
			{
				printf("0%d:%d", PayphoneMcount, PayphoneScount--);
				noracountdown++;
			}
			if (PayphoneScount == -1)
			{
				PayphoneMcount = PayphoneMcount - 1;
				PayphoneScount = 59;
			}
			Sleep(1000);
		}
	}
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
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");

}
void FinishPage()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	Gotoxy(45, 5);
	puts("타자연습이 종료되었습니다!!!\n\n\n\n\n\n\n\n\n\n\n\n");
}
char FirstPage()
{
	char FirstSelect;
	char ID, Password;
	int count = 0;
	int selecting2 = 1;
	HideCursor();
	system("cls");
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
	if (FirstPageCount == 0)
	{
		FirstPageCount++;
		Gotoxy(42, 6); printf("광"); Sleep(70);
		Gotoxy(44, 6); printf("주"); Sleep(70);
		Gotoxy(46, 6); printf("소"); Sleep(70);
		Gotoxy(48, 6); printf("프"); Sleep(70);
		Gotoxy(50, 6); printf("트"); Sleep(70);
		Gotoxy(52, 6); printf("웨"); Sleep(70);
		Gotoxy(54, 6); printf("어"); Sleep(70);
		Gotoxy(56, 6); printf("마"); Sleep(70);
		Gotoxy(58, 6); printf("이"); Sleep(70);
		Gotoxy(60, 6); printf("스"); Sleep(70);
		Gotoxy(62, 6); printf("터"); Sleep(70);
		Gotoxy(64, 6); printf("고"); Sleep(70);
		Gotoxy(66, 6); printf("등"); Sleep(70);
		Gotoxy(68, 6); printf("학"); Sleep(70);
		Gotoxy(70, 6); printf("교"); Sleep(70);
		Gotoxy(46, 7); printf("타"); Sleep(140);
		Gotoxy(52, 7); printf("자"); Sleep(140);
		Gotoxy(58, 7); printf("연"); Sleep(140);
		Gotoxy(64, 7); printf("습"); Sleep(140);
	}
	else
	{
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
		Gotoxy(46, 7); printf("타"); 
		Gotoxy(52, 7); printf("자"); 
		Gotoxy(58, 7); printf("연"); 
		Gotoxy(64, 7); printf("습"); 
}
	while (1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		Gotoxy(69, 29);
		puts("* 방향키로 이동, 스페이스바로 선택하세요.");
		if (selecting2 == 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
		}		
		Gotoxy(13, 15);
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
		for (int i = 16; i <= 25; i++)
		{
			Gotoxy(13, i);
			printf("┃");
		}
		for (int i = 16; i <= 25; i++)
		{
			Gotoxy(49, i);
			printf("┃");
		}
		Gotoxy(13, 26);
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		Gotoxy(20, 14);
		puts("영어타자연습하러 가기");
		Gotoxy(15, 17);
		puts("'영어 타자연습하러 가기'를 ");
		Gotoxy(15, 19);
		puts("선택하시면 자신의 영어 타자 실력을");
		Gotoxy(15, 21);
		puts("늘릴 수 있는 타자연습을 마음껏 ");
		Gotoxy(15, 23);
		puts("즐길 수 있습니다.");
		if (selecting2 == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
		}
		Gotoxy(60, 15);
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
		for (int i = 16; i <= 25; i++)
		{
			Gotoxy(60, i);
			printf("┃");
		}
		for (int i = 16; i <= 25; i++)
		{
			Gotoxy(96, i);
			printf("┃");
		}
		Gotoxy(60, 26);
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		Gotoxy(73, 14);
		puts("게임 설명");
		Gotoxy(63, 17);
		puts("'게임 설명'을");
		Gotoxy(63, 19);
		puts("선택하시면 이 타자연습에");
		Gotoxy(63, 21);
		puts("대한 설명을 듣고 ");
		Gotoxy(63, 23);
		puts("게임방법을 알게 될겁니다.");

		FirstSelect = _getch();
		if (FirstSelect == 75 || FirstSelect == 77)
		{
			switch (FirstSelect)
			{
				case 77: // 방향키 -> 를 눌렀을때
				{
					if (selecting2 == 1)
					{
						selecting2 = 2;
					}
					break;
				}
				case 75:  // 방향키 <- 를 눌렀을때
				{
					if (selecting2 == 2)
					{
						selecting2 = 1;
					}
					break;
				}
			}
			continue;
		}
		else if (FirstSelect == 32) // ENTER를 눌렀을때
		{
			break;
		}
		else if (FirstSelect == 27)  // ESC를 눌렀을때
		{
			system("cls");
			border();
			Gotoxy(46, 10);
			printf("종료되었습니다!!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			exit(0);
		}
	}
	return selecting2;
}
int Menu()
{
	system("cls");
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
	Gotoxy(46, 7); printf("타");
	Gotoxy(52, 7); printf("자");
	Gotoxy(58, 7); printf("연");
	Gotoxy(64, 7); printf("습");
	char selecting = 0; // NULL로 지정
	char Macro = 0;   // NULL로 지정
	const int Position[6] = { 12, 14, 16, 18, 20, 22 };

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	Gotoxy(69, 29);
	puts("* 방향키로 이동, 스페이스바로 선택해주세요.");
	while (1)
	{
		/*
		// 긴 글 연습
		if (selecting == 0) // 선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
		}
		else // 미선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
		}
		Gotoxy(49, 12);
		printf("긴 글 연습");
		*/

		// 짧은 글 연습
		if (selecting == 0) // 선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		}
		else  // 미선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
		}
		Gotoxy(48, 12);
		printf("짧은 글 연습");

		// 게임 방법
		if (selecting == 1)  // 선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
		}
		else  // 미선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
		}
		Gotoxy(52, 15);
		printf("설정");

		// 게임 방법
		if (selecting == 2)  // 선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LightAqua);
		}
		else  // 미선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
		}
		Gotoxy(49, 18);
		printf("뒤로 가기");


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
					selecting = 2;
				}
				break;
			}
			case 80: // 매크로를 DOWN 했을때
			{
				if (selecting < 2)
				{
					selecting++;
				}
				else if (selecting == 2)
				{
					selecting = 0;
				}
				break;
			}
			}
			continue;
		}
		else if (Macro == 32)
		{
			break;
		}
		else if (Macro == 27)  // ESC를 눌렀을때
		{
			system("cls");
			border();
			Gotoxy(46, 10);
			printf("종료되었습니다!!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			exit(0);
		}
	}
	return selecting;
}
void ScoreBoard()
{
	score++;
	char ch;
	system("cls");
	border();
	Gotoxy(40, 8);
	printf("┌─────────────────────────────┐");
	Gotoxy(40, 9);
	printf("│");
	Gotoxy(40, 10);
	printf("│");
	Gotoxy(40, 11);
	printf("│");
	Gotoxy(40, 12);
	printf("│");
	Gotoxy(40, 13);
	printf("│");
	Gotoxy(40, 14);
	printf("│");
	Gotoxy(40, 15);
	printf("│");
	Gotoxy(40, 16);
	printf("│");
	Gotoxy(70, 9);
	printf("│");
	Gotoxy(70, 10);
	printf("│");
	Gotoxy(70, 11);
	printf("│");
	Gotoxy(70, 12);
	printf("│");
	Gotoxy(70, 13);
	printf("│");
	Gotoxy(70, 14);
	printf("│");
	Gotoxy(70, 15);
	printf("│");
	Gotoxy(70, 16);
	printf("│");
	Gotoxy(70, 17);
	printf("│");
	Gotoxy(40, 17);
	printf("└─────────────────────────────┘");
	Gotoxy(44, 12);
	printf("점수 : %d", ScoreCount);
	if (q == 0)
	{
		Gotoxy(44, 14);
		printf("진행도 : %d/27",Page_Count);
	}
	else if (q == 1)
	{
		Gotoxy(44, 14);
		printf("진행도 : %d/36", Page_Count);
	}
	else if (q == 2)
	{
		Gotoxy(44, 14);
		printf("진행도 : %d/27", Page_Count);
	}
	else if (q == 3)
	{
		Gotoxy(44, 14);
		printf("진행도 : %d/41", Page_Count);
	}
	/*
	Gotoxy(44, 14);
	printf("다시 시작하겠습니까?(y/n)");
	ch = _getch();
	if (ch == 'y' || ch == 'Y')
	{
		
	}
	else if (ch == 'n' || ch == 'N')
	{
		exit(0);
	}
	*/

}
void LGameSetting()
{
	Gotoxy(45, 2);
	puts(" +------------------+ ");
	Gotoxy(46, 3);
	puts("|");
	Gotoxy(65, 3);
	puts("|");
	Gotoxy(45, 4);
	puts(" +------------------+ ");
	Gotoxy(51, 3);
	puts("긴 글 연습");
	Gotoxy(8, 5);
	puts("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	for (int i = 6; i <= 26; i++)
	{
		Gotoxy(8, i);
		puts("┃");
	}
	for (int i = 6; i <= 26; i++)
	{
		Gotoxy(110, i);
		puts("┃");
	}
	for (int i = 6; i <= 26; i++)
	{
		Gotoxy(83, i);
		puts("┃");
	}
	Gotoxy(8, 27);
	puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");


	for (int i = 7; i <= 23; i += 4)
	{

		Gotoxy(11, i);
		puts("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	}
	for (int i = 8; i <= 24; i += 4)
	{
		Gotoxy(11, i);
		puts("┃");
		Gotoxy(82, i);
		puts("┃");
	}
	for (int i = 9; i <= 25; i += 4)
	{
		Gotoxy(11, i);
		puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	}
	Gotoxy(85, 16);
	puts("━━━━━━━━━━━━━━━━━━━━━━━━");
	Gotoxy(86, 20);
	puts("현재 점수 : ");
	Gotoxy(86, 22);
	puts("시간  00:00");
}
void SGameSetting()
{
	Gotoxy(80, 29);
	puts("*종료하려면 ESC를 눌러주세요.");
	Gotoxy(45, 2);
	puts(" +------------------+ ");
	Gotoxy(46, 3);
	puts("|");
	Gotoxy(65, 3);
	puts("|");
	Gotoxy(45, 4);
	puts(" +------------------+ ");
	Gotoxy(50, 3);
	puts("짧은 글 연습");
	Gotoxy(6, 5);
	puts("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	Gotoxy(6, 6);
	puts("┃");
	Gotoxy(107, 6);
	puts("┃");
	Gotoxy(6, 7);
	puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	Gotoxy(7, 24);
	puts("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	Gotoxy(7, 25);
	puts("┃");
	Gotoxy(105, 25);
	puts("┃");
	Gotoxy(7, 26);
	puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	Gotoxy(17, 12);
	puts("┌─────────────────────────────────────────────────────────────────────────────┐");
	Gotoxy(17, 13);
	puts("┃");
	Gotoxy(95, 13);
	puts("┃");
	Gotoxy(17, 14);
	puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");

}
void Music_Setting()
{
	char Macro = 0;   // NULL로 지정
	system("cls");
	border();
	Gotoxy(50, 5);
	printf("음악 설정");
	system("cls");
	border();
	Gotoxy(47, 5);
	puts("음악 설정");
	Gotoxy(82, 29);
	puts("* 뒤로가려면 'b'를 눌러주세요.");
	Gotoxy(23, 20);
	puts("저희 타자게임은 타자연습을 하는 동안 선택한 노래를 들을 수 있습니다.");
	Gotoxy(28, 22);
	puts("하지만 노래를 듣기 싫으면 듣지 않아도 됩니다.");
	while (1)
	{
		if (MusicSelect== 0) // 노래있게
		{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else 
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
		Gotoxy(37, 9);
		puts("저는 노래 있게 플레이 하고 싶어요");
		if (MusicSelect == 1) // 노래없이
		{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else 
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
		Gotoxy(37, 14);
		puts("저는 노래 없이 플레이 하고 싶어요");
		Macro = _getch();
		if (Macro == 0x00 || Macro == 0xE0) // 오류 대비
		{
			Macro = _getch();
		}
		if (Macro == 66 || Macro == 98)
		{
			return -1;
		}
		if (Macro == 80 || Macro == 72)
		{
			switch (Macro)
			{
				case 72:// 매크로를 UP했을때
				{
					if (MusicSelect == 1)
					{
						MusicSelect=0;
					}
					else if (MusicSelect == 0)
					{
						MusicSelect = 1;
					}
					break;
				}
				case 80: // 매크로를 DOWN 했을때
				{
					if (MusicSelect == 1)
					{
						MusicSelect =0;
					}
					else if (MusicSelect == 0)
					{
						MusicSelect = 1;
					}
					break;
				}
			}
			continue;
		}
		else if (Macro == 32)
		{
			break;
		}
	}
	return MusicSelect;
}
int English_Selected(int Language)
{
	/*
	system("cls");
	int TextSelecting = 0; // NULL로 지정
	char Macro = 0;   // NULL로 지정
	int Page_Selecting = 1;
	border();
	Gotoxy(47, 5);
	puts("긴 글 선택");
	Gotoxy(82, 29);
	puts("* 뒤로가려면 'b'를 눌러주세요.");
	Gotoxy(85, 29);
	puts(" ");
	while (1)
	{
		// 긴 글 연습
		if (TextSelecting == 0) // 선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else // 미선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
		}
		Gotoxy(24, 8);
		puts("|");
		Gotoxy(24, 9);
		puts("|");
		Gotoxy(24, 7);
		puts("+-----------------------------------------------------------+");
		Gotoxy(84, 8);
		puts("|");
		Gotoxy(84, 9);
		puts("|");
		Gotoxy(24, 10);
		puts("+-----------------------------------------------------------+");
		Gotoxy(45, 8);
		puts("제목 : Shape of You");
		Gotoxy(45, 9);
		puts("가수 : Ed Sheeran");
		if (TextSelecting == 1) // 선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else  // 미선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
		}
		Gotoxy(24, 13);
		puts("|");
		Gotoxy(24, 14);
		puts("|");
		Gotoxy(24, 12);
		puts("+-----------------------------------------------------------+");
		Gotoxy(84, 13);
		puts("|");
		Gotoxy(84, 14);
		puts("|");
		Gotoxy(24, 15);
		puts("+-----------------------------------------------------------+");
		Gotoxy(45, 13);
		puts("제목 : MONEY");
		Gotoxy(45, 14);
		puts("가수 : Lisa");

		if (TextSelecting == 2)  // 선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else  // 미선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
		}
		Gotoxy(24, 18);
		puts("|");
		Gotoxy(24, 19);
		puts("|");
		Gotoxy(24, 17);
		puts("+-----------------------------------------------------------+");
		Gotoxy(84, 18);
		puts("|");
		Gotoxy(84, 19);
		puts("|");
		Gotoxy(24, 20);
		puts("+-----------------------------------------------------------+");

		Gotoxy(45, 18);
		puts("제목 : DanceMonkey");
		Gotoxy(45, 19);
		puts("가수 : Tones And I");
		if (TextSelecting == 3)  // 선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else  // 미선택
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
		}
		Gotoxy(24, 23);
		puts("|");
		Gotoxy(24, 24);
		puts("|");
		Gotoxy(24, 22);
		puts("+-----------------------------------------------------------+");
		Gotoxy(84, 23);
		puts("|");
		Gotoxy(84, 24);
		puts("|");
		Gotoxy(24, 25);
		puts("+-----------------------------------------------------------+");
		Gotoxy(45, 23);
		puts("제목 : Bad Habits");
		Gotoxy(45, 24);
		puts("가수 : Ed Sheeran");		
		

		Macro = _getch();
		if (Macro == 0x00 || Macro == 0xE0)
		{
			Macro = _getch();
		}
		if (Macro == 66 || Macro == 98)
		{
			return -1;
		}
		if (Macro == 80 || Macro == 72)
		{
			switch (Macro)
			{
			case 72:// 매크로를 UP했을때
			{
				if (TextSelecting > 0)
				{
					TextSelecting--;
				}
				else if (TextSelecting == 0)
				{
					TextSelecting = 3;
				}
				break;
			}
			case 80: // 매크로를 DOWN 했을때
			{
				if (TextSelecting < 3)
				{
					TextSelecting++;
				}
				else if (TextSelecting == 3)
				{
					TextSelecting = 0;
				}
				break;
			}
			}
			continue;
		}
		else if (Macro == 32)
		{
			break;
		}
	}
	return TextSelecting;
	*/ // 이 코드는 만들었지만 사용하지 않는 코드입니다 
	   // 하지만 버리기 진짜로 너무 아까워서 남겨둡니다.

}
int English_Selected2(int Language) 
{
	i = 0;
	system("cls");
	int selecting = 0; // NULL로 지정
	char Macro = 0;   // NULL로 지정	
	border();
	Gotoxy(42, 4);
	puts(" +------------------+ ");
	Gotoxy(43, 5);
	puts("|");
	Gotoxy(62, 5);
	puts("|");
	Gotoxy(42, 6);
	puts(" +------------------+ ");
	Gotoxy(47, 5);
	puts("짧은 글 선택");
	Gotoxy(82, 29);
	puts("* 뒤로가려면 'b'를 눌러주세요.");
	Gotoxy(78, 29);
	puts(" ");
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
		Gotoxy(46, 9);
		puts("제목 : BAD ");
		Gotoxy(46, 10);
		puts("가수 : Christopher    노래시간 : 3:10");


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
		Gotoxy(46, 14);
		puts("제목 : Parachute");
		Gotoxy(46, 15);
		puts("가수 : John K         노래시간 : 2:52");	


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
		Gotoxy(46, 19);
		puts("제목 : 2002");
		Gotoxy(46, 20);
		puts("가수 : Anna Marie     노래시간 : 3:09");

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
		Gotoxy(46, 24);
		puts("제목 : Payphone");
		Gotoxy(46, 25);
		puts("가수 : Maroon5        노래시간 : 3:52");



		Macro = _getch();
		if (Macro == 0x00 || Macro == 0xE0)
		{
			Macro = _getch();
		}
		if (Macro == 66 || Macro == 98)
		{
			return -1;
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
		else if (Macro == 32)
		{
			break;
		}
	}
	return selecting;
}  // 긴 글 연습 // 
int English_LongText(char x)
{
	/*

	char* shape[9][5] = { 
		                {"Shape of You",
						 "Me and my friends at the table doing shots drinking fast and then",
						 "we talk slow you come over and start up a conversation with just",
						 "me and trust me I'll give it a chance now Take my hand stop,",
						 "put van the man on the jukebox and then we start to dance And now"},
						{"I'm singing like Girl you know I want your love Your love was",
						 "handmade for somebody like me Come on now follow my lead I may be",
						 "crazy don't mind me Say boy let's not talk too much Grab on my waist",
						 "and put that body on me Come on now follow my lead Come come on now",
						 "follow my lead I'm in love with the shape of you We push and pull like"},
						{"a magnet do Although my heart is falling too I'm in love with your",
						 "body Last night you were in my room And now my bed sheets smell",
						 "like you Every day discovering something brand new I'm in love with",
						 "your body Oh I Oh I Oh I Oh I I'm in love with your body",
						 "Oh I Oh I Oh I Oh I'm in love with your body Oh I Oh I Oh I Oh"},
						{"I'm in love with your body Every day discovering something brand new",
						 "I'm in love with the shape of you One week in we let the story begin",
						 "We're going out on our first date You and me are thrifty",
						 "So go all you can eat Fill up your bag and I fill up a plate",
						 "We talk for hours and hours about the sweet and the sour"},
						{"And how your family's doing ok leave and get in a taxi,",
						 "then kiss in the backseat Tell the driver make the radio play",
						 "and I'm singing like Girl you know I want your love",
						 "Your love was handmade for somebody like me Come on now follow",
						 "my lead I may be crazy, don't mind me Say boy let's not talk too"},
						{"much Grab on my waist and put that body on me Come on now follow",
						 "Come on now follow my lead Come come on now follow my lead I'm in love",
						 "with the shape of you We push and pull like a magnet do Although my",
						 "heart is falling too I'm in love with your body Last night you were",
						 "in my room And now my bed sheets smell like you Every day discovering"},
						{"something brand new Well I'm in love with your body Oh I Oh I Oh I Oh",
						 "I'm in love with your body Oh I Oh I Oh I Oh I'm in love with",
						 "your body Oh I Oh I Oh I Oh I'm in love with your body Every day",
						 "discovering something brand new I'm in love with the shape of you Come",
						 "on be my baby come on Come on be my baby come on Come on be my baby"},
						{"come on Come on be my baby come on Come on be my baby come on",
						 "Come on be my baby come on Come on be my baby come on Come on be my",
						 "baby come on I'm in love with the shape of you We push and pull like",
						 "a magnet do Although my heart is falling too I'm in love with",
						 "your body Last night you were in my room And now my bed sheets smell"},
						{"like you Every day discovering something brand new Well I'm in love",
						 "with your body Come on be my baby come on Come on be my baby",
						 "come on Come on be my baby come on Come on be my baby come on Come",
						 "on be my baby come on Come on be my baby come on Every day",
						 "discovering something brand new I'm in love with the shape of you"}
	                    };
	char* money[6][5] = { {"Money",
							"It's the end of the month And the Weekend Imma spend this check",
							"Weekend Imma spend this check Everything on me yeah Imma tip",
							"Myself Imma spend it on myself Imma drop it like it's pouring",
							"Imma pour it on myself Check Check Check Check that money making bank"},
							{"account number That's that shiz that's never getting bounced on ya",
							 "Bish I do the money dance I just made a hundred bands When the store",
							"says sign for it Imma leave my autograph Dolla bills Dolla bills",
							"Watch it fallin for me I love the way that feels Dolla bills Dolla",
							"bills Keep on fallin for me I love bills Keep on fallin for me I"},
							{"love the way it feels I came here to Drop some money Dropping",
							"all my Money Drop some money All this bread so yummy yeah Twerking",
							"twerking When I buy the thingsI like Dolla dollas Dropping on my",
							"ass tonight Everyone silent Listen to my money talk Spend how I like",
							"it Yeah everyone know what I mean mean When they see green When they"},
							{"see green that mean go Give me what the hell I want Give me what the",
							"hell I want Check that money making bank account number That's that",
							"shiz that's never getting bounced on ya Bish I do the money dance I",
							"just made a hundred bands When the store says sign for it Imma leave",
							"my autograph Dolla bills Dolla bill Watch it fallin for me I love the"},
							{"way that feels Dolla bills Dolla bills Keep on fallin for me I love",
							"the way it feels I came here to Drop some money Dropping all my",
							"Money Drop some money All this bread so",
							"yummy yeah Twerking twerking When I buy the things I",
							"like Dolla dollas Dropping on my ass tonight Drop some money"},
							{"Dropping all my money Drop some Money All this bread so yummy yeah",
							"Drop some money Dropping all my Money Drop some money All this",
							"bread so yummy yeah My money moves Money I choose Celine my shoes",
							"Walkin on you My money rules My money moves Money I choose Watch",
							"how my wons and yens and dollars be Droppin on you" }
	};
	char* DanceMonkey[6][5] = { {"Dance Monkey",
							   "They say, Oh my god I see the way you shine Take your hand, my dear",
							   "and place them both in mine You know you stopped me dead when I was",
							   "passing by And now I beg to see you dance just one more time Ooh, I",
							   "see you, see you, see you every time And I, I, I, I like your style"},
							  {"You you make me, make me, make me wanna cry And now I beg to see you",
							   "dance just one more time So I say Dance for me, dance for me, dance",
							   "for me, oh oh oh I've never seen anybody do the things you do before",
							   "They say Move for me, move for me, move for me, ay ay ay And when",
							   "you're done I'll make you do it all again I said, Oh my god I see you"},
							  {"walking By Take my hands, my dear and look me in my eyes Just like a",
							   "monkey, I've been dancing my whole life And you just beg to see me",
							   "dance just one more time Ooh, I see you, see you, see you every time",
							   "And I, I, I, I like your style You, you make me make me, make me",
							   "wanna cry And nowI beg to see you dance just one more time So I say"},
							  {"Dance for me dance for me, dance for me, oh oh oh I've never seen",
							   "anybody do the things you do before They say Move for me, move for me",
							   "move for me ay ay ay And when you're done I'll make you do it all",
							   "again They say Dance for me, dance for me, dance for me, oh oh oh,oh",
							   "oh-oh I've never seen anybody do the things you do before They say"},
							  {"Move for me, move for me, move for me, ay ay ay And",
							   "when you're done I'll make you do it all again Ooh,",
							   "ooh, ooh, ooh, ooh Oh-oh, oh-oh ,oh Ooh, ooh, ooh, ooh,",
							   "oh-ooh Ooh, ah-ah, ah-ah They say Dance for medance for",
							   " me dance for me, oh oh oh I've never seen anybody do the"},
							  {"things you do before They say Move for me, move ",
							   "for me, move for me ay ay ay",
							   "And when you're done I'll make you",
							   "do it all"," again"}

	                         };
	char* badhabits[6][5] = { {"Bad Habits",
								"Every time you come around you know I can't say no Every time the sun",
								"goes down I let you take control I can feel the paradise before my",
								"world implodes and tonight had something wonderful My bad habits",
								"lead to late nights ending alone Conversations with a stranger I"},
								{"barely know Swearing this will be the last but it probably won't I've",
								 "got nothing left to lose, or use or do My bad habits to lead to wide",
								 "eyes stare into space And I know I lose control of the things that I",
								 "say I was looking for a way out, now I can't escape Nothing happens",
								 "after two It's true it's true My bad habits lead to you My bad"},
								{"habits lead to you My bad habits lead to you Every pure intention ends",
								 "when the good times start Falling over everything to reach the first",
								 "times spark Started under neon lights then it all got dark I only",
								 "know how to go too far My bad habit lead to late nights ending alone",
								 "Conversations with a stranger I barely know Swearing this will be"},
								{"the last but it probably won't I've got nothing left to lose, or use,",
								 "or do My bad habits to lead to wide eyes stare into space",
								 "And I know I lose control of the things that I say I was looking for",
								 "a way out, now I can't escape Nothing happens after two It's",
								 "true it's true My bad habits lead to you My bad habits lead to you"},
								{"We took the long way round And burned til the fun ran out, now My",
								 "bad habits lead to late nights ending alone Conversations with a",
								 "stranger I barely know Swearing this will be the last but it",
								 "probably won't I've got nothing left to lose, or use, or do My bad",
								 "habits to lead to wide eyes stare into space And I know I lose"},
		                        {"control of the things that I say I was looking for a way out, now I",
								 "can't escape Nothing happens after",
								 "two It's true it's trueMy bad habits lead to you",
								 "My bad habits lead to you",
								 "My bad habits lead to you"}
	                             };
	char ch;
	char input[100] = { 0 };
	char answer[5][100] = { 0 };
	int FLAG = 0;
	int count = 0;
	int k = 0;
	int Music_Count = 0;
	int Time = 0;
	system("cls");
	border();
	LGameSetting();
	LookingCursor();
	while (1)
	{
		switch (x)
		{
		case 0: // shape of you
			if (MusicSelect == 1)
			{
				PlaySound(TEXT("shape of you.wav"), NULL, SND_ASYNC);
			}
			for (int i = 0; i < 9; i++)
			{
				Gotoxy(86, 18);
				puts("현재 노래 : Shape of You");
				Gotoxy(87, 24);
				printf("페이지 : %d / 9", i + 1);
				Gotoxy(13, 6);
				printf("                                                                      ");
				Gotoxy(13, 6);
				printf("%s", shape[i][0]);
				strcpy(answer[0], shape[i][0]);
				Gotoxy(13, 10);
				printf("                                                                      ");
				Gotoxy(13, 10);
				printf("%s", shape[i][1]);
				strcpy(answer[1], shape[i][1]);
				Gotoxy(13, 14);
				printf("                                                                      ");
				Gotoxy(13, 14);
				printf("%s", shape[i][2]);
				strcpy(answer[2], shape[i][2]);
				Gotoxy(13, 18);
				printf("                                                                      ");
				Gotoxy(13, 18);
				printf("%s", shape[i][3]);
				strcpy(answer[3], shape[i][3]);
				Gotoxy(13, 22);
				printf("                                                                      ");
				Gotoxy(13, 22);
				printf("%s", shape[i][4]);
				strcpy(answer[4], shape[i][4]);
				for (int j = 8; j <= 24; j += 4)
				{
					Gotoxy(13, j);
					while (1)
					{
						if (_kbhit())
						{
							if (Time == 0)
							{
								_beginthreadex(NULL, 0, Thread_A, 0, 0, NULL);
								Time = 1;
							}
							ch = _getch();
							if (ch == 9)
							{
								return 0;
							}
							if (ch == 27)
							{
								system("cls");
								border();
								Gotoxy(50, 5);
								printf("종료되었습니다!!");
								exit(0);
							}
							if (ch == 8)
							{
								if (count > 0)
								{
									if (input[count - 1] >= 32 && input[count - 1] <= 127)
									{
										input[count - 1] = NULL;
										count -= 1;
									}
									if (strcmp(input, answer[k]) == 0)
									{
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
									}
									if (strstr(answer, input) == NULL)
									{
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
									}
									Gotoxy(13, j);
									printf("%60c", ' ');
									Gotoxy(13, j);
									printf("%s", input);
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
								}
							}
							else if (ch == 13)
							{
								FLAG = 1;
								// 입력받을 배열 초기화
								for (int k = 0; k < 100; k++)
								{
									input[k] = NULL;
								}
								// 입력한 값이 없으므로 count 변수 초기화
								count = 0;
								Gotoxy(13, j + 4);
								break;
							}
							else
							{
								input[count++] = ch;
								printf("%c\b ", input[count - 1]);
								if (strcmp(input, answer[k]) == 0)
								{
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
								}
								if (strstr(answer, input) == NULL)
								{
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
								}
								// 문자열 출력 문제 해결 위해 지우고 문자열 자체 출력
								for (int k = 0; k < 100; k++)
								{
									input[k] = NULL;
								}

								Gotoxy(13, j);
								printf("%60c", ' ');
								Gotoxy(13, j);
								printf("%s", input);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
							}
							if (FLAG == 1)
							{
								// 입력받을 배열 초기화
								for (int i = 0; i < 100; i++)
								{
									input[i] = NULL;
								}
								count = 0;
								FLAG = 0;
							}
						}
						k++;
					}
				}
				for (int u = 8; u <= 24; u += 4)
				{
					Gotoxy(13, u);
					printf("                                                                     ");
				}

			}
			break;
		case 1: // money
			if (MusicSelect == 1)
			{
				PlaySound(TEXT("money.wav"), NULL, SND_ASYNC);
			}
			for (int i = 0; i < 6; i++)
			{
				Gotoxy(86, 18);
				puts("현재 노래 : Money");
				Gotoxy(87, 24);
				printf("페이지 : %d / 6", i+1);
				Gotoxy(13, 6);
				printf("                                                                      ");
				Gotoxy(13, 6);
				printf("%s", money[i][0]);
				strcpy(answer[0], money[i][0]);
				Gotoxy(13, 10);
				printf("                                                                      ");
				Gotoxy(13, 10);
				printf("%s", money[i][1]);
				strcpy(answer[1], money[i][1]);
				Gotoxy(13, 14);
				printf("                                                                      ");
				Gotoxy(13, 14);
				printf("%s", money[i][2]);
				strcpy(answer[2], money[i][2]);
				Gotoxy(13, 18);
				printf("                                                                      ");
				Gotoxy(13, 18);
				printf("%s", money[i][3]);
				strcpy(answer[3], money[i][3]);
				Gotoxy(13, 22);
				printf("                                                                      ");
				Gotoxy(13, 22);
				printf("%s", money[i][4]);
				strcpy(answer[4], money[i][4]);
				for (int i = 8; i <= 24; i += 4)
				{
					Gotoxy(13, i);
					while (1)
					{
						if (_kbhit())
						{
							if (Time == 0)
							{
								_beginthreadex(NULL, 0, Thread_A, 0, 0, NULL);
								Time++;
							}
							ch = _getch();
							if (ch == 9)
							{
								return 0;
							}
							if (ch == 27)
							{
								system("cls");
								border();
								Gotoxy(50, 5);
								printf("종료되었습니다!!");
							}
							if (ch == 8)
							{
								if (count > 0)
								{
									if (input[count - 1] >= 32 && input[count - 1] <= 127)
									{
										input[count - 1] = NULL;
										count -= 1;
									}
	
									if (!strcmp(input, answer))
									{
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
									}
									if (strstr(answer, input) == NULL)
									{
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
									}
									Gotoxy(13, i);
									printf("%60c", ' ');
									Gotoxy(13, i);
									printf("%s", input);

									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
								}
							}
							else if (ch == 13)
							{
								// 일치하면 정답처리
								if (!strcmp(input, answer))
								{
									FLAG = 1;
								}
								// 일치하지 않으면 안내
								else
								{
									// 입력받을 배열 초기화
									for (int k = 0; k < 100; k++)
									{
										input[k] = NULL;
									}
									// 입력한 값이 없으므로 count 변수 초기화
									count = 0;
									Gotoxy(13, i);
								}
								break;
							}
							else
							{
								input[count++] = ch;
								printf("%c\b ", input[count - 1]);
								if (!strcmp(input, answer)) 
								{
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
								}
								if (strstr(answer, input) == NULL) 
								{
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
								}
								Gotoxy(13, i);
								printf("%60c", ' ');
								Gotoxy(13, i);
								printf("%s", input);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
							}
							if (FLAG == 1)
							{
								// 입력받을 배열 초기화
								for (int i = 0; i < 100; i++)
								{
									input[i] = NULL;
								}
								count = 0;
								FLAG = 0;
							}
						}
						k++;
					}
				}
				for (int u = 8; u <= 24; u += 4)
				{
					Gotoxy(13, u);
					printf("                                                                     ");
				}
			}
			break;
		case 2: // dancemonkey
			if (MusicSelect == 1)
			{
				PlaySound(TEXT("dancemonkey.wav"), NULL, SND_ASYNC);
			}
			for (int i = 0; i < 6; i++)
			{
				Gotoxy(86, 18);
				puts("현재 노래 : DanceMonkey");
				Gotoxy(87, 24);
				printf("페이지 : %d / 6", i + 1);
				Gotoxy(13, 6);
				printf("                                                                      ");
				Gotoxy(13, 6);
				printf("%s", DanceMonkey[i][0]);
				strcpy(answer[0], DanceMonkey[i][0]);
				Gotoxy(13, 10);
				printf("                                                                      ");
				Gotoxy(13, 10);
				printf("%s", DanceMonkey[i][1]);
				strcpy(answer[1], DanceMonkey[i][1]);
				Gotoxy(13, 14);
				printf("                                                                      ");
				Gotoxy(13, 14);
				printf("%s", DanceMonkey[i][2]);
				strcpy(answer[2], DanceMonkey[i][2]);
				Gotoxy(13, 18);
				printf("                                                                      ");
				Gotoxy(13, 18);
				printf("%s", DanceMonkey[i][3]);
				strcpy(answer[3], DanceMonkey[i][3]);
				Gotoxy(13, 22);
				printf("                                                                      ");
				Gotoxy(13, 22);
				printf("%s", DanceMonkey[i][4]);
				strcpy(answer[4], DanceMonkey[i][4]);
				for (int i = 8; i <= 24; i += 4)
				{
					Gotoxy(13, i);
					while (1)
					{
						if (_kbhit())
						{
							if (Time == 0)
							{
								_beginthreadex(NULL, 0, Thread_A, 0, 0, NULL);
								Time++;
							}
							ch = _getch();
							if (ch == 27)
							{
								return 0;
							}
							if (ch == 9)
							{
								system("cls");
								border();
								Gotoxy(50, 5);
								printf("종료되었습니다!!");
							}
							if (ch == 8)
							{
								if (count > 0)
								{
									if (input[count - 1] >= 32 && input[count - 1] <= 127)
									{
										input[count - 1] = NULL;
										count -= 1;
									}
									if (!strcmp(input, answer))
									{
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
									}
									if (strstr(answer, input) == NULL)
									{
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
									}
									Gotoxy(13, i);
									printf("%60c", ' ');
									Gotoxy(13, i);
									printf("%s", input);

									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
								}
							}
							else if (ch == 13)
							{
								// 일치하면 정답처리
								if (!strcmp(input, answer))
								{
									FLAG = 1;
								}
								// 일치하지 않으면 안내
								else
								{
									// 입력받을 배열 초기화
									for (int k = 0; k < 100; k++)
									{
										input[k] = NULL;
									}
									// 입력한 값이 없으므로 count 변수 초기화
									count = 0;
									Gotoxy(13, i);
								}
								break;
							}
							else
							{
								// 한글은 2Byte이므로 두 칸에 저장한다. (영어의 경우도 각각 한 칸에 저장된다.)
								input[count++] = ch;
								if (_kbhit())
								{
									ch = _getch();
									input[count++] = ch;
									// 한글의 경우 두 바이트를 함께 출력해야 한다.
									printf("%c", input[count - 2]);
								}
								printf("%c\b ", input[count - 1]);

								// 사용자에게 상태 알려줌
								// 잘 치고 있으면 흰색
								// 틀리게 치고 있으면 빨강
								// 완전히 맞으면 초록
								if (!strcmp(input, answer)) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
								}
								if (strstr(answer, input) == NULL) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
								}

								// 문자열 출력 문제 해결 위해 지우고 문자열 자체 출력

								Gotoxy(13, i);
								printf("%60c", ' ');
								Gotoxy(13, i);
								printf("%s", input);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
							}
						}
					}
					k++;
				}
				for (int u = 8; u <= 24; u += 4)
				{
					Gotoxy(13, u);
					printf("                                                                     ");
				}
			}
			break;
		case 3: // badhabits
			if (MusicSelect == 1)
			{
				PlaySound(TEXT("badhabits.wav"), NULL, SND_ASYNC);
			}
			for (int i = 0; i < 6; i++)
			{
				Gotoxy(86, 18);
				puts("현재 노래 : BadHabits");
				Gotoxy(87, 24);
				printf("페이지 : %d / 11", i + 1);
				Gotoxy(13, 6);
				printf("                                                                      ");
				Gotoxy(13, 6);
				printf("%s", badhabits[i][0]);
				strcpy(answer[0], badhabits[i][0]);
				Gotoxy(13, 10);
				printf("                                                                      ");
				Gotoxy(13, 10);
				printf("%s", badhabits[i][1]);
				strcpy(answer[1], badhabits[i][1]);
				Gotoxy(13, 14);
				printf("                                                                      ");
				Gotoxy(13, 14);
				printf("%s", badhabits[i][2]);
				strcpy(answer[2], badhabits[i][2]);
				Gotoxy(13, 18);
				printf("                                                                      ");
				Gotoxy(13, 18);
				printf("%s", badhabits[i][3]);
				strcpy(answer[3], badhabits[i][3]);
				Gotoxy(13, 22);
				printf("                                                                      ");
				Gotoxy(13, 22);
				printf("%s", badhabits[i][4]);
				strcpy(answer[4], badhabits[i][4]);
				for (int j = 8; j <= 24; j += 4)
				{
					Gotoxy(13, j);
					while (1)
					{
						if (_kbhit())
						{
							if (Time == 0)
							{
								_beginthreadex(NULL, 0, Thread_A, 0, 0, NULL);
								Time++;
							}
							ch = _getch();
							if (ch == 9)
							{
								return 0;
							}
							if (ch == 27)
							{
								system("cls");
								border();
								Gotoxy(50, 5);
								printf("종료되었습니다!!");
								exit(0);
							}
							if (ch == 8)
							{
								if (count > 0)
								{
									if (input[count - 1] >= 32 && input[count - 1] <= 127)
									{
										input[count - 1] = NULL;
										count -= 1;
									}
									if (strcmp(input, answer[k]) == 0)
									{
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
									}
									if (strstr(answer, input) == NULL)
									{
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
									}
									Gotoxy(13, j);
									printf("%60c", ' ');
									Gotoxy(13, j);
									printf("%s", input);
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
								}
							}
							else if (ch == 13)
							{
								// 일치하면 정답처리
								if (!strcmp(input, answer[k]))
								{
									FLAG = 1;
								}
								// 일치하지 않으면 안내

								// 입력받을 배열 초기화
								for (int k = 0; k < 100; k++)
								{
									input[k] = NULL;
								}
								// 입력한 값이 없으므로 count 변수 초기화
								count = 0;
								Gotoxy(13, j);
								break;
							}
							else
							{
								// 한글은 2Byte이므로 두 칸에 저장한다. (영어의 경우도 각각 한 칸에 저장된다.)
								input[count++] = ch;
								if (_kbhit())
								{
									ch = _getch();
									input[count++] = ch;
									// 한글의 경우 두 바이트를 함께 출력해야 한다.
									printf("%c", input[count - 2]);
								}
								printf("%c\b ", input[count - 1]);

								// 사용자에게 상태 알려줌
								// 잘 치고 있으면 흰색
								// 틀리게 치고 있으면 빨강
								// 완전히 맞으면 초록
								if (strcmp(input, answer[k]) == 0)
								{
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
								}
								if (strstr(answer, input) == NULL)
								{
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
								}
								// 문자열 출력 문제 해결 위해 지우고 문자열 자체 출력

								Gotoxy(13, j);
								printf("%60c", ' ');
								Gotoxy(13, j);
								printf("%s", input);
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
							}
							if (FLAG == 1)
							{
								// 입력받을 배열 초기화
								for (int i = 0; i < 100; i++)
								{
									input[i] = NULL;
								}
								count = 0;
								FLAG = 0;
							}
						}
					}
					k++;
				}
				for (int u = 8; u <= 24; u += 4)
				{
					Gotoxy(13, u);
					printf("                                                                     ");
				}
			}
			break;
		}
	}
	*/
}
int ShortText(int y)
{
	if (score == 0)
	{
		q = y;
		music = y;
		timeout = y;
		// BAD
		char BAD[27][100] = { "BAD",
							 "I don't wanna be another him, that shit is over Finally, you found",
							 "yourself a friend and you run him over Ever since the start. I saw",
							 "the end around the corner Cause I know you so well So predictable",
							 "You're an animal I can't let you go You're so good at being bad, you",
							 "Know So predictable You're an Animal I can't let you go You're so",
							 "good at being bad uh My baby's bad you know My baby's bad, you know My",
							 "baby, my, my, my baby's bad, you know My, my baby's bad, you know My",
							 "my baby's bad, you know My baby, my, my, my baby's bad you know You know",
							 "I'm not gonna leave your side, and I can't deny it Tried to play it",
							 "cool but I can't hide my true desire Cause I can see the dirty in",
							 "your eyes, my favorite liar And I know you so well, well, well, well",
							 "So predictable You're an animal I can't let you go You're so good at",
							 "being bad, you know So predictable You're an animal I can't let you go",
							 "You're so good at being bad (uh) My baby's bad, you know",
							 "My baby's bad, you know My baby, my, my, my baby's bad, you",
							 "know My, my baby's bad, you know My, my baby's bad, you know",
							 "My baby, my, my, my baby's bad, you know I can see the way you look at",
							 "me, waiting to attack You are on your worst behaviour, I want it",
							 "just like that I can see the way you look at me, waiting to attack",
							 "You are on your worst behaviour, I want it just like that (uh)",
							 "My baby's bad, you know My baby's bad, you know",
							 "My baby, my, my, my baby's bad, you Know My, my baby's bad, you know My",
							 "my baby's bad, you know My baby, my my, my baby's bad, you know So",
							 "predictable You're an animal I can't let you go You're so good at",
							 "being bad, you know So predictable You're an animal I can't let you go",
							 "You're so good at being bad (uh)"

		};
		// PARACHUTE
		char PARACHUTE[36][100] = {
								 "Parachute",
								 "Vibin', we could talk all night or sit in silence",
								 "Watchin' shitty movies, gettin' high movies, gettin'",
								 "high and Laughin' about nothing much at all And",
								 "that's cool with me Losin' control but I like it",
								 "What you doin' to me, doin' to me?",
								 "You got a hold of my psychic And that's",
								 "alright with me I don't know what's happenin Lately",
								 "I've been someone and it ain't Myself I'm spendin'",
								 "all my time on somebody else I'm feelin' all these",
								 "feelings I don't understand You're the one",
								 "good thing I ain't questionin' Like ooh, if I knew that it",
								 " would kill me I would still be here a thousand",
								 "time over If that’s the consequence of lovin' you ",
								 "Then I will fall without a parachutе Da da da da da",
								 "da da, da da, da da da da da, da da Then I will fall",
								 "without parachute Da da, da da da da da, da da, da da",
								 "da-da-da, da-da-da Fingers, wrappеd around me And",
								 "I'm thinkin' three words Got me thinkin' diamonds and",
								 "I usually take my time, yeah I just can't believe it,",
								 "all the ways that you blow my mind, yeah Everyone can",
								 "see it Lately, I've been someone and it ain't myself",
								 "I'm spendin all my time on somebody else I'm",
								 "feelin' all these feelings I don't understand",
								 "You're the one good thing I ain't questionin' Like ooh",
								 "thing I ain't questionin' Like ooh if I knew that it would",
								 "kill me I would still be here a thousand time",
								 "over yeah If that's the consequence of lovin you",
								 "Then I will fall without parachute Da da da da da da",
								 "da da da da da da da da da da Then I will fall without",
								 "a parachute Da da, da da da da da, da da, da da da",
								 "da da, da da da Then I will fall without a parachute",
								 " Da da, da da da da da, da da, da da da da da, da da",
								 "da Then I will fall without a parachute Da da, da",
								 "da da da da da da, da da da da da, da da da Then I",
								 "will fall without a parachute"
		};
		// 2002
		char Anna2002[27][100] = {
						  "2002",
						  "I will always remember The day you kissed my lips Light as a feather",
						  "And it went just like this No, it's never been better Than the summer",
						  "of 2002 We were only eleven But acting like grownups Like we are in",
						  "the present Drinking from plastic cups Singing love is forever and",
						  "ever Well, I guess that was true Dancing on the hood in the middle",
						  "of the woods On an old Mustang where we sang Songs with all our",
						  "childhoods friends And it went like this, say Oops I got 99 problems",
						  "singing bye, bye, bye Hold up, if you wanna go and take a ride with me",
						  "Better hit me, baby, one more time Paint a picture for you and me Of",
						  "the days when we were young Singing at the top of both our lung",
						  "Now we're under the covers Fast forward to eighteen We are more",
						  "than lovers Yeah we are all we need When we're holding each other I'm",
						  "taken back to 2002 Dancing on the hood in the middle of the woods On",
						  "an old Mustang, where we sang Songs with all our childhoods friends And",
						  "it went like this, say Oops I got 99 problems singing bye, bye, bye",
						  "Hold up, if you wanna go and take a ride with me Better hit me, baby,",
						  "one more time Paint a picture for you and me Of the days when we were",
						  "young Singing at the top of both our lungs On the day we fell in love",
						  "On the day we fell in love Dancing on the hood in the middle of the",
						  "woods On an old Mustang, where we sang Songs with all our childhoods",
						  "friends Oh, now Oops I got 99 problems singing bye, bye, bye Hold",
						  "up, if you wanna go and take a ride with me Better hit me, baby, one",
						  "more time Paint a picture for you and me Of the days when we were",
						  "young Singing at the top of both our lungs On the day we fell in love",
						  "On the day we fell in love On the day we fell in love",
						  "On the day we fell in love, love, love" };
		// payphone
		char payphone[41][100] = {
									"Payphone",
								   "I'm at a payphone trying to call Home All of my change I've spent on",
								   "Home All of my change I've spent on You Where are the times gone baby",
									"It's all wrong, where are the plans we made for two Yeah, I, I know",
									"it's hard to remember The people we used to be It's even harder to",
									"picture That you're not here next to me You said it's too late to",
									"make it But is it too late to try? And in our time that you wasted All",
									"of our bridges burned down I've wasted my nights You turned out the",
									"lights Now I'm paralyzed Still stucked in that time when we called",
									"it love But even the sun sets in paradise I'm at a payphone trying",
									"to call home All of my change I've spent on you Where are the times",
									"gone baby It's all wrong, where are the plans we made for two If Happy",
									"ever after did exist, I would still be holding you like this All those",
									"fairy tales are full of it One more stupid love song, I'll be sick You",
									"turned your back on tomorrow Cause you forgot yesterday I gave you my",
									"love to borrow But you just gave it away You can't expect me to be a",
									"fine I don't expect you to care I know I said it before But all of",
									"our bridges burnt down I've wasted my nights You turned out the lights",
									"Now I'm paralyzed Still stucked in that time when we called it love",
									"But even the sun sets in paradise I'm at a payphone trying to call",
									"Home All of my change I've spent on You Where are the times gone baby",
									"It's all wrong, where are the plans we made for two If Happy ever after",
									"did exist, I would still be holding you like this All those",
									"fairy tales are full of it One more stupid love song, I'll be sick Now",
									"I’m at a payphone Man fuck that shit I'll be right here spending all",
									"this money while you sitting round Wondering why wasn't you who came",
									"out from nothing Made it from the botton Now when you see me I'm",
									"strutting And all of my cause a way to push up a button Telling me the",
									"chances I blew up or whatever you call it Switched the number to my",
									"phone So you never can call it Don't need my name, or my show You can",
									"tell it I'm ballin' Shish, what a shame coulda got picked Had a",
									"really good game but you missed your last shot So you talk about",
									"who you see at the top Or what you could've saw But sad to say it's",
									"over for it Phantom roll out valet open doors Where's the car way got",
									"what you was looking for Now ask me who they want So you can go take",
									"that little piece of shit with you I'm at a payphone trying to call",
									"home All of my change I've spent on It's all wrong, where are the plans",
									"you Where are the times gone baby It's all wrong, where are the plans",
									"we made for two If happy ever after did exist I would still be holding",
									"you like this And all these fairytales are full of shit One",
									"more fucking love song I'll be sick Now I'm at a payphone"
		};
		char input[100], answer[100];
		int count = 0; // 글자 수 count
		char ch, FLAG = 0;
		int len = 0;
		int START_TIME;
		char Typing_count = 0;
		int start = 0;
		int Music_Count = 0;
		system("cls");
		border();
		SGameSetting();
		Gotoxy(37, 6);
		printf("현재 점수 : %d", ScoreCount);
		if (y == 0)
		{

			Gotoxy(11, 6);
			printf("현재 노래 : BAD");
			Gotoxy(63, 6);
			puts("시간 03:10 ");
			if (Page_Count == 28)
			{
				ScoreBoard();
			}
			Gotoxy(83, 6);
			printf("진행도 : %d / 27", Page_Count++);
			Gotoxy(22, 13);
			printf("%s", BAD[i]);
			strcpy(answer, BAD[i]);
			i++;
		}
		else if (y == 1)
		{

			Gotoxy(10, 6);
			printf("현재 노래 : Parachute");
			Gotoxy(63, 6);
			puts("시간 02:33 ");
			if (Page_Count == 37)
			{
				ScoreBoard();
			}
			Gotoxy(83, 6);
			printf("진행도 : %d / 36", Page_Count++);
			Gotoxy(22, 13);
			printf("%s", PARACHUTE[i]);
			strcpy(answer, PARACHUTE[i]);
			i++;
		}
		else if (y == 2)
		{
			Gotoxy(11, 6);
			printf("현재 노래 : 2002");
			Gotoxy(63, 6);
			puts("시간 03:09 ");
			if (Page_Count == 28)
			{
				ScoreBoard();
			}
			Gotoxy(83, 6);
			printf("진행도 : %d / 27", Page_Count++);
			Gotoxy(22, 13);
			printf("%s", Anna2002[i]);
			strcpy(answer, Anna2002[i]);
			i++;
		}
		else if (y == 3)
		{
			Gotoxy(10, 6);
			printf("현재 노래 : Payphone");
			Gotoxy(63, 6);
			puts("시간 03:52 ");
			if (Page_Count == 42)
			{
				ScoreBoard();
			}
			Gotoxy(83, 6);
			printf("진행도 : %d / 41", Page_Count++);
			Gotoxy(22, 13);
			printf("%s", payphone[i]);
			strcpy(answer, payphone[i]);
			i++;
		}
		Gotoxy(9, 25);
		printf("E N T E R : %84c", ' ');
		Gotoxy(21, 25);
		for (int i = 0; i < 100; i++)
		{
			input[i] = NULL;
		}
		while (1)
		{
			if (y == 0)
			{
				if (noracountdown == 191)
				{
					system("cls");
					ScoreBoard();
				}
			}
			else if (y == 1)
			{
				if (noracountdown == 154)
				{
					system("cls");
					ScoreBoard();
				}
			}
			else if (y == 2)
			{
				if (noracountdown == 190)
				{
					system("cls");
					ScoreBoard();
				}
			}
			else if (y == 3)
			{
				if (noracountdown == 233)
				{
					system("cls");
					ScoreBoard();
				}
			}


			if (Page_Count == 24) // 글 페이지가 끝났을때
			{
				ScoreBoard();
				break;
			}
			if (_kbhit())
			{
				ch = _getch();
				if (time_count == 0) // 입력과 동시에 시간을 나타낸다
				{
					_beginthreadex(NULL, 0, Thread_C, 0, 0, NULL);
					time_count++;
				}
				if (Music_Count == 0) // 입력과 동시에 노래가 나온다
				{
					if (y == 0)
					{
						if (MusicSelect == 0)
						{
							PlaySound(TEXT("BAD.wav"), NULL, SND_ASYNC);
						}
					}
					else if (y == 1)
					{
						if (MusicSelect == 0)
						{
							PlaySound(TEXT("para.wav"), NULL, SND_ASYNC);
						}
					}
					else if (y == 2)
					{
						if (MusicSelect == 0)
						{
							PlaySound(TEXT("2002.wav"), NULL, SND_ASYNC);
						}
					}
					else if (y == 3)
					{
						if (MusicSelect == 0)
						{
							PlaySound(TEXT("payphone.wav"), NULL, SND_ASYNC);
						}
					}
					Music_Count++;
				}
				if (ch == 27) // ESC를 눌렀을때 종료가 된다
				{
					system("cls");
					border();
					Gotoxy(50, 5);
					printf("종료되었습니다!!");
					system("pause");
				}
				if (ch == 8)  // 백스페이스를 눌렀을때
				{
					if (count > 0)
					{
						if (input[count - 1] >= 32 && input[count - 1] <= 127)
						{
							input[count - 1] = NULL;
							count -= 1;
						}
						if (strcmp(input, answer) == 0)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
						}
						if (strcmp(answer, input) == -1 || strcmp(answer, input) == 1)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
						}
						Gotoxy(21, 25);
						printf("%84c", ' ');
						Gotoxy(21, 25);
						printf("%s", input);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
					}
				}
				else if (ch == 13) // ENTER를 눌렀을때
				{
					if (strcmp(input, answer) == 0) // 정답
					{
						FLAG = 1;
					}
					else // 오답
					{
						FLAG = 1;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
						Gotoxy(44, 21);
						printf("* 땡!!! 틀렸습니다 *");
						Sleep(1000);
						Gotoxy(44, 21);
						printf("                         ");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
						Gotoxy(9, 25);
						printf("E N T E R : %84c", ' ');
						for (int i = 0; i < 100; i++)
						{
							input[i] = NULL;
						}
						// 입력한 값이 없으므로 count 변수 초기화
						count = 0;
						Gotoxy(21, 25);
					}
				}
				else
				{
					input[count++] = ch;
					printf("%c\b ", input[count - 1]);
					if (strcmp(input, answer) == 0)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
						ScoreCount += 10;
					}
					else if (strstr(answer, input) == NULL)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
					}
					Gotoxy(21, 25);
					printf("%84c", ' ');
					Gotoxy(21, 25);
					printf("%s", input);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				}
				if (FLAG == 1)
				{
					Gotoxy(23, 13);
					printf("                                                                        ");
					Gotoxy(9, 25);
					printf("E N T E R : %83c", ' ');
					if (y == 0)
					{
						Gotoxy(37, 6);
						printf("현재 점수 : %d", ScoreCount);
						Gotoxy(11, 6);
						printf("현재 노래 : BAD");
						if (Page_Count == 28)
						{
							ScoreBoard();
						}
						Gotoxy(83, 6);
						printf("진행도 : %d / 27", Page_Count++);
						Gotoxy(22, 13);
						printf("%s", BAD[i]);
						strcpy(answer, BAD[i]);
						i++;
					}
					else if (y == 1)
					{
						Gotoxy(37, 6);
						printf("현재 점수 : %d", ScoreCount);
						Gotoxy(10, 6);
						printf("현재 노래 : Parachute");
						if (Page_Count == 37)
						{
							ScoreBoard();
						}
						Gotoxy(83, 6);
						printf("진행도 : %d / 36", Page_Count++);
						Gotoxy(22, 13);
						printf("%s", PARACHUTE[i]);
						strcpy(answer, PARACHUTE[i]);
						i++;
					}
					else if (y == 2)
					{
						Gotoxy(37, 6);
						printf("현재 점수 : %d", ScoreCount);
						Gotoxy(11, 6);
						printf("현재 노래 : 2002");
						if (Page_Count == 28)
						{
							ScoreBoard();
						}
						Gotoxy(83, 6);
						printf("진행도 : %d / 27", Page_Count++);
						Gotoxy(22, 13);
						printf("%s", Anna2002[i]);
						strcpy(answer, Anna2002[i]);
						i++;
					}
					else if (y == 3)
					{
						Gotoxy(37, 6);
						printf("현재 점수 : %d", ScoreCount);
						Gotoxy(10, 6);
						printf("현재 노래 : Payphone");
						if (Page_Count == 42)
						{
							ScoreBoard();
						}
						Gotoxy(83, 6);
						printf("진행도 : %d / 41", Page_Count++);
						Gotoxy(22, 13);
						printf("%s", payphone[i]);
						strcpy(answer, payphone[i]);
						i++;
					}
					// 입력받을 배열 초기화
					for (int i = 0; i < 100; i++)
					{
						input[i] = NULL;
					}
					// 입력한 값이 없으므로 count 변수 초기화
					count = 0;
					FLAG = 0;
				}
				else if (FLAG == -1)
				{
					exit(0);
				}
			}

		}
	}
}
int GameRule()
{
	char Game_Rule;
	system("cls");
	border();
	Gotoxy(82, 29);
	puts("* 뒤로가려면 'b'를 눌러주세요.");
	Gotoxy(50, 5);
	puts("게임 설명");
	Gotoxy(30, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
	puts("이 게임은 타자연습게임으로 영어타수를 늘릴 수 있습니다.");
	Gotoxy(13, 10);
	puts("이 게임은 우리가 흔히 아는 타자연습과 달리 노래를 선택하여서 그 노래로 타자연습을 하는 것 입니다.");
	Gotoxy(27, 12);
	puts("노래를 선택하여서 타자연습을 함으로 당연히 노래도 나오겠죠?");
	Gotoxy(27, 14);
	puts("노래는 설정에서 선택하여서 틀지 안 틀지 선택하시면 됩니다");
	Gotoxy(20, 16);
	puts("이 게임은 선택한 노래가 끝날 때 까지 진행되고 노래가 끝났을때의 점수로 계산합니다");
	Gotoxy(43, 18);
	puts("즐거운 타자연습 되세요.");
	Game_Rule = _getch();
	if (Game_Rule == 66 || Game_Rule == 98)
	{
		return -1;
	}
}