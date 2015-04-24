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

void Robot::move_on_left()
{
   
  servo3.write(   SERVO_3_INITIAL_POSITION + LEG_MOVE_DEGREES );
  servo4.write(   SERVO_4_INITIAL_POSITION + LEG_MOVE_DEGREES );
  delay(400);
  servo2.write(   SERVO_2_INITIAL_POSITION - LEG_MOVE_DEGREES );
  servo1.write(   SERVO_1_INITIAL_POSITION - LEG_MOVE_DEGREES );
  delay(400);
  servo4.write(   SERVO_4_INITIAL_POSITION);
  servo3.write(   SERVO_3_INITIAL_POSITION);  
  
}




void Robot::move_on_right()
{

   servo3.write(   SERVO_3_INITIAL_POSITION - LEG_MOVE_DEGREES );
   servo4.write(   SERVO_4_INITIAL_POSITION - LEG_MOVE_DEGREES );
   delay(400);
   servo1.write(   SERVO_1_INITIAL_POSITION + LEG_MOVE_DEGREES );
   servo2.write(   SERVO_2_INITIAL_POSITION + LEG_MOVE_DEGREES );
   delay(400);
   servo4.write(   SERVO_4_INITIAL_POSITION);
   servo3.write(   SERVO_3_INITIAL_POSITION);


}

void Robot::move_back_left()
{
  
   servo3.write(   SERVO_3_INITIAL_POSITION + LEG_MOVE_DEGREES );
   servo4.write(   SERVO_4_INITIAL_POSITION + LEG_MOVE_DEGREES );
   delay(400);
   servo2.write(   SERVO_2_INITIAL_POSITION + LEG_MOVE_DEGREES );
   servo1.write(   SERVO_1_INITIAL_POSITION + LEG_MOVE_DEGREES );
   delay(400);
   servo4.write(   SERVO_4_INITIAL_POSITION);
   servo3.write(   SERVO_3_INITIAL_POSITION);  
   
}
void Robot::move_back_right()
{

  servo3.write(   SERVO_3_INITIAL_POSITION - LEG_MOVE_DEGREES );
   servo4.write(   SERVO_4_INITIAL_POSITION - LEG_MOVE_DEGREES );
   delay(400);
   servo1.write(   SERVO_1_INITIAL_POSITION - LEG_MOVE_DEGREES );
   servo2.write(   SERVO_2_INITIAL_POSITION - LEG_MOVE_DEGREES );
   delay(400);
   servo4.write(   SERVO_4_INITIAL_POSITION);
   servo3.write(   SERVO_3_INITIAL_POSITION);
 
}

void Robot::ajeita_direita()
{
  
   servo3.write(   SERVO_3_INITIAL_POSITION - LEG_MOVE_DEGREES );
   servo4.write(   SERVO_4_INITIAL_POSITION - LEG_MOVE_DEGREES );
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
void Robot::move_on()
{
  
  static int dir = 0;
  if ( dir == 0)
  {
     move_on_right();
     dir = 1; 
  }else{
    move_on_left();
    dir = 0;
  }
  delay(tempo_espera);
  

}
void Robot::move_back()
{

  static int dir = 0;
  if ( dir == 0)
  {
    move_back_left();
    dir = 1; 
  }else{
    move_back_right();
    dir = 0;
  }
  delay(tempo_espera);
  
}
void Robot::move_right()
{

  delay(tempo_espera);
  
}
void Robot::move_left()
{
  

  delay(tempo_espera);
  
}
