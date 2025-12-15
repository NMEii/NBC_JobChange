#include "Thief.h"
#include "Monster.h"

Thief::Thief(string nickname) : Player("도적", nickname, 10, 80, 150, 150, 90, 100, 200)
{
}

void Thief::attack()
{
	cout << "암살" << endl;
}

void Thief::attack(Monster* monster)
{
	int finalDamage = getPower() - monster->getDefence();
	int damagedivide = finalDamage / 5;

	if (damagedivide < 0) damagedivide = 1;   // 데미지가 음수 일 때 1으로 변환.

	for (int i = 0; i < 5; i++)
	{
		cout << monster->getName() << " 에게 " << damagedivide << " 데미지를 입혔다." << endl;
		monster->takeDamage(damagedivide);
	}
}
