#include <iostream>
#include <string>
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "PlayerManager.h"
#include "Monster.h"
#include "Windows.h"

using namespace std;

int main()
{
	PlayerManager Manager;
	Player* player = nullptr;
	Monster* monster = nullptr;
	string name;
	int choice;
	int slotIndex;

	Manager.showSlot();

	while (true)
	{
		slotIndex = Manager.ProcessInput(5);

		if (slotIndex == 0)
		{
			break;
		}

		if (Manager.isEmptySlot(slotIndex-1))
		{
			cout << "빈 슬롯 입니다." << endl;
			continue;
		}
		
		if (slotIndex == 9)
		{			
			cout << "캐릭터를 생성할 슬롯을 선택해주세요. ";
			slotIndex = Manager.ProcessInput(5);

			if (!Manager.isEmptySlot(slotIndex-1))
			{
				system("cls");
				Manager.showSlot();
				cout << "빈 슬롯이 아닙니다." << endl;
				continue;
			}
			Manager.createCharacter(slotIndex-1);
			player = Manager.getPlayer(slotIndex - 1);
		}

		if (slotIndex < 0 || slotIndex > 4)
		{
			cout << "잘못된 입력입니다." << endl;
			continue;
		}
		
		player = Manager.getPlayer(slotIndex - 1);

		system("cls");

		cout << "------------------------------------" << endl;
		cout << "1. 스탯창" << endl;
		cout << "2. 공격" << endl;
		cout << "0. 뒤로가기" << endl;
		cout << "------------------------------------" << endl;
		cout << "메뉴를 선택하세요." << endl;

		int choice;
		bool bExit = true;

		while (bExit)
		{
			choice = Manager.ProcessInput(5);

			if (!(choice == 0 || choice == 1 || choice == 2))
			{
				cout << "잘못된 입력입니다." << endl;
				continue;
			}

			switch (choice)
			{
			case 1:
				player->printPlayerStatus();
				break;
			case 2:
				monster = new Monster("고블린");

				while (true)
				{
					player->attack();
					player->attack(monster);

					monster->attack(player);

					if (monster->isDead(monster->getHP()))
					{
						cout << monster->getName() << "이(가) 쓰러졌습니다." << endl;
						cout << "전투에서 승리하였습니다." << endl;
						delete monster;
						monster = nullptr;
						break;
					}
					if (player->isDead(player->getHP()))
					{
						cout << player->getNickname() << "이(가) 쓰러졌습니다." << endl;
						player->setHP(10);
						break;
					}
				}
				break;
			case 0:
				bExit = false;
				system("cls");
				Manager.showSlot();
				break;
			}

		}

	}

	if (monster != nullptr) 
	{ 
		delete monster; 
	}

	return 0;
}