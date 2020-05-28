#ifndef CODER_H
#define CODER_H

#include "io.h"


namespace typotron{



byte matrixToKey(matrix_t matrix,bool* key_pressed_flag)
{
  /*
   * ENCODING:
   * key = 0b00 000  000
   *         || |    |
   *         CS byte bit  
  */
  bool shift = false;
  bool code = false;
  byte key = 000;
  byte zeros = 0;
  for(byte i=0;i<8;i++)
  { 
    byte matrix_byte = matrix[i];
    if(matrix_byte == 0) 
    {
      ++zeros;
      continue;
    }
    for(byte j=0;j<8;++j)
    {
       if ((matrix_byte >> j)&1)
       {
        if(i==1 && j==4)
        {
          code = true;
          continue;
        }
        if(i==2 && j==4)
        {
          shift = true;
          continue;
        }
        key = (i << 3) | j;
       }
    }
  }
  if(shift) key |= 0b01000000;
  if(code)  key |= 0b10000000;
  *key_pressed_flag = (zeros < 8); 
  return key;
}

void keyToMatrix(byte key, matrix_t matrix)
{
  /*
   * ENCODING:
   * key = 0b00 000  000
   *         || |    |
   *         CS byte bit  
  */
  bool shift = (key >> 6) & 1;
  bool code =  (key >> 7) & 1;
  key &= 0b00111111;
 
  for(byte i=0;i<8;++i)
  {
    if((key & 0b00111000) >> 3 == i) matrix[i] = (1 << (key & 0b00000111));
    else matrix[i] = 0;
  }
  if(shift) matrix[2] |= 0b00010000; //SHIFT = 024
  if(code)  matrix[1] |= 0b00010000; //CODE = 014
}


}//namespace
#endif
