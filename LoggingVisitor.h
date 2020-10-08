/******************************************************************************/
/*!
\file   LoggingVisitor.h
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the templated class LoggingVisitor
and declarations of its member functions.


Functions included:
LoggingVisitor			- Conversion constructor
visit					- visit functions for logging of
						individual shapes
~LoggingVisitor			- virtual destructor
Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/

#ifndef LOGGINGVISITOR_H
#define LOGGINGVISITOR_H
#include "IShape.h"
#include "IVisitor.h"
#include "IVisitable.h"
#include"Background.h"
#include"Point.h"
#include"Circle.h"
#include"Polygon.h"
#include"Triangle.h"
#include"RegularPolygon.h"
#include <fstream>

namespace cs225
{
	template<typename T>
	class LoggingVisitor : public IVisitor<T>
	{
	public:
		//conversion constructor
		LoggingVisitor(const std::string filename);
		//visit functions
		void visit(Background<T>& background) override;
		void visit(Circle<T>& circle) override;
		void visit(Triangle<T>& triangle) override;
		void visit(Point<T>& point) override;
		void visit(Polygon<T>& polygon) override;
		void visit(RegularPolygon<T>& regularpolygon) override;
		//virtual destructor
		virtual ~LoggingVisitor();
	private:
		//data member
		std::ofstream file_m;
	};
}
#include "LoggingVisitor.hpp"
#endif