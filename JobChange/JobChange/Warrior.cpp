#include "Warrior.h"
#include "Monster.h"

Warrior::Warrior(string nickname) : Player("전사", nickname, 10, 200, 80, 100, 200, 100, 90)
{
}

void Warrior::attack()
{
	cout << "전진 베기" << endl;
}

void Warrior::attack(Monster* monster)
{
	int finalDamage = getPower() - monster->getDefence();

	if (finalDamage < 0) finalDamage = 1;   // 데미지가 음수 일 때 1으로 변환.

	cout << monster->getName() << " 에게 " << finalDamage << " 데미지를 입혔다." << endl;
	monster->takeDamage(finalDamage);
}
