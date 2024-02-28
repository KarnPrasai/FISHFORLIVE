#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Fishing.h"


using namespace std;

int FishChance()
{
    srand(time(NULL));
    int per = rand() % 100 + 1;
    if (per <= 40)
    {
        return 1;
    }
    if (per <= 65&& per > 40)
    {
        return 2;
    }
    if (per <= 80 && per > 65)
    {
        return 3;
    }
    if (per <= 90 && per > 80)
    {
        return 4;
    }
    if (per <= 97 && per > 90)
    {
        return 5;
    }
    if (per <= 99 && per > 97)
    {
        return 6;
    }
    if (per == 100)
    {
        return 7;
    }

}

void Fishing::GoFishing()
{
    cout << "=========================================\n";
    cout << "\n";
    atomic<bool> stopAnimation(false);
    std::atomic<bool> fishHooked(false);
    thread animationThread([&]()
        {
            while (!stopAnimation)
            {

                cout << "\rSteady." << flush;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "\rSteady.." << flush;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "\rSteady..." << flush;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "\rSteady   " << flush;

            }
        });
    srand(time(NULL));
    int waitTime = rand() % 3 + 2;
    this_thread::sleep_for(chrono::seconds(waitTime));
    stopAnimation = true;
    animationThread.join();
    string input;
    cout << "\nHook!! (Type \"Hook\") : " << flush;
    cin >> input;
    if (input == "Hook")
    {
        HookAFish();
    }
    else
    {
        cout << "Oh no!!, The fish was gone.\n";
    }

}


void Fishing::HookAFish()
{
    cout << "\n";
    cout << "Fish hooked!\n";
    cout << "\n";
    string action[] = { "Up", "Down", "Left", "Right" };
    string namefish[6][7] = { {"Crawfish","Carp","Bluegill","Bass","Bream","Trout","Salmon"},
                               {"Catfish","Cod","BullHead","Perch","Salmon","Pike","Sturgoen"} ,
                               { "Anchovy","Crab","Herring","Halibut","Lionfish","Flounder","Eel" }, 
                               { "Red_Mullet","Sardine","Albacore","Octopus","Pufferfish","TigerShark","Dolphin" } ,
                               { "Squid","Grouper","BlueMarlin","Sunfish","Orca","Tuna","GreatWhiteShark" }, 
                               { "Moby_Dick","Megalodon","Kraken","Leviathan","The_Bloop","Hydra","Godzilla" } };
    int costfish[6][7] = { {10,20,30,40,50,60,70},{15,30,45,60,80,108,210},
                         {20,40,60,82,120,216,630}, {25,50,75,100,180,389,1890},
                         {30,60,102,225,470,820,5670},{12257,20671,36857,51328,96517,170542,497324} };
    int count = 0;
    int typefish = FishChance();
    for (int i = 0; i < typefish; ++i)
    {
        int fishact = rand() % 4;
        cout << "Go " << action[fishact] << "(Type " << action[fishact] << ") : ";
        string playerAction;
        string input;
        cin >> playerAction;
        if (playerAction == action[fishact])
        {
            count++;
            if (count == typefish)
            {
                cout << "=========================================\n";
                cout << "\n";
                cout << "Gotcha!! You got " << namefish[playergoing-1][typefish-1] << "\n";
                cout <<"cost "<< costfish[playergoing-1][typefish-1] << "\n";
                char namef[100];
                int costf;
                fish_amount[slotfish] = costfish[playergoing-1][typefish-1];
                fish[slotfish] = namefish[playergoing-1][typefish-1];
                slotfish += 1;
                break;
            }
        }
        else
        {
            cout << "No!!, The line was broken by the fish.\n";
            break;
        }
    }

}
