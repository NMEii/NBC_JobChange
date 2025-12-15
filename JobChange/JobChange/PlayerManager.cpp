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
		Slot[i] = nullptr;
	}
}


PlayerManager :: ~PlayerManager()
{
	for (int i = 0; i < 4; i++)
	{
		if (Slot[i] == nullptr)
		{
			continue;
		}
		delete Slot[i];
		Slot[i] = nullptr;
	}
}

int PlayerManager::ProcessInput(int defaultValue)
{
	int input = defaultValue;	// 입력 실패시 기본값 설정
	cin >> input;
	if (cin.fail() || cin.peek() != '\n')	// cin.fail 입력 실패 / cin.peak 제일 마지막에 정수 외의 문자가 올시
	{							
		cin.clear();			// 다음 입력을 받을 수 있도록 스트림 상태 복구
		input = defaultValue;	// 잘못된 입력은 무조건 기본값으로 처리
	}
	cin.ignore(INT_MAX, '\n');	// 이전 입력에서 남아 있는 문자 제거
	return input;
}

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
	string jobs[] = { "전사", "마법사", "도적", "궁수" };
	string name;
	int jobIndex = 0;

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

	while (jobIndex < 1 || jobIndex > 4)
	{
		jobIndex = ProcessInput(5);

		if (jobIndex < 1 || jobIndex > 4)
		{
			cout << "잘못된 입력입니다. " << endl;
		}
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