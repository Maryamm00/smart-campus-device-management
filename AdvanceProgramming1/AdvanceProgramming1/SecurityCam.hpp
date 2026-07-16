#pragma once
#include <string>
#include "Device.hpp"
using namespace std;

class CSecurityCam : public device //this class inherits (child) from base class device (parent)
{
private:
	string quality; //pixel 4k etc
	string power; //battery/ solar

public: 
	CSecurityCam(int ID, string name, string manufacture, string camQuality, string power);
	void viewInfo() override; //displays info about camera. Each child class. other devices will have their own
	void interactionEvent() override; //https://www.simplilearn.com/tutorials/cpp-tutorial/function-overriding-in-cpp#:~:text=Function%20overriding%20in%20C%2B%2B%20is%20a%20concept%20by%20which,with%20a%20different%20function%20definition.
};