#include"game.h"

# define row 30
# define len 80

Game::Game()
{
	mytank = new MyTank(15, 38, 1);
}

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
				wcout << L"■";
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
	wcout << L"第     关";
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
	wcout << 21 - speed;
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
	unsigned int interval[12] = { 1,1,1,1,1,1,1,1,1,1,1,1 };
	HideCursor();                         //隐藏光标
	system("mode con cols=112 lines=42"); //控制窗口大小
	display_main_GUI(); //打印游戏主体框架
	init();
	display_map();
	int i(0);
	while (1)
	{
		i++;
		interval[0]++;
		if (interval[0] % speed == 0)
		{
			bullet_move();
			
			for (int i(0); i < tank.size(); i++)
			{
				tank[i]->Move();
			}
					
			for (int i = 0; i < tank.size(); i++)
			{
				if (tank[i]->alive == 0 && tank[i]->revive < 4 && interval[9]++ % 90 == 0)  //一个敌方坦克每局只有4条命
				{                                               //如果坦克不存活。计时,每次建立有间隔  1750 ms
					tank[i]->gen_tank();     //建立AI坦克（复活）
					break;                                      //每次循环只建立一个坦克
				}
			}
			for (i = 0; i <= 3; i++)
			{
				if (tank[i]->alive)
				{
					Bullet *temp= tank[i]->shoot(mytank->posx, mytank->posy);
					if (temp != NULL)
					{
						bullet.push_back(temp);
					}
				}			
			}
				
			if (mytank->alive && interval[10]++ % 2 == 0)
			{
				handle_key();
			}
		}
		Sleep(5);
	}
	return 0;
}

int Game::display()
{
	//modeset(100,50);
	_setmode(_fileno(stdout), _O_U16TEXT);//让控制台启用Unicode 16
	//L告诉编译器使用两个字节的Unicode字符集
	for (int i(0); i < row; i++)
	{
		for (int j(0); j < len; j++)
		{
			if (j == 0 || j == len - 1)
			{
				wcout << L"\u2551";
				if (j == len - 1)
				{
					wcout << endl;
				}
			}
			else
			{
				if (i == 0 || i == row - 1)
				{
					wcout << L"\u2550";
				}
				else
				{
					wcout << " ";
				}
			}
		}
	}
	return 0;
}

void Game::init()
{
	remain_enemy = 16;
	mytank->revive = 0;  //我的坦克复活次数为0
	position = 0;
	bul_num = 0;
	GetMap(1);
	for (int i = 0; i <= 3; i++)         //AI坦克初始化
	{
		AITank* temp = new AITank(i, 0, 0, 0);
		tank.push_back(temp);
	}
	mytank->revive = 0;
	position = 0;
	mytank->display_tank();
	GoToxy(97, 2);                        //在副屏幕上关卡数
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	wcout << level;
	GoToxy(102, 5);                       //在副屏幕上打印分数
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
	wcout << score;
	GoToxy(102, 7);                       //在副屏幕打印我的剩余生命值
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	wcout << MAX_LIFE - mytank->revive;
	GoToxy(102, 9);                       //在副屏幕上打印剩余坦克数
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	wcout << remain_enemy;
	GoToxy(100, 13);                      //在副屏幕上打印状态
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
	wcout << L"正在游戏";
	return;

}

void Game::handle_key()
{
	int count = 0;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		mytank->MoveMyTank(UP);
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		mytank->MoveMyTank(DOWN);
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		mytank->MoveMyTank(LEFT);
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		mytank->MoveMyTank(RIGHT);
	else if (GetAsyncKeyState(0x1B) & 0x8000)  // Esc键
		exit(0);                                //退出程序函数
	else if (GetAsyncKeyState(0x20) & 0x8000)  //空格
		wcout << "pause";//Stop();
	else if (count++ % 7 == 0)            //这里添加计数器是为了防止按键粘连不能达到微调效果
	{
		if (speed > 1 && GetAsyncKeyState(0x6B) & 0x8000)   // +键
		{
			speed--;
			GoToxy(102, 11);           //在副屏幕打印出当前速度
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			wcout<<21 - speed;   //副屏幕显示的速度为1~10
		}
		else if (speed < 20 && GetAsyncKeyState(0x6D) & 0x8000)  // - 键
		{
			speed++;
			GoToxy(102, 11);           //在副屏幕打印出当前速度
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED);
			wcout<< 21 - speed;   //副屏幕显示的速度为1~10
		}
	}
	if (mytank->shot == 7)
	{
		if (GetAsyncKeyState(88) & 0x8000)
		{
			bullet.push_back(mytank->shoot());
			mytank->shot = 0;
		}
	}
	else
		mytank->shot++;
}

