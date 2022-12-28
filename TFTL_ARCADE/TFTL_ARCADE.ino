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

#include "EncButton2.h"
EncButton2<EB_BTN> btn1(INPUT, BTN_1);
EncButton2<EB_BTN> btn2(INPUT, BTN_2);
EncButton2<EB_BTN> btn3(INPUT, BTN_3);
EncButton2<EB_BTN> gas1(INPUT, GAS_1);
EncButton2<EB_BTN> gas2(INPUT, GAS_1);
EncButton2<EB_ENC> first(INPUT, DT1, SW1);
EncButton2<EB_ENC> second(INPUT, DT2, SW2);
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
  if(first.right()) Keyboard.print(KEY_RIGHT_ARROW);
  if(first.left()) Keyboard.print(KEY_LEFT_ARROW);
  if(second.right()) Keyboard.print('a');
  if(second.left()) Keyboard.print('d');
//----------------------pedals---------------------------
  if(gas1.hold()) Keyboard.print(KEY_UP_ARROW);
  if(gas2.hold()) Keyboard.print('w');
//-----------------------btns----------------------------
  if(btn1.click()) Keyboard.print('p');
  if(btn2.click()) Keyboard.print('q');
  if(btn3.click()) Keyboard.print(' ');
  
//=======================================================
}
