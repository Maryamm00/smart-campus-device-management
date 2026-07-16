#include "DeviceFactory.hpp"
#include "Door.hpp"
#include "AirCon.hpp"
#include "Projector.hpp"
#include "RoomLight.hpp"
#include "SecurityCam.hpp"

unique_ptr<device> DeviceFactory::createDevice(int type, int id, string name, string manufacture,
	int temp, string quality, string power)
{
	if (type == 1)
		return make_unique<CDoor>(id, name, manufacture);
	else if (type == 2)
		return make_unique<CAirCon>(id, name, manufacture, temp);
	else if (type == 3)
		return make_unique<CProjector>(id, name, manufacture);
	else if (type == 4)
		return make_unique<CLight>(id, name, manufacture);
	else if (type == 5)
		return make_unique<CSecurityCam>(id, name, manufacture, quality, power);
	else
		return nullptr; // caller checks for this
}