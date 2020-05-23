//#include "globals.h"
#include "io.h"
#include "coder.h"
using namespace typotron;

byte inputMatrix[8];
void setup() {
  Serial.begin(9600);

}

void loop() {

readToMatrix(inputMatrix);
Serial.write(matrixToKey(inputMatrix))


}
