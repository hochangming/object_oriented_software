#include <array>
#include <iostream>
#include <string>
#include "RegularPolygon.h"
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
		using actual_type1 = typename cs225::RegularPolygon<type1>::type;

		using expected_type2 = double;
		using type2 = typename cs225::Vector2D<expected_type2>;
		using actual_type2 = typename cs225::RegularPolygon<type2>::type;

		if constexpr ((!std::is_same<actual_type1, expected_type1>::value) ||
			(!std::is_same<actual_type2, expected_type2>::value))
		{
			throw std::string{"Dependent type does not match!"};
		}
	}

	void test2()
	{
		const cs225::RegularPolygon<vector> regularPolygon{
			{50, 100, 150},
			{1, 0},
			{2, 0},
			4
		};
		if ((regularPolygon.x() != 1) || (regularPolygon.y() != 0))
		{
			throw std::string{"Constructor with position has failed."};
		}
	}

	void test3()
	{
		const cs225::RegularPolygon<vector> regularPolygon{
			{50, 100, 150},
			{1, 0},
			{2, 0},
			4
		};
		if ((regularPolygon.pivot().x() != 1) || (regularPolygon.pivot().y() != 0))
		{
			throw std::string{"Getter for pivot has failed."};
		}
	}

	void test4()
	{
		const cs225::RegularPolygon<vector> regularPolygon{
			{50, 100, 150},
			{1, 0},
			{2, 0},
			4
		};
		if ((regularPolygon.color().red() != 50) ||
			(regularPolygon.color().green() != 100) ||
			(regularPolygon.color().blue() != 150))
		{
			throw std::string{"Getter for color has failed."};
		}
	}

	void test5()
	{
		const cs225::RegularPolygon<vector> regularPolygon{
			{50, 100, 150},
			{1, 0},
			{2, 0},
			4
		};
		const cs225::IColoredShape<vector>& shape = regularPolygon;
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
		cs225::RegularPolygon<vector> regularPolygon{
			{50, 100, 150},
			{1, 0},
			{2, 0},
			4
		};
		cs225::ITranslatable<vector>& translatable = regularPolygon;
		translatable.translate({100, 200});
		if ((regularPolygon.x() != 101) || (regularPolygon.y() != 200))
		{
			throw std::string{"Realization of ITranslatable has failed."};
		}
	}

	void test7()
	{
		const cs225::RegularPolygon<vector> regularPolygon{
			{50, 100, 150},
			{1, 0},
			{2, 0},
			4
		};
		const cs225::Point<vector>& point = regularPolygon;
		if ((point.x() != 1) || (point.y() != 0))
		{
			throw std::string{"Base class reference failed."};
		}
	}

	void test8()
	{
		const cs225::RegularPolygon<vector> regularPolygon{
			{50, 100, 150},
			{1, 0},
			{2, 0},
			4
		};
		const cs225::Polygon<vector>& polygon = regularPolygon;
		if ((polygon.x() != 1) || (polygon.y() != 0))
		{
			throw std::string{"Base class reference failed."};
		}
	}

	void test9()
	{
		cs225::RegularPolygon<vector> regularPolygon{
			{50, 100, 150},
			{1, 0},
			{2, 0},
			4
		};
		cs225::IRotatable& rotatable = regularPolygon;
		rotatable.rotate(PI<float> / 2.0f);
		const vector* pts = regularPolygon.points();
		if ((regularPolygon.size() != 4) ||
			(pts[0].x() != 1) || (pts[0].y() != 1) ||
			(pts[1].x() != 0) || (pts[1].y() != 0) ||
			(pts[2].x() != 1) || (pts[2].y() != -1) ||
			(pts[3].x() != 2) || (pts[3].y() != 0))
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
