#include "Player.h"

Player::Player(string job, string _nickname, int lev, int hp, int mp, int att, int def, int acc, int spd) 
    : 
    job_name(job),
    nickname(_nickname),
    level(lev),
    HP(hp),
    MP(mp),
    power(att),
    defence(def),
    accuracy(acc),
    speed(spd),
    MAX_HP(hp),
    MAX_MP(mp)
{
}

void Player::printPlayerStatus()
{
    cout << "------------------------------------" << endl;
    cout << "* 현재 능력치" << endl;
    cout << "닉네임: " << nickname << endl;
    cout << "Lv. " << level << endl;
    cout << "HP: " << HP << " / " << MAX_HP << endl;
    cout << "MP: " << MP << " / " << MAX_MP << endl;
    cout << "공격력: " << power << endl;
    cout << "방어력: " << defence << endl;
    cout << "정확도: " << accuracy << endl;
    cout << "속도: " << speed << endl;
    cout << "------------------------------------" << endl;
}

void Player::takeDamage(int damage)
{
    int finalDamage = damage - defence;

    if (finalDamage < 0) finalDamage = 0;   // 데미지가 음수 일 때 0으로 변환.

    HP -= finalDamage;                      // 데미지 계산

    if (HP < 0) HP = 0;                     // 체력이 0 밑은 다 0으로 인식

    cout << nickname
        << " 이(가) "
        << finalDamage << " 피해를 입었다. (HP : "
        << HP << " / " << MAX_HP << ")\n";
}

bool Player::isDead(int HP)
{
    return HP <= 0;
}

void Player::setNickname(string nickname)
{
    this->nickname = nickname;
}

void Player::setLevel(int Level)
{
    this->level = Level;
}

void Player:: setHP(int HP)
{
    this->HP = HP;
}

void Player:: setMP(int MP)
{
    this->MP = MP;
}

void Player:: setPower(int power)
{
    this->power = power;
}

void Player:: setDefence(int defence)
{
    this->defence = defence;
}

void Player:: setAccuracy(int accuracy)
{
    this->accuracy = accuracy;
}

void Player:: setSpeed(int speed)
{
    this->speed = speed;
}

string Player :: getJobName()
{
    return job_name;
}

string Player:: getNickname()
{
    return nickname;
}

int Player :: getLevel()
{
    return level;
}

int Player :: getHP()
{
    return HP;
}

int Player :: getMP()
{
    return MP;
}

int Player :: getPower()
{
    return power;
}

int Player :: getDefence()
{
    return defence;
}

int Player :: getAccuracy()
{
    return accuracy;
}

int Player :: getSpeed()
{
    return speed;
}
