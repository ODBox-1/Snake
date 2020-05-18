#include <stdio.h>
#include "funcDec.h"


// Moves the cursor to position (x,y) on screen.
// Parameters:
//     x: the row of the posiiton.
//     y: the column of the posiiton.
void gotoxy(int x, int y) {
	printf("\x1b[%d;%df", x, y);
}

//This function initialized the direction of the snake. 
void initDirection(int x, int y, snake* headOfSnake)
{
	headOfSnake->directionX = x;
	headOfSnake->directionY = y;
}