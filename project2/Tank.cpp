#include "Tank.h"

char* tank_figure[4][3][4] =
{
  {
	{(char*)"◢┃◣", (char*)"◢━◣",(char*)"◢┳◣", (char*)"◢┳◣"},
	{(char*)"┣●┫", (char*)"┣●┫", (char*)"━●┃", (char*)"┃●━"},
	{(char*)"◥━◤", (char*)"◥┃◤", (char*)"◥┻◤", (char*)"◥┻◤"}
  },
  {
	{(char*)"┏┃┓", (char*)"┏┳┓", (char*)"┏┳┓", (char*)"┏┳┓"},
	{(char*)"┣●┫",(char*)"┣●┫", (char*)"━●┫",(char*)"┣●━"},
	{(char*)"┗┻┛", (char*)"┗┃┛", (char*)"┗┻┛", (char*)"┗┻┛"}
  },
  {
	{(char*)"┏┃┓", (char*)"◢━◣", (char*)"┏┳◣", (char*)"◢┳┓"},
	{(char*)"┣●┫", (char*)"┣●┫", (char*)"━●┃", (char*)"┃●━"},
	{(char*)"◥━◤", (char*)"┗┃┛", (char*)"┗┻◤", (char*)"◥┻┛"}
  },
  {
	{(char*)"╔┃╗", (char*)"╔╦╗", (char*)"╔╦╗", (char*)"╔╦╗"},
	{(char*)"╠█╣", (char*)"╠█╣", (char*)"━█╣",(char*)"╠█━"},
	{(char*)"╚╩╝", (char*)"╚┃╝",(char*)"╚╩╝", (char*)"╚╩╝"}
  }
};

MyTank::MyTank(int x, int y, int d) :game_item(15, 38, 1)
{
	type = 0;
	stop = 0;
	revive = 0;
	id = 0;
	alive = 1;
	color = 1;
	shot = 7;
	owner = 1;
}

int MyTank::display_tank()
{
	ColorChoose(color);  //颜色选择函数   定义一个数组里装着字符指针(既装字符串)的数组指针(指向一维数组首地址的指针)
	char* (*tankF)[4] = tank_figure[type];  //将二维数组首址赋初值给数组指针 model==0为我的坦克,4为电脑1坦克,8为电脑2,类推
	for (int i = 0; i < 3; i++)
	{
		GoToxy((posx - 1) * 2, posy - 1 + i);        //在坦克中心坐标的左边，上中下三行打印
		string temp = tankF[i][direction - 1];
		//printf("%s", tankF[i][tank.direction - 1]); //打印的是地址，地址既字符串
		wstring temp2 = string2wstring(temp);
		wcout << temp2;
		for (int j = 0; j < 3; j++)
			if (owner)       //若为我的坦克
				map[posy + j - 1][posx + i - 1] = 200;  //在map上把"坦克"九格填满代表敌我坦克的参数。敌方此值为100~103,我方为200
			else
				map[posy + j - 1][posx + i - 1] = 100 + id;  //这样可以通过map值读取坦克编号,读取操作在BulletHit 函数
	}
	return 0;
}

AITank::AITank(int i,int x, int y, int d) :game_item(x, y, d)
{
	revive = 0;
	alive = 0;  //初始化坦克全是不存活的，BuildAITank()会建立重新建立不存活的坦克
	stop = 0;
	id = i;
	owner = 0;
	shot = 0;
}

int AITank::display_tank()
{
	ColorChoose(color);  //颜色选择函数   定义一个数组里装着字符指针(既装字符串)的数组指针(指向一维数组首地址的指针)
	char* (*tankF)[4] = tank_figure[type];  //将二维数组首址赋初值给数组指针 model==0为我的坦克,4为电脑1坦克,8为电脑2,类推
	for (int i = 0; i < 3; i++)
	{
		GoToxy((posx - 1) * 2, posy - 1 + i);        //在坦克中心坐标的左边，上中下三行打印
		string temp = tankF[i][direction - 1];
		//printf("%s", tankF[i][tank.direction - 1]); //打印的是地址，地址既字符串
		wstring temp2 = string2wstring(temp);
		wcout << temp2;
		for (int j = 0; j < 3; j++)
			if (owner)       //若为我的坦克
				map[posy + j - 1][posx + i - 1] = 200;  //在map上把"坦克"九格填满代表敌我坦克的参数。敌方此值为100~103,我方为200
			else
				map[posy + j - 1][posx + i - 1] = 100 + id;  //这样可以通过map值读取坦克编号,读取操作在BulletHit 函数
	}
	return 0;
}

int MyTank::undisplay()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{                     //将坦克占用的地图上的九格去掉
			map[posy + j - 1][posx + i - 1] = 0;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			GoToxy(2 * posx + 2 * j - 2, posy + i - 1);
			wcout << L"  ";
		}
	return 0;
}

int AITank::undisplay()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{                     //将坦克占用的地图上的九格去掉
			map[posy + j - 1][posx + i - 1] = 0;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			GoToxy(2 * posx + 2 * j - 2, posy + i - 1);
			wcout << L"  ";
		}
	return 0;
}

