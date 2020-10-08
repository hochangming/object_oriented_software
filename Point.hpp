/******************************************************************************/
/*!
\file   Point.hpp
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the templated class Point
and declarations of its member functions.


Functions included:
Point					- Conversion constructor
x						- A x-coordinate getter function.
y						- A y-coordinate getter function.
pivot					- A pivot getter function to read the pivot point
color					- A Color getter function to read color from class
translate				- A translate function to translate a vector by a
						  displacement
clone					- A clone() function used for covariant return types
accept					- An accept visitor function for double dispatching

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/
#include "Point.h"


namespace cs225
{

/******************************************************************************/
/*!
	\brief
	Conversion Constructor to construct Point object

	\param color
	A color type object that holds a collection of data colors

	\param pts
	Vector2D type point for construction

*/
/******************************************************************************/
	template<typename T>
	Point<T>::Point(const Color& color, const T& pts) 
			: _pivotPt(pts), _ncolor(color) {}
/******************************************************************************/
/*!
	\brief
	An x-coordinate getter function to read

*/
/******************************************************************************/
	template<typename T>
	unsigned int Point<T>::x() const
	{
		return _pivotPt.x();
	}
/******************************************************************************/
/*!
	\brief
	A y-coordinate getter function to read

*/
/******************************************************************************/
	template<typename T>
	unsigned int Point<T>::y() const
	{
		return _pivotPt.y();
	}
/******************************************************************************/
/*!
	\brief
	A pivot getter function for x and y coordinate

*/
/******************************************************************************/
	template<typename T>
	T Point<T>::pivot() const
	{
		return _pivotPt;
	}
/******************************************************************************/
/*!
	\brief
	A color getter function

*/
/******************************************************************************/
	template<typename T>
	Color Point<T>::color() const 
	{
		return _ncolor;
	}

/******************************************************************************/
/*!
	\brief
	A translate function to translate a point by a displacement

*/
/******************************************************************************/
	template<typename T>
	void Point<T>::translate(const T& displacement)
	{
		_pivotPt = T(round<typename Point<T>::type, size_t>
			(static_cast<size_t>(_pivotPt.x() + displacement.x())),
			round<typename Point<T>::type, size_t>
			(static_cast<size_t>(_pivotPt.y() + displacement.y())));
	}
/******************************************************************************/
/*!
	\brief
	A clone() function used on Point for creation of prototypes
	A Prototype design pattern that uses covariant return types

*/
/******************************************************************************/
	template <typename T>
	Point<T>* Point<T>::clone() const
	{
		return new Point(*this);
	}
/******************************************************************************/
/*!
	\brief
	An accept visitor function for Point used for double dispatching

*/
/******************************************************************************/
	template <typename T>
	void Point<T>::accept(IVisitor<T>& visitor)
	{
		visitor.visit(*this);
	}
}
