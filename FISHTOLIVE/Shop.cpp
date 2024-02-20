#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include "Shop.h"

using namespace std;



void Shop::upgrade(int &money) {
    Fishrod player_fishrod;
    Boat player_boatlevel;
    cout << "Which gear do you to upgrade?\n";
    cout << "[1] fishing rod [2] boat [3] quit\n";
    cout << "Fishing rod upgrade price = " << player_fishrod.rodprice << endl;
    cout << "Boat upgrade price = " << player_boatlevel.boatprice << endl;
    cout << " Your money = " << money;
    int shopaction;
	do {
		cin >> shopaction;
		if (shopaction == 1) {
			
			player_fishrod.rodlevel += 1;
			//upgrade fishing rod
		}
		else if (shopaction == 2) {
			
			player_boatlevel.boatlevel += 1;
			//upgrade boat
		}
		
		else {
		cout << "action not found";
		}
	}
	while(shopaction != 3);

	cout << "Good bye,see you again next time.";
	
	}
