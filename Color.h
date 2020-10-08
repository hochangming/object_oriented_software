#ifndef _COLOR_H_
#define _COLOR_H_

namespace cs225
{
	class Color
	{
	public:
		using type = unsigned char;

		Color(type red, type green, type blue);

		type red() const;
		type green() const;
		type blue() const;

	private:
		type _red;
		type _green;
		type _blue;
	};
}

#endif
