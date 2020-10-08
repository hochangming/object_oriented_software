#include <array>
#include <vector>
#include <algorithm> // std::for_each

#include "ICloneable.h"
#include "IVisitable.h"
#include "VisitorFactory.h"

#include "Point.h"
#include "Circle.h"
#include "Polygon.h"
#include "RegularPolygon.h"
#include "Triangle.h"

namespace
{ 
	#include "Test.h"

	using vector = cs225::Vector2D<float>;

	// Shape types
	using PShape = cs225::IShape<vector>*;

	using Point = cs225::Point<vector>;
	using PPoint = Point*;

	using Circle = cs225::Circle<vector>;
	using PCircle = Circle*;

	using Polygon = cs225::Polygon<vector>;
	using PPolygon = Polygon*;

	using RegularPolygon = cs225::RegularPolygon<vector>;
	using PRegularPolygon = RegularPolygon*;

	using Triangle = cs225::Triangle<vector>;
	using PTriangle = Triangle*;

	// A functor for transforming individual objects
	struct Transformation
	{
		PShape operator()(PShape shape) const
		{

			using PRotatable = cs225::IRotatable*;
			using PTranslatable = cs225::ITranslatable<vector>*;
			if (PTranslatable t = dynamic_cast<PTranslatable>(shape))
			{
				t->translate({ 0.0f, 50.0f });
			}
			if (PRotatable r = dynamic_cast<PRotatable>(shape))
			{
				r->rotate(0.25f);

			}

			using PScalable = cs225::IScalable*;
			if (PScalable s = dynamic_cast<PScalable>(shape))
			{
				s->scale(0.85f);
			}
			return shape;
		}
	};

	void test1()
	{
		// Create shapes
		const std::size_t polygon_offset = 400;
		std::array<vector, 9> polygon_points = {
			vector{polygon_offset - 15.0f, 65.0f},
			vector{polygon_offset - 15.0f, 35.0f},
			vector{polygon_offset + 15.0f, 35.0f},
			vector{polygon_offset + 15.0f, 40.0f},
			vector{polygon_offset - 10.0f, 40.0f},
			vector{polygon_offset - 10.0f, 60.0f},
			vector{polygon_offset + 15.0f, 60.0f},
			vector{polygon_offset + 15.0f, 65.0f},
			vector{polygon_offset - 15.0f, 65.0f}
		};
		const std::size_t triangle_offset = 500;
		std::array<vector, 3> triangle_points = {
			vector{triangle_offset, 40},
			vector{triangle_offset - 15, 55},
			vector{triangle_offset + 15, 55}
		};
		std::vector<PShape> shapes =
		{
			new Point{
				{200, 0, 0},
				{100, 50}
			},
			new Circle{
				{200, 200, 0},
				{200, 50},
				10
			},
			new RegularPolygon{
				{0, 200, 0},
				{300, 50},
				{315, 50},
				5
			},
			new Polygon{
				{0, 200, 200},
				polygon_points.size(),
				polygon_points.data()
			},
			new Triangle{
				{0, 0, 200},
				triangle_points
			}
		};

		// Transform shapes few times
		Transformation transformation;
		std::size_t iterations = 8;
		const std::size_t initial_shape_count = shapes.size();
		while (iterations--)
		{
			std::size_t index = initial_shape_count;
			const std::size_t shape_count = shapes.size();
			while (index--)
			{
				const PShape& s = shapes[shape_count - index - 1];
				using PCloneable = cs225::ICloneable*;
				using CPCloneable = const PCloneable;
				if (CPCloneable cloneable = dynamic_cast<CPCloneable>(s))
				{
					PCloneable clone = cloneable->clone();
					if (PShape c = dynamic_cast<PShape>(clone))
					{
						shapes.push_back(transformation(c));
					}
					else
					{
						throw std::string{"Cloning must produce a shape!"};
					}
				}
			}
		}

		// Render image
		using VisitorFactory = cs225::VisitorFactory<vector>;
		VisitorFactory visitorFactory;
		using PVisitor = typename VisitorFactory::type;
		PVisitor visitor = visitorFactory.create(2);
		for (const PShape& s : shapes)
		{
			using PVisitable = cs225::IVisitable<vector>*;
			using CPVisitable = const PVisitable;
			if (CPVisitable visitable = dynamic_cast<CPVisitable>(s))
			{
				visitable->accept(*visitor);
			}
		}
		delete visitor;

		// Destroy shapes
		auto deleter = [](auto s) { delete s; };
		std::for_each(shapes.begin(), shapes.end(), deleter);
	}
}

int main()
{
	const Test tests[] = {
		test1
	};

	std::cout << __FILE__ << std::endl;
	std::size_t test_index = 0;
	for (std::size_t i = 0; i < sizeof(tests) / sizeof(*tests); ++i)
	{
		run(test_index, tests[i]);
	}
}
