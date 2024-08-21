int pin_S2 = 4; // Defina o número do pino ao qual o sensor está conectado
int pin_S1 = 3; // Defina o número do pino ao qual o sensor está conectado

//Definição dos pinos de controle do motor
const int M1_frente = A0; //  1º Motor Esquerdo Para frente ( 0 a 255)_ Porta IN2 ponte H;
const int M2_frente = A2; //2º Motor Direito Para frente ( 0 a 255 _ Porta IN4 ponte H;
const int M1_tras = A1; //1º Motor Para trás ( 0 a 255) porta IN1 ponte H;
const int M2_tras = A3; //2º Motor Para trás ( 0 a 255)_ porta IN3 ponte H;

//variável responsável por controlar a velocidade dos motores
int velocidade = 155;

int trigPin = 6;  // Porta Trigger do sensor ultrassônico
int echoPin = 5;  // Porta Echo do sensor ultrassônico


void setup() {
  Serial.begin(9600);
  //Sensor
  pinMode(pin_S2, INPUT); // Configura o pino como entrada
  pinMode(pin_S1, INPUT); // Configura o pino como entrada
  
  // Definindo as portas do sensor ultrassônico
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
  bool Sensor2 = digitalRead(pin_S2); // Lê o valor do sensor
  bool Sensor1 = digitalRead(pin_S1); // Lê o valor do sensor
  Serial.print("Esquerdo: ");
  Serial.println(Sensor1);
  Serial.print("Direito: ");
  Serial.println(Sensor2);
  delay(250);

  // Medindo a distância com o sensor ultrassônico
  long duracao, distancia;
  
  // Limpando o trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Configurando o trigPin para HIGH por 10 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leitura do tempo de retorno do som (echoPin)
  duracao = pulseIn(echoPin, HIGH);
   
  // Calculando a distância em centímetros
  distancia = duracao * 0.034 / 2;

  // Imprimindo a distância no monitor serial
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Verificando a presença de obstáculos
  //if (distancia < 20) {  // Se houver um obstáculo a menos de 20 cm
  //   analogWrite(M1_frente, 0); 
  //   analogWrite(M2_frente, 0); 
  //   delay(1000);
  //   analogWrite(M1_frente, 0); 
  //   analogWrite(M2_frente, velocidade); 
  //   delay(110);
  //   analogWrite(M1_frente, velocidade); 
  //   analogWrite(M2_frente, velocidade); 
  //   delay(1000);
  //   analogWrite(M1_frente, velocidade); 
  //   analogWrite(M2_frente, 0);
  //   delay(110);
  //   analogWrite(M1_frente, velocidade); 
  //   analogWrite(M2_frente, velocidade);
  //   delay(2000);
  //   analogWrite(M1_frente, velocidade); 
  //   analogWrite(M2_frente, 0);
  //   delay(110);
  //   analogWrite(M1_frente, velocidade); 
  //   analogWrite(M2_frente, velocidade); 
  //   delay(1000);
  //   analogWrite(M1_frente, 0); 
  //   analogWrite(M2_frente, velocidade); 
  //   delay(110);
  //}
  
  //Aqui está toda a lógica de comportamento do robô: Para a cor branca atribuímos o valor 0 e, para a cor preta, o valor 1.
  if((Sensor1 == 0) && (Sensor2 == 0)){ // Se detectar na extremidade das faixas duas cores brancas
      delay(500);
      analogWrite(M1_frente, velocidade); // Ambos motores ligam na mesma velocidade
      analogWrite(M2_frente, velocidade);
      analogWrite(M1_tras, 0); 
      analogWrite(M2_tras, 0);
      delay(500);
  }

  if((Sensor1 == 1) && (Sensor2 == 0)){ // Se detectar um lado preto e o outro branco
      delay(500);
      analogWrite(M2_frente, 0); // O motor 1 desliga
      analogWrite(M1_frente, velocidade); // O motor 2 fica ligado, fazendo assim o carrinho virar
      analogWrite(M1_tras, 0); 
      analogWrite(M2_tras, 0);
      delay(500);
  }

  if((Sensor1 == 0) && (Sensor2 == 1)){ // Se detectar um lado branco e o outro preto
      delay(500);
      analogWrite(M2_frente, velocidade); //O motor 1 fica ligado
      analogWrite(M1_frente, 0); // O motor 2 desliga, fazendo assim o carrinho virar no outro sentido
      analogWrite(M1_tras, 0); 
      analogWrite(M2_tras, 0);
      delay(500);
  }
  
  
  //if((Sensor1 == 1) && (Sensor2 == 1)){ // Se detectar 2 lados pretos
   //   analogWrite(M1_frente, 0); //O motor 1 fica desligado
   //   analogWrite(M2_frente, 0); // O motor 2 fica desligado
   
//}
}
