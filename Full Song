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
const int motorTimeJump2 = 242;   //F6-D6 to E6-F6
const int motorTimeJump2R = 290;  //E6-F6 to F6-D6

const int solenoid1 = 6;
const int solenoid2 = 7;
const int solenoid3 = 8;
const int solenoid4 = 9;

/*Note Layout:
E6 - C6*
Bb6 - A6
*F6 - A5*
C#7 - G6
*D6 - C#6
* indicate start position
*/

/*Solenoid Layout:
2 - 4
1 - 3
*/

/*Motor Layout:
2
1*/

/*Limit Switch Layout:
2
1
*/

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
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 1; i++) {  //1 for high, 0 is low, measure 1
    Serial.println("measure 1");
    digitalWrite(solenoid2, HIGH);  //F6
    delay(timing[0]);
    digitalWrite(solenoid2, LOW);
    digitalWrite(solenoid1, HIGH);  //D6
    delay(timing[0]);
    digitalWrite(solenoid1, LOW);
    digitalWrite(solenoid3, HIGH);  //A5
    delay(timing[0]);
    digitalWrite(solenoid3, LOW);
    digitalWrite(solenoid1, HIGH);  // D6
    delay(timing[0]);
    digitalWrite(solenoid1, LOW);
  }

  for (int i = 0; i <= 1; i++) {  //1 for high, 0 is low, measure 2
    Serial.println("measure 2");
    digitalWrite(solenoid2, HIGH);  //F6
    delay(timing[0]);
    digitalWrite(solenoid2, LOW);
    digitalWrite(solenoid4, HIGH);  //C6
    delay(timing[0]);
    digitalWrite(solenoid4, LOW);
    digitalWrite(solenoid3, HIGH);  //A5
    delay(timing[0]);
    digitalWrite(solenoid3, LOW);
    if (i == 0) {
      digitalWrite(solenoid4, HIGH);  //C6
      delay(timing[0]);
      digitalWrite(solenoid4, LOW);
    } else {
      digitalWrite(motor2d, 0);
      digitalWrite(motor2s, motorSpd2);

      digitalWrite(solenoid4, HIGH);  //C6

      delay(motorTimeJump2);
      digitalWrite(motor2s, 0);

      delay(timing[0] - motorTimeJump2);
      digitalWrite(solenoid4, LOW);
    }
  }

  for (int i = 0; i <= 2; i++) {  //measure 3-4 1st half
    if (i == 0) {
      Serial.println("measure 3-4 1st half");
      digitalWrite(motor1d, 0);
      digitalWrite(motor1s, motorSpd1);

      digitalWrite(solenoid2, HIGH);  //E6
      delay(motorTime1ab-5);
      digitalWrite(motor1s, 0);

      delay(timing[0] - motorTime1ab-5);
      digitalWrite(solenoid2, LOW);

    } else {
      digitalWrite(solenoid2, HIGH); //E6
      delay(timing[0]);
      digitalWrite(solenoid2, LOW);
    }
    digitalWrite(solenoid3, HIGH); // Cs6
    delay(timing[0]);
    digitalWrite(solenoid3, LOW);
    digitalWrite(solenoid4, HIGH); // A5
    delay(timing[0]);
    digitalWrite(solenoid4, LOW);
    digitalWrite(solenoid3, HIGH); // Cs6
    delay(timing[0]);
    digitalWrite(solenoid3, LOW);
  }
  Serial.println("measure 4 2nd half"); //measure 4 2nd half
  digitalWrite(solenoid2, HIGH);  //E6
  delay(timing[0]);
  digitalWrite(solenoid2, LOW);
  digitalWrite(solenoid3, HIGH); //Cs6
  delay(timing[0]);
  digitalWrite(solenoid3, LOW);
  // not accurate
  digitalWrite(motor1s, motorSpd1);
  digitalWrite(motor1d, 1);
  delay(motorTime1b); // Change if motor over/undershoots A6
  digitalWrite(motor1s, 0); // Stops at A6

  digitalWrite(solenoid4, HIGH); //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  

