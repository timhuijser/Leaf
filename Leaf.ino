#include "DHT.h"

// Light sensor pins and variables
int pinLightLeft = 0;             
int leftLightValue = 0;        
int pinLightRight = 1;             
int rightLightValue = 0;        

// Ground moisture pin and variable
int pinMoist = 2;
int moistValue = 0;

// Warning LED pins
int pinLightWarning = 13;
int pinMoistWarning = 12;

// Warning LED pins
float humidityValue = 0;
float temperatureValue = 0;

// Temperature and humidity sensor pin
#define DHTPIN 3

// Temperature and humidity sensor type
#define DHTTYPE DHT11

// Use existing library
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  pinMode(pinLightWarning, OUTPUT);
  pinMode(pinMoistWarning, OUTPUT);
  
  // Let the Temperature and humidity sensor start
  dht.begin();
}

void loop()
{
  
  // Read light sensors
  leftLightValue = analogRead(pinLightLeft);
  rightLightValue = analogRead(pinLightRight);
  
  // Read ground moisture sensor
  moistValue = analogRead(pinMoist);
  
  // Read Temperature and humidity sensor
  humidityValue = dht.readHumidity();
  temperatureValue = dht.readTemperature();
  
  // Check if one of the light sensors needs more light
  if (leftLightValue < 700 || rightLightValue < 700) {
    digitalWrite(pinLightWarning, HIGH);
    Serial.println("Lekker dat zonnetje.");
  } else {
    digitalWrite(pinLightWarning, LOW);
    Serial.println("Ik krijg zo veel te weinig licht, ik ga me verplaatsen.");
  }
  
  // Check what to do based on the ground moisture value
  if (moistValue < 300) {
    digitalWrite(pinMoistWarning, HIGH);
    Serial.println("Te weinig water, geef mij water!"); 
  } else if (moistValue > 300 && moistValue < 700) {
    digitalWrite(pinMoistWarning, LOW);
    Serial.println("Dit is precies goed zo, ik geef wel aan als ik dorst heb!");
  } else {
    digitalWrite(pinMoistWarning, LOW);
    Serial.println("IK VERDRINK HELP!!");
  }
  
  // Print values to serial.
  Serial.print("Lichtwaarde links:");
  Serial.println(leftLightValue); 
  Serial.print("Lichtwaarde rechts:");
  Serial.println(rightLightValue);
  Serial.print("Grondvochtigheidswaarde:");
  Serial.println(moistValue);   
  Serial.print("Temperatuur:");
  Serial.println(temperatureValue);
  Serial.print("Luchtvochtigheid:");
  Serial.println(humidityValue);   
  
  delay(1000);                  //wait
}
