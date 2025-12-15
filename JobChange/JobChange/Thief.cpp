#include "Thief.h"

Thief::Thief(string nickname) : Player("살성", nickname, 10, 80, 150, 150, 90, 100, 200)
{
}

void Thief::attack()
{
	cout << "암살" << endl;
}