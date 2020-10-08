/******************************************************************************/
/*!
\file   Triangle.hpp
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the templated class Triangle
and declarations of its member functions.

Functions included:
Triangle				- Conversion constructor
Color					- A getter function for color
clone					- A clone() function used for covariant return types
accept					- An accept visitor function for double dispatching

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/
#include "Triangle.h"

namespace cs225
{
/******************************************************************************/
/*!
	\brief
	Conversion Constructor to construct Triangle object

	\param pts
	An array of points for construction of triangle

*/
/******************************************************************************/
	template<typename T>
	Triangle<T>::Triangle(const Color& colors, std::array<T, 3> pts) 
	: Polygon<T>(colors, 3, pts.data()) {}
/******************************************************************************/
/*!
	\brief
	A getter function of color
*/
/******************************************************************************/
	template<typename T>
	Color Triangle<T>::color() const
	{
		return Triangle<T>::_ncolor;
	}
/******************************************************************************/
/*!
	\brief
	A clone() function used on triangle for creation of prototypes 
	A Prototype design pattern that uses covariant return types

*/
/******************************************************************************/
	template <typename T>
	Triangle<T>* Triangle<T>::clone()
	{
		return new Triangle(*this);
	}
/******************************************************************************/
/*!
	\brief
	An accept visitor function for triangle used for double dispatching 

*/
/******************************************************************************/
	template <typename T>
	void Triangle<T>::accept(IVisitor<T>& visitor)
	{
		visitor.visit(*this);
	}

}
