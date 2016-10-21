/*
* Internet of Things - Things
* Infrarood opdracht
* 
* Opdracht 2 - aansluiten en Testen
* Toggle een LED door een willekeurig IR-signaal te versturen
*/

//Library includes
#include <IRremote.h>

//Definieren constanten
const int input_pin = 10; 
const int led_pin = 13; 

//Definieren variabelen
int led_state = LOW;

IRrecv irrecv(input_pin,led_pin);
decode_results signals;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); //Enables input from IR-receiver
  pinMode(led_pin, OUTPUT); //sets onboard pin 13 as output
}

void loop() {
  if (irrecv.decode(&signals)) {
    
    toggleLed();
    //Serial.println(digitalRead(input_pin));
    irrecv.resume(); // get the next signal
  }
}

void toggleLed(){
  if(led_state == 0){
    digitalWrite(led_pin,HIGH);
    led_state = 1;
  }else{
    digitalWrite(led_pin,LOW);
    led_state = 0;
  }
}







