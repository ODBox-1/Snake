#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "funcDec.h"

int main() {
	snake* snake;
	bool isGameOver = false, gameOverPrinted = true;
	double delaySecs = 1;
	char ch;
	init();
	printBoard();
	snake = initSnake();
	while (!isGameOver)
	{
		for (int i = 0; i < 5; i++) {
			if(_kbhit())
			{
				ch = _getch();
				switch (ch)
				{
				case 'a':
					snake->directionX = -1;
					snake->directionY = 0;
					break;
				case 's':
					snake->directionX = 0;
					snake->directionY = 1;
					break;
				case 'd':
					snake->directionX = 1;
					snake->directionY = 0;
					break;
				case 'w':
					snake->directionX = 0;
					snake->directionY = -1;
					break;
				default:
					break;
				}
			}
			isGameOver = gameOver(snake);
			if (!isGameOver)
				updateSnake(snake);
			else {
				gameOverPrinted = false; 
				printGameOver();
				break;
			}
			sleep(delaySecs);
		}
		if (!gameOver(snake))
			addNewNode(snake);
		else 
			if(gameOverPrinted){
				printGameOver();
				break;
		}
		if (delaySecs >= 0.1)
			delaySecs -= 0.03;
	}	
}

