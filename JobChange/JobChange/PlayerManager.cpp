#include <iostream>
#include <string>
#include "PlayerManager.h"
#include "Warrior.h"
#include "Magician.h"
#include "Archer.h"
#include "Thief.h"


PlayerManager::PlayerManager()
{
	for (int i = 0; i < 4; i++)
	{
		Slot[i] = { nullptr };
	}
}


PlayerManager :: ~PlayerManager()
{
	for (int i = 0; i < 4; i++)
	{
		delete Slot[i];
		Slot[i] = { nullptr };
	}
	
}

/*
	
*/
void PlayerManager::showSlot() const	
{
	cout << "< 캐릭터 목록 >" << endl;
	cout << "------------------------------------" << endl;
	for (int i = 0; i < MAX_SLOT ; i++)
	{
		if (Slot[i] == nullptr)
		{
			cout << i + 1 << ". 빈 슬롯" << endl;	
		}
		else
		{
			cout << i + 1 << ". 닉네임 : " << Slot[i]->getNickname() << " 직업 : " << Slot[i]->getJobName() << endl;
		}
	}
	cout << "9.캐릭터를 생성" << endl;
	cout << "0. 종료" << endl;
	cout << "------------------------------------" << endl;	 	
	
	cout << "접속할 캐릭터를 선택해주세요." << endl;

}

bool PlayerManager::isEmptySlot(int slotIndex)
{
	if (slotIndex < 0 || slotIndex >= MAX_SLOT)
	{
		return false;
	}

	return Slot[slotIndex] == nullptr;
}

void PlayerManager::createCharacter(int slotIndex)
{
	string jobs[] = { "검성", "법성", "살성", "궁성" };
	string name;
	int jobIndex;

	if (slotIndex < 0 || slotIndex >= MAX_SLOT)
	{
		cout << "잘못된 슬롯입니다. " << endl;
		return;
	}

	if (Slot[slotIndex] != nullptr)
	{
		cout << "이미 캐릭터가 존재하는 슬롯입니다." << endl;
		return;
	}

	// 직업 나열
	cout << "○ 직업을 선택하세요." << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << ". " << jobs[i] << endl;

	}
	cin >> jobIndex;
	if (jobIndex < 1 || jobIndex > 4)
	{
		cout << "잘못된 슬롯입니다. " << endl;
		return;
	}

	cout << "닉네임 입력 : ";
	cin >> name;

	switch (jobIndex)
	{
	case 1:
		Slot[slotIndex] = new Warrior(name);
		break;
	case 2:
		Slot[slotIndex] = new Magician(name);
		break;
	case 3:
		Slot[slotIndex] = new Thief(name);
		break;
	case 4:
		Slot[slotIndex] = new Archer(name);
		break;
	default:
		cout << "잘못된 입력입니다." << endl;
		return;
	}

	cout << "캐릭터 생성 완료." << endl;
	
}

Player* PlayerManager::getPlayer(int slotIndex)
{
	if (slotIndex < 0 || slotIndex >= MAX_SLOT)
		return nullptr;

	return Slot[slotIndex];
}