#if (ARDUINO >= 100)
# include "Arduino.h"
#else
# include "WProgram.h"

#endif
#include "Robot.h"


#define BLINK_PIN 3
#define DATA_RATE 38400

Robot bobina;




#define DATA_RATE 9600
void setup() {
  Serial.begin(DATA_RATE);
   bobina.setup();
   Serial.println("Iniciando bobina");
  
  
}

void loop() {
    
  if (Serial.available()){
    char op = Serial.read();
    Serial.println(op);
    switch ( op )
    {
      case 't':  
       bobina.ir_tras();
       break;
     case 'f':
      bobina.ir_frente();
        break;
      case 'd':
        bobina.ir_direita();
         break;
      case 'e':
        bobina.ir_esquerda();
        break;
      case 'h':
        digitalWrite(BLINK_PIN,HIGH);
        break;
      case 'x':
        digitalWrite(BLINK_PIN,LOW);
        break;
    }
  }
  
}




