#ifndef IO_H
#define IO_H
//#include "globals.h"
#include <assert.h>

namespace typotron{

typedef volatile byte* matrix_t;

void portSetup()
{
  //0 - input, 1 - output

  DDRD &= 0b00000011; 
  DDRB &= 0b11111100; //zero the inputs (B0,B1)
  DDRB |= 0b00111100; //one the outputs (B2-B5)
  DDRC &= 0b11001111;
  DDRC |= 0b00001111;

  /*
  *
  *  PINOUT:
  * 
  *   0   D0  RX            An0   C0   --out4
  *   1   D1  TX            An1   C1   --out5
  *   2   D2  -in0          An2   C2   --.
  *   3   D3  -in1          An3   C3   --out7
  *   4   D4  -in2          An4   C4   -inCLK
  *   5   D5  -in3          An5   C5   -inRST
  *   6   D6  -in4          An6   C6   /ADC ONLY/
  *   7   D7  -in5          An7   C7   /ADC ONLY/
  * 
  *   8   B0  -in6
  *   9   B1  -in7
  *   10  B2  --out0
  *   11  B3  --out1
  *   12  B4  --out2
  *   13  B5  --out3
  *       B6  /RESET/
  *       B7  /CLOCK/
  */
}


inline bool resetState()  //Reset on reset high
{
  return (PINC & 0b00100000) >> 5;
}

inline bool clockState() //Change on clock low
{
  return (PINC & 0b00010000) >> 4;
}


void readToMatrix(matrix_t matrix)
{
  while(!resetState()){};   // wait for reset high;
 
  for(byte i=0;i<8;++i)
  {
    delayMicroseconds(800); // wait for the middle of the pulse
    matrix[i] = (PIND & 0b11111100) >> 2 | (PINB & 0b000000011) << 6;  // read state  0b543210TR -> 0b0054321     0bUUUUUU87 -> 0b87000000
    while(clockState());    // wait for clock low
  }
}

void writeFromMatrix(matrix_t matrix)
{
  while(!resetState()){}; // wait for reset high

  for(byte i=0;i<7;i++)
  {
    PORTB = ((matrix[i] & 0b00001111) << 2) | (PORTB & 0b11000011);
    PORTC = ((matrix[i] & 0b11110000) >> 4) | (PORTC & 0b11110000);
    while(clockState()){};
    while(!clockState()){}; // wait for rising clock edge
  }
  
  while(!resetState()){}; // wait for reset high
  
  PORTB &= 0b11000011; // zero all the outputs
  PORTC &= 0b11110000; 
}

} //namespace
#endif
