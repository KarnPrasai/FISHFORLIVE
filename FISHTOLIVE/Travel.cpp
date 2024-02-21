#include <iostream>
#include <string>
#include "Travel.h"
#include "Main.h"
#include "Fishing.h"

using namespace std;
Player p;
Fishing f;

void Travel::PlaceTravel()
{
    Fishing f;
    int Old_location = f.playergoing;
    cout << "Which place do you want to go?\n";
    cout << "================================\n";
    for (int i = 0; i < 6; i++)
    {
        cout << " " << i + 1 << " " << FishingArea[i] << ". \n";
    }
    cout << "================================\n";
    cout << "Input Number of the place : ";
    int placeinput;
    cin >> placeinput;
    PlaceChecker(placeinput,Old_location);
}

void Travel::PlaceChecker(int playergoing,int Old_lo)
{
    if (p.location != FishingArea[playergoing - 1])
    {
        if (p.boat_lvl >= playergoing)
        {
            cout << "Going to " << FishingArea[playergoing - 1] << endl;
            p.location = FishingArea[playergoing - 1];
            f.playergoing = playergoing;
            IsTraveled = true;
        }
        else if (p.boat_lvl < playergoing)
        {
            cout << "You cannot go there!!. Upgrade your boat first\n";
            f.playergoing = Old_lo;
        }
        else
        {
            cout << "You cannot go there!!. It's not the way to go\n";
        }
    }
    else
    {
        cout << "You have been here. Why you need to go?\n";
    }
}
