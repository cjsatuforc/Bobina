
#ifndef ROBOT_H
#define ROBOT_H
#if defined(ARDUINO) && ARDUINO >= 100
      #include "Arduino.h"
    #else
      #include "WProgram.h"
    #endif

#include "Servo.h"

/*
 * id's that identifies the
 * motors of the rotot
 */
#define SERVO_1     11
#define SERVO_2     12
#define SERVO_3     13
#define SERVO_4     14

/*
 * initial servo positions
 */
#define SERVO_1_INITIAL_POSITION 93
#define SERVO_2_INITIAL_POSITION 93
#define SERVO_3_INITIAL_POSITION 93
#define SERVO_4_INITIAL_POSITION 99//tava 99


#define LEG_MOVE_DEGREES 30




class Robot{
 public:
    Robot();
    /*
     * Initialize the robot
     */
    void setup(int servo1_pin,int servo2_pin,int servo3_pin,int servo4_pin);
    /*
     *  Manually move one motor
     *  use the motors id's defined 
     *  in this file     
     */

    bool move_motor(int motor_id,int servo_degrees);

    
    void move_on();
    void move_back();
    void move_left();
    void move_right();
private:
    int tempo_espera = 100;
    
    Servo servo1;
    Servo servo2;
    Servo servo3;
    Servo servo4;

    void move_on_left();
    void move_on_right();
    void move_back_left();
    void move_back_right();
    void ajeita_direita();   

};

#endif

