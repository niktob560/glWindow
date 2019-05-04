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
#include <map>
#include <string>

#include "libpng/png.h"

#include <FTGL/ftgl.h>
#include <FTGL/FTGLPixmapFont.h>

#include "api.h"


using namespace std;

View rootView;



void glSetColor(uint32_t color)
{
	glColor3f((float)((color >> 16) & 0xFF) / 255, (float)((color >> 8) & 0xFF) / 255,  (float)(color & 0xFF)/ 255);
}



void mainDraw(BaseGlObj* owner)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glSetColor(0x000000);
	drawRect(100, 100, owner->getW(), owner->getH());
	glSetColor(0xFFFFFF);
	drawRect(owner->getW() / 2, owner->getH() / 2, 100, 100);
	for(int i = 0; i < owner->getH(); i += 120)
	{
		drawText(to_wstring(i), 20, 100, i);
	}
	for(int i = 0; i < owner->getW(); i += 120)
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


	rootView.setH(glutGet(GLUT_WINDOW_HEIGHT));
	rootView.setW(glutGet(GLUT_WINDOW_WIDTH));
	cout << "sizes set\n";

	rootView.setX(glutGet(GLUT_WINDOW_WIDTH) / 2);
	rootView.setY(glutGet(GLUT_WINDOW_HEIGHT) / 2);
	cout << "coords set\n";
}


int fuck = 200;
View childView(fuck, 100, 100, 100, &rootView);
bool wannaFuck = true;

void _timf(int value)				// Timer function
{
	if(wannaFuck)
	{
		fuck++;
		if(fuck > glutGet(GLUT_WINDOW_WIDTH) + 100)
			fuck = -300;
	}
	// cout << "fuck " << fuck << "\n";
	childView.setX(fuck);
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
	rootView.sendMessage(BaseGlObj::MSG_TYPE_KEYBOARD,
		{
			make_pair(BaseGlObj::MSG_PART_KEY, key),
			make_pair(BaseGlObj::MSG_PART_X, x),
			make_pair(BaseGlObj::MSG_PART_Y, rootView.getH() - y)
		});
}


void _mouseClick(int button, int state, int x, int y)
{
	rootView.sendMessage(BaseGlObj::MSG_TYPE_MOUSE,
		{
			make_pair(BaseGlObj::MSG_PART_BUTTON, button),
			make_pair(BaseGlObj::MSG_PART_STATE, state),
			make_pair(BaseGlObj::MSG_PART_X, x),
			make_pair(BaseGlObj::MSG_PART_Y, rootView.getH() - y)
		});
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
    glutDisplayFunc([](){rootView.draw();});
	cout << "keypress\n";
	glutKeyboardFunc(_handleKeypress);
	// glutIdleFunc(display);
	cout << "timer\n";
	glutTimerFunc(40, _timf, 0);
	rootView.setDrawerFunc(mainDraw);
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







void drawChild(BaseGlObj* owner)
{
	glSetColor(0xFF0000);
	drawRect(owner->getW() / 2, owner->getH() / 2, owner->getW(), owner->getH());
	// glutSwapBuffers();
}

void drawChild2(BaseGlObj* owner)
{
	// cout << "A\n";
	// cout << w << ":" << h << "\n";
	// cout << "dc2 " << w << ":" << h << endl;
	glSetColor(0x1a1a1a1a);
	drawRect(owner->getW() / 2, owner->getH() / 2, owner->getW(), owner->getH());
	glSetColor(0xFFFFFF);
	drawText(L"fuck.", 10, owner->getW() / 2 - 10, owner->getH() / 2);
	// glutSwapBuffers();
}


void endDrawAll()
{
	glutSwapBuffers();
}

void childKeyPressed(unsigned char key, int x, int y)
{
	cout << "\tKey pressed! Key: " << key << "; code: " << (int)key << "; coords: " << x << ":" << y << endl;
}


void mouseClickedChlid(int button, int state, int x, int y)
{
	cout << "\tMouce clicked! Button: " << button << "; state: " << state << "; coords: " << x << ":" << y << endl;
	if(state == 1 && button == 0)
		wannaFuck = !wannaFuck;
}

// void testF(map<int, int> data)
// {
// 	for (auto it = data.begin(); it != data.end(); it++)
//     {
//        cout << it->first << " : "<< it->second << endl;
//     }
// }

void drawButton(BaseGlObj* owner)
{
	glSetColor(0xFFFFFF);
	drawRect(20, 20, owner->getW(), owner->getH());
	glSetColor(0x000000);
	drawText(((BaseGlButton*)owner)->getText(), 10, 8, 20);
}

void buttonClicked(int button, int state, int x, int y)
{
	cout << "button clicked!" << endl;
}


int main(int argc, char * argv[])
{
	signal(SIGINT, sigintHandler); 			//set SIGINT system interrupt handler

	// rootView = new View();
	rootView.setDrawerFunc(mainDraw);
	rootView.setDrawEnderFunc(endDrawAll);
	rootView.setRootObject(&rootView);
	rootView.setX(0);
	rootView.setY(0);
	rootView.setObjectId(1);

	childView.setDrawerFunc(drawChild);
	// childView.setMouseClickHandler(mouseClickedChlid);
	childView.setObjectId(2);
	// childView.setKeypressHandler(childKeyPressed);
	childView.setW(100);
	childView.setH(100);

	rootView.registrateChildObject(&childView);

	BaseGlButton btn(20, 20, 50, 30, &childView, L"Button");
	btn.setDrawerFunc(drawButton);
	btn.setMouseClickHandler(buttonClicked);
	btn.setObjectId(4);
	childView.registrateChildObject(&btn);

	// View secondChildView(20, 20, 60, 60, &childView);
	// secondChildView.setObjectId(3);
	// secondChildView.setDrawerFunc(drawChild2);
	// childView.registrateChildObject(&secondChildView);
	// secondChildView.setMouseClickHandler(mouseClickedChlid);
	// secondChildView.setKeypressHandler(childKeyPressed);

	// testF({	make_pair(BaseGlObj::MSG_PART_BUTTON, 	1),
	// 		make_pair(BaseGlObj::MSG_PART_STATE, 	0),
	// 		make_pair(BaseGlObj::MSG_PART_X,	 	100),
	// 		make_pair(BaseGlObj::MSG_PART_Y, 		100)});

	glInit(argc);


	// sleep(2);
	// rootView.sendMessage(BaseGlObj::MSG_TYPE_MOUSE,
	// 	{
	// 		make_pair(BaseGlObj::MSG_PART_BUTTON, 1),
	// 		make_pair(BaseGlObj::MSG_PART_STATE, 2),
	// 		make_pair(BaseGlObj::MSG_PART_X, childView.getX() + 10),
	// 		make_pair(BaseGlObj::MSG_PART_Y, childView.getY() + 10)
	// 	});

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
