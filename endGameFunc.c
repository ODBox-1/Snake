#include <stdio.h>
#include <stdbool.h>
#include "funcDec.h"



//This function checks if the game is over. 
bool gameOver(snake* snake)
{
	listNode* tail = snake->snakeHead;
	listNode* temp = snake->snakeHead;
	while (tail->next != NULL)
		tail = tail->next;
	if (tail->x == 0 || tail->x == 25) // Border exception
		return true;
	if (tail->y == 0 || tail->y == 75) // Border exception
		return true;
	while (temp->next != NULL) // If the snake hits itself
	{
		if (tail->x == temp->x && tail->y == temp->y)
			return true;
		temp = temp->next;
	}
	return false;
}

//This function prints Game Over
void printGameOver()
{
	init();
	printBoard();
	gotoxy(13, 37);
	printf("GAME OVER");
	gotoxy(26, 0);
}