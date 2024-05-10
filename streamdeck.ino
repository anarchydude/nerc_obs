// ArduinoDECK by S-Config v0.1
// https://www.s-config.com/arduniodeck/ for more information on this.
// This is a super-simple input program where we attempt to show people how to map buttons as keys on a keyboard
// so instead of paying $200 for an Elgato StreamDeck they can instead make their own array of buttons to use in OBS
// This tutorial uses F13 - F24 however you can map it to practically anything you want.

// We must declare a library that is within the core Arduino IDE to activate the keyboard USB function on our Arduino
#include <Keyboard.h>

void setup() {
  // This is the setup part. This only runs once the moment your Arduino boots up.
  // We're going to define the digital pins and we will also be using an also add a pullup value
  // so we can use the pullup resistor in the chip and not have to add any additional parts
  // to our project.
  
pinMode(2,INPUT_PULLUP);
pinMode(3,INPUT_PULLUP);
pinMode(4,INPUT_PULLUP);
pinMode(5,INPUT_PULLUP);
pinMode(6,INPUT_PULLUP);
pinMode(7,INPUT_PULLUP);
pinMode(8,INPUT_PULLUP);
pinMode(9,INPUT_PULLUP);
pinMode(10,INPUT_PULLUP);
pinMode(14,INPUT_PULLUP);
pinMode(15,INPUT_PULLUP);
pinMode(16,INPUT_PULLUP);
}

//You may wish to uncomment the serial connection if you want to see what your Arduino is doing.
//The Serial connection is typically for debugging purposes.

//Serial.begin(9600);

void loop() {
  // put your main code here, to run repeatedly:
Keyboard.begin();
//We start the Keyboard IO. This is done in the loop instead of setup so that it does not accidently take
//control of your PC and lead to a world of problems.

if (digitalRead(2) == 0) // If the button is pressed digital pin will read 0 indicating it has been grounded.
 {
     Keyboard.press(KEY_F13); //If statement is true it will hold down the F13 key 
     //delay(100); // I've commenteded out delay because I didn't notice any bounce or multiple key presses.
     
 }
     else if (digitalRead(2) == 1) { //If the button is not pressed it will indicate 1 for high.
      Keyboard.release(KEY_F13); //Since we are in a high state it will release F13 
      }
      // this code loops a lot and we probably could optimize this way better. But for simplicity.
      // I just repeated the same steps for all 12 keys.

//begin F14 mapping.
if (digitalRead(3) == 0){
        Keyboard.press(KEY_F14);
     }
     else if (digitalRead(3) == 1){
        Keyboard.release(KEY_F14);
     }     

//begin F15 mapping.
if (digitalRead(4) == 0){
        Keyboard.press(KEY_F15);
     }
     else if (digitalRead(4) == 1){
        Keyboard.release(KEY_F15);
     }  

//begin F16 mapping.
if (digitalRead(5) == 0){
        Keyboard.press(KEY_F16);
     }
     else if (digitalRead(5) == 1){
        Keyboard.release(KEY_F16);
     }  

//begin F17 mapping.
if (digitalRead(6) == 0)
 {
     Keyboard.press(KEY_F17);
 }
     else if (digitalRead(6) == 1) {
      Keyboard.release(KEY_F17);
      }


//begin F18 mapping.
if (digitalRead(7) == 0){
        Keyboard.press(KEY_F18);
     }
     else if (digitalRead(7) == 1){
        Keyboard.release(KEY_F18);
     }     


//begin F19 mapping.
if (digitalRead(8) == 0){
        Keyboard.press(KEY_F19);
     }
     else if (digitalRead(8) == 1){
        Keyboard.release(KEY_F19);
     }  

//begin F20 mapping.
if (digitalRead(9) == 0){
        Keyboard.press(KEY_F20);
     }
     else if (digitalRead(9) == 1){
        Keyboard.release(KEY_F20);
     }  

//begin F21 mapping.
if (digitalRead(10) == 0)
 {
     Keyboard.press(KEY_F21);
 }
     else if (digitalRead(10) == 1) {
      Keyboard.release(KEY_F21);
      }

//begin F22 mapping.      
if (digitalRead(14) == 0){
        Keyboard.press(KEY_F22);
     }
     else if (digitalRead(14) == 1){
        Keyboard.release(KEY_F22);
     }     

//begin F23 mapping.
if (digitalRead(15) == 0){
        Keyboard.press(KEY_F23);
     }
     else if (digitalRead(15) == 1){
        Keyboard.release(KEY_F23);
     }  

//begin F24 mapping.
if (digitalRead(16) == 0){
        Keyboard.press(KEY_F24);
     }
     else if (digitalRead(16) == 1){
        Keyboard.release(KEY_F24);
     }  

//We've come to the end of our loop and thus we turn off the keyboard so that it does not completly take over our system.

Keyboard.end(); 
}

// The loop is now closed and that's what server said.
// +++END OF LINE
