#ifndef CARRO_BODY
#define CARRO_BODY
#include "./carro.h"
#include <Arduino.h>
// Constructor

Carro::Carro(
            int prmMotorIzquierdoPin1,
            int prmMotorIzquierdoPin2,
            int prmMotorDerechoPin1,
            int prmMotorDerechoPin2
        )
{
    this->atrMotorIzquierdoPin1 = prmMotorIzquierdoPin1;
    this->atrMotorIzquierdoPin2 = prmMotorIzquierdoPin2;
    this->atrMotorDerechoPin1 = prmMotorDerechoPin1;
    this->atrMotorDerechoPin2 = prmMotorDerechoPin2;
}

// Metodos 'getter' y 'setter':

int Carro::getMotorIzquierdoPin1()
{
    return this->atrMotorIzquierdoPin1;
}

void Carro::setMotorIzquierdoPin1(int prmMotorIzquierdoPin1)
{
    this->atrMotorIzquierdoPin1 = prmMotorIzquierdoPin1;
}

int Carro::getMotorIzquierdoPin2()
{
    return this->atrMotorIzquierdoPin2;
}

void Carro::setMotorIzquierdoPin2(int prmMotorIzquierdoPin2)
{
    this->atrMotorIzquierdoPin2 = prmMotorIzquierdoPin2;
}

int Carro::getMotorDerechoPin1()
{
    return this->atrMotorDerechoPin1;
}

void Carro::setMotorDerechoPin1(int prmMotorDerechoPin1)
{
    this->atrMotorDerechoPin1 = prmMotorDerechoPin1;
}

int Carro::getMotorDerechoPin2()
{
    return this->atrMotorDerechoPin2;
}

void Carro::setMotorDerechoPin2(int prmMotorDerechoPin2)
{
    this->atrMotorDerechoPin2 = prmMotorDerechoPin2;
}

// Metodos:

void Carro::configurarPinesSalida()
{
    pinMode(this->atrMotorIzquierdoPin1, OUTPUT);
    pinMode(this->atrMotorIzquierdoPin2, OUTPUT);
    pinMode(this->atrMotorDerechoPin1, OUTPUT);
    pinMode(this->atrMotorDerechoPin2, OUTPUT);
}

void Carro::configurarPinesEntrada()
{
    pinMode(SENSOR_IZQUIERDO, INPUT);
    pinMode(SENSOR_DERECHO, INPUT);
    Serial.begin(9600);
}

void Carro::avanzar()
{
    digitalWrite(this->atrMotorIzquierdoPin1, HIGH);
    digitalWrite(this->atrMotorDerechoPin1, HIGH);
    digitalWrite(this->atrMotorIzquierdoPin2, LOW);
    digitalWrite(this->atrMotorDerechoPin2, LOW);
    Serial.println("Carro avanza");
}

void Carro::girarIzquierda()
{
    digitalWrite(this->atrMotorIzquierdoPin1, HIGH);
    digitalWrite(this->atrMotorIzquierdoPin2, LOW);
    digitalWrite(this->atrMotorDerechoPin1, LOW);
    digitalWrite(this->atrMotorDerechoPin2, HIGH);
    Serial.println("Carro izquierda");
}

void Carro::girarDerecha()
{
    digitalWrite(this->atrMotorIzquierdoPin1, LOW);
    digitalWrite(this->atrMotorIzquierdoPin2, HIGH);
    digitalWrite(this->atrMotorDerechoPin1, HIGH);
    digitalWrite(this->atrMotorDerechoPin2, LOW);
    Serial.println("Carro derecha");
}

void Carro::detener()
{
    digitalWrite(this->atrMotorIzquierdoPin1, LOW);
    digitalWrite(this->atrMotorIzquierdoPin2, LOW);
    digitalWrite(this->atrMotorDerechoPin1, LOW);
    digitalWrite(this->atrMotorDerechoPin2, LOW);
    Serial.println("Carro detener");
}

void Carro::determinarDireccion()
{
    if (digitalRead(SENSOR_IZQUIERDO) && digitalRead(SENSOR_DERECHO))
        avanzar();

    else if(digitalRead(SENSOR_IZQUIERDO) && !digitalRead(SENSOR_DERECHO))
        girarIzquierda();
    
    else if(!digitalRead(SENSOR_IZQUIERDO) && digitalRead(SENSOR_DERECHO))
        girarDerecha();

    else
        detener();
}

#endif
