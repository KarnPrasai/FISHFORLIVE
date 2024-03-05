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
    else 
    {
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
    else 
    {
        return 0;
    }

}

void Shop::upgrade(int& money, int& player_boatlevel, int& player_rodlevel)
{
    int shopaction;
    do
    {
        cout << "\033[1;97m" << " ________________________________        \n";
        cout << "\033[1;97m" << "|  Which gear do you to upgrade? \\       \n";
        cout << "\033[1;97m" << "\\_______  _______________________|       \n";
        cout << "         \\ |                              \n";
        cout << "          \\|     " << "\033[0;33m" << "________\n" << "\033[1;97m";
        cout << "                " << "\033[0;33m" << "/" << "\033[0;31m" << "________" << "\033[0;33m" << "\\                \n" << "\033[1;97m";
        cout << "             " << "\033[0;33m" << "___" << "\033[0;31m" << "|________|" << "\033[0;33m" << "___             \n" << "\033[1;97m";
        cout << "            " << "\033[0;33m" << "/________________\\            \n" << "\033[1;97m";
        cout << "              " << "\033[1;90m" << "< /\\|_\\|_|/\\ >              \n" << "\033[1;97m";
        cout << "               " << "\033[1;93m" << "(|" << "\033[1;90m" << "  0  0} " << "\033[1;93m" << "|)               \n" << "\033[1;97m";
        cout << "                " << "\033[1;93m" << "|   " << "\033[1;31m" << "\\/   " << "\033[1;93m" << "|                \n" << "\033[1;97m";
        cout << "            " << "\033[0;31m" << "_____" << "\033[1;93m" << "\\______/" << "\033[0;31m" << "_____            \n" << "\033[1;97m";
        cout << "           " << "\033[0;31m" << "/     (      )     \\           \n";
        cout << "          " << "\033[0;31m" << "/       |" << "\033[1;31m" << "\\  /" << "\033[0;31m" << "|       \\          \n" << "\033[1;97m";
        cout << "         " << "\033[0;31m" << "|    |   |" << "\033[1;31m" << " \\/ " << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
        cout << "         " << "\033[0;31m" << "|    |   |" << "\033[1;31m" << ">  <" << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
        cout << "         " << "\033[0;31m" << "|    |   | " << "\033[1;31m" << "/\\ " << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
        cout << "\033[1;31m" << "==========================================\n";
        cout << "\n";
        if (player_rodlevel >= 7)
        {
            cout << "\033[1;31m" << "Your rod is max level.\n";
        }
        else
        {
            cout << "\033[1;97m" << "Fishing rod level" << "\033[1;31m" << player_rodlevel + 1 << "\033[1;97m" << " ,upgrade price = " << "\033[1;31m" << rodlevel(player_rodlevel + 1) << endl;
            cout << "\033[1;31m" << "(Increase the rarity of fish that can be caught.)\n";
        }
        if (player_boatlevel >= 6)
        {
            cout << "\033[1;31m" << "Your boat is max level.\n";
        }
        else
        {
            cout << "\033[1;97m" << "Boat level " << "\033[1;31m" << player_boatlevel + 1 << "\033[1;97m" << " ,upgrade price = " << "\033[1;31m" << boatlevel(player_boatlevel + 1) << endl;
            cout << "\033[1;31m" << "(For traveling to the other place.)\n";
        }

        cout << "\n";
        cout << "\033[1;97m" << "Your boat level = " << "\033[0;32m" << player_boatlevel << "\033[1;97m" << ",Your fishing rod level = " << "\033[0;32m" << player_rodlevel << endl;
        cout << "\033[1;97m" << "Your have " << "\033[0;32m" << money << "\033[1;97m" << "$ for now." << endl;
        cout << "\033[1;93m" << "[1] " << "\033[1;97m" << "fishing rod " << "\033[1;93m" << "[2] " << "\033[1;97m" << "boat " << "\033[1;93m" << "[3] " << "\033[1;97m" << "quit " << "\033[1;93m" << "\nInput number of your action. --> ";
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
                    cout << "\033[1;31m" << "Your have " << "\033[0;32m" << money << "\033[1;97m" << "$ Left." << endl;
                }
                else
                {
                    cout << "\033[1;31m" << "You don't have enough money.\n";
                }
            }
            else
            {
                cout << "\033[1;31m" << "Your rod is max level\n";
            }

        }
        else if (shopaction == 2)
        {
            int boatp = boatlevel(player_boatlevel + 1);
            if (player_boatlevel < 6)
            {
                if (money >= boatp)
                {
                    player_boatlevel += 1;
                    money -= boatp;
                    cout << "\033[1;97m" << "Your have " << "\033[0;32m" << money << "\033[1;97m" << "$ Left." << endl;
                }
                else
                {
                    cout << "\033[1;31m" << "You don't have enough money.\n";
                }
            }
            else
            {
                cout << "\033[1;31m" << "Your boat is max level\n";
            }
            //upgrade boat

        }
        else
        {
            cout << "\033[1;31m" << "Invalid input. Please choose again.\n" << "\033[0m";
            cin.clear();    // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    } while (shopaction != 3);
}

