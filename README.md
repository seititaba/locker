# Project Locker

A locker is the name of a system that is used to control water flow. For lack of better naming, it will be used as a alias to "eclusa" (portuguese). The locker will control personal flow in and out from our shop.

The first verion has two slide doors, room light, QRCode reading indicators, and logo light. It is controlled by an Arduino UNO and a Web interface. It's uses php to call python and send commands over serial COM to UNO.

This was the very first prototype. And for future work, it will be developed a new version with Raspberry PI, and 3D printed parts.


## Getting Started

To get a copy of locker repository and contribute to this project, use:

* For HTTPS:
```
git clone https://github.com/seititaba/locker.git
```
* For SSH:
```
git clone git@github.com:seititaba/locker.git
```

Or just for fun:
* Direct download from [project repository](https://github.com/seititaba/locker/archive/master.zip) and extract files. Have Fun!


### Prerequisites

To get this project running you will need:

For Arduino:
* Arduino IDE
* Arduino board
* Bipolar stepper motor (we used 28byj-48)
* Motor drive board (we used ULN2003)

For Raspberry PI:
* TODO#


### Installing

* TODO#


## Running the tests

For unit tests:
* Load *.ino file in Arduino IDE and add *.h and *.cpp files
* You can use *.py files in /Tools to get serial COM. **/Tools/SerialCmdLight.py**. Execute it with inputs: 
```
python SerialCmdLight.py <serial COM> <logo, room, entry, exit> <on, off>
```

Note: Current project .ino is in **"/Modules/Arduino/libraries/LightLutti/LighLitty.ino"**

For unit tests from worktree:
* TODO#


## Built With

* [Arduino IDE](https://www.arduino.cc/en/Main/Software) - The IDE used


## Authors

* **Lucas Seiti Taba** - *Initial work* - [locker](https://github.com/locker)


