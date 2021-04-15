#include <math.h>
#include "Motor.h"
#include "Encoder.h"

// Encoder constantes
#define A               12
#define B               13
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
  Serial.begin(9600);
  Serial.println("Iniciando o programa");
  steeringEncoder.configuration();
  steeringMotor.configuration();
  attachInterrupt(digitalPinToInterrupt(inicioDeCurso),desabilitaInterrupcao,RISING);
  Serial.println("Habilitando o motor");
  steeringMotor.turnOnMotor();
  //Serial.println("Setando velocidade");
  //steeringMotor.rotationDirection(true);

}

void loop() {
  //Serial.println("Digite a velocidade de 0 a 255: ");
  //while(Serial.available() <= 0);
  //steeringMotor.setVelocity((int)Serial.read());
  //delay(1000);
  //steeringMotor.setVelocity(0);

  Serial.println("Começando");
  
  //if(steeringEncoder.directionEncoder())
  //  Serial.println("Sentido Anti-horário");
  // else
  //  Serial.println("Sentido Horário");

   Serial.println(steeringEncoder.encoderVelocity(1000));

}

void desabilitaInterrupcao(){
  Serial.println("Interrupção ativa");
  steeringMotor.turnOffMotor();
  steeringMotor.setVelocity(0);
  detachInterrupt(digitalPinToInterrupt(inicioDeCurso));
}
