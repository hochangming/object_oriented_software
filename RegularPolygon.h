/******************************************************************************/
/*!
\file   RegularPolygon.h
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the templated class RegularPolygon
and declarations of its member functions.


Functions included:
RegularPolygon			- Conversion constructor
rotationfn				- To compute rotatation about a point of origin
clone					- A clone() function used for covariant return types
accept					- An accept visitor function for double dispatching

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/
#ifndef REGULAR_POLYGON_H
#define REGULAR_POLYGON_H
#include "Polygon.h"
#include "IVisitable.h"

namespace cs225
{
	template<typename T>
	class RegularPolygon : public Polygon<T>
	{
	public:
		//Conversion Constructor
		RegularPolygon(const Color& color, const T& origin,
						const T& vertex,
						const size_t n_sides);
		//Rotation function to rotate about point of origin
		void rotationfn(const T& origin, const T& vertex, 
						const size_t n_sides);

		RegularPolygon* clone() const override;

		void accept(IVisitor<T>& visitor) override;

	};
}
#include"IVisitor.h"
#include "RegularPolygon.hpp"
#endif