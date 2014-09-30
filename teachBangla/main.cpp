#include "WindowManager.h"
#define _CRT_SECURE_NO_WARNINGS
NewWindow mainWindow(1, 1, 1200, 800, myMainWindow);

void iDraw() {
	iClear();	
	mainWindow.show();


}

void iMouseMove(int mx, int my) {
}

void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		string s = mainWindow.clickedButton(mx, my);

		if (s == "closeButton"){
			exit(0);
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
//InitializeKnightPosition();

	iInitialize(1200,800,"Fun and Learn");
	return 0;
}
