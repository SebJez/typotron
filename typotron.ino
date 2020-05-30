//#define ENCODING_UNIT_TEST //uncomment to compile unit test instead of the main program


#ifdef ENCODING_UNIT_TEST
#include "encode_decode_unit_test.h"
#else

//#include "globals.h"

#include "io.h"
#include "coder.h"
#include "key_lut_literal.h"
//#include "key_lut_us.h"
using namespace typotron;


void setup() 
{
  Serial.begin(115200);
  portSetup();
}

volatile byte inputMatrix[8];
bool any_key;
byte prev_key;
bool prev_any_key = false;

void loop() 
{
  readToMatrix(inputMatrix);
  writeFromMatrix(inputMatrix);

  //for(byte i=0;i<8;++i) Serial.println(String(inputMatrix[i],2));
  //Serial.println("\n");
  byte key = matrixToKey(inputMatrix,&any_key);

  if(any_key) 
  {
    if(!prev_any_key || prev_key != key) 
    {
      Serial.println(keyToAsciiLiteral(key));
    }
  }

  prev_key = key;
  prev_any_key = any_key;

}

#endif
