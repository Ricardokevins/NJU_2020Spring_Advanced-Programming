#include <Windows.h>
#include<iostream>
#include<io.h>//使用_setmode(_fileno(stdout), _O_U16TEXT)必须加的头文件
#include<fcntl.h>//使用_setmode(_fileno(stdout), _O_U16TEXT)必须加的头文件
using namespace std;

void modeset(int w,int h) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size = {w, h};
	SetConsoleScreenBufferSize(hOut,size);
	SMALL_RECT rc = {1,1, w, h};
	SetConsoleWindowInfo(hOut ,true ,&rc);
	system("cls");
	return;
}


int main(){
    modeset(100,50);
     _setmode(_fileno(stdout), _O_U16TEXT);//让控制台启用Unicode 16
//L告诉编译器使用两个字节的Unicode字符集
    for(int i(0);i<100;i++)
    {
        for(int j(0);j<100;j++)
        {
            if(j==0||j==99)
            {
                wcout<<  L"\u2551";
            }
            else
            {
                if(i==0||i==90)
                {
                    wcout<<  L"\u2550";
                }
                else
                {
                    wcout<<
                }
            }
        }
    }
	return 0;
}

/*
for(int i(0);i<5;i++)
    {
        wcout<<  L"\u2588";
    }
    wcout<<endl;
    for(int i(0);i<5;i++)
    {
        wcout<<  L"\u2588";
    }

    wcout<<endl;
    */
