#include "Projector.hpp"
#include "Device.hpp"
#include <iostream>
using namespace std;

CProjector::CProjector(int ID, string name, string manufacture) // string Input, int Brightness)
	: device(ID, name, manufacture)
{
	 Brightness = 10;
	 Input = " ";
}

void CProjector::viewInfo()

{
	cout << "Projector Information" << endl;
	cout << "ID-" << deviceID << endl;
	cout << "Name-" << deviceName << endl;
	cout << "Manufacturer-" << manufacturer << endl;
	cout << "Input-" << Input << endl;
	cout << "Brightness Level-" << Brightness << endl; 
	cout << "Status-"; //https://www.youtube.com/watch?v=wOxjjy3tKAo 
	if (status)
	{
		cout << "On" << endl;
	}
	else
	{
		cout << "Off" << endl;
	}
}

void CProjector::interactionEvent()
{
	if (!status)
	{
		cout << "Projector is off" << endl;
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
				cout << "Bye" << endl;
				return;
			}
			else
			{
				cout << "Invalid option please try again" << endl;
			}
		}
	}

	//now let the user pick to put brightness higher
	int bright;
	cout << "Please type number 1 - 100  to:" << endl;
	
	cin >> bright;

	if (bright >= 1 && bright <= 100)
	{
		// increase brightness by one or 2 degress
		cout << "Brightness is now " << bright << endl;
	}
	
	else
	{
		cout << "Invalid option please try again" << endl;
	}
}
