/******************************************************************************/
/*!
\file   Circle.h
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

#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
#include "IScalable.h"
#include "IVisitable.h"
#include<cmath>
namespace cs225
{
	template<typename T>
	class Circle : public Point<T>, public IScalable
	{
	public:
		//Conversion constructor
		Circle(const Color& color, 
		const T& pts, float radius);
		//Scale function
		void scale(float factor) override;
		//radius function
		float radius() const;
		//color function
		Color color() const;
		//clone function
		Circle* clone() const override;
		//accept visitor function
		void accept(IVisitor<T>& visitor) override;

	private:
		//_radius of circle
		float _radius;
	};
}

#include "Circle.hpp"
#endif