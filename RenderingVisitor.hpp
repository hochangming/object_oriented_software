/******************************************************************************/
/*!
\file   RenderingVisitor.hpp
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
#include "RenderingVisitor.h"

namespace cs225
{
/******************************************************************************/
/*!
	\brief
	RenderingVisitor's conversion constructor

	\param width
	pixel width of background 

	\param height
	pixel height of background 

	\param scalefac1
	scale factor to determine the amount to scale by

	\param scalefac2
	scale factor to determine the amount to scale by

	\param filename
	file to write to

*/
/******************************************************************************/
	template<typename T>
	RenderingVisitor<T>::RenderingVisitor(const int width,const int height,
	const float scalefac1, const float scalefac2, std::string filename)
	: _width{ width }, _height{ height }, scalef_1{ scalefac1 }
	, scalef_2{ scalefac2 }, _mFile{ filename }
	{
		int newWidth{};
		int newHeight{};
		if (_height == 240)
		{
			/*Width after scaling*/
			newWidth = round<int,float>
			(static_cast<float>
			(_width) * scalefac1);	
			/*height after scaling*/
			newHeight = round<int, float>
			(static_cast<float>
			(_height) * scalefac2);
			/*Assign bitmap ptr to new dimensions*/
			bitmap = new BitmapCanvas<T>(newWidth, newHeight);
		}
		else
		{
			/*Assign bitmap ptr to orig dimensions*/
			bitmap = new BitmapCanvas<T>(_width, _height);
		}

	} 
/******************************************************************************/
/*!
	\brief
	visit function's implementation to be called for rendering of background

	\param background
	To call upon background's data members/functions

*/
/******************************************************************************/
	template<typename T>
	void RenderingVisitor<T>::visit(Background<T>& background)
	{
		float x_Factor = static_cast<float>(_width);
		float y_Factor = static_cast<float>(_height);
		const float dx = 1.0f / static_cast<float>(_width);
		const float dy = 1.0f / static_cast<float>(_height);
		int i = 0;

		for (int h{}; h < _height; ++h) //height iteration
		{
			for (int w{}; w < _width; ++w) //width iteration
			{
				const float wf = static_cast<float>(w);
				const float hf = static_cast<float>(h);

				const Vector2D<float> _uleft
				(scalef_1 * wf * dx,
				scalef_2 * (hf + 1.0f) * dy);
				const Vector2D<float> _lRight
				(scalef_1 * (wf + 1.0f) * dx,
				scalef_2 * hf * dy);

				const typename BitmapCanvas<T>::point2D 
				upper_left =
				typename BitmapCanvas<T>::point2D(
				round<int,float>(x_Factor * _uleft.x()), 
				round<int, float>(scalef_1 * static_cast<float>
				(_height) - y_Factor * _uleft.y()));
				const typename BitmapCanvas<T>::point2D 
				lower_right =
				typename BitmapCanvas<T>::point2D(
				round<int, float>(x_Factor * _lRight.x()),
				round<int, float>(scalef_2 * static_cast<float>
				(_height) - y_Factor * _lRight.y()));

				/*retrieve color of pixels from background*/
				const Color* const colorData = 
				background.colorData(); 
				bitmap->color(colorData[i++]);

				/*Draw rectangle with the color of pixels*/
				bitmap->drawRectangle(upper_left, lower_right); 

			}
		}

	}
/******************************************************************************/
/*!
	\brief
	visit function's implementation to be called for rendering of triangle

	\param triangle
	To call upon triangle's data members/functions

*/
/******************************************************************************/
	template<typename T>
	void RenderingVisitor<T>::visit(Triangle<T>& triangle)
	{
		std::vector<typename BitmapCanvas<T>::point2D> v;
		for (unsigned int i{}; i < triangle._npts.size(); i++)
		{
			const typename BitmapCanvas<T>::point2D pul1 = 
				typename BitmapCanvas<T>::point2D(
				round<int, float>(scalef_1 *
				static_cast<float>
				(triangle._npts[i].x())),
				round<int, float>(static_cast<float>
				(static_cast<float>(_height) 
				* scalef_1)
				+ (scalef_1 * 
				static_cast<float>
				(triangle._npts[i].y())) * -1)
			); 
			v.push_back(pul1);
		}
		bitmap->color(triangle.color());
		bitmap->drawPolygon(v);

	}
