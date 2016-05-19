# include "iGraphics.h"
# include <iostream>
# include <ctime>

using namespace std;

//char *tochar(int i, char *p);

void page1();
void page2();
void page6();
void page7();
void page8();
void levelOne_background();
void levelTwo_background();
void tops();

void drawTarget();
void possitionTarget();
void targetBulletInitializer();
void drawTargetBullet();
void possitionTargetBullet();

void targetInitializer();
void drawTarget2();
void possitionTarget2();

void drawPlane();
void drawPlaneBullet();
void planeBulletInitializer();
void positionPlaneBullet();

void targetDestruction();
void planeDestruction();

int page=1, newgame=0, highscore=0, about=0, ext=0, level2=0;
double targetX=0, targetY=600, moveL=0, moveR=1;
double planeSelecter, planeX = 350, planeY = 0;
int iBullet=1;
int i, m, n=1;
int counter=0, l, o, p=1, sec_lev_bul=0;
int gameOver = 0;
int countTargetBulletCall=0, mode;
int hit, life = 3;
class Bullet 
{
public:
	int bulletX;
	int bulletY;
};


Bullet target[100];
Bullet planeLeft[500];
Bullet planeRight[500];

class Target
{
public:
	int targetX;
	int targetY;
	int move;
	int flag;
};
Target possition[10];
Target flag[40];


void iDraw()
{
	iClear();
	if (page == 1)
		page1();
	if (page == 2)
	{
		page2();
	}
	if (page == 3 && gameOver == 0)
	{
		levelOne_background();
		tops();
		drawTarget();
		drawTargetBullet();
		drawPlane();
		drawPlaneBullet();
		planeDestruction();
	}
	if (page == 4 && gameOver == 0)
	{
		levelTwo_background();
		tops();
		drawTarget2();
		drawTargetBullet();
		drawPlane();
		drawPlaneBullet();
		planeDestruction();
	}
	if (page == 6)
	{
		page6();
	}
	if (page==7)
	{
		page7();
	}
	if (page==8)
		page8();

	targetDestruction();
}

void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{ 
		if (mx >= 50 && mx <=178 && my >= 600 && my <= 632 && page==1)
		{
			page=2;
		}
	    if (mx >= 50 && mx <= 178 && my >= 550 && my <= 582 && page==1)
		{
			page=8;
		}
		if (mx >= 50 && mx <= 178 && my >= 500 && my <= 532 && page==1)
			exit(0);
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (mx >= 150 && mx <= 250 && my >= 450 && my <= 550 && page==2)
		{
			planeSelecter = 1;
			page=3;
		}
		if (mx >= 350 && mx <= 450 && my >= 450 && my <= 550 && page==2)
		{
			planeSelecter = 2;
			page=3;
		}
		if (mx >= 550 && mx <= 650 && my >= 450 && my <= 550 && page==2)
		{
			planeSelecter = 3;
			page=3;
		}
		if (mx >= 150 && mx <= 250 && my >= 150 && my <= 250 && page==2)
		{
			planeSelecter = 4;
			page=3;
		}
		if (mx >= 350 && mx <= 450 && my >= 150 && my <= 250 && page==2)
		{
			planeSelecter = 5;
			page=3;
		}
		if (mx >= 550 && mx <= 650 && my >= 150 && my <= 250 && page==2)
		{
			planeSelecter = 6;
			page=3;
		}
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		planeBulletInitializer();
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}


void iKeyboard(unsigned char key)
{
	if(key == ' ') 
	{
		planeBulletInitializer();
	}
	if(key == 'p') 
	{
		iPauseTimer(0);
	}
	if(key == 'r') 
	{
		iResumeTimer(0);
		if (page==6 || page==7 || page==8)
		{
			page=1;
			life=3;
			planeX=350;
			planeY=0;
            hit=0;
			sec_lev_bul=0;				
			p=1;
			counter=0;
			countTargetBulletCall=0;
		}
	}
	if(key == 'q')
	{
		exit(0);
	}
}


void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_RIGHT) 
	{
		if (planeX < 700 ) 
		{
			planeX += 10;
		}
	}
	if (key == GLUT_KEY_LEFT) 
	{
		if (planeX>0) 
		{
			planeX -= 10;
		}
	}
	if (key == GLUT_KEY_UP)
	{
		if (planeY<=500)
		{
			planeY += 20;
		}
	}
	if (key == GLUT_KEY_DOWN)
	{
		if (planeY>0 && planeY<=550)
		{
			planeY -= 20;
		}
	}
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
}

