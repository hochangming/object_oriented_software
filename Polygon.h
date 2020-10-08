/******************************************************************************/
/*!
\file   Polygon.h
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the templated class Polygon
and declarations of its member functions.


Functions included:
Polygon					- Conversion constructor
size					- A size getter function.
points					- points() getter function to read points of polygon.
rotate					- A rotate function for rotation of a polygon.
scale					- A width getter function to read the width of polygon.
color					- A Color getter function to read color from class
clone					- A clone() function used for covariant return types
accept					- An accept visitor function for double dispatching

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/

#ifndef POLYGON_H
#define POLYGON_H
#include "Point.h"
#include "IScalable.h"
#include "IRotatable.h"
#include "Round.h"
#include <cmath>
#include <vector>
#include "IVisitable.h"

namespace cs225
{
	template<typename T>
	class Polygon : public Point<T>, public IScalable, public IRotatable
	{
	public:
		//Conversion constructor
		Polygon(const Color& colors, const size_t size, const T* points);
		//Size getter function
		size_t size() const;
		//points() getter function
		T* points();
		//color function
		Color color() const;
		//center function
		T center();
		//rotate function
		void rotate(const float angle) override;
		//scale function
		void scale(const float factor) override;
		//clone function
		Polygon* clone() const override;
		//Translate function
		void translate(const T& displacement) override;
		//accept visitor function
		void accept(IVisitor<T>& visitor) override;

		//No.of points in polygon
		const size_t _nsize;
		 //A vector of points
		std::vector<T>_npts;
		 
	};
}
#include "Polygon.hpp"
#endif