#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "Shop.h"

using namespace std;

//funtion call
//advantage of level function

int Shop::boatlevel(int player_boatlevel) {
    int boatprice;
    if (player_boatlevel == 1) {
        boatprice == 50;
        return boatprice;
    }
    else if (player_boatlevel == 2) {
        boatprice == 100;
        return boatprice;
    }
    else if (player_boatlevel == 3) {
        boatprice == 150;
        return boatprice;
    }
    else if (player_boatlevel == 4) {
        boatprice == 170;
        return boatprice;
    }
    else {
        cout << "This is max level";
        return 0;
    }

}

int Shop::rodlevel(int player_rodlevel) {
    int rodprice;
    if (player_rodlevel == 1) {
        rodprice == 60;
        return rodprice;
    }
    else if (player_rodlevel == 2) {
        rodprice == 80;
        return rodprice;
    }
    else if (player_rodlevel == 3) {
        rodprice == 100;
        return rodprice;
    }
    else if (player_rodlevel == 4) {
        rodprice == 120;
        return rodprice;
    }
    else {
        cout << "This is max level";
        return 0;
    }

}

void Shop::upgrade(int& money,int &player_boatlevel,int &player_rodlevel)
{
    
    cout << "Which gear do you to upgrade?\n";
    cout << "[1] fishing rod [2] boat [3] quit\n";
    cout << "Fishing rod upgrade price = " << rodlevel(player_boatlevel + 1) << endl;
    cout << "Boat upgrade price = " << boatlevel(player_rodlevel + 1) << endl;
    cout << " Your money = " << money<<endl;
    int shopaction;
    do
    {
        cin >> shopaction;
        if (shopaction == 1) 
        {

            player_rodlevel += 1;
            money -= rodlevel(player_boatlevel);
            cout << "Your money = "<<money<<endl;
            //upgrade fishing rod
        }
        else if (shopaction == 2) 
        {

            player_boatlevel += 1;
            money -= boatlevel(player_boatlevel) << money;
            cout << "Your money = " << money<<endl;
            //upgrade boat
        }

        else 
        {
            cout << "action not found"<<endl;
        }
    }while (shopaction != 3);
}

void Shop::sell(int fish_amount[],int slotfish,int &money)
{
    cout << "Do you really want to sell all fish?\n";
    cout << "[1] YES [2] NO \n" << "->";
    int shopsell;
    
    do
    {
        cin >> shopsell;
        if (shopsell == 1)
        {
            int totalprice;
            for (int i = 0; i <= slotfish; i++) {
                totalprice += fish_amount[i];

            }
            for (int i = 0; i <= slotfish; i++) {
                fish_amount[i] = 0;

            }
            money += totalprice;
            cout << "Your money = " << money<<endl;
            
        }
        else
        {
            cout << "action not found"<<endl;
        }
    } while (shopsell != 2);
    cout << "Good luck sir"<<endl;

}