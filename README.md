# lab3
Assembling your printed circuit board.

In lecture, you learned about basic electronics and circuits. In this lab, we
will make the PCB you made in the last lab come alive. We will be doing this by
soldering the board - the process of installing and then creating the electrical
connection by applying solderto the joints between the PCB and the components.

Even if you've soldered PCBs before, **please still read the lab instructions**!
There are some small differences between this type of milled board and
commerical PCBs, notably that vias need to be manually connected with wire and
the presence of the large copper planes.

If you need a refresher on basic soldering skills, here are some resources to
guide you:

* http://inst.eecs.berkeley.edu/~ee16a/sp15/Labs/touchscreen/ee16a_touchscreen_lab1.html#task2
* http://robotics.eecs.berkeley.edu/~pister/42x100sp13/Resources/Lab_1_Soldering_PCBs_2.1.pdf
* https://wiki.pierobotics.org/wiki/Soldering

Once you have assembled your circuit board, you will program it in a similar
fashion to what you did in lab1, and then extend its functionality and observe
its increased robustness in comparison to the breadboard.

![Top side of the assembled board](/images/pcb_top.jpg?raw=true)

![Bottom side of the assembled board](/images/pcb_bottom.jpg?raw=true)

## Prerequisites and Materials

* [Jacobs Hall Electronics Training](https://bcourses.berkeley.edu/courses/1353091/pages/electronics-lab-module)
* Multi-meter
* Flush cutter
* Soldering iron
* Solder (lead or lead-free)
* Copper wire (or normal wire as a fallback)
* Through-hole components:
  * 1x 0.1μF (100nF) capacitor
  * 4x 1kΩ resistor
  * 1x switch
  * 3x LEDs (1 red, 1 yellow, 1 green)
  * 2x 15-pin socket headers
* Nucleo L432KC (from lab 1)

## Pre-lab

For pre-lab, set up the environment from [lab1](https://github.com/cs194-126/lab1)
if you haven't already. You will be using it to program your newly assembled
board.

## Procedure

This procedure should take about **1-1.5 hours** total to complete.

### Assembly

1. Take your milled PCB from last week and clean it off to remove all dust.
   If you haven't already, use a multi-meter to perform a connectivity test to
   ensure that you have no discontinuities in your traces.

2. Turn on the soldering iron.

3. Wait for the soldering iron to fully heat up. For Weller soldering irons, the
   green LED on the front panel (if it is present) will stop blinking once the
   soldering iron is fully heated and ready for use.

4. Prepare 4x small pieces of copper wire for use in joining the vias. Vias are
   small holes (normally filled in commercial PCBs) used for connecting traces
   (wires) across the two sides of a PCB.

5. Insert the small copper pieces into the vias (they are circled in red below,
   looking from the top). Solder the piece to one side, flip the board over, and
   then solder it to the other side as well.

   > **Soldering tip**: Because the 'extra' copper in unused regions isn't
   > removed, solder may inadvertently flow onto those large regions, especially
   > if heat is applied for a long time or overly broadly (as solder will flow
   > with the heat). This will cause unintended short circuits on your board!
   >
   > To combat this, minimize the amount of time you apply the soldering iron
   > and be careful to only touch your wire and the ring (and nothing else like
   > neighbouring planes, etc).

  <!---
  TODO: add pictures for this procedure?
  -->

  ![Vias in red](/images/pcb_top_vias.jpg?raw=true)

  > **Note**: You don't need to assemble the other through holes in the same way
  > since they aren't connected to traces on the top.

6. Solder on the components facing upwards from the top side of the board, using
   the diagram below.

   Consult the picture of the fully soldered board at the top of this page to
   reference what your final board should look like.

   ![Components](/images/components.png?raw=true)

  > **Note**: Pay particular attention to the polarity of the LEDs! Note that
  > the flat side (connecting to the negative pin) is facing the bottom of the
  > board.

7. Once you have soldered all the components, use the flush cutter to remove the
   extra lead lengths dangling from the bottom.

8. *(Optional but recommended)* Use the multimeter to test the connectivity
   again to ensure that you have not accidentally created unintended solder
   bridges and shorts.

9. Turn off the soldering iron and clean up your workstation.

### Programming

Clone this repository with the source code and build system, and [build and run](https://github.com/cs194-126/lab1#build--sanity-check)
the code on the Nucleo as described in the first lab.

```
git clone --recursive https://github.com/cs194-126/lab3.git
```

> **Note**: Don't plug in the Nucleo backwards. The micro-USB port should be
> facing to your left. See the picture at the top of this lab document for more
> details.

When you have flashed the code onto the Nucleo, you should

> **Note**: the LEDs turn on when the pin is driven low (since the GPIO is
> connected to the ground side of the LED) and the switch goes to 0 when it is
> pressed (active low).
> Remember to modify your code accordingly.


## Checkoff

**Objective**: A cool-looking assembled PCB that functions!

1. Show a running program which advances by one cycle the cycle of active LEDs
   green → yellow → red → green whenever the pushbutton is pressed.
   In other words, if the green LED is currently on, then pushing the button
   should turn off the green LED and turn on the yellow LED.
   Only one LED should be active at a given time.

2. Imagine that this board is the controller for a traffic light. Obviously, it
   would be very boring for you to sit at the light to manually control the
   lights. Implement logic on the Nucleo which would control the LEDs as an
   automated traffic light with the following on-times:
    * Green - 1.5 s
    * Yellow - 0.3 s
    * Red - 1.5 s

   Pushing the button should cause the traffic light to immediately advance to
   the next state.

   Optional extra reading: [Finite state machines](http://inst.eecs.berkeley.edu/~cs150/sp12/resources/FSM.pdf)
