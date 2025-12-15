#pragma once
#include <string>
#include <iostream>
using namespace std;

class Player
{
public:
	Player(string job, 
		string nickname, 
		int lev, 
		int hp, 
		int mp, 
		int att, 
		int def, 
		int acc, 
		int spd
	);
	virtual void attack() = 0;		// 순수 가상합수
	void printPlayerStatus();		// 스탯창

	string getJobName();
	string getNickname();
	int getLevel();
	int getHP();
	int getMP();
	int getPower();
	int getDefence();
	int getAccuracy();
	int getSpeed();

	// setter 함수
	void setNickname(string nickname);
	void setLevel(int Level);
	void setHP(int HP);
	void setMP(int MP);
	void setPower(int power);
	void setDefence(int defence);
	void setAccuracy(int accuracy);
	void setSpeed(int speed);


private:
	string job_name;		// 직업 이름
	string nickname;		// 닉네임
	int level;				// 레벨
	int HP;					// 체력
	int MP;					// 마나
	int power;				// 공격력
	int defence;			// 방어력
	int accuracy;			// 명중률
	int speed;				// 속도
};