void Shop::sell(int fish_amount[], int& slotfish, int& money)
{
    int shopsell = 0;
    do
    {
        cout << "\033[1;97m" << " ______________________________________  \n";
        cout << "\033[1;97m" << "| Do you really want to sell all fish? \\       \n";
        cout << "\033[1;97m" << "\\_______  _____________________________|       \n";
        cout << "         \\ |                              \n";
        cout << "          \\|     " << "\033[0;33m" << "________\n" << "\033[1;97m";
        cout << "                " << "\033[0;33m" << "/" << "\033[0;31m" << "________" << "\033[0;33m" << "\\                \n" << "\033[1;97m";
        cout << "             " << "\033[0;33m" << "___" << "\033[0;31m" << "|________|" << "\033[0;33m" << "___             \n" << "\033[1;97m";
        cout << "            " << "\033[0;33m" << "/________________\\            \n" << "\033[1;97m";
        cout << "              " << "\033[1;90m" << "< /\\|_\\|_|/\\ >              \n" << "\033[1;97m";
        cout << "               " << "\033[1;93m" << "(|" << "\033[1;90m" << "  0  0} " << "\033[1;93m" << "|)               \n" << "\033[1;97m";
        cout << "                " << "\033[1;93m" << "|   " << "\033[1;31m" << "\\/   " << "\033[1;93m" << "|                \n" << "\033[1;97m";
        cout << "            " << "\033[0;31m" << "_____" << "\033[1;93m" << "\\______/" << "\033[0;31m" << "_____            \n" << "\033[1;97m";
        cout << "           " << "\033[0;31m" << "/     (      )     \\           \n";
        cout << "          " << "\033[0;31m" << "/       |" << "\033[1;31m" << "\\  /" << "\033[0;31m" << "|       \\          \n" << "\033[1;97m";
        cout << "         " << "\033[0;31m" << "|    |   |" << "\033[1;31m" << " \\/ " << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
        cout << "         " << "\033[0;31m" << "|    |   |" << "\033[1;31m" << ">  <" << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
        cout << "         " << "\033[0;31m" << "|    |   | " << "\033[1;31m" << "/\\ " << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
        cout << "\033[1;31m" << "==========================================\n";
        cout << "\n";
        cout << "\033[1;93m" << "[1] " << "\033[1;97m" << "YES " << "\033[1;93m" << "[2] " << "\033[1;97m" << "NO " << "\033[1;93m" << "\nInput number of your action. --> ";
        cin >> shopsell;
        cout << "\n";
        if (shopsell == 1)
        {
            if (slotfish <= 0)
            {
                cout << "\033[1;31m" << "Why are you here? You don't have any fish to sell.\n" << endl;
            }
            else
            {
                int totalprice = 0;
                for (int i = 0; i <= slotfish; i++)
                {
                    totalprice += fish_amount[i];

                }
                cout << "\033[1;97m" << "You got  " << "\033[1;31m" << totalprice << "\033[1;97m" << " from selling " << "\033[1;31m" << slotfish << "\033[1;97m" << " fishes.\n";
                money += totalprice;
                cout << "\033[1;97m" << "Your have " << "\033[1;31m" << money << "\033[1;97m" << "$ for now.\n";
                for (int i = 0; i <= slotfish; i++)
                {
                    fish_amount[i] = 0;
                }
                slotfish = 0;
            }

        }
        else if (shopsell == 2)
        {
            cout << "\033[1;31m" << "You decided not to sell fish." << endl;
        }
        else
        {
            cout << "\033[1;31m" << "Invalid input. Please choose again.\n" << "\033[0m";
            cin.clear();    // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    } while (shopsell != 1 && shopsell != 2);
    cout << "\033[1;97m" << " ___________________        \n";
    cout << "\033[1;97m" << "|     Good luck sir \\       \n";
    cout << "\033[1;97m" << "\\_______  __________|       \n";
    cout << "         \\ |                              \n";
    cout << "          \\|     " << "\033[0;33m" << "________\n" << "\033[1;97m";
    cout << "                " << "\033[0;33m" << "/" << "\033[0;31m" << "________" << "\033[0;33m" << "\\                \n" << "\033[1;97m";
    cout << "             " << "\033[0;33m" << "___" << "\033[0;31m" << "|________|" << "\033[0;33m" << "___             \n" << "\033[1;97m";
    cout << "            " << "\033[0;33m" << "/________________\\            \n" << "\033[1;97m";
    cout << "              " << "\033[1;90m" << "< /\\|_\\|_|/\\ >              \n" << "\033[1;97m";
    cout << "               " << "\033[1;93m" << "(|" << "\033[1;90m" << "  0  0} " << "\033[1;93m" << "|)               \n" << "\033[1;97m";
    cout << "                " << "\033[1;93m" << "|   " << "\033[1;31m" << "\\/   " << "\033[1;93m" << "|                \n" << "\033[1;97m";
    cout << "            " << "\033[0;31m" << "_____" << "\033[1;93m" << "\\______/" << "\033[0;31m" << "_____            \n" << "\033[1;97m";
    cout << "           " << "\033[0;31m" << "/     (      )     \\           \n";
    cout << "          " << "\033[0;31m" << "/       |" << "\033[1;31m" << "\\  /" << "\033[0;31m" << "|       \\          \n" << "\033[1;97m";
    cout << "         " << "\033[0;31m" << "|    |   |" << "\033[1;31m" << " \\/ " << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
    cout << "         " << "\033[0;31m" << "|    |   |" << "\033[1;31m" << ">  <" << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
    cout << "         " << "\033[0;31m" << "|    |   | " << "\033[1;31m" << "/\\ " << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
    cout << "\033[1;31m" << "==========================================\n";
    cout << "\n";

}

void Shop::ShopControl(int& money, int& boatlvl, int& rodlvl, int fishamount[], int& slotfish)
{
    int shopact = 0;
    do {
        cout << "\033[1;97m" << " ________________________________________\n";
        cout << "\033[1;97m" << "| Welcome to the shop. What do you want? \\       \n";
        cout << "\033[1;97m" << "\\_______  _______________________________|       \n";
        cout << "         \\ |                              \n";
        cout << "          \\|     " << "\033[0;33m" << "________\n" << "\033[1;97m";
        cout << "                " << "\033[0;33m" << "/" << "\033[0;31m" << "________" << "\033[0;33m" << "\\                \n" << "\033[1;97m";
        cout << "             " << "\033[0;33m" << "___" << "\033[0;31m" << "|________|" << "\033[0;33m" << "___             \n" << "\033[1;97m";
        cout << "            " << "\033[0;33m" << "/________________\\            \n" << "\033[1;97m";
        cout << "              " << "\033[1;90m" << "< /\\|_\\|_|/\\ >              \n" << "\033[1;97m";
        cout << "               " << "\033[1;93m" << "(|" << "\033[1;90m" << "  0  0} " << "\033[1;93m" << "|)               \n" << "\033[1;97m";
        cout << "                " << "\033[1;93m" << "|   " << "\033[1;31m" << "\\/   " << "\033[1;93m" << "|                \n" << "\033[1;97m";
        cout << "            " << "\033[0;31m" << "_____" << "\033[1;93m" << "\\______/" << "\033[0;31m" << "_____            \n" << "\033[1;97m";
        cout << "           " << "\033[0;31m" << "/     (      )     \\           \n";
        cout << "          " << "\033[0;31m" << "/       |" << "\033[1;31m" << "\\  /" << "\033[0;31m" << "|       \\          \n" << "\033[1;97m";
        cout << "         " << "\033[0;31m" << "|    |   |" << "\033[1;31m" << " \\/ " << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
        cout << "         " << "\033[0;31m" << "|    |   |" << "\033[1;31m" << ">  <" << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
        cout << "         " << "\033[0;31m" << "|    |   | " << "\033[1;31m" << "/\\ " << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
        cout << "\033[1;31m" << "==========================================\n";
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
            cout << "\033[1;31m" << "Invalid Input, Please try again\n" << "\033[0m";
            cin.clear();    // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    } while (true);  // Loop indefinitely until the user chooses to quit
    cout << "\033[1;97m" << " _________________                           \n";
    cout << "\033[1;97m" << "|     Goodbye     \\       \n";
    cout << "\033[1;97m" << "\\________  _______|       \n";
    cout << "         \\ |                              \n";
    cout << "          \\|     " << "\033[0;33m" << "________\n" << "\033[1;97m";
    cout << "                " << "\033[0;33m" << "/" << "\033[0;31m" << "________" << "\033[0;33m" << "\\                \n" << "\033[1;97m";
    cout << "             " << "\033[0;33m" << "___" << "\033[0;31m" << "|________|" << "\033[0;33m" << "___             \n" << "\033[1;97m";
    cout << "            " << "\033[0;33m" << "/________________\\            \n" << "\033[1;97m";
    cout << "              " << "\033[1;90m" << "< /\\|_\\|_|/\\ >              \n" << "\033[1;97m";
    cout << "               " << "\033[1;93m" << "(|" << "\033[1;90m" << "  0  0} " << "\033[1;93m" << "|)               \n" << "\033[1;97m";
    cout << "                " << "\033[1;93m" << "|   " << "\033[1;31m" << "\\/   " << "\033[1;93m" << "|                \n" << "\033[1;97m";
    cout << "            " << "\033[0;31m" << "_____" << "\033[1;93m" << "\\______/" << "\033[0;31m" << "_____            \n" << "\033[1;97m";
    cout << "           " << "\033[0;31m" << "/     (      )     \\           \n";
    cout << "          " << "\033[0;31m" << "/       |" << "\033[1;31m" << "\\  /" << "\033[0;31m" << "|       \\          \n" << "\033[1;97m";
    cout << "         " << "\033[0;31m" << "|    |   |" << "\033[1;31m" << " \\/ " << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
    cout << "         " << "\033[0;31m" << "|    |   |" << "\033[1;31m" << ">  <" << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
    cout << "         " << "\033[0;31m" << "|    |   | " << "\033[1;31m" << "/\\ " << "\033[0;31m" << "|    |   |         \n" << "\033[1;97m";
    cout << "\033[1;31m" << "==========================================\n";
}