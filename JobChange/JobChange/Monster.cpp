#include "Monster.h"
#include "Player.h"


Monster::Monster(string _name) : 
	name(_name),
	HP(200),
	MAX_HP(200),
	power(30), 
	defence(10), 
	speed(10)
{

}

void Monster::takeDamage(int finalDamage)
{

	HP -= finalDamage;                      // 데미지 계산

	if (HP < 0) HP = 0;                     // 체력이 0 밑은 다 0으로 인식

	cout << name
		<< " 이(가) "
		<< finalDamage << " 피해를 입었다. (HP : "
		<< HP << " / " << MAX_HP << ")\n";
}

void Monster::attack(Player* player)
{
	cout << name << " 이(가) 플레이어를 공격했다.\n";
	player->takeDamage(power);
}

bool Monster::isDead(int HP)
{
	return HP <= 0;
}

string Monster::getName()
{
	return name;
}

int Monster::getHP()
{
	return HP;
}

int Monster::getPower()
{
	return power;
}

int Monster::getDefence()
{
	return defence;
}

int Monster::getSpeed()
{
	return speed;
}

void Monster::setName(string name)
{
	this->name = name;
}

void Monster::setHP(int HP)
{
	this->HP = HP;
}

void Monster::setPower(int power)
{
	this->power = power;
}

void Monster::setDefence(int defence)
{
	this->defence = defence;
}

void Monster::setSpeed(int speed)
{
	this->speed = speed;
}

