
#include<stdio.h>
#include<math.h>
#include <cstdlib>
#include<GL/glut.h>

float angle, move, scene, roadmove, turn, on = 1;
float z_scene;
int i, start;
float chicken_move = 0; 
int jump; //chicken jumping
int star=0; //twinkle stars

void init(GLvoid)
{
	glClearColor(0, 0, 0, 0);           //set the Background Color BLACK
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);           // Enable Smooth Shading
}

void drawWall()
{
	glRectf(0, 0, 14, 10);
}

void drawStar()
{
	if (star == 1)
	{
		glColor3f(1.0, 1.0, 1.0);//white
	}
	else if (star == 0)
	{
		glColor3f(0.0, 0.0, 0.0); //black
	}
	
	glRotatef(-30, 0, 0, 1);
	glPushMatrix();
	glTranslatef(-11.0, 5, 0);
	glutSolidSphere(0.5, 10, 10);
	glTranslatef(-2.0, -5, 0);
	glutSolidSphere(0.5, 10, 10);
	glTranslatef(-6.0, 0, 0);
	glutSolidSphere(0.5, 10, 10);
	glTranslatef(-1.0, 5, 0);
	glutSolidSphere(0.5, 10, 10);
	glTranslatef(-5.0, 1, 0);
	glutSolidSphere(0.5, 10, 10);
	glTranslatef(-5.0, 2, 0);
	glutSolidSphere(0.5, 10, 10);
	glTranslatef(-6.0, 0, 0);
	glutSolidSphere(0.5, 10, 10);
	glPopMatrix();
}
void drawMoon()
{
	glutSolidSphere(5, 10, 10);
}

void drawTree() {

	//bottom
	glPushMatrix();
	glTranslatef(4.75, .25, 3); 
	//glRotatef(a, 0, 1, 0);
	glColor3f(51/256.0, 153/256.0, 51/256.0);
	glutSolidCone(1.5, 2, 10, 2);
	glPopMatrix();

	//middle
	glPushMatrix();
	glTranslatef(4.75, .25, 3.9); 
	//glRotatef(a, 0, 1, 0);
	glColor3f(51 / 256.0, 153 / 256.0, 51 / 256.0);
	glutSolidCone(1.5, 2, 10, 2);
	glPopMatrix();
	
	//top
	glPushMatrix();
	glTranslatef(4.75, .25, 4.75); 
	//glRotatef(a, 0, 1, 0);
	glColor3f(51 / 256.0, 153 / 256.0, 51 / 256.0);
	glutSolidCone(1.5, 2, 10, 2);
	glPopMatrix();

	//body
	glPushMatrix(); 
	glTranslatef(5.0, 0.0, 0);
	glRotatef(90, 1, 0, 0);
	glColor3f(102 / 256.0, 51 / 256.0, 0 / 256.0);
	glRectf(0, 0, -0.5, 3);
	glPopMatrix();

	//fruit1 yellow
	glPushMatrix();
	glTranslatef(5.0, -1.0, 4.75);
	glRotatef(90, 0, 0, 1);
	glColor3f(1.0,1.0,0.0);
	glutSolidSphere(0.3, 10, 10);
	glPopMatrix();
	//fruit2 red
	glPushMatrix();
	glTranslatef(4.3, -1.0, 4.5);
	glRotatef(90, 0, 0, 1);
	glColor3f(204/256.0, 0/256.0, 0/256.0);
	glutSolidSphere(0.3, 10, 10);
	glPopMatrix();
	//fruit3 pink
	glPushMatrix();
	glTranslatef(4.7, -1.0, 5.5);
	glRotatef(90, 0, 0, 1);
	glColor3f(255 / 256.0, 102 / 256.0, 102 / 256.0);
	glutSolidSphere(0.3, 10, 10);
	glPopMatrix();
	//fruit4 blue
	glPushMatrix();
	glTranslatef(5.2, -1.0, 3.5);
	glRotatef(90, 0, 0, 1);
	glColor3f(51 / 256.0, 51 / 256.0, 153 / 256.0);
	glutSolidSphere(0.3, 10, 10);
	glPopMatrix();	

}

