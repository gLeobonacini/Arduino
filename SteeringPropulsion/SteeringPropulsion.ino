#include <math.h>
#include "Motor.h"
#include "Encoder.h"

// Encoder constantes
#define A               2     // A -> Pino 2
#define B               3     // B -> Pino 3
#define pulseEncoder    600
#define wheelDiameter   0.6

// Motor constantes
#define enableMotor     11
#define directionMotor  10
#define inicioDeCurso   2
#define PWM             9 

SensorEncoder steeringEncoder(A,B,pulseEncoder,wheelDiameter);
Motor steeringMotor(enableMotor,directionMotor,PWM);

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando o programa");
  steeringEncoder.configuration();
  attachInterrupt(digitalPinToInterrupt(steeringEncoder.getPinA()),isrA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(steeringEncoder.getPinB()),isrB, CHANGE);
}

void loop() {
  //Serial.print(steeringEncoder.goAhead());
  //Serial.print(" ****** ");
  steeringEncoder.velocity(1000);
}

void isrA(){
  if(readPinA != readPinB)
    contadorPassos++;
  else
    contadorPassos--;
}

void isrB(){
  if(readPinA == readPinB)
    contadorPassos++;
  else
    contadorPassos--;
}
