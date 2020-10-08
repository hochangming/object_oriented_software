/******************************************************************************/
/*!
\file   Circle.hpp
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the templated class Circle
and declarations of its member functions.

Functions included:
Circle					- Conversion constructor
scale					- A width getter function.
radius					- A height getter function.
Color					- A Color getter function to read color from class
clone					- A clone() function used for covariant return types
accept					- An accept visitor function for double dispatching

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/
#include "Circle.h"

namespace cs225
{
/******************************************************************************/
/*!
	\brief
	A Constructor to construct Circle object

	\param color
	A color type object that holds a collection of data colors

	\param pts
	A color Vector2D type object that holds a collection of points

	\param radius
	Int value that holds the radius of circle

*/
/******************************************************************************/
	template<typename T>
	Circle<T>::Circle(const Color& color, const T& pts, float radius) 
			: Point<T>(color, pts), _radius(radius) {}
/******************************************************************************/
/*!
	\brief
	A function for scaling of Points in Circle

	\param factor
	Int value that holds the width of background

*/
/******************************************************************************/
	template<typename T>
	void Circle<T>::scale(float factor)
	{
		_radius *= (factor);
	}
/******************************************************************************/
/*!
	\brief
	A radius getter function

*/
/******************************************************************************/
	template<typename T>
	float Circle<T>::radius() const
	{
		return _radius;
	}
/******************************************************************************/
/*!
	\brief
	A color getter function

*/
/******************************************************************************/
	template<typename T>
	Color Circle<T>::color() const
	{
		return Point<T>::_ncolor;
	}
/******************************************************************************/
/*!
	\brief
	A clone() function used on Circle for creation of prototypes
	A Prototype design pattern that uses covariant return types
*/
/******************************************************************************/
	template <typename T>
	Circle<T>* Circle<T>::clone() const
	{
		return new Circle(*this);
	}
/******************************************************************************/
/*!
	\brief
	An accept visitor function for Circle used for double dispatching

*/
/******************************************************************************/
	template <typename T>
	void Circle<T>::accept(IVisitor<T>& visitor)
	{
		visitor.visit(*this);
	}
}
