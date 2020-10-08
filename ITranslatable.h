/******************************************************************************/
/*!
\file   ITranslatable.h
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the interface class ITranslatable
and declarations of its member functions.

Functions included:
translate			   - a virtual function for translating a vector.
~ITranslatable         - a virtual destructor with a default implementation.

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers!
*/
/******************************************************************************/
#ifndef ITRANSLATABLE_H
#define ITRANSLATABLE_H

namespace cs225
{
	template<typename T>
	class ITranslatable
	{
	public:
		//Translate function
		virtual void translate(const T& displacement)  = 0; 
		// Virtual destructor
		virtual ~ITranslatable() = default;
	};
}

#endif