int MyTank::check_pos()
{
	switch (direction)                    //direction变量   1上，2下，3左，4右
	{
	case UP:
		if (map[posy - 2][posx] == 0 && map[posy - 2][posx - 1] == 0 && map[posy - 2][posx + 1] == 0)
			return 1;
		else
			return 0;
	case DOWN:
		if (map[posy + 2][posx] == 0 && map[posy + 2][posx - 1] == 0 && map[posy + 2][posx + 1] == 0)
			return 1;
		else
			return 0;
	case LEFT:
		if (map[posy][posx - 2] == 0 && map[posy - 1][posx - 2] == 0 && map[posy + 1][posx - 2] == 0)
			return 1;
		else
			return 0;
	case RIGHT:
		if (map[posy][posx + 2] == 0 && map[posy - 1][posx + 2] == 0 && map[posy + 1][posx + 2] == 0)
			return 1;
		else
			return 0;
	default:
		wcout << L"错误！！";
		Sleep(5000);
		return 0;
	}
}

int AITank::check_pos()
{
	switch (direction)                    //direction变量   1上，2下，3左，4右
	{
	case UP:
		if (map[posy - 2][posx] == 0 && map[posy - 2][posx - 1] == 0 && map[posy - 2][posx + 1] == 0)
			return 1;
		else
			return 0;
	case DOWN:
		if (map[posy + 2][posx] == 0 && map[posy + 2][posx - 1] == 0 && map[posy + 2][posx + 1] == 0)
			return 1;
		else
			return 0;
	case LEFT:
		if (map[posy][posx - 2] == 0 && map[posy - 1][posx - 2] == 0 && map[posy + 1][posx - 2] == 0)
			return 1;
		else
			return 0;
	case RIGHT:
		if (map[posy][posx + 2] == 0 && map[posy - 1][posx + 2] == 0 && map[posy + 1][posx + 2] == 0)
			return 1;
		else
			return 0;
	default:
		wcout << L"错误！！";
		Sleep(5000);
		return 0;
	}
}

void MyTank::MoveMyTank(int turn)   //玩家专用函数，turn为keyboard函数里因输入不同方向键而传入的不同的值
{
	undisplay();        //map 数组中“我的坦克”参数清除工作已在此函数中完成
	direction = turn;                  //将键盘输入的方向值传入我的坦克方向值
	if (check_pos())  //若此时我的坦克当前方向上无障碍
		switch (turn)
		{
		case UP: posy--; break;  //上前进一格
		case DOWN: posy++; break;  //下前进一格
		case LEFT: posx--; break;  //左前进一格
		case RIGHT: posx++; break;  //右前进一格
		}                                        //若坦克当前方向上有障碍则跳过坐标变化直接打印该转向的坦克
	display_tank();
}

void AITank::gen_tank()
{
	if (gen_pos_check())        //若此位置无障碍,可生成。position参数详见AIPositionCheak函数定义
	{
		posx = 20 + 18 * (position);  //20 + 18 * position 对应三个生成位置的x假坐标
		posy = 2;
		if (revive == level_info[level - 1].firm_tank_order)  //坦克出现(复活)次序==关卡信息(level_info)中firm tank的出现次序
		{
			type = 3;           //3为firm tank的模型(外观)
			color = 2;           //颜色参数2为绿色，具体详见函数ColorChoose
		}
		else if (revive == level_info[level - 1].fast_tank_order)  //同上if，这里是fast_tank的
		{
			type = 2;
			color = rand() % 6 + 1;  //若不是firm tank则随机颜色，颜色参数为1~6,分别代表不同颜色,详见函数ColorChoose
		}
		else      //普通坦克
		{
			type = 1;
			color = rand() % 6 + 1;  //若不是firm tank则随机颜色
		}
		alive = 1;       //坦克变为存在
		direction = 2;  //方向朝下
		revive++;        //复活次数+1
		display_tank();
		position++;
		remain_enemy--;
		GoToxy(102, 9);            //在副屏幕上打印剩余坦克数
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		wcout << remain_enemy;
		if (position == 2)          //position只能为0,1，-1，这里position循环重置
			position = -1;
		return ;                  //若生成了一辆坦克，则结束该函数
	}
}

