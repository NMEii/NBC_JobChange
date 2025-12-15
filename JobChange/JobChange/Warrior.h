#pragma once
#include "Player.h"
using namespace std;

class Warrior : public Player
{
public:
	Warrior(string nickname);
	void attack() override;
};