#include <string>
#include <iostream>

using namespace std;

#include "Block.h"
void Block::print()
{
	string spacer;
	
	if (value / 10 <= 0)
		spacer = " ";
	else
		spacer = "";

	if (value == 0)
		cout << "[" << spacer << spacer << "]";
	else
		cout << "[" << spacer << value << "]";

}

void Block::setValue(int value)
{
	if (value >= 0)
		this->value = value;
}

int Block::getValue()
{
	return value;
}