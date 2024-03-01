#ifndef MAIN_H
#define MAIN_H

using namespace std;

class Player
{
    public:
        int money = 1000000;
        int boat_lvl = 7;
        int rod_lvl = 7;
        string location = "River";
        bool end = false;
};
#endif