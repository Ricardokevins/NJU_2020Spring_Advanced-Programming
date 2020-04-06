#include <Windows.h>
#include<iostream>
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
    char a='\u2515';
    printf("%c",a);
    printf("■");
	return 0;
}

#include<iostream>
#include<io.h>//使用_setmode(_fileno(stdout), _O_U16TEXT)必须加的头文件
#include<fcntl.h>//使用_setmode(_fileno(stdout), _O_U16TEXT)必须加的头文件
using namespace std;
 
int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);//让控制台启用Unicode 16
    wcout<<L"DDDD \u2612!\n";//L告诉编译器使用两个字节的Unicode字符集
    wcout << L'☒';
    return 0;
}