void page1()
{
	iSetColor (255, 255, 255);
	iFilledRectangle (0, 0, 800, 700);
	iShowBMP (50, 600, "NEW_GAME.bmp");
	iShowBMP (50, 550, "ABOUT.bmp");
	iShowBMP (50, 500,"EXIT.bmp" );
//  iSetColor(255, 0, 0);
//	iFilledRectangle (50, 400, 128, 32);
}

void levelOne_background() 
{
	iSetColor(255, 255, 255);
	//iFilledRectangle(0, 0, 800, 700);
	iLine(0, 650, 800, 650);
	newgame=0, highscore=0, about=0, ext=0;
}

void drawTarget() 
{
	//iSetColor (100, 200, 255);
	//iFilledRectangle (targetX, targetY, 70, 50);
	iShowBMP (targetX, targetY, "alien1.bmp");
}

void possitionTarget() 
{
	if(page == 3)
	{
		if(targetX >= 730) 
		{
			moveR = 0;
			moveL = 1;
			targetY -= 70;
		}
	if(targetX <= 0) 
	{
		moveR = 1;
		moveL = 0;
		targetY -= 70;
	}

	if(moveR == 1)
	{		
		targetX += 10;
	}
	if(moveL == 1) 
	{
		targetX -= 10;
	}
	}
}

void targetBulletInitializer() //***********************************
{
	if (page == 3)
	{
		target[n].bulletX = targetX + 50;
		target[n].bulletY = targetY + 40;

	}
	else if (page == 4)
	{
		static int i=0; 
		if (p==2)
			i=0;
		mode = countTargetBulletCall%60;
		sec_lev_bul++;
		if (mode>=1 && mode<=30)
		{
			target[sec_lev_bul].bulletX = possition[i].targetX + 35;
			target[sec_lev_bul].bulletY = possition[i].targetY;
            flag[sec_lev_bul].flag = 1;
		}
		else if (mode>=31 && mode<=59)
			flag[sec_lev_bul].flag = 0;
		if (mode==0)
		{
			i++;
			sec_lev_bul=1;
			countTargetBulletCall = 0;
		}
		if (i == 6)
			i = 1;
	}
}

void drawTargetBullet()
{
	if (page==3)
	{
		for (i=1; i<n; i++)
		{
			iSetColor (255, 0, 0);
			iFilledRectangle (target[i].bulletX, target[i].bulletY, 3,6);
		}
	}
	if (page==4)
	{
		for (i=1; i<=sec_lev_bul; i++)
		{
			if (flag[i].flag==1)
			{
				iSetColor (255, 0, 0);
		    	iFilledRectangle (target[i].bulletX, target[i].bulletY, 3,6);
			}
		}
	}
}

void possitionTargetBullet()
{
	targetBulletInitializer ();
	if (page==3)
	{
		for (m=1; m<=n; m++)
		{
			target[m].bulletY -= 15;
		}
		n++;
		if (n==100)
			n=1;
	}
	if (page==4)
	{
		for (m=1; m<=sec_lev_bul; m++)
		{
			if (flag[m].flag==1)
				target[m].bulletY -= 20;
		}
		countTargetBulletCall++;
	}
}

void drawPlane() 
{
	if (planeSelecter==1)
		iShowBMP (planeX, planeY, "BOMBER-33.bmp");
	if (planeSelecter==2)
		iShowBMP (planeX, planeY, "300px-Vulture_fighter.bmp");
	if (planeSelecter==3)
		iShowBMP (planeX, planeY, "Fighter_Plane_Maker.bmp");
	if (planeSelecter==4)
		iShowBMP (planeX, planeY, "ifighter2.bmp");
	if (planeSelecter==5)
		iShowBMP (planeX, planeY, "jetca.bmp");
	if (planeSelecter==6)
		iShowBMP (planeX, planeY, "Mantacon_CLPD.bmp");
}

void planeBulletInitializer() 
{
//	cout << iBullet << "\n";
	if (iBullet <=500)
	{
		planeLeft[iBullet].bulletX = planeX;
		planeLeft[iBullet].bulletY = planeY + 60;
		planeRight[iBullet].bulletX = planeX + 100;
		planeRight[iBullet].bulletY = planeY + 60;
		iBullet++;
	}
}

