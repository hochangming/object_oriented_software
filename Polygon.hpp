/******************************************************************************/
/*!
\file   Polygon.hpp
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
center					- A center of polygon getter function.
points					- points() getter function to read points of polygon.
scale					- A width getter function to read the width of polygon.
rotate					- A rotate function for rotation of a polygon.
color					- A Color getter function to read color from class
clone					- A clone() function used for covariant return types
accept					- An accept visitor function for double dispatching

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/

#include "Polygon.h"

namespace cs225
{
/******************************************************************************/
/*!
	\brief
	A conversion Constructor to construct Polygon object

	\param colors
	A color type object that holds a collection of data colors

	\param size
	size_t value that holds the size of Polygon

	\param points
	A Vector2D type pointer that points to first vector(x,y)
*/
/******************************************************************************/

	template<typename T>
	Polygon<T>::Polygon(const Color& colors, const size_t size,
	const T* points)
	: Point<T>{ colors, T{}}, _nsize{size}
	{
		for (unsigned int i{}; i < size; i++)
		{
			_npts.push_back(points[i]);
		}

		for (auto& vertice : _npts) 
		{
			Point<T>::_pivotPt += vertice;
		}
		Point<T>::_pivotPt = T{ round<typename Point<T>::type, float>
							(static_cast<float>(Point<T>::_pivotPt.x())
							/ static_cast<float>(size)) ,
							round<typename Point<T>::type, float>
							(static_cast<float>(Point<T>::_pivotPt.y())
							/ static_cast<float>(size)) };
	}

/******************************************************************************/
/*!
	\brief
	A size() function to read the number of the points

*/
/******************************************************************************/
	template<typename T>
	size_t Polygon<T>::size() const
	{
		return _nsize;
	}

/******************************************************************************/
/*!
	\brief
	A center function to get compute the center of the polygon points

*/
/******************************************************************************/
	template<typename T>
	T Polygon<T>::center()
	{
		T center{};
		for (unsigned int i{}; i < _nsize; i++)
		{
			center += _npts[i];
		}
		return center;
	}
/******************************************************************************/
/*!
	\brief
	points function to read the array of points

*/
/******************************************************************************/
	template<typename T>
	T* Polygon<T>::points() 
	{
		return _npts.data();
	}

/******************************************************************************/
/*!
	\brief
	A scale function to scale a polygon by a given factor.
	Translate the designated point to the origin
	Scale at the (temporary, new) origin.
	Translate back so that the origin goes back to the designated point.

	\param factor
	Signifies the amount scaling is to be done

*/
/******************************************************************************/

	template<typename T>
	void Polygon<T>::scale(const float factor) 
	{
		T centerpt = center();
	 
		centerpt = T(round<typename Point<T>::type, float>
					(static_cast<float>(centerpt.x()) /
					static_cast<float>(_nsize))
					, round<typename Point<T>::type, float>
					(static_cast<float>(centerpt.y()) /
					static_cast<float>(_nsize)));
		for (auto& vertices_ : _npts)
		{
			vertices_ = T(round<typename Point<T>::type, float>
					(static_cast<float>(centerpt.x()) + (factor) *
					(static_cast<float>(vertices_.x() - centerpt.x()))),
					round<typename Point<T>::type, float>
					(static_cast<float>(centerpt.y()) + (factor) *
					(static_cast<float>(vertices_.y() - centerpt.y()))));
		}

	}
/******************************************************************************/
/*!
	\brief
	A translate function to translate a polygon by a given displacement.

	\param displacement
	Signifies the amount translating is to be done

*/
/******************************************************************************/
	template<typename T>
	void Polygon<T>::translate(const T& displacement)
	{
		T centerpt = center();

		centerpt = T(round<typename Point<T>::type, float>
					(static_cast<float>(centerpt.x()) /
					static_cast<float>(_nsize))
					, round<typename Point<T>::type, float>
					(static_cast<float>(centerpt.y()) /
					static_cast<float>(_nsize)));
		for (size_t i{}; i < _nsize; i++)
		{
			_npts[i] = T(round<typename Point<T>::type, float>
					(static_cast<float>(_npts[i].x() +
					displacement.x())),
					round<typename Point<T>::type, float>
					(static_cast<float>(_npts[i].y() +
					displacement.y())));
		}
		Point<T>::_pivotPt = T(round<typename Point<T>::type, float>
					(static_cast<float>(centerpt.x()+ displacement.x())),
					round<typename Point<T>::type, float>
					(static_cast<float>
					(centerpt.y() +
					displacement.y())));

	}
/******************************************************************************/
/*!4
	\brief
	A rotate function to rotate the polygon by a given angle

	\param angle
	Signifies the angle of rotation

*/
/******************************************************************************/
 
	template<typename T>
	void Polygon<T>::rotate(const float angle)
	{
		T centerpt = center();
		typename Point<T>::type x_n, y_n;

		centerpt = T(round<typename Point<T>::type, float>
					(static_cast<float>(centerpt.x()) /
					static_cast<float>(_nsize)), 
					round<typename Point<T>::type, float>
					(static_cast<float>(centerpt.y()) /
					static_cast<float>(_nsize)));

		for (auto& vertices_ : _npts)
		{
			x_n = round<typename Point<T>::type, float>
				(static_cast<float>(centerpt.x())
				+ std::cos(angle) * static_cast<float>(vertices_.x() -
				centerpt.x()) -
				std::sin(angle) * static_cast<float>(vertices_.y() -
				centerpt.y()));

			y_n = round<typename Point<T>::type, float>
				(static_cast<float>(centerpt.y())
				+ std::sin(angle) * static_cast<float>(vertices_.x() -
				centerpt.x()) + std::cos(angle) *
				static_cast<float>(vertices_.y() - centerpt.y()));
			vertices_ = T(x_n, y_n);
		}
	}

/******************************************************************************/
/*!
	\brief
	A color getter function to read the color

*/
/******************************************************************************/
	template<typename T>
	Color Polygon<T>::color() const
	{
		return Polygon<T>::_ncolor;
	}
/******************************************************************************/
/*!
	\brief
	A clone() function used on Polygon for creation of prototypes 
	A Prototype design pattern that uses covariant return types

*/
/******************************************************************************/
	template <typename T>
	Polygon<T>* Polygon<T>::clone() const
	{
		return new Polygon(*this);
	}
/******************************************************************************/
/*!
	\brief
	An accept visitor function for Polygon used for double dispatching

*/
/******************************************************************************/
	template <typename T>
	void Polygon<T>::accept(IVisitor<T>& visitor)
	{
		visitor.visit(*this);
	}
}
