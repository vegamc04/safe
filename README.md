
[Spanish](https://github.com/vegamc04/safe/blob/master/readme_config/versions/readme_es.md)

[Portuguese](https://github.com/vegamc04/safe/blob/master/readme_config/versions/readme_pt.md)

![arduino](./readme_config/media/svg/arduino_icon.svg)

# Safe

Project developed with [Arduino](https://www.arduino.cc/)

## Components used

- Arduino UNO R3
- Container (any size preference)
- Protoboard (any size preference)
- 220 Ω resistors - Quantity: **3**
- KY-017 (mercury tilt sensor)
- Active buzzer
- Led - Quantity: **3**
- 4x4 Keypad
- Female-male dupont wire - Quantity: **11**
- Male-male dupont wire - Quantity: **10**
- USB A to USB B cable (for Arduino)

## Initialization instructions

1. Install the "Arduino AVR Boards" library from Arduino in your preferred development environment (Arduino IDE is recommended) through the Boards Manager.

2. Navigate to the [arduino.ino](./arduino.ino) file and connect your Arduino Uno to your computer using the usb cable, upload the code to it, and then reset it.

## Operation

|Key|Action|
|:--------|:--------|
|A|Disarm|
|B|Set password and ( Change password )|
|C|[ Rearm ]|
|D|( Reset )|
**( )** Action requires password confirmation before execution.
**[ ]** Action requires the safe to be disarmed before execution.

|Led|Status|Action|
|:--------|:--------|:------|
|Blue|On|Divice in operation|
|Blue|One blink|Request for memory change|
|Green|One blink|Operation completed successfully|
|Green|Two blinks|Password change request accepted|
|Red|One blink|Operation failed|
|Blue + Red|One blink|Inactive key|

General connection diagram, complete project in [Tinkercad](https://www.tinkercad.com/things/jaSxoWvyj15-safe)

![first_connection_diagram](./readme_config/media/webp/safe_connection_diagram.webp)

## Photographs

![first_photograph](./readme_config/media/webp/first_photograph.webp)

![second_photograph](./readme_config/media/webp/second_photograph.webp)

Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