void drawPlaneBullet() 
{	
	for(int i = 1; i< iBullet; i++) 
	{			
		iSetColor(0, 255, 0);
		iFilledRectangle(planeLeft[i].bulletX, planeLeft[i].bulletY, 3, 6 );
		iFilledRectangle(planeRight[i].bulletX, planeRight[i].bulletY, 3, 6 );
	}
}

void positionPlaneBullet() 
{	
	for(int i = 1; i< iBullet; i++) 
	{
		planeLeft[i].bulletY += 10;
		planeRight[i].bulletY += 10;
		if (planeLeft[i].bulletY>=650)
		{
			planeLeft[i].bulletY=800;
			planeRight[i].bulletY=800;
		}
		if (planeLeft[iBullet-1].bulletY>=650)
		{
			iBullet=1;
		}
	}
}

void targetDestruction() 
{
	if (page==3)
	{
		for (int i = 1; i< iBullet; i++) 			
		{
			if ((planeLeft[i].bulletX >= targetX && planeLeft[i].bulletX <= targetX + 100 && planeLeft[i].bulletY >= targetY && planeLeft[i].bulletY < targetY + 100) || (planeRight[i].bulletX >= targetX && planeRight[i].bulletX <= targetX + 100 && planeRight[i].bulletY >= targetY && planeRight[i].bulletY < targetY + 100))
			{			
				targetX = rand()%400;
				targetY = 550;

				if (planeLeft[i].bulletX >= targetX && planeLeft[i].bulletX <= targetX + 100 && planeLeft[i].bulletY >= targetY && planeLeft[i].bulletY < targetY + 100)
					planeLeft[i].bulletY = 800;
				if (planeRight[i].bulletX >= targetX && planeRight[i].bulletX <= targetX + 100 && planeRight[i].bulletY >= targetY && planeRight[i].bulletY < targetY + 100)
					planeRight[i].bulletY = 800;

				moveL = rand()%2;
				if (moveL)
						moveR = 0;
				else
					moveR = 1;
				hit++;
				//	cout << hit << endl;
			}
		}
		
		if (hit==6)
			page=4;
	}

	if (page==4)
	{
		for (int i = 1; i< iBullet; i++) 
		{
			for (int j=1; j<p;j++)
			{
				if ((planeLeft[i].bulletX >= possition[j].targetX && planeLeft[i].bulletX <= possition[j].targetX + 70 && planeLeft[i].bulletY >= possition[j].targetY && planeLeft[i].bulletY < possition[j].targetY + 50) || (planeRight[i].bulletX >= possition[j].targetX && planeRight[i].bulletX <= possition[j].targetX + 70 && planeRight[i].bulletY >= possition[j].targetY && planeRight[i].bulletY < possition[j].targetY + 50))
				{
					if (planeLeft[i].bulletX >= possition[j].targetX && planeLeft[i].bulletX <= possition[j].targetX + 70 && planeLeft[i].bulletY >= possition[j].targetY && planeLeft[i].bulletY < possition[j].targetY + 50)
					{
						planeLeft[i].bulletY = 800;
						possition[j].targetY = -100;
					}
					if (planeRight[i].bulletX >= possition[j].targetX && planeRight[i].bulletX <= possition[j].targetX + 70 && planeRight[i].bulletY >= possition[j].targetY && planeRight[i].bulletY < possition[j].targetY + 50)
					{
						planeRight[i].bulletY = 800;
						possition[j].targetY = -100;
					}
					hit++;
				}
			}
			if (hit==11)
			page=6;
		}
	}
}


int main()
{
	srand(time(0));
	
	iSetTimer(50, possitionTarget);
	iSetTimer(50, possitionTargetBullet);
	iSetTimer(5, positionPlaneBullet);
	iSetTimer(50, possitionTarget2);
	iInitialize(800, 700, " SHOOT THE ALIENS ");
	return 0;
}



void levelTwo_background()
{
	iSetColor(255, 255, 255);
	//iFilledRectangle(0, 0, 800, 700);
	iLine(0, 650, 800, 650);
}

void targetInitializer()
{
	possition[p].targetX = 0;
	possition[p].targetY = 550;
	possition[p].move = 10;
	
}

void drawTarget2()
{
	for(o=1; o<p; o++)
	{
		iShowBMP (possition[o].targetX, possition[o].targetY, "alien2.bmp");
	}
}

