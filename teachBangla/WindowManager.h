#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "headers.h"
#include "files\fileslist.h"

class Button
{
public:
	int sx;
	int sy;
	int ex;
	int ey;
	char filename[150];
public:
	Button();
	Button(int x, int y, int end_x, int end_y, const char *iconfile){
		sx = x;
		sy = y;
		ex = end_x;
		ey = end_y;
		strcpy(filename, iconfile);
	}
	void show(){
		iShowBMP(sx, sy, filename);
	}

};
Button closeButton(1200 - 48, 800 - 48, 1200, 800, buttonClose.data());
Button nextButton();

class NewWindow
{
public:
	int sx;
	int sy;
	int ex;
	int ey;
	char filename[150];
public:
	NewWindow();
	NewWindow(int x, int y, int end_x, int end_y, const char *iconfile){
		sx = x;
		sy = y;
		ex = end_x;
		ey = end_y;
		strcpy(filename, iconfile);
	}
	void show(){
		iShowBMP(sx, sy, filename);
		closeButton.show();
	}

	string clickedButton(int x, int y){
		if (x >= closeButton.sx && x <= closeButton.ex && y >= closeButton.sy && y <= closeButton.ey){
			return "closeButton";
		}
	}
};