void drawMomChicken()
{
	//body
	glPushMatrix();
	glTranslatef(3, 1.0 + chicken_move, 0.5);
	glColor3f(255 / 256.0, 255 / 256.0, 255 / 256.0);
	glutSolidCube(0.8);
	glPopMatrix();

	//head
	glPushMatrix();
	glTranslatef(3.23, 1.45 + chicken_move, 0.5);
	glColor3f(255 / 256.0, 255 / 256.0, 255 / 256.0);
	glutSolidCube(0.5);
	glPopMatrix();

	//leg1
	glPushMatrix();
	glTranslatef(3.4, 0.85 + chicken_move, 0.5);
	glColor3f(1.0, 0.0, 0.0);
	glRectf(-0.5, -0.8, -0.65, -0.1);
	glPopMatrix();

	//leg2
	glPushMatrix();
	glTranslatef(3.8, 0.85 + chicken_move, 0.5);
	glColor3f(1.0, 0.0, 0.0);
	glRectf(-0.5, -0.8, -0.65, -0.1);
	glPopMatrix();

	//eye
	glPushMatrix();
	glTranslatef(3.3, 1.45 + chicken_move, 0.75);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.1);
	glPopMatrix();

	//mouse
	glPushMatrix();
	glTranslatef(3.57, 1.35 + chicken_move, 0.5);
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.2);
	glPopMatrix();
	
	//cockscomb
	glPushMatrix();
	glTranslatef(3.3, 1.75 + chicken_move, 0.5);
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.2);
	glPopMatrix();

}
void drawBabyChicken()
{
	//body
	glPushMatrix();
	glTranslatef(3, 1.0 + chicken_move, 0.5);
	glColor3f(255 / 256.0, 255 / 256.0, 0 / 256.0);
	glutSolidCube(0.7);
	glPopMatrix();

	//head
	glPushMatrix();
	glTranslatef(3.2, 1.45 + chicken_move, 0.5);
	glColor3f(255 / 256.0, 255 / 256.0, 0 / 256.0);
	glutSolidCube(0.45);
	glPopMatrix();

	//leg1
	glPushMatrix();
	glTranslatef(3.1, 0.85 + chicken_move, 0.5);
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glRectf(-0.5, -0.1, -0.2, 0.0);
	glPopMatrix();

	//leg2
	glPushMatrix();
	glTranslatef(2.85, 0.85 + chicken_move, 0.5);
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glRectf(-0.5, -0.1, -0.2, 0.0);
	glPopMatrix();

	//eye
	glPushMatrix();
	glTranslatef(3.3, 1.45 + chicken_move, 0.75);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.1);
	glPopMatrix();

	//mouse
	glPushMatrix();
	glTranslatef(3.55, 1.35 + chicken_move, 0.5);
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.2);
	glPopMatrix();

}
void drawGroundRoad()                  
{
	glColor3f(102 / 256.0, 153 / 256.0, 0 / 256.0); // middle
	glPushMatrix();                       
	glScalef(50, 1000, 0);
	drawWall();                        
	glPopMatrix();

	glPushMatrix();
	glColor3f(0 / 256.0, 51 / 256.0, 0 / 256.0); //맨 왼쪽 땅
	glScalef(-100, 50, 0);
	drawWall();                       
	glPopMatrix();

	glTranslatef(5, 0, .01);
	glPushMatrix();
	glScalef(.25, 50, 1);
	glColor3f(77/256.0, 77 / 256.0, 51 / 256.0);
	drawWall();                           //Black Road
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, -1.3, .01);
	glColor3f(1, 1, 1);
	for (i = 0; i < 250; i++)
	{
		glTranslatef(0, 2, 0);
		glRectf(0, 0, .5, 1);       //White Bricks on Road
	}

	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, -1.3, .01);
	glColor3f(1, 0.54902, 0);
	for (i = 0; i < 500; i++)
	{
		glTranslatef(0, 1, 0);
		glRectf(0, 0, .5, 1);       //Yellow line on Road
	}

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-.5, -1.3, .01);
	glColor3f(1, 0.54902, 0);
	for (i = 0; i < 500; i++)
	{
		glTranslatef(0, 1, 0);
		glRectf(0, 0, .5, 1);       //Yellow line on Road
	}

	glPopMatrix();



	//오른쪽 나무 세워주기
	glPushMatrix();
	glTranslatef(1.7, 1.0, -1);
	glColor3f(1, 0.54902, 0);
	for (i = 0; i < 30; i++)
	{
		glTranslatef(0, 10, 0);
		drawTree();
	}
	glPopMatrix();
	//왼쪽 나무 세워주기
	glPushMatrix();
	glTranslatef(-6, -7, -1);
	glColor3f(1, 0.54902, 0);
	for (i = 0; i < 30; i++)
	{
		glTranslatef(0, 10, 0);
		drawTree();
	}
	glPopMatrix();

	//mountain
	glPushMatrix();
	glColor3f(0 / 256.0, 51 / 256.0, 0 / 256.0);
	glTranslatef(60, 60, -1);
	glutSolidCone(50, 20, 10, 2);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0 / 256.0, 51 / 256.0, 0 / 256.0);
	glTranslatef(50, 100, -1);
	glutSolidCone(50, 20, 10, 2);
	glPopMatrix();
	
	//치킨 팜
	//닭 띄우기
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(7, -1.3, -255);
	
	//아기치킨
	for (i = 0; i < 30; i++)
	{
		float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0~1까지의 랜덤 실수
		glTranslatef(0.2f*r, 0.1f, 10);
		drawBabyChicken(); 
		glPushMatrix();
		glTranslatef(1.0f, 0, 0);
		drawMomChicken();
		glPopMatrix();
	}
	glPopMatrix();


	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(13, -1.3, -255);
	
	//엄마 치킨
	for (i = 0; i < 30; i++)
	{
		float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); //0~1까지의 랜덤 실수
		glTranslatef(0.1f, 0.1f, 10);
		drawMomChicken(); 
		}
	glPopMatrix();


	//치킨 팜 frame
	//왼쪽 기둥
	glPushMatrix();
	glTranslatef(4.75, 5, 0);
	glRotatef(90, 1, 0, 0);
	glColor3f(102/256.0, 0 / 256.0, 102 / 256.0);
	glRectf(0, 0, -0.5, 2.5);
	glPopMatrix();
	//오른쪽 기둥
	glPushMatrix();
	glTranslatef(7.5, 5, 0);
	glRotatef(90, 1, 0, 0);
	glColor3f(102 / 256.0, 0 / 256.0, 102 / 256.0);
	glRectf(0, 0, -0.5, 2.5);
	glPopMatrix();
	//간판
	glPushMatrix();
	glTranslatef(7.5,5, 1);
	glRotatef(90, 1, 0, 0);
	glColor3f(102 / 256.0, 0 / 256.0, 102 / 256.0);
	glRectf(0, 0, -3.0, 1.5);
	glPopMatrix();



}

