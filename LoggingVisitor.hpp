/******************************************************************************/
/*!
\file   LoggingVisitor.hpp
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

#include "LoggingVisitor.h"

namespace cs225
{
/******************************************************************************/
/*!
	\brief
	LoggingVisitor's conversion contructor that takes in a file

	\param file_name
	To read in a file

*/
/******************************************************************************/
	template<typename T>
	LoggingVisitor<T>::LoggingVisitor(const std::string file_name)
	: file_m(file_name)
	{
		file_m << "### List of shapes ###" << std::endl;
	}
/******************************************************************************/
/*!
	\brief
	Implementation of background visit function, to be
	called once double dispatch has been carried out

	\param background
	To call upon background's data members/functions

*/
/******************************************************************************/
	template<typename T>
	void LoggingVisitor<T>::visit(Background<T>& background)
	{
		file_m << "\tBackground" << std::endl;
		file_m << "\t\tSize: " << "(" << background.height()
			<< ", " << background.width() << ")" << std::endl;
	}

/******************************************************************************/
/*!
	\brief
	Implementation of point visit function, to be called
	once double dispatch has been carried out

	\param point
	To call upon point's data members/functions

*/
/******************************************************************************/
	template<typename T>
	void LoggingVisitor<T>::visit(Point<T>& point)
	{
		file_m << "\tPixel" << std::endl;
		file_m << "\t\tCoordinates: " << "(" << point._pivotPt.x()
			<< ", " << point._pivotPt.y() << ")" << std::endl;
		file_m << "\t\tColor: " << "(" <<
			static_cast<size_t>(point.color().red())
			<< ", " << static_cast<size_t>(point.color().green())
			<< ", " << static_cast<size_t>(point.color().blue())
			<< ")" << std::endl;
	}
/******************************************************************************/
/*!
	\brief
	Implementation of polygon visit function, to be called
	once double dispatch has been carried out

	\param polygon
	To call upon polygon's data members/functions

*/
/******************************************************************************/
	template<typename T>
	void LoggingVisitor<T>::visit(Polygon<T>& polygon)
	{
		unsigned int j{};
		file_m << "\tPolygon" << std::endl;
		file_m << "\t\tPivot: " << "(" << polygon._pivotPt.x()
			<< ", " << polygon._pivotPt.y() << ")" << std::endl;
		for (auto& _pt : polygon._npts)
		{
			file_m << "\t\tPoint[" << j++ << "]: "
				<< "(" << _pt.x() << ", "
				<< _pt.y() << ")"
				<< std::endl;
		}
		file_m << "\t\tColor: " << "(" <<
			static_cast<size_t>(polygon.color().red())
			<< ", " << static_cast<size_t>(polygon.color().green())
			<< ", " << static_cast<size_t>(polygon.color().blue())
			<< ")" << std::endl;
		file_m << "###" << std::endl;
	}
/******************************************************************************/
/*!
	\brief
	Implementation of circle visit function, to be called once
	double dispatch has been carried out

	\param circle
	To call upon circle's data members/functions

*/
/******************************************************************************/
	template<typename T>
	void LoggingVisitor<T>::visit(Circle<T>& circle)
	{
		file_m << "\tCircle" << std::endl;
		file_m << "\t\tCenter: " << "(" << circle._pivotPt.x()
			<< ", " << circle._pivotPt.y() << ")"
			<< std::endl;
		file_m << "\t\tCoordinates: " << "(" << circle._pivotPt.x()
			<< ", " << circle._pivotPt.y() << ", " << circle.radius()
			<< ")" << std::endl;
		file_m << "\t\tColor: " << "(" <<
			static_cast<size_t>(circle.color().red())
			<< ", " << static_cast<size_t>(circle.color().green())
			<< ", " << static_cast<size_t>(circle.color().blue())
			<< ")" << std::endl;
	}
/******************************************************************************/
/*!
	\brief
	Implementation of triangle visit function, to be called 
	once double dispatch has been carried out

	\param triangle
	To call upon triangle's data members/functions

*/
/******************************************************************************/
	template<typename T>
	void LoggingVisitor<T>::visit(Triangle<T>& triangle)
	{
		unsigned int j{};
		file_m << "\tTriangle" << std::endl;
		file_m << "\t\tPivot: " << "(" << triangle._pivotPt.x()
			<< ", " << triangle._pivotPt.y() << ")" << std::endl;

		for (auto& _pt : triangle._npts)
		{
			file_m << "\t\tPoint[" << j++ << "]: " << "("
				<< _pt.x() << ", " << _pt.y() << ")"
				<< std::endl;
		}
		file_m << "\t\tColor: " << "(" <<
		static_cast<size_t>(triangle.color().red())
		<< ", " << static_cast<size_t>(triangle.color().green())
		<< ", " << static_cast<size_t>(triangle.color().blue())
		<< ")" << std::endl;
	}
/******************************************************************************/
/*!
	\brief
	Implementation of regularpolygon visit function, to be
	called once double dispatch has been carried out

	\param regularpolygon
	To call upon regularpolygon's data members/functions

*/
/******************************************************************************/
	template<typename T>
	void LoggingVisitor<T>::visit(RegularPolygon<T>& regularpolygon)
	{
		unsigned int j{};
		file_m << "\tRegular polygon" << std::endl;
		file_m << "\t\tPivot: " << "(" << regularpolygon._pivotPt.x()
			<< ", " << regularpolygon._pivotPt.y() << ")" << std::endl;
		for (auto& _pt : regularpolygon._npts)
		{
			file_m << "\t\tPoint[" << j++ << "]: "
				<< "(" << _pt.x() << ", "
				<< _pt.y() << ")"
				<< std::endl;
		}
		file_m << "\t\tColor: " << "("
			<< static_cast<size_t>(regularpolygon.color().red()) << ", "
			<< static_cast<size_t>(regularpolygon.color().green()) << ", "
			<< static_cast<size_t>(regularpolygon.color().blue()) << ")"
			<< std::endl;
	}
/******************************************************************************/
/*!
	\brief
	Destructor to close file

*/
/******************************************************************************/
	template<typename T>
	LoggingVisitor<T>::~LoggingVisitor()
	{
		file_m.close();
	}
}
