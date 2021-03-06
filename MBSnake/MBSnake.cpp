#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <io.h>
#include <direct.h>
#include <fstream>
#include <thread>

int speed;
int level;
int score = 0;
int Screenscore = 0;
int length = 2;
int headX = 8, headY = 8;
int foodX[10000], foodY[10000];
int bodyX[100], bodyY[100];
int Keyboard_input;
int gameover = 0;
int num = 2;
int difficult;
int off_flag = 0;
int Gamenum = 1;

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Clean_stats()
{
	score = 0;
	Screenscore = 0;
	length = 2;
	headX = 8, headY = 8;
	bodyX[100] = { 0 };
	bodyY[100] = { 0 };
	gameover = 0;
	num = 2;
	off_flag = 0;
}

void Start_m()
{
	int SpeedT = 20;
	int Snake_length = 9;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);

	int num = 0;
	while (1)
	{
		for (int i = 0; i <= 5; ++i)
		{
			gotoxy(num + 2 * i, 15 - i);
			std::cout << "■" << std::endl;
			Sleep(SpeedT);
		}
		if (num == 60)
			break;
		num = num + 10;

		for (int i = 1; i <= 5; ++i)
		{
			gotoxy(num + 2 * i, 10 + i);
			std::cout << "■" << std::endl;
			Sleep(SpeedT);
		}
		num = num + 10;
	}
	num = 0;
	while (1)
	{
		for (int i = 0; i <= 5; ++i)
		{
			gotoxy(num + 2 * i, 15 - i);
			std::cout << " " << std::endl;
			Sleep(SpeedT);
		}
		if (num == 60)
			break;
		num = num + 10;

		for (int i = 1; i <= 5; ++i)
		{
			gotoxy(num + 2 * i, 10 + i);
			std::cout << " " << std::endl;
			Sleep(SpeedT);
		}
		num = num + 10;
	}

	//E
	for (int i = 10; i <= 14; i = i + 2)
	{
		gotoxy(68, i);
		std::cout << "■" << std::endl;
	}
	Sleep(SpeedT);
	for (int i = 10; i <= 14; i = i + 2)
	{
		gotoxy(66, i);
		std::cout << "■" << std::endl;
	}
	Sleep(SpeedT);
	for (int i = 10; i <= 14; ++i)
	{
		gotoxy(64, i);
		std::cout << "■" << std::endl;
	}
	Sleep(SpeedT);
	//K
	gotoxy(58, 10);
	std::cout << "■" << std::endl;
	gotoxy(58, 14);
	std::cout << "■" << std::endl;
	Sleep(SpeedT);
	gotoxy(56, 11);
	std::cout << "■" << std::endl;
	gotoxy(56, 13);
	std::cout << "■" << std::endl;
	Sleep(SpeedT);
	gotoxy(54, 12);
	std::cout << "■" << std::endl;
	Sleep(SpeedT);
	for (int i = 10; i <= 14; ++i)
	{
		gotoxy(52, i);
		std::cout << "■" << std::endl;
	}
	Sleep(SpeedT);
	//A
	gotoxy(46, 14);
	std::cout << "■" << std::endl;
	Sleep(SpeedT);
	gotoxy(44, 13);
	std::cout << "■" << std::endl;
	Sleep(SpeedT);
	gotoxy(42, 12);
	std::cout << "■" << std::endl;
	Sleep(SpeedT);
	gotoxy(40, 11);
	std::cout << "■" << std::endl;
	gotoxy(40, 12);
	std::cout << "■" << std::endl;
	Sleep(SpeedT);
	gotoxy(38, 10);
	std::cout << "■" << std::endl;
	gotoxy(38, 12);
	std::cout << "■" << std::endl;
	Sleep(SpeedT);
	gotoxy(36, 11);
	std::cout << "■" << std::endl;
	gotoxy(36, 12);
	std::cout << "■" << std::endl;
	Sleep(SpeedT);
	gotoxy(34, 12);
	std::cout << "■" << std::endl;
	Sleep(SpeedT);
	gotoxy(32, 13);
	std::cout << "■" << std::endl;
	Sleep(SpeedT);
	gotoxy(30, 14);
	std::cout << "■" << std::endl;
	Sleep(SpeedT);
	//N
	for (int i = 10; i <= 14; ++i)
	{
		gotoxy(24, i);
		std::cout << "■" << std::endl;
	}
	Sleep(SpeedT);
	for (int i = 1; i <= 4; ++i)
	{
		gotoxy(24 - 2 * i, 15 - i);
		std::cout << "■" << std::endl;
		Sleep(SpeedT);
	}
	for (int i = 10; i <= 14; ++i)
	{
		gotoxy(14, i);
		std::cout << "■" << std::endl;
	}
	Sleep(SpeedT);
	//S
	gotoxy(8, 10);
	std::cout << "■" << std::endl;
	gotoxy(8, 13);
	std::cout << "■" << std::endl;
	Sleep(SpeedT);
	for (int i = 10; i <= 14; i = i + 2)
	{
		gotoxy(6, i);
		std::cout << "■" << std::endl;
	}
	gotoxy(4, 11);
	std::cout << "■" << std::endl;
	gotoxy(4, 14);
	std::cout << "■" << std::endl;
	Sleep(SpeedT);

	gotoxy(26, 26);
	system("pause");
	gotoxy(26, 26);
	std::cout << "                                " << std::endl;
}

