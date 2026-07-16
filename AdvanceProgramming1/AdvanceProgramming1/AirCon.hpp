#pragma once
#include <string>
#include "Device.hpp"
using namespace std;

class CAirCon : public device //this class inherits (child) from base class device (parent device)
	
{
private:
	int temperature; // eg 67°
	

public:
	CAirCon(int ID, string name, string manufacture, int temp); //constructors are called automatically when object of a class is created.initliases object with id name manufacturer etc
	void viewInfo() override; 
	void interactionEvent() override; //https://www.simplilearn.com/tutorials/cpp-tutorial/function-overriding-in-cpp#:~:text=Function%20overriding%20in%20C%2B%2B%20is%20a%20concept%20by%20which,with%20a%20different%20function%20definition.
};
//oveerride type of polymorphism shows virual method and checks no new methods child class changes method so matches base class signature