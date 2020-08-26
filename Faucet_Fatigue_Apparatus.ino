// target pressure 50 psi
// actuator pressure 70 psi
// three channel...removing second channel and tap in 1st position.  connecting channel 1 to the tap in 2nd position
const int TS1 = 4; // associates tap #1 air solenoid vavle with digital ouput pin 4 
const int TS2 = 12; // associates tap #2 air solenoid vavle with digital ouput pin 12
const int TS3 = 11; // associates tap #3 air solenoid vavle with digital ouput pin 11
const int TS4 = 10; // associates tap #4 air solenoid vavle with digital ouput pin 10
const int Engine = 9; // associates engine air solenoid vavle with digital ouput pin 9
const int WaterIn = 8; // associates water solenoid vavle with digital ouput pin 8
const int PumpPower = 7; // pump power

volatile byte LED = 5;
const int BUTTON = 2; // changed from int to byte
volatile int State = 6; // state of on/off switch

const int potPin = 0;
const int LowTHRESHOLD = 100; // down from 225, 150
const int HighTHRESHOLD = 1015; // 1015 worke but was too low

int potVal = 0; // initializes water level as low

// Interrupt Service Routine (ISR)
void switchPressed ()
{
  if (digitalRead (BUTTON) == HIGH)
    digitalWrite (LED, HIGH);
  else
    digitalWrite (LED, LOW);
}  // end of switchPressed

void setup() {
  // put your setup code here, to run once:

pinMode(TS1, OUTPUT);
pinMode(TS2, OUTPUT);
pinMode(TS3, OUTPUT);
pinMode(TS4, OUTPUT);
pinMode(Engine, OUTPUT);
pinMode(WaterIn, OUTPUT);
pinMode(PumpPower, OUTPUT);
pinMode(LED, OUTPUT);
pinMode(State, OUTPUT);
attachInterrupt (digitalPinToInterrupt (BUTTON), switchPressed, CHANGE);  // attach interrupt handle
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(PumpPower, LOW);  // pump off
// delay(1000); // pause to allow for pump spool down
// digitalWrite(WaterIn, LOW);  // water valve closed

//int val = digitalRead(Switch); removed for interrupt 
if(digitalRead (LED) == HIGH)
{
potVal = analogRead(potPin);

while (potVal >= LowTHRESHOLD && digitalRead (LED) == HIGH) 
{
  digitalWrite(Engine, HIGH);
  delay(1000);              // needs 3 seconds to allow tap sytem to get full pressure
  digitalWrite(TS1, HIGH);
  delay(500);                // changed from 1000 to 500
  digitalWrite(TS1, LOW);
  delay(5000);               // allow tap to run for 4 seconds
  
 potVal = analogRead(potPin);
 //digitalRead(LED); 

  if(potVal <= LowTHRESHOLD || digitalRead (LED) == LOW) 
  {
  
    break;
  }
  
  // digitalWrite(TS2, HIGH);
  //delay(500);
  //digitalWrite(TS2, LOW);
  //delay(4500);               // allow tap to run for 4 seconds
  
 potVal = analogRead(potPin);
 //digitalRead(LED); 

  if(potVal <= LowTHRESHOLD || digitalRead (LED) == LOW)
  {
   
    break;
  }
  
  digitalWrite(TS3, HIGH);
  delay(500);
  digitalWrite(TS3, LOW);
  delay(4500);               // allow tap to run for 4 seconds

 potVal = analogRead(potPin); // channel three eliminated
 //digitalRead(LED); 

 if(potVal <= LowTHRESHOLD || digitalRead (LED) == LOW)
  {
    
    break;
 }

 digitalWrite(TS4, HIGH);
 delay(500);
 digitalWrite(TS4, LOW);
 delay(5000);               // allow tap to run for 4 seconds

 potVal = analogRead(potPin);
// digitalRead(LED); 

  if(potVal <= LowTHRESHOLD || digitalRead (LED) == LOW)
  {
    
    break;
}

}
digitalWrite(Engine, LOW);
delay(15000); // allow pressure pot to vent

while (potVal <= HighTHRESHOLD && digitalRead (LED) == HIGH)
{

digitalWrite(Engine, LOW);
digitalWrite(WaterIn, HIGH);
delay(2000); // ensure water valve is open
digitalWrite(PumpPower, LOW);
digitalWrite(PumpPower, HIGH);

 potVal = analogRead(potPin);
 //digitalRead(LED);
 
 if(potVal >= HighTHRESHOLD  || digitalRead (LED) == LOW)
  {
    digitalWrite(PumpPower, LOW);
    delay(5000);            // delay to allow pump spool down
    digitalWrite(WaterIn, LOW);
    break;
  }
}
}
}