void Hide_mouse()
{
	HANDLE h0ut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = 1;
	curInfo.bVisible = FALSE;
	SetConsoleCursorInfo(h0ut, &curInfo);
}

int Getkeyboard()
{
	Keyboard_input = _getch();
	return Keyboard_input;
}

void Game_map()
{
	system("mode con cols=90 lines=30");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(0, 0);
	for (int i = 1; i <= 68; i = i + 2)
	{
		printf("■");
		Sleep(8);
	}
	printf("\n");
	for (int i = 1; i <= 27; i++)
	{
		printf("■                                                                ■\n");
		Sleep(8);
	}
	for (int i = 1; i <= 68; i = i + 2)
	{
		printf("■");
		Sleep(8);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	gotoxy(70, 1);
	std::cout << "贪吃蛇" << std::endl;
	gotoxy(70, 7);
	std::cout << "游戏难度：" << std::endl;
	gotoxy(80, 7);
	if (difficult == 1)
	{
		std::cout << "简单" << std::endl;
	}
	if (difficult == 2)
	{
		std::cout << "普通" << std::endl;
	}
	if (difficult == 3)
	{
		std::cout << "困难" << std::endl;
	}
	if (difficult == 4)
	{
		std::cout << "极限" << std::endl;
	}
	gotoxy(70, 11);
	std::cout << "按下空格暂停游戏" << std::endl;
}

void Main_screen()
{
	int yj = 20;
	int flag = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	gotoxy(10, 18);
	std::cout << "蛇的操纵：" << std::endl;
	gotoxy(10, 20);
	std::cout << "W：向上，S：向下" << std::endl;
	gotoxy(10, 22);
	std::cout << "A：向左，D：向右" << std::endl;
	gotoxy(10, 24);
	std::cout << "选择好难度后按回车确定" << std::endl;
	gotoxy(50, 18);
	std::cout << "选择游戏难度:" << std::endl;
	gotoxy(50, 20);
	std::cout << "简单" << std::endl;
	gotoxy(50, 22);
	std::cout << "普通" << std::endl;
	gotoxy(50, 24);
	std::cout << "困难" << std::endl;
	gotoxy(50, 26);
	std::cout << "极限" << std::endl;

	while (1)
	{
		if (flag == 1)
			break;
		gotoxy(60, yj);
		std::cout << "<--" << std::endl;
		while (1)
		{
			Getkeyboard();
			if (Keyboard_input == 119)
			{
				gotoxy(60, yj);
				std::cout << "   " << std::endl;
				if (yj == 20)
					yj += 6;
				else
					yj -= 2;
				break;
			}
			if (Keyboard_input == 115)
			{
				gotoxy(60, yj);
				std::cout << "   " << std::endl;
				if (yj == 26)
					yj -= 6;
				else
					yj += 2;
				break;
			}
			if (Keyboard_input == 13)
			{
				if (yj == 20)
				{
					speed = 300;
					difficult = 1;
				}

				if (yj == 22)
				{
					speed = 200;
					difficult = 2;
				}

				if (yj == 24)
				{
					speed = 140;
					difficult = 3;
				}

				if (yj == 26)
				{
					speed = 80;
					difficult = 4;
				}

				flag = 1;
				break;
			}
		}
	}
}

int Get_direction(int x)
{
	char ch;
	if (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case 'w':
			x = 1;
			break;
		case 's':
			x = 2;
			break;
		case 'a':
			x = 3;
			break;
		case 'd':
			x = 4;
			break;
		case ' ':
			gotoxy(69, 23);
			std::cout << "游戏暂停..." << std::endl;
			gotoxy(69, 26);
			system("pause");
			gotoxy(69, 23);
			std::cout << "                " << std::endl;
			gotoxy(69, 26);
			std::cout << "                " << std::endl;
		}
	}
	return x;
}

