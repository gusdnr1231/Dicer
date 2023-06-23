#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include "gameLogic.h"

using namespace std;
 
string monsterNames[15] = 
{
	"����� ���", //0
	"�ܴ��� ������", //1
	"��û ���� ������", //2
	"������ �̳�Ÿ�츣��", //3
	"���ָ� �Ŵ� ��ũ", //4
	"������ ���� ���� ����", //5
	"�Ż����� ���� ���� �ΰ�", //6
	"�������� ����", //7
	"���� ���� ������", //8
	"��� �޶��� ������", //9
	"������ ������ �巡��", //10
	"������ ���� ���̷���", //11
	"������ ���� ����", //12
	"�������� ���ع��� �� ���", //13
	"�� ���� �ְ��� �Ǵ� ����" //14
};

int monsterStats[15][4]
{
	//ü�� ���ݷ� ���� �γ���
	{100, 2, 20, 2}, //0
	{350, 4, 50, 6}, //1
	{210, 1, 30, 3}, //2
	{500, 8, 80, 5}, //3
	{1450, 9, 120, 6}, //4
	{400, 4, 170, 3}, //5
	{800, 5, 60, 7}, //6
	{220, 0, 0, 4}, //7
	{300, 3, 40, 2}, //8
	{420, 2, 70, 3}, //9
	{2000, 6, 140, 3}, //10
	{600, 9, 130, 4}, //11
	{1000, 6, 130, 5}, //12
	{2100, 8, 150, 5}, //13
	{4000, 10, 1000, 4} //14
};

int main()
{
	srand((unsigned int)time(NULL));
	int monsterTempHP = 0, monsterNum = 0, stageNum = 1;
	char input = NULL;
	PLAYER player = { };
	DICE dice = { };
	Monster monster;
	InIt(&player);
	SetEnemy(&monster, monsterNames[0],
		monsterStats[0][0],
		monsterStats[0][1],
		monsterStats[0][2],
		monsterStats[0][3], &monsterTempHP);

	cout << "\t\t\t" << stageNum << "���Դϴ�." << endl;
	MonsterAppearance(&monster, monsterTempHP);
	while (input != -1 && player.isDie != true)
	{
		cout << endl << "\t\t       <<Q : ����>>" << endl << "\t\t       <<W : �޽�>>" << endl << "\t\t       <<E : ����>>" << endl;
		input = _getch();
		if (input == 'Q' || input == 'q')
		{
			PlayerAttack(dice, &player, &monster);
			ShowMonsterHP(&monster, monsterTempHP);
		}
		if(input == 'W' || input == 'w')
		{
			PlayerRest(&player, &monster);
		}
		if (input == 'E' || input == 'e')
		{
			ShowPlayerStat(player);
		}
		if(monster.isDie)
		{
			Sleep(1500);
			stageNum++;
			if (stageNum == 15) break;
			cout << "\t\t���� ������ ���� �ֽ��ϴ�." << endl;
			Sleep(1500);
			system("cls");
			cout << "\t\t\t" << stageNum << "���Դϴ�." << endl;
			Sleep(500);
			SetEnemy(&monster,
				monsterNames[stageNum],
				monsterStats[stageNum][0],
				monsterStats[stageNum][1],
				monsterStats[stageNum][2],
				monsterStats[stageNum][3], &monsterTempHP);
			if(stageNum == 7)
			{
				SetEnemy(&monster,
					monsterNames[stageNum],
					monsterStats[stageNum][0],
					rand() % 6 + 1,
					(rand() % 6 + 1) * 20,
					monsterStats[stageNum][3], &monsterTempHP);
			}
			MonsterAppearance(&monster, monsterTempHP);
		}
	}
	system("cls");
	if(player.isDie)
	{
		cout << "\t�÷��̾ ��������..." << endl << "\tGame Over..." << endl;
	}
	else if(player.isDie == false)
	{
		cout << "\t������ ��������!" << endl;
		Sleep(100);
		cout << "\t����: ����... ������ ����� ����..?" << endl;
		Sleep(100);
		cout << "\t���: ����� �ڻ� ������ ������ �������." << endl;
		Sleep(100);
		cout << "\t����: ��... �� ����..! ��� ��������!" << endl;
		Sleep(100);
		cout << "\t���: ����� �ʵ� �ֻ��� ��������." << endl;
		Sleep(100);
		cout << "\t�׷��� ����... ������ ����ġ�� ���ſ��� �ҿ����� ��� �ᵵ ���� ��ŭ�� ���� �޶�� �ߴ�ϴ�!" << endl;
		cout << "\t�÷��̾ 999,999,999,999,999,999,999,999,999���� ������ϴ�!" << endl;
	}
}