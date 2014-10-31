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
	char *frame = "icons\\frame.bmp";
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
		iShowBMP(110, 110, frame);
		mainMenu.show();
		closeButton.show();
		nextButton.show();
		previousButton.show();
	}

	void show(){
		iShowBMP(0, 0, filename);
		iShowBMP(800, 110, frame);
		closeButton.show();
		nextButton.show();
		mainMenu.show();
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
		else if (x >= learnNumbers.sx && x <= learnNumbers.ex && y >= learnNumbers.sy && y <= learnNumbers.ey){
			return "numbers_menu";
		}
		else if (x >= mainMenu.sx && x <= mainMenu.ex && y >= mainMenu.sy && y <= mainMenu.ey){
			return "main_menu";
		}
		else if (x >= quiz.sx && x <= quiz.ex && y >= quiz.sy && y <= quiz.ey){
			return "quiz_menu";
		}
		return "";
	}
};

void generateQuiz(){
	int n = 50,i;
	int quiz_options[5],used[150],value;
	
	memset(used, 0, sizeof used);
	
	i = 1;
	value = rand() % n;
	used[value]++;
	quiz_options[0] = value;
	while (i <= 4)
	{
		while (used[value] != 0){
			value = rand() % n;
		}
		quiz_options[i++] = value;
		used[value]++;
	}
	cout << quiz_options[0] << " " << quiz_options[1] << " " << quiz_options[2] << " " << quiz_options[3] << "\n";

}