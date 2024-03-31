void setup() {
  // put your setup code here, to run once:
  //Standard config for Chime Machine Control Box
  pinMode (2, INPUT_PULLUP);
  pinMode (3, INPUT_PULLUP);
  for (int i=6; i<=13; i++){ pinMode(i,OUTPUT); }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}
