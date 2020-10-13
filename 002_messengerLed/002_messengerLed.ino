#include <CmdMessenger.h>
#include <Servo.h>

const int pinGreenLed = 13;
const int pinRedLed = 12;
const int pinServo01 = 11;

CmdMessenger msg = CmdMessenger(Serial);
Servo servo01;

enum{
  CMD_SETLED = 0,     /* 0, led, state; */  
  CMD_SERVO = 1       /* 1, servo, angle(0~180) */
};

void attachCommandCallbacks(){
  msg.attach(CMD_SETLED, callbackOnLed);
  msg.attach(CMD_SERVO, callbackOnServo);
}

void callbackOnLed(){
  int ledEnum = msg.readInt16Arg();
  bool ledState = msg.readBoolArg();
  switch (ledEnum){
    case 0:
        digitalWrite(pinGreenLed, (ledState?HIGH:LOW));
        break;
    case 1:
        digitalWrite(pinRedLed, (ledState?HIGH:LOW));
        break;
    default:
      break;
  }
}

void callbackOnServo(){
  String servoEnum = msg.readStringArg();
  int servoVal = msg.readInt16Arg();
  if(servoEnum.equals("servo01")){
    servo01.write(servoVal);
  }
}

void setup() {
  Serial.begin(9600); 
  msg.printLfCr();   
  attachCommandCallbacks();
  pinMode(pinGreenLed, OUTPUT);
  pinMode(pinRedLed, OUTPUT);
  servo01.attach(pinServo01);
}

void loop() {
  msg.feedinSerialData();
}