void AITank::Move()
{
	if (alive)         //如果坦克活着
	{
		if ( stop != 0)   //坦克是否停止运动的判断，若stop参数不为0
		{
			 stop--;   //则此坦克本回合停止运动
			return;
		}
		if (!(rand() % 23))     //22分之1的概率执行方向重置
		{
			 direction = rand() % 4 + 1;
			if (rand() % 3)     //在方向重置后有2分之1的概率停止走动3步的时间
			{
				 stop = 2;
				return;
			}
		}
		undisplay();
		if (check_pos())   //如果前方无障碍
			switch ( direction)
			{
				case UP:  posy--; break;  //上前进一格
				case DOWN:  posy++; break;  //下前进一格
				case LEFT:  posx--; break;  //左前进一格
				case RIGHT:  posx++; break;  //右前进一格
			}
		else                     //前方有障碍
		{
			if (!(rand() % 4))      //3分之1的概率乱转
			{
				 direction = rand() % 4 + 1;
				 stop = 2; //乱转之后停止走动3步的时间
				display_tank();
				return;          //∵continue会跳过下面的打印函数,∴这里先打印
			}
			else                 //另外3分之2的几率选择正确的方向
			{
				int j;
				int temp = direction;
				for (j = 1; j <= 4; j++)//ToDo
				{
					direction = j;
					if (check_pos())  //循环判断坦克四周有无障碍,此函数返值1为可通过
						break;
				}		
				direction = temp;
				if (j == 5)         //j==5说明此坦克四周都有障碍物，无法通行
				{
					display_tank();
					return;      //则跳过下面的while循环以防程序卡死
				}
				while (check_pos() == 0)  //如果前方仍有障碍
					 direction = (rand() % 4 + 1);                    //则换个随机方向检测
			}
		}
		display_tank();     //打印AI坦克
	}
}

int AITank::gen_pos_check()    //position为坦克生成位置2为我的坦克位置，其余为AI位，-1为左位，0为中间位置，1为右位
{
	int	x, y;
	if (position == 2)                    //2为我的坦克位置，现在暂时用不到
		x = 15, y = 38;
	else
		y = 2, x = 20 + 18 * position;  //20 + 18 * position 对应三个生成位置的x假坐标
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (map[y + j - 1][x + i - 1] != 0)  //如果遍历的九宫格里有障碍物
				return 0;              //则返回0，表示此生成位置有阻碍
	return 1;                          //否则生成1，表示此生成位置无阻碍
}

Bullet* MyTank::shoot()
{
	Bullet* temp = new Bullet(posx, posy, direction,owner);
	return temp;
}

int Bullet::display_bullet()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	GoToxy(2 * posx, posy);
	wcout << L"☉";
	return 1;
}

int Bullet::undisplay_bullet()
{
	GoToxy(2 * posx, posy);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	wcout << L"  ";
	return 1;
}

int Bullet::check_pos()
{
	if (map[posy][posx] == 0)
		return 1;
	else if (map[posy][posx] == 5)
		return 2;
	else
		return 0;
}

Bullet* AITank::shoot(int x,int y)
{
	if (shot == 15)
	{
		if (!(rand() % 11))     //冷却结束后在随后的每个游戏周期中有10分之一的可能发射子弹
		{
			Bullet* temp = new Bullet(posx, posy, direction, owner);
			shot = 0;
			return temp;
		}
	}
	else
		shot++;
	if (shot >= 14)       //AI强化部分，在冷却到达一定范围即可使用
	{
		if (posy == 38)     //如果坦克在底部(这个最优先)
		{
			if (posx < 20) //在老家左边
			{
				if (direction == RIGHT)  //坦克方向朝左
				{
					Bullet* temp = new Bullet(posx, posy, direction, owner);     //发射子弹
					shot = 0;
					return temp;
				}
			}
			else             //在老家右边
				if (direction == LEFT)   //坦克方向朝右
				{
					Bullet* temp = new Bullet(posx, posy, direction, owner);     //发射子弹
					shot = 0;
					return temp;
				}
		}
		else if (posx == x + 1 ||posx == x || posx == x - 1)  //AI坦克在纵向上"炮口"对准我的坦克
		{
			if (direction == DOWN && y > posy || direction == UP && y < posy)
			{                               //若是AI朝下并且我的坦克在AI坦克下方(数值大的在下面)或者AI朝上我的坦克在AI上方
				int big = y, smal = y, i;
				if (y < posy)
				{
					big =posy;
					smal =y;
				}
				for (i = smal + 2; i <= big - 2; i++)  //判断AI炮口的直线上两坦克间有无障碍
					if (map[i][posx] != 0 || map[i][posx] != 5)      //若有障碍
						break;
				if (i == big - 1)                //若i走到big-1说明无障碍
				{
					Bullet* temp = new Bullet(posx, posy, direction, owner);     //发射子弹
					shot = 0;
					return temp;
				}
			}
		}
		else if (posy ==  y + 1 || posy ==  y || posy ==  y - 1) //AI坦克在横向上"炮口"对准我的坦克
		{
			if (direction == RIGHT &&  x > posx || direction == LEFT &&  x < posx)
			{                  //若是AI朝右并且我的坦克在AI坦克右方(数值大的在下面)或者AI朝左我的坦克在AI左方
				int big =  y, smal = posy, i;
				if ( x < posx)
				{
					big = posx;
					smal =  x;
				}
				for (i = smal + 2; i <= big - 2; i++)  //判断AI炮口的直线上两坦克间有无障碍
					if (map[posy][i] != 0 || map[posy][i] != 5)      //若有障碍
						break;
				if (i == big - 1)   //若i走到big-1说明无障碍
				{
					Bullet* temp = new Bullet(posx, posy, direction, owner);     //发射子弹
					shot = 0;
					return temp;
				}
			}
		}
	}
	return NULL;
}