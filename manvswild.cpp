#include<iostream>

using namespace std;
//#include "iGraphics.h"
#define screenheight 800
#define screenwidth 1500
#define BackGroundSpeed 12
#define JUMPLIMIT 50
#define RightkeySpeed 10
#define LeftkeySpeed 10
#define ENEMYNUMBER 5
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int mpos, mpoy;

struct obstacle1
{
	int enemy1x = 0;
	int enemy1y = 0;
	int enemy1Index = 0;
	bool enemy1Show;
};
obstacle1 enemy1[ENEMYNUMBER];

struct obstacle2
{
	int enemy2x = 0;
	int enemy2y = 0;
	int enemy2Index = 0;
	bool enemy2Show;
};
obstacle2 enemy2[ENEMYNUMBER];

struct obstacle3
{
	int enemy3x = 0;
	int enemy3y = 0;
	int enemy3Index = 0;
	bool enemy3Show;
};
obstacle3 enemy3[ENEMYNUMBER];

struct obstacle4
{
	int enemy4x = 0;
	int enemy4y = 0;
	int enemy4Index = 0;
	bool enemy4Show;
};
obstacle4 enemy4[ENEMYNUMBER];

struct obstacle5
{
	int enemy5x = 0;
	int enemy5y = 0;
	int enemy5Index = 0;
	bool enemy5Show;
};
obstacle5 enemy5[ENEMYNUMBER];

struct obstacle6
{
	int enemy6x = 0;
	int enemy6y = 0;
	int enemy6Index = 0;
	bool enemy6Show;
};
obstacle6 enemy6[ENEMYNUMBER];

struct obstacle7
{
	int enemy7x = 0;
	int enemy7y = 0;
	int enemy7Index = 0;
	bool enemy7Show;
};
obstacle7 enemy7[ENEMYNUMBER];

struct obstacle8
{
	int enemy8x = 0;
	int enemy8y = 0;
	int enemy8Index = 0;
	bool enemy8Show;
};
obstacle8 enemy8[ENEMYNUMBER];

struct obstacle9
{
	int enemy9x = 0;
	int enemy9y = 0;
	int enemy9Index = 0;
	bool enemy9Show;
};
obstacle9 enemy9[ENEMYNUMBER];

struct Obstaclebar
{
	int barX = 0;
	int barY = 0;
	int barIndex = 0;
	bool barShow;
};
Obstaclebar bar1[ENEMYNUMBER];

char S1[100] = "20";
char s[100] = "Score: ";
char *score = S1;
int scoring;

bool musicOn = true;
int position[25];

char BackGroundImage[25][30] = { "GAME\\1.bmp", "GAME\\2.bmp", "GAME\\3.bmp", "GAME\\4.bmp", "GAME\\5.bmp", "GAME\\6.bmp", "GAME\\7.bmp", "GAME\\8.bmp", "GAME\\9.bmp", "GAME\\10.bmp", "GAME\\11.bmp", "GAME\\12.bmp", "GAME\\13.bmp", "GAME\\14.bmp", "GAME\\15.bmp", "GAME\\16.bmp", "GAME\\17.bmp", "GAME\\18.bmp", "GAME\\19.bmp", "GAME\\20.bmp", "GAME\\21.bmp", "GAME\\22.bmp", "GAME\\23.bmp", "GAME\\24.bmp", "GAME\\25.bmp" };
char BackGroundImage1[25][30] = { "GAME\\27.bmp", "GAME\\28.bmp", "GAME\\29.bmp", "GAME\\30.bmp", "GAME\\31.bmp", "GAME\\32.bmp", "GAME\\33.bmp", "GAME\\34.bmp", "GAME\\35.bmp", "GAME\\36.bmp", "GAME\\37.bmp", "GAME\\38.bmp", "GAME\\39.bmp", "GAME\\40.bmp", "GAME\\41.bmp", "GAME\\42.bmp", "GAME\\43.bmp", "GAME\\44.bmp", "GAME\\45.bmp", "GAME\\46.bmp", "GAME\\47.bmp", "GAME\\48.bmp", "GAME\\49.bmp", "GAME\\50.bmp", "GAME\\51.bmp" };

int slice = 25;
int width = 1500 / slice;

int bCordinate[6];
int bcIndex = 0;

