#include <iostream>
#include <string>
#include "Point.h"
#include "Vector2D.h"

namespace
{
#include "Test.h"

	using vector = cs225::Vector2D<int>;

	void test1()
	{
		using expected_type1 = float;
		using type1 = typename cs225::Vector2D<expected_type1>;
		using actual_type1 = typename cs225::Point<type1>::type;

		using expected_type2 = double;
		using type2 = typename cs225::Vector2D<expected_type2>;
		using actual_type2 = typename cs225::Point<type2>::type;

		if constexpr ((!std::is_same<actual_type1, expected_type1>::value) ||
			(!std::is_same<actual_type2, expected_type2>::value))
		{
			throw std::string{"Dependent type does not match!"};
		}
	}

	void test2()
	{
		const cs225::Point<vector> point{
			{50, 100, 150},
			{200, 250}
		};
		if ((point.x() != 200) || (point.y() != 250))
		{
			throw std::string{"Constructor with position has failed."};
		}
	}

	void test3()
	{
		const cs225::Point<vector> point{
			{50, 100, 150},
			{200, 250}
		};
		if ((point.pivot().x() != 200) || (point.pivot().y() != 250))
		{
			throw std::string{"Getter for pivot has failed."};
		}
	}

	void test4()
	{
		const cs225::Point<vector> point{
			{50, 100, 150},
			{200, 250}
		};
		if ((point.color().red() != 50) ||
			(point.color().green() != 100) ||
			(point.color().blue() != 150))
		{
			throw std::string{"Getter for color has failed."};
		}
	}

	void test5()
	{
		const cs225::Point<vector> point{
			{50, 100, 150},
			{200, 250}
		};
		const cs225::IColoredShape<vector>& shape = point;
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
		cs225::Point<vector> point{
			{50, 100, 150},
			{200, 250}
		};
		cs225::ITranslatable<vector>& translatable = point;
		translatable.translate({100, 200});
		if ((point.x() != 300) || (point.y() != 450))
		{
			throw std::string{"Realization of ITranslatable has failed."};
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
		test6
	};

	std::cout << __FILE__ << std::endl;
	std::size_t test_index = 0;
	for (std::size_t i = 0; i < sizeof(tests) / sizeof(*tests); ++i)
	{
		run(test_index, tests[i]);
	}
}
