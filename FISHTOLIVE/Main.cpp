#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include "Shop.h"
#include "Main.h"
#include "Fishing.h"
#include "Travel.h"
#include <vector>

using namespace std;

struct Main
{
        int DayPlayed = 1;
        int QuotaMoney = 150;
        int THour = 6;
        int TMin = 0;
        
};

Main m;
Player player;
Fishing fish;
Travel travel;
int addH = 0, addM = 0;

void Stat()
{
    cout << "Day : " << m.DayPlayed << endl;
    cout << "Destination : " << player.location << endl;
    cout << "You have made " << player.money << "/" << m.QuotaMoney << " for this round." << endl;
}

void SetTime(int addH,int addM)
{
    m.TMin += addM;
    m.THour += addH + m.TMin / 60;
    if (m.THour >= 24)
    {
        m.DayPlayed += 1;
        m.THour = 6;
        m.TMin = 0;
    }
    m.TMin %= 60;
    m.THour %= 24;
}

void showtime(int hour, int min)
{
    cout << "Time : " << setfill('0') << setw(2) << hour << ":" << setw(2) << min << std::endl;
}

void Action(string act)
{
    if (act == "Stat")
    {
        Stat();
    }
    else if (act == "Fish")
    {
        fish.GoFishing();
        int ahour = rand()% 2;
        int amin = rand() % 60;
        SetTime(ahour, amin);
    }
    else if (act == "Travel")
    {
        travel.PlaceTravel();
        if (travel.IsTraveled)
        {
            SetTime(3, 0);
        }
    }
    if (act == "Shop")
    {

    }
    if (act == "End")
    {
        player.end = true;
    }
}
int main()
{
    while (!player.end)
    {
        travel.IsTraveled = false;
        cout << "Day : " << m.DayPlayed << endl;
        showtime(m.THour, m.TMin);
        cout << "What would you like to do?\n";
        cout << "|| Stat || Fish || Travel || Shop || \n";
        cout << "Enter your action : ";
        string playeraction;
        cin >> playeraction;
        Action(playeraction);
    }
    //p.Shop();
}

