#define readPinA        bitRead(PIND,2)
#define readPinB        bitRead(PIND,3)


// Variáveis
volatile long int contadorPassos = 0;
long int contadorProtegido = 0;
long int tempoInicial = 0;
long int tempoAtual = 0;
long int tempoDecorrido = 0;   

class SensorEncoder{
	// Atributos
	private:
		  int pinAEncoder = 0;		            // Pino que liga ou desliga o motor
	    int pinBEncoder = 0;					      // Pino que inidica a sentido de rotação do motor
		  int pulses = 0;							        // Quantidade de pulsos do encoder
		  float wheelDiameter = 0.0;				  // Diâmetro da roda
	public:
		// Construtor
		SensorEncoder(int A, int B, int pulse, float diameter){
			pinAEncoder = A;
			pinBEncoder = B;
			pulses = pulse;
			wheelDiameter = diameter;
		}

		// Métodos
		void configuration(){			// Configura os pinos
			pinMode(pinAEncoder,INPUT_PULLUP);
			pinMode(pinBEncoder,INPUT_PULLUP);
      // Configurando as interrupções
      noInterrupts();
		}

   int getPinA(){
    return pinAEncoder;
   }

   int getPinB(){
    return pinBEncoder;
   }

		bool goAhead(){			
			// Verifica o sentido de rotação do motor:
			// true -> Para frente 
			// false -> Para trás
      contadorPassos = 0;
      contadorProtegido = 0;
      interrupts();
      do{
        contadorProtegido = contadorPassos;
      }while(contadorProtegido == 0);
		  noInterrupts();
      return (contadorProtegido > 0);			
		}

		float velocity(int timeMillis){
			contadorPassos = 0;
			tempoInicial = millis();
			interrupts();
      do{
        tempoAtual = millis();
        if(tempoAtual < tempoInicial)
          tempoDecorrido = 4294967295 - tempoInicial + tempoAtual;
        else
          tempoDecorrido = tempoAtual - tempoInicial;
      }while(tempoDecorrido < timeMillis);
      contadorProtegido = contadorPassos;
      Serial.println(contadorProtegido);
      noInterrupts();
      return ((contadorProtegido/pulses)*M_PI*wheelDiameter)/(timeMillis/1000); 
		}	
};
