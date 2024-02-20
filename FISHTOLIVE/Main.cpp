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
    string FishingArea[7] = { "River","Lake","Beach","Sea","Deep Sea","Island" };
    void PlaceTravel();
    void PlaceChecker(int);
    void Shop();


};

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


int main()
{
    Player p;
    //p.GoFishing();
    //p.PlaceTravel();
    p.Shop();
}
