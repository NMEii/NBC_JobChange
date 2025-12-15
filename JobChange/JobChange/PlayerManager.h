#pragma once
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();

	void createCharacter(int slotIndex);
	bool isEmptySlot(int slotIndex);
	void showSlot() const;
	Player* getPlayer(int slotIndex);
private:
	static const int MAX_SLOT = 4;
	Player* Slot[MAX_SLOT];
};
