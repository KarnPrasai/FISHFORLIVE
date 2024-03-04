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
#include <vector>
using namespace std;

struct Main
{
    int DayPlayed = 1;
    int DayTillDL = 2;
    int QuotaMoney = 150;
    int THour = 6;
    int TMin = 0;
    int boatlevel = 1;
    int rodlevel = 1;
    int QuotaLimit = 10000000;
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

void typeText(const string& text, int delay) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    this_thread::sleep_for(chrono::milliseconds(1000));
}

void Quotacheck()
{
    if (m.DayTillDL < 0)
    {
        cout << "\033[1;31m" << "=========================================\n" << "\033[0m";
        cout << "\n";
        if (player.money - m.QuotaMoney < 0)
        {
            cout << "\033[1;31m" << "You didn't earn enough money to meet the debt quota, so all your stuff has been taken." << "\033[0m" << endl;
            cout << "\033[1;31m" << "=========================================\n" << "\033[0m";
            cout << "\n";
            cout << "\033[1;31m" << "Game Over\n" << "\033[0m";
            cout << "You have survived " << m.DayPlayed - 1 << " Days.\n";
            cout << "\n";
            cout << "\033[1;31m" << "=========================================\n" << "\033[0m";
            cout << "\n";
            player.end = true;
        }
        else if (player.money >= 10000000 || m.QuotaLimit <= 0)
        {
            cout << "\033[0;32m" << "You have enough money to pay all of your debt, you are free now!!." << "\033[0m" << endl;
            cout << "\033[0;32m" << "=========================================\n" << "\033[0m";
            cout << "\n";
            cout << "\033[0;32m" << "You Won!!\n" << "\033[0m";
            cout << "You have spent " << m.DayPlayed - 1 << " Days.\n";
            cout << "\n";
            cout << "\033[0;32m" << "=========================================\n" << "\033[0m";
            cout << "\n";
            player.end = true;
        }
        else
        {
            player.money -= m.QuotaMoney;
            m.QuotaLimit -= m.QuotaMoney;
            m.QuotaMoney *= randomFloat(1, 2);
            cout << "\033[1;31m" << "Crediter : You have reached the quota this time. but next, I want "<< m.QuotaMoney <<" ." << "\033[0m" << endl;
        }
        m.DayTillDL = 2;
        cout << "\n";
    }
}

