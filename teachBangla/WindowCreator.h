#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "headers.h"
#include "files\fileslist.h"

class WindowCreator
{
public:
	int px;
	int py;
	char filename[150];
	WindowCreator();
	WindowCreator(int x, int y, char *iconfile){
		px = x;
		py = y;
		strcpy(filename, iconfile);
	}
	void showMyWindow(){
		iShowBMP(px, py, filename);
	}
};

