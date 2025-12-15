#include <iostream>
#include <string>
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "PlayerManager.h"
#include "Windows.h"

using namespace std;

int main()
{
	PlayerManager Manager;
	Player* player = nullptr;
	string name;
	int choice;
	int slotIndex;

	Manager.showSlot();

	while (true)
	{
		cin >> slotIndex;

		if (slotIndex == 0)
		{
			return 0;
		}

		player = Manager.getPlayer(slotIndex - 1);

		if (Manager.isEmptySlot(slotIndex-1))
		{
			cout << "빈 슬롯 입니다." << endl;
			continue;
		}
		

		if (slotIndex == 9)
		{			
			cout << "캐릭터를 생성할 슬롯을 선택해주세요. ";
			cin >> slotIndex;
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
			cin >> choice;

			switch (choice)
			{
			case 1:
				player->printPlayerStatus();
				break;
			case 2:
				player->attack();
				break;
			case 0:
				bExit = false;
				system("cls");
				Manager.showSlot();
				break;
			}

		}

	}



	return 0;
}