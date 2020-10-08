/******************************************************************************/
/*!
\file   IScalable.h
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the interface class IScalable
and declarations of its member functions.


Functions included:
scale			   - a virtual function to scale a vector
IScalable          - a virtual destructor with a default implementation.

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/
#ifndef ISCALABLE_H
#define ISCALABLE_H

namespace cs225
{
	class IScalable 
	{
	public:
		//virtual scale function
		virtual void scale(const float factor) = 0;
		// Virtual destructor
		virtual ~IScalable() = default;
	};
}

#endif