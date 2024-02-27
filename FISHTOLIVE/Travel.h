#ifndef TRAVEL_H
#define TRAVEL_H

using namespace std;

class Travel {
	public:		
		string FishingArea[7] = {"River","Lake","Beach","Sea","Deep Sea","Island"};
		void PlaceTravel();
		void PlaceChecker(int,int);
		bool IsTraveled = false;
};




#endif