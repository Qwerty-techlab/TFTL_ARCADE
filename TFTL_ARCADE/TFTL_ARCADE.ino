//--------------settings------------------
#define BTN_1 1
#define BTN_2 2
#define BTN_3 3
#define GAS_1 4
#define GAS_2 5

#define DT1 6
#define DT2 8
#define SW1 7
#define SW2 9
//----------------------------------------
#include "Keyboard.h"

#include "GyverButton.h"
GButton btn1(BTN_1);
GButton btn2(BTN_2);
GButton btn3(BTN_3);
GButton gas1(GAS_1);
GButton gas2(GAS_2);

#include "GyverEncoder.h"
Encoder first(NULL, DT1, SW1);
Encoder second(NULL, DT2, SW2);
//=========================================
void setup() {
  Keyboard.begin();
  Serial.begin(9600);
}

void loop(){
//-------init------------------------------
  btn1.tick();
  btn2.tick();
  btn3.tick();
  gas1.tick();
  gas2.tick();

  first.tick();
  second.tick();
//----------------------------------------
  if(first.isRight()) Keyboard.print('q');
  if(first.isLeft()) Keyboard.print('w');
  if(second.isRight()) Keyboard.print('e');
  if(second.isLeft()) Keyboard.print('r');

  if(gas1.isHold()) Keyboard.print('t');
  if(gas2.isHold()) Keyboard.print('y');



}
