# GPIO_basics
Arduino library for basic GPIO devices

Buttons:

The buttons.h library defines two classes: pullupButton and pullDownButton, as well as functions to read various types of presses. For the pullup button, the button should bridge an arduino GPIO pin and ground. For the pulldown button, the pin should be connected to a large resistor going to ground, as well as to the button seperating it from a voltage source(such as the 5V pin). The resistor is not strictly necessary, but is advised to prevent blowing out the pin or producing erratic readings. 

Declare a pullup button as follows: pullupButton buttonName; When the button is initialized, the appropriate pin is set to an input pullup. For the pull down button use pullDownButton buttonName;
Both classes share the same functions. 

Functions:
.begin(buttonPin, debounceDelay); //initializes a button on GPIO pin "buttonPin" with debounce delay "debounceDelay" in ms

.begin(buttonPin); //Initializes a button on GPIO pin "buttonPin" with a default debounce delay of 500 µs

.end(); //De-initializes the button by setting the pin to an output.

.changeDebounceDelay(newDebounce); // Changes the debounce delay to "newDebounce" µs.

.releaseRead(); // Once the button has been continuously depressed for the debounce time, returns true as soon as the button is released. Otherwise returns false.

.singlePressRead(); // Once the button has been continuously depressed for the debounce time, immediately returns true. Otherwise returns false.

.pressHoldRead(spacing); //Takes an unsigned long "spacing". Once the button has been continuously depressed for the debounce time, returns an unsigned long starting at 1, and incrementing every "spacing" ms until released. Otherwise returns 0.

.multiClickRead(spacing); // Takes an unsigned long "spacing" Registers button presses as consinous depressions longer than the debounce time. Returns the current cound of how many presses have occured within "spacing" ms of each other. Once more than "spacing" ms have passed from the last button press, the count resets to 0.








LED:
.begin(ledPin); // initializes an led on gpio pin "ledPin", sets the pin to output, and the led state to low. 

.on(); //Turns on the led.

.off(); //Turns off the led.

.toggle(); // Turns the led off if it is currently on and vice-versa.

.state; //returns true if the led is currently on and false if it is off.

.blink(unsigned long spacing); // Toggles the led state every "spacing" ms.

.blink(unsigned long timeOn, unsigned long timeOff); //Blinks the LED on for "timeOn" ms and then off for "timeOff" ms.

.pwm(byte val); //Pulses the led to simulate an analog value between 0 and 255. Only use with pwm pins for the specific board. 

.breathe(unsigned long breatheRate); //Only use on pwm pins. Every "breatheRate" ms either increases or decreases the brightness by 1 in cycles between 0 and 255.

.pulse(bool pulseStart, unsigned long pulseDuration); //If "pulseStart" is true, then changes it to false and turns the led on for "pulseDuration" ms. Example use:
/* if(condition){
      pulseStart = true;
   }
   led.pulse(pulseStart, pulseDuration);
*/

.pattern(bool patternStart, unsigned int ptrn[]); //Turns the led on and off in accordance with ptrn, which is an array of unsigned ints corresponding to ms 
                                                  //durations. The led will toggle and hold state for each duration. Will turn off on encountering the terminating 
                                                  //value, which should always be 0. "patternStart" works the same as "pulseStart" in the preceding function.
    


Note that the use of other led functions can interfere with pulse and pattern if called before the pulse or pattern has completed. To that end, .pulseRunning and .patternRunning can be used as a check, returning true or false based on whether those functions are currently running. 














