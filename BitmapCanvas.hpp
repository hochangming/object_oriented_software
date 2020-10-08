#include "BitmapCanvas.h"

#include <iostream>
#include <fstream>

namespace cs225
{
	template <typename Vector2D>
	BitmapCanvas<Vector2D>::BitmapCanvas(std::size_t width, std::size_t height)
	{
		_color = RGB(0, 0, 0);
		
		_context = CreateCompatibleDC(nullptr);
		ZeroMemory(&_bitmapInfo, sizeof(_bitmapInfo));
		
		BITMAPINFOHEADER& bmiHeader = _bitmapInfo.bmiHeader;
		bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bmiHeader.biWidth = static_cast<LONG>(width);
		bmiHeader.biHeight = static_cast<LONG>(height);
		bmiHeader.biPlanes = 1;
		bmiHeader.biBitCount = 24;
		bmiHeader.biCompression = BI_RGB;
		
		_bitmap = CreateDIBSection(_context, &_bitmapInfo, DIB_RGB_COLORS, &_bitmapData, nullptr, 0);
		SelectObject(_context, _bitmap);
	}
	
	template <typename Vector2D>
	BitmapCanvas<Vector2D>::~BitmapCanvas()
	{
		const HGDIOBJ old = SelectObject(_context, GetStockObject(NULL_BRUSH));
		DeleteObject(old);
		DeleteDC(_context);
		DeleteObject(_bitmap);
	}
		
	template <typename Vector2D>
	void BitmapCanvas<Vector2D>::color(const Color& color)
	{
		_color = RGB(
			color.red(),
			color.green(),
			color.blue()
		);
	}
		
	template <typename Vector2D>
	void BitmapCanvas<Vector2D>::drawPixel(const point2D& point)
	{
		SetPixel(_context, point.first, point.second, _color);
	}
	
	template <typename Vector2D>
	void BitmapCanvas<Vector2D>::drawPolygon(const std::vector<point2D>& points)
	{
		std::vector<POINT> vertices;
		vertices.reserve(points.size());
		for (const point2D& point : points)
		{
			vertices.push_back({
				static_cast<LONG>(point.first),
				static_cast<LONG>(point.second)
			});
		}
		const HGDIOBJ oldBrush = SelectObject(_context, CreateSolidBrush(_color));
		DeleteObject(oldBrush);
		::Polygon(_context, vertices.data(), static_cast<int>(vertices.size()));
	}
	
	template <typename Vector2D>
	void BitmapCanvas<Vector2D>::drawEllipse(const point2D& topLeft, const point2D& bottomRight)
	{
		const HGDIOBJ oldBrush = SelectObject(_context, CreateSolidBrush(_color));
		DeleteObject(oldBrush);
		Ellipse(_context, topLeft.first, topLeft.second, bottomRight.first, bottomRight.second);
	}
	
	template <typename Vector2D>
	void BitmapCanvas<Vector2D>::drawRectangle(const point2D& topLeft, const point2D& bottomRight)
	{
		const RECT rect{topLeft.first, topLeft.second, bottomRight.first, bottomRight.second};
		const HBRUSH newBrush = CreateSolidBrush(_color);
		const HGDIOBJ oldBrush = SelectObject(_context, newBrush);
		DeleteObject(oldBrush);
		FillRect(_context, &rect, newBrush);
	}
	