int Game::bullet_move()
{
	for (int i(0); i < bullet.size(); i++)
	{
		if (bullet[i]->exist)              //如果子弹存在
		{
			if (bullet[i]->state == 0)     //如果子弹不是初建立的
			{
				if (map[bullet[i]->posy][bullet[i]->posx] == 0 || map[bullet[i]->posx][bullet[i]->posx] == 5)   //如果子弹坐标当前位置无障碍
					bullet[i]->undisplay_bullet();     //抹除子弹图形
				switch (bullet[i]->direction)                                      //然后子弹坐标变化（子弹变到下一个坐标）
				{
					case UP:(bullet[i]->posy)--; break;
					case DOWN:(bullet[i]->posy)++; break;
					case LEFT:(bullet[i]->posx)--; break;
					case RIGHT:(bullet[i]->posx)++; break;
				}
			}
			int collide = bullet[i]->check_pos();   //判断子弹当前位置情况,判断子弹是否碰撞,是否位于水面上。
			if (collide)                                                //如果检测到当前子弹坐标无障碍(无碰撞)（包括在地面上与在水面上）
				bullet[i]->display_bullet();       //则打印子弹，若有碰撞则不打印
			else
				Hit_handle(i);     //若有碰撞则执行子弹碰撞函数                  
			if (bullet[i]->state)             //若子弹初建立，则把初建立标记去除
				bullet[i]->state = 0;
			for (int j = 0; j < bullet.size(); j++)  //子弹间的碰撞判断,若是我方子弹和敌方子弹碰撞则都删除,若为两敌方子弹则无视
				if (bullet[j]->exist && j != i && (bullet[i]->owner || bullet[j]->owner) && bullet[i]->posx == bullet[j]->posx && bullet[i]->posy == bullet[j]->posy)
				{                              //同样的两颗我方子弹不可能产生碰撞
					bullet[j]->exist = 0;
					bullet[i]->exist = 0;
					bullet[j]->undisplay_bullet();  //抹除j子弹图形,子弹i图形已被抹除
					break;
				}
		}
	}
	return 1;
}