void Move_snake(int x)
{
	if (length > 1)
	{
		for (int i = length; i >= 2; --i)
		{
			if (i == 2)
			{
				bodyX[i] = headX;
				bodyY[i] = headY;
			}
			else
			{
				bodyX[i] = bodyX[i - 1];
				bodyY[i] = bodyY[i - 1];
			}
		}
	}
	if (x == 1)
		headY -= 1;
	if (x == 2)
		headY += 1;
	if (x == 3)
		headX -= 2;
	if (x == 4)
		headX += 2;
}

void Draw_snake()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN);
	gotoxy(headX, headY);
	std::cout << "●" << std::endl;
	if (length > 1)
	{
		for (int i = 2; i <= length; ++i)
		{
			gotoxy(bodyX[i], bodyY[i]);
			std::cout << "●" << std::endl;
		}
		gotoxy(bodyX[length], bodyY[length]);
		std::cout << "  " << std::endl;
	}
}

void Draw_score()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	gotoxy(76, 4);
	std::cout << "     " << std::endl;
	gotoxy(70, 4);
	std::cout << "分数:" << std::endl;
	gotoxy(76, 4);
	std::cout << Screenscore << std::endl;
}

void Draw_food()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_BLUE);
	gotoxy(foodX[num], foodY[num]);
	std::cout << "★" << std::endl;
}

void Make_food()
{
	num++;
	if (foodX[num] == foodX[num - 1])
		num++;
	if (headX == foodX[num] && headY == foodY[num])
		num++;
	if (length > 1)
	{
		for (int i = 2; i <= length; ++i)
		{
			if (bodyX[i] == foodX[num] && bodyY[i] == foodY[num])
				num++;
		}
	}
}

void Get_food()
{
	if (headX == foodX[num] && headY == foodY[num])
	{
		gotoxy(foodX[num], foodY[num]);
		std::cout << "  " << std::endl;
		if (difficult == 1)
		{
			Screenscore = Screenscore + 10;
		}
		if (difficult == 2)
		{
			Screenscore = Screenscore + 20;
		}
		if (difficult == 3)
		{
			Screenscore = Screenscore + 30;
		}
		if (difficult == 4)
		{
			Screenscore = Screenscore + 40;
		}
		length++;
		score++;
		Make_food();
	}
}

void If_live()
{
	for (int i = 2; i <= length; ++i)
	{
		if (headX == bodyX[i] && headY == bodyY[i])
		{
			gameover = 1;
		}
	}
	if (headX == 0 || headY == 0)
		gameover = 1;
	if (headX == 66 || headY == 28)
		gameover = 1;
}

