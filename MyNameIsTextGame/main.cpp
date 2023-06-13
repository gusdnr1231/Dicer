#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <Windows.h>
#include <conio.h>
#include "gameLogic.h"

using namespace std;
 
string monsterNames[15] = 
{
	"재빠르지만 약한 고블린", //0
	"단단하고 굼뜬 가고일", //1
	"엄청 강한 슬라임", //2
	"겁이 많은 미노타우르스", //3
	"굶주린 거대 오크", //4
	"수상할 정도로 돈이 많은 늑대", //5
	"돈은 없지만 신사적인 늑대 인간", //6
	"성질 급한 마법사", //7
	"어딘가 달라진 슬라임", //8
	"도박쟁이 임프", //9
	"맷집이 약한 스켈레톤", //10
	"맷집만 강한 좀비", //11
	"날개가 찢어진 드래곤", //12
	"왜 여기 있는지 모르겠는 전 용사", //13
	"이 세상 최고의 악당 마왕" //14
};

int monsterStats[15][4]
{
	//체력 공격력 보상 인내심
	{100, 2, 20, 2}, //0
	{450, 4, 50, 6}, //1
	{210, 1, 30, 3}, //2
	{900, 8, 80, 5}, //3
	{1450, 9, 120, 6}, //4
	{700, 4, 170, 3}, //5
	{1400, 5, 60, 7}, //6
	{300, 3, 40, 2}, //7
	{680, 2, 70, 3}, //8
	{650, 0/*랜덤 값으로 지정*/, 0/*랜덤 값으로 지정*/, 4}, //9
	{600, 9, 130, 4}, //10
	{1000, 6, 130, 5}, //11
	{2000, 6, 140, 3}, //12
	{2100, 8, 150, 5}, //13
	{4000, 10, 1000, 4} //14
};

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0, monsterTempHP = 0, monsterNum = 0, stageNum = 1;
	PLAYER player = { };
	DICE dice = { };
	Monster monster;
	InIt(&player);
	SetEnemy(&monster, monsterNames[0],
		monsterStats[0][0],
		monsterStats[0][1],
		monsterStats[0][2],
		monsterStats[0][3], &monsterTempHP);
	
	MonsterAppearance(&monster, monsterTempHP);
	while (input != -1)
	{
		cout << endl << "\t1 : 공격" << endl << "\t2 : 상태창" << endl;
		cout << "\t숫자를 입력하세요 : ";
		cin >> input;
		if (input == 1)
		{
			PlayerAttack(dice, &player, &monster);
			ShowMonsterHP(&monster, monsterTempHP);
		}
		if(input == 2)
		{
			ShowPlayerStat(player);
		}
		if(monster.isDie)
		{
			stageNum++;
			if(stageNum >= 2 && stageNum <= 4)
			{
				monsterNum = rand() % 3 + 1;
				SetEnemy(&monster, 
					monsterNames[monsterNum], 
					monsterStats[monsterNum][0],
					monsterStats[monsterNum][1],
					monsterStats[monsterNum][2], 
					monsterStats[monsterNum][3], &monsterTempHP);
			}
			if(stageNum == 5)
			{
				SetEnemy(&monster,
					monsterNames[4],
					monsterStats[4][0],
					monsterStats[4][1],
					monsterStats[4][2],
					monsterStats[4][3], &monsterTempHP);
			}
		}
	}
}