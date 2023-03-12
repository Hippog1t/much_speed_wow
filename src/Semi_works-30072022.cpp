/*#include <Arduino.h>
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

  }

    //potReset();
    // read the incoming byte:
    /*
    incomingString = Serial.read();
    Serial.print("IncomingString : ");
    Serial.println(incomingString);
    delayMicroseconds(50000);
    incomingByte = incomingString.toInt()


    if (Serial.available() > 0) {
    incomingByte = Serial.read(); //Serial.parseInt(SKIP_WHITESPACE);
    //Serial.print(incomingByte);
    if(incomingByte == 'h'){
      speed_or_rot[0] = Serial.parseInt();
      /*
      Serial.print("Speed ");
      delayMicroseconds(50000);
      Serial.println(speed_or_rot[0]);
      delayMicroseconds(50000);

    }
    else if (incomingByte == 'j'){
      speed_or_rot[1] = Serial.parseInt();
      /*Serial.print("Rot ");
      delayMicroseconds(50000);
      Serial.println(speed_or_rot[1]);
      delayMicroseconds(50000);

    }
    //prevIncomingByte = incomingByte;

/*
    Serial.println(incomingByte);
    delayMicroseconds(50000);
    Serial.println((int)incomingByte);
    delayMicroseconds(50000);

  }
  potSpeed.set(speed_or_rot[0]);
  potTurn.set(speed_or_rot[1]);






    // Serial.println(incomingByte);
//    readState();


  }
*/
