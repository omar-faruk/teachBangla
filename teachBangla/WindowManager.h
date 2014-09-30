#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "headers.h"
#include "files\fileslist.h"

class Button
{
public:
	int px;
	int py;
	int ex;
	int ey;
	char filename[150];
public:
	Button();
	Button(int x, int y, int end_x, int end_y, char *iconfile){
		px = x;
		py = y;
		ex = end_x;
		ey = end_y;
		strcpy(filename, iconfile);
	}
	void show(){
		iShowBMP(px, py, filename);
	}

};
Button closeButton(1200 - 48, 800 - 48, 1200, 800, buttonClose);
Button nextButton();

class NewWindow
{
public:
	int px;
	int py;
	int ex;
	int ey;
	char filename[150];
public:
	NewWindow();
	NewWindow(int x, int y, int end_x, int end_y, char *iconfile){
		px = x;
		py = y;
		ex = end_x;
		ey = end_y;
		strcpy(filename, iconfile);
	}
	void show(){
		iShowBMP(px, py, filename);
		closeButton.show();
	}

	string clickedButton(int x, int y){
		if (x >= closeButton.px && x <= closeButton.ex && y >= closeButton.py && y <= closeButton.ey){
			return "closeButton";
		}
	}

};