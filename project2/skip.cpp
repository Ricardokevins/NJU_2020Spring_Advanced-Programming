#include <stdio.h>
#include <windows.h>
#include <time.h> 
#include<iostream>
using namespace std;
void HideCursor()  //隐藏光标
{                  //CONSOLE_CURSOR_INFO结构体包含控制台光标的信息,DWORD dwSize光标百分比厚度（1~100）和BOOL bVisible光标是否可见
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info); //SetConsoleCursorInfo用来设置指定的控制台光标的大小和可见性。
}


void GoToxy(int x,int y)  //光标移动函数，X表示横坐标，Y表示纵坐标。
{
	COORD  coord;         //使用头文件自带的坐标结构
	coord.X=x;            //这里将int类型值传给short,不过程序中涉及的坐标值均不会超过short范围
	coord.Y=y;
	HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);  //获得标准输出句柄
	SetConsoleCursorPosition(a,coord);         //以标准输出的句柄为参数设置控制台光标坐标
}


int main()
{
    HideCursor();
    GoToxy(20,20);
    cout<<"Hello WOrld"<<endl;
    return 0;

}