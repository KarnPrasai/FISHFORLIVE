#ifndef MAIN_H
#define MAIN_H


using namespace std;

class Player
{
    public:
        int DayPlayed = 1;
        int QuotaMoney = 150;
        int money = 0;
        int boat_lvl = 1;
        string location = "River";
        bool end = false;
        void Stat();

};

#endif