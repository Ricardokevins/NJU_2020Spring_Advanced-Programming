#include"game.h"

# define row 30
# define len 80

void Game::display_main_GUI()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	//printf("  ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁  ");
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"  ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	wcout << L"  ▂▂▂▂▂▂▂▂▂▂▂▂▂ \n";
	for (int i = 0; i < 14; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_INTENSITY);
		wcout << L"▕                                                                              ▏";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		wcout << L" |                          |\n";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_INTENSITY);
	wcout << L"▕                                                                              ▏";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	wcout << L" |═════════════|\n";
	for (int i = 0; i < 24; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_INTENSITY);
		wcout << L"▕                                                                              ▏";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		wcout << L" |                          |\n";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_INTENSITY);
	wcout << L"  ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	wcout << L" ﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊﹊\n";
    display_info_GUI();

	//SideScreen();  //打印副屏幕
}

void Game::display_map()
{
    for (int j = 0; j < 41; j++)
    {
		for (int i = 0; i < 41; i++)
        {
            //wcout<<map[i][j];
            if (map[i][j] == 6)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN
					| FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE);
				GoToxy(2 * j, i);
				wcout<<L"■";
			}
			else if (map[i][j] == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_RED);
				GoToxy(2 * j, i);
				wcout << L"▓";
			}
			else if (map[i][j] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_GREEN | BACKGROUND_RED);
				GoToxy(2 * j, i);
				wcout << L"▓";
                //wcout<<"Hello World";
			}
			else if (map[i][j] == 5)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_GREEN);
				GoToxy(2 * j, i);
				wcout << L"～";
			}
        }
    }		
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	GoToxy(38, 37);	 wcout << L"◣★◢";
	GoToxy(38, 38);	 wcout << L"███";    //∵无论地图怎么变,家所在位置不变,且家的字符多种,不方便用上述方式打印
	GoToxy(38, 39);	 wcout << L"◢█◣";    //∴直接打印(且家的map值与符号无关)

}

void Game::display_info_GUI()
{
    GoToxy(93, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
	wcout<<L"第     关";
	GoToxy(92, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	wcout << L"分  数：";
	GoToxy(92, 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	wcout << L"生  命：";
	GoToxy(86, 9);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	wcout << L"剩余敌方坦克：";
	GoToxy(86, 11);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	wcout << L"当前游戏速度：";
    wcout<<  21 - speed;
	GoToxy(86, 13);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	wcout << L"当前游戏状态：";
	GoToxy(94, 19);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
	GoToxy(94, 24);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
	wcout << L"帮  助";
	GoToxy(86, 27);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	wcout << L"方向键  ←↑→↓  移动";
	GoToxy(93, 29);
	wcout << L"x 键 射击";
	GoToxy(89, 31);
	wcout << L"+ - 调整游戏速度";
	GoToxy(90, 33);
	wcout << L"游戏速度范围1~20";
	GoToxy(90, 35);
	wcout << L"回车键 暂停游戏";
	GoToxy(90, 37);
	wcout << L"Esc键  退出游戏";
	
}

int Game::run()
{
    //display();
    HideCursor();                         //隐藏光标
	system("mode con cols=112 lines=42"); //控制窗口大小
	display_main_GUI(); //打印游戏主体框架
    GetMap(1);            //获取map数据
    display_map();
    return 0;
}

int Game::display()
{
    //modeset(100,50);
    _setmode(_fileno(stdout), _O_U16TEXT);//让控制台启用Unicode 16
    //L告诉编译器使用两个字节的Unicode字符集
    for(int i(0);i<row;i++)
    {
        for(int j(0);j<len;j++)
        {
            if(j==0||j==len-1)
            {
                wcout<<  L"\u2551";
                if(j==len-1)
                {
                    wcout<<endl;
                }
            }
            else
            {
                if(i==0||i==row-1)
                {
                    wcout<<  L"\u2550";
                }
                else
                {
                    wcout<<" ";
                }
            }
        }
    }
	return 0;
}