void Game_over()
{
	int yj = 11;
	int flag = 0;
	Sleep(1000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	gotoxy(15, 5);
	std::cout << "Game Over!" << std::endl;
	gotoxy(15, 7);
	std::cout << "你的分数:" << Screenscore << std::endl;
	gotoxy(15, 9);
	std::cout << "是否再来一次？" << std::endl;
	gotoxy(15, 11);
	std::cout << "是" << std::endl;
	gotoxy(15, 13);
	std::cout << "不了，还是学习有意思" << std::endl;
	while (1)
	{
		if (flag == 1)
			break;
		gotoxy(40, yj);
		std::cout << "<--" << std::endl;
		while (1)
		{
			Getkeyboard();
			if (Keyboard_input == 119)
			{
				if (yj == 11)
				{
					gotoxy(40, yj);
					std::cout << "   " << std::endl;
					yj += 2;
					break;
				}
				if (yj == 13)
				{
					gotoxy(40, yj);
					std::cout << "   " << std::endl;
					yj -= 2;
					break;
				}
			}
			if (Keyboard_input == 115)
			{
				if (yj == 11)
				{
					gotoxy(40, yj);
					std::cout << "   " << std::endl;
					yj += 2;
					break;
				}
				if (yj == 13)
				{
					gotoxy(40, yj);
					std::cout << "   " << std::endl;
					yj -= 2;
					break;
				}
			}
			if (Keyboard_input == 13)
			{
				flag = 1;
				if (yj == 11)
				{
					break;
				}
				if (yj == 13)
				{
					off_flag = 1;
					break;
				}
			}
		}

	}
	

	while (1)
	{
		Getkeyboard();
		if (Keyboard_input == 13)
		{
			off_flag = 1;
			break;
		}
		if (Keyboard_input == 32)
		{
			break;
		}
	}
}

void Change_speed()
{
	if (difficult == 1)
	{
		if (score == 4)
			speed = 260;
		if (score == 8)
			speed = 220;
		if (score == 12)
			speed = 180;
		if (score == 16)
			speed = 140;
		if (score == 20)
			speed = 120;
		if (score == 24)
			speed = 80;
	}
	if (difficult == 2)
	{
		if (score == 4)
			speed = 170;
		if (score == 8)
			speed = 140;
		if (score == 12)
			speed = 110;
		if (score == 16)
			speed = 90;
		if (score == 20)
			speed = 80;
		if (score == 24)
			speed = 70;
	}
	if (difficult == 3)
	{
		if (score == 4)
			speed = 120;
		if (score == 8)
			speed = 100;
		if (score == 12)
			speed = 80;
		if (score == 16)
			speed = 60;
		if (score == 20)
			speed = 50;
		if (score == 24)
			speed = 40;
	}
	if (difficult == 4)
	{
		if (score == 4)
			speed = 70;
		if (score == 8)
			speed = 60;
		if (score == 12)
			speed = 50;
		if (score == 16)
			speed = 40;
		if (score == 20)
			speed = 30;
		if (score == 24)
			speed = 20;
	}
}

void Main_game()
{
	int direction = 2;
	int midnum;
	Hide_mouse();
	if (Gamenum == 1)
		Start_m();
	Main_screen();
	system("cls");
	Game_map();
	while (1)
	{
		midnum = direction;
		direction = Get_direction(direction);
		if (length != 1)
		{
			if (midnum == 1 && direction == 2)
				direction = 1;
			if (midnum == 2 && direction == 1)
				direction = 2;
			if (midnum == 3 && direction == 4)
				direction = 3;
			if (midnum == 4 && direction == 3)
				direction = 4;
		}
		if (length == 1)
		{
			gotoxy(headX, headY);
			std::cout << "  " << std::endl;
		}
		Move_snake(direction);
		Get_food();
		If_live();
		if (gameover == 1)
		{
			Sleep(100);
			break;
		}
		Draw_score();
		Draw_snake();
		Draw_food();
		Sleep(speed);
		Change_speed();
	}
	Game_over();
}

void PreMake_food()
{
	for (int i = 2; i <= 10000; ++i)
	{
		srand(time(NULL));
		int low = 2, high = 26;
		foodY[i] = rand() % (high - low + 1) + low;
		while (1)
		{
			low = 2;
			high = 64;
			foodX[i] = rand() % (high - low + 1) + low;
			if (foodX[i] % 2 == 0)
				break;
		}
		Sleep(800);
	}
}

int main()
{
	while (1)
	{
		Clean_stats();
		SetConsoleTitle(L"贪吃蛇 By Neo");
		system("mode con cols=72 lines=30");
		std::thread task01(PreMake_food);
		task01.detach();
		Main_game();
		if (off_flag == 1)
			return 0;
		system("cls");
		Gamenum++;
	}
}