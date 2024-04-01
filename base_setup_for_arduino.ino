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

const int lengthArray1 = 14;
const int lengthArray2 = 10;
int startTime;
int currentTime;
int m1i /*motor 1 list iteration point*/ = 0;
int m2i /*motor 2 list iteration point*/=0;


// List of timing in song each note should play (controls solenoid)
int note8thP1 = 300;
// G6,Cs6, An5, An6, C6
int timeB1[lengthArray1] = {
  600, 1800, 2700, 3000, 3300, 3900, 4200, 4500, /*Cs6*/5100, 5400, 5700, 6300, 6600, 6900 
  /*2nd*/
};

/*{An5, An5, C6, An5, C6, C6, An5, C6, Cs6, An5, C6, C6, An5, C6, 
second line/Cs6, An5, C6, C6, An6, /slow part and third line/ An6, G6, An6, C6, 
/4th/ G6, An6, G6,/*1/4rest/ An6, An6, G6};*/
//D6, Cs7, F6, Bb6, E6
int timeB2[lengthArray2] = {
  0, 300, 900, 1200, 1500, 2100, 2400, 3600, 4800, 6000, 
  /*2nd*/
};

//list of time each not is played
//int timeofnote1[lengthArray1] = {};
//int timeofnote2[lengthArray2] = {};

// list of each note's spacinge
double An5;
double C6;
double Cs6;
double D6;
double E6;
double F6;
double G6;
double An6;
double Bb6;
double Cs7;

// List of notes on motor 1 (preferably space from switch) (controls motors 1)
// G6,Cs6, An5, An6, C6
int notes1[29/*lengthArray1*/] = {An5, An5, C6, An5, C6, C6, An5, C6, Cs6, An5, C6, C6, An5, C6, 
/*second line*/Cs6, An5, C6, C6, An6, /*slow part and third line*/ An6, G6, An6, C6, 
/*4th*/ G6, An6, G6,/*1/4rest*/ An6, An6, G6};

// List of notes on motor 2(preferably space from switch) (controls motors 2)
//D6, Cs7, F6, Bb6, E6

int notes2[25/*lengthArray2*/] = {F6, D6, D6, F6, D6, D6, F6, F6, E6, E6, 
/*second line*/E6, E6, /*slow part*/D6, E6, F6, /*third line*/D6, E6, F6, E6, 
/*4th*/ F6,/*1/4rest*/ F6, F6, F6, F6};
// Function to move solenoids based on a distance (controls motors)
void moveByDistance(int timeB, int distance, int motorspeed, int motordirec) {
  int power;
}
// Function to push solenoid based on the timing?
// function to callibrate location
void calibrate(int motorSpeed, int motorDirec, int switch3) {
  analogWrite(motorSpeed, 250);
  digitalWrite(motorDirec, 1);
  while (digitalRead(switch3)) {
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
  calibrate(motor1s, motor1d, switch1);
  calibrate(motor2s, motor2d, switch2);
  startTime = millis();
}


void loop() {
  currentTime = millis();
  // put your main code here, to run repeatedly:
  // Put all functions together.
  //motor 1
  if (timeB1[m1i] <= (currentTime - startTime)) {
    if (notes1[m1i] == Cs6 || notes1[m1i] == G6 /*notes with sollenoid 1*/) {
      digitalWrite(sollenoid1, 1);
      digitalWrite(sollenoid1, 0);
    }else{
      digitalWrite(sollenoid2, 1);
      digitalWrite(sollenoid2, 0);
    }
    m1i++;
    moveByDistance((timeB1[m1i]- timeB1[m1i-1]), (notes1[m1i]-notes1[m1i-1]), motor1s, motor1d);
  }
  //motor 2
    if (timeB1[m2i] <= (currentTime - startTime)) {
    if (notes2[m2i] == E6 || notes2[m2i] == Bb6 /*notes with sollenoid 1*/) {
      digitalWrite(sollenoid3, 1);
      digitalWrite(sollenoid3, 0);
    }else{
      digitalWrite(sollenoid4, 1);
      digitalWrite(sollenoid4, 0);
    }
    m2i++;
    moveByDistance((timeB1[m2i]- timeB2[m2i-1]), (notes2[m2i]-notes2[m2i-1]), motor2s, motor2d);
  }
  // Check for solenoid moving off path when driven by motor
}
