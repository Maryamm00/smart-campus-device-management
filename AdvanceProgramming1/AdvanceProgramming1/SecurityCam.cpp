#include "SecurityCam.hpp"
#include "Device.hpp"
#include <iostream>
using namespace std;

CSecurityCam::CSecurityCam(int ID, string name, string manufacture, string CamQuality, string CamPower)
	: device(ID, name, manufacture)
{
	quality = CamQuality;
	power = CamPower;
}

void CSecurityCam::viewInfo()


{
	cout << "Security Camera Information" << endl;
	cout << "Camera ID-" << deviceID << endl;
	cout << "Name-" << deviceName << endl;
	cout << "Manufacturer-" << manufacturer << endl;
	cout << "Camera Quality-" << quality << endl;
	cout << "Camera Power-" << power << endl;
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
void CSecurityCam::interactionEvent()
{
	if (!status)
	{
		cout << "Camera is off" << endl;
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
		cout << "now viewing camera: " << deviceName << endl;
	}
}