#include <iostream>
#include <string>
#include <sstream>
#include "Vector2D.h"

namespace
{
#include "Test.h"

	using vector = cs225::Vector2D<int>;

	void test1()
	{
		using expected_type1 = float;
		using actual_type1 = typename cs225::Vector2D<expected_type1>::type;

		using expected_type2 = double;
		using actual_type2 = typename cs225::Vector2D<expected_type2>::type;

		if constexpr ((!std::is_same<actual_type1, expected_type1>::value) ||
			(!std::is_same<actual_type2, expected_type2>::value))
		{
			throw std::string{"Dependent type does not match!"};
		}
	}

	void test2()
	{
		const vector v1;
		if ((v1.x() != 0) || (v1.y() != 0))
		{
			throw std::string{"Default constructor has failed!"};
		}
	}

	void test3()
	{
		const vector v1{1, 2};
		if ((v1.x() != 1) || (v1.y() != 2))
		{
			throw std::string{"User-defined constructor has failed!"};
		}
	}

	void test4()
	{
		const cs225::Vector2D<int> v1{3, 4};
		const cs225::Vector2D<int> v2 = v1;
		if ((v2.x() != 3) || (v2.y() != 4))
		{
			throw std::string{"Synthesized copy constructor has failed!"};
		}
	}

	void test5()
	{
		vector v1{5, 6}, v2;
		v2 = v1;
		if ((v2.x() != 5) || (v2.y() != 6))
		{
			throw std::string{"Synthesized copy assignment has failed!"};
		}
	}

	void test6()
	{
		vector v1{7, 8};
		v1.x(1);
		if ((v1.x() != 1) || (v1.y() != 8))
		{
			std::cout << v1.x() << std::endl;
			throw std::string{"Setter for x has failed."};
		}
	}

	void test7()
	{
		vector v1{7, 8};
		v1.y(1);
		if ((v1.x() != 7) || (v1.y() != 1))
		{
			std::cout << v1.y() << std::endl;
			throw std::string{"Setter for y has failed."};
		}
	}

	void test8()
	{
		vector v1{1, 2}, v2{3, 4};
		v1 = v1 + v2;
		if ((v1.x() != 4) || (v1.y() != 6))
		{
			throw std::string{"Operator + has failed."};
		}
	}

	void test9()
	{
		vector v1{4, 3}, v2{2, 1};
		v1 += v2;
		if ((v1.x() != 6) || (v1.y() != 4))
		{
			throw std::string{"Operator += has failed."};
		}
	}

	void test10()
	{
		vector v1{1, 2}, v2{3, 4};
		v1 = v1 - v2;
		if ((v1.x() != -2) || (v1.y() != -2))
		{
			throw std::string{"Operator + has failed."};
		}
	}

	void test11()
	{
		vector v1{4, 3}, v2{2, 1};
		v1 -= v2;
		if ((v1.x() != 2) || (v1.y() != 2))
		{
			throw std::string{"Operator += has failed."};
		}
	}

	void test12()
	{
		cs225::Vector2D<int> v1{123, 456};
		std::stringstream ss;
		ss << v1;
		if (ss.str() != "123,456")
		{
			throw std::string{"Operator << has failed."};
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
		test9,
		test10,
		test11,
		test12
	};

	std::cout << __FILE__ << std::endl;
	std::size_t test_index = 0;
	for (std::size_t i = 0; i < sizeof(tests) / sizeof(*tests); ++i)
	{
		run(test_index, tests[i]);
	}
}
