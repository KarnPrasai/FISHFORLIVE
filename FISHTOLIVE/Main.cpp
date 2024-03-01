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
        int QuotaMoney = 500;
        int THour = 6;
        int TMin = 0;
        int boatlevel = 1;
        int rodlevel = 1;
};

Main m;
Player player;
Fishing fish;
Travel travel;
Shop shop;
int addH = 0, addM = 0;

void Quotacheck()
{
    if (m.DayPlayed % 4 == 0)
    {
        if (player.money - m.QuotaMoney < 0)
        {
            player.end = true;
        }
        else
        {
            player.money -= m.QuotaMoney;
            m.QuotaMoney += 500;
        }
    }
}

void menu()
{
    cout << "=========================================\n";
    cout << "\n";
    cout << "FISHFORLIVE\n";
    cout << "What would you like to do?\n";
    cout << "|| Play || Quit ||\n";
    cout << "Enter your action : ";
    string action01;
    cin >> action01;
    if (action01 == "Play")
    {
        player.end = false;
    }
    else if (action01 == "Quit")
    {
        player.end = true;
    }
    else
    {
        cout << "Invalid input. Please choose again." << endl;
    }
}

void Stat()
{
    cout << "=========================================\n";
    cout << "\n";
    cout << "Day : " << m.DayPlayed << endl;
    cout << "Destination : " << player.location << endl;
    cout << "You have made " << player.money << "/" << m.QuotaMoney << " for this round." << endl;
    cout << "Your have " << player.money << "$ for now." << endl;
    cout << "Boat's level = " << player.boat_lvl << ", Rod's level " << player.rod_lvl << endl;
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
        int amin = rand() % 31 + 30;
        SetTime(ahour, amin);
    }
    else if (act == "Travel")
    {
        travel.PlaceTravel(player.location, fish.playergoing, player.boat_lvl);
        if (travel.IsTraveled)
        {
            SetTime(3, 0);
        }
    }
    else if (act == "Shop")
    {
        shop.ShopControl(player.money, player.boat_lvl, player.rod_lvl, fish.fish_amount, fish.slotfish);
        int amin = rand() % 21 + 10;
        SetTime(0, amin);
    }
    else if (act == "End")
    {
        player.end = true;
    }
    else
    {
        cout << "Invalid input. Please choose again." << endl;
    }
    
}
int main()
{
    menu();
    string playeraction;
    while (!player.end)
    {
        Quotacheck();
        cout << "=========================================\n";
        cout << "\n";
        travel.IsTraveled = false;
        cout << "Day : " << m.DayPlayed << endl;
        showtime(m.THour, m.TMin);
        cout << "What would you like to do?\n";
        cout << "|| Stat || Fish || Travel || Shop || \n";
        cout << "Enter your action : ";
        cin >> playeraction;
        Action(playeraction);
        cout << "\n";
    }
    if (player.end == true && playeraction != "End")
    {
        cout << "=========================================\n";
        cout << "\n";
        cout << "You Lost";
        cout << "\n";
        cout << "=========================================\n";
        cout << "\n";
    }
}

