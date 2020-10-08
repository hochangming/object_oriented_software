/******************************************************************************/
/*!
\file   ShapeFactory.h
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
#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include "IShape.h"
#include"Background.h"
#include"Point.h"
#include"Polygon.h"
#include"Circle.h"
#include"Triangle.h"
#include"RegularPolygon.h"
#include"BitmapCanvas.h"

#include<vector>
namespace cs225
{
	template<typename T>
	class ShapeFactory 
	{
	public:
		//create shapes function
		IShape<T>* create(const size_t index);
	private:
		//data members
		std::array<T, 3> arr;
		std::array<T, 5> arr1;
		std::vector<Color>colors_;
  	};
}
#include"ShapeFactory.hpp"
#endif