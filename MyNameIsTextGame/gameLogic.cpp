#include <iostream>
#include <string>
#include <vector>
#include<Windows.h>
#include "gameLogic.h"

using namespace std;

void InIt(PPLAYER _pPlayer)
{
	_pPlayer->hp = 30;
	_pPlayer->money = 100;
	_pPlayer->isDie = false;
}

void MoneyManage(PPLAYER _pPlayer, int amount)
{
	_pPlayer->money += amount;
}

void PlayerHPManage(PPLAYER _pPlayer, int amount)
{
	_pPlayer->hp += amount;
	if (_pPlayer->hp > 30) _pPlayer->hp = 30;
}

void PlayerAttack(DICE _pDice, PPLAYER _pPlayer, Monster* monster)
{
	srand((unsigned int)time(NULL));
	system("cls");
	cout << "�÷��̾ ������ �մϴ�." << endl;
	int sum = 0, sameCount = 0, straightCount = 0, temp = 0;
	for (int i = 0; i < 5; i++)
	{
		_pDice.dice[i] = rand() % 5 + 1;
		sum += _pDice.dice[i];
	}
	cout << "�ֻ����� ���������ϴ�! " << endl;
	ShowDice(_pDice);
#pragma region Dice Check
	//Yacht
	for (int i = 0; i < 5; i++)
	{
		if (i == 0) temp = _pDice.dice[i];
		else
		{
			if (temp == _pDice.dice[i]) sameCount++;
		}
		if (sameCount == 4) sum = 40;
		if (sameCount == 5) sum = 50;
	}
	// Small/Large Straight
	for (int i = 1; i <= 6; i++)
	{
		temp = straightCount;
		for (int j = 0; j < 5; j++)
		{
			if (_pDice.dice[j] == i)
			{
				straightCount++;
				break;
			}
		}
		if (temp == straightCount) break;
		if (straightCount == 4) sum = 20;
		if (straightCount == 5) sum = 35;
	}
#pragma endregion
#pragma region Attack Text
	if (sameCount == 4) cout << "�ֻ��� 4���� ���� �����ϴ�! ���� ������ �մϴ�! ���ݸ��� <<Full House>> �Դϴ�!" << endl;
	else if (sameCount == 5) cout << "��� �ֻ����� ���� �����ϴ�! ���� ������ ������ �մϴ�! ���ݸ��� <<Yacht>> �Դϴ�!" << endl;
	else if (straightCount == 4) cout << "4���� �ֻ����� ���� ����Ǿ����ϴ�! ���ݸ��� <<Small Straight>> �Դϴ�!" << endl;
	else if (straightCount == 5) cout << "5���� �ֻ����� ���� ����Ǿ����ϴ�! ���ݸ��� <<Large Straight>> �Դϴ�!" << endl;
	else cout << "�ֻ��� ���� ���� " << sum << "�Դϴ�!" << endl;
#pragma endregion
	cout << endl << monster->monsterName << "(��)�� " << int((_pPlayer->money / 100) * sum) << "�� �������� �Ծ����ϴ�!" << endl;
	monster->hp -= int((_pPlayer->money / 100) * sum);
	EnemyStatUpdate(_pPlayer, monster);
}

void PlayerRest(PPLAYER _pPLayer, Monster* monster)
{
	PlayerHPManage(_pPLayer, 4);
	EnemyStatUpdate(_pPLayer, monster);
}

void ShowPlayerStat(PLAYER player)
{
	system("cls");
	cout << 
		endl << "\t==============================" << 
		endl << "\t=      �÷��̾� ����         =" << 
		endl << "\t=	  ü��: " << player.hp << "	     =" << 
		endl << "\t=    ������(���ݷ�):" << player.money << "��    =" <<
		endl << "\t==============================" << 
		endl << "\t=        ������ ����         =" <<
		endl << "\t=  (������ / 100) * �ֻ���   =" << 
		endl << "\t==============================" <<
		endl;
}

void MonsterAppearance(Monster* monster, int tempHP)
{
	cout << "\t" << monster->monsterName << "�� ��Ÿ����!" << endl;
	ShowMonsterHP(monster, tempHP);
}

void ShowMonsterHP(Monster* monster, int tempHP)
{
	cout << "\t" << monster->monsterName << "�� HP: " << monster->hp << "/" << tempHP << endl;
}

void EnemyStatUpdate(PPLAYER _pPlayer, Monster* monster)
{
	if (monster->hp > 0)
	{
		monster->curWaitTurn++;
		if(monster->curWaitTurn != monster->maxWaitTurn)
		cout << endl << monster->monsterName << "(��)�� " << monster->maxWaitTurn - monster->curWaitTurn << "�� �ڿ� �����մϴ�!" << endl;
		else if (monster->curWaitTurn == monster->maxWaitTurn) EnemyAttack(_pPlayer, monster);
	}
	if (monster->hp <= 0)
	{
		monster->hp = 0;
		monster->isDie = true;
		cout << monster->monsterName << "(��)�� ���������ϴ�!" << endl;
		cout << "�÷��̾ " << monster->amount << "���� ������ϴ�!" << endl;
		MoneyManage(_pPlayer, monster->amount);
	}
}

void SetEnemy(Monster* monster, string monsterName, int hp, int attack, int amount, int maxWaitTurn, int* temp)
{
	monster->InitMonsterStat(monsterName, hp, attack, amount, maxWaitTurn);
	monster->curWaitTurn = 0;
	monster->isDie = false;
	*temp = ReturnMaxHP(hp);
}

int ReturnMaxHP(int hp)
{
	return hp;
}

void EnemyAttack(PPLAYER _pPlayer, Monster* monster)
{
	cout << monster->monsterName << "(��)�� �����մϴ�!" << endl;
	_pPlayer->hp -= monster->attack;
	monster->curWaitTurn = 0;
	cout << "�÷��̾ " << monster->attack << "�� �������� �Ծ����ϴ�!" << endl;
}

string diceEyes[6][5] =
{
	{
		{"��������"},
		{"��������"},
		{"��������"},
		{"��������"},
		{"��������"}
	},
	{
		{"��������"},
		{"��������"},
		{"��������"},
		{"��������"},
		{"��������"}
	},
	{
		{"��������"},
		{"��������"},
		{"��������"},
		{"��������"},
		{"��������"}
	},
	{
		{"��������"},
		{"��������"},
		{"��������"},
		{"��������"},
		{"��������"}
	},
	{
		{"��������"},
		{"��������"},
		{"��������"},
		{"��������"},
		{"��������"}
	},
	{
		{"��������"},
		{"��������"},
		{"��������"},
		{"��������"},
		{"��������"}
	},
};

void ShowDice(DICE _pDice)
{
	Sleep(50);
	for (int t = 0; t < 5; t++)
	{
		cout << "[]";
		cout << " �������� ";
	}
	cout << "[]" << endl;
	for (int h = 0; h < 5; h++)
	{
		Sleep(50);
		for (int v = 0; v < 5; v++)
		{
			cout << "[]";
			cout << " " << diceEyes[_pDice.dice[v] - 1][h] << " ";
		}
		cout << "[]" << endl;
	}
	Sleep(50);
	for (int t = 0; t < 5; t++)
	{
		cout << "[]";
		cout << " �������� ";
	}
	cout << "[]" << endl;
}
