/******************************************************************************/
/*!
\file   Vector2D.h
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

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/

#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

#include <iostream>
#include <complex>

namespace cs225
{
	template <typename T>
	class Vector2D : public std::complex<T>
	{
	public:
		//type alias
		using type = T;

		//conversion constructor
		Vector2D(type x = 0, type y = 0);

		//copy constructor
		Vector2D(const std::complex<T>& copy);

		//getter functions
		type x() const;
		type y() const;

		//getter functions
		void x(type value);
		void y(type value);

	};
	//ostream operator
	template <typename T>
	std::ostream& operator<<(std::ostream& stream, const Vector2D<T>& rhs);
}

#include "Vector2D.hpp"

#endif
