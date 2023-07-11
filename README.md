## Project Name

ON Demand Traffic Light Control

## Description

This repository contains the source code and documentation for an ON demand traffic light control system implemented on the ATmega328P microcontroller (Arduino). The project consists of four layers: MCAL, ECUAL, Application, and Main.

## Layers

### MCAL Layer

The MCAL (Microcontroller Abstraction Layer) layer includes the following drivers:

- DIO Driver: Provides functions for controlling digital input/output pins.
- Timer Driver: Offers functions for timer operations.
- Interrupt Driver: Handles external interrupts.

### ECUAL Layer

The ECUAL (Embedded Controller Abstraction Layer) layer includes the following drivers:

- Button Driver: Handles button inputs and provides functions to detect button presses.
- LED Driver: Controls the LEDs and provides functions for LED operations.

### Application Layer

The Application layer includes a collection of conditions and logic required for the traffic light control system. It utilizes the functionality provided by the ECUAL drivers.

### Main Layer

The Main layer consists of the main application code. It orchestrates the flow of the program and interfaces with the Application layer.

## Contributing

If you would like to contribute to this project, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Implement your changes and test thoroughly.
4. Commit your changes and push the branch to your forked repository.
5. Submit a pull request, detailing the changes made and any additional information.
