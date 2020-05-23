#ifndef IO_H
#define IO_H
//#include "globals.h"

DDRD |= B11111100;
DDRB |= B00000011;
DDRB &= B11000011;
DDRC &= B11000000; 

namespace typotron{
inline bool clockState()
{
  return (PORTC & 0b00010000) >> 4;
}

inline bool resetState()
{
  return (PORTC & 0b00100000) >> 5;
}


void readToMatrix(byte* matrix)
{
  /* TC4017BP decade counter
   * reset  ---______----
   * clock: -_-_-_-_-_-_-
   * pin:   0000112230000
   */
 while(!resetState()){};
 while(resetState()){}; //wait for falling reset edge
 
  for(byte i=0;i<8;i++)
  {
    matrix[i] = (PINC & B00001111) | ((PINB & B00111100) << 2); //read state
    while(!clockState()){};
    while(clockState()){}; //wait for falling clock edge
  }
}

void writeFromMatrix(byte* matrix)
{
 while(!resetState()){}; //wait for reset high
 PORTD = ((matrix[0] & B00111111) << 2) | (PORTD & B00000011);
 while(resetState()){};  //keep 0 while reset high
 while(clockState()){};
 while(!clockState()){}; //wait for rising clock edge
 
  for(byte i=1;i<8;i++)
  {
    PORTD = ((matrix[i] & B00111111) << 2) | (PORTD & B00000011);
    while(clockState()){};
    while(!clockState()){}; //wait for rising clock edge
  }
}

} //namespace
#endif
