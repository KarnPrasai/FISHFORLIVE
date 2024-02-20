#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "Shop.h"

using namespace std;

void Shop::shoplist()  {
	cout << "Gears available in the shop:\n";
	for (const auto & Gear : gears) {
		cout << Gear.gear_name << " - $" << Gear.price << " (" << Gear.quantity << " available)\n";
	}
}

void Shop::buy(string gearname,int quantity,int money) {
    for (auto& Gear : gears) {
        if (Gear.gear_name == gearname) {
            if (Gear.quantity >= quantity) {
                cout << "You bought " << quantity << " " << Gear.gear_name << "(s) for $" << Gear.price * quantity << endl;
                Gear.quantity -= quantity;
                
            }
            else {
                cout << "Sorry, " << Gear.quantity << " " << Gear.gear_name << "(s) available\n";
                
            }
        }
    }
    cout << "Product not found\n";
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