//#include "globals.h"
#include "io.h"
#include "coder.h"
using namespace typotron;

byte inputMatrix[8];
void setup() {
  Serial.begin(9600);
  DDRD |= B11111100;
  DDRB |= B00000011;
  DDRB &= B11000011;
  DDRC &= B11000000; 


}

void loop() {

readToMatrix(inputMatrix);
Serial.write(matrixToKey(inputMatrix));


}
