# Plant-PoT

*****

**Plant-PoT** is an Arduino-based IoT moisture monitoring system for house plants.

A capacitve moisture sensor inserted into the plant soil is used to trip a message on the LCD screen telling you to water the plant once the moisture falls below a certain threshold. 

The moisture data is being periodically sent to a ThingSpeak server, where a MATLAB visualization allows you to track the moisture value trend and displays the current moisture value. 

The whole thing is powered with two 9 V batteries. 


This repo contains:

* the wiring I/O tables which show how to connect the Arduino Uno and the ESP8266 boards together with the moisture sensor, so that the output of the ESP trips the LCD message on the Arduino loop, and how to connect the LCD screen through a potentiometer to the Arduino itsel,
* an *.ino* sketch which runs on the ESP8266 to establish a Wi-Fi connection and to upload data to a ThingSpeak channel using a personal API key,
* an *.ino* sketch which runs on the Arduino to power the small LCD screen and displays different messages depending on the moisture threshold reading.

Server IP is: 192.168.0.140.