void menu()
{

    while (!menuend)
    {
        cout << "\033[0;33m" << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n" << "\033[0m";
        cout << "\033[0;33m" << "=" << "\033[1;90m" << "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/" << "\033[0;33m" << "=\n" << "\033[0m";
        cout << "\033[0;33m" << "*" << "\033[1;90m" << "\\/\\/\\/\\/\\/\\/ " << "\033[0m";
        cout << "FISH FOR LIVE";
        cout << "\033[1;90m" << " /\\/\\/\\/\\/\\/\\" << "\033[0;33m" << "*\n" << "\033[0m";
        cout << "\033[0;33m" << "=" << "\033[1;90m" << "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/" << "\033[0;33m" << "=\n" << "\033[0m";
        cout << "\033[0;33m" << "*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n" << "\033[0m";
        cout << "\n";
        cout << "What would you like to do?\n";
        cout << "--------  --------\n";
        cout << "|";
        cout << "\033[0;32m" << " PLAY " << "\033[0m";
        cout << "|  |";
        cout << "\033[1;31m" << " QUIT " << "\033[0m";
        cout << "|\n";
        cout << "--------  --------\n";
        cout << "\033[1;30m" << "Enter your action : " << "\033[0m";
        string action01;
        cin >> action01;
        cout << "\n";
        if (toUpperStr(action01) == "PLAY")
        {
            string storyskip;
            cout << "\033[1;30m" << "Do you to skip the prologue (Type \"YES\" or \"NO\"): " << "\033[0m";
            cin >> storyskip;
            if (toUpperStr(storyskip) == "NO")
            {
                cout << "=========================================\n";
                cout << "\n";
                typeText("Once upon a time, there was a fisherman's house where a small family lived.\n", 20);
                typeText("The family had a good reputation because of their fishing skills.\n", 20);
                typeText("However, there was one problem: Grandpa had a gambling addiction.\n", 20);
                typeText("He would sneak out at night to gamble, causing the family's savings to dwindle gradually.\n", 20);
                typeText("Eventually, he accumulated a large amount of debt, leading debtors to invade their home.\n", 20);
                cout << "|\n";
                typeText("Debtor: \"Get out of this house!It's mine now.\"\n", 20);
                typeText("Fisherman: \"Wait, what's happening? Please,explain.\"\n", 20);
                typeText("Debtor: \"That old man owes me a fortune!I'm here to collect!\"\n", 20);
                typeText("Fisherman: \"How much does he owe ? \"\n", 20);
                typeText("Debtor: \"10 million dollars!\"\n", 20);
                typeText("Fisherman: \"That's impossible! How can I come up with that much money?\"\n", 20);
                typeText("Debtor: \"It's not my problem! Pay up or face the consequences! I'll take over this place!\"\n", 20);
                typeText("Fisherman: \"Alright, but can I pay in installments ? I'll give you as much as I can.\"\n", 20);
                typeText("Debtor: \"Fine, but don't try to cheat me! Otherwise, you'll regret it!You'll have nowhere to sleep!\"\n", 20);
                typeText("Debtor: \"And if you fail to earn enough money, you'll face the full force of my wrath!\".\n", 20);
                cout << "|\n";
                typeText("After that, the furious debtors stormed out, leaving the fisherman scrambling to work and save his family.\n", 20);
                cout << "\n";
                cout << "=========================================\n";
                player.end = false;
                menuend = true;
            }
            else if (toUpperStr(storyskip) == "YES")
            {
                player.end = false;
                menuend = true;
            }
            else
            {
                cout << "\033[1;31m" << "!!!Invalid input. Please choose again.!!!\n" << "\033[0m";
            }
            cout << "\n";
        }
        else if (toUpperStr(action01) == "QUIT")
        {
            player.end = true;
            menuend = true;
        }
        else
        {
            cout << "\033[1;31m" << "!!!Invalid input. Please choose again.!!!\n" << "\033[0m";
            cout << "\n";
        }
    }

}

void Stat()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "\033[1;31m" << "=============== Show Stat ===============\n" << "\033[0m";
    cout << "\n";
    cout << "Day : " << m.DayPlayed << " (" << m.DayTillDL << " Days untill the Dealine.)" << endl;
    cout << "Destination : " << player.location << endl;
    cout << "You have made " << "\033[0;32m" << player.money << "\033[0m" << "/" << m.QuotaMoney << " for this round." << endl;
    cout << "Your have " << "\033[0;32m" << player.money << "\033[0m" << "$ for now." << endl;
    cout << "Boat's level = " << player.boat_lvl << ", Rod's level " << player.rod_lvl << endl;
    cout << "Your need more " << "\033[1;31m" << m.QuotaLimit << "\033[0m" << "$ to pay all of your debt." << endl;
    cout << "\033[1;31m" << "-----------------------------------------\n" << "\033[0m";
}
void Inventory(string bag[], int size, int allcost[]) {
    vector<pair<string, int>> count;

    // Count occurrences of each string
    for (int i = 0; i < size; ++i) {
        bool found = false;
        for (auto& p : count) {
            if (p.first == bag[i]) {
                p.second++;
                found = true;
                break;
            }
        }
        if (!found) {
            count.push_back({ bag[i], 1 });
        }
    }

    // Print counts of each string
    for (const auto& p : count) {
        std::cout << "You have " << p.second << " " << p.first << endl;
    }
    int totalprice = 0;
    for (int i = 0; i <= size; i++)
    {
        totalprice += allcost[i];

    }
    cout << "You can make " << "\033[1;34m" << totalprice << "\033[0m" << " for now. " << endl;
}
void SetTime(int addH, int addM)
{
    m.TMin += addM;
    m.THour += addH + m.TMin / 60;
    if (m.THour >= 18)
    {
        m.DayPlayed += 1;
        m.DayTillDL -= 1;
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
    else if (act == "TIMESKIP"|| act == "TS") //cheatcode
    {
        SetTime(18, 0);
    }
    else if (act == "ADDMONEY" || act == "AM") //cheatcode
    {
        int addcash = 0;
        cout << "how much do you want to add? :";
        cin >> addcash;
        player.money += addcash;
    }
    else if (act == "TANK")
    {
        cout << "\033[1;34m" << "=============== Your Tank ===============\n" << "\033[0m";
        cout << "\n";
        if (fish.slotfish == 0)
        {
            cout << "You have nothing in your fish tank\n";
            cout << "\033[1;34m" << "-----------------------------------------\n" << "\033[0m";
        }
        else
        {
            Inventory(fish.fishN, fish.slotfish, fish.fish_amount);
            cout << "\033[1;34m" << "-----------------------------------------\n" << "\033[0m";
        }
    }
    else if (act == "FISHING" || act == "FISH")
    {
        HANDLE F = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(F, 3);
        int ec = rand() % 100 + 1;// 20+1;
        if (ec <= 25)
        {
            event.EventStart(player.money, fish.fish_amount, fish.slotfish, fish.fishN);
        }
        else
        {
            fish.GoFishing(player.rod_lvl);
        }
        int ahour = rand() % 2 + 1;
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
            for (int i = 0; i < sizeof(fish.fishN) / sizeof(fish.fishN[0]); ++i) {
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
        cout << "\033[1;31m" << "=========================================\n" << "\033[0m";
        cout << "\033[1;31m" << "\nInvalid input. Please choose again.\n" << "\033[0m";
    }

}
int main()
{
    menu();
    string playeraction;
    while (!player.end)
    {
        HANDLE C = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "=========================================\n";
        cout << "\n";
        travel.IsTraveled = false;
        cout << "Day : " << m.DayPlayed << " (" << m.DayTillDL << " Days untill the Dealine.)" << endl;
        showtime(m.THour, m.TMin);
        cout << "\n";
        cout << "What would you like to do?\n";
        cout << "\n";
        cout << "---------------------------------------------\n";
        cout << "|\"Stat\" : Check your status.                |\n";
        cout << "|\"Tank\" : Check your fish storage.          |\n";
        cout << "|\"Fishing\" : Cast a rod.                    |\n";
        cout << "|\"Travel\" : Go to fishing area.             |\n";
        cout << "|\"Shop\" : Upgrade tools or Sell your fishes.|\n";
        cout << "---------------------------------------------\n";

        cout << "\n";
        SetConsoleTextAttribute(C, 15);
        cout << "\033[1;30m" << "Enter your action : " << "\033[0m";
        cin >> playeraction;
        Action(toUpperStr(playeraction));
        cout << "\n";
        SetConsoleTextAttribute(C, 7);
        Quotacheck();
    }
    cout << "\033[1;31m" << "=========================================\n" << "\033[0m";
    cout << "\n";
    cout << "\033[1;31m" << "Game Over\n" << "\033[0m";
    cout << "You have survived "<< m.DayPlayed-1 << " Days.\n";
    cout << "\n";
    cout << "\033[1;31m" << "=========================================\n" << "\033[0m";
    cout << "\n";
}