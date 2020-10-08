/******************************************************************************/
/*!
\file   VisitorFactory.h
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

#ifndef VISITORFACTORY_H
#define VISITORFACTORY_H
#include"Vector2D.h"
#include"IVisitor.h"
#include"LoggingVisitor.h"
#include"RenderingVisitor.h"

namespace cs225
{
	template<typename T>
	class VisitorFactory
	{
	public:
		//type alias
		using type= IVisitor<T>*;
		//create function for visitor objects
		IVisitor<T>* create(const size_t index);
	private:
		//data member
		std::vector<T> v;

	};

}

#include"VisitorFactory.hpp"
#endif