#ifndef FISHING_H
#define FISHING_H

using namespace std;
class Fishing
{
	public:
		int lvl=0;
		string fishN[400] = {};
		int  fish_amount[400] = {};
		int slotfish = 0;
		int playergoing = 1;
		void GoFishing(int &);
		void HookAFish(int &);
};

#endif