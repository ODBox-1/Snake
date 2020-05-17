#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct listNode
{
	int x;
	int y;
	struct listNode* next;
}listNode;

typedef struct snake {
	listNode* snakeHead;
	int directionX;
	int directionY;
}snake;

void init(void);
void gotoxy(int x, int y);
void sleep(float secs);
void printBoard();
snake* initSnake();
void initDirection(int x, int y, snake* headOfSnake);
void initListNode(int x, int y, listNode* node);
void printSnake(listNode* node);
void updateSnake(snake* snake);
void clearSnake(snake* node);
void addNewNode(snake* snake);
bool gameOver(snake* snake);
void printGameOver();

