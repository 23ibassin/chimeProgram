const int switch1 = 2;
const int switch2 = 3;
const int motor1s = 10;
const int motor1d = 12;
const int motor2s = 11;
const int motor2d = 13;
const int sollenoid4 = 6;
const int sollenoid3 = 7;
const int sollenoid1 = 8;
const int sollenoid2 = 9;


const int lengthArray1 = 35;
const int lengthArray2 = 25;
unsigned int startTime;
unsigned int currentTime;
bool firstTime = true;
bool firstTime1 = true;
bool firstTime2 = true;
unsigned int m1i /*motor 1 list iteration point*/ = 0;
unsigned int m2i /*motor 2 list iteration point*/ = 0;
double power;
double din1m1 = 93;  //distance in a second for motor 1 in meters
double din1m2 = 204.5;
int timepause1 = 0;
int timepause2 = 0;

double dPerSec;             //used later for calculating the distance per second
int previousState1 = true;  // state of switches
int currentState1 = true;
int previousState2 = true;
int currentState2 = true;
bool calibrate1 = true;   // if motor 1 is being callibrated
bool calibrate2 = true;   // if motor 1 is being callibrated
bool firstTimex2 = true;  // first time code is played after callibration

// List of timing in song each note should play (controls solenoid)
int note8thP1 = 300;
// G6,Cs6, An5, An6, C6
int timeB1[lengthArray1 + 1] = {
  600, 1800, 2700, 3000, 3300, 3900, 4200, 4500, /*Cs6*/ 5100, 5400, 5700, 6300, 6600, 6900,
  /*2nd*/ 7500, 7800, 8100, 8700, 9000, /*slow part and 3rd*/ 11100, 11381, 11475, 11663, 11850,
  /*4th*/ 14100, 14475, 14850, 16350, 16538, 16725
};

/*{An5, An5, C6, An5, C6, C6, An5, C6, Cs6, An5, C6, C6, An5, C6, 
second line/Cs6, An5, C6, C6, An6, /slow part and third line/ An6, G6, An6, C6, 
/4th/ G6, An6, G6,/*1/4rest/ An6, An6, G6};*/
//D6, Cs7, F6, Bb6, E6
int timeB2[lengthArray2 + 1] = {
  0, 300, 900, 1200, 1500, 2100, 2400, 3600, 4800, 6000,
  /*2nd*/ 7200, 8400, /*slow part*/ 9600, 10163, 10350, /*3rd*/ 12600, 13163, 13350, 13725,
  /*4th*/ 15225, 15788, 15975, 16163, 16913
};

//list of time each not is played
//int timeofnote1[lengthArray1] = {};
//int timeofnote2[lengthArray2] = {};

// list of each note's spacinge
double An5 = 3.401;
double C6 = 3.402;
double Cs6 = 13.03;
double D6 = 3.5001;
double E6 = 13.4005;
double F6 = 3.5003;
double G6 = 8.104;
double An6 = 8.105;
double Bb6 = 8.4004;
double Cs7 = 8.4002;

// List of notes on motor 1 (preferably space from switch) (controls motors 1)
// G6,Cs6, An5, An6, C6
double notes1[lengthArray1] = { An5, An5, C6, An5, C6, C6, An5, C6, Cs6, An5, C6, C6, An5, C6,
                                /*second line*/ Cs6, An5, C6, C6, An6, /*slow part and third line*/ An6, G6, An6, C6,
                                /*4th*/ G6, An6, G6, /*1/4rest*/ An6, An6, G6 };

// List of notes on motor 2(preferably space from switch) (controls motors 2)
//D6, Cs7, F6, Bb6, E6

double notes2[lengthArray2] = { F6, D6, D6, F6, D6, D6, F6, F6, E6, E6,
                                /*second line*/ E6, E6, /*slow part*/ D6, E6, F6, /*third line*/ D6, E6, F6, E6,
                                /*4th*/ F6, /*1/4rest*/ F6, F6, F6, F6 };
// Function to move solenoids based on a distance (controls motors)
void moveByDistance(int timeB, double distance, int motorspeed, int motordirec) {
  //I need to make it slow down as it gets closer to the distance
  /* i need to get to a spot within a time frame as it slows down based on the distance
  it needs to go*/
  /*analogWrite(11, 225);
  delay(150);
  digitalWrite(11,0);
  delay(1000000000000000);*/
  if (motorspeed == motor1s) {
    //problem with only using if statements
    power = map(abs(distance), 0, abs(Cs6 - C6), 0, din1m1);
    if (power != 0) {
      Serial.print("motor 1 moving with power: ");
      Serial.println(power);
    }
  } else {
    power = map(abs(distance), 0, E6 - D6, 0, din1m2);
    if (power != 0) {
      Serial.print("motor 2 moving with power: ");
      Serial.println(power);
    }
  }
  analogWrite(motorspeed, power);
  digitalWrite(motordirec, distance < 0);
}
// Function to push solenoid based on the timing?
// function to callibrate location
void calibrate(int motorSpeed, int motorDirec, int switch3, int CS /*current state*/, int PS /*previous state*/, bool calib) {

  analogWrite(motorSpeed, 100);
  digitalWrite(motorDirec, 1);
  delay(5);
  if ((digitalRead(switch3) || CS) != PS) {
    analogWrite(motorSpeed, 0);
    calib = false;
  }
  PS = CS;
}
// ran when switch is = 0


