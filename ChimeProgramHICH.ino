const int switch1 = 2;
const int switch2 = 3;

const int motor1s = 10;  //speed 0-255
const int motor1d = 12;  //direction 0 is + direction, 1 is - direction
const int motor2s = 11;
const int motor2d = 13;

int motorSpd1 = 40;
int motorSpd2 = 255;           //proportionally same speed as motor 1? NO
const int motorTime1a = 70;    //C6-A5 to A6-G6
const int motorTime1aR = 76;    //A6-G6 to C6-A5
const int motorTime1b = 80;    //A5-C#6 to A6-G6
const int motorTime1ab = 125;  //C6-A5 to A5-C#6

const int motorTime2a = 152;      //E6-F6 to Bb6-C#7
const int motorTime2aR = 122;     //Bb6-C#7 to E6-F6
const int motorTimeJump2 = 243;   //F6-D6 to E6-F6
const int motorTimeJump2R = 290;  //E6-F6 to F6-D6

const int solenoid1 = 6;
const int solenoid2 = 7;
const int solenoid3 = 8;
const int solenoid4 = 9;
int timing[6] = {
  275 /*Eight Note*/, 550 /*Quarter Note*/, 825 /*Dotted Quarter*/, 1100 /*Half Note*/, 1650 /*Dotted Half*/, 2200 /*Whole Note*/
};

const int spacer = 5;  //for repeated notes

void setup() {
  // put your setup code here, to run once:
  //pinMode(switch1, INPUT_PULLUP); //sets switches as an input
  //pinMode(switch2, INPUT_PULLUP); //sets switches as an input
  for (int i = 6; i <= 13; i++) {  //sets solenoids and motors as an output
    pinMode(i, OUTPUT);
  }
  /* for (int i = 0; i <= 6; i++) {
    timing[i] = timing[i];  // allows slowing of code for testing
  }*/
  Serial.begin(9600);
}

void loop() {
  digitalWrite(solenoid2, HIGH);  //F6
  delay(timing[1]);
  digitalWrite(solenoid2, LOW);

  digitalWrite(solenoid1, HIGH);  //D6
  delay(timing[1]);
  digitalWrite(solenoid1, LOW);


  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  delay(timing[0]);
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);

  digitalWrite(motor2s, motorSpd2); // Move to F6-E6
  digitalWrite(motor2d, 0);
  delay(motorTimeJump2);
  digitalWrite(motor2s, 0);

  digitalWrite(solenoid2, HIGH);  //E6
  delay(timing[1]);
  digitalWrite(solenoid2, LOW);

  digitalWrite(motor1s, motorSpd1);  // move to Cs6-A5
  digitalWrite(motor1d, 0);
  delay(motorTime1a-7);
  digitalWrite(motor1s, 0);


  digitalWrite(motor2s, motorSpd2); // Move to D6-F6
  digitalWrite(motor2d, 1);
  delay(motorTimeJump2R + 12);
  digitalWrite(motor2s, 0);

  digitalWrite(solenoid3, HIGH);  //Cs6
  delay(timing[1]);
  digitalWrite(solenoid3, LOW);

  digitalWrite(solenoid4, HIGH);  //A5
  delay(timing[1]);
  digitalWrite(solenoid4, LOW);
  
  digitalWrite(solenoid3, HIGH);  //Cs6
  delay(timing[1]);
  digitalWrite(solenoid3, LOW);
  

  digitalWrite(solenoid1, HIGH);  //D6
  delay(timing[1]);
  digitalWrite(solenoid1, LOW);

  delay(timing[1]);

  digitalWrite(solenoid1, HIGH);  //D6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);


  Serial.println("finished");
  delay(999999999);
}
