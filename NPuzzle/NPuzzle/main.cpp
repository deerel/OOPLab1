#include <iostream>
#include <conio.h>
#include "Board.h"

using namespace std;

int main() {

	int boardSize = 10;
	Board *board = new Board(boardSize);
	char userInput = NULL;

	while (true)
	{

		board->printBoard();

		char userInput = _getch();
		
		switch (userInput)
		{
		case 'w':
		case 'W':
		case 80:
			board->moveUp();
			break;
		case 's':
		case 'S':
		case 72:
			board->moveDown();
			break;
		case 'a':
		case 'A':
		case 77:
			board->moveLeft();
			break;
		case 'd':
		case 'D':
		case 75:
			board->moveRight();
			break;
		default:
			break;
		}

		system("cls");
		if (board->isSorted() == true)
		{
			break;
		}

	}
	board->printBoard();
	cout << "You Won!" << endl << "Press the any key to quit.";

	_getch();
	return 0;
}