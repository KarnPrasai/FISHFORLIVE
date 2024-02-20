#ifndef FISHING_H
#define FISHING_H

using namespace std;

class Fishing
{
	public:
		string fish[400];
		int  fish_amount[400];
		int slotfish = 0;
		int playergoing;
		void GoFishing(); 
		void HookAFish();
};

#endif