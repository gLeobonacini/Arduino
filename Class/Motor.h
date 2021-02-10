class Motor{
	// Atributos
	int enableMotor;		// Pino que liga ou desliga o motor
	int directionMotor;		// Pino que inidica a sentido de rotação do motor
	int pwmMotor;			// Pino referente ao PWM que vai ao motor
	int initialPositionMotor;    	// Pino da interrupção que verifica se chegou na posição inicial

	// Construtor
	Motor(int enable, int direction, int pwm, int initialPosition){
		pwmMotor = pwm;
		enableMotor = enable;
		directionMotor = direction;
		initialPositionMotor = initialPosition
	}

	// Métodos
	void configuration(){			// Configura os pinos
		pinMode(enableMotor,OUTPUT);
		pinMode(directionMotor,OUTPUT);
		pinMode(pwmMotor,OUTPUT);
	}

	void turnOnMotor(){			// Liga o motor
		digitalWrite(enableMotor,true);
	}

	void turnOffMotor(){			// Desliga o motor
		digitalWrite(enableMotor,false);
	}

	void rotationDirection(bool dir){	// Configura o sentido de rotação
		digitalWrite(directionMotor,dir);
	}

	void setVelocity(byte pwm){		// Configura a velocidade do motor
		analogWrite(pwmMotor, pwm);
	}	
}