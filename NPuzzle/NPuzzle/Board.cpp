#include <iostream>
#include <string>
#include <time.h>

#include "Board.h"

using namespace std;

Board::Board(int size)
{
	this->size = size;
	blocks = new Block[size*size];

	for (int i = 0; i < (size*size); i++)
	{
		blocks[i].setValue(i);
	}

	randomizeBoard();
}

Board::~Board()
{
	delete blocks;
}

void Board::printBoard()
{
	for (int i = 0; i < (size*size); i++)
	{
		
		blocks[i].print();

		if ((i%size) == size - 1)
			cout << endl;
	}
}

void Board::randomizeBoard()
{
	srand((int)time(NULL));
	int numOfSwaps = 100;

	for (int i = 0; i < numOfSwaps; i++)
	{
		switch (rand() % 4)
		{
		case 0:
			moveUp();
			break;
		case 1:
			moveDown();
			break;
		case 2:
			moveLeft();
			break;
		case 3:
			moveRight();
			break;
		}
	}
}

void Board::swap(int indexOne, int indexTwo)
{
	Block tmpBlock = blocks[indexOne];
	blocks[indexOne] = blocks[indexTwo];
	blocks[indexTwo] = tmpBlock;

}

void Board::moveUp()
{
	int emptyBlock = findEmptyBlock();

	if (emptyBlock - size >= 0)
		swap(emptyBlock, emptyBlock - size);
}

void Board::moveDown()
{
	int emptyBlock = findEmptyBlock();

	if (emptyBlock + size < (size*size))
		swap(emptyBlock, emptyBlock + size);
}

void Board::moveLeft()
{
	int emptyBlock = findEmptyBlock();

	if ((emptyBlock-1)%size < emptyBlock%size && emptyBlock > 0)
		swap(emptyBlock, emptyBlock - 1);
}

void Board::moveRight()
{
	int emptyBlock = findEmptyBlock();

	if ((emptyBlock + 1) % size > emptyBlock % size && emptyBlock < (size*size)-1)
		swap(emptyBlock, emptyBlock + 1);
}

int Board::findEmptyBlock()
{
	for (int i = 0; i < (size*size); i++)
	{
		if (blocks[i].getValue() == 0)
			return i;
	}
	return -1;
}

bool Board::isSorted()
{

	for (int i = 0; i < size*size; i++)
	{
		if (blocks[i].getValue() != i + 1 && i < (size*size)-1)
			return false;
	}

	return true;

}