#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include<windows.h>

using namespace std;

bool timer(int ms, int id);
bool timertwo(int ms, int id);
void creatBigbullet(int number);
void loadImag();

int score = 0;

enum My
{
	Width = 591, Height = 700,
	Bullet_Num = 20, Enemy_num = 10, enemyBullet_Num = 20,
	Big, Small
};

struct Plane
{
	double x; double y;
	bool live;
	int width; int height; int hp;
	int type;//µÐ»úÀàÐÍbig or small
}player, bull[Bullet_Num], enemy[Enemy_num];

struct Bigbullet
{
	double px; double py; double qx; double qy;
	bool plive; bool qlive;
	int width; int height;
}Bigenemybullet[enemyBullet_Num];

IMAGE background;//±³¾°Í¼Æ¬

IMAGE role[2];//Íæ¼ÒÍ¼Æ¬
IMAGE death[3];
IMAGE bullet[2];//×Óµ¯Í¼Æ¬
IMAGE enemybullet[2];
IMAGE ienemy[2][2];
IMAGE imenu[3];

void loadImag()//Í¼Æ¬¼ÓÔØº¯Êý
{
	loadimage(&background, "./Images/background.jpg");

	loadimage(&imenu[0], "./Images/Menu_ori.jpg");
	loadimage(&imenu[1], "./Images/ORI_infor.jpg");
	loadimage(&imenu[2], "./Images/ORI_exit.jpg");

	loadimage(&role[0], "./Images/planeNormal_1.jpg");
	loadimage(&role[1], "./Images/planeNormal_2.jpg");

	loadimage(&bullet[0], "./Images/bullet1.jpg");
	loadimage(&bullet[1], "./Images/bullet2.jpg");

	loadimage(&enemybullet[0], "./Images/enemybullet1.jpg");
	loadimage(&enemybullet[1], "./Images/enemybullet2.jpg");

	loadimage(&ienemy[0][0], "./Images/enemy_1.jpg");
	loadimage(&ienemy[0][1], "./Images/enemy_2.jpg");
	loadimage(&ienemy[1][0], "./Images/enemyPlane1.jpg");
	loadimage(&ienemy[1][1], "./Images/enemyPlane2.jpg");

	loadimage(&death[0], "./Images/planeBoom_1.jpg");
	loadimage(&death[1], "./Images/planeBoom_2.jpg");
	loadimage(&death[2], "./Images/death.jpg");
	//¼ÓÔØÍ¼Æ¬
}

void enemyHP(int i)
{
	int flag = rand() % 10;
	if (flag == 0)
	{
		enemy[i].type = Big;
		enemy[i].hp = 3;
		enemy[i].width = 104;
		enemy[i].height = 148;
	}
	else
	{
		enemy[i].type = Small;
		enemy[i].hp = 1;
		enemy[i].width = 52;
		enemy[i].height = 39;
	}
}

void gameInit()
{
	loadImag();
	player.x = Width / 2;
	player.y = Height - 120;
	player.hp = 10;
	player.live = true;

	for (int i = 0; i < Bullet_Num; i++)
	{
		bull[i].x = 0;
		bull[i].y = 0;
		bull[i].live = false;
	}

	for (int i = 0; i < Enemy_num; i++)
	{
		enemy[i].live = false;
		enemyHP(i);
	}

	for (int i = 0; i < enemyBullet_Num; i++)
	{
		Bigenemybullet[i].plive = false;
		Bigenemybullet[i].qlive = false;
	}


}

void gameDraw()
{
	putimage(0, 0, &background);

	putimage(player.x, player.y, &role[0], NOTSRCERASE);
	putimage(player.x, player.y, &role[1], SRCINVERT);

	for (int i = 0; i < Bullet_Num; i++)
	{
		if (bull[i].live)
		{
			putimage(bull[i].x, bull[i].y, &bullet[0], NOTSRCERASE);
			putimage(bull[i].x, bull[i].y, &bullet[1], SRCINVERT);
		}
	}

	for (int i = 0; i < Enemy_num; i++)
	{
		if (enemy[i].live)
		{
			if (enemy[i].type == Big)
			{
				putimage(enemy[i].x, enemy[i].y, &ienemy[1][0], NOTSRCERASE);
				putimage(enemy[i].x, enemy[i].y, &ienemy[1][1], SRCINVERT);
			}
			else
			{
				putimage(enemy[i].x, enemy[i].y, &ienemy[0][0], NOTSRCERASE);
				putimage(enemy[i].x, enemy[i].y, &ienemy[0][1], SRCINVERT);
			}
		}
	}

	for (int i = 0; i < enemyBullet_Num; i++)
	{
		if (Bigenemybullet[i].plive)
		{
			putimage(Bigenemybullet[i].px, Bigenemybullet[i].py, &enemybullet[0], NOTSRCERASE);
			putimage(Bigenemybullet[i].px, Bigenemybullet[i].py, &enemybullet[1], SRCINVERT);
		}
		if (Bigenemybullet[i].qlive)
		{
			putimage(Bigenemybullet[i].qx, Bigenemybullet[i].qy, &enemybullet[0], NOTSRCERASE);
			putimage(Bigenemybullet[i].qx, Bigenemybullet[i].qy, &enemybullet[1], SRCINVERT);
		}
	}
}

