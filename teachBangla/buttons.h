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
		iShowBMP(sx, sy, filename);
	}
};
string buttonPrevious = "icons\\button_previous.bmp";
string buttonNext = "icons\\button_next.bmp";
string buttonClose = "icons\\button_close.bmp";
string vowels_menu = "icons\\vowels.bmp";
string consonants_menu="icons\\consonant.bmp";
string main_menu = "icons\\main_menu.bmp";

Button closeButton(1300 - 64, 700 - 64, 1300, 700, buttonClose.data());
Button mainMenu(944 ,636,1200,700,main_menu.data());
Button nextButton(300, 48, 349, 96, buttonNext.data());
Button previousButton(200, 48, 249, 96, buttonPrevious.data());
Button learnVowels(400, 400, 656, 464, vowels_menu.data());
Button learnConsonents(400,300,656,364,consonants_menu.data());


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
	else if (x >= mainMenu.sx && x <= mainMenu.ex && y >= mainMenu.sy && y <= mainMenu.ey){
		return true;
	}
	return false;
}
