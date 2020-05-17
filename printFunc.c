#include <stdio.h>
#include "funcDec.h"


//This function prints the board. 
void printBoard()
{
	for (int i = 0; i < 25;i++)
	{
		for (int j = 0; j < 75; j++)
		{
			if (i == 0 || i == 24)
				printf("#");
			else
			{
				if (j == 0 || j == 74)
					printf("#");
				else
					printf(" ");
			}
		}
		printf("\n");
	}
}

//This function prints the snake
void printSnake(listNode* node)
{
	gotoxy(node->x, node->y);
	printf("@");
}

//This function clears from the board the first cell of the linked list.
void clearSnake(snake* node)
{
	gotoxy(node->snakeHead->x, node->snakeHead->y);
	printf(" ");
}