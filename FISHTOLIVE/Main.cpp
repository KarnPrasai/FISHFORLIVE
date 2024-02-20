#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Shop.h"
#include "Main.h"
#include "Fishing.h"
#include "Travel.h"

using namespace std;

void Stat()
{
    Player player;
    cout << "Day : " << player.DayPlayed << endl;
    cout << "Destination : " << player.location << endl;
    cout << "You have made " << player.money << "/" << player.QuotaMoney << " for this round." << endl;
}

int main()
{
    Player player;
    Fishing fish;
    Travel travel;
    while (!player.end)
    {
        cout << "What would you like to do?\n";
        cout << "|| Stat || Fish || Travel || Shop || \n";
        cout << "Enter your action : ";
        string Action;
        cin >> Action;
        if (Action == "Stat")
        {
            Stat();
        }
        else if (Action == "Fish")
        {
            fish.GoFishing();
        }
        else if (Action == "Travel")
        {
            travel.PlaceTravel();
        }
        if (Action == "Shop")
        {

        }
        if (Action == "End")
        {
            player.end = true;
        }
    }
    //p.Shop();
}

