#pragma SHOP_H
#define SHOP_H

using namespace std;

struct Upgrade {
	string gear_name;
	int price;
	int level;
};

struct Fishinbag {
	string fish_name;
	int price;
	int quantity;
};

class Shop {

		vector<Upgrade> gears;
		vector<Fishinbag>fishs;

	public:
		void shoplist();
		void upgrade(string gearname, int quantity,int money);
		void sell(string fishname, int quantity,int money);

};
