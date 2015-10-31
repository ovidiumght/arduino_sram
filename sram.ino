//**************************************************************//
//  Name    : shiftOutCode, Hello World                         //
//  Author  : Carlyn Maw,Tom Igoe                               //
//  Date    : 25 Oct, 2006                                      //
//  Version : 1.0                                               //
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                            //
//****************************************************************

//Pin connected to ST_CP of 74HC595
int latchPin = 12;
//Pin connected to SH_CP of 74HC595
int clockPin = 13;
////Pin connected to DS of 74HC595
int dataPin = 11;
int cs1 = A0;
int cs2 = 9;
int we = 10;
int oe = 8;

void setup() {
  Serial.begin(9600);
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  //Serial.println('TEST');
  //write();
  //read();
}

void write() {
    
    DDRD = B11111111;
    
    //count up routine
    //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, MSBFIRST, 1);   
    //return the latch pin high to signal chip that it 
    //no longer needs to listen for information
    digitalWrite(latchPin, HIGH);

    delay(100);
    // First bit doesn't work, also the 7nth and 8th
    PORTD = B10000001;
    //Serial.print('Writing');
    //Serial.print(PORTD);
    digitalWrite(cs1,LOW);
    digitalWrite(cs2,HIGH);
    digitalWrite(we,LOW);
    digitalWrite(oe,HIGH);
    digitalWrite(cs1, HIGH);
    digitalWrite(cs2, LOW);
    digitalWrite(we, HIGH);
    delay(100);
}

void read(){
  delay(500);
  int b0,b1,b2,b3,b4,b5,b6,b7;
  
    DDRD = B00000000;
    
    
    //count up routine
    //ground latchPin and hold low for as long as you are transmitting
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, MSBFIRST, 1);   
    //return the latch pin high to signal chip that it 
    //no longer needs to listen for information
    digitalWrite(latchPin, HIGH);
    delay(500);
    digitalWrite(cs2,HIGH);
    digitalWrite(cs1,LOW);
    digitalWrite(we,HIGH);
    digitalWrite(oe,LOW);
    //Serial.print('Reading');
    //delay(500);
    Serial.print(PIND,BIN);
    Serial.print('\n');

    
}
void loop() {
  write();
  read();
} 
