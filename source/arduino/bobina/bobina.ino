#if (ARDUINO >= 100)
# include "Arduino.h"
#else
# include "WProgram.h"

#endif

#include "Robot.h"
#include "Command.h"

#define BLINK_PIN 3
//#define DATA_RATE 38400

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

/**
* start a test in the motors
* to know if the right motors are selected
* and if it's moving right
*/
void testMotors()
{
  Serial.println("girando perna esquerda");
  bobina.move_motor(SERVO_1,SERVO_1_INITIAL_POSITION);
  delay(1000);
  bobina.move_motor(SERVO_1,SERVO_1_INITIAL_POSITION+ANGULO_MOVER_PERNA);
  delay(1000);
  bobina.move_motor(SERVO_1,SERVO_1_INITIAL_POSITION-ANGULO_MOVER_PERNA);
  delay(1000);
  bobina.move_motor(SERVO_1,SERVO_1_INITIAL_POSITION);
  delay(1000);

  Serial.println("girando perna direita");
  bobina.move_motor(SERVO_2,SERVO_2_INITIAL_POSITION);
  delay(1000);
  bobina.move_motor(SERVO_2,SERVO_2_INITIAL_POSITION+ANGULO_MOVER_PERNA);
  delay(1000);
  bobina.move_motor(SERVO_2,SERVO_2_INITIAL_POSITION-ANGULO_MOVER_PERNA);
  delay(1000);
  bobina.move_motor(SERVO_2,SERVO_2_INITIAL_POSITION);
  delay(1000);

  Serial.println("inclinando perna esquerda");
  bobina.move_motor(SERVO_3,SERVO_2_INITIAL_POSITION);
  delay(1000);
  bobina.move_motor(SERVO_3,SERVO_2_INITIAL_POSITION+ANGULO_MOVER_PERNA);
  delay(1000);
  bobina.move_motor(SERVO_3,SERVO_2_INITIAL_POSITION-ANGULO_MOVER_PERNA);
  delay(1000);
  bobina.move_motor(SERVO_3,SERVO_2_INITIAL_POSITION);
  delay(1000);

  Serial.println("inclinando perna direita");
  bobina.move_motor(SERVO_4,SERVO_2_INITIAL_POSITION);
  delay(1000);
  bobina.move_motor(SERVO_4,SERVO_2_INITIAL_POSITION+ANGULO_MOVER_PERNA);
  delay(1000);
  bobina.move_motor(SERVO_4,SERVO_2_INITIAL_POSITION-ANGULO_MOVER_PERNA);
  delay(1000);
  bobina.move_motor(SERVO_4,SERVO_2_INITIAL_POSITION);
  delay(1000);  

}

void loop() {
    
//  if (Serial.available()){
   // char op = Serial.read();
//    Serial.println(op);
    switch ( command.proccess() )
    {
      case MOVE_ON:  
       bobina.ir_frente();
       break;
     case MOVE_BACK:
      bobina.ir_tras();
        break;
      case MOVE_RIGHT:
        bobina.ir_direita();
         break;
      case MOVE_LEFT:
        bobina.ir_esquerda();
        break; 
      case TEST_MOTORS:
        testMotors();
        break;     
    }
  //}
  
}




