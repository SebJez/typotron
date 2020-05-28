#ifndef IO_H
#define IO_H
//#include "globals.h"
#include <assert.h>

namespace typotron{

typedef volatile byte* matrix_t;
inline bool resetState()  //Reset on reset high
{
  return (PINC & 0b00010000) >> 4;
}

inline bool clockState() //Change on clock low
{
  return (PINC & 0b00100000) >> 5;
}


void readToMatrix(matrix_t matrix)
{
  while(!resetState()){};   // wait for reset high;
 
  for(byte i=0;i<8;++i)
  {
    delayMicroseconds(800); // wait for the middle of the pulse
    matrix[i] = (PINC & 0b00001111) | ((PINB & 0b00111100) << 2); // read state
    while(clockState());    // wait for clock low
  }
}

void writeFromMatrix(matrix_t matrix)
{
  while(!resetState()){}; // wait for reset high

  for(byte i=0;i<7;i++)
  {
    PORTD = ((matrix[i] & 0b00111111) << 2) | (PORTD & 0b00000011);
    PORTB = ((matrix[i] & 0b11000000) >> 6) | (PORTB & 0b11111100);
    while(clockState()){};
    while(!clockState()){}; // wait for rising clock edge
  }
  PORTD = ((matrix[7] & 0b00111111) << 2) | (PORTD & 0b00000011);
  PORTB = ((matrix[7] & 0b11000000) >> 6) | (PORTB & 0b11111100);
  
  while(!resetState()){}; // wait for reset high
  
  PORTD |= 0b11000000;
  PORTB |= 0b00111111; // zero all the outputs
}

} //namespace
#endif
