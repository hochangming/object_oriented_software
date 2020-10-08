/******************************************************************************/
/*!
\file   Background.hpp
\author Ho Chang Ming
\par    email: changming.h\@digipen.edu
\par    CS 225
\par    Assignment #2
\date   28/06/2020

\brief
This file contains a definition of the templated class background
and declarations of its member functions.


Functions included:
Background				- Conversion constructor
height					- A height getter function.
width					- A width getter function.
colorData				- A getter function for Color data.
clone					- A clone() function used for covariant return types
accept					- An accept visitor function for double dispatching
~background				- A destructor for background to free memory

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/
#include "Background.h"

namespace cs225
{
/******************************************************************************/
/*!
  \brief
	Conversion Constructor to construct background object

  \param width
	Int value which holds width of background

  \param height
	Int value which holds height of background

  \param color
	A pointer to a Color type 
*/
/******************************************************************************/
	template <typename T>
	 Background<T>::Background(const pixelCount& width, 
		 const pixelCount& height, const Color* color)
		 : _width{ width }, _height{ height } 
	 {
		 for (unsigned int i{}; i < width*height; i++)
		 {
			 pdata_.push_back(color[i]);
		 }
	 }

/******************************************************************************/
/*!
	\brief
	A getter function for height of background object

*/
/******************************************************************************/
	 template <typename T>
	 typename Background<T>::pixelCount Background<T>::height() const
	 {
		 return _height;
	 }

/******************************************************************************/
/*!
	\brief
	A getter function for width of background object

*/
/******************************************************************************/
	template <typename T>
	typename Background<T>::pixelCount Background<T>::width() const
	{
		return _width;
	}

/******************************************************************************/
/*!
	\brief
	A getter function for colorData
*/
/******************************************************************************/
	template <typename T>
	const Color* Background<T>::colorData() const
	{
		return pdata_.data();
	}

/******************************************************************************/
/*!
	\brief
	An accept visitor function for Background used for double dispatching

*/
/******************************************************************************/
	template <typename T>
	void Background<T>::accept(IVisitor<T>& visitor)
	{
		visitor.visit(*this);
	}

}
