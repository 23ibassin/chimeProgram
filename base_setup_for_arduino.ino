#include <Dictionary>;
const int switch1 = 2;
const int switch2 = 3;
int lengthArray = 30;
// List of timing between notes (controls solenoid)
int timeB1[lengthArray/*number is unknown, still need values from music*/] = {};
int timeB2[lengthArray/*same story as above*/] = {};

//list of time each not is played
int timeof1[lengthArray] = {};

// list of each note's spacinge
double A5;
double C6;
double Cs6;
double D6;
double E6;
double F6;
double G6;
double A6;
double Bb6;
double Cs7;

// List of notes of notes on motor 1 (preferably space from switch) (controls motors 1)
int notes1[lengthArray/*number is unknown, still need values from music*/] = {};
// List of notes of notes on motor 2(preferably space from switch) (controls motors 2)
int notes2[lengthArray/*same story as above*/] = {};
// Function to move solenoids based on a distance (controls motors)
void moveByDistance (int timeB, int distance, int motorNum){
  int power;
}
// Function to push solenoid based on the timing?
// function to callibrate location
double calibrate (){

}
// ran when switch 




void setup() {
  // put your setup code here, to run once:
  //Standard config for Chime Machine Control Box
  pinMode (switch1, INPUT_PULLUP);
  pinMode (switch2, INPUT_PULLUP);
  for (int i=6; i<=13; i++){ pinMode(i,OUTPUT); }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Put all functions together.
  // Check for solenoid moving off path when driven by motor
  if (switch1 == 0){
    int change = callibrate();
    Serial.print("change: ");
    Serial.println (change);
    for (int i = 0; i < lengthArray; i++){
      spacing1[i] -=change;
    }
  }
}
