
#ifndef ROBOT_H
#define ROBOT_H
#if defined(ARDUINO) && ARDUINO >= 100
      #include "Arduino.h"
    #else
      #include "WProgram.h"
    #endif

#include "Servo.h"

/*
 * values that identifies the
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


#define ANGULO_MOVER_PERNA 30




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


    void frente_esquerda();
    void frente_direita();
    void tras_esquerda();
    void tras_direita();
    void ajeita_direita();    
    void ir_frente();
    void ir_tras();
    void ir_direita();
    void ir_esquerda();
private:
    int tempo_espera = 100;
    
    Servo servo1;
    Servo servo2;
    Servo servo3;
    Servo servo4;

};

#endif