int Game::Hit_handle(int id)
{
	int x = bullet[id]->posx;            //∴这里的Tank使用全局变量
	int y = bullet[id]->posy;            //这里传入的值是子弹坐标,这两个值不需要改变
	int i;
	if (map[y][x] == 1 || map[y][x] == 2)  //子弹碰到砖块
	{
		if (bullet[id]->direction == UP || bullet[id]->direction == DOWN)   //如果子弹是纵向的
			for (i = -1; i <= 1; i++)
				if (map[y][x + i] == 1 || map[y][x + i] == 2)  //如果子弹打中砖块两旁为砖块,则删除砖,若不是(一旁为坦克或其他地形)则忽略
				{
					map[y][x + i] = 0;    //砖块碎
					GoToxy(2 * x + 2 * i, y);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); //背景黑色
					wcout << L"  ";
				}
		if (bullet[id]->direction == LEFT || bullet[id]->direction == RIGHT)     //若子弹是横向的  (与子弹纵向实现同理)
			for (i = -1; i <= 1; i++)
				if (map[y + i][x] == 1 || map[y + i][x] == 2)
				{
					map[y + i][x] = 0;
					GoToxy(2 * x, y + i);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); //背景黑色
					wcout << L"  ";
				}
		bullet[id]->exist = 0;           //这颗子弹已经不存在了
	}
	else if (map[y][x] == 4 || map[y][x] == 6)  //子弹碰到边框或者不可摧毁方块
		bullet[id]->exist = 0;
	else if (bullet[id]->owner && map[y][x] >= 100 && map[y][x] < 104)  //若我的子弹碰到了敌方坦克
	{
		int num = map[y][x] % 100;   //map[y][x]%100 等同于 tank.num ，可通过map值读取该坦克信息
		if (tank[num]->type == 3 && tank[num]->color == 2)   //若为firm tank,且color==2。该坦克为绿色,表明没有受到伤害
			tank[num]->color = 3;                        //则变成黄色，color=3为黄色
		else if (tank[num]->type == 3 && tank[num]->color == 3)
			tank[num]->color = 4;                        //4为红色
		else                       //其他类型的坦克或者firm tank为红色的情况
		{
			tank[num]->alive = 0;
			tank[num]->undisplay();      //清除该坦克
		}
		bullet[id]->exist = 0;
		score += 100;
		GoToxy(102, 5);             //在副屏幕上打印出分数
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		wcout << score;
	}
	else if (map[y][x] == 200 && bullet[id]->owner == 0)   //若敌方子弹击中我的坦克
	{
		mytank->alive = 0;
		mytank->undisplay();
		bullet[id]->exist = 0;
		mytank->revive++;      //我的坦克复活次数+1(∵我的坦克复活次数与生命值有关∴放在这里自减)
		score -= 100;            //分数减少
		GoToxy(102, 5);         //在副屏幕上打印出分数
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		wcout << score;
		GoToxy(102, 7);         //在副屏幕打印出我的剩余生命值
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		wcout << MAX_LIFE - mytank->revive;
	}
	//	else if(bullet[id]->my==0 && map[y][x]>=100 && map[y][x]<104) //敌方子弹击中敌方坦克,可以设置两种子弹运行方式,这种暂时不用
	//		bullet[id]->exist=0;
	else if (map[y][x] == 9)      //子弹碰到家(无论是谁的子弹)
	{
		bullet[id]->exist = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		GoToxy(38, 37);	 wcout << L"      ";
		GoToxy(38, 38);	 wcout << L"◢◣  ";
		GoToxy(38, 39);	 wcout << L"███";
		game_over(1);           //游戏结束,传入1代表老家被毁
	}
	return 1;
}

int Game::game_over(int home)
{
	int timing = 0, color = 1;
	while (1)
	{
		if (timing++ % 30 == 0)         //游戏结束原因为生命值为0
		{
			ColorChoose(color);    //颜色选择
			if (home)               //游戏结束原因为老家被毁,则多打印一行字以提示玩家
			{
				GoToxy(37, 19);     //主屏幕中心打印
				wcout << "老家被毁!";
			}
			GoToxy(37, 20);         //主屏幕中心打印
			wcout << "游戏结束!";
			GoToxy(100, 13);        //副屏幕打印
			wcout << "游戏结束";
			GoToxy(88, 17);
			wcout << "请按回车键重新开始!";
			GoToxy(88, 18);
			wcout << "或按 Esc键退出游戏!";
			if (++color == 8)
				color = 1;
		}
		if (GetAsyncKeyState(0xD) & 0x8000)  //回车键
		{
			//			system("cls");       //清屏,这里清屏后再次打印框架有一定几率造成框架上移一行的bug，因此选用自建清屏函数
			//			Frame ();            //重新打印游戏框架
			score -= 500;          //分数-500
			clean_screen();   //主屏清屏函数，无需再次打印框架
			init();        //从本关重新开始
			break;
		}
		else if (GetAsyncKeyState(0x1B) & 0x8000)  //Esc键退出	
			exit(0);
		Sleep(20);
	}
	return 1;
}

void Game::clean_screen()
{
	for (int i = 1; i < 40; i++)
	{
		GoToxy(2, i);
		wcout << "                                                                              ";
	}
}
