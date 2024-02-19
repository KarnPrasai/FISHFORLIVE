#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class Player
{
public:
    int money = 0;
    int boat_lvl = 1;
    string FishingArea[7] = { "River","Lake","Beach","Sea","Deep Sea","Island" };
    void GoFishing();
    void HookAFish();
    void PlaceTravel();
    void PlaceChecker(int);
    void Shop();


};

void Player::GoFishing()
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

void Player::HookAFish()
{
    cout << "Caught!!\n";
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

void Player::PlaceTravel()
{
    cout << "Input your Boat level :";
    cin >> boat_lvl;
    int playergoing;
    cout << "Which place do you want to go?\n";
    cout << "================================\n";
    for (int i = 0; i < 6; i++)
    {
        cout << "|| " << i + 1 << " " << FishingArea[i] << ". ||\n";
    }
    cout << "================================\n";
    cout << "Input Number of the place :";
    cin >> playergoing;
    PlaceChecker(playergoing);

}

void Player::PlaceChecker(int playergoing)
{
    if (boat_lvl >= playergoing)
    {
        cout << "Going to " << FishingArea[playergoing - 1];
    }
    else
    {
        cout << "You cannot go there!!. Upgrade your boat first";
    }
}

void Player::Shop()
{
    struct Rod {
        string name;
        int cost;
    };
    cout << "you can upgrade your stuff here.\n";
    cout << "================================\n";

}

int main()
{
    Player p;
    //p.GoFishing();
    p.PlaceTravel();
}
