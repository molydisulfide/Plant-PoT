#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
#include <DHT.h>


#define DHTPIN 5
#define DHTTYPE DHT11
WiFiClient  client;
DHT dht(DHTPIN, DHTTYPE);

unsigned long myChannelNumber = 1;
const char * myWriteAPIKey = "7AXQF24NMGB42B8V";
char ssid[] = "***";
char password[] = "***";
int Time_S = 1; //Change this to your prefered sampling interval in seconds.
float phC; 
int number = 0;

void setup() {
  
  Serial.begin(9600); 
  WiFi.mode(WIFI_STA); 
  ThingSpeak.begin(client); 
  delay(10);
  Serial.println('\n');
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to Wi-Fi network ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Successfully connected to ");  
  Serial.print(ssid); Serial.println("!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP()); 

  dht.begin();
}

void loop() {
// Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
  // pieces of information in a channel.  Here, we write to field 1.
  int x = ThingSpeak.writeField(myChannelNumber, 1, phC, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  delay(3000);
  float h = dht.readHumidity();
  delay(2000);
  //float t = dht.readTemperature();
  //delay(2000);
  //float hic = dht.computeHeatIndex(t, h, false);
  //delay(2000);
  Serial.println(h);
  //getLight();
  
  delay(5000); // Wait 20 seconds to update the channel again
}



////////////////////////////////Get Temperature readings///////////////////////////
//void getLight()
//{           
//double Light;
//int sensorValue;
//sensorValue = analogRead(A0);
//float voltage = sensorValue * (3.3 / 1023.0);   // convert sensor reading to voltage  
//phC = voltage;
//Serial.println("Voltage on photo-resistor is: ");  
//Serial.print(phC); Serial.println(" V");
//}
