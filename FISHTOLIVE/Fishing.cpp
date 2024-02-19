#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Fishing.h"

using namespace std;

void Fishing::GoFishing()
{

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
}


void Fishing::HookAFish()
{

    string action[] = { "Up", "Down", "Left", "Right" };

    int count = 0;

    for (int i = 0; i < 4; ++i)
    {
        int fishact = rand() % 4;
        cout << "Go " << action[fishact] << " : ";
        string playerAction;
        string input;
        cin >> playerAction;


        if (playerAction == action[fishact])
        {
            count++;
            if (count == 4)
            {
                cout << "Gotcha!!\n";

            }
        }
        else
        {
            cout << "No!!, The line was broken by the fish.\n";
        }
    }
}
