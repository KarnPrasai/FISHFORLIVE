#ifndef MAIN_H
#define MAIN_H

using namespace std;

class Player
{
    public:
        int money = 0;
        int boat_lvl = 1;
        int rod_lvl = 1;
        string location = "River";
        bool end = false;
};
#endif