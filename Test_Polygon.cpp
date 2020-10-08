#include <array>
#include <iostream>
#include <string>
#include "Polygon.h"
#include "Vector2D.h"

namespace
{
#include "Test.h"

	using vector = cs225::Vector2D<int>;

	template <typename T>
	const T PI = std::acos(-T{1});

	void test1()
	{
		using expected_type1 = float;
		using type1 = typename cs225::Vector2D<expected_type1>;
		using actual_type1 = typename cs225::Polygon<type1>::type;

		using expected_type2 = double;
		using type2 = typename cs225::Vector2D<expected_type2>;
		using actual_type2 = typename cs225::Polygon<type2>::type;

		if constexpr ((!std::is_same<actual_type1, expected_type1>::value) ||
			(!std::is_same<actual_type2, expected_type2>::value))
		{
			throw std::string{"Dependent type does not match!"};
		}
	}

	void test2()
	{
		std::array<vector, 3> points = {
			vector{5, 4},
			vector{0, 7},
			vector{10, 13}
		};
		const cs225::Polygon<vector> polygon{
			{50, 100, 150},
			points.size(),
			points.data()
		};
		if ((polygon.x() != 5) || (polygon.y() != 8))
		{
			throw std::string{"Constructor with position has failed."};
		}
	}

	void test3()
	{
		std::array<vector, 3> points = {
			vector{5, 4},
			vector{0, 7},
			vector{10, 13}
		};
		const cs225::Polygon<vector> polygon{
			{50, 100, 150},
			points.size(),
			points.data()
		};
		if ((polygon.pivot().x() != 5) || (polygon.pivot().y() != 8))
		{
			throw std::string{"Getter for pivot has failed."};
		}
	}

	void test4()
	{
		std::array<vector, 3> points = {
			vector{5, 4},
			vector{0, 7},
			vector{10, 13}
		};
		const cs225::Polygon<vector> polygon{
			{50, 100, 150},
			points.size(),
			points.data()
		};
		if ((polygon.color().red() != 50) ||
			(polygon.color().green() != 100) ||
			(polygon.color().blue() != 150))
		{
			throw std::string{"Getter for color has failed."};
		}
	}

	void test5()
	{
		std::array<vector, 3> points = {
			vector{5, 4},
			vector{0, 7},
			vector{10, 13}
		};
		const cs225::Polygon<vector> polygon{
			{50, 100, 150},
			points.size(),
			points.data()
		};
		const cs225::IColoredShape<vector>& shape = polygon;
		const cs225::Color& color = shape.color();
		if ((color.red() != 50) ||
			(color.green() != 100) ||
			(color.blue() != 150))
		{
			throw std::string{"Realization of IColoredShape has failed."};
		}
	}

	void test6()
	{
		std::array<vector, 3> points = {
			vector{5, 4},
			vector{0, 7},
			vector{10, 13}
		};
		cs225::Polygon<vector> polygon{
			{50, 100, 150},
			points.size(),
			points.data()
		};
		cs225::ITranslatable<vector>& translatable = polygon;
		translatable.translate({100, 200});
		if ((polygon.x() != 105) || (polygon.y() != 208))
		{
			std::cout << polygon.x() << std::endl;
			throw std::string{"Realization of ITranslatable has failed."};
		}
	}

	void test7()
	{
		std::array<vector, 3> points = {
			vector{5, 4},
			vector{0, 7},
			vector{10, 13}
		};
		const cs225::Polygon<vector> polygon{
			{50, 100, 150},
			points.size(),
			points.data()
		};
		const cs225::Point<vector>& point = polygon;
		if ((point.x() != 5) || (point.y() != 8))
		{
			throw std::string{"Base class reference failed."};
		}
	}

	void test8()
	{
		const int x = 5;
		const int y = 8;
		std::array<vector, 3> points = {
			vector{x + 0, y - 4},
			vector{x - 5, y - 1},
			vector{x + 5, y + 5}
		};
		cs225::Polygon<vector> polygon{
			{50, 100, 150},
			points.size(),
			points.data()
		};
		cs225::IRotatable& rotatable = polygon;
		rotatable.rotate(PI<float> / 2.0f);
		const vector* pts = polygon.points();
		if ((polygon.size() != 3) ||
			(pts[0].x() != (x + 4)) || (pts[0].y() != (y + 0)) ||
			(pts[1].x() != (x + 1)) || (pts[1].y() != (y - 5)) ||
			(pts[2].x() != (x - 5)) || (pts[2].y() != (y + 5)))
		{
			throw std::string{"Realization of IRotatable has failed."};
		}
	}
}

int main()
{
	const Test tests[] = {
		test1,
		test2,
		test3,
		test4,
		test5,
		test6,
		test7,
		test8
	};

	std::cout << __FILE__ << std::endl;
	std::size_t test_index = 0;
	for (std::size_t i = 0; i < sizeof(tests) / sizeof(*tests); ++i)
	{
		run(test_index, tests[i]);
	}
}
