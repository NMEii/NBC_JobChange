#include "Archer.h"
#include "Monster.h"

Archer::Archer(string nickname) : Player("궁수", nickname, 10, 80, 120, 150, 100, 200, 150)
{
}

void Archer::attack()
{
	cout << "에로우 레인" << endl;
}

void Archer::attack(Monster* monster)
{
	int finalDamage = getPower() - monster->getDefence();
	int damagedivide = finalDamage / 3;

	if (damagedivide < 0) damagedivide = 1;   // 데미지가 음수 일 때 1으로 변환.

	for (int i = 0; i < 3; i++)
	{
		cout << monster->getName() << " 에게 " << damagedivide << " 데미지를 입혔다." << endl;
		monster->takeDamage(damagedivide);
	}
}
