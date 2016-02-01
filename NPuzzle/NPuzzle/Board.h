#ifndef BOARD_H
#define BOARD_H

#include "Block.h"

class Board
{
private:
	int size;
	Block *blocks;
	void randomizeBoard();
public:
	Board();
	~Board();
	void printBoard();
	bool isSorted();
	void makeMove(char);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void swap(int, int);
	int findEmptyBlock();
};

#endif