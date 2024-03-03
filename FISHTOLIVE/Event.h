#ifndef EVENT_H
#define EVENT_H
#include<string>
#include<iostream>
#include "Main.h"
using namespace std;

class Event
{
public:
    string Event_List[4] = { "Shark_Attack","Stranger","Customer","Got_garbage" };

    void gotevent(string x, int& money, int fishamount[], int& fishslot, string fish[]);

    void EventStart(int& money,int fishamount[], int& fishslot,string fish[]);

};


#endif