char home[15] = "MENU\\home.bmp";
char homemenu[25] = "MENU\\homemenu.bmp";
char button[10][25] = { "MENU\\M1.bmp", "MENU\\M2.bmp", "MENU\\M3.bmp", "MENU\\M4.bmp", "MENU\\M5.bmp"};
char button2[10][15] = { "MENU\\mm1.bmp", "MENU\\mm2.bmp", "MENU\\mm3.bmp", "MENU\\mm4.bmp", "MENU\\mm5.bmp", "MENU\\mm6.bmp" };
char man[16][15] = { "MENU\\1.bmp", "MENU\\2.bmp", "MENU\\3.bmp", "MENU\\4.bmp", "MENU\\5.bmp", "MENU\\6.bmp", "MENU\\7.bmp", "MENU\\8.bmp", "MENU\\b1.bmp", "MENU\\b2.bmp", "MENU\\b3.bmp", "MENU\\b4.bmp", "MENU\\b5.bmp", "MENU\\b6.bmp", "MENU\\b7.bmp", "MENU\\b8.bmp" };
char manjump[3][15] = { "MENU\\10.bmp", "MENU\\11.bmp" };
char manshoot[3][15] = { "MENU\\32.bmp", "MENU\\31.bmp" };
char manhit[20] = {};
char obs1[50][50] = { "Enemy1\\5.bmp", "Enemy1\\6.bmp", "Enemy1\\7.bmp", "Enemy1\\8.bmp","Enemy1\\9.bmp", "Enemy1\\10.bmp", "Enemy1\\11.bmp", "Enemy1\\12.bmp"};
char obs2[50][50] = { "Enemy2\\13.bmp", "Enemy2\\14.bmp", "Enemy2\\15.bmp", "Enemy2\\16.bmp", "Enemy2\\17.bmp", "Enemy2\\18.bmp", "Enemy2\\19.bmp", "Enemy2\\20.bmp" };
char obs3[50][50] = { "Enemy3\\1.bmp", "Enemy3\\2.bmp", "Enemy3\\3.bmp", "Enemy3\\4.bmp", "Enemy3\\5.bmp", "Enemy3\\6.bmp", "Enemy3\\7.bmp", "Enemy3\\8.bmp" };
char obs4[50][50] = { "Enemy4\\1.bmp", "Enemy4\\2.bmp", "Enemy4\\3.bmp", "Enemy4\\4.bmp", "Enemy4\\5.bmp", "Enemy4\\6.bmp", "Enemy4\\7.bmp", "Enemy4\\8.bmp" };
char obs5[50][50] = { "Enemy5\\1.bmp", "Enemy5\\2.bmp", "Enemy5\\3.bmp", "Enemy5\\4.bmp"};
char obs6[50][50] = { "Enemy6\\11.bmp", "Enemy6\\12.bmp", "Enemy6\\13.bmp", "Enemy6\\14.bmp", "Enemy6\\15.bmp", "Enemy6\\16.bmp", "Enemy6\\17.bmp", "Enemy6\\18.bmp" };
char obs7[50][50] = { "Enemy7\\1.bmp", "Enemy7\\2.bmp", "Enemy7\\3.bmp", "Enemy7\\4.bmp", "Enemy7\\5.bmp", "Enemy7\\6.bmp", "Enemy7\\7.bmp", "Enemy7\\8.bmp" };
char obs8[50][50] = { "Enemy8\\1.bmp", "Enemy8\\2.bmp", "Enemy8\\3.bmp", "Enemy8\\4.bmp", "Enemy8\\5.bmp", "Enemy8\\6.bmp", "Enemy8\\7.bmp", "Enemy8\\8.bmp" };
char obs9[50][50] = { "Enemy9\\1.bmp", "Enemy9\\2.bmp", "Enemy9\\3.bmp", "Enemy9\\4.bmp", "Enemy9\\5.bmp", "Enemy9\\6.bmp", "Enemy9\\7.bmp", "Enemy9\\8.bmp", "Enemy9\\9.bmp" };
char manstand[15] = "MENU\\9.bmp";
char manAbout[15] = "MENU\\about.bmp";
char manControl[20] = "MENU\\control.bmp";
char back[50] = "MENU\\back2.bmp";
char bullet[50] = "MENU\\bullet2.bmp";
char manLifebar[6][50] = { "Lifebar\\1.bmp", "Lifebar\\2.bmp", "Lifebar\\3.bmp", "Lifebar\\4.bmp", "Lifebar\\5.bmp", "Lifebar\\6.bmp" };
char Level[50] = "LEVEL\\2.bmp";
char GameOver[50] = "GameOver\\1.bmp";
char scorebar[50] = "Scorebar\\111.bmp";
char Bar[2][50] = { "Scorebar\\11.bmp","Scorebar\\11.bmp" };
int manabout = 0;
int manCordinateX = 0;
int manCordinateY = 128;
int manIndex = 0;
int bCordinateX = 567;
int bCordinateY = 578;

int bulletCordinateX = manCordinateX+120;
int BulletCordinateY = manCordinateY+100;

int levelCordinateX = 1000;
int levelCordinateY = 300;
int level = 0;

int menu = 0;
int gameState = 0;
int map = 0;
bool lifebarChange = false;
bool manShow = true;
bool standPos = true;
int standCountert = 0;

int lifebarIndex = 0; 
//int lifebarIndex2 = lifebarIndex;

bool game = true;
bool colormenu = true;
bool jump = false;
bool jumpup = false;
bool gun = false;
bool shoot = false;
bool bulletShow = false;

int manCordinatejump = 0;
int manCordinateshoot = 0;

