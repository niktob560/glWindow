void glSetColor(uint32_t color)
{
	glColor3f((float)(color & 0xFF) / 255, (float)((color >> 8) & 0xFF) / 255, (float)((color >> 16) & 0xFF) / 255);
}

using namespace std;
 bool _terminated = false;

void mainDraw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawRect(0, 0, 100, 100);
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
	// mainView.setWidth(glutGet(GLUT_WINDOW_WIDTH));
	// mainView.setHeight(glutGet(GLUT_WINDOW_HEIGHT));
	cout << "sizes set\n";
	// mainView.setX(glutGet(GLUT_WINDOW_WIDTH) / 2);
	// mainView.setY(glutGet(GLUT_WINDOW_HEIGHT) / 2);
	cout << "coords set\n";
}



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




int __glArg__;
void _visualFunc()
{
	cout << "glut init\n";
	glutInit(&__glArg__, 0);
	cout << "dispmode\n";
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	cout << "windowssize\n";
	//glutInitWindowSize(800, 600);
	glutCreateWindow("glWindowStandartWindow");
	glutFullScreen();
	// cout << "mouse\n";
	// glutMouseFunc(_mouseClick);
	cout << "reshape\n";
	glutReshapeFunc(_reshape);
	cout << "dispfunc\n";
    glutDisplayFunc(mainDraw);
	// cout << "keypress\n";
	// glutKeyboardFunc(_handleKeypress);
	//glutIdleFunc(display);
	cout << "timer\n";
	glutTimerFunc(40, _timf, 0);
	// mainView.setDrawFunc(mainDraw);
	cout << "mainloop\n";
	glutMainLoop();
}

void glInit(int arg)
{
	__glArg__ = arg;
	std::thread thready(_visualFunc);
	thready.detach();
}