void setup() {
  // put your setup code here, to run once:
  //Standard config for Chime Machine Control Box
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  for (int i = 6; i <= 13; i++) { pinMode(i, OUTPUT); }
  Serial.begin(9600);
  startTime = millis();
  for (int i = 0; i <= lengthArray2 + 1; i++) {
    timeB2[i] = timeB2[i];
  }
  for (int i = 0; i <= lengthArray1 + 1; i++) {
    timeB1[i] = timeB1[i];
  }
}


void loop() {
  currentState1 = digitalRead(switch1);
  currentState2 = digitalRead(switch2);
  if (firstTime) {
    /*calibrate(motor1s, motor1d, switch1, currentState1, previousState1, calibrate1);
    calibrate(motor2s, motor2d, switch2, currentState2, previousState2, calibrate2);
    Serial.println("calibrating");

    if ((currentState1 != previousState1|| currentState2 != previousState2)) {
      startTime = millis();
      firstTime = false;
      Serial.println("firstTime");
    }*/
    firstTime = false;
    digitalWrite(motor1d, 1);
    /*} else if (calibrate1 || calibrate2) {
    if (calibrate1) {
      calibrate(motor1s, motor1d, switch1, currentState1, previousState1, calibrate1);
      if ()
    }
    if (calibrate2) {
      calibrate(motor2s, motor2d, switch2, currentState2, previousState2, calibrate2);
    }*/
  } else if (firstTimex2) {
    /*   moveByDistance(1000, notes1[0], motor1s, motor1d);
    moveByDistance(1000, 1, notes2[0], motor2d);
    delay(997);
    digitalWrite(motor1d, !digitalRead(motor1d)); 
    digitalWrite(motor2d, !digitalRead(motor2d));
    analogWrite(motor1s, 0);
    analogWrite(motor2s, 0);*/
    firstTimex2 = false;

    //move both motors to start position
    //start clock
  } else {
    currentTime = millis();
    // put your main code here, to run repeatedly:
    // Put all functions together.
    //motor 1
    if (timeB1[m1i] <= (currentTime - startTime)) {
      // I only want this top part to happen once per thing
      if (notes1[m1i] == C6 || notes2[m1i] == An6 /*notes with sollenoid 1*/) {
          if ((timeB2[m1i]+50) <= (currentTime - startTime){
          digitalWrite(sollenoid1, 1);
          Serial.print("note1 step:  ");
          Serial.println(notes1[m1i]);
          }
          if ((timeB2[m1i]+100) <= (currentTime - startTime){
          digitalWrite(sollenoid1, 0);
          }
      } else {
          if ((timeB2[m1i]+50) <= (currentTime - startTime){
          digitalWrite(sollenoid2, 1);
          Serial.print("note1 step:  ");
          Serial.println(notes1[m1i]);
          }
          if ((timeB2[m1i]+100) <= (currentTime - startTime){
          digitalWrite(sollenoid2, 0);
          }
        
        

      //going to the next sollenoid
      if (m1i == (lengthArray1 - 1)) {
          analogWrite(motor1s, 0);
      } else if ((currentTime - startTime) >= (timeB1[m1i] + 300)) {
          analogWrite(motor1s, 0);
          firstTime1 = true;
          /*Serial.print("note1: ");
        Serial.print(m1i);
        Serial.print(";   distance: ");
        Serial.println((notes1[m1i + 1] - notes1[m1i]));*/
          m1i++;
      } else {
          moveByDistance((timeB1[m1i + 1] - timeB1[m1i]), (notes1[m1i + 1] - notes1[m1i]), motor1s, motor1d);
      }
      }
      //motor 2
      if (timeB2[m2i] <= (currentTime - startTime)) {
        if (notes2[m2i] == E6 || notes2[m2i] == Bb6 || notes2[m2i] == F6 /*notes with sollenoid 1*/) {
          if ((timeB2[m2i]+50) <= (currentTime - startTime){
            digitalWrite(sollenoid3, 1);
          }
          if ((timeB2[m2i]+100) <= (currentTime - startTime){
            digitalWrite(sollenoid3, 0);
          }
        } else {
          if ((timeB2[m2i]+50) <= (currentTime - startTime){
            digitalWrite(sollenoid4, 1);
          }
          if ((timeB2[m2i]+100) <= (currentTime - startTime){
            digitalWrite(sollenoid4, 0);
          }
        }
        if (m2i == (lengthArray2 - 1)) {
          analogWrite(motor2s, 0);
        } else if ((currentTime - startTime) >= (timeB2[m2i] + 300)) {
          analogWrite(motor2s, 0);
          firstTime2 = true;
          Serial.print("note2: ");
          Serial.print(m2i);
          Serial.print(";   ");
          Serial.println((notes2[m2i + 1] - notes2[m2i]));
          m2i++;
        } else {
          moveByDistance((timeB2[m2i + 1] - timeB2[m2i]), (notes2[m2i + 1] - notes2[m2i]), motor2s, motor2d);
        }
      }
      // Check for solenoid moving off path when driven by motor
    }
  }
