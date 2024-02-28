#ifndef TRAVEL_H
#define TRAVEL_H

using namespace std;

class Travel {
	public:		
		string FishingArea[7] = {"River","Lake","Beach","Sea","Deep Sea","Island"};
		void PlaceTravel(string&,int&,int&);
		void PlaceChecker(int,int,string&,int&,int&);
		bool IsTraveled = false;
};




#endif