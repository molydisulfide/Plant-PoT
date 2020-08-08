<link href="style.css" rel="stylesheet"></link>

# Plant-PoT

<img src="https://raw.github.com/molydisulfide/Plant-PoT/master/images/plant.jpg" width="250"  />

*****

**Plant-PoT** is an Arduino-based IoT moisture monitoring system for house plants.

A capacitve moisture sensor inserted into the plant soil is used to trip a message on the LCD screen telling you to water the plant once the moisture falls below a certain threshold. 

The moisture data is being periodically sent to a ThingSpeak server, where a MATLAB visualization allows you to track the moisture value trend and displays the current moisture value. 

The whole thing is powered with two 9 V batteries. 

This repo contains:

* the wiring I/O tables which show how to connect the Arduino Uno and the ESP8266 boards together with the moisture sensor, so that the output of the ESP trips the LCD message on the Arduino loop, and how to connect the LCD screen through a potentiometer to the Arduino itsel,
* an [.ino sketch](https://github.com/molydisulfide/Plant-PoT/blob/master/ThingSpeak_Moisture.ino) which runs on the ESP8266 to establish a Wi-Fi connection and to upload data to a ThingSpeak channel using a personal API key,
* an [.ino sketch](https://github.com/molydisulfide/Plant-PoT/blob/master/LCD_Moisture_Message.ino) which runs on the Arduino to power the small LCD screen and displays different messages depending on the moisture threshold reading.

Server IP is: 192.168.0.140.

******

## Sensor-to-ESP8266-to-Power-Supply Connections:


| **[Capacitive Moisture Sensor](https://www.amazon.com/gp/product/B07SYBSHGX/ref=ppx_yo_dt_b_asin_title_o06_s00?ie=UTF8&psc=1)** | **ESP8266** | **[5 V Breadboard Power Supply](https://www.amazon.com/MakerSpot-Breadboard-Voltage-Solderless-Friendly/dp/B01IUYLVFK/ref=sr_1_3?dchild=1&keywords=breadboard+power+supply&qid=1596909037&sr=8-3)** |
|:--------------:|:-------:|:------:|
|       GND wire      |   *n/a*   | GND       |
|       Power wire     |   3.3 V   | *n/a*       |
|       Signal wire     |   A0 pin   |     *n/a*     |
|       *n/a*       |   Vin pin  |   5 V     |
|        *n/a*      |   GND pin   |   GND     |

* The **A0** pin on the ESP then connects out to the **A0** pin on the Arduino. This is the trip wire of the moisture signal, whose voltage will decide the threshold for changing the LCD message.
* The power supply module is connected to a 9 V battery with a [simple battery clip DC connector](https://www.amazon.com/gp/product/B01N4EBPR5/ref=ppx_yo_dt_b_asin_title_o01_s00?ie=UTF8&psc=1).

*****

## Arduino-to-LCD-Screen-Connections:

The **[LCD Screen](https://www.amazon.com/GeeekPi-Character-Backlight-Raspberry-Electrical/dp/B07S7PJYM6/ref=sr_1_4?dchild=1&keywords=arduino+lcd+screen&qid=1596909556&s=electronics&sr=1-4)** connections are the exact same as in the video tutorial by [DroneBot Workshop](https://www.youtube.com/watch?v=wEbGhYjn4QI&t=724s). The potentiometer allows you to control the brightness of the LCD:

<img src="https://raw.github.com/molydisulfide/Plant-PoT/master/images/lcd.png" width="550"  />

* The Arduino is also powered with a 9 V battery.

****

## Calibration:

* A key point is to test the capacitive sensor to get an idea for what readings you can expect from it when the soil is fully watered and when the soil is very dry. To do this, you can take the readings from the sensor when it is fully immersed in water (nominal 100% of moisture) and when it is fully dry out in air (nominal 0% of moisture):

<img src="https://raw.github.com/molydisulfide/Plant-PoT/master/images/happy.jpg" width="550"/> <img src="https://raw.github.com/molydisulfide/Plant-PoT/master/images/thirsty.jpg" width="250"/>

* You can then implement a map to the absolute ```dry``` and ```wet``` values: 
``` c++
int sensorValue;
    sensorValue = analogRead(A0);
    int percentageHumidity = map(sensorValue, wet, dry, 100, 0);
```

* A good threshold for when to water the plant is set to 10%. Below this value, the screen tells us the plant is thirsty.

*****

## ThingSpeak Data Visualization:

<img src="https://raw.github.com/molydisulfide/Plant-PoT/master/images/thingspeak.png" width="550"/>
