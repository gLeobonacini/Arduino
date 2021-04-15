// Constanstes do programa
// Pinos Encoder
#define encoderPinA     2     // A -> Pino 2
#define encoderPinB     3     // B -> Pino 3
// Leitura direta do rbarramenta
#define readPinA        bitRead(PIND,2)
#define readPinB        bitRead(PIND,3)
// Tempo de Aquisição
#define tempoAquisicao  1000

// Variáveis do programa
volatile long int contadorPassos = 0;
long int contadorProtegido = 0;
long int tempoInicial = 0;
long int tempoAtual = 0;
long int tempoDecorrido = 0;

void setup() {
  // Definindo a velocidade da comunicação serial
  Serial.begin(115200);
  // Definindo as entradas com um resistor de Pull Up
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  // Configurando as interrupções
  attachInterrupt(digitalPinToInterrupt(encoderPinA),isrA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB),isrB, CHANGE);
}

void loop() {
  noInterrupts();
  contadorProtegido = contadorPassos;
  Serial.print("Passos: ");
  Serial.println(contadorProtegido);
  contadorPassos = 0;
  tempoInicial = millis();
  interrupts();
  do{
    tempoAtual = millis();
    if(tempoAtual < tempoInicial){
      tempoDecorrido = 4294967295 - tempoInicial + tempoAtual;
    }
    else{
      tempoDecorrido = tempoAtual - tempoInicial;
    }
  }while(tempoDecorrido < tempoAquisicao);
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
