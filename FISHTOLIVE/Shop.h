#pragma SHOP_H
#define SHOP_H

using namespace std;

struct Gear {
	string gear_name;
	int price;
	int quantity;
};

struct Fishinbag {
	string fish_name;
	int price;
	int quantity;
};

class Shop {

		vector<Gear> gears;
		vector<Fishinbag>fishs;
	public:
		void shoplist();
		void buy(string gearname, int quantity,int money);
		void sell(string fishname, int quantity,int money);

};
