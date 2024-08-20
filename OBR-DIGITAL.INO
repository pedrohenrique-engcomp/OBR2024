int pin_S2 = 3; // Defina o número do pino ao qual o sensor está conectado
int pin_S1 = 4; // Defina o número do pino ao qual o sensor está conectado

//Definição dos pinos de controle do motor
int M1 = 9; // Pino_Velocidade 1º Motor ( 0 a 255)_ Porta IN2 ponte H;
int M2 = 11; //Pino_Velocidade 2º Motor ( 0 a 255) _ Porta IN4 ponte H;
int dir1 = 8; //Pino_Direção do 1º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN1 ponte H;
int dir2 = 10; //Pino_Direção do 2º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN3 ponte H;

//variável responsável por controlar a velocidade dos motores
int velocidade = 155;

//const int trigPin = A2;  // Porta Trigger do sensor ultrassônico
//const int echoPin = A3;  // Porta Echo do sensor ultrassônico


void setup() {
  Serial.begin(9600);
  pinMode(pin_S2, INPUT); // Configura o pino como entrada
  pinMode(pin_S1, INPUT); // Configura o pino como entrada
  
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);

  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW); 

  // Definindo as portas do sensor ultrassônico
  //pinMode(trigPin, OUTPUT);
  //pinMode(echoPin, INPUT);
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
  //long duracao, distancia;
  
  // Limpando o trigPin
  //digitalWrite(trigPin, LOW);
  //delayMicroseconds(2);
  
  // Configurando o trigPin para HIGH por 10 microsegundos
  //digitalWrite(trigPin, HIGH);
  //delayMicroseconds(10);
  //digitalWrite(trigPin, LOW);

  // Leitura do tempo de retorno do som (echoPin)
  // duracao = pulseIn(echoPin, HIGH);

  // Calculando a distância em centímetros
  //distancia = duracao * 0.034 / 2;

  // Imprimindo a distância no monitor serial
  //Serial.print("Distância: ");
  //Serial.print(distancia);
  //Serial.println(" cm");

  // Verificando a presença de obstáculos
  //if (distancia < 20) {  // Se houver um obstáculo a menos de 20 cm
   // digitalWrite(dir1, LOW);
   // digitalWrite(dir2, LOW);      // Para os motores
  //}
  
  //Aqui está toda a lógica de comportamento do robô: Para a cor branca atribuímos o valor 0 e, para a cor preta, o valor 1.
  if((Sensor1 == 0) && (Sensor2 == 0)){ // Se detectar na extremidade das faixas duas cores brancas
      analogWrite(M2, velocidade); // Ambos motores ligam na mesma velocidade
      analogWrite(M1, velocidade);
  }

  if((Sensor1 == 1) && (Sensor2 == 0)){ // Se detectar um lado preto e o outro branco
      analogWrite(M2, 0); // O motor 1 desliga
      analogWrite(M1, velocidade); // O motor 2 fica ligado, fazendo assim o carrinho virar
  }

  if((Sensor1 == 0) && (Sensor2 == 1)){ // Se detectar um lado branco e o outro preto
      analogWrite(M2, velocidade); //O motor 1 fica ligado
      analogWrite(M1, 0); // O motor 2 desliga, fazendo assim o carrinho virar no outro sentido
}

  if((Sensor1 == 1) && (Sensor2 == 1)){ // Se detectar um lado branco e o outro preto
      analogWrite(M1, 0); //O motor 1 fica ligado
      analogWrite(M2, 0); // O motor 2 fica ligado
}
}
