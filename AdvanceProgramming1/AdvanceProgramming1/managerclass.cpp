#include "Door.hpp"
#include "AirCon.hpp"
#include "Projector.hpp"
#include "RoomLight.hpp"
#include "SecurityCam.hpp"
#include "managerclass.hpp"
#include "DeviceFactory.hpp"
#include <iostream>
#include <vector>

using namespace std;
void DrawLine()
{
    for (int i = 1; i < 121; i++)
        cout << "-";
}

manager::manager()
{
    DrawLine();
    cout << "                                   Welcome to University Smart Campus" << endl;
    //vector<device*> devices; //https://www.geeksforgeeks.org/cpp/cpp-vector-of-pointers/pointer
    //to store memory address. Vectors hold lots pointers. the object will know id name pointer tells you where object is
    //device* stores the devices to let user pick one and call right function.
    //Polymorphism calls the right function and just cleaner store everything in the devices vector. calls the objects needed function even if the same name


    // Create default devices
    //pushback https://www.geeksforgeeks.org/cpp/vector-push-back-cpp-stl/
    //add new element at the end of vector this will also happen when user adds their device in
    devices.push_back(DeviceFactory::createDevice(1, 001, "Door- Front Door", "Harrington Building"));
    devices.push_back(DeviceFactory::createDevice(2, 002, "Air Conditioning- Darwin AC", "Samsung", 20));
    devices.push_back(DeviceFactory::createDevice(3, 003, "Projector- Xiaomi Projector", "Foster Building"));
    devices.push_back(DeviceFactory::createDevice(4, 004, "Light", "LG"));
    devices.push_back(DeviceFactory::createDevice(5, 005, "Security Camera- CMT Cam", "Swann", 0, "1080p", "Battery"));
}
manager::~manager()// function called when object is destroyed since creating manually mem on the heap to clean up no leaks destructor https://www.geeksforgeeks.org/cpp/destructors-c/
{
    // unique_ptr cleans up automatically when the vector is destroyed, no manual delete needed
}


void manager::run() //function that doesnt return value https://learn.microsoft.com/en-us/cpp/cpp/void-cpp?view=msvc-170
{
    int pick;

    while (true)
    {
        cout << "1. View all devices" << endl;;
        cout << "2. Activate all devices" << endl;
        cout << "3. Deactivate all devices" << endl;
        cout << "4. Interact with a device" << endl;
        cout << "5. Add a new device" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter choice. Only typing numbers 1- 6: ";

        while (!(cin >> pick)) //keeps asking until its a number https://www.w3schools.com/cpp/cpp_input_validation.asp
        {
            cout << "Invalid number! Please make sure to enter a number: " << endl;
            cin.clear(); //clears any invalid data entered
            cin.ignore(1000, '\n'); //removes characters from input buffer   https://stackoverflow.com/questions/25475384/when-and-why-do-i-need-to-use-cin-ignore-in-c
        }

        if (pick == 1)
        { //https://www.w3schools.com/cpp/cpp_pointers.asp
            for (auto& deviceptr : devices) //create a pointer (store mem address as its value) inside vector
                deviceptr->viewInfo(); //the pointer will point to that function and use overriden ver.
            //its polymorphism cos pointer points to each device to print out its unique info
        }
        else if (pick == 2)
        {
            for (auto& deviceptr : devices)
                deviceptr->activate();
            cout << "All devices activated!" << endl;
        }
        else if (pick == 3)
        {
            for (auto& deviceptr : devices)
                deviceptr->deactivate();
            cout << "All devices deactivated!" << endl;
        }
        else if (pick == 4)
        {
            cout << "Select device: " << endl;

            for (int i = 0; i < devices.size(); i++) //adds one cos it starts from 0. .size tell how many elements in vector https://www.codecademy.com/resources/docs/cpp/vectors/size
            {
                cout << i << ": " << devices[i]->getName() << endl;
            }

            int selectdevice;

            while (!(cin >> selectdevice)) //keeps asking user until valid number is entered
            {
                cout << "Invalid number! Please make sure to enter a number: " << endl;
                cin.clear(); //clears any invalid data entered
                cin.ignore(1000, '\n'); //removes characters from input buffer. no mixing left over input with new
            }

            if (selectdevice >= 0 && selectdevice < devices.size()) //so they have to pick from 0 to 5
                devices[selectdevice]->interactionEvent();
            else
                cout << "Invalid option " << endl;
        }
        else if (pick == 5)
        {
            int type;

            cout << "1. Door" << endl;
            cout << "2. Air Conditioning" << endl;
            cout << "3. Projector" << endl;
            cout << "4. Light" << endl;
            cout << "5. Security Camera" << endl;

            while (true) //https://www.geeksforgeeks.org/cpp/how-to-validate-user-input-in-cpp/
            {
                cout << "Pick number 1-5 to add a device: "; //make sure numbers are within range
                if (cin >> type && type >= 1 && type <= 5) //https://www.w3schools.com/cpp/cpp_operators_logical.asp
                {
                    break; //exits the loop
                }
                else
                {
                    cout << "Invalid number! Please make sure to enter a number: " << endl;
                    cin.clear(); //clears any invalid data entered
                    cin.ignore(1000, '\n'); //removes characters from input buffer https://www.geeksforgeeks.org/cpp/cin-ignore-function-in-cpp/
                }

            }

            cin.ignore(1000, '\n');

            int id, temp = 0;
            string name, manufacture, quality, power;

            cout << "Enter ID: ";

            while (!(cin >> id)) //keeps asking user until valid number is entered
            {
                cout << "Invalid number! Please make sure to enter a number: " << endl;
                cin.clear(); //clears any invalid data entered
                cin.ignore(1000, '\n'); //removes characters from input buffer
            }

            cin.ignore(1000, '\n'); //removes characters from input buffer, in order to avoid getline see the "enter" key from id input

            cout << "Enter name: ";
            //cin.ignore(); //function gets rid of prev. input so doesnt intefere with new lines
            getline(cin, name); //https://www.geeksforgeeks.org/cpp/getline-string-c/
            //function to read the input so can read name user puts and storing it in name

            cout << "Enter manufacturer: ";
            getline(cin, manufacture); //same with manufacturer quality power etc etc

            if (type == 2)
            {
                cout << "Enter temperature: ";
                cin >> temp;
            }
            else if (type == 5)
            {
                cout << "Enter camera quality: ";
                cin.ignore();
                getline(cin, quality);

                cout << "Enter power type: ";
                getline(cin, power);
            }

            devices.push_back(DeviceFactory::createDevice(type, id, name, manufacture, temp, quality, power));

            if (devices.back())
                cout << "Device added" << endl;
            else
                cout << "Invalid device type." << endl;
        }


        else if (pick == 6)
            return;

        else
        {
            cout << "Invalid option " << endl;
        }

    }
}