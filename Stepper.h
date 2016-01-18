#ifndef STEPPER_H
#define STEPPER_H

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define CLOCKWISE 1
#define COUNTERCLOCKWISE 2

class Stepper {

  private:
    int pins[];
    byte steps[];
    unsigned int stepCount;
    float stepsPerRotation;
    float rotationsPerMinute;
    float distancePerRotation;
    byte direction;

    unsigned int stepsRemaining;
    unsigned int currentStepIndex;
    unsigned int microsBetweenSteps;
    unsigned int nextMicrosForStep;

  public:
    Stepper(int pins[],
                  byte steps[] = (byte[]){8, B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001},
                  float stepsPerRotation = 4075.7728395,
                  float rotationsPerMinute = 12,
                  float distancePerRotation = 200,
                  byte direction = CLOCKWISE);

    void rotate(int rotations);
    void rotateByDegrees(float degrees);
    void move(float distance);

    void run();

    boolean isDone;

};

#endif
