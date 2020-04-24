#pragma once


#include"Tank.h"
#include "tool.h"
class Game {
public:
    Game();

    MyTank* mytank;
    vector<AITank*> tank;
    vector<Bullet*> bullet;
    int run();
    void display_main_GUI();
    void display_info_GUI();
    void display_map();
    void clean_screen();
    int display();
    void init();
    void handle_key();

    int bullet_move();
    int Hit_handle(int id);

    int game_over(int i);
};
