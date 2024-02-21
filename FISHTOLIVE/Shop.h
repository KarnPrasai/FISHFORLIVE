#pragma SHOP_H
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
		void upgrade(int &money); //level up = How many level do you want to up
		void sell();
		void boatlevel();
		void rodlevel();

};
