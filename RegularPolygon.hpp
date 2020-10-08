/******************************************************************************/
/*!
\file   RegularPolygon.hpp
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
#include "RegularPolygon.h"

namespace cs225
{
/******************************************************************************/
/*!
	\brief
	A conversion Constructor to construct RegularPolygon object

	\param color
	A color type object that holds a collection of data colors

	\param origin
	Vector2D type value that is the origin of Regular Polygon

	\param vertex
	Vector2D type value that is the vertex of Regular Polygon

	\param n_sides
	Int value that holds the sides of Regular Polygon

*/
/******************************************************************************/
	template<typename T>
	RegularPolygon<T>::RegularPolygon(const Color& color, const T& origin, 
								const T& vertex, const size_t n_sides)
								: Polygon<T>{ color, n_sides, &vertex }
	{
		rotationfn(origin, vertex, n_sides);
	}
/******************************************************************************/
/*!
	\brief
	A rotation function to compute rotation about point of origin

	\param origin
	Vector2D type value that is the origin of Regular Polygon

	\param vertex
	Vector2D type value that is the vertex of Regular Polygon

	\param n_sides
	Int value that holds the sides of Regular Polygon
*/
/******************************************************************************/
	template<typename T>
	void RegularPolygon<T>::rotationfn(const T& origin,
		const T& vertex, const size_t n_sides)
	{
		std::vector<T> result;
		const float angle = static_cast<float>((2.0f * (4 * std::atan(1)))/
							static_cast<float>(n_sides));
		Point<T>::_pivotPt = origin; // origin of rotation
		for (size_t i=0; i < n_sides; ++i)
		{
			float n_x = static_cast<float>(vertex.x() - origin.x()); //vertex - origin
			float n_y = static_cast<float>(vertex.y() - origin.y());
			result.push_back(T{
					round<typename Point<T>::type, float>(static_cast<float>
					(origin.x()) + //origin + rotate
					std::cos(static_cast<float>(i) * angle) * n_x -
					std::sin(static_cast<float>(i) * angle) * n_y),
					round<typename Point<T>::type, float>(static_cast<float>
					(origin.y()) + 
					std::sin(static_cast<float>(i) * angle) * n_x +
					std::cos(static_cast<float>(i) * angle) * n_y) });

		}
		for (size_t i=0; i < n_sides; i++)
		{
			Polygon<T>::_npts[i] = result[i];
		}
	}
/******************************************************************************/
/*!
	\brief
	A clone() function used on RegularPolygon for creation of prototypes
	A Prototype design pattern that uses covariant return types

*/
/******************************************************************************/
	template <typename T>
	RegularPolygon<T>* RegularPolygon<T>::clone() const
	{
		return new RegularPolygon(*this);
	}
/******************************************************************************/
/*!
	\brief
	An accept visitor function for RegularPolygon used for double dispatching

*/
/******************************************************************************/
	template <typename T>
	void RegularPolygon<T>::accept(IVisitor<T>& visitor)
	{
		visitor.visit(*this);
	}
}
