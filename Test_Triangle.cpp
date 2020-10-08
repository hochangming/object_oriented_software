#include <array>
#include <iostream>
#include <string>
#include "Triangle.h"
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
		using actual_type1 = typename cs225::Triangle<type1>::type;

		using expected_type2 = double;
		using type2 = typename cs225::Vector2D<expected_type2>;
		using actual_type2 = typename cs225::Triangle<type2>::type;

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
		const cs225::Triangle<vector> triangle{
			{50, 100, 150},
			points
		};
		if ((triangle.x() != 5) || (triangle.y() != 8))
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
		const cs225::Triangle<vector> triangle{
			{50, 100, 150},
			points
		};
		if ((triangle.pivot().x() != 5) || (triangle.pivot().y() != 8))
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
		const cs225::Triangle<vector> triangle{
			{50, 100, 150},
			points
		};
		if ((triangle.color().red() != 50) ||
			(triangle.color().green() != 100) ||
			(triangle.color().blue() != 150))
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
		const cs225::Triangle<vector> triangle{
			{50, 100, 150},
			points
		};
		const cs225::IColoredShape<vector>& shape = triangle;
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
		cs225::Triangle<vector> triangle{
			{50, 100, 150},
			points
		};
		cs225::ITranslatable<vector>& translatable = triangle;
		translatable.translate({100, 200});
		if ((triangle.x() != 105) || (triangle.y() != 208))
		{
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
		const cs225::Triangle<vector> triangle{
			{50, 100, 150},
			points
		};
		const cs225::Point<vector>& point = triangle;
		if ((point.x() != 5) || (point.y() != 8))
		{
			throw std::string{"Base class reference failed."};
		}
	}

	void test8()
	{
		std::array<vector, 3> points = {
			vector{5, 4},
			vector{0, 7},
			vector{10, 13}
		};
		const cs225::Triangle<vector> triangle{
			{50, 100, 150},
			points
		};
		const cs225::Polygon<vector>& polygon = triangle;
		if ((polygon.size() != 3) ||
			(polygon.x() != 5) || (polygon.y() != 8))
		{
			throw std::string{"Base class reference failed."};
		}
	}

	void test9()
	{
		const int x = 5;
		const int y = 8;
		std::array<vector, 3> points = {
			vector{x + 0, y - 4},
			vector{x - 5, y - 1},
			vector{x + 5, y + 5}
		};
		cs225::Triangle<vector> triangle{
			{50, 100, 150},
			points
		};
		cs225::IRotatable& rotatable = triangle;
		rotatable.rotate(PI<float> / 2.0f);
		const vector* pts = triangle.points();
		if ((triangle.size() != 3) ||
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
		test8,
		test9
	};

	std::cout << __FILE__ << std::endl;
	std::size_t test_index = 0;
	for (std::size_t i = 0; i < sizeof(tests) / sizeof(*tests); ++i)
	{
		run(test_index, tests[i]);
	}
}
