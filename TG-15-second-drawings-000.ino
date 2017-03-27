///////////////////////////////////////////////////////////////////////////////
// Circuit Playground 15 Second Drawing Timer
//
// Author: Tinker Girl, with thanks to Carter Nelson
// MIT License (https://opensource.org/licenses/MIT)

#include <Adafruit_CircuitPlayground.h>

// set pin numbers:
  const int buttonPin = 3;     // the number of the pushbutton pin
// variables will change:
  int buttonState = 0;         // variable for reading the pushbutton status
// we light one pixel at a time, this is our counter
  uint8_t pixeln = 0;

//  Divide the time the lights are on by this number, so that it makes it easier/quicker to test the program
int drawingTimer = 15*1000; 
//  Duration of alert noises
int alertDuration = 100*1.5;

///////////////////////////////////////////////////////////////////////////////
void setup() {
  // Initialize the Circuit Playground
  CircuitPlayground.begin();

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  }

///////////////////////////////////////////////////////////////////////////////
void loop() {
  // read the state of the pushbutton value:
  buttonState = 0;
  
  //  Cycle through color wheel - over the course of the entire drawing time
  while (pixeln <11)
    { 
    CircuitPlayground.setPixelColor(pixeln++, CircuitPlayground.colorWheel(25* pixeln)); 
    delay(drawingTimer/11);
    }

  //  Reset the pixel counter
  pixeln = 0;
  //  Turn off all the pixels
  CircuitPlayground.clearPixels();

  // Turn OFF all the NeoPixels
  CircuitPlayground.clearPixels();

  //  Speech
  //  speakerTone();
  //  Play tones once the lights go out
  musicalTone();

  // Wait for button press to reset timer
  while (!CircuitPlayground.leftButton()   && 
         !CircuitPlayground.rightButton() && 
         buttonState == LOW)  {
    // Do nothing, just waiting for a button press...
    // read the state of the pushbutton value:
    buttonState = digitalRead(3);
  }
}

//  Alerts
void musicalTone()
  {
  CircuitPlayground.playTone(300, alertDuration);
  CircuitPlayground.playTone(100, alertDuration);
  CircuitPlayground.playTone(700, alertDuration);
  CircuitPlayground.playTone(100, alertDuration);
  CircuitPlayground.playTone(1100, alertDuration);
  }


