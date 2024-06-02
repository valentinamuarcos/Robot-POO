#ifndef CARRO_HEADER
#define CARRO_HEADER

// Definir los pines para los sensores infrarrojos

#define SENSOR_IZQUIERDO A0
#define SENSOR_DERECHO A1

class Carro {

    private:

        // Definir los pines para los motores

        int atrMotorIzquierdoPin1;
        int atrMotorIzquierdoPin2;
        int atrMotorDerechoPin1;
        int atrMotorDerechoPin2;

    public:

        // Constructors

        Carro() = default;

        Carro(
            int prmMotorIzquierdoPin1,
            int prmMotorIzquierdoPin2,
            int prmMotorDerechoPin1,
            int prmMotorDerechoPin2
        );

        // Metodos 'getter' y 'setter':

        int getMotorIzquierdoPin1();
        void setMotorIzquierdoPin1(int prmMotorIzquierdoPin1);
        int getMotorIzquierdoPin2();
        void setMotorIzquierdoPin2(int prmMotorIzquierdoPin2);

        int getMotorDerechoPin1();
        void setMotorDerechoPin1(int prmMotorDerechoPin1);
        int getMotorDerechoPin2();
        void setMotorDerechoPin2(int prmMotorDerechoPin2);

        /**
         *  Metodo para configurar los pines de los motorores como salidas
        */
        void configurarPinesSalida();

        /**
         *  Metodo para configurar los pines de los motorores como entrada
        */
        void configurarPinesEntrada();

        /**
         *  Metodo para que el carro avance en linea recta
        */
        void avanzar();

        /**
         *  Metodo para que el carro gire a la izquierda
        */
        void girarIzquierda();

        /**
         *  Metodo para que el carro gire a la derecha
        */
        void girarDerecha();

        /**
         *  Metodo para detener al carro en movimiento
        */
        void detener();

        /**
         *  Metodo para determinar la direccion del movimiento del carro
        */
        void determinarDireccion();

        // Destructor
        ~Carro() = default;
};

#endif
