#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Fishing.h"


using namespace std;

int FishChance(int& a)
{
    srand(time(NULL));

    int hook[20][20] = { {40,65,80,90,97,99,100},{33,60,75,86,95,98,100}, {26,56,73,84,94,98,100}, {20,48,68,81,92,97,100}, {17,37,62,78,90,97,100}, {15,26,40,65,85,95,100},{10,25,40,50,75,90,100} };
    int per = rand() % 100 + 1;
    if (per <= hook[a - 1][0])
    {
        return 1;
    }
    else if (per <= hook[a - 1][1])
    {
        return 2;
    }
    else if (per <= hook[a - 1][2])
    {
        return 3;
    }
    else if (per <= hook[a - 1][3])
    {
        return 4;
    }
    else if (per <= hook[a - 1][4])
    {
        return 5;
    }
    else if (per <= hook[a - 1][5])
    {
        return 6;
    }
    else if (per <= hook[a - 1][6])
    {
        return 7;
    }


}

void Fishing::GoFishing(int& a)
{
    cout << "\033[1;93m" << "======================" << "\033[1;37m" << "|" << "\033[1;93m" << "=]                 \n" << "\033[0m";
    cout << "\033[1;37m" << "                      |                  \n" << "\033[0m";
    cout << "\033[1;37m" << "                      |                  \n" << "\033[0m";
    cout << "\033[1;97m" << ".o0o.._.o00o.o0o0o...o" << "\033[1;37m" << "|" << "\033[1;97m" << "o..__..o00o._o0o..\n" << "\033[0m";
    cout << "\033[1;96m" << ":..o00o._.o0o..o00o0o." << "\033[1;37m" << "|" << "\033[1;96m" << "_.o0o._.o0o.._o0o.\n" << "\033[0m";
    cout << "\033[1;94m" << "_____-------______-(" << "\033[1;37m" << "((0))" << "\033[1;94m" << ")------___----__\n" << "\033[0m";
    cout << "\033[0;34m" << "---___--_____-____---___------___-----__-\n" << "\033[0m";
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
    cout << "\n";
    if (input == "Hook")
    {
        HookAFish(a);
    }
    else
    {
        cout << "\033[1;91m" << "Oh no!!, The fish was gone.\n" << "\033[0m";
    }

}


void Fishing::HookAFish(int& a)
{
    cout << "\033[1;93m" << "Fish hooked!\n" << "\033[0m";
    cout << "\n";
    string action[] = { "Up", "Down", "Left", "Right" };
    string namefish[6][7] = { {"Crawfish","Carp","Blue gill","Bass","Bream","Trout","Salmon"},
                               {"Catfish","Cod","Bull Head","Perch","Salmon","Pike","Sturgoen"} ,
                               { "Anchovy","Crab","Herring","Halibut","Lionfish","Flounder","Eel" },
                               { "Red Mullet","Sardine","Albacore","Octopus","Pufferfish","Tiger Shark","Dolphin" } ,
                               { "Squid","Grouper","BlueMarlin","Sunfish","Orca","Tuna","Great White Shark" },
                               { "Moby Dick","Megalodon","Kraken","Leviathan","The Bloop","Hydra","Godzilla" } };
    int costfish[6][7] = { {10,20,30,40,50,60,70},{15,30,45,60,80,108,210},
                         {20,40,60,82,120,216,630}, {25,50,75,100,180,389,1890},
                         {30,60,102,225,470,820,5670},{12257,20671,36857,51328,96517,170542,497324} };
    int count = 0;
    int typefish = FishChance(a);
    for (int i = 0; i < typefish; ++i)
    {
        int fishact = rand() % 4;
        cout << "Go " << action[fishact] << "(Type \"" << action[fishact] << "\") : ";
        string playerAction;
        string input;
        cin >> playerAction;
        if (playerAction == action[fishact])
        {
            count++;
            if (count == typefish)
            {
                cout << "\033[1;93m" << "=========================================\n" << "\033[0m";
                cout << "\033[1;90m" << "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n" << "\033[0m";
                cout << "\033[1;90m" << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n" << "\033[0m";
                cout << "\n";
                cout << "Gotcha!! You got " << "\033[1;93m" << namefish[playergoing - 1][typefish - 1] << "\n" << "\033[0m";
                cout << "cost " << "\033[1;93m" << costfish[playergoing - 1][typefish - 1] << "\n" << "\033[0m";
                cout << "\n";
                cout << "\033[1;90m" << "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n" << "\033[0m";
                cout << "\033[1;90m" << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n" << "\033[0m";
                cout << "\033[1;93m" << "=========================================\n" << "\033[0m";
                char namef[100];
                int costf;
                fish_amount[slotfish] = costfish[playergoing - 1][typefish - 1];
                fishN[slotfish] = namefish[playergoing - 1][typefish - 1];
                slotfish += 1;
                break;
            }
        }
        else
        {
            cout << "\n";
            cout << "\033[1;91m" << "No!!, The line was broken by the fish.\n" << "\033[0m";
            break;
        }
    }

}