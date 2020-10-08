/******************************************************************************/
/*!
\file   Triangle.h
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
Color					- A Color getter function to read color from class
clone					- A clone() function used for covariant return types
accept					- An accept visitor function for double dispatching

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<array>
#include "Polygon.h"
#include "IVisitable.h"

namespace cs225
{	
	template <typename T>
	class IVisitor;

	template<typename T>
	class Triangle : public Polygon<T>
	{
	public:
		//Conversion constructor
		Triangle(const Color& colors, std::array<T, 3> pts);
		//color function
		Color color() const;
		//Clone function
		Triangle* clone();
		//accept visitor function
		void accept(IVisitor<T>& visitor) override;

	};

}
#include"IVisitor.h"
#include "Triangle.hpp"
#endif