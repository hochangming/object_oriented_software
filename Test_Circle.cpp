#include <iostream>
#include <string>
#include "Circle.h"
#include "Vector2D.h"

namespace
{
#include "Test.h"

	using vector = cs225::Vector2D<int>;

	void test1()
	{
		using expected_type1 = float;
		using type1 = typename cs225::Vector2D<expected_type1>;
		using actual_type1 = typename cs225::Circle<type1>::type;

		using expected_type2 = double;
		using type2 = typename cs225::Vector2D<expected_type2>;
		using actual_type2 = typename cs225::Circle<type2>::type;

		if constexpr ((!std::is_same<actual_type1, expected_type1>::value) ||
			(!std::is_same<actual_type2, expected_type2>::value))
		{
			throw std::string{"Dependent type does not match!"};
		}
	}

	void test2()
	{
		const cs225::Circle<vector> circle{
			{50, 100, 150},
			{200, 250},
			1000
		};
		if ((circle.x() != 200) || (circle.y() != 250))
		{
			throw std::string{"Constructor with position has failed."};
		}
	}

	void test3()
	{
		const cs225::Circle<vector> circle{
			{50, 100, 150},
			{200, 250},
			1000
		};
		if ((circle.pivot().x() != 200) || (circle.pivot().y() != 250))
		{
			throw std::string{"Getter for pivot has failed."};
		}
	}

	void test4()
	{
		const cs225::Circle<vector> circle{
			{50, 100, 150},
			{200, 250},
			1000
		};
		if ((circle.color().red() != 50) ||
			(circle.color().green() != 100) ||
			(circle.color().blue() != 150))
		{
			throw std::string{"Getter for color has failed."};
		}
	}

	void test5()
	{
		const cs225::Circle<vector> circle{
			{50, 100, 150},
			{200, 250},
			1000
		};
		const cs225::IColoredShape<vector>& shape = circle;
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
		cs225::Circle<vector> circle{
			{50, 100, 150},
			{200, 250},
			1000
		};
		cs225::ITranslatable<vector>& translatable = circle;
		translatable.translate({100, 200});
		if ((circle.x() != 300) || (circle.y() != 450))
		{
			throw std::string{"Realization of ITranslatable has failed."};
		}
	}

	void test7()
	{
		const cs225::Circle<vector> circle{
			{50, 100, 150},
			{200, 250},
			1000
		};
		if (circle.radius() != 1000)
		{
			throw std::string{"Getter for radius has failed."};
		}
	}

	void test8()
	{
		const cs225::Circle<vector> circle{
			{50, 100, 150},
			{200, 250},
			1000
		};
		const cs225::Point<vector>& point = circle;
		if ((point.x() != 200) || (point.y() != 250))
		{
			throw std::string{"Base class reference failed."};
		}
	}

	void test9()
	{
		cs225::Circle<vector> circle{
			{50, 100, 150},
			{200, 250},
			1000
		};
		cs225::IScalable& scalable = circle;
		scalable.scale(2);
		if (circle.radius() != 2000)
		{
			throw std::string{"Realization of IScalable has failed."};
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
