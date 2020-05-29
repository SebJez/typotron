//#define ENCODING_UNIT_TEST //uncomment to compile unit test instead of the main program


#ifdef ENCODING_UNIT_TEST
#include "encode_decode_unit_test.h"
#else

//#include "globals.h"

#include "io.h"
#include "coder.h"
#include "key_lut_literal.h"
using namespace typotron;

volatile byte inputMatrix[8];
void setup() {
  Serial.begin(115200);
  DDRD |= 0b11111100;
  DDRB |= 0b00000011;
  DDRB &= 0b11000011;
  DDRC &= 0b11000000; 
  
}

  bool any_key;
  byte prev_key;
  bool prev_any_key = false;

void loop() 
{
  readToMatrix(inputMatrix);



  byte key = matrixToKey(inputMatrix,&any_key);

  if(any_key) 
  {
    if(!prev_any_key || prev_key != key) Serial.print(keyToAsciiLiteral(key));
  }

  prev_key = key;
  prev_any_key = any_key;


}

#endif
