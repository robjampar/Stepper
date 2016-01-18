# Stepper
Stepper motor library for arduino

Setup a stepper motor with its constructor (this should be done in setup()):

```c
Stepper(int pins[], byte steps[], float stepsPerRotation, float rotationsPerMinute, float distancePerRotation, byte direction);
```

eg

```c
Stepper stepperX = Stepper((int[]){4, 2, 3, 4, 5}, (byte[]){4, B1010, B0110, B0101, B1001}, 200, 350, 5, CLOCKWISE);
```

## Array Inputs
The first element in each array arguments on construction should represent the number of elements in that array.
eg "int pins[]{4, 2, 3, 4, 5}" means a motor is connected to 4 pins with pin numbers (2,3,4,5)

Once a Stepper is constructed, you can call any of the step functions:

    step(int steps);
    rotate(float rotations);
    rotateByDegrees(float degrees);
    move(float distance);


## Ensure that the run() method is called
The run method must then be called from anywhere within your loop() function - Note if this is not called often enough, there may be problems with step timing.

```c
void loop() {
  stepperX.run();
}
```

## Default Values
|Argument|Default Value|
| --- | --- |
| pins      | N/A |
| steps      | {8, B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001} |
| stepsPerRotation | 4075.7728395 |
| rotationsPerMinute | 12 |
| distancePerRotation | 200 |
| direction | CLOCKWISE |

These defaults are designed for the 28BYJ-48 motor.


