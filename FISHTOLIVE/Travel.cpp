#include <iostream>
#include <string>
#include "Travel.h"
#include "Main.h"
#include "Fishing.h"

using namespace std;


void Travel::PlaceTravel(string& location,int& playergoing,int& boatlvl)
{
    int Old_location = playergoing;
    cout << "Which place do you want to go?\n";
    cout << "================================\n";
    cout << "\n";
    for (int i = 0; i < 6; i++)
    {
        cout << " " << i + 1 << " " << FishingArea[i] << ".";
        cout << " (Require Boat level " << i + 1 << ") .\n";
    }
    cout << "\n";
    cout << "================================\n";
    cout << "\n";
    cout << "Input Number of the place : ";
    int placeinput;
    cin >> placeinput;
    if (!(cin >> placeinput))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input! Please enter a number between 1 and 6.\n";
        return;
    }
    PlaceChecker(placeinput, Old_location, location, playergoing, boatlvl);
}

void Travel::PlaceChecker(int placeinput,int Old_lo,string& playerlocation,int& playergoing,int& boatlvl)
{
    cout << "================================\n";
    cout << "\n";
    if (playerlocation != FishingArea[placeinput - 1])
    {
        if (placeinput <= boatlvl)
        {
            cout << "Going to " << FishingArea[placeinput - 1] << endl;
            playerlocation = FishingArea[placeinput - 1];
            playergoing = placeinput;
            IsTraveled = true;
        }
        else if(placeinput > boatlvl)
        {
            cout << "You cannot go there!!. Upgrade your boat first\n";
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
