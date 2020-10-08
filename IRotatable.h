/******************************************************************************/
/*!
\file   IRotatable.h
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the interface class IRotatable
and declarations of its member functions.


Functions included:
rotate			   - a virtual function for rotating a vector.
~IRotatable        - a virtual destructor with a default implementation.

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers!
*/
/******************************************************************************/

#ifndef IROTATABLE_H
#define IROTATABLE_H

namespace cs225
{
	class IRotatable
	{
	public:
		//virtual Rotate function
		virtual void rotate(const float angle) = 0;
		// Virtual destructor
		virtual ~IRotatable() = default;
	};
}

#endif