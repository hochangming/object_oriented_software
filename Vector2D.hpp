/******************************************************************************/
/*!
\file   Vector2D.hpp
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the templated class Triangle
and declarations of its member functions.

Functions included:
Vector2D				- Conversion constructor
x						- getter functions for x coordinate
y						- getter functions for y coordinate
operator<<				- ostream operator to print out contents

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/

#include "Vector2D.h"

namespace cs225
{
/******************************************************************************/
/*!
	\brief
	Conversion Constructor to construct Vector2D object

	\param x
	x value to be instantiated by std::complex

	\param y
	y value to be instantiated by std::complex
*/
/******************************************************************************/
	template <typename T>
	Vector2D<T>::Vector2D(type x, type y) :
	std::complex<T>(x, y){}
/******************************************************************************/
/*!
	\brief
	Copy Constructor for Vector2D object

	\param copy
	Value to be instantiated by copy constructor of std::complex

*/
/******************************************************************************/
	template <typename T>
	Vector2D<T>::Vector2D(const std::complex<T>& copy) :
	std::complex<T>(copy){}
/******************************************************************************/
/*!
	\brief
	x getter function to get value of x

*/
/******************************************************************************/
	template <typename T>
	typename Vector2D<T>::type Vector2D<T>::x() const
	{
		return std::complex<T>::real();
	}
/******************************************************************************/
/*!
	\brief
	y getter function to get value of y

*/
/******************************************************************************/
	template <typename T>
	typename Vector2D<T>::type Vector2D<T>::y() const
	{
		return std::complex<T>::imag();
	}
/******************************************************************************/
/*!
	\brief
	x getter function to get value of x

	\param value
	value of x to be passed to std::complex to instantiate

*/
/******************************************************************************/
	template <typename T>
	void Vector2D<T>::x(type value)
	{
		std::complex<T>::real(value);
	}
/******************************************************************************/
/*!
	\brief
	y getter function to get value of y

	\param value
	value of y to be passed to std::complex to instantiate

*/
/******************************************************************************/
	template <typename T>
	void Vector2D<T>::y(type value)
	{
		std::complex<T>::imag(value);
	}
/******************************************************************************/
/*!
	\brief
	ostream<< operator to for print out of coordinates x,y

	\param stream
	output stream for print out

	\param rhs
	rhs parameter used to print out x and y.
*/
/******************************************************************************/
	template <typename T>
	std::ostream& operator<<(std::ostream& stream, const Vector2D<T>& RHS)
	{
		return (stream << RHS.x() << "," << RHS.y());
	}
}
