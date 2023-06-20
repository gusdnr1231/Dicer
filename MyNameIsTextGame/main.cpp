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
	"재빠른 고블린", //0
	"단단한 가고일", //1
	"엄청 강한 슬라임", //2
	"겁쟁이 미노타우르스", //3
	"굶주린 거대 오크", //4
	"왜인지 돈이 많은 늑대", //5
	"신사적인 거지 늑대 인간", //6
	"도박쟁이 임프", //7
	"성질 급한 마법사", //8
	"어딘가 달라진 슬라임", //9
	"날개가 찢어진 드래곤", //10
	"맷집이 약한 스켈레톤", //11
	"맷집만 강한 좀비", //12
	"마왕한테 반해버린 전 용사", //13
	"이 세상 최고의 악당 마왕" //14
};

int monsterStats[15][4]
{
	//체력 공격력 보상 인내심
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
	int input = 0;
	PLAYER player = { };
	DICE dice = { };
	Monster monster;
	InIt(&player);
	SetEnemy(&monster, monsterNames[0],
		monsterStats[0][0],
		monsterStats[0][1],
		monsterStats[0][2],
		monsterStats[0][3], &monsterTempHP);

	cout << "\t\t\t" << stageNum << "층입니다." << endl;
	MonsterAppearance(&monster, monsterTempHP);
	while (input != -1 && player.isDie != true)
	{
		cout << endl << "\t\t       <<1 : 공격>>" << endl << "\t\t       <<2 : 상태>>" << endl << "\t\t       <<3 : 휴식>>" << endl;
		cout << "\t\t       행동 번호: ";
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
		if (input == 3)
		{
			PlayerRest(&player, &monster);
		}
		if(monster.isDie)
		{
			Sleep(1500);
			stageNum++;
			if (stageNum == 15) break;
			cout << "\t\t다음 층으로 가고 있습니다." << endl;
			Sleep(1500);
			system("cls");
			cout << "\t\t\t" << stageNum << "층입니다." << endl;
			Sleep(500);
			/*if(stageNum >= 2 && stageNum <= 4)
			{
				monsterNum = rand() % 4 + 1;
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
			if(stageNum >= 6 && stageNum <= 9)
			{
				monsterNum = rand() % 4 + 5;
				SetEnemy(&monster,
					monsterNames[monsterNum],
					monsterStats[monsterNum][0],
					monsterStats[monsterNum][1],
					monsterStats[monsterNum][2],
					monsterStats[monsterNum][3], &monsterTempHP);
			}
			if(stageNum == 10)
			{
				SetEnemy(&monster,
					monsterNames[10],
					monsterStats[10][0],
					monsterStats[10][1],
					monsterStats[10][2],
					monsterStats[10][3], &monsterTempHP);
			}
			if(stageNum <= 11)
			{
				
			}*/
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
		cout << "\t플레이어가 쓰러졌다..." << endl << "\tGame Over..." << endl;
	}
	else if(player.isDie == false)
	{
		cout << "\t마왕이 쓰러졌다!" << endl;
		Sleep(100);
		cout << "\t마왕: 으윽... 강함의 비결이 뭐지..?" << endl;
		Sleep(100);
		cout << "\t용사: 우수한 자산 관리가 강함의 비결이지." << endl;
		Sleep(100);
		cout << "\t마왕: 이... 이 내가..! 용사 따위에게!" << endl;
		Sleep(100);
		cout << "\t용사: 꼬우면 너도 주사위 굴리던가." << endl;
		Sleep(100);
		cout << "\t그렇게 용사는... 마왕을 물리치고 여신에게 소원으로 평생 써도 남을 만큼의 돈을 달라고 했답니다!" << endl;
		cout << "\t플레이어가 999,999,999,999,999,999,999,999,999원을 얻었습니다!" << endl;
	}
}