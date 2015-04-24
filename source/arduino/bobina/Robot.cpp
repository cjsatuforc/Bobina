#include "Robot.h"

#include "Servo.h"


Robot::Robot()
{
 
  
}

void Robot::setup(int servo1_pin,int servo2_pin,int servo3_pin,int servo4_pin)
{
  Robot::servo1.attach(servo1_pin);
  Robot::servo2.attach(servo2_pin);
  Robot::servo3.attach(servo3_pin);
  Robot::servo4.attach(servo4_pin);  
  
  Robot::servo1.write(SERVO_1_INITIAL_POSITION);
  Robot::servo2.write(SERVO_2_INITIAL_POSITION);
  Robot::servo3.write(SERVO_3_INITIAL_POSITION);
  Robot::servo4.write(SERVO_4_INITIAL_POSITION);  
}

void Robot::frente_esquerda()
{
   
  servo3.write(   SERVO_3_INITIAL_POSITION + ANGULO_MOVER_PERNA );
  servo4.write(   SERVO_4_INITIAL_POSITION + ANGULO_MOVER_PERNA );
  delay(400);
  servo2.write(   SERVO_2_INITIAL_POSITION - ANGULO_MOVER_PERNA );
  servo1.write(   SERVO_1_INITIAL_POSITION - ANGULO_MOVER_PERNA );
  delay(400);
  servo4.write(   SERVO_4_INITIAL_POSITION);
  servo3.write(   SERVO_3_INITIAL_POSITION);  
  
}




void Robot::frente_direita()
{

   servo3.write(   SERVO_3_INITIAL_POSITION - ANGULO_MOVER_PERNA );
   servo4.write(   SERVO_4_INITIAL_POSITION - ANGULO_MOVER_PERNA );
   delay(400);
   servo1.write(   SERVO_1_INITIAL_POSITION + ANGULO_MOVER_PERNA );
   servo2.write(   SERVO_2_INITIAL_POSITION + ANGULO_MOVER_PERNA );
   delay(400);
   servo4.write(   SERVO_4_INITIAL_POSITION);
   servo3.write(   SERVO_3_INITIAL_POSITION);


}

void Robot::tras_esquerda()
{
  
   servo3.write(   SERVO_3_INITIAL_POSITION + ANGULO_MOVER_PERNA );
   servo4.write(   SERVO_4_INITIAL_POSITION + ANGULO_MOVER_PERNA );
   delay(400);
   servo2.write(   SERVO_2_INITIAL_POSITION + ANGULO_MOVER_PERNA );
   servo1.write(   SERVO_1_INITIAL_POSITION + ANGULO_MOVER_PERNA );
   delay(400);
   servo4.write(   SERVO_4_INITIAL_POSITION);
   servo3.write(   SERVO_3_INITIAL_POSITION);  
   
}
void Robot::tras_direita()
{

  servo3.write(   SERVO_3_INITIAL_POSITION - ANGULO_MOVER_PERNA );
   servo4.write(   SERVO_4_INITIAL_POSITION - ANGULO_MOVER_PERNA );
   delay(400);
   servo1.write(   SERVO_1_INITIAL_POSITION - ANGULO_MOVER_PERNA );
   servo2.write(   SERVO_2_INITIAL_POSITION - ANGULO_MOVER_PERNA );
   delay(400);
   servo4.write(   SERVO_4_INITIAL_POSITION);
   servo3.write(   SERVO_3_INITIAL_POSITION);
 
}

void Robot::ajeita_direita()
{
  
   servo3.write(   SERVO_3_INITIAL_POSITION - ANGULO_MOVER_PERNA );
   servo4.write(   SERVO_4_INITIAL_POSITION - ANGULO_MOVER_PERNA );
   delay(400);
   servo1.write(   SERVO_3_INITIAL_POSITION);
   servo2.write(   SERVO_4_INITIAL_POSITION);
   delay(400);
   
   servo4.write(   SERVO_4_INITIAL_POSITION);
   servo3.write(   SERVO_3_INITIAL_POSITION);
   
 
}
bool Robot::move_motor(int motor_id,int servo_degrees)
{
  //validate degrees
  if ( servo_degrees < 0 || servo_degrees > 180)
    return false;

    if ( motor_id == SERVO_1){
      servo1.write(servo_degrees);
      return true;
    }
    else if ( motor_id == SERVO_2){
      servo2.write(servo_degrees);
      return true;
    }
    else if ( motor_id == SERVO_3){
      servo3.write(servo_degrees);
      return true;
    }
    else if ( motor_id == SERVO_4){
      servo4.write(servo_degrees);
      return true;
    }
    return false;

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
