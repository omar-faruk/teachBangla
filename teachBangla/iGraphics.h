#pragma once
#define _CRT_SECURE_NO_WARNINGS

# include <stdio.h>
# include <stdlib.h>
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glaux.lib")
#include "glut.h"
#include <time.h>
#include <math.h>
#include <windows.h>
#include <gl\glaux.h>
#include "headers.h"

int iScreenHeight, iScreenWidth;
int iMouseX, iMouseY;
int ifft = 0;
void(*iAnimFunction[10])(void) = { 0 };
int iAnimCount = 0;
int iAnimDelays[10];
int iAnimPause[10];

static void  __stdcall iA0(HWND, unsigned int, unsigned int, unsigned long){ if (!iAnimPause[0])iAnimFunction[0](); }
static void  __stdcall iA1(HWND, unsigned int, unsigned int, unsigned long){ if (!iAnimPause[1])iAnimFunction[1](); }
static void  __stdcall iA2(HWND, unsigned int, unsigned int, unsigned long){ if (!iAnimPause[2])iAnimFunction[2](); }
static void  __stdcall iA3(HWND, unsigned int, unsigned int, unsigned long){ if (!iAnimPause[3])iAnimFunction[3](); }
static void  __stdcall iA4(HWND, unsigned int, unsigned int, unsigned long){ if (!iAnimPause[4])iAnimFunction[4](); }
static void  __stdcall iA5(HWND, unsigned int, unsigned int, unsigned long){ if (!iAnimPause[5])iAnimFunction[5](); }
static void  __stdcall iA6(HWND, unsigned int, unsigned int, unsigned long){ if (!iAnimPause[6])iAnimFunction[6](); }
static void  __stdcall iA7(HWND, unsigned int, unsigned int, unsigned long){ if (!iAnimPause[7])iAnimFunction[7](); }
static void  __stdcall iA8(HWND, unsigned int, unsigned int, unsigned long){ if (!iAnimPause[8])iAnimFunction[8](); }
static void  __stdcall iA9(HWND, unsigned int, unsigned int, unsigned long){ if (!iAnimPause[9])iAnimFunction[9](); }

using namespace std;


class Graphics{
public:
	Graphics();
	static void iDraw();

	static int iSetTimer(int msec, void(*f)(void))
	{
		int i = iAnimCount;

		if (iAnimCount >= 10){ printf("Error: Maximum number of already timer used.\n"); return -1; }

		iAnimFunction[i] = f;
		iAnimDelays[i] = msec;
		iAnimPause[i] = 0;

		if (iAnimCount == 0) SetTimer(0, 0, msec, iA0);
		if (iAnimCount == 1) SetTimer(0, 0, msec, iA1);
		if (iAnimCount == 2) SetTimer(0, 0, msec, iA2);
		if (iAnimCount == 3) SetTimer(0, 0, msec, iA3);
		if (iAnimCount == 4) SetTimer(0, 0, msec, iA4);

		if (iAnimCount == 5) SetTimer(0, 0, msec, iA5);
		if (iAnimCount == 6) SetTimer(0, 0, msec, iA6);
		if (iAnimCount == 7) SetTimer(0, 0, msec, iA7);
		if (iAnimCount == 8) SetTimer(0, 0, msec, iA8);
		if (iAnimCount == 9) SetTimer(0, 0, msec, iA9);
		iAnimCount++;

		return iAnimCount - 1;
	}
	static void iPauseTimer(int index){
		if (index >= 0 && index <iAnimCount){
			iAnimPause[index] = 1;
		}
	}

	static void iResumeTimer(int index){
		if (index >= 0 && index <iAnimCount){
			iAnimPause[index] = 0;
		}
	}

	static void iShowBMP(int x, int y, char filename[])
	{
		AUX_RGBImageRec *TextureImage;

		TextureImage = auxDIBImageLoad(filename);

		glRasterPos2f(x, y);
		glDrawPixels(TextureImage->sizeX, TextureImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);

		free(TextureImage->data);
		free(TextureImage);

	}

	static void iGetPixelColor(int cursorX, int cursorY, int rgb[])
	{
		GLubyte pixel[3];
		glReadPixels(cursorX, cursorY, 1, 1,
			GL_RGB, GL_UNSIGNED_BYTE, (void *)pixel);

		rgb[0] = pixel[0];
		rgb[1] = pixel[1];
		rgb[2] = pixel[2];

		//printf("%d %d %d\n",pixel[0],pixel[1],pixel[2]);   
	}

	
	static void iSetColor(double r, double g, double b)
	{
		double mmx;
		mmx = r;
		if (g > mmx)mmx = g;
		if (b > mmx)mmx = b;
		mmx = 255;
		if (mmx > 0){
			r /= mmx;
			g /= mmx;
			b /= mmx;
		}
		glColor3f(r, g, b);
	}

	static void iDelay(int sec)
	{
		int t1, t2;
		t1 = time(0);
		while (1){
			t2 = time(0);
			if (t2 - t1 >= sec)
				break;
		}
	}

	static void iClear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glClearColor(0, 0, 0, 0);
		glFlush();
	}

	static void displayFF(void){
		iDraw();
		glutSwapBuffers();
	}

	static void animFF(void)
	{
		//iAnimation();
		if (ifft == 0){
			ifft = 1;
			iClear();
		}
		glutPostRedisplay();
	}

	static void iKeyboard(unsigned char key);
	static void iSpecialKeyboard(unsigned char key);

	static void keyboardHandler1FF(unsigned char key, int x, int y)
	{
		iKeyboard(key);
		glutPostRedisplay();
	}
	static void keyboardHandler2FF(int key, int x, int y)
	{
		iSpecialKeyboard(key);
		glutPostRedisplay();
	}
	static void iMouseMove(int mx, int my);

	static void mouseMoveHandlerFF(int mx, int my)
	{
		iMouseX = mx;
		iMouseY = iScreenHeight - my;
		iMouseMove(iMouseX, iMouseY);

		glFlush();
	}
	static void iMouse(int button, int state, int mx, int my);

	static void mouseHandlerFF(int button, int state, int x, int y)
	{
		iMouseX = x;
		iMouseY = iScreenHeight - y;

		iMouse(button, state, iMouseX, iMouseY);

		glFlush();
	}

	static void iInitialize(int width = 500, int height = 500, char *title = "iGraphics")
	{
		iScreenHeight = height;
		iScreenWidth = width;

		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowSize(width, height);
		glutInitWindowPosition(10, 10);
		glutCreateWindow(title);
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, width, 0.0, height, -1.0, 1.0);
		//glOrtho(-100.0 , 100.0 , -100.0 , 100.0 , -1.0 , 1.0) ;
		//SetTimer(0, 0, 10, timer_proc);

		iClear();

		glutDisplayFunc(displayFF);
		glutKeyboardFunc(keyboardHandler1FF); //normal
		glutSpecialFunc(keyboardHandler2FF); //special keys
		glutMouseFunc(mouseHandlerFF);
		glutMotionFunc(mouseMoveHandlerFF);
		glutIdleFunc(animFF);

		glutMainLoop();
	}
};