# Thomson Halloween DJ Controller

Arduino sketch to flash LEDS in different patterns based on button presses.  
LEDS can be hot-glued into a toy DJ controller to create light effects.  This is
a quick-and-fast project intended for a single use on halloween night, so
optimizations like interrupt-driven buttons and power consumption have been ignored.

## Hardware

* 1 x Arduino.  Using a Duemilanove, but any one will work.
* 8 x blue LEDS
* 8 x 115 Ohm resistors
* 2 x arcade-style momentary push button switches

Connect the annode of each LED to a different Arduino digital pin via 115 Ohm
resistor, and connect all cathodes to GND.  Connect each button to a digital pin
and to GND (buttons are active-low).  Provide power using a portable USB battery
pack or similar.

## Software (Sketch)

Match the sketch to your hardware:

* set `PIN_RANDOM` and `PIN_RING` to the digital pins connected to the buttons
* list each LED pin in `pin[]` and set `count` to the number of LEDS in use

Optionally, tweak the behaviour:

* Adjust the delay in `randomDisplay()` to show the random pattern for more/less
  time.
* Adjust the delay in `loopDisplay()` to make the animation faster or slower.
* Adjust the actions for the different button-press combinations in `loop()`.

For longer-term or more ambitions projects, consider:

* Using the [Buttons library ](https://playground.arduino.cc/Code/Buttons) to
  allow more button combinations like press-and-hold.  This is a nice little
  library but needs to be hacked to use active-low buttons.  See `buttons.patch`.

* Sleeping while no buttons are pressed to save power.
