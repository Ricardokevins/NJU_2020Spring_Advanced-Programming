#pragma once
#include"Tank.h"
#include "tool.h"
class Game{
public:
    vector<Tank*> tank;
    vector<Bullet> bullet;
    int run();
    void display_main_GUI();
    void display_info_GUI();
    void display_map();
    void clean_screen();
    int display();
};
