//Omer David
//ID: 308483437
//Project: Snake. 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// terminal escape codes/ANSI escape codes (or ANSI escape sequences)
// "\x1B" is the escape character that tells your terminal that what comes next is not meant to be printed on the screen, 
// but rather a command to the terminal (or most likely terminal emulatoion).

//--------------------------------STRUCTS-----------------------------------------

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

//--------------------------------FUNCTIONS DECLERATION-----------------------------

// Turn escape codes ON.
void init(void);

// Moves the cursor to position (x,y) on screen.
// Parameters:
//     x: the row of the posiiton.
//     y: the column of the posiiton.
void gotoxy(int x, int y);

// Delays the execution of the program.
// Parameters:
//     secs: the length of the delay in seconds. 
void sleep(float secs);

//This function prints the board.
void printBoard();

//This function initialized the fisrt cell of the linked list
snake* initSnake();

//This function initialized the direction of the snake. 
void initDirection(snake* headOfSnake);

//This function initialized the last cell of the linked list.
void initListNode(int x,int y, listNode* node);

//This function prints the snake
void printSnake(snake* head);

//This function update the snake - it clears from the board the first cell of the linked list,
//adds a new cell at the tail of the snake, and free the previous head of the snake from the memory. 
void updateSnake(snake* snake);

//This function clears from the board the first cell of the linked list.
void clearSnake(snake* node);

// This function adds a new node to the tail of the linked list, 
//and positioning it acoording to the direction of the snake. 
void addNewNode(snake* snake);

//This function checks if the game is over. 
bool gameOver(snake* snake);

//This function prints Game Over.
void printGameOver();

//--------------------------------MAIN-----------------------------------------

int main() {
	snake* snake;
	bool flag=true, gameOverPrinted = true;
	double t = 1;
	char ch;
	init();
	printBoard();
	snake=initSnake();
	while (flag)
	{
		for (int i = 0;i < 5;i++) {
			if(_kbhit())
			{
				ch=_getch();
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
			flag = gameOver(snake);
			if (flag)
				updateSnake(snake);
			else {
				gameOverPrinted = false; 
				printGameOver();
				break;
			}
			sleep(t);
		}
		if (gameOver(snake))
			addNewNode(snake);
		else 
			if(gameOverPrinted){
				printGameOver();
				break;
		}
		if (t >= 0.1)
			t -= 0.03;
	}	
}


//--------------------------------FUNCTIONS REALIZATION-----------------------------------------


// Turn escape codes ON.
void init(void) {
	system("cls");
}

// Moves the cursor to position (x,y) on screen.
// Parameters:
//     x: the row of the posiiton.
//     y: the column of the posiiton.
void gotoxy(int x, int y) {
	printf("\x1b[%d;%df", x, y);
}

// Delays the execution of the program.
// Parameters:
//     secs: the length of the delay in seconds. 
void sleep(float secs) {
	clock_t clocks_start = clock();

	while (clock() - clocks_start < secs*CLOCKS_PER_SEC)
		;
}

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

//This function initialized the fisrt cell of the linked list
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
	initListNode(13,37,headOfSnake->snakeHead);
	printSnake(headOfSnake->snakeHead);
	return headOfSnake;
}


//This function initialized the direction of the snake. 
void initDirection(int x, int y, snake* headOfSnake)
{
	headOfSnake->directionX = x;
	headOfSnake->directionY = y;
}


//This function initialized the last cell of the linked list.
void initListNode(int x,int y,listNode* node)
{
	node->x = x;
	node->y = y;
	node->next = NULL;
}

//This function prints the snake
void printSnake(listNode* node)
{
		gotoxy(node->x, node->y);
		printf("@");
}

//This function update the snake - it clears from the board the first cell of the linked list,
//adds a new cell at the tail of the snake, and free the previous head of the snake from the memory. 
void updateSnake(snake* snake){
	clearSnake(snake);
	addNewNode(snake);
	listNode* temp = snake->snakeHead;
	snake->snakeHead = snake->snakeHead->next;
	free(temp);
}

//This function clears from the board the first cell of the linked list.
void clearSnake(snake* node)
{
	gotoxy(node->snakeHead->x, node->snakeHead->y);
	printf(" ");
}

// This function adds a new node to the tail of the linked list, 
//and positioning it acoording to the direction of the snake. 
void addNewNode(snake* snake)
{ 
	listNode* tail = snake->snakeHead;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = (listNode*)malloc(sizeof(listNode));
	initListNode(tail->x + (snake->directionY), tail->y + (snake->directionX), tail->next);
	printSnake(tail->next);
}

//This function checks if the game is over. 
bool gameOver(snake* snake)
{
	listNode* tail = snake->snakeHead;
	listNode* temp = snake->snakeHead;
	while (tail->next != NULL)
		tail = tail->next;
	if (tail->x == 0 || tail->x == 25) // Border exception
		return false;
	if (tail->y == 0 || tail->y == 75) // Border exception
		return false;
	while (temp->next!=NULL) // If the snake hits itself. 
	{
		if (tail->x == temp->x && tail->y == temp->y)
			return false;
		temp = temp->next;
	}
	return true;
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