const int switch1 = 2;
const int switch2 = 3;
const int motor1s = 10;
const int motor1d = 12;
const int motor2s = 11;
const int motor2d = 13;
const int sollenoid1 = 6;
const int sollenoid2 = 7;
const int sollenoid3 = 8;
const int sollenoid4 = 9;

int lengthArray1 = 30;
int lengthArray2 = 30;
int startTime;
int currentTime;
int m1i /*motor 1 list iteration point*/;
int m2i /*motor 2 list iteration point*/;


// List of timing in song each note should play (controls solenoid)
int timeB1[lengthArray1] = {
  0,
};
int timeB2[lengthArray2] = {
  0,
};

//list of time each not is played
//int timeofnote1[lengthArray1] = {};
//int timeofnote2[lengthArray2] = {};

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

// List of notes on motor 1 (preferably space from switch) (controls motors 1)
int notes1[lengthArray1] = {};
// List of notes on motor 2(preferably space from switch) (controls motors 2)
int notes2[lengthArray2] = {};
// Function to move solenoids based on a distance (controls motors)
void moveByDistance(int timeB, int distance, int motorspeed, int motordirec) {
  int power;
}
// Function to push solenoid based on the timing?
// function to callibrate location
void calibrate(int motorSpeed, int motorDirec, int switch) {
  analogWrite(motorSpeed, 250);
  digitalWrite(motorDirec, 1);
  while (digitalRead(switch)) {
  }
  analogWrite(motorSpeed, 0);
}
// ran when switch is = 0




void setup() {
  // put your setup code here, to run once:
  //Standard config for Chime Machine Control Box
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  for (int i = 6; i <= 13; i++) { pinMode(i, OUTPUT); }
  Serial.begin(9600);
  callibrate(motor1s, motor1d, switch1);
  callibrate(motor2s, motor2d, switch2);
  startTime = millis();
}


void loop() {
  currentTime = millis();
  // put your main code here, to run repeatedly:
  // Put all functions together.
  //motor 1
  if (timeB1[m1i] <= (currentTime - startTime)) {
    if (notes[m1i] == Cs6 || notes[m1i] == G6 /*notes with sollenoid 1*/) {
      digitalWrite(sollenoid1, 1);
      digitalWrite(sollenoid1, 0);
    }else{
      digitalWrite(sollenoid2, 1);
      digitalWrite(sollenoid2, 0);
    }
    m1i++;
    movebyDistance((timeB1[mli]- timeB1[m1i-1]), (notes1[m1i]-notes[m1i-1]), motor1s, motor1d);
  }
  //motor 2
    if (timeB1[m2i] <= (currentTime - startTime)) {
    if (notes[m2i] == E6 || notes[m2i] == Bb6 /*notes with sollenoid 1*/) {
      digitalWrite(sollenoid3, 1);
      digitalWrite(sollenoid3, 0);
    }else{
      digitalWrite(sollenoid4, 1);
      digitalWrite(sollenoid4, 0);
    }
    m2i++;
    movebyDistance((timeB1[m2i]- timeB2[m2i-1]), (notes2[m2i]-notes[m2i-1]), motor2s, motor2d);
  }
  // Check for solenoid moving off path when driven by motor
}
