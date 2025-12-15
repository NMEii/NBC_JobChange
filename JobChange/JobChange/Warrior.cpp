#include "Warrior.h"

Warrior::Warrior(string nickname) : Player("°Ë¼º", nickname, 10, 200, 80, 100, 200, 100, 90)
{
}

void Warrior::attack()
{
	cout << "±Ã±×´Ò" << endl;
}