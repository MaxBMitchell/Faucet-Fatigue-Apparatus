# Background (PAST)

A set of faucets were under consideration for a handwash station that was being developed for use in various low-resource settings.  Each faucet utilized a 
time delay design.  A time delay faucet is a valve which, once activated, dispenses water for a brief period of time before automatically shutting off.  
This design is commonly found in public restrooms.

As part of the selection process the reliability of each faucet was observed during the course of an accelerated fatigue test.  The files in this repository 
document the design of the test apparatus which was used to conduct the test. 

An facuet example is shown below:

![Image of a Faucet](https://github.com/MaxBMitchell/Faucet-Fatigue-Apparatus/blob/master/Images/example_1.jpg)

### The folowing goals were used to guide the apparatus design: (PAST)

* Accomodate at least four test samples.
* Supply water in a controlled and consistent manner which mimics municipal water supply.
* Provide means for testing at various pressures up to a maximum of 100 PSI.
* Supply water with turbidity of approximately 10 NTU.
* Operate constantly in an attempt to maximize the usage of each sample.
* Recycle water to minimize cost and waste.
* Provide a means for mounting the faucets in a manner similar to the handwash station.
* Record the number of instances each tap was activated.

### Theory of Operation (PRESENT)

The apparatus executes sequence of two cycles which are repeated.  During the first cycle air pressure is used to transfer water from the Pressure Vessel to the faucets.  Instead of a human hand, pnuematic Actuators are used to asynchronously activate the faucets.  Water exiting the faucets is accumulated in the Collection Tank.  

The second cycle begins when the water level in the Pressure Vessel is low.  The pump will then transfer water from the collection tank and back into the Pressure Vessel.  When the Pressure Vessel is full the second cycle is complete and first cycle will begin.

* Pressure Vessel - supplies pressurized water to each faucet.
* Collection Tank - accumulates water which has been dispensed from faucets.
* Actuators - pneumatic cylinders used to activate the faucets.
* Pump - this is used to transfer water from the collection tank back into the pressure vessel.

