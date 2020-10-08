/******************************************************************************/
/*!
\file   Point.h
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
color					- A color getter function to read the width of polygon.
translate				- A translate function to translate a vector by a 
						  displacement
clone					- A clone() function used for covariant return types
accept					- An accept visitor function for double dispatching

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/
#ifndef POINT_H
#define POINT_H
#include "IVisitable.h"
#include "color.h"
#include "IColoredShape.h"
#include "ITranslatable.h"
#include "ICloneable.h"
#include "Round.h"
#include "IVisitor.h"

namespace cs225
{

	template<typename T>
	class Point : public IVisitable<T>, public IColoredShape<T>, public ITranslatable<T>, public ICloneable
	{
	public:
		//Type alias
		using type = typename T::type;
		//Conversion constructor
		Point(const Color& color, const T& pts);
		//x and y getter functions
		unsigned int x() const;
		unsigned int y() const;
		//pivot function
		T pivot() const;
		//color function
		Color color() const;
		//translate function
		void translate(const T& displacement) override;

		virtual Point* clone() const override;

		void accept(IVisitor<T>& visitor) override;

		//Data members
		T _pivotPt;
		Color _ncolor;
  	};

}
#include "Point.hpp"
#endif