#include <string>
// #include <wstring>

using namespace std;

FTGLPixmapFont hack_italic_font("/usr/share/fonts/TTF/Hack-Italic.ttf");


void drawRect(float x, float y, float a, float b)
{
	x -= a / 2;
	y -= b / 2;
	glBegin(GL_QUADS);
	glVertex2d(x, y);
	glVertex2d(x, y + b);
	glVertex2d(x + a, y + b);
	glVertex2d(x + a, y);
	glEnd();
}

void drawQuad(float x, float y, float a)
{
	drawRect(x, y, a, a);
}


void drawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void drawCircleFilled(float cx, float cy, float r, int numSegments)
{
	glBegin(GL_POLYGON);
    for(int ii = 0; ii < numSegments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(numSegments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}

void drawOct(float x, float y, float a)
{
	float alpha = 22.35;

	glBegin(GL_POLYGON);
	glVertex2d(x + a * sin(alpha), y + a * cos(alpha));
	glVertex2d(x - a * sin(alpha), y + a * cos(alpha));
	glVertex2d(x - a * cos(alpha), y + a * sin(alpha));
	glVertex2d(x - a * cos(alpha), y - a * sin(alpha));
	glVertex2d(x - a * sin(alpha), y - a * cos(alpha));
	glVertex2d(x + a * sin(alpha), y - a * cos(alpha));
	glVertex2d(x + a * cos(alpha), y - a * sin(alpha));
	glVertex2d(x + a * cos(alpha), y + a * sin(alpha));
	glEnd();
}


void drawTriangle(float x, float y, float a)
{
	glBegin(GL_TRIANGLES);
	glVertex2d(x, y);
	glVertex2d(x + a, y);
	glVertex2d(x + (a / 2), y + a);
	glEnd();
}


void drawImage(struct myImage image, float scale)
{
	glBegin(GL_POINTS);
	for(int y = 0; y < image.height; y++)
	{
		png_bytep row = image.row_pointers[y];
		for(int x = 0; x < image.width; x++)
		{
			png_bytep px = &(row[x * 4]);
			if(px[3] != 0)
			{
				glColor4f((float)px[0]/255, (float)px[1]/255, (float)px[2]/255, (float)px[3]/255);
				glVertex2d(((float)x) * scale, ((float)image.height - (float)y) * scale);
			}
		}
	}
	glEnd();//*/
}

void drawImage(struct myImage image)
{
	drawImage(image, 1);
}

void drawText(wstring text, int size, int x, int y)
{
	if(!hack_italic_font.Error())
	{
		glPushMatrix();
		//const wchar_t * tarr = (wchar_t*)malloc(text.length());
		//wstrcpy(tarr, text);
		hack_italic_font.FaceSize(size);
		glRasterPos2f(x, y);//TODO: refactor
		hack_italic_font.Render(text.c_str());
		glPopMatrix();
	}
	else
	{
		cout << "FONT ERR\n";
	}
}
