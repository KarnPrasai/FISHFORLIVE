#include <iostream>
#include <string>
#include "Shop.h"
#include "Fishing.h"
#include "Main.h"
#include "Event.h"
#include "Fishing.h"
using namespace std;

float randomFloat(int min, int max)
{
    float dot = (float)((rand() % (max - min)) + min) / 100.0f;
    return dot;
}

void removeElementStr(string arr[], int arr2[], int& size, int index) {

    for (int i = index; i <= size; ++i) {
        arr[i] = arr[i + 1];
        arr2[i] = arr2[i + 1];
    }
    size--;
}


void Event::gotevent(string x, int& money, int fishamount[], int& fishslot, string fish[]) {

    cout << "\033[1;91m" << "===============!!!!!!!!!!================\n" << "\033[0m";
    cout << "\n";
    if (x == "Shark_Attack")
    {
        cout << "\033[1;91m" << "Oh no!! You was attacked by a shark.\n" << "\033[0m";
        if (fishslot > 0)
        {
            int amount = rand() % 4;
            if (amount == 0)
            {
                cout << "\033[1;91m" << "Luckily that you didn't lost any fish.\n" << "\033[0m";
            }
            else
            {
                if (fishslot <= amount)
                {
                    amount = fishslot;
                }
                cout << "\033[1;91m" << "You have lost " << amount << " fishes" << "\033[0m";
                for (int i = 0; i < amount; i++)
                {
                    int f = rand() % fishslot;
                    removeElementStr(fish, fishamount, fishslot, f);
                }
            }
        }
        else
        {
            cout << "\033[1;91m" << "But You didn't have any fish. So you ran away.\n" << "\033[0m";
        }
    }
    if (x == "Stranger") {
        int mlost = money * randomFloat(1, 10);
        money -= mlost;
        cout << "\033[1;91m" << "Someone just stole your money!!\n" << "\033[0m";
        cout << "\033[1;91m" << "You lost " << mlost << ".\n" << "\033[0m";
    }
    if (x == "Customer") {
        if (fishslot > 0)
        {
            int f = rand() % fishslot;
            cout << "\033[1;91m" << "Someone just bought your " << fish[f] << " for " << fishamount[f] * 2 << ".\n" << "\033[0m";
            money += fishamount[f] * 2;
            removeElementStr(fish, fishamount, fishslot, f);
            cout << "\033[1;91m" << "You have " << money << " for now.\n" << "\033[0m";
        }
        else
            cout << "\033[1;91m" << "Someone want to buy your fish, but you don't have any of them.\n" << "\033[0m";
    }
    if (x == "Got_garbage")
    {
        cout << "\033[1;91m" << "This spot is full of garbage. So you move to the better area.\n" << "\033[0m";
    }
}

void Event::EventStart(int& money, int fishamount[], int& fishslot, string fish[])
{
    int Chance = rand() % 20 + 1;//20
    if (Chance <= 4)//4
    {
        gotevent(Event_List[0], money, fishamount, fishslot, fish);
    }
    else if (Chance <= 8)//8
    {
        gotevent(Event_List[1], money, fishamount, fishslot, fish);
    }
    else if (Chance <= 12)//12
    {
        gotevent(Event_List[2], money, fishamount, fishslot, fish);
    }
    else
    {
        gotevent(Event_List[3], money, fishamount, fishslot, fish);
    }
}