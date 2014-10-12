#include "headers.h"
#pragma once
string letterType = "";
class Letters
{
public:
	int sx;
	int sy;
	int ex;
	int ey;
	char filename[150];
	char *imageFile;
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
	void setImage(const char *imageName){
		strcpy(imageFile, imageName);
	}
	void showLetter(){
		iShowBMP(sx, sy, filename);
	}
	void showImage(){
		iShowBMP(120, 120, imageFile);
	}
};
vector<Letters> vowels, consonants;

bool isLetter(int x, int y){
	return false;
}
string clickedLetter(int x, int y){

	if (letterType == "vowel"){
		int n = vowels.size();
		for (int i = 0; i <n ; i++){
			if ((x >= vowels[i].sx && x <= vowels[i].ex) && (y >= vowels[i].sy && y <= vowels[i].ey)){
				printf("%s\n", vowels[i].filename);
				return vowels[i].filename;
			}
		}
	}
	else{
		for (int i = 0; i < consonants.size(); i++){
			if (x >= consonants[i].sx && x <= consonants[i].ex && y >= consonants[i].sy && y <= consonants[i].ey)
				return consonants[i].filename;
		}
	}
	return "";
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