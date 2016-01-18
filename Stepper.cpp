#include "Stepper.h"

Stepper::Stepper(int pins[], int, byte steps[], float stepsPerRotation, float rotationsPerMinute, float distancePerRotation, byte direction) {

  this->pins = pins;
  this->steps = steps;
  this->stepsPerRotation = stepsPerRotation;
  this->rotationsPerMinute = rotationsPerMinute;
  this->distancePerRotation = distancePerRotation;
  this->direction = direction;

  for (unsigned int pin = 1; pin <= pins[0]; ++pin)   // Setup the pims
      pinMode(pins[pin], OUTPUT);

  this->stepCount = steps[0];
  for (int i = 0; i < this->stepCount; i++)   // Remove the stepcount from the steps array
    this->steps[i] = steps[i+1];

  this->currentStepIndex = 0;
  this->isDone = true;
  this->microsBetweenSteps = ((60*1000000)/this->stepsPerRotation)/this->rotationsPerMinute;
}

void Stepper::step() {
  if (this->stepsRemaining != 0) {
    digitalWrite(this->pins[1], (this->steps[this->currentStepIndex] & B1000));
    digitalWrite(this->pins[2], (this->steps[this->currentStepIndex] & B0100));
    digitalWrite(this->pins[3], (this->steps[this->currentStepIndex] & B0010));
    digitalWrite(this->pins[4], (this->steps[this->currentStepIndex] & B0001));

    int stepChange = ((this->direction == CLOCKWISE) == (this->stepsRemaining > 0)? 1 : -1);
    this->stepsRemaining += stepChange;
    this->current_step += stepChange;
    if(this->current_step < 0) {
      this->current_step = 8;
    }
    else if(this->current_step > 8) {
      this->current_step = 0;
    }

  }
  else {
    this->isDone = true;
  }
}

void addSteps(int steps) {
  this->isDone = false;
  this->stepsRemaining += steps;
}

void CustomStepper::rotate(int rotations) {
  addSteps(rotations * this->stepsPerRotation);
}

void CustomStepper::rotateByDegrees(float degrees) {
  addSteps((degrees * this->stepsPerRotation)/360);
}

void CustomStepper::move(float distance) {
  rotate(distance / this->distancePerRotation);
}


void run() {
  int currentMicros = micros();
  if (this->nextMicrosForStep <= currentMicros){
    step();
    this->nextMicrosForStep = currentMicros + microsBetweenSteps;
  }
}
