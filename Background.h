/******************************************************************************/
/*!
\file   Background.h
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
width					- A width getter function.
height					- A height getter function.
colorData				- A getter function for Color data.
clone					- A clone() function used for covariant return types
accept					- An accept visitor function for double dispatching

Hours spent on this assignment: 8
Specific portions that gave you the most trouble: Commenting file headers.
*/
/******************************************************************************/
#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "IVisitable.h"
#include "color.h"
#include "IShape.h"
#include "ICloneable.h"
#include "IVisitor.h"
#include<vector>

namespace cs225
{
 	template <typename T>
	class Background : public IVisitable<T>, public IShape<T>
	{
	public:
		//type alias
		using pixelCount = unsigned int;
		//Conversion constructor
		Background(const pixelCount& width, 
		const pixelCount& height, const Color* color);
		//width function
		pixelCount width() const;
		//height function
		pixelCount height() const;
		//colorData function
		const Color* colorData() const;
		//accept visitor function
		void accept(IVisitor<T>& visitor) override;

	private:
		//Data Members 
		pixelCount _width;
		pixelCount _height;
		std::vector<Color> pdata_;
	};

}

#include "Background.hpp"
#endif
