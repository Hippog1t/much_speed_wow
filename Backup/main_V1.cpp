#include <Arduino.h>
#include "header.h"
#include <DigiPotX9Cxxx.h>

DigiPot potSpeed(2,3,4);
DigiPot potTurn(5,6,7);

int incomingByte = 0; // for incoming serial data
int i, decrease, increase;
bool resetFlag = true;

void readState(){
    // Serial.print("Speed :");
    // Serial.print(potSpeed.get());
    // Serial.print(" ");
    // Serial.println(analogRead(A0));
    // Serial.print("Turn :");
    // Serial.print(potTurn.get());
    // Serial.print(" ");
    // Serial.println(analogRead(A1));
}

void readPot(){
  int a = potSpeed.get();
//  int b = potTurn.get();
  // Serial.print("Speed ");
  // Serial.print(a);
  // Serial.print(" ");
  // Serial.print("Turn ");
  //// Serial.println(b);
}

void neutral(){
//  readState();
  potSpeed.set(50);
  potTurn.set(50);
//  readState();
}

void potReset(){
  readState();
  potSpeed.reset();
  potTurn.reset();
  // Serial.println("Reset");
  readState();
}
void potSetup(){
//  readState();
//  potReset();
  potSpeed.set(99);
  potTurn.set(99);
//  potReset();
  // Serial.println("Initial setup");
//  readState();
}
void setup() {
  Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
  delay(500);
  Serial.println("Setup OK");
}

void loop() {
/*  if (resetFlag){
    resetFlag = false;
    potSetup();
  }
  */
  // send data only when you receive data:
  if (Serial.available() > 0) {
    //potReset();
    // read the incoming byte:
    incomingByte = Serial.read();

    switch(incomingByte)
    {
      case 69:
        // Serial.println("up");
        if (potSpeed.get() > 1 && potSpeed.get() >= 20){
          potSpeed.decrease(2);

        }

        break;
      case 70:
        // Serial.println("up-right");
        if (potSpeed.get() > 1 && potSpeed.get() >= 20){
          potSpeed.decrease(2);

        }
        if (potTurn.get() > 1){
          potTurn.decrease(10);

        }
        break;
      case 71:
        // Serial.println("right");
        if (potTurn.get() > 1){
          potTurn.decrease(10);

        }
        break;
      case 72:
        // Serial.println("down-right");

        if (potSpeed.get() < 99){
          potSpeed.increase(10);
        }
        if (potTurn.get() > 1){
          potTurn.decrease(10);

        }
        break;
      case 65:
        Serial.println("down");
        if (potSpeed.get() < 99){
          Serial.println("In Down");
          potSpeed.increase(10);
        }
        break;
      case 66:
        // Serial.println("down-left");
        if (potSpeed.get() < 99){
          potSpeed.increase(10);
        }
        if (potTurn.get() < 99){
          potTurn.increase(10);
        }
        break;
      case 67:
        // Serial.println("left");
        if (potTurn.get() < 99){
          potTurn.increase(10);
        }
        break;
      case 68:
        // Serial.println("up-left");
        if (potSpeed.get() > 1 && potSpeed.get() >= 20){
          potSpeed.decrease(2);

        }
        if (potTurn.get() < 99){
          potTurn.increase(10);
        }
        break;
      case 73:
        neutral();
        break;
    }





    // Serial.println(incomingByte);
//    readState();


  }
}
