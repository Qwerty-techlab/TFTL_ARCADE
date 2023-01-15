/*
  TFTL-ARCADE
  this sketch works only on Arduino Leonardo 
  and similar bords (like as pro micro).
  created 24 Dec 2022
  modified 12 Jan 2023
  by Kirill Chefonov
  GitHub: https://github.com/Qwerty-techlab
  VK: https://vk.com/alkekseevich 
*/

//--------------settings------------------
#define BTN_1 2 //left btn
#define BTN_2 3 //right btn
#define BTN_3 4 //start btn
#define GAS_1 5 
#define GAS_2 6

//encoder(wheel) pins. 1-left encoder, 2-right encoder
#define DT1 7  
#define DT2 8
#define SW1 9
#define SW2 10
//----------------------------------------
#include "Keyboard.h"
#include "GyverEncoder.h"
#include "GyverButton.h"
GButton btn1(BTN_1);
GButton btn2(BTN_2);
GButton btn3(BTN_3);
GButton gas1(GAS_1);
GButton gas2(GAS_2);
Encoder first(DT1, SW1);
Encoder second(DT2, SW2);
//=========================================
void setup() {
  Keyboard.begin();
  Serial.begin(9600);
  first.setType(TYPE2);
  second.setType(TYPE2);
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
  if(first.isRight()) Keyboard.print('z');
  if(first.isLeft()) Keyboard.print('x');
  if(second.isRight()) Keyboard.print('a');
  if(second.isLeft()) Keyboard.print('d');
//----------------------pedals---------------------------
  if(gas1.isHold()) Keyboard.print('e');
  if(gas2.isHold()) Keyboard.print('w');
//-----------------------btns----------------------------
  if(btn1.isClick()) Keyboard.print('p');
  if(btn2.isClick()) Keyboard.print('q');
  if(btn3.isClick()) Keyboard.print(' ');
  
//=======================================================
}
