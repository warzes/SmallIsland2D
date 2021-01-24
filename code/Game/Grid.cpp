#include "stdafx.h"
#include "Grid.h"
//-----------------------------------------------------------------------------
Grid::Grid(float x, float y, float width, float height, int step, const Color& color)
	: mX(x)
	, mY(y)
	, mWidth(width)
	, mHeight(height)
	, mStep(step)
	, mColor(color)
{
	Vertices.resize(1 + 2 * (int)(width + height) / step);
	Indexes.resize(1 + 2 * (int)(width + height) / step);
	DrawType = D_LINES;

	buildVertices();
}
//-----------------------------------------------------------------------------
void Grid::buildVertices()
{
	int i = 0;

	for (int x = 0; x < (int)mWidth; x += mStep) 
	{
		Vertices[i].SetPos(x, 0);
		Vertices[i].SetColor(mColor);
		Indexes[i] = i;
		i++;
		Vertices[i].SetPos(x, mHeight);
		Vertices[i].SetColor(mColor);
		Indexes[i] = i;
		i++;
	}

	for (int y = 0; y < (int)mHeight; y += mStep) 
	{
		Vertices[i].SetPos(0, y);
		Vertices[i].SetColor(mColor);
		Indexes[i] = i;
		i++;
		Vertices[i].SetPos(mWidth, y);
		Vertices[i].SetColor(mColor);
		Indexes[i] = i;
		i++;
	}
}
//-----------------------------------------------------------------------------