void iDraw()
{
	iClear();
	iSetColor(0, 0, 0);

	if (gameState == 0);
	{
	    iShowBMP(0, 0, home);
	}
	if (gameState == 1)
	{
		iShowBMP(0, 0, homemenu);
		//iShowBMP2(bCordinateX, 136, button[5], 0);
		iShowBMP2(bCordinateX, 224, button[4], 0);
		iShowBMP2(bCordinateX, 312, button[3], 0);
		iShowBMP2(bCordinateX, 400, button[2], 0);
		iShowBMP2(bCordinateX, 488, button[1], 0);
		iShowBMP2(bCordinateX, 576, button[0], 0);
		if (menu == 2)
		{
			iShowBMP2(levelCordinateX, levelCordinateY, Level, 0);
			if (level == 1)
			{
				if (game)
				{
					for (int i = 0; i < 25; i++)
					{
						iShowBMP(position[i], 0, BackGroundImage[i]);
					}
					iShowBMP2(1200, 740, scorebar, 0);
					iText(1225, 755, s, GLUT_BITMAP_TIMES_ROMAN_24);
					iText(1300, 755, S1, GLUT_BITMAP_TIMES_ROMAN_24);
					sprintf_s(S1, "%d", scoring);
					for (int i = 0; i < ENEMYNUMBER; i++)
					{
						if (enemy1[i].enemy1Show)
						{
							iShowBMP2(enemy1[i].enemy1x, enemy1[i].enemy1y, obs1[enemy1[i].enemy1Index], 0);
						}
					}
					for (int i = 0; i < ENEMYNUMBER; i++)
					{
						if (enemy2[i].enemy2Show)
						{
							iShowBMP2(enemy2[i].enemy2x, enemy2[i].enemy2y, obs2[enemy2[i].enemy2Index], 0);
						}
					}
					if (bulletShow)
					{
						iShowBMP2(bulletCordinateX, BulletCordinateY, bullet, 0);
					}
					if (lifebarChange)
					{
						lifebarIndex++;
						if (lifebarIndex >= 6)
						{
							lifebarIndex = 0;
						}
						lifebarChange = false;
					}
					iShowBMP2(600, 744, manLifebar[lifebarIndex], 0);
					if (jump)
					{
						if (jumpup)
						{
							iShowBMP2(manCordinateX, manCordinateY + manCordinatejump, manjump[0], 0);
						}
						else
						{
							iShowBMP2(manCordinateX, manCordinateY + manCordinatejump, manjump[1], 0);
						}
					}
					else if (gun)
					{
						if (shoot)
						{
							iShowBMP2(manCordinateX + manCordinateshoot, manCordinateY, manshoot[0], 0);
						}
						else
						{
							iShowBMP2(manCordinateX + manCordinateshoot, manCordinateY, manshoot[1], 0);


						}
					}
					else
					{
						if (!standPos)
						{

							iShowBMP2(manCordinateX, manCordinateY, man[manIndex], 0);
							standCountert++;
							if (standCountert >= 5)
							{
								standCountert = 0;
								manIndex = 0;
								standPos = true;
							}
						}
						else
						{

							iShowBMP2(manCordinateX, manCordinateY, manstand, 0);
						}
					}

				}
				if (!game)
				{
					iShowBMP(0, 0, GameOver);
					iShowBMP2(50, 650, back, 0);
				}
			}
			if (level == 2)
			{
				if (game)
				{
					for (int i = 0; i < 25; i++)
					{
						iShowBMP(position[i], 0, BackGroundImage[i]);
					}
					iShowBMP2(1200, 740, scorebar, 0);
					iText(1225, 755, s, GLUT_BITMAP_TIMES_ROMAN_24);
					iText(1300, 755, S1, GLUT_BITMAP_TIMES_ROMAN_24);
					sprintf_s(S1, "%d", scoring);
					for (int i = 0; i < ENEMYNUMBER; i++)
					{
						if (enemy3[i].enemy3Show)
						{
							iShowBMP2(enemy3[i].enemy3x, enemy3[i].enemy3y, obs3[enemy3[i].enemy3Index], 0);
						}
					}
					for (int i = 0; i < ENEMYNUMBER; i++)
					{
						if (enemy4[i].enemy4Show)
						{
							iShowBMP2(enemy4[i].enemy4x, enemy4[i].enemy4y, obs4[enemy4[i].enemy4Index], 0);
						}
					}
					for (int i = 0; i < ENEMYNUMBER; i++)
					{
						if (enemy5[i].enemy5Show)
						{
							iShowBMP2(enemy5[i].enemy5x, enemy5[i].enemy5y, obs5[enemy5[i].enemy5Index], 0);
						}
					}
					if (bulletShow)
					{
						iShowBMP2(bulletCordinateX, BulletCordinateY, bullet, 0);
					}
					if (lifebarChange)
					{
						lifebarIndex++;
						if (lifebarIndex >= 6)
						{
							lifebarIndex = 0;

						}
						lifebarChange = false;
					}
					iShowBMP2(600, 744, manLifebar[lifebarIndex], 0);
					if (jump)
					{
						if (jumpup)
						{
							iShowBMP2(manCordinateX, manCordinateY + manCordinatejump, manjump[0], 0);
						}
						else
						{
							iShowBMP2(manCordinateX, manCordinateY + manCordinatejump, manjump[1], 0);
						}
					}
					else if (gun)
					{
						if (shoot)
						{
							iShowBMP2(manCordinateX + manCordinateshoot, manCordinateY, manshoot[0], 0);
						}
						else
						{
							iShowBMP2(manCordinateX + manCordinateshoot, manCordinateY, manshoot[1], 0);


						}
					}
					else
					{
						if (!standPos)
						{

							iShowBMP2(manCordinateX, manCordinateY, man[manIndex], 0);
							standCountert++;
							if (standCountert >= 5)
							{
								standCountert = 0;
								manIndex = 0;
								standPos = true;
							}
						}
						else
						{

							iShowBMP2(manCordinateX, manCordinateY, manstand, 0);
						}
					}


				}
				if (!game)
				{
					iShowBMP(0, 0, GameOver);
					iShowBMP2(50, 650, back, 0);
				}
			}
			if (level == 3)
			{
				if (game)
				{
					for (int i = 0; i < 25; i++)
					{
						iShowBMP(position[i], 0, BackGroundImage[i]);
					}
					iShowBMP2(1200, 740, scorebar, 0);
					iText(1225, 755, s, GLUT_BITMAP_TIMES_ROMAN_24);
					iText(1300, 755, S1, GLUT_BITMAP_TIMES_ROMAN_24);
					sprintf_s(S1, "%d", scoring);
					for (int i = 0; i < ENEMYNUMBER; i++)
					{
						if (bar1[i].barShow)
						{
							iShowBMP2(bar1[i].barX, bar1[i].barY, Bar[bar1[i].barIndex], 0);
						}
					}
					for (int i = 0; i < ENEMYNUMBER; i++)
					{
						if (enemy6[i].enemy6Show)
						{
							iShowBMP2(enemy6[i].enemy6x, enemy6[i].enemy6y, obs6[enemy6[i].enemy6Index], 0);
						}
					}
					for (int i = 0; i < ENEMYNUMBER; i++)
					{
						if (enemy7[i].enemy7Show)
						{
							iShowBMP2(enemy7[i].enemy7x, enemy7[i].enemy7y, obs7[enemy7[i].enemy7Index], 0);
						}
					}
					for (int i = 0; i < ENEMYNUMBER; i++)
					{
						if (enemy8[i].enemy8Show)
						{
							iShowBMP2(enemy8[i].enemy8x, enemy8[i].enemy8y, obs8[enemy8[i].enemy8Index], 0);
						}
					}
					for (int i = 0; i < ENEMYNUMBER; i++)
					{
						if (enemy9[i].enemy9Show)
						{
							iShowBMP2(enemy9[i].enemy9x, enemy9[i].enemy9y, obs9[enemy9[i].enemy9Index], 0);
						}
					}
					if (bulletShow)
					{
						iShowBMP2(bulletCordinateX, BulletCordinateY, bullet, 0);
					}
					if (lifebarChange)
					{
						lifebarIndex++;
						if (lifebarIndex >= 6)
						{
							lifebarIndex = 0;
						}
						lifebarChange = false;
					}
					iShowBMP2(600, 744, manLifebar[lifebarIndex], 0);
					if (jump)
					{
						if (jumpup)
						{
							iShowBMP2(manCordinateX, manCordinateY + manCordinatejump, manjump[0], 0);
						}
						else
						{
							iShowBMP2(manCordinateX, manCordinateY + manCordinatejump, manjump[1], 0);
						}
					}
					else if (gun)
					{
						if (shoot)
						{
							iShowBMP2(manCordinateX + manCordinateshoot, manCordinateY, manshoot[0], 0);
						}
						else
						{
							iShowBMP2(manCordinateX + manCordinateshoot, manCordinateY, manshoot[1], 0);


						}
					}
					else
					{
						if (!standPos)
						{

							iShowBMP2(manCordinateX, manCordinateY, man[manIndex], 0);
							standCountert++;
							if (standCountert >= 5)
							{
								standCountert = 0;
								manIndex = 0;
								standPos = true;
							}
						}
						else
						{

							iShowBMP2(manCordinateX, manCordinateY, manstand, 0);
						}
					}
				}

			}
			if (!game)
			{
				iShowBMP(0, 0, GameOver);
				iShowBMP2(50, 650, back, 0);
			}
		}
		if (menu == 3)
		{

		}
		if (menu == 4)
		{
			iShowBMP(0, 0, manControl);
			iShowBMP2(50, 650, back, 0);
		}
		if (menu == 5)
		{
			iShowBMP(0, 0, manAbout);
			iShowBMP2(50, 650, back, 0);
		}
		if (menu == 6)
		{
			exit(0);
		}
		if (menu == 7)
		{
			
		}
		if (menu == 14)
		{
			gameState = 1;
		}
		/*else if (menu == 8)
		{
			iShowBMP(567, 576, button2[0]);
		}
		else if (menu == 9)
		{
			iShowBMP(567, 488, button2[1]);
		}
		else if (menu == 10)
		{
			iShowBMP(567, 400, button2[2]);
		}
		else if (menu == 11)
		{
			iShowBMP(567, 312, button2[3]);
		}
		else if (menu == 12)
		{
			iShowBMP(567, 224, button2[4]);
		}
		else if (menu == 13)
		{
			iShowBMP(567, 136, button2[5]);
		}*/
	}
	

}



