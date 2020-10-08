#include "Color.h"

namespace cs225
{
	Color::Color(type red, type green, type blue) :
		_red{red},
		_green{green},
		_blue{blue}
	{
	}

	Color::type Color::red() const
	{
		return _red;
	}

	Color::type Color::green() const
	{
		return _green;
	}

	Color::type Color::blue() const
	{
		return _blue;
	}
}
