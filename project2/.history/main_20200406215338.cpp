#include <Windows.h>
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
	modeset(100,180);

    for(int i(0);i<3;i++)
    {
        cout<< &#x2500
    }
	return 0;
}