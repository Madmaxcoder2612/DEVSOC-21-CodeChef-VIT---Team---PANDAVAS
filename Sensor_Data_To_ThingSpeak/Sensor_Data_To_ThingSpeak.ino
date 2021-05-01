#include<ESP8266WiFi.h>;
#include<WiFiClient.h>;
#include<ThingSpeak.h>;

long duration;
int distance;
const int trigPin = 14;
const int echoPin = 12;
const char* ssid =   "Abhishek";
const char* password = "Madmax2001";

int val;
int IRpin = A0;

WiFiClient client;

unsigned long myChannelNumber = 1376760;
const char* myWriteAPIKey = "YMLMKR4EQKELT91S";

void setup()

{
Serial.begin(115200); 
delay(10);


  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); 
  delay(10);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
 
}

void loop() 
{

{
val = analogRead(IRpin);
Serial.print(val);
delay(1000);
ThingSpeak.setField(2,IRpin);
ThingSpeak.writeField(myChannelNumber,2,distance,myWriteAPIKey);
}

{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration*0.034)/2;

  Serial.print("level:  ");
  Serial.print(distance);
  Serial.println("cm");
  delay(500);
  
  Serial.print(distance);
  delay(500);
  ThingSpeak.setField(1,distance);
  ThingSpeak.writeField(myChannelNumber, 1,distance,myWriteAPIKey);

  delay(100);

}
  
}
