#pragma once

#include "Graphics.h"
#include "Colors.h"
#include "Vec2.h"

class Cells {
public:

	static constexpr int cellsize = 35;
	static constexpr int wallsize = 1;
	static constexpr int mazeSize = (Graphics::ScreenHeight / cellsize) * (Graphics::ScreenWidth / cellsize);

	static constexpr int mazeSizeHeight = (Graphics::ScreenHeight / cellsize);
	static constexpr int mazeSizeWidth = (Graphics::ScreenWidth / cellsize);

	static void DrawCells(Graphics& GFX ,Cells cellboard[mazeSizeHeight][mazeSizeWidth]);
	static void DrawCurrentCell(Graphics& GFX,Vei2 cell, Color c );

	int leftWall = 1;
	int rightWall = 1;
	int topWall = 1;
	int bottomWall = 1;


};
