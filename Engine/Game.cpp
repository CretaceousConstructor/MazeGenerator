/******************************************************************************************
*	Chili DirectX Framework Version 16.10.01											  *
*	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
#include "Mat2.h"
#include <stack>

Game::Game(MainWindow& wnd) :
	wnd(wnd),
	gfx(wnd),
	startPosition(0, 0),
	cellDist(0, 3),
	rng(rd()),
	link("D:\\CS\\ComputerGraphics\\PackMan\\Bmp\\images.bmp", 4, 5, Vec2{50.f,50.f})
{

	stack.push(startPosition);
	visited[startPosition.y][startPosition.x] = true;
	++visitedCount;
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	
	if (visitedCount < Cells::mazeSize) {
		if (!stack.empty()) {
			currentCell = stack.top();
			if (allVisited(currentCell)) {
				stack.pop();
				if( !stack.empty() ) {
					currentCell = stack.top();
					if (!allVisited(currentCell)) {
						hasPath();
					}
					else
					{
						stack.pop();
					}
				}
			}
			else 
			{
				hasPath();
			}
			
		}
	}

}



void Game::hasPath() {
	Vei2 testCell;
	int choice;
	Vei2 currentCell = stack.top();
	while (testVisited((choice = cellDist(rng)), currentCell));
	switch (choice)
	{
	case 0:
		testCell = { currentCell.x,currentCell.y - 1 };

		cellBoard[currentCell.y][currentCell.x].topWall =0;
		cellBoard[currentCell.y - 1][currentCell.x].bottomWall = 0;



		visited[testCell.y][testCell.x] = true;
		++visitedCount;
		stack.push(testCell);
		break;
	case 1:
		testCell = { currentCell.x + 1,currentCell.y };



		cellBoard[currentCell.y][currentCell.x].rightWall = 0;
		cellBoard[currentCell.y][currentCell.x + 1].leftWall = 0;



		visited[testCell.y][testCell.x] = true;
		++visitedCount;
		stack.push(testCell);
		break;
	case 2:
		testCell = { currentCell.x,currentCell.y + 1 };


		cellBoard[currentCell.y][currentCell.x].bottomWall = 0;
		cellBoard[currentCell.y + 1][currentCell.x].topWall = 0;

		visited[testCell.y][testCell.x] = true;
		++visitedCount;
		stack.push(testCell);
		break;
	case 3:
		testCell = { currentCell.x - 1,currentCell.y };

		cellBoard[currentCell.y][currentCell.x].leftWall = 0;
		cellBoard[currentCell.y][currentCell.x-1].rightWall = 0;


		visited[testCell.y][testCell.x] = true;
		++visitedCount;
		stack.push(testCell);
		break;
	default:
		break;
	}
}

bool Game::allVisited(const Vei2& current)
{

	

	int clippedXRigth;
	int clippedYBottom;
	int clippedXLeft;
	int clippedYTop;


	if (current.x + 1 >= Cells::mazeSizeWidth) {
		clippedXRigth = current.x;
	}
	else {
		clippedXRigth = current.x + 1;
	}


	if (current.y + 1 >= Cells::mazeSizeHeight) {
		clippedYBottom = current.y;
	}
	else {
		clippedYBottom = current.y + 1;
	}



	if (current.x - 1 < 0) {
		clippedXLeft = current.x;
	}
	else {
		clippedXLeft = current.x - 1;
	}


	if (current.y - 1 < 0) {
		clippedYTop = current.y;
	}
	else {
		clippedYTop = current.y - 1;
	}

	if (
		visited[clippedYTop][current.x] &&
		visited[ current.y][clippedXRigth] &&
		visited[ clippedYBottom] [current.x]&&
		visited[ current.y][clippedXLeft]
		)
	{
		return true;
	}
	else {
		return false;
	}

}

bool Game::testVisited(int direction, const Vei2& currentCell)
{


	int clippedXRigth;
	int clippedYBottom;
	int clippedXLeft;
	int clippedYTop;

	if (currentCell.x + 1 >= Cells::mazeSizeWidth) {
		clippedXRigth = currentCell.x;
	}
	else {
		clippedXRigth = currentCell.x + 1;
	}
	if (currentCell.y + 1 >= Cells::mazeSizeHeight) {
		clippedYBottom = currentCell.y;
	}
	else {
		clippedYBottom = currentCell.y + 1;
	}

	if (currentCell.x - 1 < 0) {
		clippedXLeft = currentCell.x;
	}
	else {
		clippedXLeft = currentCell.x - 1;
	}
	if (currentCell.y - 1 < 0) {
		clippedYTop = currentCell.y;
	}
	else {
		clippedYTop = currentCell.y - 1;
	}




	switch (direction)
	{
	case 0:
		return visited[clippedYTop][currentCell.x];
	case 1:
		return visited[currentCell.y ][clippedXRigth ];
	case 2:
		return visited[clippedYBottom ][currentCell.x ];
	case 3:
		return visited[currentCell.y][clippedXLeft];
	default:
		break;
	}

	return false;
}


void Game::ComposeFrame()
{


	
	
	Cells::DrawCells(gfx, cellBoard);
	Cells::DrawCurrentCell(gfx, currentCell,Colors::Red);



}