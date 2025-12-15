#include "Magician.h"

Magician::Magician(string nickname) : Player("법성", nickname, 10, 50, 200, 200, 30, 100, 70)
{
}

void Magician::attack()
{
	cout << "도트 퍼니셔" << endl;
}