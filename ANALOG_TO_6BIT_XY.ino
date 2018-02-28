/*
 * ADC JOYSTICK 2 AXIS 
 * Analog to Digital converter for Joystick Arduino UNO/NANO
 * Takes analogue signal from 2Axis Joystick
 * and transform the signal in a digital 6+6 bits 
 */
const int analogInPinX = A4;  // Analog input pin that the potentiometer is attached to
const int analogInPinY = A5;  // Analog input pin that the potentiometer is attached to
int analogValue = 0;         // value read from the pot
int i=0,a,r;
const int ledBitPinX[6]={2,3,4,5,6,7};          // the number of the LED pin
const int ledBitPinY[6]={8,9,10,11,12,13};      // the number of the LED pin

void resetLed(){

  i=5;
  while( i>0 ){
    digitalWrite(ledBitPinX[i], LOW);
    digitalWrite(ledBitPinY[i], LOW);
    i--;
  }
  i=0;
  
  
  }

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(ledBitPinX[0], OUTPUT);
  pinMode(ledBitPinX[1], OUTPUT);
  pinMode(ledBitPinX[2], OUTPUT);
  pinMode(ledBitPinX[3], OUTPUT);
  pinMode(ledBitPinX[4], OUTPUT);
  pinMode(ledBitPinX[5], OUTPUT); 

  pinMode(ledBitPinY[0], OUTPUT);
  pinMode(ledBitPinY[1], OUTPUT);
  pinMode(ledBitPinY[2], OUTPUT);
  pinMode(ledBitPinY[3], OUTPUT);
  pinMode(ledBitPinY[4], OUTPUT);
  pinMode(ledBitPinY[5], OUTPUT); 
}

void loop() {
  a = 0,r = 0, i=0;
  
  // read the analog in value:
  analogValue = analogRead(analogInPinX);
  a = analogValue/16;
  // print the results to the Serial Monitor:
  Serial.print("Analog sensorX = ");
  Serial.print(a);
  Serial.print("\n");
  
  while( a>=1 ){
    r = a%2;
    a = a/2;
    if( r==0 ){
      digitalWrite(ledBitPinX[i], LOW);
      Serial.print("sensor = ");
      Serial.print(i);
      Serial.print(": LOW\n");
    }else{
      digitalWrite(ledBitPinX[i], HIGH);
      Serial.print("sensor = ");
      Serial.print(i);
      Serial.print(": HIGH\n");
    }
    i++;
  }
  while(i<6){
    Serial.print("sensor = ");
    Serial.print(i);
    Serial.print(": LOW\n");
    digitalWrite(ledBitPinX[i], LOW);
    i++;
  }
  
  a = 0 , r = 0 , i=0;
  // read the analog in value:
  analogValue = analogRead(analogInPinY);
  a = analogValue/16;
  // print the results to the Serial Monitor:
  Serial.print("Analog sensorY = ");
  Serial.print(a);
  Serial.print("\n");
  //resetLed();
  while( a>=1 ){
    r = a%2;
    a = a/2;
    if( r==0 ){
      digitalWrite(ledBitPinY[i], LOW);
      Serial.print("sensor = ");
      Serial.print(i);
      Serial.print(": HIGH\n");
    }else{
      digitalWrite(ledBitPinY[i], HIGH);
      Serial.print("sensor = ");
      Serial.print(i);
      Serial.print(": LOW\n");
    }
    i++;
  }
  while(i<6){
    Serial.print("sensor = ");
    Serial.print(i);
    Serial.print(": LOW\n");
    digitalWrite(ledBitPinY[i], LOW);
    i++;
  }
  
  // wait 400 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  //delay(20);
}
