/******************************************************************************/
/*!
\file   RenderingVisitor.h
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the class RenderingVisitor
and declarations of its member functions.


Functions included:
RenderingVisitor			- a conversion constructor
visit						- visit functions used for rendering of
							individual shapes to a bitmap file
Destructor					- a destructor to save file and free memory

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers!
*/
/******************************************************************************/

#ifndef RENDERINGVISITOR_H
#define RENDERINGVISITOR_H
#include "IVisitor.h"
#include"Round.h"
#include"Vector2D.h"
#include "BitmapCanvas.h"
#include<string>

namespace cs225
{
	template<typename T>
	class RenderingVisitor : public IVisitor<T>
	{
	public:
		//conversion constructor
		RenderingVisitor(const int width,const int height,
		const float scalefac1, const float scalefac2, 
		std::string filename);
		//visit functions 
		void visit(Background<T>& background) override;
		void visit(Triangle<T>& triangle) override;
		void visit(Circle<T>& circle) override;
		void visit(Point<T>& point) override;
		void visit(Polygon<T>& polygon) override;
		void visit(RegularPolygon<T>&
		regularpolygon) override;
		//virtual destructor
		virtual ~RenderingVisitor();
		
	private:
		//data members
		const int _width;
		const int _height;
		const float scalef_1;
		const float scalef_2;
		std::string _mFile;
		BitmapCanvas<T>* bitmap;
	};

}
#include"RenderingVisitor.hpp"
#endif