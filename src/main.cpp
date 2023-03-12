#include <Arduino.h>
#include "header.h"
#include <DigiPotX9Cxxx.h>

DigiPot potSpeed(2,3,4);
DigiPot potTurn(5,6,7);

String incomingString;
char incomingByte, prevIncomingByte;
const int MAX_INPUT = 3;
char input_line [MAX_INPUT];
int input_pos = 0;
//char convertBytes[5];
int speed_or_rot[2];
bool resetFlag = true;

void potReset(){
  potSpeed.reset();
  potTurn.reset();
}

void setup() {
  Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
  delay(500);
  Serial.println("Setup OK");
}

void loop() {
  if (resetFlag){
    resetFlag = false;
    potReset();
    /*potSpeed.set(50);
    potTurn.set(50);
    Serial.print("Speed reset ");
    delayMicroseconds(50000);
    Serial.println(potSpeed.get());
    delayMicroseconds(50000);
    Serial.print("Rot reset ");
    delayMicroseconds(50000);
    Serial.println(potTurn.get());
    delayMicroseconds(50000);*/
    //Serial.println("Reset");
    //delayMicroseconds(50000);
  }
  /*
  // send data only when you receive data:
  while (Serial.available() > 0) {
    incomingByte = Serial.read();
    switch (incomingByte)
    {

    case '\n':   // end of text
      input_line [input_pos] = 0;  // terminating null byte

      // reset buffer for next time
      input_pos = 0;
      break;

    case '\r':   // discard carriage return
      break;

    default:
      // keep adding if not full ... allow for terminating null byte
      if (input_pos < (MAX_INPUT - 1))
        input_line [input_pos++] = incomingByte;
      break;

    }

  }*/

    //potReset();
    // read the incoming byte:
    /*
    incomingString = Serial.read();
    Serial.print("IncomingString : ");
    Serial.println(incomingString);
    delayMicroseconds(50000);
    incomingByte = incomingString.toInt()
    */

    if (Serial.available() > 0) {
    incomingByte = Serial.read();
    /*Serial.print((int)incomingByte);
    delayMicroseconds(50000);
    Serial.print(" = ");
    delayMicroseconds(50000);
    Serial.println((int)incomingByte);
    delayMicroseconds(50000);*/
    if(prevIncomingByte == 'h'){
      speed_or_rot[0] = (int)incomingByte;

      //Serial.print("Speed ");
      //delayMicroseconds(50000);
      //Serial.println(speed_or_rot[0]);

      delayMicroseconds(50000);
      delayMicroseconds(50000);
      delayMicroseconds(50000);
      delayMicroseconds(50000);

    }
    else if (prevIncomingByte == 'j'){
      speed_or_rot[1] = (int)incomingByte;

      //Serial.print("Rot ");
      //delayMicroseconds(50000);
      //Serial.println(speed_or_rot[1]);

      //delayMicroseconds(50000);
      //delayMicroseconds(50000);

      delayMicroseconds(50000);
      delayMicroseconds(50000);
      delayMicroseconds(50000);
      delayMicroseconds(50000);

    }
    if(incomingByte != '\r' || incomingByte != '\t' ){
      prevIncomingByte = incomingByte;
    }



    }



    //Serial.println(potSpeed.get());
    //delayMicroseconds(50000);

    //Serial.println((int)incomingByte);
    //delayMicroseconds(50000);


  potSpeed.set(speed_or_rot[0]);
  delayMicroseconds(50000);
  potTurn.set(speed_or_rot[1]);
  delayMicroseconds(50000);






    // Serial.println(incomingByte);
//    readState();


  }
