#pragma once
#include <string>
#include "Device.hpp"
using namespace std;

class CProjector : public device //this class inherits (child) from base class device (parent)
{
private:
	string Input; // eg HDCMI, wireless
	int Brightness;


public:
	CProjector(int ID, string name, string manufacture); // string Input, int Brightness);
	void viewInfo() override;
	void interactionEvent() override; //https://www.simplilearn.com/tutorials/cpp-tutorial/function-overriding-in-cpp#:~:text=Function%20overriding%20in%20C%2B%2B%20is%20a%20concept%20by%20which,with%20a%20different%20function%20definition.
};