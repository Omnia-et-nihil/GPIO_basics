# GPIO_basics
Arduino library for basic GPIO devices

Buttons:

The buttons.h library defines a class pullupButton, and functions to read various types of presses. For the hardware, the button should bridge an arduino GPIO pin and ground. 
Declare a pullup button as follows: pullupButton buttonName(); When the button is initialized, the appropriate pin is set to an input pullup.

Functions:
.begin(buttonPin, debounceDelay); //initializes a button on GPIO pin "buttonPin" with debounce delay "debounceDelay" in ms

.begin(buttonPin); //Initializes a button on GPIO pin "buttonPin" with a default debounce delay of 50 ms

.end(); //De-initializes the button by setting the pin to an output.

.changeDebounceDelay(newDebounce); // Changes the debounce delay to newDebounce in ms.

.releaseRead(); // Once the button has been continuously depressed for the debounce time, returns true as soon as the button is released. Otherwise returns false.

.singlePressRead(); // Once the button has been continuously depressed for the debounce time, immediately returns true. Otherwise returns false.

.pressHoldRead(spacing); //Takes an unsigned long "spacing". Once the button has been continuously depressed for the debounce time, returns an unsigned long starting at 1, and incrementing every "spacing" ms until released. Otherwise returns 0.

.multiClickRead(spacing); // Takes an unsigned long "spacing" Registers button presses as consinous depressions longer than the debounce time. Returns the current cound of how many presses have occured within "spacing" ms of each other. 
