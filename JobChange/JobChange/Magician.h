#pragma once
#include "Player.h"
using namespace std;

class Magician : public Player
{
public:
	Magician(string nickname);
	void attack() override;
	void attack(Monster* monster) override;

}; 
