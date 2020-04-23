#pragma once
#include "tool.h"


class game_item{
public:
    game_item(int x,int y,int d){posx=x;posy=y;direction=d;}
    int posx;
    int posy;
    int direction;
};

class Tank:public game_item{
public:
    int type;
    int stop;
    int revive;
    int id;
    int alive;
    int color;
    int shot;
    int owner;
};

class Bullet:public game_item{
public:
    int exist;
    int building;
    int owner;
    int state;
};

