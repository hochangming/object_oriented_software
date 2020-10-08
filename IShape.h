/******************************************************************************/
/*!
\file   IShape.h
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the interface class IShape
and declarations of its member functions.


Functions included:
~IShape         - a virtual destructor with a default implementation.

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers!
*/
/******************************************************************************/
#ifndef ISHAPE_H
#define ISHAPE_H
#include "color.h"

namespace cs225
{ 
	template<typename T>
	class IShape 
	{
	public:
		// Virtual destructor
		virtual ~IShape() = default;

	};

}
#endif