void creatbullet()
{
	for (int i = 0; i < Bullet_Num; i++)
	{
		if (!bull[i].live)
		{
			bull[i].x = player.x + 45;
			bull[i].y = player.y;
			bull[i].live = true;
			break;
		}
	}
}

void bulletMove()
{
	for (int i = 0; i < Bullet_Num; i++)
	{
		if (bull[i].live)
		{
			bull[i].y -= 1;
			if (bull[i].y < 0)
			{
				bull[i].live = false;
			}
		}
	}
}

void roleMove(int speed)
{

#if 0
	if (_kbhit())
	{
		//×èÈûº¯Êý²»Á÷³©
		char check = _getch();
		switch (check)
		{
		case'w':
		case'W':
			player.y -= speed;
			break;
		case's':
		case'S':
			player.y += speed;
			break;
		case'a':
		case'A':
			player.x -= speed;
			break;
		case'd':
		case'D':
			player.x += speed;
			break;
		}
	}

#elif 1
	//·Ç×èÈûº¯Êý

	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
	{
		if (player.y > 0)
		{
			player.y -= speed;
		}
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
	{
		if (player.y + 120 < Height)
		{
			player.y += speed;
		}
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
	{
		if (player.x + 60 > 0)
		{
			player.x -= speed;
		}//+60¿¼ÂÇ·É»úÖ÷ÖáÄÜ¶ÔÆë±ß½çµÄµÐ»ú
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
	{
		if (player.x + 60 < Width)
		{
			player.x += speed;
		}
	}

#endif
	if (GetAsyncKeyState(VK_SPACE) && timer(230, 2))
	{
		creatbullet();
	}

	if (GetAsyncKeyState(VK_RBUTTON))
	{
		system("pause");
	}

}

void creatEnemy()
{
	for (int i = 0; i < Enemy_num; i++)
	{
		if (!enemy[i].live)
		{
			enemy[i].live = true;
			enemy[i].x = rand() % (Width - 60);
			enemy[i].y = -100;
			enemyHP(i);
			break;
		}
	}
}

void enemyMove()
{
	for (int i = 0; i < Enemy_num; i++)
	{
		if (enemy[i].live)
		{
			if (enemy[i].type == Big)
			{
				enemy[i].y += 0.06;
				if (timertwo(1500, i))
				{
					creatBigbullet(i);
				}
			}
			if (enemy[i].type == Small)
			{
				enemy[i].y += 0.12;
			}
			if (enemy[i].y > Height)
			{
				enemy[i].live = false;
			}
		}
	}
}

void creatBigbullet(int number)
{
	for (int i = 0; i < enemyBullet_Num; i++)
	{
		if (!Bigenemybullet[i].plive && !Bigenemybullet[i].qlive)
		{
			Bigenemybullet[i].plive = true;
			Bigenemybullet[i].qlive = true;
			Bigenemybullet[i].px = enemy[number].x + 20;
			Bigenemybullet[i].qx = enemy[number].x + 60;
			Bigenemybullet[i].py = enemy[number].y + 150;
			Bigenemybullet[i].qy = enemy[number].y + 150;
			break;
		}
	}
}

void BigbulletMove()
{
	for (int i = 0; i < enemyBullet_Num; i++)
	{
		if (Bigenemybullet[i].plive)
		{
			Bigenemybullet[i].py += 0.2;
		}
		if (Bigenemybullet[i].plive)
		{
			Bigenemybullet[i].qy += 0.2;
		}
		if (Bigenemybullet[i].py > Height)
		{
			Bigenemybullet[i].plive = false;
		}
		if (Bigenemybullet[i].qy > Height)
		{
			Bigenemybullet[i].qlive = false;
		}
	}
}

bool timer(int ms, int id)
{
	static DWORD t[10];
	if (clock() - t[id] > ms)
	{
		t[id] = clock();
		return true;
	}
	return false;
}

bool timertwo(int ms, int id)
{
	static DWORD t[10];
	if (clock() - t[id] > ms)
	{
		t[id] = clock();
		return true;
	}
	return false;
}

void beatCheck()
{
	for (int i = 0; i < Enemy_num; i++)
	{
		if (!enemy[i].live)
		{
			continue;
		}
		for (int j = 0; j < Bullet_Num; j++)
		{
			if (!bull[j].live)
			{
				continue;
			}
			if (bull[j].x > enemy[i].x && bull[j].x<enemy[i].x + enemy[i].width
				&& bull[j].y>enemy[i].y && bull[j].y < enemy[i].y + enemy[i].height)
			{
				bull[j].live = false;
				enemy[i].hp--;
			}
		}
		if (enemy[i].hp <= 0)
		{
			enemy[i].live = false;
			mciSendString("play ./Images./score.mp3", 0, 0, 0);
			if (enemy[i].type == Big)
			{
				score += 3;
			}
			else if (enemy[i].type == Small)
			{
				score += 1;
			}
		}
	}
}

void enemybeatCheck()
{
	for (int i = 0; i < Enemy_num; i++)
	{
		if (enemy[i].live)
		{
			if (enemy[i].x > player.x && enemy[i].x<player.x + 117
				&& enemy[i].y>player.y && enemy[i].y < player.y + 120)
			{
				enemy[i].live = false;
				if (enemy[i].type == Big)
				{
					player.hp -= 3;
				}
				if (enemy[i].type == Small)
				{
					player.hp -= 1;
				}
			}
		}
	}

	for (int i = 0; i < enemyBullet_Num; i++)
	{
		if (Bigenemybullet[i].plive)
		{
			if (Bigenemybullet[i].px > player.x && Bigenemybullet[i].px<player.x + 117
				&& Bigenemybullet[i].py > player.y && Bigenemybullet[i].py < player.y + 120)
			{
				player.hp--;
				Bigenemybullet[i].plive = false;
			}
		}
		if (Bigenemybullet[i].qlive)
		{
			if (Bigenemybullet[i].qx > player.x && Bigenemybullet[i].qx<player.x + 117
				&& Bigenemybullet[i].qy > player.y && Bigenemybullet[i].qy < player.y + 120)
			{
				player.hp--;
				Bigenemybullet[i].qlive = false;
			}
		}
	}
}

void liveCheck()
{
	if (player.hp <= 0)
	{
		player.live = false;
		Sleep(300);
	}
}

void printscore()
{
	rectangle(30, 650, 130, 685);
	settextstyle(25, 0, "Î¢ÈíÑÅºÚ");
	settextcolor(RGB(255, 255, 255));
	outtextxy(40, 655, "µÃ·Ö£º");
	char str[10];
	sprintf_s(str, "%d", score);
	outtextxy(95, 655, str);

}

void game()
{
	gameInit();
	BeginBatchDraw();//Ë«»º³å»æÍ¼


	while (player.live)
	{
		gameDraw();
		printscore();
		FlushBatchDraw();
		roleMove(1);
		bulletMove();

		if (timer(350, 1))
		{
			creatEnemy();
		}
		enemyMove();
		BigbulletMove();
		beatCheck();
		enemybeatCheck();
		liveCheck();

		if (!player.live)
		{
			closegraph();
			initgraph(Width, Height);
			loadImag();
			putimage(0, 0, &death[2]);
			settextstyle(100, 0, "Î¢ÈíÑÅºÚ");
			settextcolor(RGB(255, 255, 255));
			char str[10];
			sprintf_s(str, "%d", score);
			outtextxy(250, 400, str);
			FlushBatchDraw();

			while (1)
			{
				if (_kbhit)
				{
					char check = _getch();
					if (check == 'Z')
					{
						player.x = Width / 2;
						player.y = Height - 120;
						player.hp = 10;
						player.live = true;
						break;
					}
					else if (check == 'C')
					{
						exit(0);
					}
				}
			}

		}
	}

	EndBatchDraw();
}

int main()
{
	initgraph(Width, Height);//´´½¨´°¿Ú
	loadImag();
	putimage(0, 0, &imenu[0]);
	while (1)
	{
		if (_kbhit)
		{
			char check = _getch();
			if (check == 'Z')
			{
				game();
			}
			else if (check == 'X')
			{
				putimage(0, 0, &imenu[1]);
				if (_kbhit)
				{
					char pcheck = _getch();
					{
						if (check == 'X')continue;
					}
				}
			}
			else if (check == 'C')
			{
				putimage(0, 0, &imenu[2]);
				Sleep(500);
				exit(0);
			}
		}
	}

	return 0;
}