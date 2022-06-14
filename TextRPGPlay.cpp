#pragma once
#include "console.h"
#include "miroGamePlay.h"
#include "TextRPGPlay.h"

using namespace std;

enum monsterType {
	monster1,
	monster2,
	monster3,
	monster4,
	monster5
};

void TextRPG(int &totalScore, int &stage, int itemParts[]) {

	int playerHp = totalScore, playerAtk = 20, playerDef = 0;
	int monsterHp = 0, monsterAtk = 0, monsterDef = 0;
	int reflectCount = 3;
	int item[5] = { 1, 1, 0, 0, 0 };
	int iItem;
	string monsterName = "", itemPart = "";
	int playerAct;

	srand((unsigned int)time(NULL));

	int monstertype = rand() % 5;

	switch (monstertype)
	{
	case monster1: // HP : 100, ATK : 5, DEF = 2
		monsterName += "monster1";
		monsterHp = 50;
		monsterAtk = 5;
		monsterDef = 2;
		itemPart += "���������1";
		break;
	case monster2: // HP : 300, ATK : 10, DEF = 5
		monsterName += "monster2";
		monsterHp = 40;
		monsterAtk = 10;
		monsterDef = 5;
		itemPart += "���������2";
		break;
	case monster3: // HP : 500, ATK : 15, DEF = 10
		monsterName += "monster3";
		monsterHp = 80;
		monsterAtk = 15;
		monsterDef = 10;
		itemPart += "���������3";
		break;
	case monster4: // HP : 700, ATK : 23, DEF = 0
		monsterName += "monster4";
		monsterHp = 120;
		monsterAtk = 23;
		monsterDef = 0;
		itemPart += "���������4";
		break;
	case monster5: // HP : 1000, ATK : 15, DEF = 15
		monsterName += "monster5";
		monsterHp = 150;
		monsterAtk = 15;
		monsterDef = 15;
		itemPart += "���������5";
		break;
	}

	while (true) {
		system("cls");
		if (playerHp <= 0) {
			cout << "�÷��̾� ���" << endl;
			break;
		}

		cout << "���Ϳ��� ���� ����!" << endl << endl;
		cout << "�÷��̾� ����" << endl;
		cout << "Hp : " << playerHp << endl;
		cout << "Atk : " << playerAtk << endl;
		cout << "Def : " << playerDef << endl << endl;

		cout << "���� ����" << endl;
		cout << "���� �̸� : " << monsterName << endl;
		cout << "Hp : " << monsterHp << endl;
		cout << "Atk : " << monsterAtk << endl;
		cout << "Def : " << monsterDef << endl << endl;

		cout << "������ �� ������ �������ּ���!" << endl;
		cout << "1 : ����, 2 : �������ݻ� (���� Ƚ�� : " << reflectCount << "), 3 : �����ۻ��" << endl << endl;

		cin >> playerAct;

		if (playerAct == 1) {
			cout << "�÷��̾��� ����!" << endl;
			cout << "���� ������ : " << (playerAtk - monsterDef) << endl;
			cout << "������ ����!" << endl;
			cout << "���� ������ : " << (monsterAtk - playerDef) << endl;
			playerHp -= (monsterAtk - playerDef);
			monsterHp -= (playerAtk - monsterDef);
			Sleep(1000);
		}
		else if (playerAct == 2) {
			if (reflectCount <= 0) {
				cout << "�� �̻� �������ݻ縦 ����� �� �����ϴ�!" << endl;
				break;
			}
			cout << "�������ݻ�!" << endl;
			if (monsterAtk - monsterDef > 0) {
				cout << "���� ������ : " << (monsterAtk - monsterDef) << endl;
				monsterHp -= (monsterAtk - monsterDef);
			}
			else if (monsterAtk - monsterDef == 0) {
				cout << "�ƴ�?! ���� ������ ���� ���ݷ��̶� ���Ƽ� ȿ���� ���ݾ�!" << endl;
				cout << "���� ������ : 0" << endl;
			}
			else if (monsterAtk - monsterDef <= 0) {
				cout << "���� ������ ���� ���ݷº��� ���Ƽ� �������� �ȵ�!" << endl;
				cout << "���� ������ : 0" << endl;
			}
			reflectCount--;
			Sleep(1000);
		}
		else if (playerAct == 3) {
			cout << "���� �������� ����Ͻðڽ��ϱ�? " << endl;
			cout << "1. ���ݷ����� (���ݷ� X2) : " << item[0] << endl;
			cout << "2. �������� (���� +5) : " << item[1] << endl;
			cin >> iItem;
			if (iItem == 1 && item[0] != 0) {
				cout << "���ݷ� ���!" << endl;
				item[0]--;
				playerAtk *= 2;
				Sleep(1000);
			}
			else if (iItem == 2 && item[1] != 0) {
				cout << "���� ���!" << endl;
				item[1]--;
				playerDef += 5;
				Sleep(1000);
			}
			else if (item[0] <= 0 || item[1] <= 0) {
				cout << "�������� ���ڶ��ϴ�!" << endl;
				Sleep(1000);
			}
 		}

		if (monsterHp <= 0) {
			cout << endl << "�÷��̾��� �¸�!" << endl;
			cout << itemPart << "��(��) ȹ���Ͽ����ϴ�!" << endl;
			GetItem(itemPart, itemParts);

			for (int i = 2; i > 0; --i) {
				cout << i << "�� �� �̷ΰ������� �Ѿ�ϴ�.." << endl;
				Sleep(1000);
			}
			Miro(totalScore, stage);
			break;
		}
	}
}

void GetItem(string itemPart, int itemParts[]) {
	if (itemPart == "���������1") {
		itemParts[0]++;
	}
	else if (itemPart == "���������2") {
		itemParts[1]++;
	}
	else if (itemPart == "���������3") {
		itemParts[2]++;
	}
	else if (itemPart == "���������4") {
		itemParts[3]++;
	}
	else if (itemPart == "���������5") {
		itemParts[4]++;
	}
}