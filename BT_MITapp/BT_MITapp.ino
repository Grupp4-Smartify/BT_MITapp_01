#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

int ledPin = 13;
int potPin = A5;

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            10
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      6

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
String readString;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(potPin,INPUT);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  // put your main code here, to run repeatedly:
 
  while (Serial.available()){
    delay(3);
    char c = Serial.read();
    readString += c;
    
  }
  if (readString.length() >0){
     //Serial.println(readString);
    
    if (readString == "on"){
      digitalWrite(ledPin,HIGH);
      }
    if (readString == "off"){
      digitalWrite(ledPin,LOW);
      }
    if (readString.startsWith("D", 0)){
      neoPix();
      }
      readString="";
      }  
  //  pixels.setPixelColor(5, pixels.Color(46,37,255));
  //  pixels.show(); // This sends the updated pixel color to the hardware.
  // potRead();
 //  Serial.print("q");
 //  tempRead();
}
