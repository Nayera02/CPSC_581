#include "dht.h"
#define dht_apin A1 // Analog Pin sensor is connected to
 
dht DHT;

const int buzzerPin = 8;
const int ldrPin = A0;


void setup() {
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
  pinMode(ldrPin, INPUT);   //initialize the LDR pin as an input
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor and LDR\n\n");
  delay(1000);//Wait before accessing Sensor
}

void loop() {
  DHT.read11(dht_apin);
  
  float temperature = DHT.temperature;
  float humidity = DHT.humidity;
  int ldrValue = analogRead(ldrPin);
  
  Serial.print("Current humidity = ");
  Serial.print(humidity);
  Serial.print("%  ");
  Serial.print("  = ");
  Serial.print(temperature); 
  Serial.println("C  ");
  Serial.print("LDR Value = ");
  Serial.println(ldrValue);


  
  //digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
  //delay(2000); // Buzzer on for 1 second
  digitalWrite(buzzerPin, LOW); // Turn off the buzzer
  if (ldrValue <=100 || temperature< 10.0 || temperature> 35.0 ||  humidity <15.0 || humidity >70.0) {
    digitalWrite(buzzerPin, LOW);
    Serial.println("DARK!\n"); 
  }else{
    digitalWrite(buzzerPin, HIGH);
    Serial.println("BRIGHT!\n"); 
  }
  delay(3000);//Wait 5 seconds before accessing sensor again.
  
  
}
