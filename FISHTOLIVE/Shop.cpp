#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "Shop.h"

using namespace std;

void Shop::shoplist()  {
	cout << "Gears available in the shop:\n";
	for (const auto & Upgrade : gears) {
		cout << Upgrade.gear_name << " - $" << Upgrade.price << " (" << Upgrade.level << " available)\n";
	}
}

void Shop::upgrade(string gearname,int quantity,int money) {
    for (auto& Upgrade : gears) {
        if (Upgrade.gear_name == gearname) {
            if (money >= Upgrade.price) {
                cout << "You upgraded " << Upgrade.gear_name << " to " << Upgrade.level << ".\n";
                money -= Upgrade.price;
                cout << "Your money = " << money;
                
            }
            else {
                cout << "Sorry,You are brike";
  
            }
        }
    }
    cout << "Gear not found.\n";
}

void Shop::sell(string fishname, int quantity,int money) {
    for (auto& Fishinbag : fishs) {
        if (Fishinbag.fish_name == fishname) {
            cout << "Fish quantity : "<< Fishinbag.quantity;
            cout << "Fish price : " << Fishinbag.price;
            Fishinbag.quantity -= quantity;
            money += quantity * (Fishinbag.price);
            cout << "You sold " << quantity << " " << Fishinbag.fish_name << "(s) for $" << Fishinbag.price * quantity << endl;
            
        }
    }
    cout << "Product not found\n";
}