/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	/*if (mx >= 0 && mx <= 1500  && my <= 800 && my >= 0)
	{
		menu = 8;
	}*/
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	/*if (mx >= bCordinateX && mx <= bCordinateX + 366 && my <= 664 && my >= 576)
	{
		menu = 8;
	}
	
	if (mx >= bCordinateX && mx <= bCordinateX + 366 && my <= 576 && my >= 488)
	{
		menu = 9;
	}
	if (mx >= bCordinateX && mx <= bCordinateX + 366 && my <= 488 && my >= 400)
	{
		menu = 10;
	}
	if (mx >= bCordinateX && mx <= bCordinateX + 366 && my <= 400 && my >= 312)
	{
		menu = 11;
	}
	if (mx >= bCordinateX && mx <= bCordinateX + 366 && my <= 312 && my >= 224)
	{
		menu = 12;
	}
	if (mx >= bCordinateX && mx <= bCordinateX + 366 && my <= 224 && my >= 136)
	{
		menu = 13;
	}*/
}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		if (mx >= bCordinateX && mx <= bCordinateX + 366 && my <= 664 && my >= 576)
		{
			menu = 2;	
			game = true;
			//map = 1;
		}
		if (mx >= levelCordinateX + 14 && mx <= levelCordinateX + 236 && my >= levelCordinateY + 248 && my <= levelCordinateY + 330)
		{
			level = 1;
			
		}
		if (mx >= levelCordinateX + 14 && mx <= levelCordinateX + 236 && my >= levelCordinateY + 130 && my <= levelCordinateY + 236)
		{
			level = 2;
		}
		if (mx >= levelCordinateX + 14 && mx <= levelCordinateX + 236 && my >= levelCordinateY + 10 && my <= levelCordinateY + 118)
		{
			level = 3;
		}
		if (mx >= bCordinateX && mx <= bCordinateX + 366 && my <= 576 && my >= 488)
		{
			menu = 3;
		}
		if (mx >= bCordinateX && mx <= bCordinateX + 366 && my <= 488 && my >=400)
		{
			menu = 4;
		}
		if (mx >= bCordinateX && mx <= bCordinateX + 366 && my <= 400 && my >= 312)
		{
			menu = 5;
		}
		if (mx >= bCordinateX && mx <= bCordinateX + 366 && my <= 312 && my >= 224)
		{
			menu = 6;
		}
		if (mx >= bCordinateX && mx <= bCordinateX + 366 && my <= 224 && my >= 136)
		{
			menu = 7;
		}
		if (mx >= 50 && mx <= 50 + 79 && my >= 650 && my <= 650 + 60)
		{
			menu = 14;
		}

	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		/*if (mx >= bCordinateX && mx <= bCordinateX + 366 && my <= 664 && my >= 576)
		{
			menu = 8;
		}*/
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 114)
	{
		if (musicOn){
		musicOn = false;
		PlaySound(0, 0, 0);
		}
		/*else{
		musicOn = true;
		PlaySound("music\\bc.wav", NULL, SND_LOOP | SND_ASYNC);
		}*/
	}
	if (key == 'p')
	{
			if (!musicOn){
				musicOn = false;
				PlaySound("music\\bc.wav", NULL, SND_LOOP | SND_ASYNC);
			}
	}
	if (key == 'c')
	{
		gameState = 1;
	}
	 if (key == ' ')
	{
		for (int i = 0; i < 25; i++)
		{
			position[i] -= 60;
			if (position[i] < 0)
			{
				position[i] = (slice*width) - width;
			}

		}
		for (int i = 0; i < 2; i++)
		{
			if (!jump)
			{
				jump = true;
				jumpup = true;
			}
		}
	}
	if (key == 's')
	{
		if (!bulletShow)
		{
			bulletCordinateX = manCordinateX+120;
			bulletShow = true;
		}
		for (int i = 0; i < 2; i++)
		{
			if (!shoot)
			{
				gun = true;
				shoot = true;
			}
		}


		
	}
	

}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_UP)
	{
		
	}
	else if (key == GLUT_KEY_DOWN)
	{
		
	}

	else if (key == GLUT_KEY_RIGHT)
	{

		for (int i = 0; i < 25; i++)
		{
			position[i] -= 60;
			if (position[i] < 0)
			{
				position[i] = (slice*width) - width;
			}

		}
		manCordinateX += 5;
		manIndex++;
		if (manIndex >= 8)
		{
			manIndex = 0;
		}
		standPos = false;


	}
	else if (key == GLUT_KEY_LEFT)
	{
		for (int i = 0; i < 25; i++)
		{
			position[i] -= 60;
			if (position[i] < 0)
			{
				position[i] = (slice*width) - width;
			}

		}
		manCordinateX -= 5;
		manIndex--;
		if (manIndex < 8)
		{
			manIndex = 15;
		}
		standPos = false;
	}

	else if (key == GLUT_KEY_HOME)
	{

	}
	if (key == GLUT_KEY_UP){


	}



}