// Measure 5
  Serial.println("measure 5");    // Outputs "measure 5" to serial output

  digitalWrite(motor2s, motorSpd2); // Moves belt 2 to D6-F6
  digitalWrite(motor2d, 1);

  delay(motorTimeJump2R-5);
  digitalWrite(motor2s, 0);

  digitalWrite(solenoid1, HIGH);  //D6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);

  digitalWrite(motor2s, motorSpd2);
  digitalWrite(motor2d, 0);
  delay(motorTimeJump2-4);
  digitalWrite(motor2s, 0);
  delay(timing[4] - motorTimeJump2-4 - timing[0]);

  digitalWrite(solenoid2, HIGH);  //E6
  delay(timing[1]);
  digitalWrite(solenoid2, LOW);

// Measure 6
  Serial.println("measure 6");
  digitalWrite(solenoid1, HIGH);  //F6
  delay(timing[5]);
  digitalWrite(solenoid1, LOW);

//measure 7
  Serial.println("measure 7"); 
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[2]);
  digitalWrite(solenoid4, LOW);

  digitalWrite(solenoid3, HIGH); // G6
  delay(timing[2]);
  digitalWrite(solenoid3, LOW);

  digitalWrite(solenoid4, HIGH); //A6
  delay(timing[1]);
  digitalWrite(solenoid4, LOW);

//measure 8
  digitalWrite(motor1s, motorSpd1); //Moves belt 1 to C6
  digitalWrite(motor1d, 1);
  delay(motorTime1a +12);
  digitalWrite(motor1s, 0);

  Serial.println("measure 8"); 
  digitalWrite(solenoid4, HIGH);  //C6
  delay(timing[5]);
  digitalWrite(solenoid4, LOW);

  digitalWrite(motor2s, motorSpd2);
  digitalWrite(motor2d, 1);
  delay(motorTimeJump2R + 9);
  digitalWrite(motor2s, 0);

//measure 9
  Serial.println("measure 9"); 
  digitalWrite(solenoid1, HIGH);  //D6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);

  digitalWrite(motor2s, motorSpd2);
  digitalWrite(motor2d, 0);
  delay(motorTimeJump2-2);
  digitalWrite(motor2s, 0);
  delay(timing[4] - timing[0]);

  digitalWrite(solenoid2, HIGH); // E6
  delay(timing[1]);
  digitalWrite(solenoid2, LOW);

//measure 10
  Serial.println("measure 10");  
  digitalWrite(solenoid1, HIGH); //F6
  delay(timing[3]);
  digitalWrite(solenoid1, LOW);
  digitalWrite(solenoid2, HIGH); //E6
  delay(timing[3]);
  digitalWrite(solenoid2, LOW);
 //changing
  digitalWrite(motor1d, 0);
  digitalWrite(motor1s, motorSpd1);
  delay(motorTime1a);
  digitalWrite(motor1s, 0);


//measure 11
  Serial.println("measure 11");   
  digitalWrite(solenoid3, HIGH);  //G6
  delay(timing[3]);
  digitalWrite(solenoid3, LOW);
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[3]);
  digitalWrite(solenoid4, LOW);
  
