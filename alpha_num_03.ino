//
// Reference: https://jayconsystems.com/blog/programming-a-16-segment-display-with-arduino
//

#define NUM_LED_SEGMENTS 17   // Do NOT change this

#define NUMBER_OF_SYMBOLS  38 // (10 + 26 + 1 + 1 ) 0-9:numbers; 26 Alphabets; 1 Error Symbol, 1 Blank Space


// As per the circuit diagram :
//                                      A2,A1, F, H,   E, J, M, N,    L,D2,D1,DP,    C,G1, B,G2,   K
int picoPinNoGPIO[NUM_LED_SEGMENTS] = {  2, 3, 4, 5,   6, 7, 8, 9,   10,11,12,13,   14,15,16,17,  18 };
//                                                                   NOTE     DP is not working the actual display

////// Set up which segments have to be turned ON or OFF for each letter or symbol
////// you can identify the neccesary pattern using the font.png mapping file
int fontSymbolBits[NUMBER_OF_SYMBOLS][NUM_LED_SEGMENTS] = { 
//  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K
   { 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1}, // 0
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1}, // 1
   { 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1}, // 2
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 3 DIY: Do It Yourself
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 4 DIY

//  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K   
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 5 DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 6 DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 7 DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 8 DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 9 DIY
   
//  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K

   { 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1}, // A 
   { 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0}, // B 
   { 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1}, // C 
   { 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1}, // D 
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // E DIY

//  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // F DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // G DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // H DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // I DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // J DIY

//  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // K DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // L DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // M DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // N DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // O DIY

//  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // P DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Q DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // R DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // S DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // T DIY


//  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // U DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // V DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // W DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // X DIY
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Y DIY

//  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Z 
   { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // CLEAR ALL
   { 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1}, // ERROR Indicator: A Sigma like symbol!
};
//////////////////////////////////////////////////////////////////////////////
void setup()
{   
//For loop to declare all pins as an output
 for (int i = 0; i < NUM_LED_SEGMENTS; i++) {
   pinMode(picoPinNoGPIO[i], OUTPUT);
 }
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void loop()
{

    displayAlphaNumString("AB CD 12", 1000); 
    //displayAlphaNumString("HBDS", 1000); 

    delay(1000);

}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void displayAlphaNumString(char s[], int inBetweenDelay)
{
    for(int i=0; i< strlen(s); i++)
    {
        displayAlphaNum(s[i]);
        delay(inBetweenDelay);
    }
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void displayAlphaNum(char ch)
{
  int fontArrayRowNumber;

       if(ch >= '0' && ch <= '9')
          fontArrayRowNumber = ch - '0'; // or ch -48 or ch - "ASCII OF ZERO" all are same
  else if(ch >= 'A' && ch <= 'Z')
          fontArrayRowNumber = 10 + (ch - 'A'); // After 0 to 9 there are Alphabets
  else if(ch == ' ')
          fontArrayRowNumber = 10 + 26 + 0; // Index of : BLANK: CLEAR ALL BITS       
       else
          fontArrayRowNumber = 10 + 26 + 1 + 0; // Error Indicator Symbol: if it is NOT 0-9, A-Z or space then error symbol is diaplayed


  for(int pinNoIndex =0; pinNoIndex < NUM_LED_SEGMENTS; pinNoIndex++)
    {
        digitalWrite( picoPinNoGPIO[pinNoIndex], fontSymbolBits[fontArrayRowNumber][pinNoIndex]);
  
    }

}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////