void setMenu()
{
	int i,j;
	for (i = 6,j=0; i >= 0; i--)
	{
		bCordinate[i]= j;
		j += 88;
	}
}
void setAll()
{
	int i, j;
	for (i = 0, j = 0; i < slice; i++)
	{
		position[i] = j;
		j += width;

	}
}

void changeEnemy1()
{
	for (int i = 0; i <ENEMYNUMBER; i++)
	{
		enemy1[i].enemy1x -= 10;
		if (enemy1[i].enemy1x <= 0)
		{
			enemy1[i].enemy1x = screenwidth + rand() % 10000;
		}
		enemy1[i].enemy1Index++;
		if (enemy1[i].enemy1Index >= 8)
		{
			enemy1[i].enemy1Index = 0;
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy2[i].enemy2x -= 10;
		if (enemy2[i].enemy2x <= 0)
		{
			enemy2[i].enemy2x = screenwidth + rand() % 5000;
		}
		enemy2[i].enemy2Index++;
		if (enemy2[i].enemy2Index >= 8)
		{
			enemy2[i].enemy2Index = 0;
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy3[i].enemy3x -= 15;
		if (enemy3[i].enemy3x <= 0)
		{
			enemy3[i].enemy3x = screenwidth + rand() % 15000;
		}
		enemy3[i].enemy3Index++;
		if (enemy3[i].enemy3Index >= 8)
		{
			enemy3[i].enemy3Index = 0;
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy4[i].enemy4x -= 15;
		if (enemy4[i].enemy4x <= 0)
		{
			enemy4[i].enemy4x = screenwidth + rand() % 10000;
		}
		enemy4[i].enemy4Index++;
		if (enemy4[i].enemy4Index >= 8)
		{
			enemy4[i].enemy4Index = 0;
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy5[i].enemy5x -= 15;
		if (enemy5[i].enemy5x <= 0)
		{
			enemy5[i].enemy5x = screenwidth + rand() % 7000;
		}
		enemy5[i].enemy5Index++;
		if (enemy5[i].enemy5Index >= 4)
		{
			enemy5[i].enemy5Index = 0;
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy6[i].enemy6x -= 20;
		if (enemy6[i].enemy6x <= 0)
		{
			enemy6[i].enemy6x = screenwidth + rand() % 20000;
		}
		enemy6[i].enemy6Index++;
		if (enemy6[i].enemy6Index >= 8)
		{
			enemy6[i].enemy6Index = 0;
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy7[i].enemy7x -= 20;
		if (enemy7[i].enemy7x <= 0)
		{
			enemy7[i].enemy7x = screenwidth + rand() % 15000;
		}
		enemy7[i].enemy7Index++;
		if (enemy7[i].enemy7Index >= 8)
		{
			enemy7[i].enemy7Index = 0;
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy8[i].enemy8x -= 20;
		if (enemy8[i].enemy8x <= 0)
		{
			enemy8[i].enemy8x = screenwidth + rand() % 12000;
		}
		enemy8[i].enemy8Index++;
		if (enemy8[i].enemy8Index >= 8)
		{
			enemy8[i].enemy8Index = 0;
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy9[i].enemy9x -= 20;
		if (enemy9[i].enemy9x <= 0)
		{
			enemy9[i].enemy9x = screenwidth + rand() % 17000;
		}
		enemy9[i].enemy9Index++;
		if (enemy9[i].enemy9Index >= 9)
		{
			enemy9[i].enemy9Index = 0;
		}
	}
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		bar1[i].barX -= 10;
		if (bar1[i].barX<= 0)
		{
			bar1[i].barX = screenwidth + rand() % 12000;
		}
		bar1[i].barIndex++;
		if (bar1[i].barIndex >= 2)
		{
			bar1[i].barIndex = 0;
		}
	}

}


void setEnemy1()
{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy1[i].enemy1x = screenwidth - rand() % 10000;
		enemy1[i].enemy1y = 128;
		enemy1[i].enemy1Show = true;
	}
}
void setEnemy2()
{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy2[i].enemy2x = screenwidth - rand() % 5000;
		enemy2[i].enemy2y = 128;
		enemy2[i].enemy2Show = true;
	}
}
void setEnemy3()
{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy3[i].enemy3x = screenwidth - rand() % 12000;
		enemy3[i].enemy3y = 128;
		enemy3[i].enemy3Show = true;
	}
}
void setEnemy4()
{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy4[i].enemy4x = screenwidth - rand() % 10000;
		enemy4[i].enemy4y = 128;
		enemy4[i].enemy4Show = true;
	}
}
void setEnemy5()
{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy5[i].enemy5x = screenwidth - rand() % 5000;
		enemy5[i].enemy5y = 128;
		enemy5[i].enemy5Show = true;
	}
}
void setEnemy6()
{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy6[i].enemy6x = screenwidth - rand() % 12000;
		enemy6[i].enemy6y = 128;
		enemy6[i].enemy6Show = true;
	}
}

void setEnemy7()
{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy7[i].enemy7x = screenwidth - rand() % 10000;
		enemy7[i].enemy7y = 128;
		enemy7[i].enemy7Show = true;
	}
}
void setEnemy8()
{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy8[i].enemy8x = screenwidth - rand() % 5000;
		enemy8[i].enemy8y = 128;
		enemy8[i].enemy8Show = true;
	}
}
void setEnemy9()
{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		enemy9[i].enemy9x = screenwidth - rand() % 12000;
		enemy9[i].enemy9y = 450;
		enemy9[i].enemy9Show = true;
	}
}
void setbar()
{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		bar1[i].barX= screenwidth - rand() % 12000;
		bar1[i].barY = 280;
		bar1[i].barShow = true;
	}
}
void collisionCheckBulletEnemy1()
{
	if (bulletShow)
	{
		for (int i = 0; i < ENEMYNUMBER; i++)
		{
			if (bulletCordinateX + 5 > enemy1[i].enemy1x &&  bulletCordinateX < enemy1[i].enemy1x + 80)
			{
				enemy1[i].enemy1Show = false;
				bulletShow = false;
				bulletCordinateX = manCordinateX + 120;
				enemy1[i].enemy1x = screenwidth + rand() % 10000;
				scoring += 5;
			}
			else
			{
				enemy1[i].enemy1Show = true;
			}
		}

		for (int i = 0; i < ENEMYNUMBER; i++)
		{
			if (bulletCordinateX + 5 > enemy2[i].enemy2x &&  bulletCordinateX < enemy2[i].enemy2x + 80)
			{
				enemy2[i].enemy2Show = false;
				bulletShow = false;
				bulletCordinateX = manCordinateX + 120;
				enemy2[i].enemy2x = screenwidth + rand() % 5000;
				scoring += 5;
			}
			else
			{
				enemy2[i].enemy2Show = true;
			}
		}

		for (int i = 0; i < ENEMYNUMBER; i++)
		{
			if (bulletCordinateX + 5 > enemy3[i].enemy3x &&  bulletCordinateX < enemy3[i].enemy3x + 80)
			{
				enemy3[i].enemy3Show = false;
				bulletShow = false;
				bulletCordinateX = manCordinateX + 120;
				enemy3[i].enemy3x = screenwidth + rand() % 12000;
				scoring += 5;
			}
			else
			{
				enemy3[i].enemy3Show = true;
			}
		}

		for (int i = 0; i < ENEMYNUMBER; i++)
		{
			if (bulletCordinateX + 5 > enemy4[i].enemy4x &&  bulletCordinateX < enemy4[i].enemy4x + 80)
			{
				enemy4[i].enemy4Show = false;
				bulletShow = false;
				bulletCordinateX = manCordinateX + 120;
				enemy4[i].enemy4x = screenwidth + rand() % 10000;
				scoring += 5;
			}
			else
			{
				enemy4[i].enemy4Show = true;
			}
		}

		for (int i = 0; i < ENEMYNUMBER; i++)
		{
			if (bulletCordinateX + 5 > enemy5[i].enemy5x &&  bulletCordinateX < enemy5[i].enemy5x + 80)
			{
				
				bulletShow = false;
				bulletCordinateX = manCordinateX + 120;
				enemy5[i].enemy5Show = false;
				enemy5[i].enemy5x = screenwidth + rand() % 5000;
				scoring += 5;
			}
			else
			{
				enemy5[i].enemy5Show = true;
			}
		}

		for (int i = 0; i < ENEMYNUMBER; i++)
		{
			if (bulletCordinateX + 5 > enemy6[i].enemy6x &&  bulletCordinateX < enemy6[i].enemy6x + 80)
			{
				enemy6[i].enemy6Show = false;
				bulletShow = false;
				bulletCordinateX = manCordinateX + 120;
				enemy6[i].enemy6x = screenwidth + rand() % 12000;
				scoring += 5;
			}
			else
			{
				enemy6[i].enemy6Show = true;
			}
		}
	}

	if (bulletShow)
	{
		for (int i = 0; i < ENEMYNUMBER; i++)
		{
			if (bulletCordinateX + 5 > enemy7[i].enemy7x &&  bulletCordinateX < enemy7[i].enemy7x + 80)
			{
				enemy7[i].enemy7Show = false;
				bulletShow = false;
				bulletCordinateX = manCordinateX + 120;
				enemy7[i].enemy7x = screenwidth + rand() % 10000;
				scoring += 5;
			}
			else
			{
				enemy7[i].enemy7Show = true;
			}
		}

		for (int i = 0; i < ENEMYNUMBER; i++)
		{
			if (bulletCordinateX + 5 > enemy8[i].enemy8x &&  bulletCordinateX < enemy8[i].enemy8x + 80)
			{
				enemy8[i].enemy8Show = false;
				bulletShow = false;
				bulletCordinateX = manCordinateX + 120;
				enemy8[i].enemy8x = screenwidth + rand() % 5000;
				scoring += 5;
			}
			else
			{
				enemy8[i].enemy8Show = true;
			}
		}

		for (int i = 0; i < ENEMYNUMBER; i++)
		{
			if (bulletCordinateX + 5 > enemy9[i].enemy9x &&  bulletCordinateX < enemy9[i].enemy9x + 80)
			{
				enemy9[i].enemy9Show = false;
				bulletShow = false;
				bulletCordinateX = manCordinateX + 120;
				enemy9[i].enemy9x = screenwidth + rand() % 12000;
				scoring += 5;
			}
			else
			{
				enemy9[i].enemy9Show = true;
			}
		}
	}
}
/*void collisionCheckBulletEnemy4()
{
	if (bulletShow)
	{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
			if (bulletCordinateX + 5 > enemy4[i].enemy4x &&  bulletCordinateX < enemy4[i].enemy4x + 80)
			{
				enemy4[i].enemy4Show = false;
				bulletShow = false;
				bulletCordinateX = manCordinateX + 120;
				enemy4[i].enemy4x = screenwidth + rand() % 10000;
			}
			else
			{
				enemy4[i].enemy4Show = true;
			}
		}

		for (int i = 0; i < ENEMYNUMBER; i++)
		{
			if (bulletCordinateX + 5 > enemy5[i].enemy5x &&  bulletCordinateX < enemy5[i].enemy5x + 80)
			{
				enemy5[i].enemy5Show = false;
				bulletShow = false;
				bulletCordinateX = manCordinateX + 120;
				enemy5[i].enemy5x = screenwidth + rand() % 5000;
			}
			else
			{
				enemy5[i].enemy5Show = true;
			}
		}

		for (int i = 0; i < ENEMYNUMBER; i++)
		{
			if (bulletCordinateX + 5 > enemy6[i].enemy6x &&  bulletCordinateX < enemy6[i].enemy6x + 80)
			{
				enemy6[i].enemy6Show = false;
				bulletShow = false;
				bulletCordinateX = manCordinateX + 120;
				enemy6[i].enemy6x = screenwidth + rand() % 12000;
			}
			else
			{
				enemy6[i].enemy6Show = true;
			}
		}
	}
}*/

