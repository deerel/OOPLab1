#ifndef BOARD_H
#define BOARD_H

#include "Block.h"

class Board
{
private:
	int size;
	Block *blocks;
	void randomizeBoard();
	void swap(int, int);
	int findEmptyBlock();
public:
	Board(int);
	~Board();
	void printBoard();
	bool isSorted();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

#endif