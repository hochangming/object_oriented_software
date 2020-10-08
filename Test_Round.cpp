#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include "Round.h"

namespace
{
#include "Test.h"

	void test1()
	{
		using source_type = int;
		using target_type = float;

		source_type data[] = {
			static_cast<source_type>(1),
			static_cast<source_type>(1),
			static_cast<source_type>(3)
		};
		target_type sum{};
		for (std::size_t i = 0; i < sizeof(data) / sizeof(*data); ++i)
		{
			sum += static_cast<target_type>(data[i]);
		}
		if (static_cast<int>(std::round(static_cast<source_type>(sum / 3.0f))) != 1)
		{
			throw std::string{"Static cast from float to int does not work for positive values."};
		}
	}

	void test2()
	{
		using source_type = int;
		using target_type = float;

		source_type data[] = {
			static_cast<source_type>(-1),
			static_cast<source_type>(-1),
			static_cast<source_type>(-3)
		};
		target_type sum{};
		for (std::size_t i = 0; i < sizeof(data) / sizeof(*data); ++i)
		{
			sum += static_cast<target_type>(data[i]);
		}
		if (static_cast<int>(std::round(static_cast<source_type>(sum / 3.0f))) != -1)
		{
			throw std::string{"Static cast from float to int does not work for negative values."};
		}
	}

	void test3()
	{
		using source_type = float;
		using target_type = float;

		source_type data[] = {
			static_cast<source_type>(1),
			static_cast<source_type>(1),
			static_cast<source_type>(3)
		};
		target_type sum{};
		for (std::size_t i = 0; i < sizeof(data) / sizeof(*data); ++i)
		{
			sum += static_cast<target_type>(data[i]);
		}
		if (static_cast<int>(std::round(static_cast<source_type>(sum / 3.0f))) != 2)
		{
			throw std::string{"Static cast from float to float does not work for positive values."};
		}
	}

	void test4()
	{
		using source_type = float;
		using target_type = float;

		source_type data[] = {
			static_cast<source_type>(-1),
			static_cast<source_type>(-1),
			static_cast<source_type>(-3)
		};
		target_type sum{};
		for (std::size_t i = 0; i < sizeof(data) / sizeof(*data); ++i)
		{
			sum += static_cast<target_type>(data[i]);
		}
		if (static_cast<int>(std::round(static_cast<source_type>(sum / 3.0f))) != -2)
		{
			throw std::string{"Static cast from float to float does not work for negative values."};
		}
	}

	void test5()
	{
		using source_type = int;
		using target_type = float;

		source_type data[] = {
			static_cast<source_type>(0),
			static_cast<source_type>(0),
			static_cast<source_type>(0)
		};
		target_type sum{};
		for (std::size_t i = 0; i < sizeof(data) / sizeof(*data); ++i)
		{
			sum += static_cast<target_type>(data[i]);
		}
		if (static_cast<int>(std::round(static_cast<source_type>(sum / 3.0f))) != 0)
		{
			throw std::string{"Static cast from float to int does not work for zero."};
		}
	}

	void test6()
	{
		using source_type = float;
		using target_type = float;

		source_type data[] = {
			static_cast<source_type>(0),
			static_cast<source_type>(0),
			static_cast<source_type>(0)
		};
		target_type sum{};
		for (std::size_t i = 0; i < sizeof(data) / sizeof(*data); ++i)
		{
			sum += static_cast<target_type>(data[i]);
		}
		if (static_cast<int>(std::round(static_cast<source_type>(sum / 3.0f))) != 0)
		{
			throw std::string{"Static cast from float to float does not work for zero."};
		}
	}

	void test7()
	{
		using source_type = int;
		using target_type = float;

		source_type data[] = {
			static_cast<source_type>(1),
			static_cast<source_type>(1),
			static_cast<source_type>(3)
		};
		target_type sum{};
		for (std::size_t i = 0; i < sizeof(data) / sizeof(*data); ++i)
		{
			sum += cs225::round<target_type>(data[i]);
		}
		if (static_cast<int>(std::round(cs225::round<source_type>(sum / 3.0f))) != 2)
		{
			throw std::string{"Operation round from float to int does not work for positive values."};
		}
	}

	void test8()
	{
		using source_type = int;
		using target_type = float;

		source_type data[] = {
			static_cast<source_type>(-1),
			static_cast<source_type>(-1),
			static_cast<source_type>(-3)
		};
		target_type sum{};
		for (std::size_t i = 0; i < sizeof(data) / sizeof(*data); ++i)
		{
			sum += cs225::round<target_type>(data[i]);
		}
		if (static_cast<int>(std::round(cs225::round<source_type>(sum / 3.0f))) != -2)
		{
			throw std::string{"Operation round from float to int does not work for negative values."};
		}
	}

	void test9()
	{
		using source_type = float;
		using target_type = float;

		source_type data[] = {
			static_cast<source_type>(1),
			static_cast<source_type>(1),
			static_cast<source_type>(3)
		};
		target_type sum{};
		for (std::size_t i = 0; i < sizeof(data) / sizeof(*data); ++i)
		{
			sum += cs225::round<target_type>(data[i]);
		}
		if (static_cast<int>(std::round(cs225::round<source_type>(sum / 3.0f))) != 2)
		{
			throw std::string{"Operation round from float to float does not work for positive values."};
		}
	}

	void test10()
	{
		using source_type = float;
		using target_type = float;

		source_type data[] = {
			static_cast<source_type>(-1),
			static_cast<source_type>(-1),
			static_cast<source_type>(-3)
		};
		target_type sum{};
		for (std::size_t i = 0; i < sizeof(data) / sizeof(*data); ++i)
		{
			sum += cs225::round<target_type>(data[i]);
		}
		if (static_cast<int>(std::round(cs225::round<source_type>(sum / 3.0f))) != -2)
		{
			throw std::string{"Operation round from float to float does not work for negative values."};
		}
	}

	void test11()
	{
		using source_type = int;
		using target_type = float;

		source_type data[] = {
			static_cast<source_type>(0),
			static_cast<source_type>(0),
			static_cast<source_type>(0)
		};
		target_type sum{};
		for (std::size_t i = 0; i < sizeof(data) / sizeof(*data); ++i)
		{
			sum += static_cast<target_type>(data[i]);
		}
		if (static_cast<int>(std::round(cs225::round<source_type>(sum / 3.0f))) != 0)
		{
			throw std::string{"Static cast from float to int does not work for zero."};
		}
	}

	void test12()
	{
		using source_type = float;
		using target_type = float;

		source_type data[] = {
			static_cast<source_type>(0),
			static_cast<source_type>(0),
			static_cast<source_type>(0)
		};
		target_type sum{};
		for (std::size_t i = 0; i < sizeof(data) / sizeof(*data); ++i)
		{
			sum += static_cast<target_type>(data[i]);
		}
		if (static_cast<int>(std::round(cs225::round<source_type>(sum / 3.0f))) != 0)
		{
			throw std::string{"Static cast from float to float does not work for zero."};
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
