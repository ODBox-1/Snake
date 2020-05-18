#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "funcDec.h"

// Turn escape codes ON.
void init(void) {
	system("cls");
}

// Delays the execution of the program.
// Parameters:
//     secs: the length of the delay in seconds. 
void sleep(float secs) {
	clock_t clocks_start = clock();

	while (clock() - clocks_start < secs*CLOCKS_PER_SEC)
		;
}


//This function initialized the first cell of the linked list
snake* initSnake()
{
	snake* headOfSnake;
	headOfSnake = (snake*)malloc(sizeof(snake));
	if (!headOfSnake)
	{
		printf("Error allocating memory: could not create node");
		return;
	}
	headOfSnake->snakeHead = (listNode*)malloc(sizeof(listNode));
	if (!headOfSnake->snakeHead)
	{
		printf("Error allocating memory: could not create node");
		return;
	}
	initDirection(1, 0, headOfSnake);
	initListNode(13, 37, headOfSnake->snakeHead);
	printSnake(headOfSnake->snakeHead);
	return headOfSnake;
}

//This function initialized the last cell of the linked list.
void initListNode(int x, int y, listNode* node)
{
	node->x = x;
	node->y = y;
	node->next = NULL;
}

//This function update the snake - it clears from the board the first cell of the linked list,
//adds a new cell at the tail of the snake, and free the previous head of the snake from the memory. 
void updateSnake(snake* snake) {
	clearSnake(snake);
	addNewNode(snake);
	listNode* temp = snake->snakeHead;
	snake->snakeHead = snake->snakeHead->next;
	free(temp);
}

// This function adds a new node to the tail of the linked list, 
//and positioning it according to the direction of the snake. 
void addNewNode(snake* snake)
{
	listNode* tail = snake->snakeHead;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = (listNode*)malloc(sizeof(listNode));
	initListNode(tail->x + (snake->directionY), tail->y + (snake->directionX), tail->next);
	printSnake(tail->next);
}