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
	"��������� ���� ���", //0
	"�ܴ��ϰ� ���� ������", //1
	"��û ���� ������", //2
	"���� ���� �̳�Ÿ�츣��", //3
	"���ָ� �Ŵ� ��ũ", //4
	"������ ������ ���� ���� ����", //5
	"���� ������ �Ż����� ���� �ΰ�", //6
	"���� ���� ������", //7
	"��� �޶��� ������", //8
	"�������� ����", //9
	"������ ���� ���̷���", //10
	"������ ���� ����", //11
	"������ ������ �巡��", //12
	"�� ���� �ִ��� �𸣰ڴ� �� ���", //13
	"�� ���� �ְ��� �Ǵ� ����" //14
};

int monsterStats[15][4]
{
	//ü�� ���ݷ� ���� �γ���
	{100, 2, 20, 2}, //0
	{450, 4, 50, 6}, //1
	{210, 1, 30, 3}, //2
	{900, 8, 80, 5}, //3
	{1450, 9, 120, 6}, //4
	{700, 4, 170, 3}, //5
	{1400, 5, 60, 7}, //6
	{300, 3, 40, 2}, //7
	{680, 2, 70, 3}, //8
	{650, 0/*���� ������ ����*/, 0/*���� ������ ����*/, 4}, //9
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
		cout << endl << "\t1 : ����" << endl << "\t2 : ����â" << endl;
		cout << "\t���ڸ� �Է��ϼ��� : ";
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