#include "headers.h"
#pragma once
string letterType = "";
string imageSet[] = { "wordSet1\\", "wordSet2\\", "wordSet3\\" };
string soundFile;
string image;
int setCount = 0;

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
		iShowBMP(sx, sy, filename);
	}
};
vector<Letters> vowels, consonants,numbers;

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
	image[7] = char(setCount+1 + '0');
	soundFile[7] = char(setCount+1 + '0');
}

void showClickedLetter(int x, int y){
	string imageName;
	if (letterType == "vowel"){
		int n = vowels.size();
		for (int i = 0; i <n ; i++){
			if ((x >= vowels[i].sx && x <= vowels[i].ex) && (y >= vowels[i].sy && y <= vowels[i].ey)){
				imageName = vowels[i].filename;
				imageName.erase(0,8);
				imageName = imageSet[setCount] + imageName;
				soundFile = imageName.substr(0, imageName.size() - 4);
				soundFile += ".WAV";
				image = imageName;
			}
		}
	}
	else if(letterType=="consonant"){
		for (int i = 0; i < consonants.size(); i++){
			if ((x >= consonants[i].sx && x <= consonants[i].ex) && (y >= consonants[i].sy && y <= consonants[i].ey)){
				imageName = consonants[i].filename;
				imageName.erase(0, 8);
				imageName = imageSet[setCount] + imageName;
				soundFile = imageName.substr(0, imageName.size() - 4);
				soundFile += ".WAV";
				image = imageName;
			}
		}
	}
	else if (letterType == "numbers"){
		for (int i = 0; i < numbers.size(); i++){
			if ((x >= numbers[i].sx && x <= numbers[i].ex) && (y >= numbers[i].sy && y <= numbers[i].ey)){
				imageName = numbers[i].filename;
				imageName.erase(0, 8);
				imageName = imageSet[setCount] + imageName;
				soundFile = imageName.substr(0, imageName.size() - 4);
				soundFile += ".WAV";
				image = imageName;
			}
		}
	}
	return ;
}

void showAllVowels(){
	int i;
	for (i = 0; i < vowels.size(); i++){
		vowels[i].showLetter();
	}
}
void showAllConsonants(){
	int i;
	for (i = 0; i < consonants.size(); i++){
		consonants[i].showLetter();
	}
}
void showAllNumbers(){
	int i;
	for (i = 0; i < numbers.size(); i++){
		numbers[i].showLetter();
	}
}