/******************************************************************************/
/*!
\file   IColoredShape.h
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the interface class IColoredShape
and declarations of its member functions.


Functions included:
color				   - a virtual function to read the color of a shape.
IColoredShape          - a virtual destructor with a default implementation.

Hours spent on this assignment: 6
Specific portions that gave you the most trouble: Commenting file headers!
*/
/******************************************************************************/

#ifndef ICOLOREDSHAPE_H
#define ICOLOREDSHAPE_H
#include "IShape.h"

namespace cs225
{
	template<typename T>
	class IColoredShape : public IShape<T>
	{
	public:
		//virtual color function
		virtual Color color() const = 0;
		// Virtual destructor
		virtual ~IColoredShape() = default;
	};

}
#endif