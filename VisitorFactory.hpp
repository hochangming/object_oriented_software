/******************************************************************************/
/*!
\file   VisitorFactory.hpp
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the Factory class VisitorFactory
and declarations of its member functions.


Functions included:
create				   - Instantiates objects of visitor types

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers!
*/
/******************************************************************************/
#include "VisitorFactory.h"

namespace cs225
{
/******************************************************************************/
/*!
	\brief
	Factory's create function to generate new objects of visitors

	\param index
	index is used to determine which object to create

*/
/******************************************************************************/
	template<typename T>
	IVisitor<T>* VisitorFactory<T>::create(size_t index)
	{
		switch (index)
		{
			case 0: return new LoggingVisitor<T>
			{ "output0.txt" };
			case 1: return new RenderingVisitor<T>
			{ 640,240,2.0F,2.0F,"output1.bmp" };
			case 2: return new RenderingVisitor<T>
			{ 640,480,1.0F,1.0F,"output2.bmp" };
			default: throw std::string
			{ "Not supported!" };
		}
	}
}
