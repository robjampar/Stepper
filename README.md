# Stepper
Stepper motor library for arduino

Setup a stepper motor with its constructor:

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
