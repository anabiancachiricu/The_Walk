#include <iostream>
#include "Map.h"
#include<ctime>
#include"Robot.h"
#include "Wall_E.h"
#include"Run_game.h"
using namespace std;
int main()
{
    //srand((int)time(NULL));
    Map map;
    map.print(map);
    cout << "Hello World!\n";
    Run_game();
    return 0;
}

