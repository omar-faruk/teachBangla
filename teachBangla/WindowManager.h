#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "letters.h"
#include "buttons.h"
#include "iGraphics.h"
string myMainWindow = "icons\\main_background.bmp";
string defaultBackground = "icons\\default.bmp";
bool startQuiz = false;
bool quiz_window = false,startNumberQuiz=false;

class NewWindow
	{
	public:
		int sx;
		int sy;
		int ex;
		int ey;
		char filename[150];
		char quizBackground[150];
		char QuizQuestion[150];
		char frame[100] ;
	public:
		NewWindow();
		NewWindow(int x, int y, int end_x, int end_y, const char *iconfile){
			sx = x;
			sy = y;
			ex = end_x;
			ey = end_y;
			strcpy(filename, iconfile);
			strcpy(frame , "icons\\frame.bmp");
			strcpy(quizBackground , "icons\\default.bmp");
			strcpy(QuizQuestion, "icons\\question.bmp");
		}
		void showMain(){
			Graphics::iShowBMP(sx, sy, filename);
			closeButton.show();
		}
		void showQuizButtons(){
			Graphics::iShowBMP(0, 0, filename);
			mainMenu.show();
			closeButton.show();
			letterQuiz.show();
			numberQuiz.show();
		}
		void showQuestion(){
			Graphics::iShowBMP(810, 510, QuizQuestion);
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
			Graphics::iShowBMP(0, 0, quizBackground);
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
				if (quiz_window){
					return "letter_quiz";
				}
				else return "consonant_menu";
			}
			else if (x >= learnNumbers.sx && x <= learnNumbers.ex && y >= learnNumbers.sy && y <= learnNumbers.ey){
				if (quiz_window){
					return "number_quiz";
				}
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
	NewWindow quizWindow(1, 1, 1300, 700, myMainWindow.data());

	static int quiz_ans;
	static char quizLetters[65][100], selected_quiz[200];
	int mod;
	static int quiz_options[5], used[150];
	void showQuizOptions(){

		char quiz_set[5][100];
		if (startNumberQuiz){
			quizWindow.showQuestion();
		}
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
		if (startNumberQuiz==true){
			mod = 10;
		}
		else mod = 50;

		value = rand() % mod;
		if (value == 0){
			if (startNumberQuiz){
				value = 59;
			}
			else value = 50;
		}
		if (startNumberQuiz){
			value += 50;
		}
		used[value]++;
		quiz_options[quiz_ans] = value;

		while (i <= 4)
		{
			if (i != quiz_ans){
			top:;
			value = rand() % mod;
				if (value == 0){
					if (startNumberQuiz){
						value = 9;
					}
					else value = 50;
				}
				if (startNumberQuiz){
					value += 50;
				}
				if (used[value] != 0) goto top;
				quiz_options[i] = value;
				used[value]++;
			}
			i++;
		}
		cout << used[quiz_options[1]]<<" ";
		cout << used[quiz_options[2]] << " ";
		cout << used[quiz_options[3]] << " "; 
		cout << used[quiz_options[4]] << endl;
		strcpy(selected_quiz, word[quiz_options[quiz_ans]][0].c_str());
		//puts(selected_quiz);
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
			const char *imageOfLetter = word[quiz_options[quiz_ans]][0].data();
			int len = strlen(imageOfLetter);
			char soundOfLetter[100];
			strcpy(soundOfLetter, imageOfLetter);
			soundOfLetter[len - 1] = 'v';
			soundOfLetter[len - 2] = 'a';
			soundOfLetter[len - 3] = 'w';
			puts(soundOfLetter);
			PlaySound(soundOfLetter, NULL, SND_FILENAME | SND_ASYNC);
			Graphics::iDelay(2.5);
			generateQuiz();
		}

		else {
			PlaySound("quiz\\wrong.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		return;
	}
