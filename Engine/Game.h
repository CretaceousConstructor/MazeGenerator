/******************************************************************************************
*	Chili DirectX Framework Version 16.10.01											  *
*	Game.h																				  *
*	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
*																						  *
*	This file is part of The Chili DirectX Framework.									  *
*																						  *
*	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
*	it under the terms of the GNU General Public License as published by				  *
*	the Free Software Foundation, either version 3 of the License, or					  *
*	(at your option) any later version.													  *
*																						  *
*	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
*	GNU General Public License for more details.										  *
*																						  *
*	You should have received a copy of the GNU General Public License					  *
*	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
******************************************************************************************/
#pragma once

#include <vector>
#include "Graphics.h"
#include "Vec2.h"
#include "ChiliMath.h"
#include "Snow.h"
#include "Character.h"
#include "Timer.h"
#include "Cells.h"

#include <random>
#include <stack>
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	//~Game() = default;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Timer clock;
	bool visited[Cells::mazeSizeHeight][Cells::mazeSizeWidth] = {false};
	Cells cellBoard[Cells::mazeSizeHeight][Cells::mazeSizeWidth];
	Vei2 startPosition;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> cellDist;
	std::stack<Vei2> stack;
	int visitedCount = 0;
	Character link;
	Vei2 currentCell;
private:
	 void hasPath();
	 bool allVisited(const Vei2& current);
	 bool testVisited(int direction,const Vei2& current);
	/********************************/
};

