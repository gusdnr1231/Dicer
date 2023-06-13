#pragma once
#include <string>
#include <vector>
#include<Windows.h>
typedef struct _player {
	int hp;
	int money;
	bool isDie;
}PLAYER, *PPLAYER;

typedef struct _dice {
	int dice[5] = {0, 0, 0, 0, 0};
}DICE, *PDICE;

class MonsterBase {
public:
	std::string monsterName;
	int hp;
	int attack;
	bool isDie = false;
	int amount;
	int curWaitTurn = 0;
	int maxWaitTurn;
};

class Monster : public MonsterBase {
public:
	void InitMonsterStat(std::string monsterName, int hp, int attack, int amount, int maxWaitTurn){
		this->monsterName = monsterName;
		this->hp = hp;
		this->attack = attack;
		this->amount = amount;
		this->maxWaitTurn = maxWaitTurn;
	}
};

class Item
{
public:
	std::string itemName;
	int value;
};

void InIt(PPLAYER _pPlayer);
void MoneyManage(PPLAYER _pPlayer, int amount);
void PlayerAttack(DICE _pDice, PPLAYER _pPlayer, Monster *monster);
void ShowPlayerStat(PLAYER player);
void MonsterAppearance(Monster* monster, int tempHP);
void ShowMonsterHP(Monster* monster, int tempHP);
void SetEnemy(Monster* monster, std::string enemyName, int hp, int attack, int amount, int maxWaitTurn, int* temp);
int ReturnMaxHP(int hp);
void EnemyAttack(PPLAYER _pPlayer, Monster* monster);
void EnemyStatUpdate(PPLAYER _pPlayer, Monster* monster);
void ShowDice(DICE _pDice);