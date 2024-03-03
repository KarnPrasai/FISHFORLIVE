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
#include <windows.h>
#include "Event.h"
using namespace std;

struct Main
{
        int DayPlayed = 1;
        int QuotaMoney = 150;
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
Event event;
int addH = 0, addM = 0;
bool menuend = false;

string toUpperStr(const string& str) 
{
    string upperStr;
    for (char c : str) {
        upperStr += toupper(c);
    }
    return upperStr;
}

float randomFloat(float min, float max) 
{
    float digit = rand() % (int)(max - min) + min;
    float dot = (float)(rand() % 50 + 50) / 100.0f;    
    float ran = digit + dot;                       
    return ran;
}

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
            m.QuotaMoney *= randomFloat(1, 2);
        }
    }
}

void menu()
{

    while (!menuend)
    {
        cout << "=========================================\n";
        cout << "\n";
        cout << "FISHFORLIVE\n";
        cout << "\n";
        cout << "What would you like to do?\n";
        cout << "|| Play || Quit ||\n";
        cout << "Enter your action : ";
        string action01;
        cin >> action01;
        cout << "\n";
        if (toUpperStr(action01) == "PLAY")
        {
            player.end = false;
            menuend = true;
        }
        else if (toUpperStr(action01) == "QUIT")
        {
            player.end = true;
            menuend = false;
        }
        else
        {
            cout << "Invalid input. Please choose again." << endl;
            cout << "\n";
        }
    }
    
}

void Stat()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "=========================================\n";
    cout << "\n";
    cout << "Day : " << m.DayPlayed << endl;
    cout << "Destination : " << player.location << endl;
    SetConsoleTextAttribute(h, 13);
    cout << "You have made " << player.money << "/" << m.QuotaMoney << " for this round." << endl;
    cout << "Your have " << player.money << "$ for now." << endl;
    SetConsoleTextAttribute(h, 7);
    cout << "Boat's level = " << player.boat_lvl << ", Rod's level " << player.rod_lvl << endl;
}

void SetTime(int addH,int addM)
{
    m.TMin += addM;
    m.THour += addH + m.TMin / 60;
    if (m.THour >= 18)
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
    cout << "\n";
    if (act == "STAT")
    {
        Stat();
    }
    else if (act == "FISHING" || act == "FISH")
    {
        HANDLE F = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(F, 3);
        int ec = rand() % 100+1;// 20+1;
        if (ec <= 5)
        {
            event.EventStart(player.money, fish.fish_amount,fish.slotfish,fish.fishN);
        }
        else
        {
            fish.GoFishing(player.rod_lvl);
        }
        int ahour = rand()% 2+1;
        int amin = rand() % 60;
        SetTime(ahour, amin);
        SetConsoleTextAttribute(F, 7);
    }
    else if (act == "TRAVEL")
    {
        travel.PlaceTravel(player.location, fish.playergoing, player.boat_lvl);
        if (travel.IsTraveled)
        {
            SetTime(3, 0);
        }
    }
    else if (act == "SHOP")
    {
        HANDLE S = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(S, 14);
        shop.ShopControl(player.money, player.boat_lvl, player.rod_lvl, fish.fish_amount, fish.slotfish);
        if (fish.fish_amount == NULL)
        {
            for (int i = 0; i < sizeof(fish.fishN)-1; ++i) {
                fish.fishN[i] = ""; // Set each element to an empty string
            }
        }
        int amin = rand() % 21 + 10;
        SetTime(0, amin);
        SetConsoleTextAttribute(S, 7);
    }
    else if (act == "END")
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
        HANDLE C = GetStdHandle(STD_OUTPUT_HANDLE);
        Quotacheck();
        cout << "=========================================\n";
        cout << "\n";
        travel.IsTraveled = false;
        cout << "Day : " << m.DayPlayed << endl;
        showtime(m.THour, m.TMin);
        cout << "What would you like to do?\n";
        cout << "|| Stat || Fishing || Travel || Shop || \n";
        SetConsoleTextAttribute(C, 15);
        cout << "Enter your action : ";
        cin >> playeraction;
        Action(toUpperStr(playeraction));
        cout << "\n";
        SetConsoleTextAttribute(C, 7);
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

