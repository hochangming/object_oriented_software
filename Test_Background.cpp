#include <iostream>
#include <string>
#include <array>
#include "Background.h"
#include "Vector2D.h"

namespace
{
#include "Test.h"

	using vector = cs225::Vector2D<int>;

	void test1()
	{
		using pixelCount = typename cs225::Background<vector>::pixelCount;
		const pixelCount width = 2;
		const pixelCount height = 1;
		const std::array<cs225::Color, width * height> colors = {
			cs225::Color{0, 0, 0},
			cs225::Color{255, 255, 255}
		};
		const cs225::Background<vector> background{width, height, colors.data()};
		if ((background.width() != 2) || (background.height() != 1))
		{
			throw std::string{"Constructor with dimensions has failed."};
		}
	}

	void test2()
	{
		using pixelCount = typename cs225::Background<vector>::pixelCount;
		const pixelCount width = 2;
		const pixelCount height = 1;
		const std::array<cs225::Color, width * height> colors = {
			cs225::Color{1, 2, 3},
			cs225::Color{4, 5, 6}
		};
		const cs225::Background<vector> background{
			width,
			height,
			colors.data()
		};
		const cs225::Color* const colorData = background.colorData();
		if ((colorData[0].red() != 1) ||
			(colorData[0].green() != 2) ||
			(colorData[0].blue() != 3) ||
			(colorData[1].red() != 4) ||
			(colorData[1].green() != 5) ||
			(colorData[1].blue() != 6)
			)
		{
			throw std::string{"Constructor with colors has failed."};
		}
	}
}

int main()
{
	const Test tests[] = {
		test1,
		test2
	};

	std::cout << __FILE__ << std::endl;
	std::size_t test_index = 0;
	for (std::size_t i = 0; i < sizeof(tests) / sizeof(*tests); ++i)
	{
		run(test_index, tests[i]);
	}
}
