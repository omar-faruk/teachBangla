#include "WindowManager.h"
#define _CRT_SECURE_NO_WARNINGS

bool play = false;

void show(const char *letter){
	char file[150];
	strcpy(file, letter);
	Graphics::iShowBMP(118, 117, file);
}

void Graphics::iDraw() {
	iClear();

	if (letterType == ""){
		mainWindow.showMain();
		learnVowels.show();
		learnConsonents.show();
		learnNumbers.show();
		quiz.show();
	}
	else if (letterType == "vowel"){
		defaultWindow.showDefault();
		showAllVowels();
	}
	else if (letterType == "consonant"){
		defaultWindow.showDefault();
		showAllConsonants();
	}
	else if (letterType == "numbers"){
		defaultWindow.showDefault();
		showAllNumbers();
	}
	else if (letterType == "quiz"){
		if (startQuiz == true){
			quizWindow.showQuizWindow();
			showQuiz(selected_quiz);
		}
		else quizWindow.showQuizButtons();
	}
	if (image != ""){
		show(image.data());
		if (play == false){
			play = true;
			PlaySound(soundFile.data(), NULL, SND_FILENAME | SND_ASYNC);
		}
	}
}

void Graphics::iMouseMove(int mx, int my) {

}

void Graphics::iMouse(int button, int state, int mx, int my) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		if (isButton(mx, my)){
			clickedButton = mainWindow.clickedButton(mx, my);
			if (clickedButton == "closeButton"){
				image = "";
				exit(0);
			}
			else if (clickedButton == "vowels_menu" &&!startQuiz && letterType == ""){
				setCount = 0;
				letterType = "vowel";
				image = "";
			}
			else if (clickedButton == "consonant_menu" && !startQuiz && letterType == ""){
				setCount = 0;
				letterType = "consonant";
				image = "";
			}
			else if (clickedButton == "numbers_menu" && !startQuiz && letterType == ""){
				setCount = 0;
				letterType = "numbers";
				image = "";
			}
			else if (clickedButton == "main_menu"){
				setCount = 0;
				quiz_window=startQuiz = false;
				letterType = "";
				image = "";
			}
			else if (clickedButton == "quiz_menu" && letterType == "" && !startQuiz){
				quiz_window = true;
				setCount = 0;
				letterType = "quiz";
				image = "";
				
			}
			else if (clickedButton == "number_quiz" && letterType=="quiz"){
				startQuiz = true;
				startNumberQuiz = true;
				quizWindow.showQuizWindow();
				generateQuiz();
			}
			else if (clickedButton == "letter_quiz" && letterType=="quiz"){
				startQuiz = true;
				startNumberQuiz = false;
				quizWindow.showQuizWindow();
				generateQuiz();
			}

			else if (clickedButton == "nextButton"){
			if(!startQuiz){
					setCount++;
					play = false;
					changeSet();
				}
				if (startQuiz == true){
					generateQuiz();
				}
				
			}
			else if (clickedButton == "previousButton" && !startQuiz){
				setCount--;
				play = false;
				changeSet();
			}
		}
		if (isLetter(mx, my) && !startQuiz){
			selectedLetter=ClickedLetter(mx, my);
			image = word[selectedLetter][setCount];
			soundFile = word[selectedLetter][setCount];
			soundFile[soundFile.size() - 1] = 'v';
			soundFile[soundFile.size() - 2] = 'a';
			soundFile[soundFile.size() - 3] = 'w';
			play = false;
		}
		if ((isQuizButton(mx, my))){
			clickedQuizOption(mx, my);
		}
	}
}

void Graphics::iKeyboard(unsigned char key) {

	if (key == 'q') {
		exit(0);
	}
	return;
}

void Graphics::iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
}

void getAllFiles(char *name,int i)
{
	char search[200]="wordSet\\";
	string fileName;
	strcat(search, name);
	strcat(search, "_*");
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search, &fd);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do{
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)){
				fileName = fd.cFileName;
				if (fileName[fileName.size()-1]=='p'){
					string bmpFile = "wordSet\\";
					bmpFile +=fileName;
					word[i].push_back(bmpFile);
				}
			}

		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	return ;
}

int main()
{
	int i,startx, starty, endx, endy;
	string location = "letters\\";
	char key[1000];
	setCount = 0;
	for (i = 1; i <= 60; i++){
		_itoa(i, key, 10);
		getAllFiles(key,i);
	}

	freopen("letters\\vowels.txt", "r", stdin);
	
	for (i = 1; i <= 12; i++){
		string file;
		cin >> startx >> starty >> endx >> endy >> file;
		file = location + file;
		Letters temp(startx, starty, endx, endy, file.data());
		vowels.push_back(temp);
	}

	freopen("letters\\consonants.txt", "r", stdin);
	for (i = 1; i <= 39; i++){
		string file;
		cin >> startx >> starty >> endx >> endy >> file;
		file = location + file;
		Letters temp(startx, starty, endx, endy, file.data());
		consonants.push_back(temp);
	}
	freopen("quiz\\quiz.txt", "r", stdin);
	for (i = 1; i <= 59; i++){
		scanf("%s", quizLetters[i]);
	}
	freopen("letters\\numbers.txt", "r", stdin);
	for (i = 1; i <= 9; i++){
		string file;
		cin >> startx >> starty >> endx >> endy >> file;
		file = location + file;
		Letters temp(startx, starty, endx, endy, file.data());
		numbers.push_back(temp);
	}
	clickedButton = "main_menu";
	Graphics::iInitialize(1300, 700, "Learn Bangla with Fun");

	return 0;
}