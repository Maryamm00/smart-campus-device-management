#pragma once
#include <vector>
#include <string>
#include "Device.hpp"
#include "DeviceFactory.hpp"

class manager
{
private:
	vector<unique_ptr<device>> devices;
	
public:
	manager();
	~manager(); //https://www.geeksforgeeks.org/cpp/destructors-c/ automatically called when class is destroyed cleans up
	void run();
};