#pragma once
#include <memory>
#include <string>
#include "Device.hpp"
using namespace std;

// Factory pattern: centralises device creation so the manager doesn't need
// to know the concrete class for each device type - just the type number
class DeviceFactory
{
public:
	static unique_ptr<device> createDevice(int type, int id, string name, string manufacture,
		int temp = 0, string quality = "", string power = "");
};