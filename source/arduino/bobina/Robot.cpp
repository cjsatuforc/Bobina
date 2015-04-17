#include "Robot.h"

#include "Servo.h"


Robot::Robot()
{
 
  
}

void Robot::setup()
{
  Robot::servo1.attach(SERVO_1_PIN);
  Robot::servo2.attach(SERVO_2_PIN);
  Robot::servo3.attach(SERVO_3_PIN);
  Robot::servo4.attach(SERVO_4_PIN);  
  
  Robot::servo1.write(SERVO_1_ORIGINAL_POSITION);
  Robot::servo2.write(SERVO_2_ORIGINAL_POSITION);
  Robot::servo3.write(SERVO_3_ORIGINAL_POSITION);
  Robot::servo4.write(SERVO_4_ORIGINAL_POSITION);  
}

void Robot::frente_esquerda()
{
   
  servo3.write(   SERVO_3_ORIGINAL_POSITION + ANGULO_MOVER_PERNA );
  servo4.write(   SERVO_4_ORIGINAL_POSITION + ANGULO_MOVER_PERNA );
  delay(400);
  servo2.write(   SERVO_2_ORIGINAL_POSITION - ANGULO_MOVER_PERNA );
  servo1.write(   SERVO_1_ORIGINAL_POSITION - ANGULO_MOVER_PERNA );
  delay(400);
  servo4.write(   SERVO_4_ORIGINAL_POSITION);
  servo3.write(   SERVO_3_ORIGINAL_POSITION);  
  
}




void Robot::frente_direita()
{

   servo3.write(   SERVO_3_ORIGINAL_POSITION - ANGULO_MOVER_PERNA );
   servo4.write(   SERVO_4_ORIGINAL_POSITION - ANGULO_MOVER_PERNA );
   delay(400);
   servo1.write(   SERVO_1_ORIGINAL_POSITION + ANGULO_MOVER_PERNA );
   servo2.write(   SERVO_2_ORIGINAL_POSITION + ANGULO_MOVER_PERNA );
   delay(400);
   servo4.write(   SERVO_4_ORIGINAL_POSITION);
   servo3.write(   SERVO_3_ORIGINAL_POSITION);


}

void Robot::tras_esquerda()
{
  
   servo3.write(   SERVO_3_ORIGINAL_POSITION + ANGULO_MOVER_PERNA );
   servo4.write(   SERVO_4_ORIGINAL_POSITION + ANGULO_MOVER_PERNA );
   delay(400);
   servo2.write(   SERVO_2_ORIGINAL_POSITION + ANGULO_MOVER_PERNA );
   servo1.write(   SERVO_1_ORIGINAL_POSITION + ANGULO_MOVER_PERNA );
   delay(400);
   servo4.write(   SERVO_4_ORIGINAL_POSITION);
   servo3.write(   SERVO_3_ORIGINAL_POSITION);  
   
}
void Robot::tras_direita()
{

  servo3.write(   SERVO_3_ORIGINAL_POSITION - ANGULO_MOVER_PERNA );
   servo4.write(   SERVO_4_ORIGINAL_POSITION - ANGULO_MOVER_PERNA );
   delay(400);
   servo1.write(   SERVO_1_ORIGINAL_POSITION - ANGULO_MOVER_PERNA );
   servo2.write(   SERVO_2_ORIGINAL_POSITION - ANGULO_MOVER_PERNA );
   delay(400);
   servo4.write(   SERVO_4_ORIGINAL_POSITION);
   servo3.write(   SERVO_3_ORIGINAL_POSITION);
 
}

void Robot::ajeita_direita()
{
  
   servo3.write(   SERVO_3_ORIGINAL_POSITION - ANGULO_MOVER_PERNA );
   servo4.write(   SERVO_4_ORIGINAL_POSITION - ANGULO_MOVER_PERNA );
   delay(400);
   servo1.write(   SERVO_3_ORIGINAL_POSITION);
   servo2.write(   SERVO_4_ORIGINAL_POSITION);
   delay(400);
   
   servo4.write(   SERVO_4_ORIGINAL_POSITION);
   servo3.write(   SERVO_3_ORIGINAL_POSITION);
   
 
}

void Robot::ir_frente()
{
  
  static int dir = 0;
  if ( dir == 0)
  {
     frente_direita();
     dir = 1; 
  }else{
    frente_esquerda();
    dir = 0;
  }
  delay(tempo_espera);
  

}
void Robot::ir_tras()
{

  static int dir = 0;
  if ( dir == 0)
  {
    tras_direita();
    dir = 1; 
  }else{
    tras_esquerda();
    dir = 0;
  }
  delay(tempo_espera);
  
}
void Robot::ir_direita()
{

static int dir = 0;
  if ( dir == 0)
  {
    tras_direita();
    dir = 1; 
  }else{
    ajeita_direita();
    dir = 0;
  }
  delay(tempo_espera);  
  
}
void Robot::ir_esquerda()
{
  
    static int dir = 0;
  if ( dir == 0)
  {
    frente_direita();
    dir = 1; 
  }else{
    ajeita_direita();
    dir = 0;
  }
  delay(tempo_espera);
  
}
