#include "Magician.h"
#include "Monster.h"


Magician::Magician(string nickname) : Player("마법사", nickname, 10, 50, 200, 200, 30, 100, 70)
{
}

void Magician::attack()
{
	cout << "파이어 볼" << endl;
}

void Magician::attack(Monster* monster)
{
	int finalDamage = getPower() - monster->getDefence();
	
	if (finalDamage < 0) finalDamage = 1;   // 데미지가 음수 일 때 1으로 변환.

	cout << monster->getName() << " 에게 " << finalDamage << " 데미지를 입혔다." << endl;
	monster->takeDamage(finalDamage);
}
