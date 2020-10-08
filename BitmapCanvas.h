#ifndef _BITMAPCANVAS_H_
#define _BITMAPCANVAS_H_

#include <string>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "Color.h"
#include "IColoredShape.h"

namespace cs225
{
	template <typename Vector2D>
	class BitmapCanvas
	{
	public:
		using point2D = std::pair<int, int>;
	
		BitmapCanvas(std::size_t width, std::size_t height);
		~BitmapCanvas();
		
		void color(const Color& color);
		
		void drawPixel(const point2D& point);
		void drawEllipse(const point2D& topLeft, const point2D& bottomRight);
		void drawRectangle(const point2D& topLeft, const point2D& bottomRight);
		void drawPolygon(const std::vector<point2D>& points);

		void save(const std::string& fileName) const;
		
		static void load(
			const std::string& fileName,
			std::size_t& width,
			std::size_t& height,
			std::vector<Color>& colors
		);

	private:
		BITMAPINFO _bitmapInfo;
		void* _bitmapData;
		HBITMAP _bitmap;
		HDC _context;
		COLORREF _color;
		
		static COLORREF convert(const Color& color);
		static COLORREF pickColor(const IColoredShape<Vector2D>& coloredShape);
	};
}

#include "BitmapCanvas.hpp"

#endif
