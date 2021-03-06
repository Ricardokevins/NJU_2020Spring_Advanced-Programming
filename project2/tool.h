#pragma once
#include <stdio.h>
#include <windows.h>
#include <time.h> 
#include <Windows.h>
#include<iostream>
#include<io.h>//使用_setmode(_fileno(stdout), _O_U16TEXT)必须加的头文件
#include<vector>
#include<fcntl.h>//使用_setmode(_fileno(stdout), _O_U16TEXT)必须加的头文件
//里规格：长39*2=78 （真坐标）(假坐标宽为39)  高39
//外规格：长41*2=82 （真坐标）(假坐标宽为41)  高41
using namespace std;

extern int map[41][41];  //地图二维数组
extern  int key_x;        // X键是否被“读入”的变量，也是子弹是否可以发射的变，
extern  int bul_num;      //子弹编号
extern  int position;     //位置计数,对应AI坦克生成位置,-1为左位置,0为中间,1为右,2为我的坦克位置
extern  int speed;      //游戏速度,调整用
extern  int level;      //游戏关卡数
extern  int score;      //游戏分数
extern  int remain_enemy; //剩余敌人(未出现的敌人)
#define UP    1
#define DOWN  2
#define LEFT  3
#define RIGHT 4
#define MAX_LEVEL 8
#define BULLET_NUM 20
#define MAX_LIFE 4

typedef struct             //这里的出现次序指的是一个AI_tank变量中的次序，游戏共有四个AI_tank变量
{                          //∵设定每个AI_tank每种特殊坦克只出现一次 ∴fast_tank & firm_tank 最多出现次数不超过1
	int fast_tank_order;   //fast_tank出现的次序(在第fast_tank_order次复活出现,从第0次开始)，且每个AI_tank只出现一次
	int firm_tank_order;   //firm_tank出现的次序，同上
} LevInfo;   
extern LevInfo level_info[MAX_LEVEL];//关卡信息(准确说是该关出现的坦克信息)




void HideCursor();
void GoToxy(int x, int y);
void ColorChoose(int color);
void GetMap(int level);

string wstring2string(wstring& ws);
wstring string2wstring(string& s);
