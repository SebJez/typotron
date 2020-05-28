#ifndef ENCODE_DECODE_UNIT_TEST_H
#define ENCODE_DECODE_UNIT_TEST_H

#include "coder.h"
using namespace typotron;

volatile byte matrix[8];

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    for (byte i = 0; i < 255; ++i)
    {
        keyToMatrix(i,matrix);
        bool any_key_pressed;
        byte j = matrixToKey(matrix,&any_key_pressed);
        if(j != i) Serial.println(String(i,8)+">"+String(j,8));
    }
    Serial.println("Finished");

    delay(10000);
    
}


#endif