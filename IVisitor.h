/******************************************************************************/
/*!
\file   IVisitor.h
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the interface class IColoredShape
and declarations of its member functions.


Functions included:
visit				   - a virtual function for visiting individual shapes
IVisitor			   - a virtual destructor with a default implementation.

Hours spent on this assignment: 6
Specific portions that gave you the most trouble: Commenting file headers!
*/
/******************************************************************************/

#ifndef IVISITOR_H
#define IVISITOR_H

 namespace cs225
{
	 //declarations of shapes
	 template<typename T>
	 class Background;
	 template<typename T>
	 class Polygon;
	 template<typename T>
	 class Point;
	 template<typename T>
	 class Circle;
	 template<typename T>
	 class Triangle; 
	 template<typename T>
	 class RegularPolygon;
	template<typename T>

	class IVisitor
	{
	public:
		//visit functions
		virtual void visit(Background<T>& background) = 0;
		virtual void visit(Point<T>& point) = 0;
		virtual void visit(Circle<T>& circle) = 0;
		virtual void visit(Triangle<T>& triangle) = 0;
		virtual void visit(Polygon<T>& polygon) = 0;
		virtual void visit(RegularPolygon<T>& regularpolygon) = 0;
		//destructor
		virtual ~IVisitor() = default;
	};
	
}

#endif