#pragma once
#pragma once
#include "tool.h"


class game_item {
public:
    game_item(int x, int y, int d) { posx = x; posy = y; direction = d; }
    int posx;
    int posy;
    int direction;
};



class MyTank :public game_item {
public:
    MyTank(int x, int y, int d);
    int type;
    int stop;
    int revive;
    int id;
    int alive;
    int color;
    int shot;
    int owner;
    int display_tank();
    int undisplay(); 
    void MoveMyTank(int turn);
    int check_pos();
};

class AITank :public game_item {
public:
    AITank(int i,int x, int y, int d);
    void gen_tank();
    int type;
    int stop;
    int revive;
    int id;
    int alive;
    int color;
    int shot;
    int owner;
    int display_tank();
    int undisplay();
    void Move();
    int check_pos();
    int gen_pos_check();
};

class Bullet :public game_item {
public:
    int exist;
    int building;
    int owner;
    int state;
};

#pragma once
#pragma once
#include "tool.h"


class game_item {
public:
    game_item(int x, int y, int d) { posx = x; posy = y; direction = d; }
    int posx;
    int posy;
    int direction;
};


class Bullet :public game_item {
public:
    Bullet(int x, int y, int d, int o) :game_item(x, y, d) { owner = o; exist = 1; state = 1; }
    int exist;
    int building;
    int owner;
    int state;
    int display_bullet();
    int undisplay_bullet();
    int check_pos();
};



class MyTank :public game_item {
public:
    MyTank(int x, int y, int d);
    int type;
    int stop;
    int revive;
    int id;
    int alive;
    int color;
    int shot;
    int owner;
    int display_tank();
    int undisplay(); 
    void MoveMyTank(int turn);
    int check_pos();
    Bullet* shoot();
};

class AITank :public game_item {
public:
    AITank(int i,int x, int y, int d);
    void gen_tank();
    int type;
    int stop;
    int revive;
    int id;
    int alive;
    int color;
    int shot;
    int owner;
    int display_tank();
    int undisplay();
    void Move();
    int check_pos();
    int gen_pos_check();
    Bullet* shoot(int x,int y);
};


