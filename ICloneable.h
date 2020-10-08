/******************************************************************************/
/*!
\file   ICloneable.h
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the interface class ICloneable
and declarations of its member functions.


Functions included:
clone				   - a virtual function for cloning an object
ICloneable			   - a virtual destructor with a default implementation.

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers!
*/
/******************************************************************************/

#ifndef ICLONEABLE_H
#define ICLONEABLE_H

namespace cs225
{
	class ICloneable
	{
	public:
		virtual ICloneable* clone() const = 0;
		virtual ~ICloneable() = default;
	};

}
#endif