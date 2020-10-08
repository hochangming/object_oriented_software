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
accept				   - a virtual function for accepting a visitor.
IVisitable             - a virtual destructor with a default implementation.

Hours spent on this assignment: 6
Specific portions that gave you the most trouble: Commenting file headers!
*/
/******************************************************************************/

#ifndef IVISITIBLE_H
#define IVISITIBLE_H

namespace cs225
{
	//declaration
	template <typename T>
	class IVisitor;

	template<typename T>
	class IVisitable
	{
	public:
		//accept function
		virtual void accept(IVisitor<T>& visitor) = 0;
		//destructor
		virtual ~IVisitable() = default;
	};

}
#endif