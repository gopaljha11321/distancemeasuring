//// Follow the github account for latest update :-https://github.com/gopaljha11321
///Subscribe our channel Circuit G 
///Circuit diagram & etc :-https://github.com/gopaljha11321/distancemeasuring.git 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>// search in include library or press ctrl+shif+i
#include <Adafruit_SSD1306.h>

#define trigPin 7
#define echoPin 6

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
display.clearDisplay();

}

void loop() {
float duration;
float distance_cm;
float distance_in;

digitalWrite(trigPin, LOW); 
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance_cm = (duration/2) / 29.1;
distance_in = (duration/2) / 73.914;

display.setCursor(25,0); 
display.setTextSize(1);
display.setTextColor(WHITE);
display.println("Distance Meter");

display.setCursor(10,10); 
display.setTextSize(1);
display.setTextColor(WHITE);
display.println(distance_cm);
display.setCursor(70,10);
display.setTextSize(1);
display.println("cm");

display.setCursor(30,20); 
display.setTextSize(1);
display.setTextColor(WHITE);
display.println(distance_in);
display.setCursor(70,20);
display.setTextSize(1);
display.println("in");
display.display();

delay(500);
display.clearDisplay();

Serial.println(distance_cm);
Serial.println(distance_in);
}
