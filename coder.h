#ifndef CODER_H
#define CODER_H

#define SHIFT 000;
#define CODE 001;

namespace typotron{

//const char asciiToKeys;
//const char keysToAscii;

//struct keystruct{byte key, byte modifiers};
//typedef struct keystruct keys;

byte matrixToKey(byte* matrix)
{
  for(byte i=0;i<8;i++)
  {
    byte sig = ~matrix[i];
    for(byte j=0;j<8;j++)
    {
      if(sig&1)
      {
        return (i << 3) | j;
      }
      sig = sig >> 1;
    }
  }
}



}//namespace
#endif
