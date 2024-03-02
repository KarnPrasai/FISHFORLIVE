#ifndef SHOP_H
#define SHOP_H

using namespace std;

struct Fishrod {
	int rodlevel = 1;
	int rodprice = 0;
};

struct Boat {
	int boatlevel = 1;
	int boatprice = 0;
};

class Shop {
	public:
		int money;
		void upgrade(int& money, int &player_boatlevel, int &player_rodlevl); //level up = How many level do you want to up
		void sell(int fish_amount[], int& slotfish, int& money);
		int boatlevel(int player_boatlevel);
		int rodlevel(int player_rodlevel);
		void ShopControl(int&,int&,int&,int[], int&);
};
#endif