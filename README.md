# Smart Campus Device Management System

A C++ command-line application for managing smart devices across a university campus — security cameras, air conditioning, projectors, lighting, and door locks. Built as a coursework project and extended independently afterward.

## What it does

- View, activate, and deactivate all campus devices
- Interact with individual devices (e.g. lock/unlock a door, adjust projector brightness, change AC temperature)
- Add new devices of any supported type at runtime

## Design

- **Polymorphism**: all devices inherit from an abstract `device` base class, so the manager can treat every device type identically (`viewInfo()`, `activate()`, `interactionEvent()`) without knowing its concrete type.
- **Factory pattern**: device creation is centralised in `DeviceFactory`, so adding a new device type only requires updating the factory — not the manager's logic. This removed duplicated creation code that previously existed in two separate places.
- **Smart pointers**: devices are stored as `unique_ptr<device>`, so memory is cleaned up automatically with no manual `delete` calls and no risk of leaks.

## Tech stack

C++ (Visual Studio / MSVC)

## How to run

Open `AdvanceProgramming1.sln` in Visual Studio and build/run (F5).

## Class structure

```
device (abstract base)
 ├── CDoor
 ├── CAirCon
 ├── CProjector
 ├── CLight
 └── CSecurityCam

manager — owns and controls the collection of devices
DeviceFactory — creates the correct device subclass from a type number
```
