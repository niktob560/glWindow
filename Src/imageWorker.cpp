
struct myImage read_png_file(char *filename)
{
	myImage image;
	FILE *fp = fopen(filename, "rb");
	//cout << "open\n";
	png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if(!png) abort();

	png_infop info = png_create_info_struct(png);
	if(!info) abort();

	if(setjmp(png_jmpbuf(png))) abort();

	png_init_io(png, fp);
	png_read_info(png, info);

	image.width      = png_get_image_width(png, info);
	image.height     = png_get_image_height(png, info);
	image.color_type = png_get_color_type(png, info);
	image.bit_depth  = png_get_bit_depth(png, info);

  // Read any color_type into 8bit depth, RGBA format.
  // See http://www.libpng.org/pub/png/libpng-manual.txt

	if(image.bit_depth == 16)
		png_set_strip_16(png);

	if(image.color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb(png);

  // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
	if(image.color_type == PNG_COLOR_TYPE_GRAY && image.bit_depth < 8)
		png_set_expand_gray_1_2_4_to_8(png);

	if(png_get_valid(png, info, PNG_INFO_tRNS))
		png_set_tRNS_to_alpha(png);

  // These color_type don't have an alpha channel then fill it with 0xff.
	if(image.color_type == PNG_COLOR_TYPE_RGB ||
		image.color_type == PNG_COLOR_TYPE_GRAY ||
		image.color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

	if(image.color_type == PNG_COLOR_TYPE_GRAY ||
		image.color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
		png_set_gray_to_rgb(png);

	png_read_update_info(png, info);

	image.row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * image.height);
	for(int y = 0; y < image.height; y++)
	{
		image.row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
	}

	png_read_image(png, image.row_pointers);

	fclose(fp);
	return image;
}
