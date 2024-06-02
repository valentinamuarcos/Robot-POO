#include "carro.h"


// Definir los pines para los motores

#define MOTOR_IZQUIERDO_PIN1 8
#define MOTOR_IZQUIERDO_PIN2 9
#define MOTOR_DERECHO_PIN1 10
#define MOTOR_DERECHO_PIN2 11

Carro objCarro;
int codigo = 2;

void setup()
{
  // Configurar el carro:
  objCarro.setMotorIzquierdoPin1(MOTOR_IZQUIERDO_PIN1);
  objCarro.setMotorIzquierdoPin2(MOTOR_IZQUIERDO_PIN2);
  objCarro.setMotorDerechoPin1(MOTOR_DERECHO_PIN1);
  objCarro.setMotorDerechoPin2(MOTOR_DERECHO_PIN2);

  objCarro.configurarPinesSalida();
  objCarro.configurarPinesEntrada();
}

void loop()
{
  while(codigo == 2)
    objCarro.determinarDireccion();
}