/*void collisionCheckBulletEnemy7()
{
	
}*/
/*void collisionCheckBulletEnemy5()
{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		if (bulletCordinateX + 5 > enemy5[i].enemy5x &&  bulletCordinateX < enemy5[i].enemy5x + 80)
		{
			enemy5[i].enemy5Show = false;
			bulletShow = false;
			bulletCordinateX = manCordinateX + 120;
			enemy5[i].enemy5x = screenwidth + rand() % 12000;
		}
		else
		{
			enemy5[i].enemy5Show = true;
		}
	}
}
void collisionCheckBulletEnemy6()
{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		if (bulletCordinateX + 5 > enemy6[i].enemy6x &&  bulletCordinateX < enemy6[i].enemy6x + 80)
		{
			enemy6[i].enemy6Show = false;
			bulletShow = false;
			bulletCordinateX = manCordinateX + 120;
			enemy6[i].enemy6x = screenwidth + rand() % 12000;
		}
		else
		{
			enemy6[i].enemy6Show = true;
		}
	}
}*/
void collisionCheckEnemy1()
{
	//if (lifebarChange)
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		if (enemy1[i].enemy1Show)
		{
			if ((manCordinateX + 5 > enemy1[i].enemy1x && manCordinateX < enemy1[i].enemy1x + 10) && manCordinateY == enemy1[i].enemy1y)
			{
				lifebarChange = true;
				enemy1[i].enemy1Show = false;
				enemy1[i].enemy1x = screenwidth + rand() % 5000;
				if (lifebarIndex >= 5)
				{
					game = false;
				}

				/*enemy1[i].enemy1Show = false;
				enemy1[i].enemy1x = screenwidth + rand() % 5000;*/
			}
			else
			{

				//enemy1[i].enemy1Show = true;
				lifebarChange = false;
			}
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		if (enemy2[i].enemy2Show)
		{
			if (manCordinateX + 5 > enemy2[i].enemy2x && manCordinateX < enemy2[i].enemy2x + 10 && manCordinateY == enemy2[i].enemy2y)
			{
				lifebarChange = true;
				enemy2[i].enemy2Show = false;
				enemy2[i].enemy2x = screenwidth + rand() % 5000;
				if (lifebarIndex >= 5)
				{
					game = false;
				}
				/*enemy1[i].enemy1Show = false;
				enemy1[i].enemy1x = screenwidth + rand() % 5000;*/
			}
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		if (enemy3[i].enemy3Show)
		{
			if (manCordinateX + 5 > enemy3[i].enemy3x && manCordinateX < enemy3[i].enemy3x + 10 && manCordinateY == enemy3[i].enemy3y)
			{
				lifebarChange = true;
				enemy3[i].enemy3Show = false;
				enemy3[i].enemy3x = screenwidth + rand() % 5000;
				if (lifebarIndex >= 5)
				{
					game = false;
				}
				/*enemy1[i].enemy1Show = false;
				enemy1[i].enemy1x = screenwidth + rand() % 5000;*/
			}
		}
	}


		/*if (manCordinateX +5 > enemy1[0].enemy1x && manCordinateX+5 < enemy1[0].enemy1x+10)
		{
			lifebarChange = true;
		}

		else if (manCordinateX +5 > enemy1[1].enemy1x && manCordinateX +5 < enemy1[1].enemy1x+10)
		{
			lifebarChange = true;
		}
		
		else
		{
			lifebarChange = false;
		}*/
}

void collisionCheckEnemy4()
{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		if (enemy4[i].enemy4Show)
		{
			if (manCordinateX + 5 > enemy4[i].enemy4x && manCordinateX < enemy4[i].enemy4x + 10 && manCordinateY == enemy4[i].enemy4y)
			{
				lifebarChange = true;
				enemy4[i].enemy4Show = false;
				enemy4[i].enemy4x = screenwidth + rand() % 5000;
				if (lifebarIndex >= 5)
				{
					game = false;
				}
				/*enemy1[i].enemy1Show = false;
				enemy1[i].enemy1x = screenwidth + rand() % 5000;*/
			}
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		if (enemy5[i].enemy5Show)
		{
			if (manCordinateX + 5 > enemy5[i].enemy5x && manCordinateX < enemy5[i].enemy5x + 10 && manCordinateY == enemy5[i].enemy5y)
			{
				lifebarChange = true;
				enemy5[i].enemy5Show = false;
				enemy5[i].enemy5x = screenwidth + rand() % 5000;
				if (lifebarIndex >= 5)
				{
					game = false;
				}
				/*enemy1[i].enemy1Show = false;
				enemy1[i].enemy1x = screenwidth + rand() % 5000;*/
			}
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		if (enemy6[i].enemy6Show)
		{
			if (manCordinateX + 5 > enemy6[i].enemy6x && manCordinateX < enemy6[i].enemy6x + 10 && manCordinateY == enemy6[i].enemy6y)
			{
				lifebarChange = true;
				enemy6[i].enemy6Show = false;
				enemy6[i].enemy6x = screenwidth + rand() % 5000;
				if (lifebarIndex >= 5)
				{
					game = false;
				}
				/*enemy1[i].enemy1Show = false;
				enemy1[i].enemy1x = screenwidth + rand() % 5000;*/
			}
		}
	}
}

void collisionCheckEnemy7()
{
	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		if (enemy7[i].enemy7Show)
		{
			if (manCordinateX + 5 > enemy7[i].enemy7x && manCordinateX < enemy7[i].enemy7x + 10 && manCordinateY == enemy7[i].enemy7y)
			{
				lifebarChange = true;
				enemy7[i].enemy7Show = false;
				enemy7[i].enemy7x = screenwidth + rand() % 5000;
				if (lifebarIndex >= 5)
				{
					game = false;
				}
				/*enemy1[i].enemy1Show = false;
				enemy1[i].enemy1x = screenwidth + rand() % 5000;*/
			}
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		if (enemy8[i].enemy8Show)
		{
			if (manCordinateX + 5 > enemy8[i].enemy8x && manCordinateX < enemy8[i].enemy8x + 10 && manCordinateY == enemy8[i].enemy8y)
			{
				lifebarChange = true;
				enemy8[i].enemy8Show = false;
				enemy8[i].enemy8x = screenwidth + rand() % 5000;
				if (lifebarIndex >= 5)
				{
					game = false;
				}
				/*enemy1[i].enemy1Show = false;
				enemy1[i].enemy1x = screenwidth + rand() % 5000;*/
			}
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		if (enemy9[i].enemy9Show)
		{
			if (manCordinateX + 5 > enemy9[i].enemy9x && manCordinateX < enemy9[i].enemy9x + 10 && manCordinateY == enemy9[i].enemy9y)
			{
				lifebarChange = true;
				enemy9[i].enemy9Show = false;
				enemy9[i].enemy9x = screenwidth + rand() % 5000;
				if (lifebarIndex >= 5)
				{
					game = false;
				}
				/*enemy1[i].enemy1Show = false;
				enemy1[i].enemy1x = screenwidth + rand() % 5000;*/
			}
		}
	}

	for (int i = 0; i < ENEMYNUMBER; i++)
	{
		if (bar1[i].barShow)
		{
			if (manCordinateX + 30 > bar1[i].barX && manCordinateX < bar1[i].barX + 120 && manCordinateY+100 >= bar1[i].barY)
			{
				manCordinateY = 270;
				/*enemy1[i].enemy1Show = false;
				enemy1[i].enemy1x = screenwidth + rand() % 5000;*/
			}
		}
	}
}
void change2()
{
	if (jump)
	{
		if (jumpup)
		{
			manCordinatejump += 15;
			if (manCordinatejump >= 100)
			{
				jumpup = false;
			}
		}
		else
		{
			manCordinatejump -= 15;
			if (manCordinatejump<0)
			{
				jump = false;
				manCordinatejump = 0;
			}
		}
	}

	if (gun)
	{
		if (shoot)
		{
			shoot = false;
		}
		else
		{
			gun = false;
		}
	}
}

void bulletShot()
{
	if (bulletShow)
	{
		if (bulletCordinateX > 1500)
		{
			bulletShow = false;
			bulletCordinateX = manCordinateX + bulletCordinateX;

	    }
		else{
			bulletCordinateX += 100;
		}
		
		 
	}
}
void music()
{	
	if (musicOn)
	PlaySound("music\\bc.wav", NULL, SND_LOOP | SND_ASYNC);
}


int main()
{
	setAll();
	setEnemy1();
	setEnemy2();
	setEnemy3();
	setEnemy4();
	setEnemy5();
	setEnemy6();
	setEnemy7();
	setEnemy8();
	setEnemy9();
	setbar();
	setMenu();
	music();
	iSetTimer(100, changeEnemy1);
    iSetTimer(100, collisionCheckBulletEnemy1);
	iSetTimer(100, collisionCheckEnemy1);
	iSetTimer(100, collisionCheckEnemy4);
	iSetTimer(100, collisionCheckEnemy7);
	iSetTimer(80, change2);
	iSetTimer(10, bulletShot);

	/*FILE *file;
	file = fopen("Score.txt", "w");
	char HighScore = -100;
	if (file == NULL)
	{
		printf("file doesn't exist");
	}
	else
	{
		printf("File is open\n");
		scanf("%d",scoring);
		if (scoring > HighScore)
		{
			HighScore = scoring;
		}
		fprintf(file,"%d", HighScore);
		fclose(file);
	}*/

	iInitialize(screenwidth, screenheight, "MAN VS WILD");
	///updated see the documentations
	iStart();
	return 0;
}