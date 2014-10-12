#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "letters.h"
#include "buttons.h"

string myMainWindow = "icons\\main_background.bmp";
string defaultBackground = "icons\\default.bmp";


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
	void showMain(){
		iShowBMP(sx, sy, filename);
		closeButton.show();
	}
	void showDefault(){
		iShowBMP(sx, sy, filename);
		closeButton.show();
		nextButton.show();
		previousButton.show();
	}
	string clicked(int x, int y){
		
		
		if (isButton(x,y)){
			return clickedButton(x, y);
		}
		if (isLetter(x, y)){
			return clickedLetter(x, y);
		}
		return "";
	}

	string clickedButton(int x, int y){
		if (x >= closeButton.sx && x <= closeButton.ex && y >= closeButton.sy && y <= closeButton.ey){
			return "closeButton";
		}
		else if (x >= nextButton.sx && x <= nextButton.ex && y >= nextButton.sy && y <= nextButton.ey){
			return "nextButton";
		}
		else if (x >= previousButton.sx && x <= previousButton.ex && y >= previousButton.sy && y <= previousButton.ey){
			return "previousButton";
		}
		else if (x >= learnVowels.sx && x <= learnVowels.ex && y >= learnVowels.sy && y <= learnVowels.ey){
			return "vowels_menu";
		}
		else if (x >= learnConsonents.sx && x <= learnConsonents.ex && y >= learnConsonents.sy && y <= learnConsonents.ey){
			return "consonant_menu";
		}
	}
};