/*
File:   MousieWiSwitch.ino
Author: Tip Partridge
Origin: 29-May-2022
Target: Spark Fun Pro Micro (ATMEGA32U4) Set board as Leonardo
Description: From Mousie.ino. Become a mouse and move back and forth one step each 5 minutes.
             Intended to defeat login timeout.  Button toggles on/off.
             LED cycles dim-brite-dim with 4 progressive speeds,1, 2, 4, 8, as activity indicator.

Revisions:
        30-May-2022 (TEP) v0.1 Origin
 */
 #include <Mouse.h>
 #define LEDpin 17            // use pro micro RX LED on D17. Note: on/off reversed
 #define BUTTONpin 10         // On/Off button. SOldered between pins 10 and 14.
 #define BUTTONpwr 14         // LOW output for button
 bool onOff;                  // on/off flag
 bool turnOnAtTop = true;     // flag to turn on only at top of loop
 bool buttonPressed = false;  // flag for only one toggle per press
 int Dim = 5;                 // 5 = 0.5%
 int Brite = 100;             // 100 = 10%
 #define dfltCycle 4000       // 4 sec brightness up/down
 int Cycle;
 #define dfltStage 40         // 40 gives 5 min.
 int Stage;                   // Number of up/down at each brightness
 unsigned long len;

// setup //////////////////////////////

void setup() {
  pinMode(LEDpin, OUTPUT);
  pinMode(BUTTONpin, INPUT_PULLUP);
  pinMode(BUTTONpwr, OUTPUT);
  digitalWrite(BUTTONpwr, LOW);
}

// loop //////////////////////////////

void loop()
{
int ii, jj;
  checkButton();
  onOff = turnOnAtTop;
// Speed 1
  Cycle = dfltCycle;
  Stage = dfltStage;
  if (onOff)
    {
    for (jj=0; jj<Stage; jj++)
      if (onOff)
        {
        for (ii=Dim; ii<=Brite; ii++)
          Blip( ii, Cycle/2/(Brite-Dim+1));
        for (ii=Brite; ii>Dim; ii--)
          Blip( ii, Cycle/2/(Brite-Dim+1));
        }
    }
// Speed 2
  Cycle /= 2;
  Stage /= 2;
  if (onOff)
    {
    for (jj=0; jj<Stage; jj++)
      if (onOff)
        {
        for (ii=Dim; ii<=Brite; ii++)
          Blip( ii, Cycle/2/(Brite-Dim+1));
        for (ii=Brite; ii>Dim; ii--)
          Blip( ii, Cycle/2/(Brite-Dim+1));
        }
    }
// Speed 3
  Cycle /= 2;
  Stage /= 2;
  if (onOff)
    {
    for (jj=0; jj<Stage; jj++)
      if (onOff)
        {
        for (ii=Dim; ii<=Brite; ii++)
          Blip( ii, Cycle/2/(Brite-Dim+1));
        for (ii=Brite; ii>Dim; ii--)
          Blip( ii, Cycle/2/(Brite-Dim+1));
        }
    }
// Speed 4
  Cycle /= 2;
  Stage /= 2;
  if (onOff)
    {
    for (jj=0; jj<Stage; jj++)
      if (onOff)
        {
        for (ii=Dim; ii<=Brite; ii++)
          Blip( ii, Cycle/2/(Brite-Dim+1));
        for (ii=Brite; ii>Dim; ii--)
          Blip( ii, Cycle/2/(Brite-Dim+1));
        }
    }
// Wiggle mouse
  if (onOff) Wiggle();
}

// Wiggle //////////////////////////////

void Wiggle()
  {
// Move mouse back/forth one pixel.
  Mouse.begin();
  Mouse.move(1,0,0);
  Mouse.move(-1,0,0);
  Mouse.end();
  delay(1000);
  }

// Blip //////////////////////////////

void Blip(int level, unsigned long duration)
  {
// turn on LED at level (0..1000) for duration ms.
  unsigned long tt;
  unsigned long Ton, Toff;
  Ton = 1 * level;
  Toff = 1000 - Ton;
  for (tt = 0; tt < duration; tt++)
    {
    digitalWrite( LEDpin, 0);
    delayMicroseconds(Ton);
    digitalWrite( LEDpin, 1);
    delayMicroseconds(Toff);
    }
  checkButton();
  }

// checkButton ////////////////////////

void checkButton()
// Check for button press. Toggle on/off.
  {
  if (digitalRead(BUTTONpin)) buttonPressed = false;
  if (!digitalRead(BUTTONpin) && !buttonPressed)
    {
    buttonPressed = true;
    turnOnAtTop = !turnOnAtTop;
    if (!turnOnAtTop)
      onOff = false;
    digitalWrite(LEDpin, !turnOnAtTop);
    delay(200);
    }
  }

// Enf of program /////////////////////
