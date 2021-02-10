class Encoder{
	// Atributos
	int pinAEncoder;		// Pino que liga ou desliga o motor
	int pinBEncoder;		// Pino que inidica a sentido de rotação do motor

	// Construtor
	Encoder(int A, int B){
		pinAEncoder = A;
		pinBEncoder = B;
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
		bool actualStateA = digitalReal(pinAEncoder)
		bool actualStateB = digitalReal(pinAEncoder)
		bool previousStateA;
		bool previousStateB;
		
		do{
			previousStateA = actualStateA;
			previousStateB = actualStateB;
			actualStateA = digitalReal(pinAEncoder);
			actualStateB = digitalReal(pinBEncoder);
			if(actualStateA != previousStateA || actualStateB != previousStateB)
				change = true
		}while(!change);
		
		if(previousStateA == 0 && previousStateB == 0){
			if(actualStateA == 0)
				return true
			else
				return false
		}

		else if(previousStateA == 0 && previousStateB == 1){
			if(actualStateA == 1)
				return true
			else
				return false
		}

		else if(previousStateA == 1 && previousStateB == 1){
			if(actualStateA == 1)
				return true
			else
				return false
		}

		else{
			if(actualStateA == 0)
				return true
			else
				return false
		}

	}

	float encoderVelocity(float diameterMeter, int pulses, int timeMillis){		
		// Retorna a velocidade em diameterUnit/s
		int count = 0;
		int initialTime = millis();

		do{
			if(digitalRead(pinAEncoder) == 0 && digitalRead(pinBEncoder) == 0)
				count++;
		}while(initialTime + timeMillis > millis());

		return ((count/pulses)*pi*diameter)/(timeMillis/1000)  
	}
		
}