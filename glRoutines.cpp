#include "view.h"

using namespace std;
bool _terminated = false;

void glSetColor(uint32_t color)
{
	glColor3f((float)(color & 0xFF) / 255, (float)((color >> 8) & 0xFF) / 255, (float)((color >> 16) & 0xFF) / 255);
}

void _terminateWindow(int code = RETURN_CODE_OK)
{
	cout << "terminated\n";
	_terminated = false;			//set terminated flag
	exit(code);		//terminate thread
}

void callTerminateWindow(int code)
{
	_terminated = true;				//send terminate
	while(_terminated){asm("nop");}			//wait to terminating
	_terminateWindow(code);
	
}

View mainView;
void _timf(int value)				// Timer function
{
	if(!_terminated)					//if don't wanna terminate
	{
		//cout << "redraw by timer\n";
		glutPostRedisplay();		//Redraw windows
		glutTimerFunc(40, _timf, 0);	//Setup next timer
	}
	else							//if wanna terminate
	{
		terminate();
	}
}


void _mouseClick(int button, int state, int x, int y)
{
	baseGlObj obj = mainView.checkClick(x, y);
	if(obj.getWidth() != -1)
	{
		obj.onClick(button, state);
	}
} 


void _handleKeypress(unsigned char key, //The key that was pressed                                                                                                           
                                        int x, int y) //The current mouse coordinates      
{                                                                                
	switch (key) 
	{
		case 27 : //Escape key
		case 'q':
			terminate();
			break;
	}
}

void mainDraw(int x, int y, int w, int h)
{
	//cout << "maindraw\n";
	glClear(GL_COLOR_BUFFER_BIT);
	glSetColor(mainView.getBgColor());
	//glColor3f(1, 1, 1);
	drawRect(x, y, w, h);
	mainView.drawChild();
	glutSwapBuffers();
}


void _reshape(int w, int h)
{
	cout << "reshape\n";
	glViewport(0, 0, w, h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	cout << "reshape complete\n";
	mainView.setWidth(glutGet(GLUT_WINDOW_WIDTH));
	mainView.setHeight(glutGet(GLUT_WINDOW_HEIGHT));
	cout << "sizes set\n";
	mainView.setX(glutGet(GLUT_WINDOW_WIDTH) / 2);
	mainView.setY(glutGet(GLUT_WINDOW_HEIGHT) / 2);
	cout << "coords set\n";
}

int __glArg__;
void _visualFunc()
{
	cout << "glut init\n";
	glutInit(&__glArg__, 0);
	cout << "dispmode\n";
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	cout << "windowssize\n";
	//glutInitWindowSize(800, 600);
	glutCreateWindow("monitor");
	glutFullScreen();
	cout << "mouse\n";
	glutMouseFunc(_mouseClick);
	cout << "reshape\n";
	glutReshapeFunc(_reshape);
	cout << "dispfunc\n";
	glutDisplayFunc([](){mainView.draw();});
	cout << "keypress\n";
	glutKeyboardFunc(_handleKeypress);
	//glutIdleFunc(display);
	cout << "timer\n";
	glutTimerFunc(40, _timf, 0);
	mainView.setDrawFunc(mainDraw);
	cout << "mainloop\n";
	glutMainLoop();
}

void glInit(int arg)
{
	__glArg__ = arg;
	std::thread thready(_visualFunc);
	thready.detach();
}