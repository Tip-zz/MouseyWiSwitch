Project MouseyWiSwitch
05-June-2022  TEP

No warranty made or implied. Free for all use. No attribution required.

This project appears as a mouse to a computer and moves (wiggles) the cursor one pixel left and right every 5 minutes.  Its function is to keep an activity timer busy because it would otherwise blank the screen and require a password login to resume every 7 minutes.

This version runs on an Arduino style Pro Micro microcontroller board. It should work on any board with HID support (USB controller built in to the microcontroller chip).  The Pro Micro doesn't have a dedicated onboard LED, so I use the TX LED as the activity enunciator.

While running an LED pulsates from dim to bright, with the pulse rate increasing in 4 discrete steps to indicate that the device is running and how close it is to wiggling.

There is a button to toggle the operation on or off. To keep the package small I used a tiny "tactile" pushbutton and soldered it between two digital IO pins. One is defined as a digital input with a built-in pull-up and the other is defined as an output and programmed to LOW so the input will be pulled LOW when the button is pressed. I used an E-Switch TL1015AF-160QG pushbutton that I purchased from Mouser. 

The loop timing is determined by the LED pulse rate as opposed to an explicit interval, so changing the timing requires either some math (I used a spreadsheet) or trial and error.

The code is far from optimized and is a bit rambling, but there was plenty of flash available so didn't feel any need to make it efficient or tight.

The case is 3D printed on a Prusa filament printer. It's held together with two #2 x 3/8" sheet metal screws. I used two light pipes to bring out the LEDs, had to cut to length and polish, but this wouldn't be necessary except to satisfy OCD. I used a short USB cable to connect it to the computer to minimize strain on the computer's USB port.

