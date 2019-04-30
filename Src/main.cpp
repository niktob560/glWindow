#include <iostream>
#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <termios.h>    // POSIX terminal control definitions
#include <signal.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
//#include <GL/glext.h>
#include <thread>
#include <math.h>
#include "libpng/png.h"
#include <vector>
#include <FTGL/ftgl.h>
#include <FTGL/FTGLPixmapFont.h>
#include "api.h"









using namespace std;

//
//
//
//
// int msleep(ulong milisec)
// {
// 	struct timespec req = {0};
// 	time_t sec = (int) (milisec/1000);
// 	milisec -= (sec * 1000);
// 	req.tv_sec = sec;
// 	req.tv_nsec = milisec * 1000000L;
// 	while(nanosleep(&req, &req) == -1)
// 	{
// 		continue;
// 	}
// 	return 1;
// }
//
//
//
// void sigintHandler(int sig)
// {
// 	cout << "\ncauched SIGINT!\n";	//
// 	//glutLeaveMainLoop();
// 	callTerminateWindow(RETURN_CODE_SIGINT);
// }
//
//
//
//
//
// void drawButton(int x, int y, int w, int h)
// {
// 	cout << "drawing btn\n";
// 	glSetColor(0x484848);
// 	drawRect(x, y, w, h);
// 	glSetColor(0xFFFFFF);
// 	drawRect(x, y, w - 10, h - 10);
// }
//
// void clickButton(int btn, int state)
// {
// 	if(btn == GLUT_LEFT_BUTTON && state == GLUT_UP)
// 	{
// 		cout << "BTN CLICKED!\n";
// 		callTerminateWindow(RETURN_CODE_OK);
// 	}
// }


int main(int argc, char * argv[])
{
	// signal(SIGINT, sigintHandler); 			//set SIGINT system interrupt handler
	//
	//
	// cout << "starting...\n";
	// //thread thready(visualFunc);				//set opengl handler to thread
	//
	//
	// cout << "start visual\n";
	//
	// glInit(argc);
	//
	//
	// sleep(1);
	// uint32_t c;
	// Button btn(mainView.getWidth() / 2, mainView.getHeight() / 2 - 50, 50, 20, drawButton);
	// btn.setOnClick(clickButton);
	// EditText et(40, 40, 140, 50);
	// et.setDrawFunc(drawEditText);
	// mainView.addObj(btn);
	// mainView.addObj(et);
	//
	// while(1)
	// {
	//
	// 	//et.draw();
	// 	//cin >> hex >> c;
	// 	//mainView.setBgColor(c);
	// }
	//
	//
	//
	// while(1)
	// {
	// 	asm("NOP");
	// }
	return 0;
}
