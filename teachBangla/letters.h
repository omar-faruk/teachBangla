#include "headers.h"
#pragma once
string letterType = "";
string imageSet = "wordSet1\\";
string soundFile;
string image;
int setCount = 1;

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
vector<Letters> vowels, consonants;

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
	return false;
}
void showClickedLetter(int x, int y){

	string imageName;
	if (letterType == "vowel"){
		int n = vowels.size();
		for (int i = 0; i <n ; i++){
			if ((x >= vowels[i].sx && x <= vowels[i].ex) && (y >= vowels[i].sy && y <= vowels[i].ey)){
				imageName = vowels[i].filename;
				imageName.erase(0,8);
				imageName = imageSet + imageName;
				soundFile = imageName.substr(0, imageName.size() - 4);
				soundFile += ".WAV";
				image = imageName;
			}
		}
	}
	if(letterType=="consonant"){
		for (int i = 0; i < consonants.size(); i++){
			if ((x >= consonants[i].sx && x <= consonants[i].ex) && (y >= consonants[i].sy && y <= consonants[i].ey)){
				imageName = consonants[i].filename;
				imageName.erase(0, 8);
				imageName = imageSet + imageName;
				soundFile = imageName.substr(0, imageName.size() - 4);
				soundFile += ".WAV";
				image = imageName;
				//return consonants[i].imageFile;
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
