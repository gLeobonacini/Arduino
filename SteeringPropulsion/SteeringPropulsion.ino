#include <math.h>
#include "Motor.h"
#include "Encoder.h"

// Encoder constantes
#define´A               12
#define B               13
#define pulseEncoder    600
#define wheelDiameter   0.6

// Motor constantes
#define enableMotor     11
#define directionMotor  10
#define inicioDeCurso   2


Encoder steeringEncoder(A,B,pulseEncoder,wheelDiameter);
Motor steeringMotor(enableMotor.directionMotor,pwm);

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando o programa");
  sterringEncoder.configuration();
  sterringMotor.configuration();
  attachInterrupt(digitalPinToInterrupt(inicioDeCurso),desabilitaInterrupcao,RISING);
  Serial.println("Habilitando o motor");
  steeringMotor.turnOnMotor();
  Serial.println("Setando velocidade em 10% com sentido true");
  steeringMotor.rotationDirection(true);
  steeringMotor.setVelocity(25);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

void desabilitaInterrupcao(){
  Serial.println("Interrupção ativa");
  sterringMotor.turnOffMotor();
  sterringMotor.setVelocity(0);
  detachInterrupt(digitalPinToInterrupt(inicioDeCurso));
}