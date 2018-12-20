
#include "Image2D.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

namespace resource
{
	bool Image2D::Load()
	{

		if(_loaded)
			return false;
		unsigned char * data = stbi_load(_file_name.c_str(), &_width, &_height, &_channels, 0);
		if (data == nullptr || _width + _height == 0)
			return false;
		_data = data;
		_loaded = true;
		return true;
	}

	void Image2D::Release()
	{
		if(_loaded)
			stbi_image_free(_data);
	}
}