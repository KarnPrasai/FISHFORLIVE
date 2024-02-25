#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "Shop.h"
#include "Fishing.h"
#include "Main.h"
using namespace std;

//funtion call
//advantage of level function

Player ps;
Fishing fs;
Shop shopcall;
int Shop::boatlevel(int player_boatlevel) {
    int boatprice;
    if (player_boatlevel == 1) {
        boatprice = 50;
        return boatprice;
    }
    else if (player_boatlevel == 2) {
        boatprice = 100;
        return boatprice;
    }
    else if (player_boatlevel == 3) {
        boatprice = 150;
        return boatprice;
    }
    else if (player_boatlevel == 4) {
        boatprice = 170;
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
        rodprice = 60;
        return rodprice;
    }
    else if (player_rodlevel == 2) {
        rodprice = 80;
        return rodprice;
    }
    else if (player_rodlevel == 3) {
        rodprice = 100;
        return rodprice;
    }
    else if (player_rodlevel == 4) {
        rodprice = 120;
        return rodprice;
    }
    else {
        cout << "This is max level";
        return 0;
    }

}

void Shop::Shopcontrol()
{
    int shopact = 0;
    do
    {

        cout << "=========================================\n";
        cout << "Welcome to the shop\n";
        cout << "What do you want?\n" << "[1] Upgrade [2] Sell [3] Exit -> ";
        cin >> shopact;
        if (shopact == 1)
            shopcall.upgrade(ps.money, ps.boat_lvl, ps.rod_lvl);
        else if (shopact == 2)
            shopcall.sell(fs.fish_amount, fs.slotfish, ps.money);
        else if (shopact == 3)
            break;  // Exit the loop if the user chooses to quit
        else {
            cout << "Invalid Input, Please try again\n";
            cin.clear();    // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    } while (true);  // Loop indefinitely until the user chooses to quit
    cout << "Goodbye\n";
}

void Shop::upgrade(int& money,int &player_boatlevel,int &player_rodlevel)
{
    int shopaction;
    do
    {
        cout << "=========================================\n";
        cout << "Which gear do you to upgrade?\n";
        cout << "Fishing rod level" << player_rodlevel + 1 << " ,upgrade price = " << rodlevel(player_rodlevel + 1) << endl;
        cout << "Boat level " << player_boatlevel + 1 << " ,upgrade price = " << boatlevel(player_boatlevel + 1) << endl;
        cout << "Your have " << money << "$ for now." << endl;
        cout << "[1] fishing rod [2] boat [3] quit -> ";
        cin >> shopaction;
        if (shopaction == 1) 
        {
            int rodp = rodlevel(player_rodlevel + 1);
            if (money >= rodp)
            {
                player_rodlevel += 1;
                money -= rodp;
                cout << "Your have" << money << "$ Left." << endl;
            }
            else
            {
                cout << "You don't have enough money.";
            }
        }
        else if (shopaction == 2) 
        {
            int boatp = boatlevel(player_boatlevel + 1);
            //upgrade boat
            if (money >= boatp)
            {
                player_boatlevel += 1;
                money -= boatp;
                cout << "Your have" << money << "$ Left." << endl;
            }
            else
            {
                cout << "You don't have enough money.";
            }
        }
        else 
        {
            cout << "Invalid input. Please choose again." << endl;
            cin.clear();    // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }while (shopaction != 3);
}

void Shop::sell(int fish_amount[],int slotfish,int &money)
{
    int shopsell = 0;
    do
    {
        cout << "=========================================\n";
        cout << "Do you really want to sell all fish?\n";
        cout << "[1] YES [2] NO -> ";
        cin >> shopsell;
        if (shopsell == 1)
        {
            int totalprice = 0;
            for (int i = 0; i <= slotfish; i++) 
            {
                totalprice += fish_amount[i];

            }
            for (int i = 0; i <= slotfish; i++) 
            {
                fish_amount[i] = 0;
            }
            cout << "You got  " << totalprice << " from selling " << slotfish << " fishes." << endl;
            money += totalprice;
            cout << "Your have " << money << "$ for now." << endl;
            for (int i = 0; i <= slotfish; i++) {
                fish_amount[i] = 0;
            }
            slotfish = 0;
        }
        else if (shopsell == 2) 
        {
            cout << "You decided not to sell fish." << endl;
        }
        else
        {
            cout << "Invalid input. Please choose again." << endl;
            cin.clear();    // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    } while (shopsell !=1 && shopsell != 2);
    cout << "Good luck sir"<<endl;

}

