#if (ARDUINO >= 100)
# include "Arduino.h"
#else
# include "WProgram.h"

#endif

#include "Robot.h"
#include "Command.h"

#define BLINK_PIN 3
#define DATA_RATE 38400

//vai virar atributo
#define SERVO_1_PIN  10
#define SERVO_2_PIN  11
#define SERVO_3_PIN  7
#define SERVO_4_PIN  8

Robot bobina;
Command command;



#define DATA_RATE 9600
void setup() {
  Serial.begin(DATA_RATE);
  bobina.setup(SERVO_1_PIN,SERVO_2_PIN,SERVO_3_PIN,SERVO_4_PIN);
  Serial.println("Iniciando bobina");
  
  
}

void loop() {
    
  if (Serial.available()){
    char op = Serial.read();
    Serial.println(op);
    switch ( command.proccess() )
    {
      case MOVE_ON:  
       bobina.ir_tras();
       break;
     case MOVE_BACK:
      bobina.ir_frente();
        break;
      case MOVE_RIGHT:
        bobina.ir_direita();
         break;
      case MOVE_LEFT:
        bobina.ir_esquerda();
        break;      
    }
  }
  
}




