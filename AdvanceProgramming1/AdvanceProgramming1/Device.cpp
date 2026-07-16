#include "Device.hpp"
#include <iostream>
using namespace std;

device::device() // constructor for class device
{
	deviceID = 0;
	deviceName = "";
	manufacturer = "";
	status = false;
}

device::device(int ID, string name, string manufacture) // creates a device stored with these attributes
{
	deviceID = ID;
	deviceName = name;
	manufacturer = manufacture;
	status = false;
}

void device::activate()
{
	status = true;
}

void device::deactivate()
{
	status = false;
}