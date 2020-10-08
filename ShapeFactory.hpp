/******************************************************************************/
/*!
\file   ShapeFactory.hpp
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the templated class ShapeFactory
and declarations of its member functions.


Functions included:
create					- A function for shape objects creation

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/
#include "ShapeFactory.h"

namespace cs225
{
/******************************************************************************/
/*!
	\brief
	A create function to create objects of shapes

	\param index
	to determine the shape to construct

*/
/******************************************************************************/
	template<typename T>
	IShape<T>* ShapeFactory<T>::create(const size_t index)
	{
		switch (index)
		{
		case 0:
			size_t width;
			size_t height;

			BitmapCanvas<T>::load(
				"Logo.bmp",
				width,
				height,
				colors_
			);
			return new Background<T>{
				static_cast<typename Background<T>
				::pixelCount>(height),
				static_cast<typename Background<T>
				::pixelCount>(width), 
				colors_.data() };

		case 1: return new Circle<T>{ Color{ 0, 200, 0 },
				{ 100, 150 }, 15 };
		case 2: return new Point<T>{ { 100, 0, 0 }, { 95, 150 } };
		case 3: return new Point<T>{ { 100, 0, 0 }, { 105, 150 } };
		case 4: return new RegularPolygon<T>(Color
				{ 200, 0, 200 }, { 100, 50 }, { 110, 50 }, 6);
		case 5: arr = { T{100,135}, T{70,115},T{130,115} };
				return new Triangle<T>(Color{ 200,200, 0 }
				, arr);
		case 6: arr1 = { T{85, 115}, T{90, 60},T{100, 50},
				T{110, 60}, T{115, 115} };
				return new Polygon<T>(Color{ 0, 200, 200 },
				arr1.size(), arr1.data());
		default: throw std::string{ "Not supported!" };
		}

	}
}
