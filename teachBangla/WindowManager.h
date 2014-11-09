#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "letters.h"
#include "buttons.h"
#include "iGraphics.h"
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
			Graphics::iShowBMP(sx, sy, filename);
			closeButton.show();
		}

		void showDefault(){
			Graphics::iShowBMP(sx, sy, filename);
			Graphics::iShowBMP(110, 110, frame);
			mainMenu.show();
			closeButton.show();
			nextButton.show();
			previousButton.show();
		}

		void showQuizWindow(){
			Graphics::iShowBMP(0, 0, filename);
			Graphics::iShowBMP(800, 110, frame);
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
	NewWindow mainWindow(1, 1, 1300, 700, myMainWindow.data());
	NewWindow defaultWindow(1, 1, 1300, 700, defaultBackground.data());
	NewWindow quizWindow(1, 1, 1300, 700, defaultBackground.data());

	static int quiz_ans;
	static char quizLetters[55][100], selected_quiz[200];
	static int mod = 50;
	static int quiz_options[5], used[150];
	bool startQuiz = false;
	void showQuizOptions(){

		char quiz_set[5][100];
		
		Graphics::iShowBMP(128, 120, quizLetters[quiz_options[1]]);
		Graphics::iShowBMP(200, 120, quizLetters[quiz_options[2]]);
		Graphics::iShowBMP(272, 120, quizLetters[quiz_options[3]]);
		Graphics::iShowBMP(344, 120, quizLetters[quiz_options[4]]);
	}

	void generateQuiz(){

		int value, j = 5, i = 1;
		quiz_ans = rand() % 4;
		if (quiz_ans == 0){
			quiz_ans = 4;
		}
		memset(used, 0, sizeof used);
		value = rand() % mod;
		if (value == 0){
			value = 50;
		}
		used[value]++;
		quiz_options[quiz_ans] = value;

		while (i <= 4)
		{
			if (i != quiz_ans){
				while (used[value] != 0 && value != 0){
					value = rand() % mod;
					if (value == 0){
						value = 50;
					}
				}
				quiz_options[i] = value;
				used[value]++;
			}
			i++;
		}

		cout << quiz_options[quiz_ans] << endl;
		strcpy(selected_quiz, word[quiz_options[quiz_ans]][0].c_str());
		puts(selected_quiz);

		return;
	}

	void showQuiz(char *image){
		Graphics::iShowBMP(808, 118, image);
		showQuizOptions();
	}

	bool isCorrect(int mx, int my){
		int clickedOption;
		if ((mx >= 128 && mx <= 192) && (my >= 120 && my <= 184)){
			clickedOption = 1;
		}
		else if ((mx >= 200 && mx <= 264) && (my >= 120 && my <= 184)){
			clickedOption = 2;
		}
		else if ((mx >= 272 && mx <= 336) && (my >= 120 && my <= 184)){
			clickedOption = 3;
		}
		else if ((mx >= 344 && mx <= 408) && (my >= 120 && my <= 184)){
			clickedOption = 4;
		}
		if (clickedOption == quiz_ans){
			return true;
		}
		else return false;
	}

	void  clickedQuizOption(int mx, int my){
		if (isCorrect(mx, my)){
			PlaySound("quiz\\right.wav", NULL, SND_FILENAME | SND_ASYNC);
			Graphics::iDelay(2);
			generateQuiz();
		}

		else {
			PlaySound("error", NULL, SND_FILENAME | SND_ASYNC);
		}
		return;
	}
