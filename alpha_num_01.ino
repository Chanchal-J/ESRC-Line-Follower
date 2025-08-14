#define NUM_LED_SEGMENTS 17   // Do NOT change this
//////#define NUMBER_OF_SYMBOLS  36 // (10 + 26) 0-9 numbers; and 26 Alphabets

int picoPinNoGPIO[NUM_LED_SEGMENTS] = { 2,3,4,5,  6,7,8,9,   10,11,12,13,   14,15,16,17,  18 };

////// Set up which segments have to be turned on or off for each letter or symbol
////// you can identify the neccesary pattern using the data sheet map
////// int FONT[NUMBER_OF_SYMBOLS][NUM_LED_SEGMENTS] =;

void setup()
{   

//For loop to declare all pins as an output
 for (int i = 0; i < NUM_LED_SEGMENTS; i++) {
   pinMode(picoPinNoGPIO[i], OUTPUT);
 }
}

void loop()
{
  for (int i = 0; i < NUM_LED_SEGMENTS; i++) 
  {
    //digitalWrite( picoPinNoGPIO[i], LOW); // Common Anode, so inverted logic !
    delay(250);
    digitalWrite( picoPinNoGPIO[i], HIGH); // After running this code once, swap HIGH and LOW to see the effect
    delay(100);

  }
  // 1) First Upload and Run this code, as it is, try to understand : What happens & Why !?!?!?!
  //    Whenever you will press the RUN button, the code will run again, without unplugging/ reconnecting the USB
  //
  // 2) Then uncomment the line number 23 that is  digitalWrite( picoPinNoGPIO[i], LOW);
  //    and reUpload and Run
  //    Whenever you will press the RUN button, the code will run again, without unplugging/ reconnecting the USB
  //
  // 3) Then in Line 23 and 25 swap LOW and HIGH ss the change
  //    Whenever you will press the RUN button, the code will run again, without unplugging/ reconnecting the USB
  // 
}
