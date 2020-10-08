#include <vector>
#include <algorithm>

#include "IVisitable.h"
#include "VisitorFactory.h"
#include "ShapeFactory.h"

namespace
{
	#include "Test.h"

	using vector = cs225::Vector2D<int>;

	// Shape types
	using PShape = cs225::IShape<vector>*;

	void testVisitor(std::size_t visitorIndex)
	{
		// Create visitor: visitorIndex
		using VisitorFactory = cs225::VisitorFactory<vector>;
		VisitorFactory visitorFactory;
		using PVisitor = typename VisitorFactory::type;
		std::vector<PVisitor> visitors =
		{
			visitorFactory.create(visitorIndex)
		};

		// Create shapes: 0...6
		using ShapeFactory = cs225::ShapeFactory<vector>;
		ShapeFactory shapeFactory;
		std::vector<PShape> shapes;
		for (std::size_t i = 0; i < 7; ++i)
		{
			shapes.push_back(shapeFactory.create(i));
		}

		// Visit each shape
		for (PVisitor& v : visitors)
		{
			for (PShape& s : shapes)
			{
				using PVisitable = cs225::IVisitable<vector>*;
				using CPVisitable = const PVisitable;
				if (CPVisitable visitable = dynamic_cast<CPVisitable>(s))
				{
					visitable->accept(*v);
				}
			}
		}

		// Destroy shapes
		auto deleter = [](auto s) { delete s; };
		std::for_each(shapes.begin(), shapes.end(), deleter);
		std::for_each(visitors.begin(), visitors.end(), deleter);
	}

	void test1()
	{
		testVisitor(0);
	}

	void test2()
	{
		testVisitor(1);
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