void drawHouse()
{
	glPushMatrix();
	glTranslatef(-16, 2, 2);
	glColor3f(230 / 256.0, 230 / 256.0, 230 / 256.0);
	glutSolidCube(4);

	glPushMatrix();
	glTranslatef(-2.5, 3, 1.5);
	glRotatef(90, 0, 1, 0);
	glColor3f(1, 1, 0);
	glRectf(0, 0, .5, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 1, 1.5);
	glRotatef(90, 0, 1, 0);
	glColor3f(1, 1, 0);
	glRectf(0, 0, .5, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, -1, 1.5);
	glRotatef(90, 0, 1, 0);
	glColor3f(1, 1, 0);
	glRectf(0, 0, .5, 1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-2.5, 3, -.5);
	glRotatef(90, 0, 1, 0);
	glColor3f(1, 1, 0);
	glRectf(0, 0, .5, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 1, -.5);
	glRotatef(90, 0, 1, 0);
	glColor3f(1, 1, 0);
	glRectf(0, 0, .5, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, -1, -.5);
	glRotatef(90, 0, 1, 0);
	glColor3f(1, 1, 0);
	glRectf(0, 0, .5, 1);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-16, 5, 2);
	glColor3f(230 /256.0, 230 / 256.0, 230 / 256.0);
	glutSolidCube(4);
	glPopMatrix();

}