/******************************************************************************/
/*!
	\brief
	visit function's implementation to be called for rendering of circle

	\param circle
	To call upon circle's data members/functions

*/
/******************************************************************************/
	template<typename T>
	void RenderingVisitor<T>::visit(Circle<T>& circle)
	{
		const Vector2D<float> upper_left{ scalef_1 * 
			(static_cast<float>(circle.Point<T>::pivot().x())
			- circle.radius()),scalef_2 * 
			(static_cast<float>(circle.Point<T>::pivot().y())
			+ circle.radius()) };
		const Vector2D<float> lower_right{ scalef_1 * 
			(static_cast<float>(circle.Point<T>::pivot().x())
			+ circle.radius()),scalef_2 * 
			(static_cast<float>(circle.Point<T>::pivot().y())
			- circle.radius()) };

		const typename BitmapCanvas<T>::point2D pul1 = 
			typename BitmapCanvas<T>::point2D(
			round<int, float>(upper_left.x()),
			round<int, float>(static_cast<float>
			(static_cast<float>(_height) * scalef_1) + 
			(upper_left.y() * -1))
		);
		const typename BitmapCanvas<T>::point2D plr1 = 
			typename BitmapCanvas<T>::point2D(
			round<int, float>(lower_right.x()),
			round<int, float>(static_cast<float>
			(static_cast<float>(_height) * scalef_1) +
			(lower_right.y() * -1))
		);
		bitmap->color(circle.color());
		bitmap->drawEllipse(pul1, plr1);
	}
/******************************************************************************/
/*!
	\brief
	visit function's implementation to be called for rendering of point

	\param point
	To call upon point's data members/functions

*/
/******************************************************************************/
	template<typename T>
	void RenderingVisitor<T>::visit(Point<T>& point)
	{
		const typename BitmapCanvas<T>::point2D plr1 = 
			typename BitmapCanvas<T>::point2D(
			round<int, float>
			(scalef_1 *
			static_cast<float>(point.pivot().x())),
			round<int, float>
			(static_cast<float>(_height) * scalef_1+ 
			(scalef_2 *
			static_cast<float>(point.pivot().y())) * -1)
		);
		bitmap->color(point.color());
		bitmap->drawPixel(plr1);
	}
/******************************************************************************/
/*!
	\brief
	visit function's implementation to be called for rendering of polygon

	\param polygon
	To call upon polygon's data members/functions

*/
/******************************************************************************/
	template<typename T>
	void RenderingVisitor<T>::visit(Polygon<T>& polygon)
	{
		std::vector<typename BitmapCanvas<T>::point2D> v;
		for (unsigned int i{}; i < polygon._npts.size(); i++)
		{
			const typename BitmapCanvas<T>::point2D pul1 = 
				typename BitmapCanvas<T>::point2D(
				round<int,float>(scalef_1 *
				static_cast<float>(polygon._npts[i].x())),
				round<int, float>
				(static_cast<float>(_height) * 
				scalef_1 +(scalef_2 *
				static_cast<float>(polygon._npts[i].y())) *
				-1));

			v.push_back(pul1);
		}
		bitmap->color(polygon.color());
		bitmap->drawPolygon(v);

	}
/******************************************************************************/
/*!
	\brief
	visit function's implementation to be called for rendering of regularpolygon

	\param regularpolygon
	To call upon regularpolygon's data members/functions

*/
/******************************************************************************/
	template<typename T>
	void RenderingVisitor<T>::visit(RegularPolygon<T>& regularpolygon)
	{
		std::vector<typename BitmapCanvas<T>::point2D> v;
		for (unsigned int i{}; i < regularpolygon._npts.size(); i++)
		{
			const typename BitmapCanvas<T>::point2D pul1 = 
				typename BitmapCanvas<T>::point2D(
				round<int, int>(static_cast<int>(scalef_1) * 
				static_cast<int>(regularpolygon._npts[i].x())),
				round<int, int>(static_cast<int>
				(static_cast<float>(_height)*scalef_1) +
				(static_cast<int>(scalef_2) * static_cast<int>
				(regularpolygon._npts[i].y()) * -1))
			); 
			v.push_back(pul1);
		}
		bitmap->color(regularpolygon.color());
		bitmap->drawPolygon(v);
	}
/******************************************************************************/
/*!
	\brief
	Destructor to save file and free memory
*/
/******************************************************************************/
	template<typename T>
	RenderingVisitor<T>::~RenderingVisitor()
	{
		bitmap->save(_mFile);
		delete bitmap;
	}
}
