#include "Tank.h"


Tank::Tank(int a):game_item(0,0,0)
{
    type=a;
    stop=0;
    revive=0;
    id=0;
    alive=0;
    color=0;
    shot=0;
    owner=0;
}