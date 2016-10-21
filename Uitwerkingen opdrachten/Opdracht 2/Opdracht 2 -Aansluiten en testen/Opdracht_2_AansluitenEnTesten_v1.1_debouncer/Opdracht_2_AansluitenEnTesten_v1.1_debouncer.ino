/*
  Internet of Things - Things
  Infrarood opdracht

  Opdracht 2 - aansluiten en Testen
  Toggle een LED door een willekeurig IR-signaal te versturen
*/

//Library includes
#include <IRremote.h>

//Definieren constanten
const int input_pin = 10;
const int led_pin = 13;

//Definieren variabelen
int led_state = LOW;
int currentIRstate;
int lastIRstate = LOW;

unsigned long lastDebounceTime;
unsigned long debounceDelay = 800;

IRrecv irrecv(input_pin, led_pin);
decode_results signals;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); //Enables input from IR-receiver
  pinMode(led_pin, OUTPUT); //sets onboard pin 13 as output
}

void loop() {
  if (irrecv.decode(&signals)) {
    //toggleLed();
    debounce_debug();

    irrecv.resume(); // get the next signal
  }
}

void debounce_debug() {
  int reading = digitalRead(input_pin);
  //Serial.print("reading:");
  //Serial.println(reading);

  //Als de huidige waarde van de IR-pin niet gelijk is aan de laatste IR-status
  //Start dan een timer
  if (reading != lastIRstate) {
    //Serial.println("Ga nu kijken of het een consistent signaal is");
    lastDebounceTime = micros();
    Serial.print("lastDebounceTime");
    Serial.println(lastDebounceTime);
  }

  if (((micros() - lastDebounceTime) > debounceDelay) && (reading != currentIRstate) ) {

    Serial.println("GA NU IETS DOEN");
    Serial.print("tussentijd");
    Serial.println(micros()-lastDebounceTime);
    /*if(reading != currentIRstate){
      currentIRstate = reading;
        if(currentIRstate == HIGH){
        }
      }
      Serial.println("Consistent SIGNAAL ontvangen");
      }else{
      Serial.println(millis());
      Serial.println(lastDebounceTime);
      }*/
  }
  /*else{
    long bounceTijd = (millis() - lastDebounceTime);
    Serial.print("tijd om te bouncen is:");
    Serial.println(bounceTijd);
    }*/
}

/*
  void debouncer(){
  //Maakt een tijdelijke variabele aan voor het IR signaal
  int reading = digitalRead(input_pin);

  //Checkt of het signaal veranderd, zo ja reset timer.
  if(reading != lastIRstate){
    lastDebounceTime = millis();
    Serial.println("start timer" + lastDebounceTime);
  }

  if((millis() - lastDebounceTime) > debounceDelay){
    if(reading != currentIRstate){
      currentIRstate = reading;
      //toggleLed();
      led_state = !led_state;
      Serial.println("GENOEG GEWACHT");
    }
  }

  //digitalWrite(led_pin,led_state);
  lastIRstate = reading;
  Serial.println("laatste IR signaal"  + lastIRstate);
  irrecv.resume();
  }*/


void toggleLed() {
  if (led_state == 0) {
    digitalWrite(led_pin, HIGH);
    led_state = 1;
  } else {
    digitalWrite(led_pin, LOW);
    led_state = 0;
  }
}





