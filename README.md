# ArdunioWaterSensor
Ardunio Water Sensor Code
I have a catch basin in my back yard and it needs to be emptied occasionally. To automate this process I used an old Ardunio with a simple water sensor and relay. The sketch runs every minute and if water is detected it will run the water pump for 2 minutes. However if the water level is not falling the pump will continue to run.

Here's the pinouts:

Power:
* 5v - Water Sensor (+)
* GND - Water Sensor (-)
* GND - Relay Switch (-)
* Vin - Relay Switch (+)

Analog:
* A0 - Water Sensor (S)

Digital:
* Pin7 - Relay (S)

Enjoy!
