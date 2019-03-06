
void drawBitmapText18(std::string str, float x, float y)
{
	glRasterPos2f(x - (str.length() * 1.8 * 2), y);
	for(int i = 0; i < str.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
	}
}
void drawBitmapText18(char *str, float x, float y) 
{
	drawBitmapText18(std::string(str), x, y);
}

void drawBitmapText10(std::string str, float x, float y)
{
	glRasterPos2f(x - (str.length() * 2), y);
	for(int i = 0; i < str.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, str[i]);
	}
}
void drawBitmapText10(char *str, float x, float y) 
{
	drawBitmapText10(std::string(str), x, y);
}

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


void drawArrow(float x, float y, int dir)
{
	switch(dir)
	{
		case DIRECTION_DOWN:
			y += (ARROW_LEN / 2);
			glBegin(GL_LINES);
			glLineWidth(5);
			glVertex2d(x, y);
			glVertex2d(x, y - ARROW_LEN);
			
			glVertex2d(x, y - ARROW_LEN);
			glVertex2d(x + ARROW_LEN / 2, y - ARROW_LEN / 2);
			
			glVertex2d(x, y - ARROW_LEN);
			glVertex2d(x - ARROW_LEN / 2, y - ARROW_LEN / 2);
			glEnd();
			break;
		case DIRECTION_UP:
			y -= (ARROW_LEN / 2);
			glBegin(GL_LINES);
			glLineWidth(5);
			glVertex2d(x, y);
			glVertex2d(x, y + ARROW_LEN);
			
			glVertex2d(x, y + ARROW_LEN);
			glVertex2d(x + ARROW_LEN / 2, y + ARROW_LEN / 2);
			
			glVertex2d(x, y + ARROW_LEN);
			glVertex2d(x - ARROW_LEN / 2, y + ARROW_LEN / 2);
			glEnd();
			break;
		case DIRECTION_RIGHT:
			x -= (ARROW_LEN / 2);
			glBegin(GL_LINES);
			glLineWidth(5);
			glVertex2d(x, y);
			glVertex2d(x + ARROW_LEN, y);
			
			glVertex2d(x + ARROW_LEN, y);
			glVertex2d(x + ARROW_LEN / 2, y + ARROW_LEN / 2);
			
			glVertex2d(x + ARROW_LEN, y);
			glVertex2d(x + ARROW_LEN / 2, y - ARROW_LEN / 2);
			glEnd();
			break;
		case DIRECTION_LEFT:
			x += (ARROW_LEN / 2);
			glBegin(GL_LINES);
			glLineWidth(5);
			glVertex2d(x, y);
			glVertex2d(x - ARROW_LEN, y);
			
			glVertex2d(x - ARROW_LEN, y);
			glVertex2d(x - ARROW_LEN / 2, y + ARROW_LEN / 2);
			
			glVertex2d(x - ARROW_LEN, y);
			glVertex2d(x - ARROW_LEN / 2, y - ARROW_LEN / 2);
			glEnd();
			break;
		case DIRECTION_UP_RIGHT:
			x -= (ARROW_LEN / 2);
			y -= ARROW_LEN / 2;
			glBegin(GL_LINES);
			glVertex2d(x, y);
			glVertex2d(x + ARROW_LEN, y + ARROW_LEN);
			glVertex2d(x + ARROW_LEN, y + ARROW_LEN);
			glVertex2d(x + ARROW_LEN, y + (ARROW_LEN / 2));
			glVertex2d(x + ARROW_LEN, y + ARROW_LEN);
			glVertex2d(x + (ARROW_LEN / 2), y + ARROW_LEN);
			glEnd();
			break;
		case DIRECTION_DOWN_RIGHT:
			x -= ARROW_LEN / 2;
			y += ARROW_LEN / 2;
			glBegin(GL_LINES);
			glVertex2d(x, y);
			glVertex2d(x + ARROW_LEN, y - ARROW_LEN);
			glVertex2d(x + ARROW_LEN, y - ARROW_LEN);
			glVertex2d(x + ARROW_LEN, y - (ARROW_LEN / 2));
			glVertex2d(x + ARROW_LEN, y - ARROW_LEN);
			glVertex2d(x + ARROW_LEN / 2, y - ARROW_LEN);
			glEnd();
			break;
		case DIRECTION_DOWN_LEFT:
			x += ARROW_LEN / 2;
			y += ARROW_LEN / 2;
			glBegin(GL_LINES);
			glVertex2d(x, y);
			glVertex2d(x - ARROW_LEN, y - ARROW_LEN);
			glVertex2d(x - ARROW_LEN, y - ARROW_LEN);
			glVertex2d(x - ARROW_LEN, y - (ARROW_LEN / 2));
			glVertex2d(x - ARROW_LEN, y - ARROW_LEN);
			glVertex2d(x - ARROW_LEN / 2, y - ARROW_LEN);
			glEnd();
			break;
		case DIRECTION_UP_LEFT:
			x += ARROW_LEN / 2;
			y -= ARROW_LEN / 2;
			glBegin(GL_LINES);
			glVertex2d(x, y);
			glVertex2d(x - ARROW_LEN, y + ARROW_LEN);
			glVertex2d(x - ARROW_LEN, y + ARROW_LEN);
			glVertex2d(x - ARROW_LEN, y + (ARROW_LEN / 2));
			glVertex2d(x - ARROW_LEN, y + ARROW_LEN);
			glVertex2d(x - ARROW_LEN / 2, y + ARROW_LEN);
			glEnd();
			break;
		default:
			drawArrow(x, y, DIRECTION_DOWN);
			drawArrow(x, y, DIRECTION_UP);
			drawArrow(x, y, DIRECTION_LEFT);
			drawArrow(x, y, DIRECTION_RIGHT);
			drawArrow(x, y, DIRECTION_UP_RIGHT);
			drawArrow(x, y, DIRECTION_UP_LEFT);
			drawArrow(x, y, DIRECTION_DOWN_LEFT);
			drawArrow(x, y, DIRECTION_DOWN_RIGHT);//*/
			break;
	}
}

