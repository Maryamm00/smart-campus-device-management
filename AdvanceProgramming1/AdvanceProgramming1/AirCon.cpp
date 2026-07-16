#include "AirCon.hpp"
#include "Device.hpp" //inherit fromm device https://www.w3schools.com/cpp/cpp_inheritance.asp reusing attributes and methods from another class for clean code
#include <iostream>
using namespace std;

CAirCon::CAirCon(int ID, string name, string manufacture, int temp)
	: device(ID, name, manufacture)
{
	temperature = temp;
}

void CAirCon::viewInfo() //https://www.geeksforgeeks.org/cpp/override-keyword-c/ function in child has same as base (device)

{
	cout << "Air Conditioning Information" << endl;
	cout << "Air Conditioning ID-" << deviceID << endl;
	cout << "Name-" << deviceName << endl;
	cout << "Manufacturer-" << manufacturer << endl;
	cout << "Target Temperature-" << temperature << endl;
	cout << "Status-"; //https://www.youtube.com/watch?v=wOxjjy3tKAo 
	if (status)
		cout << "On" << endl;
	else
		cout << "Off" << endl;
	
}

void CAirCon::interactionEvent()
{
	if (!status)
	{
		cout << "Air conditioning is off" << endl;
		cout << "Would you like to turn it on? Press 1 or 2" << endl;
		cout << "1 for yes" << endl;
		cout << "2 for no" << endl;

		int pick;
		cin >> pick;
		{
			if (pick == 1)
			{
				activate();
				cout << "On" << endl;
			}
			else if (pick == 2)
			{
				cout << "Bye " << endl;
			}
			else
			{
				cout << "Invalid option please try again" << endl;
			}
		}
	}

	//now let the user pick to lock or unlock the door
	int picktemp;
	cout << "Please type number 1 or 2  to:" << endl;
	cout << "1. Increase temp" << endl;
	cout << "2. decrease temp" << endl;
	cin >> picktemp;

	if (picktemp == 1)
	{
		// increase temp by one or 2 degress
		temperature += 2 ;
		cout << "Temperature increased" << endl;
	}
	else if (picktemp == 2)
	{
		temperature -= 2;
		cout << "Temperarture decreased " << endl;
	}
	else
	{
		cout << "Invalid option please try again" << endl;
	}
	
}
	