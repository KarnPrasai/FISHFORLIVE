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
    int Old_location = f.playergoing;
    cout << "Which place do you want to go?\n";
    cout << "================================\n";
    for (int i = 0; i < 6; i++)
    {
        cout << " " << i + 1 << " " << FishingArea[i] << ".";
        cout << " (Require Boat level " << i + 1 << ") \n.";
    }
    cout << "================================\n";
    cout << "Input Number of the place : ";
    int placeinput;
    cin >> placeinput;
    PlaceChecker(placeinput,Old_location);
}

void Travel::PlaceChecker(int placeinput,int Old_lo)
{
    if (p.location != FishingArea[placeinput - 1])
    {
        if (placeinput <= p.boat_lvl)
        {
            cout << "Going to " << FishingArea[placeinput - 1] << endl;
            p.location = FishingArea[placeinput - 1];
            f.playergoing = placeinput;
            IsTraveled = true;
        }
        else if(placeinput > p.boat_lvl)
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
