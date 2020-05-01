#include "Cells.h"

void Cells::DrawCells(Graphics& GFX, Cells cellboard[mazeSizeHeight][mazeSizeWidth])
{

	/*for (int i = 0; i < mazeSizeHeight; i++) {
		for (int j = 0; j < mazeSizeWidth; j++) {
			const int topCoordinate = i * cellsize;
			const int leftCoordinate = j * cellsize;
			for (int k = topCoordinate + wallsize; k < (topCoordinate + wallsize + cellsize - 2 * wallsize); k++)
			{
				for (int l = leftCoordinate + wallsize; l < (leftCoordinate + wallsize + cellsize - 2 * wallsize); l++) {
					GFX.PutPixel(l, k, Colors::Blue);
				}
			}
		}

	}*/

	for (int i = 0; i < mazeSizeHeight; i++) {
		for (int j = 0; j < mazeSizeWidth; j++) {
			const int topCoordinate = i * cellsize;
			const int leftCoordinate = j * cellsize;
			const int topWall = cellboard[i][j].topWall;
			const int bottomWall = cellboard[i][j].bottomWall;
			const int leftWall = cellboard[i][j].leftWall;
			const int rightWall = cellboard[i][j].rightWall;


			for (int k = topCoordinate + wallsize * topWall; k < (topCoordinate + cellsize - bottomWall * wallsize); k++)
			{
				for (int l = leftCoordinate + wallsize * leftWall; l < (leftCoordinate + cellsize - rightWall * wallsize); l++) {

					GFX.PutPixel(l, k, Colors::White);
				}
			}

		}
	}





}

void Cells::DrawCurrentCell(Graphics& GFX, Vei2 cell, Color c)
{
	const int topCoordinate = cell.y * cellsize;
	const int leftCoordinate = cell.x * cellsize;
	


	for (int k = topCoordinate + wallsize ; k < (topCoordinate + cellsize - wallsize); k++)
	{
		for (int l = leftCoordinate + wallsize ; l < (leftCoordinate + cellsize - wallsize); l++) {

			GFX.PutPixel(l, k, c);
		}
	}
}
