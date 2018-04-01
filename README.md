# STM32F4_FreeRTOS_Demo

In this project, there are two tasks running scheduled by FreeRTOS scheduler, Task 1 prints something via serial port, Task 2 toggles the LEDs on the EVAL board.
Task 1 occurs every 1000ms, and Task2 every 2000ms.

The code has been tested successfully on an STM32F4 Discovery board.The Hardware used is STM32F411E-DISCO Eval board. The controller on board is STM32F411VETx.
The compiler used is arm-gcc, the IDE used is SW4STM32 from OpenSTM32. The code has been compiled and flashed from Linux (ubuntu 16.04) machine.