void drawTrain()
{
	//굴뚝
	glPushMatrix();
	glTranslatef(0.0, -0.75, 1.5);
	glColor3f(255 / 256.0, 51 / 256.0, 0 / 256.0);
	glScalef(1, 2, 1);
	glutSolidCube(0.25);
	glPopMatrix();
	//굴뚝에서 연기...
	glPushMatrix();
	glTranslatef(0.0, -1.5, 1.5);
	glColor3f(64 / 256.0, 64 / 256.0, 64 / 256.0);
	glutSolidSphere(0.25, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -1.5, 1.2);
	glColor3f(64 / 256.0, 64 / 256.0, 64 / 256.0);
	glutSolidSphere(0.3, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -1.5, 1.0);
	glColor3f(64 / 256.0, 64 / 256.0, 64 / 256.0);
	glutSolidSphere(0.35, 10, 10);
	glPopMatrix();

	//body1
	glPushMatrix();
	glTranslatef(0.0, 0.0, 1.5);
	glColor3f(255 / 256.0, 51 / 256.0, 0 / 256.0);
	glScalef(1, 1, 1);
	glutSolidCube(1);
	glPopMatrix();
	
	//body2
	glPushMatrix();
	glPushMatrix();
	glColor3f(36 / 256.0, 36 / 256.0, 143 / 256.0);
	glScalef(1, 1, 1.5);
	glutSolidCube(1);
	glPopMatrix();
	//inside
	glPushMatrix();
	glColor3f(26 / 256.0, 0 / 256.0, 0 / 256.0);
	glTranslatef(0.0, -0.275, 0.0);
	glScalef(1, 1, 1.7);
	glutSolidCube(0.5);
	glPopMatrix();
	glPopMatrix();

	//body3
	glPushMatrix();
	glPushMatrix();
	glColor3f(36 / 256.0, 36 / 256.0, 143 / 256.0);
	glTranslatef(0, 0, -1.75);
	glScalef(1, 1, 1.5);
	glutSolidCube(1);
	glPopMatrix();
	//inside
	glPushMatrix();
	glColor3f(26 / 256.0, 0 / 256.0, 0 / 256.0);
	glTranslatef(0.0, -0.275, -1.85);
	glScalef(1, 1, 1.7);
	glutSolidCube(0.5);
	glPopMatrix();
	glPopMatrix();

	//right wheel
	glPushMatrix();
	glTranslatef(0.25, 0.6, -2.0);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.35);
	glPopMatrix();
	//left wheel
	glPushMatrix();
	glTranslatef(-0.25, 0.6, -2.0);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.35);
	glPopMatrix();

	//right wheel
	glPushMatrix();
	glTranslatef(0.25, 0.6, -1.25);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.35);
	glPopMatrix();
	//left wheel
	glPushMatrix();
	glTranslatef(-0.25, 0.6, -1.25);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.35);
	glPopMatrix();

	//right wheel
	glPushMatrix();
	glTranslatef(0.25, 0.6, -0.5);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.35);
	glPopMatrix();
	//left wheel
	glPushMatrix();
	glTranslatef(-0.25, 0.6,-0.5);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.35);
	glPopMatrix();

	//right wheel
	glPushMatrix();
	glTranslatef(0.25, 0.6,0.3);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.35);
	glPopMatrix();
	//left wheel
	glPushMatrix();
	glTranslatef(-0.25, 0.6, 0.3);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.35);
	glPopMatrix();

	//right wheel
	glPushMatrix();
	glTranslatef(0.25, 0.6, 1.2);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.35);
	glPopMatrix();
	//left wheel
	glPushMatrix();
	glTranslatef(-0.25, 0.6, 1.2);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.35);
	glPopMatrix();

	//right wheel
	glPushMatrix();
	glTranslatef(0.25, 0.6, 1.8);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.35);
	glPopMatrix();
	//left wheel
	glPushMatrix();
	glTranslatef(-0.25, 0.6, 1.8);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glutSolidCube(0.35);
	glPopMatrix();

	//chain1
	glPushMatrix();
	glTranslatef(-0.25, 0.6, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glScalef(1, 1, 1.5);
	glutSolidCube(0.35);
	glPopMatrix();
	//chain2
	glPushMatrix();
	glTranslatef(-0.25, 0.6, -1.0);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 0, 1);
	glScalef(1, 1, 1.5);
	glutSolidCube(0.35);
	glPopMatrix();

}

