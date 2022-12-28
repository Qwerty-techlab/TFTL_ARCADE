/*
  TFTL-ARCADE

  this sketch works only on Arduino Leonardo 
  and similar bords (like as pro micro).

  created 24 Dec 2022
  modified 28 Dec 2022
  by Kirill Chefonov

  GitHub: https://github.com/Qwerty-techlab
  VK: https://vk.com/alkekseevich 
*/

//--------------settings------------------
#define BTN_1 1 //left btn
#define BTN_2 2 //right btn
#define BTN_3 3 //start btn
#define GAS_1 4 
#define GAS_2 5

//encoder(wheel) pins. 1-left encoder, 2-right encoder
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

//=======================================================

//-----------------------wheel---------------------------
  if(first.isRight()) Keyboard.print(KEY_RIGHT_ARROW);
  if(first.isLeft()) Keyboard.print(KEY_LEFT_ARROW);
  if(second.isRight()) Keyboard.print('a');
  if(second.isLeft()) Keyboard.print('d');
//----------------------pedals---------------------------
  if(gas1.isHold()) Keyboard.print(KEY_UP_ARROW);
  if(gas2.isHold()) Keyboard.print('w');
//-----------------------btns----------------------------
  if(btn1.isHold()) Keyboard.print('p');
  if(btn2.isHold()) Keyboard.print('q');
  if(btn3.isHold()) Keyboard.print('');
  
//=======================================================
}
