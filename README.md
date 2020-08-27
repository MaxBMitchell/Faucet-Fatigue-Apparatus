# Background

A set of faucets were under consideration for a handwash station that was being developed for use in various low-resource settings.  Each faucet utilized a 
time delay design.  A time delay faucet is a valve which, once activated, dispenses water for a brief period of time before automatically shutting off.  This design is commonly found in public restrooms.

As part of the selection process the reliability of each faucet was observed during the course of an accelerated fatigue test.  The files in this repository document the design of the test apparatus which was used to conduct the test. 

An facuet example is shown below:

![Image of a Faucet](https://github.com/MaxBMitchell/Faucet-Fatigue-Apparatus/blob/master/Images/example_1.jpg)

### The folowing goals were used to guide the apparatus design:

* Accomodate at least four test samples.
* Supply water in a controlled and consistent manner which mimics municipal water supply.
* Provide means for testing at various pressures up to a maximum of 100 PSI.
* Supply water with turbidity of approximately 10 NTU.
* Operate constantly with minimal maintenance in an attempt to maximize the usage of each sample.
* Recycle water to minimize cost and waste.
* Provide a means for mounting the faucets in a manner similar to the handwash station.
* Record the number of instances in which each tap was activated.



# Device Explanation 

### Description of Operation

The apparatus repeatedly executes sequence of two cycles (test and refill).  During the test cycle air pressure is used to transfer water from the **Pressure Vessel** to the faucets.  Instead of a human hand, pnuematic **Actuators** are used to asynchronously activate each faucet.  Water exiting the faucets is accumulated in the **Collection Tank**.  

The refill cycle begins when the water level in the **Pressure Vessel** is low.  During the refill cycle the **Pump** transfers water from the **Collection Tank** and back into the **Pressure Vessel**.  When the **Pressure Vessel** is full the refill cycle is complete and test cycle will begin.

### Main Components

* **Pressure Vessel** - A 75L stainless steel tank capable of being pressurized.  This component supplies pressurized water to each faucet.
* **Collection Tank** - A 200L HDPE tank used to support the Actuators, faucets, and accumulate water dispensed from faucets.
* **Actuators** - Pneumatic cylinder actuators used to activate the faucets.
* **Pump** - A positive displacement rotarty vane pump used to transfer water from the Collection Tank back into the Pressure Vessel.  The Pump is powered by a 0.5 horsepower AC inductive motor.
* **Controller** - This component is programmed to controls the valves which are used to direct air and water througout the system. This is accomplished with an Arduino Mega microcontroller.
* **Solenoid Valves** - Various two-way two-position solenoid valves are used to direct air and water flow througout the system.

### Documentation Guide

The following files are schematics and diagrams which explain the operation and construction details of the apparatus.

* System_Overview.png: diagram illustrating how each component is oriented in the system.
* Controller.png: wiring schematic for the Controller.
* Test_Environemnt.png: wiring schematic for the Solenoid Valves, Pump, and other electrical components not located within the Controller.
* Test_Cycle.png: diagram of component functions during the cyle in which the faucets are tested.
* Refill_Cycle.png: diagram of component functions during the cycle in which the Pressure Vessel is refilled.

