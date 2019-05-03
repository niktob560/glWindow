struct myImage
{
	int width, height;
	png_byte color_type;
	png_byte bit_depth;
	png_bytep *row_pointers;
};

#define DITECTION				0
#define DIRECTION_UP			1
#define DIRECTION_DOWN			2
#define DIRECTION_RIGHT			3
#define DIRECTION_LEFT			4
#define DIRECTION_UP_RIGHT		5
#define DIRECTION_UP_LEFT		6
#define DIRECTION_DOWN_RIGHT	7
#define DIRECTION_DOWN_LEFT		8


#define ARROW_LEN				10


#define RETURN_CODE_OK			0
#define RETURN_CODE_FAIL		1
#define RETURN_CODE_SIGINT		130
