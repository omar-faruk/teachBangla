#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "headers.h"
#include "iGraphics.h"

vector<string>word[100];
string letterType = "",image="",soundFile="";
int setCount = 0,selectedLetter;

class Letters
{
public:
	int sx;
	int sy;
	int ex;
	int ey;
	char filename[150];
public:
	Letters();
	Letters(int x, int y, int end_x, int end_y, const char *iconfile){
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
	void showLetter(){
		Graphics::iShowBMP(sx, sy, filename);
	}
};
vector<Letters> vowels, consonants, numbers;

bool isLetter(int x, int y){
	if (letterType == "vowel"){
		int n = vowels.size();
		for (int i = 0; i <n; i++){
			if ((x >= vowels[i].sx && x <= vowels[i].ex) && (y >= vowels[i].sy && y <= vowels[i].ey)){
				return true;
				break;
			}
		}
	}
	if (letterType == "consonant"){
		int n = consonants.size();
		for (int i = 0; i < n; i++){
			if ((x >= consonants[i].sx && x <= consonants[i].ex) && (y >= consonants[i].sy && y <= consonants[i].ey)){
				return true;
				break;
			}
		}
	}
	if (letterType == "numbers"){
		int n = numbers.size();
		for (int i = 0; i < n; i++){
			if ((x >= numbers[i].sx && x <= numbers[i].ex) && (y >= numbers[i].sy && y <= numbers[i].ey)){
				return true;
				break;
			}
		}
	}
	return false;
}

void changeSet(){

	if (setCount >= word[selectedLetter].size()){
		setCount = 0;
	}

	image = word[selectedLetter][setCount];

	cout << "After setChange=" << image << endl;
	soundFile = word[selectedLetter][setCount];
	soundFile[soundFile.size() - 1] = 'v';
	soundFile[soundFile.size() - 2] = 'a';
	soundFile[soundFile.size() - 3] = 'w';
}

int ClickedLetter(int x, int y){
	if (letterType == "vowel"){
		int n = vowels.size();
		for (int i = 0; i <n; i++){
			if ((x >= vowels[i].sx && x <= vowels[i].ex) && (y >= vowels[i].sy && y <= vowels[i].ey)){
				return i + 1;
			}
		}
	}
	else if (letterType == "consonant"){
		for (int i = 0; i < int(consonants.size()); i++){
			if ((x >= consonants[i].sx && x <= consonants[i].ex) && (y >= consonants[i].sy && y <= consonants[i].ey)){
				return 11 + i + 1;
			}
		}
	}
	else if (letterType == "numbers"){
		for (int i = 0; i < int(numbers.size()); i++){
			if ((x >= numbers[i].sx && x <= numbers[i].ex) && (y >= numbers[i].sy && y <= numbers[i].ey)){
				return 50 + i + 1;
			}
		}
	}
	return -1;
}

void showAllVowels(){
	int i;
	for (i = 0; i < int(vowels.size()); i++){
		vowels[i].showLetter();
	}
}
void showAllConsonants(){
	int i;
	for (i = 0; i < int(consonants.size()); i++){
		puts(consonants[i].filename);
		consonants[i].showLetter();
	}
}
void showAllNumbers(){
	int i;
	for (i = 0; i < int(numbers.size()); i++){
		numbers[i].showLetter();
	}
}