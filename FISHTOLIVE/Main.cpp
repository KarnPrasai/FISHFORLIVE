#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Shop.h"
#include "Fishing.h"

using namespace std;

class Player
{
public:
    int money = 0;
    int boat_lvl = 1;
    int playergoing;
    string FishingArea[7] = { "River","Lake","Beach","Sea","Deep Sea","Island" };
    void PlaceTravel();
    void PlaceChecker(int);
    void Shop();


};

void Player::PlaceTravel()
{
    string FishingArea[] = { "River","Lake","Beach","Sea","Deep Sea","Island" };
    cout << "Which place do you want to go?\n";
    cout << "================================\n";
    for (int i = 0; i < 6; i++)
    {
        cout << " " << i + 1 << " " << FishingArea[i] << ". \n";
    }
    cout << "================================\n";
    cout << "Input Number of the place :";
    cin >> playergoing;
    cout << "Going to " << FishingArea[playergoing - 1] << "\n";
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


int main()
{
    Player p;
    Fishing pp;
    p.PlaceTravel();
    pp.playergoing = p.playergoing;
    pp.GoFishing();
    //p.Shop();
}