void drawTriangle(float x, float y, float a)
{
	glBegin(GL_TRIANGLES);
	glVertex2d(x, y);
	glVertex2d(x + a, y);
	glVertex2d(x + (a / 2), y + a);
	glEnd();
}



void drawBWBorderred(int h, int w, png_bytep *_row_pointers, float scale, int delta)
{
	glBegin(GL_POINTS);
	glColor3f(1,1,1);
	for(int y = 0; y < h; y++) 
	{
		png_bytep row = _row_pointers[y];
		for(int x = 0; x < w; x++) 
		{
		  png_bytep px = &(row[x * 4]);
		  if(px[0] < 200 || px[1] < 200 || px[1] < 200)
		  {
			  //glColor4ffloat)px[0]/255, (float)px[1]/255, (float)px[2]/255, (float)px[3]/255);
			  glVertex2d(((float)x      )*scale, ((float)h-(float)y        )*scale);
			  glVertex2d(((float)x+delta)*scale, ((float)h-(float)y        )*scale);
			  glVertex2d(((float)x-delta)*scale, ((float)h-(float)y        )*scale);
			  glVertex2d(((float)x      )*scale, ((float)h-(float)(y+delta))*scale);
			  glVertex2d(((float)x      )*scale, ((float)h-(float)(y-delta))*scale);
			  glVertex2d(((float)x+delta)*scale, ((float)h-(float)(y-delta))*scale);
			  glVertex2d(((float)x-delta)*scale, ((float)h-(float)(y-delta))*scale);
			  glVertex2d(((float)x-delta)*scale, ((float)h-(float)(y+delta))*scale);
			  glVertex2d(((float)x+delta)*scale, ((float)h-(float)(y+delta))*scale);
		  }
		}
	}
	glColor3f(0,0,0);
	for(int y = 0; y < h; y++) 
	{
		png_bytep row = _row_pointers[y];
		for(int x = 0; x < w; x++) 
		{
		  png_bytep px = &(row[x * 4]);
		  if(px[0] < 200 || px[1] < 200 || px[1] < 200)
		  {
			  //glColor4f((float)px[0]/255, (float)px[1]/255, (float)px[2]/255, (float)px[3]/255);
			  glVertex2d(((float)x)*scale, ((float)h - (float)y)*scale);
		  }
		}
	}
	glEnd();
}

void drawBWBorderred(struct myImage image, float scale, int delta)
{
	drawBWBorderred(image.height, image.width, image.row_pointers, scale, delta);
}

void drawBWBorderred(float x, float y, int h, int w, png_bytep *_row_pointers, float scale, int delta)
{
	glPushMatrix();
		glTranslatef(x, y, 0);
		drawBWBorderred(h, w, _row_pointers, scale, delta);
	glPopMatrix();
}


void drawImage(struct myImage image, float scale)
{
	//glDrawPixels(image.width, image.height, GL_RGBA, GL_UNSIGNED_BYTE, image.row_pointers);
	
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
