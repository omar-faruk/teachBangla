#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "headers.h"
#include "iGraphics.h"

string clickedButton;
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
		void setData(int x, int y, int end_x, int end_y, const char *iconfile){
			sx = x;
			sy = y;
			ex = end_x;
			ey = end_y;
			strcpy(filename, iconfile);
		}
		void show(){
			Graphics::iShowBMP(sx, sy, filename);
		}
};
string buttonPrevious = "icons\\button_previous.bmp";
string buttonNext = "icons\\button_next.bmp";
string buttonClose = "icons\\button_close.bmp";
string vowels_menu = "icons\\vowels.bmp";
string consonants_menu = "icons\\consonant.bmp";
string main_menu = "icons\\main_menu.bmp";
string numbers_menu = "icons\\numbers.bmp";
string quiz_menu = "icons\\quiz.bmp";
string letter_quiz = "icons\\letterQuiz.bmp";
string number_quiz = "icons\\numberQuiz.bmp";

Button closeButton(1300 - 64, 700 - 64, 1300, 700, buttonClose.data());
Button mainMenu(944, 636, 1200, 700, main_menu.data());
Button nextButton(300, 48, 349, 96, buttonNext.data());
Button previousButton(200, 48, 249, 96, buttonPrevious.data());
Button learnVowels(400, 450, 656, 514, vowels_menu.data());
Button learnConsonents(400, 350, 656, 414, consonants_menu.data());
Button learnNumbers(400, 250, 656, 314, numbers_menu.data());
Button quiz(400, 150, 656, 214, quiz_menu.data());
Button letterQuiz(400, 350, 656, 414, letter_quiz.data());
Button numberQuiz(400, 250, 656, 314, number_quiz.data());

bool isButton(int x, int y){

	if (x >= closeButton.sx && x <= closeButton.ex && y >= closeButton.sy && y <= closeButton.ey){
		return true;
	}
	else if (x >= nextButton.sx && x <= nextButton.ex && y >= nextButton.sy && y <= nextButton.ey){
		return true;
	}
	else if (x >= previousButton.sx && x <= previousButton.ex && y >= previousButton.sy && y <= previousButton.ey){
		return true;
	}
	else if (x >= learnVowels.sx && x <= learnVowels.ex && y >= learnVowels.sy && y <= learnVowels.ey){
		return true;
	}
	else if (x >= learnConsonents.sx && x <= learnConsonents.ex && y >= learnConsonents.sy && y <= learnConsonents.ey){
		return true;
	}
	else if (x >= learnNumbers.sx && x <= learnNumbers.ex && y >= learnNumbers.sy && y <= learnNumbers.ey){
		return true;
	}
	else if (x >= mainMenu.sx && x <= mainMenu.ex && y >= mainMenu.sy && y <= mainMenu.ey){
		return true;
	}
	else if (x >= quiz.sx && x <= quiz.ex && y >= quiz.sy && y <= quiz.ey){
		return true;
	}
	return false;
}
bool isQuizButton(int mx, int my){
	if ((mx >= 128 && mx <= 192) && (my >= 120 && my <= 184)){
		return true;
	}
	else if ((mx >= 200 && mx <= 264) && (my >= 120 && my <= 184)){
		return true;
	}
	else if ((mx >= 272 && mx <= 336) && (my >= 120 && my <= 184)){
		return true;
	}
	else if ((mx >= 344 && mx <= 408) && (my >= 120 && my <= 184)){
		return true;
	}
	return false;
}
