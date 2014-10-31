#include "WindowManager.cpp"
#define _CRT_SECURE_NO_WARNINGS

string clickedButton;
NewWindow mainWindow(1, 1, 1300, 700, myMainWindow.data());
NewWindow defaultWindow(1, 1, 1300, 700, defaultBackground.data());
NewWindow quizWindow(1, 1, 1300, 700, defaultBackground.data());

bool play = false;
bool startQuiz = false;

void show(const char *letter){
	char file[150];
	strcpy(file, letter);
	iShowBMP(118, 117, file);
}
void showQuiz(const char *letter){
	char file[150];
	strcpy(file, letter);
	iShowBMP(801, 111, file);
}

void iDraw() {
	iClear();

	if (letterType == ""){
	
		if (startQuiz==true){
			quizWindow.show();
		}

	 else{
			mainWindow.showMain();
			learnVowels.show();
			learnConsonents.show();
			learnNumbers.show();
			quiz.show();
		}
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
	if (image != ""){
		show(image.data());
		if (play == false){
			play = true;
			PlaySound(soundFile.data() , NULL, SND_FILENAME | SND_ASYNC);
		}
	}
}

void iMouseMove(int mx, int my) {

}

void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		if (isButton(mx, my)){
			clickedButton = mainWindow.clickedButton(mx, my);
			if (clickedButton == "closeButton"){
				image = "";
				exit(0);
			}
			if (clickedButton == "vowels_menu"){
				setCount = 0;
				letterType = "vowel";
				image = "";
			}
			if (clickedButton == "consonant_menu"){
				setCount = 0;
				letterType = "consonant";
				image = "";
			}
			if (clickedButton == "numbers_menu"){
				setCount = 0;
				letterType = "numbers";
				image = "";
			}
			if (clickedButton == "main_menu"){
				setCount = 0;
				startQuiz = false;
				letterType = "";
				image = "";
			}
			if (clickedButton == "quiz_menu"){
				setCount = 0;
				letterType = "";
				image = "";
				startQuiz = true;
				generateQuiz();
			}
			if (clickedButton == "nextButton"){
				if (startQuiz==true){
					generateQuiz();

				}
				else{
					setCount++;
					play = false;
					changeSet();
				}
			}
			if (clickedButton == "previousButton"){
				setCount--;
				play = false;
				changeSet();
			}
		}
		if (isLetter(mx, my)){
			setCount = 0;
			showClickedLetter(mx, my);
			play = false;
		}		
	}
}

void iKeyboard(unsigned char key) {

	if (key == 'q') {
		exit(0);
	}
	return;
}

void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
}
int main()
{
	freopen("letters\\vowels.txt", "r", stdin);
	int i;
	int startx, starty, endx, endy;
	string location = "letters\\";

	for (i = 1; i <=11; i++){
		string file;
		cin >> startx >> starty >> endx >> endy >> file;
		file = location + file;
		Letters temp(startx, starty, endx, endy, file.data());
		vowels.push_back(temp);
		}

	freopen("letters\\consonants.txt", "r", stdin);
	for (i = 1; i <=39; i++){
		string file;
		cin >> startx >> starty >> endx >> endy >> file;
		file = location + file;
		Letters temp(startx, starty, endx, endy, file.data());
		consonants.push_back(temp);
	}

	freopen("letters\\numbers.txt", "r", stdin);
	for (i = 1; i <= 9; i++){
		string file;
		cin >> startx >> starty >> endx >> endy >> file;
		file = location + file;
		Letters temp(startx, starty, endx, endy, file.data());
		numbers.push_back(temp);
	}
	iInitialize(1300,700,"Learn Bangla with Fun");

	return 0;
}
