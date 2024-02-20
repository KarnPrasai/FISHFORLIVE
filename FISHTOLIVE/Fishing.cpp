#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Fishing.h"

using namespace std;

void Fishing::GoFishing()
{
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
            cout << "Fish hooked!\n";
            HookAFish();
        }
        else
        {
            cout << "Oh no!!, The fish was gone.\n";
        }

    }


void Fishing::HookAFish()
{
    cout << "Caught!!\n";
    string action[] = { "Up", "Down", "Left", "Right" };
    string namefish[6][7] = { {"aaa1","bbb1","ccc1","ddd1","eee1","fff1","ggg1"},{"aaa2","bbb2","ccc2","ddd2","eee2","fff2","ggg2"} ,{ "aaa3","bbb3","ccc3","ddd3","eee3","fff3","ggg3" }, { "aaa4","bbb4","ccc4","ddd4","eee4","fff4","ggg4" } ,{ "aaa5","bbb5","ccc5","ddd5","eee5","fff5","ggg5" }, { "aaa6","bbb6","ccc6","ddd6","eee6","fff6","ggg6" } };
    int count = 0;
    int slotfish = 0;
    int typefish = rand() % 7;
    for (int i = 0; i < typefish + 1; ++i)
    {
        int fishact = rand() % 4;
        cout << "Go " << action[fishact] << " : ";
        string playerAction;
        string input;
        cin >> playerAction;


        if (playerAction == action[fishact])
        {
            count++;
            if (count == typefish + 1)
            {
                cout << "Gotcha!! You got " << namefish[playergoing - 1][typefish] << "\n";
                fish[slotfish] = namefish[playergoing - 1][typefish];
                slotfish += 1;
            }
        }
        else
        {
            cout << "No!!, The line was broken by the fish.\n";
        }
    }