//measure 12
  Serial.println("measure 12");  
  digitalWrite(solenoid3, HIGH);  //G6
  delay(timing[3]);
  digitalWrite(solenoid3, LOW);
  digitalWrite(solenoid1, HIGH);  //F6
  delay(timing[3]);
  digitalWrite(solenoid1, LOW);

  //measure 13
  Serial.println("measure 13");
  delay(timing[1]);               // quarter rest
  digitalWrite(solenoid1, HIGH);  //F6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);
  digitalWrite(solenoid1, HIGH);  //F6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);
  digitalWrite(solenoid1, HIGH);  //F6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);


  //measure 14
  Serial.println("measure 14");
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  delay(timing[0]);
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  delay(timing[0]);
  digitalWrite(solenoid3, HIGH);  //G6
  delay(timing[0]);
  digitalWrite(solenoid3, LOW);
  delay(timing[0]);
  digitalWrite(solenoid1, HIGH);  //F6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);

  Serial.println("measure 15");   //measure 15
  delay(timing[1]);               //rest
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  delay(timing[0]);
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  delay(timing[0]);
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  delay(timing[0]);

  Serial.println("measure 16");   //measure 16
  digitalWrite(solenoid3, HIGH);  //G6
  delay(timing[0]);
  digitalWrite(solenoid3, LOW);
  delay(timing[0]);
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  delay(timing[0]);
  digitalWrite(solenoid3, HIGH);  //G6
  delay(timing[0]);
  digitalWrite(solenoid3, LOW);
  delay(timing[0]);
  digitalWrite(solenoid1, HIGH);  //F6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);

  Serial.println("measure 17");   //measure 17
  delay(timing[1]);               // quarter rest
  digitalWrite(solenoid1, HIGH);  //F6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);
  digitalWrite(solenoid1, HIGH);  //F6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);
  digitalWrite(solenoid1, HIGH);  //F6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);

  Serial.println("measure 18");   //measure 18
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  delay(timing[0]);
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  delay(timing[0]);
  digitalWrite(solenoid3, HIGH);  //G6
  delay(timing[0]);
  digitalWrite(solenoid3, LOW);
  delay(timing[0]);
  digitalWrite(solenoid1, HIGH);  //F6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);

  Serial.println("measure 19");   //measure 19
  delay(timing[1]);               //rest
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  delay(timing[0]);
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  delay(timing[0]);
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  delay(timing[0]);

  digitalWrite(motor2d, 1);  //measure 20
  digitalWrite(motor2s, motorSpd2);
  delay(motorTime2a);
  digitalWrite(motor2s, 0);
  delay(timing[1] - motorTime2a);
  digitalWrite(solenoid1, HIGH);  //C#7
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);
  digitalWrite(solenoid1, HIGH);  //C#7
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);
  digitalWrite(solenoid1, HIGH);  //C#7
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);

  Serial.println("measure 21");  //measure 21
  digitalWrite(motor2d, 0);
  digitalWrite(motor2s, motorSpd2);
  delay(motorTime2aR);
  digitalWrite(motor2s, 0);
  delay(timing[1] - motorTime2a);  // remaining quarter rest
  digitalWrite(solenoid1, HIGH);   //F6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);
  digitalWrite(solenoid1, HIGH);  //F6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);
  digitalWrite(solenoid1, HIGH);  //F6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);

  Serial.println("measure 22");   //measure 22
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  delay(timing[0]);
  digitalWrite(solenoid4, HIGH);  //A6
  delay(timing[0]);
  digitalWrite(solenoid4, LOW);
  delay(timing[0]);
  digitalWrite(solenoid3, HIGH);  //G6
  delay(timing[0]);
  digitalWrite(solenoid3, LOW);
  delay(timing[0]);
  digitalWrite(solenoid1, HIGH);  //F6
  delay(timing[0]);
  digitalWrite(solenoid1, LOW);
  delay(timing[0]);

  digitalWrite(motor2d, 1);  //measure 23
  digitalWrite(motor2s, motorSpd2);
  delay(motorTime2a);
  digitalWrite(motor2s, 0);
  delay(timing[1] - motorTime2a);
  digitalWrite(solenoid2, HIGH);  //Bb6
  delay(timing[0]);
  digitalWrite(solenoid2, LOW);
  delay(timing[0]);
  digitalWrite(solenoid2, HIGH);  //Bb6
  delay(timing[0]);
  digitalWrite(solenoid2, LOW);
  delay(timing[0]);
  digitalWrite(solenoid2, HIGH);  //Bb6
  delay(timing[0]);
  digitalWrite(solenoid2, LOW);
  delay(timing[0]);

  digitalWrite(solenoid3, HIGH);  //measure 24
  delay(timing[1]);
  digitalWrite(solenoid3, LOW);
  digitalWrite(motor1d, 1);
  digitalWrite(motor1s, motorSpd1);
  delay(motorTime1aR);
  digitalWrite(motor1s, 0);
  delay(timing[1] - motorTime1aR);
  digitalWrite(solenoid4, HIGH);
  delay(timing[1]);
  digitalWrite(solenoid4, LOW);

  digitalWrite(motor1d, 0);  //measure 25
  digitalWrite(motor1s, motorSpd1);
  delay(motorTime1a);
  digitalWrite(motor1s, 0);
  delay(timing[1] - motorTime1a);
  digitalWrite(solenoid4, HIGH);
  delay(timing[3]);
  digitalWrite(solenoid4, LOW);
  digitalWrite(solenoid1, HIGH);
  delay(timing[3]);
  digitalWrite(solenoid1, LOW);

  Serial.println("finished");
  delay(999999999);
}
