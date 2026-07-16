#pragma once
#include <string>
using namespace std;

//all classes have at least a constructor or c++ will create a default one
class device //device is object classes contain data and methods the devices must have:
{
protected:
	int deviceID;
	string deviceName;
	string manufacturer;
	bool status;

public: //functions are public
	device();
	device(int deviceID, string deviceName, string manufacturer); //parameter constructor initialises devices with ID name manufa
	void set(int deviceID, string deviceName, string manufacturer); // gives variables
	void getName(int& deviceID, string& deviceName, string& manufacturer);
	string getName() const { return deviceName; }
	//polymorphism https://www.youtube.com/watch?v=nYCMW3kfTvs object can be identified by mmore thn one type 
	//polymorphism means to have lots of forms virual func let child class override
	virtual void activate();  //https://www.geeksforgeeks.org/cpp/virtual-function-cpp/ virtual voids. every device can be activated, deactivated etc
	virtual void deactivate();
	virtual void viewInfo() = 0; // =0 means veiwInfo got to make own function in subclass
	virtual void interactionEvent() = 0;
};