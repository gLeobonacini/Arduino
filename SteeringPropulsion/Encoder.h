class SensorEncoder{
	// Atributos
	private:
		int pinAEncoder = 0;		            // Pino que liga ou desliga o motor
	    int pinBEncoder = 0;					// Pino que inidica a sentido de rotação do motor
		int pulses = 0;							// Quantidade de pulsos do encoder
		float wheelDiameter = 0.0;				// Diâmetro da roda
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
			pinMode(pinAEncoder,INPUT);
			pinMode(pinBEncoder,INPUT);
		}

		bool directionMotor(){			
			// Verifica o sentido de rotação do motor:
			// true -> Anti-horário 
			// false -> Horário
		
			bool change = false;
			bool actualStateA = digitalRead(pinAEncoder);
			bool actualStateB = digitalRead(pinAEncoder);
			bool previousStateA;
			bool previousStateB;
		
			do{
				previousStateA = actualStateA;
				previousStateB = actualStateB;
				actualStateA = digitalRead(pinAEncoder);
				actualStateB = digitalRead(pinBEncoder);
				if(actualStateA != previousStateA || actualStateB != previousStateB)
					change = true;
			}while(!change);
		
			if(previousStateA == 0 && previousStateB == 0){
				if(actualStateA == 0)
					return true;
				else
					return false;
			}

			else if(previousStateA == 0 && previousStateB == 1){
				if(actualStateA == 1)
					return true;
				else
					return false;
			}	

			else if(previousStateA == 1 && previousStateB == 1){
				if(actualStateA == 1)
					return true;
				else
					return false;
			}	

			else{
				if(actualStateA == 0)
					return true;
				else
					return false;
			}

		}

		float encoderVelocity(int timeMillis){		
			// Retorna a velocidade em diameterUnit/s
			int count = 0;
			int initialTime = millis();

			do{
				if(digitalRead(pinAEncoder) == 0 && digitalRead(pinBEncoder) == 0)
					count++;
			}while(initialTime + timeMillis > millis());
	
			return ((count/pulses)*M_PI*wheelDiameter)/(timeMillis/1000); 
		}	
};