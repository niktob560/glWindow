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


#include <thread>
#include <math.h>
#include <vector>

#include "libpng/png.h"

#include <FTGL/ftgl.h>
#include <FTGL/FTGLPixmapFont.h>

#include "api.h"


using namespace std;

View rootObject;



void glSetColor(uint32_t color)
{
	glColor3f((float)((color >> 16) & 0xFF) / 255, (float)((color >> 8) & 0xFF) / 255,  (float)(color & 0xFF)/ 255);
}



void mainDraw(int w, int h)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glSetColor(0x000000);
	drawRect(100, 100, w, h);
	glSetColor(0xFFFFFF);
	drawRect(w / 2, h / 2, 100, 100);
	for(int i = 0; i < h; i += 120)
	{
		drawText(to_wstring(i), 20, 100, i);
	}
	for(int i = 0; i < w; i += 120)
	{
		drawText(to_wstring(i), 20, i, 100);
	}
	// glutSwapBuffers();
}

void _glReshape(int w, int h)
{
	cout << "reshape\n";
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	cout << "reshape complete\n";


	rootObject.setH(glutGet(GLUT_WINDOW_HEIGHT));
	rootObject.setW(glutGet(GLUT_WINDOW_WIDTH));
	cout << "sizes set\n";

	rootObject.setX(glutGet(GLUT_WINDOW_WIDTH) / 2);
	rootObject.setY(glutGet(GLUT_WINDOW_HEIGHT) / 2);
	cout << "coords set\n";
}


int fuck = 200;
View childObject(fuck, 100, 100, 100, &rootObject);

void _timf(int value)				// Timer function
{
	// fuck++;
	// if(fuck > glutGet(GLUT_WINDOW_WIDTH) + 100)
	// 	fuck = -300;
	// cout << "fuck " << fuck << "\n";
	childObject.setX(fuck);
	// if(!_terminated)					//if don't wanna terminate
	// {
		//cout << "redraw by timer\n";
		glutPostRedisplay();		//Redraw windows
		glutTimerFunc(10, _timf, 0);	//Setup next timer
	// }
	// else							//if wanna terminate
	// {
	// 	terminate();
	// }
}

void _handleKeypress(unsigned char key, //pressed key
										int x, int y)//coords of mouse
{
	rootObject.keyPressed(key, x, rootObject.getH() - y);
}


void _mouseClick(int button, int state, int x, int y)
{
	rootObject.mouseClicked(button, state, x, rootObject.getH() - y);
}

int __glArg__;
void _glVisualFunc()
{
	cout << "glut init\n";
	glutInit(&__glArg__, 0);
	cout << "dispmode\n";
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	cout << "windowssize\n";
	//glutInitWindowSize(800, 600);
	glutCreateWindow("glWindowStandartWindow");
	glutFullScreen();
	cout << "mouse\n";
	glutMouseFunc(_mouseClick);
	cout << "reshape\n";
	glutReshapeFunc(_glReshape);
	cout << "dispfunc\n";
    glutDisplayFunc([](){rootObject.draw();});
	cout << "keypress\n";
	glutKeyboardFunc(_handleKeypress);
	// glutIdleFunc(display);
	cout << "timer\n";
	glutTimerFunc(40, _timf, 0);
	rootObject.setDrawerFunc(mainDraw);
	cout << "mainloop\n";
	glutMainLoop();
}

void glInit(int arg)
{
	__glArg__ = arg;
	std::thread thready(_glVisualFunc);
	thready.detach();
}







using namespace std;





int msleep(ulong milisec)
{
	struct timespec req = {0};
	time_t sec = (int) (milisec/1000);
	milisec -= (sec * 1000);
	req.tv_sec = sec;
	req.tv_nsec = milisec * 1000000L;
	while(nanosleep(&req, &req) == -1)
	{
		continue;
	}
	return 1;
}



void sigintHandler(int sig)
{
	cout << "\ncauched SIGINT!\n";	//
	exit(0);
	//glutLeaveMainLoop();
	// callTerminateWindow(RETURN_CODE_SIGINT);
}





void drawButton(int x, int y, int w, int h)
{
	cout << "drawing btn\n";
	// glSetColor(0x484848);
	// drawRect(x, y, w, h);
	// glSetColor(0xFFFFFF);
	// drawRect(x, y, w - 10, h - 10);
}

void clickButton(int btn, int state)
{
	if(btn == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		cout << "BTN CLICKED!\n";
		// callTerminateWindow(RETURN_CODE_OK);
	}
}


void drawChild(int w, int h)
{
	glSetColor(0xFF0000);
	drawRect(w / 2, h / 2, w, h);
	// glutSwapBuffers();
}

void drawChild2(int w, int h)
{
	// cout << "A\n";
	// cout << w << ":" << h << "\n";
	glSetColor(0x1a1a1a1a);
	drawRect(w / 2, h / 2, w, h);
	glSetColor(0xFFFFFF);
	drawText(L"fuck.", 10, w / 2 - 10, h / 2);
	// glutSwapBuffers();
}


void endDrawAll()
{
	glutSwapBuffers();
}

void childKeyPressed(unsigned char key, int x, int y)
{
	cout << key << endl;
}


void mouseClickedChlid(int button, int state, int x, int y)
{
	cout << "\tmouce clicked! button: " << button << "; state: " << state << "; coords: " << x << ":" << y << endl;
}


int main(int argc, char * argv[])
{
	signal(SIGINT, sigintHandler); 			//set SIGINT system interrupt handler

	// rootObject = new View();
	rootObject.setDrawerFunc(mainDraw);
	rootObject.setDrawEnderFunc(endDrawAll);
	rootObject.setRootObject(&rootObject);
	rootObject.setX(0);
	rootObject.setY(0);
	rootObject.setObjectId(1);
	// rootObject.setMouseClickHandler(mouseClickedChlid);

	childObject.setDrawerFunc(drawChild);
	childObject.setMouseClickHandler(mouseClickedChlid);
	childObject.setObjectId(2);

	rootObject.registrateChildObject(&childObject);
	rootObject.setKeypressHandler(childKeyPressed);

	// View secondChildObj(50, 50, 60, 60, &childObject);
	// secondChildObj.setDrawerFunc(drawChild2);
	// childObject.registrateChildObject(&secondChildObj);


	glInit(argc);




	while(1)
	{

		//et.draw();
		//cin >> hex >> c;
		//mainView.setBgColor(c);
	}



	while(1)
	{
		asm("NOP");
	}
	return 0;
}