void possitionTarget2()
{
	if(page == 4)
	{
		if (counter%110==0 && counter <= 440)
		{
			targetInitializer();
			p++;
		}
		for(l=1; l<p; l++)
		{
			possition[l].targetX += possition[l].move;
			if (possition[l].targetX >= 730)
			{
				possition[l].move = -10;
				possition[l].targetY -= 70;
			}
			if (possition[l].targetX <= 0)
			{
				possition[l].move = 10;
				possition[l].targetY -= 70;
			}
		}
		if (counter<450)
			counter += 10;
	}
}

void tops()
{
	iSetColor (205,	0, 205);
	iText (8, 670, "Life :", GLUT_BITMAP_HELVETICA_18);
	for(int i=1; i<=life; i++)
	{
		iShowBMP(i*28+18, 660, "life.BMP");
	}

	if (page==3)
		iText (340, 670, "LEVEL ONE", GLUT_BITMAP_HELVETICA_18);
	if (page==4)
		iText (340, 670, "LEVEL TWO", GLUT_BITMAP_HELVETICA_18);

	iText(700, 670, "Score : ", GLUT_BITMAP_HELVETICA_18);
	int scoreN= hit * 10;
	char score[5];
	sprintf(score, "%d",scoreN);
	iText(770, 670, score, GLUT_BITMAP_HELVETICA_18);
}

void planeDestruction()
{
	if (page==3)
	{
		for (int i=1; i<n; i++)
		{
			if (target[i].bulletX>=planeX && target[i].bulletX<=planeX+100 && target[i].bulletY>=planeY+50 && target[i].bulletY<=planeY+70)
			{	
				life--;
				targetX=0;
				targetY=550;
				n=1;
				break;
			//	cout << "called\n";
			}
		}
		if (targetX<=planeX+100 && targetX+100>=planeX && targetY<=planeY+100 && targetY+100>=planeY)
		{
			life--;
			targetX=0;
			targetY=550;
			n=1;
		}
	}
	if (page==4)
	{
		for (int i=1; i<=sec_lev_bul; i++)
		{
			if (flag[i].flag==1 && target[i].bulletX>=planeX && target[i].bulletX<=planeX+100 && target[i].bulletY>=planeY+70 && target[i].bulletY<=planeY+100)
			{
				life--;
				sec_lev_bul=0;
				p=1;
				counter=0;
				countTargetBulletCall=0;
				hit=6;
				break;
			//	cout << "called\n";
			}
		}
		for (int j=1; j<p; j++)
		{
			if (possition[j].targetX<=planeX+100 && possition[j].targetX+64>=planeX && possition[j].targetY<=planeY+100 && possition[j].targetY+64>=planeY)
			{
				life--;
				sec_lev_bul=0;				
				p=1;
				counter=0;
				countTargetBulletCall=0;
				hit=6;
				break;
			}
		}
	}
	if (life==0)
	{
		page=7;
	}
}

void page2()
{
	iSetColor (176, 23, 31);
	iText (220, 650, "SELECT A PLANE TO CRUSH THE ALIENS", GLUT_BITMAP_HELVETICA_18);
	iSetColor (75, 0, 130);
	iShowBMP (150, 450, "BOMBER-33.bmp");
	iShowBMP (350, 450, "300px-Vulture_fighter.bmp");
	iShowBMP (550, 450, "Fighter_Plane_Maker.bmp");
	iShowBMP (150, 150, "ifighter2.bmp");
	iShowBMP (350, 150, "jetca.bmp");
	iShowBMP (550, 150, "Mantacon_CLPD.bmp");
	iRectangle (150, 450, 100, 100);
	iRectangle (350, 450, 100, 100);
	iRectangle (550, 450, 100, 100);
	iRectangle (150, 150, 100, 100);
	iRectangle (350, 150, 100, 100);
	iRectangle (550, 150, 100, 100);
	iSetColor (255,	236, 139);
	iText (147, 430, "BOMBER-33", GLUT_BITMAP_HELVETICA_18);
	iText (320, 430, "300-Vulture Fighter", GLUT_BITMAP_HELVETICA_18);
	iText (560, 430, "Volgar H2", GLUT_BITMAP_HELVETICA_18);
	iText (183, 130, "B-52", GLUT_BITMAP_HELVETICA_18);
	iText (349, 130, "F-16 Stealth", GLUT_BITMAP_HELVETICA_18);
	iText (533, 130, "Mantacon CLPD", GLUT_BITMAP_HELVETICA_18);

}

void page6()
{
	iShowBMP (0, 0, "bravo.bmp");
}

void page7()
{
	iShowBMP(0, 0, "sad-face-1.bmp");
}

void page8()
{
	iShowBMP(0, 0, "about_pic.bmp");
}
