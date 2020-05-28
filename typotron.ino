#define ENCODING_UNIT_TEST


#ifdef ENCODING_UNIT_TEST
#include "encode_decode_unit_test.h"
#else

//#include "globals.h"

#include "io.h"
#include "coder.h"
using namespace typotron;

volatile byte inputMatrix[8];
void setup() {
  Serial.begin(115200);
  DDRD |= 0b11111100;
  DDRB |= 0b00000011;
  DDRB &= 0b11000011;
  DDRC &= 0b11000000; 
  
}

void loop() 
{
  readToMatrix(inputMatrix);

  bool any_key;
  byte key = matrixToKey(inputMatrix,&any_key);

  if(any_key)Serial.println(String(key,8));
  delay(300);


}

#endif