	template <typename Vector2D>
	void BitmapCanvas<Vector2D>::save(const std::string& fileName) const
	{
		static const WORD bfType = 'B' + ('M' << 8);
		static const DWORD bfOffBits = static_cast<DWORD>(
			sizeof(BITMAPFILEHEADER) +
			sizeof(BITMAPINFOHEADER)
		);
		
		const std::size_t width = _bitmapInfo.bmiHeader.biWidth;
		const std::size_t height = _bitmapInfo.bmiHeader.biHeight;
		const std::size_t rowData = (24 / 8) * width;
		const std::size_t rowPadding = (rowData % 4 != 0)
			? (4 - rowData % 4)
			: 0;
		const std::size_t stride = rowData + rowPadding;
		std::ofstream file{fileName, std::ios_base::binary | std::ios_base::out};
		if (!file)
		{
			throw std::string{"Unable to open a bitmap file."};
		}
		
		BITMAPFILEHEADER bmfh;
		ZeroMemory(&bmfh, sizeof(bmfh));
		bmfh.bfType = bfType;
		bmfh.bfOffBits = bfOffBits;
		bmfh.bfSize = bfOffBits + static_cast<DWORD>(stride * height);
		if (!file.write(reinterpret_cast<const char*>(&bmfh), sizeof(bmfh)))
		{
			throw std::string{"Unable to write a bitmap file header."};
		}
		if (!file.write(reinterpret_cast<const char*>(&_bitmapInfo.bmiHeader), sizeof(_bitmapInfo.bmiHeader)))
		{
			throw std::string{"Unable to write a bitmap info header."};
		}

		const char* data = reinterpret_cast<const char*>(_bitmapData);
		const char paddingBuffer[3] = {0};
		std::size_t written = 0;
		for (std::size_t h = 0; h < height; ++h)
		{
			if (!file.write(data + written, rowData))
			{
				throw std::string{"Unable to write bitmap data."};
			}
			written += rowData;
			if (stride > rowData)
			{
				if (!file.write(paddingBuffer, rowPadding))
				{
					throw std::string{"Unable to write bitmap padding."};
				}
			}
		}
		if (written != (width * height * (24 / 8)))
		{
			throw std::string{"Unable to write all bitmap data."};
		}
	}
	
	template <typename Vector2D>
	void BitmapCanvas<Vector2D>::load(
		const std::string& fileName,
		std::size_t& width,
		std::size_t& height,
		std::vector<Color>& colors
	)
	{
		static const WORD bfType = 'B' + ('M' << 8);
		static const DWORD bfOffBits = static_cast<DWORD>(
			sizeof(BITMAPFILEHEADER) +
			sizeof(BITMAPINFOHEADER)
		);
		
		std::ifstream file{fileName, std::ios_base::binary | std::ios_base::in};
		if (!file)
		{
			throw std::string{"Unable to open a bitmap file."};
		}
		
		BITMAPFILEHEADER bmfh;
		if (!file.read(reinterpret_cast<char*>(&bmfh), sizeof(bmfh)))
		{
			throw std::string{"Unable to read a bitmap file header."};
		}
		if (bmfh.bfType != bfType)
		{
			throw std::string{"Unsupported file header format."};
		}
		if (bmfh.bfOffBits != bfOffBits)
		{
			throw std::string{"Unsupported file header format."};
		}
		
		BITMAPINFOHEADER bmih;
		if (!file.read(reinterpret_cast<char*>(&bmih), sizeof(bmih)))
		{
			throw std::string{"Unable to read a bitmap info header."};
		}
		if (bmih.biSize != sizeof(BITMAPINFOHEADER))
		{
			throw std::string{"Unsupported info header format."};
		}
		if (bmih.biPlanes != 1)
		{
			throw std::string{"Unsupported info header format."};
		}
		if (bmih.biCompression != BI_RGB)
		{
			throw std::string{"Unsupported info header format."};
		}
		if (bmih.biBitCount != 24)
		{
			throw std::string{"Unsupported info header format."};
		}
		
		width = static_cast<std::size_t>(bmih.biWidth);
		height = static_cast<std::size_t>(bmih.biHeight);
		
		const std::size_t rowData = (24 / 8) * width;
		const std::size_t rowPadding = (rowData % 4 != 0)
			? (4 - rowData % 4)
			: 0;
		const std::size_t stride = rowData + rowPadding;
		if (bmfh.bfSize != bmfh.bfOffBits + static_cast<DWORD>(stride * height))
		{
			throw std::string{"Unsupported file header format."};
		}
		std::vector<char> bitmapData;
		bitmapData.resize(stride * height);
		char* const data = bitmapData.data();
		char paddingBuffer[4];
		std::size_t read = 0;
		for (std::size_t h = 0; h < height; ++h)
		{
			if (!file.read(data + read, rowData))
			{
				throw std::string{"Unable to read bitmap data."};
			}
			read += rowData;
			if (stride > rowData)
			{
				if (!file.read(paddingBuffer, rowPadding))
				{
					throw std::string{"Unable to read bitmap padding."};
				}
			}
		}
		colors.clear();
		colors.reserve(width * height);
		for (std::size_t i = 0; i < bitmapData.size(); i += 3)
		{
			using component = unsigned char;
			const component r = static_cast<component>(bitmapData[2 + i]);
			const component g = static_cast<component>(bitmapData[1 + i]);
			const component b = static_cast<component>(bitmapData[0 + i]);
			colors.push_back(Color{r, g, b});
		}
	}
}
