#pragma SHOP_H
#define SHOP_H

using namespace std;

struct Fishrod {
	int rodlevel;
	int rodprice;
};

struct Boat {
	int boatlevel;
	int boatprice;
};

class Shop {
		


	public:
		int money;
		void upgrade(int &money); //level up = How many level do you want to up
		void sell();
		void boatlevel();
		void rodlevel();

};
