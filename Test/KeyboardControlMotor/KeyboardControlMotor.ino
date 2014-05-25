#include <AFMotor.h>
 
// Declare motors
AF_DCMotor motorLeftWheel(1, MOTOR12_64KHZ);
AF_DCMotor motorRightWheel(2, MOTOR12_64KHZ);

int incomingByte;

void setup() {
  
  Serial.begin(9600);
  
  // Set motorspeed (1-255)
  motorLeftWheel.setSpeed(255); 
  motorRightWheel.setSpeed(255);
}

void loop() {
  
  // Check if there is serial data
  if (Serial.available() > 0) {
   
    // Read from serial data
    incomingByte = Serial.read();
    
    // Based on incomingByte, find out how to run the motor
    if (incomingByte == 'S') {
      motorLeftWheel.run(RELEASE);     
      motorRightWheel.run(RELEASE);
    } else if (incomingByte == 'U') {
      motorLeftWheel.run(FORWARD);      
      motorRightWheel.run(FORWARD);
    } else if (incomingByte == 'D') {
      motorLeftWheel.run(BACKWARD);     
      motorRightWheel.run(BACKWARD);
    } else if (incomingByte == 'T') {
      motorLeftWheel.run(FORWARD);     
      motorRightWheel.run(BRAKE);
    } else if (incomingByte == 'R') {
      motorLeftWheel.run(BRAKE);     
      motorRightWheel.run(FORWARD);
    } 
  }
}
