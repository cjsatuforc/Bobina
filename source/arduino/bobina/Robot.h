
#ifndef ROBOT_H
#define ROBOT_H
#if defined(ARDUINO) && ARDUINO >= 100
      #include "Arduino.h"
    #else
      #include "WProgram.h"
    #endif

#include "Servo.h"


#define SERVO_1_ORIGINAL_POSITION 93
#define SERVO_2_ORIGINAL_POSITION 93
#define SERVO_3_ORIGINAL_POSITION 93
#define SERVO_4_ORIGINAL_POSITION 99//tava 99


#define ANGULO_MOVER_PERNA 30

//vai virar atributo
#define SERVO_1_PIN  10
#define SERVO_2_PIN  11
#define SERVO_3_PIN  7
#define SERVO_4_PIN  8


class Robot{
 public:
    Robot();
    void setup();
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

