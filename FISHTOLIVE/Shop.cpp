#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "Shop.h"
#include "Fishing.h"
#include "Main.h"

using namespace std;

int Shop::boatlevel(int player_boatlevel) {
    int boatprice;
    if (player_boatlevel == 2) {
        boatprice = 430;
        return boatprice;
    }
    else if (player_boatlevel == 3) {
        boatprice = 940;
        return boatprice;
    }
    else if (player_boatlevel == 4) {
        boatprice = 2180;
        return boatprice;
    }
    else if (player_boatlevel == 5) {
        boatprice = 4680;
        return boatprice;
    }
    else if (player_boatlevel == 6) {
        boatprice = 50000;
        return boatprice;
    }
    else {
        cout << "Your boat is max level ";
        return 0;
    }

}

int Shop::rodlevel(int player_rodlevel) {
    int rodprice;
    if (player_rodlevel == 2) {
        rodprice = 200;
        return rodprice;
    }
    else if (player_rodlevel == 3) {
        rodprice = 450;
        return rodprice;
    }
    else if (player_rodlevel == 4) {
        rodprice = 1080;
        return rodprice;
    }
    else if (player_rodlevel == 5) {
        rodprice = 2600;
        return rodprice;
    }
    else if (player_rodlevel == 6) {
        rodprice = 6400;
        return rodprice;
    }
    else if (player_rodlevel == 7) {
        rodprice = 20000;
        return rodprice;
    }
    else {
        cout << "Your rod is max level ";
        return 0;
    }

}

void Shop::upgrade(int& money,int &player_boatlevel,int &player_rodlevel)
{
    int shopaction;
    do
    {
        cout << "=========================================\n";
        cout << "\n";
        cout << "Which gear do you to upgrade?\n";
        if (player_rodlevel == 7)
        {
            cout << "Your rod is max level.\n";
        }
        else
        {
            cout << "Fishing rod level" << player_rodlevel + 1<< " ,upgrade price = " << rodlevel(player_rodlevel + 1) << endl;
        }
        if (player_boatlevel == 6)
        {
            cout << "Your boat is max level.\n";
        }
        else
        {
            cout << "Boat level " << player_boatlevel + 1 << " ,upgrade price = " << boatlevel(player_boatlevel + 1) << endl;
        }
            
        cout << "\n";
        cout << "Your boat level = " << player_boatlevel << ",Your fishing rod level = " << player_rodlevel<<"." << endl;
        cout << "Your have " << money << "$ for now." << endl;
        cout << "[1] fishing rod [2] boat [3] quit -> ";
        cin >> shopaction;
        cout << "\n";
        if (shopaction == 1) 
        {
            int rodp = rodlevel(player_rodlevel + 1);
            if (player_rodlevel < 7)
            {
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
            else
            {
                cout << "Your rod is max level";
            }
            
        }
        else if (shopaction == 2) 
        {
            int boatp = boatlevel(player_boatlevel + 1);
            if (player_boatlevel < 7)
            {
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
                cout << "Your rod is max level";
            }
            //upgrade boat
            
        }
        else 
        {
            cout << "Invalid input. Please choose again." << endl;
            cin.clear();    // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }while (shopaction != 3);
}

void Shop::sell(int fish_amount[],int& slotfish,int &money)
{
    int shopsell = 0;
    do
    {
        cout << "=========================================\n";
        cout << "\n";
        cout << "Do you really want to sell all fish?\n";
        cout << "[1] YES [2] NO -> ";
        cin >> shopsell;
        cout << "\n";
        if (shopsell == 1)
        {
            if(slotfish <= 0)
            {
                cout << "Why are you here? You don't have any fish to sell." << endl;
            }
            else
            {
                int totalprice = 0;
                for (int i = 0; i <= slotfish; i++) 
                {
                     totalprice += fish_amount[i];

                }
                cout << "You got  " << totalprice << " from selling " << slotfish << " fishes." << endl;
                money += totalprice;
                cout << "Your have " << money << "$ for now." << endl;
                for (int i = 0; i <= slotfish; i++) 
                {
                    fish_amount[i] = 0;
                }
                slotfish = 0;
            }
            
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

void Shop::ShopControl(int& money, int& boatlvl, int& rodlvl, int fishamount[], int& slotfish)
{
    int shopact = 0;
    do {
        cout << "=========================================\n";
        cout << "\n";
        cout << "Welcome to the shop\n";
        cout << "What do you want?\n" << "[1] Upgrade [2] Sell [3] Exit -> ";
        cin >> shopact;
        cout << "\n";
        if (shopact == 1)
            upgrade(money, boatlvl, rodlvl);
        else if (shopact == 2)
            sell(fishamount, slotfish, money);
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