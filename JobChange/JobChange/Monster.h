#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player;

class Monster
{
private:
    string name;    // 몬스터의 이름
    int MAX_HP;     // 몬스터의 MAX_HP
    int HP;         // 몬스터의 HP
    int power;      // 몬스터의 공격력
    int defence;    // 몬스터의 방어력
    int speed;      // 몬스터의 스피드
    
public:
    Monster(string _name);
    void takeDamage(int damage);
    void attack(Player* player);
    bool isDead(int HP);


    // 몬스터의 속성값을 리턴하는 get 함수
    string getName();
    int getHP();
    int getPower();
    int getDefence();
    int getSpeed();

    // 몬스터의 속성값을 정의하는 set 함수
    void setName(string name);
    void setHP(int HP);
    void setPower(int power);
    void setDefence(int defence);
    void setSpeed(int speed);
};