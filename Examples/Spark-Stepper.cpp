#include "application.h"

#include "Stepper.h"

// change this to the number of steps on your motor
#define STEPS 48

int toggle(String args);

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
//
// ARDUINO             12,11,10,9
// SPARK SHIELD SHIELD A4,A5,A2,D6
Stepper stepper(STEPS,A4,A5,A2,D6);

int toggleCount = 0;
int TWO_ROTATIONS = (STEPS * 2);
int SPEED = 60; // RPM

void setup()
{
  Spark.function("toggle", toggle);
  Spark.variable("rpm", &SPEED, INT);
  Spark.variable("toggleCount", &toggleCount, INT);
  
  stepper.setSpeed(SPEED);
  pinMode(D7, OUTPUT);
}


int toggle(String args)
{
    digitalWrite(D7, HIGH);
    stepper.step(TWO_ROTATIONS);
    digitalWrite(D7, LOW);
    toggleCount = toggleCount++;
    return 200;
}

void loop()
{

}