void MyTimer(int x)
{
	if (star == 0)
	{
		star =1;
	}
	else if(star == 1)
	{
		star = 0;
	}
	if (jump == 0)
	{
		chicken_move = 0.05;
		jump = 1;
	}
	else if(jump==1){
		chicken_move =- 0.05;
		jump = 0;
	}
	glutPostRedisplay(); //장면 다시 불러주기
	glutTimerFunc(1500, MyTimer, 1); //recursive로 불러오기
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(-7, -5, -6);
	glTranslatef(0, 0, roadmove); //Road Movement
								
	
	glTranslatef(scene, 0, 1); //Scene Rotation x축
	//glRotatef(scene, 0, 1, 0);
	glTranslatef(0, 1, z_scene); //앞뒤로 갈 수 있게
	
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	drawGroundRoad();       //Ground & Road
	glPopMatrix();

	//house
	glPushMatrix();
	glTranslatef(-8.0, 0, -10);
	glRotatef(90, 0, 1, 0);
	for (int k = 0; k < 20; k++)
	{
		
		glTranslatef(10, 0, 0);
		drawHouse(); 
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-16.0, 0, -10);
	glRotatef(90, 0, 1, 0);
	for (int k = 0; k < 20; k++)
	{

		glTranslatef(10, 0, 0);
		drawHouse(); 
	}
	glPopMatrix();


	//train
	glPushMatrix();
	glTranslatef(6, 1, -4);
	glTranslatef(turn, 0, move);
	glTranslatef(0, 0, on);
	glRotatef(-180, 1, 0, 0);
	//glRotatef(-180, 1, 0, 1);
	drawTrain();
	glPopMatrix();

	//엄마치킨 아기치킨 앞에 한마리씩만
	glPushMatrix();
	glTranslatef(7, 0.25, -3);
	drawMomChicken();
	glTranslatef(1.5, 0, 0);
	drawBabyChicken();
	glPopMatrix();

	//타워
	//건물
	glPushMatrix();
	glColor3f(153 / 256.0, 204 / 256.0, 255 / 256.0);
	glTranslatef(-20, 25, -50);
	glRotatef(-90, 1, 0, 0);
	glScalef(1, 1, 0.7);
	glutSolidCube(10);
	glPopMatrix();
	glPushMatrix();

	//창문
	glColor3f(255 / 256.0, 255 / 256.0, 255 / 256.0);
	glTranslatef(-20, 15, -50);
	glRotatef(-90, 1, 0, 0);
	glScalef(1, 1, 4);
	glutSolidCube(10);
	glPopMatrix();

	//왼쪽 기둥
	glPushMatrix();
	glTranslatef(-21, 38, -47);
	glColor3f(102 / 256.0, 0 / 256.0, 102 / 256.0);
	glScalef(1, 3.5, 1);
	glutSolidCube(1);
	glPopMatrix();
	//오른쪽 기둥
	glPushMatrix();
	glTranslatef(-17, 38, -47);
	glColor3f(102 / 256.0, 0 / 256.0, 102 / 256.0);
	glScalef(1, 3.5, 1);
	glutSolidCube(1);
	glPopMatrix();
	//간판
	glPushMatrix();
	glTranslatef(-19, 40, -47);
	glColor3f(102 / 256.0, 0 / 256.0, 102 / 256.0);
	glScalef(8, 3, 1);
	glutSolidCube(1);
	glPopMatrix();
	
	//Moon
	glPushMatrix();
	glTranslatef(50, 50, -100);
	glColor3f(0.0, 0.0, 0.0); //black
	drawMoon();
	//translate another sphere for making crescent(초승달)
	glTranslatef(.2, 0, 0);
	glColor3f(1.0, 1.0, 0.0); //yellow
	drawMoon();
	glPopMatrix();

	//star
	glPushMatrix();
	glTranslatef(40, 50, -100);
	drawStar();
	glPopMatrix();


	if (start == -1) //control from keyboard
	{

		if (roadmove < 550)
		{
			roadmove = roadmove + .02; //Ground & Road Movement

			on = on - .022; // Truck Movement
			glutPostRedisplay();
		}
		else
		{
			//
		}

	}
	glutSwapBuffers(); //화면 뜨게 만들어주기

}

void SpecialInput(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP: //Truck Forward


		move = move - .05;

		break;


	case GLUT_KEY_DOWN: //Truck Reverse


		move += .3;

		break;

	case GLUT_KEY_LEFT: //Truck Left Turn


		turn = turn - .05;

		break;


	case GLUT_KEY_RIGHT: //Truck Righ Turn
		turn = turn + .05;
		break;

	}
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27://ESC
		exit(0);

		break;

	case 'r': //reset all scene
		angle = 0;
		move = 0;
		scene = 0;
		roadmove = 0;
		on = 0;
		turn = 0;
		break;

	case '4': //scene rotation
		scene = scene +0.5;
		break;

	case '6': //scene rotation
		scene = scene -0.5;
		break;
	case '2': //scene rotation
		z_scene = z_scene - 0.5;
		break;
	case '8': //scene rotation
		z_scene = z_scene + 0.5;
		break;

	case 'w': //strat scene
		start = -1;
		break;

	}
	glutPostRedisplay();
}

void reshape(int w, int h) // Create The Reshape Function (the viewport)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
	glLoadIdentity(); // Reset The Projection Matrix
	if (h == 0) // Calculate The Aspect Ratio Of The Window
		gluPerspective(80, (float)w, 1.0, 5000.0);
	else
		gluPerspective(80, (float)w / (float)h, 1.0, 5000.0);
	glMatrixMode(GL_MODELVIEW); // Select The Model View Matrix
	glLoadIdentity(); // Reset The Model View Matrix
}

int main(int a, char** b)
{
	glutInit(&a, b);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(600, 500);           //Size of the Window
	glutInitWindowPosition(80, 80);       //Position of the Windows  
	glutCreateWindow("MY PROJECT");           //Title of the Window
	init();
	glutDisplayFunc(display);               //Callback Function
	glutReshapeFunc(reshape);               //Callback Function
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(SpecialInput);
	glutTimerFunc(2000, MyTimer, 1);
	glutMainLoop();                           //Mainloop
	
	return 0;
}

