#include "Door.hpp"
#include "Device.hpp"
#include <iostream>
using namespace std;

//the constructor parameters https://www.w3schools.com/cpp/cpp_constructors.aspdo 
CDoor::CDoor(int ID, string name, string manufacture)
{
	lockedOrNot = true;
	lastlocked = "Maryam Mohammed";
}

void CDoor::viewInfo()

{
	cout << "Door Lock Information" << endl;
	cout << "ID-" << deviceID << endl;
	cout << "Name-" << deviceName << endl;
	cout << "Manufacturer-" << manufacturer << endl;
	cout << "Last Opened by-" << lastlocked << endl;

	cout << "Locked-";

	//this is if the system is avtive or inactive
	cout << "Status-"; //https://www.youtube.com/watch?v=wOxjjy3tKAo 
	if (status)
	{
		cout << "Active" << endl;
	}
	else
	{
		cout << "Inactive" << endl;
	}
}


	void CDoor::interactionEvent() //function override is a typ of polymorphism
	{
	if (lockedOrNot) //boolean if door is locked or not
	{
		cout << "Locked" << endl;
	}
	else
	{
		cout << "Unlocked" << endl;
	}

	//now let the user pick to lock or unlock the door
	int pick;
	cout << "Please type number 1 or 2  to:" << endl;
	cout << "1. Lock the door" << endl;
	cout << "2. Unlock the door" << endl;
	cin >> pick;

	if (pick == 1)
	{
		lockedOrNot = true;
		cout << "Door is now locked" << endl;
		cout << "Please enter your name" << endl;
		string lastUser;
		cin >> lastUser;
	}
	else if (pick == 2)
	{
		lockedOrNot = false;
		cout << "Door is now unlocked" << endl;
	}
	else
	{
		cout<< "Invalid option please try again" << endl;
	}
}