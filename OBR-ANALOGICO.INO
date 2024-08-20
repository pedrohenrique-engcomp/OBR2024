int Sensor1 = 2;
int Valor_Sensor1 = 0; 
int Sensor2 = 3; 
int Valor_Sensor2 = 0;
int Valor_Corte = 60;

//Definição dos pinos de controle do motor
int M1 = 9; // Pino_Velocidade 1º Motor ( 0 a 255)_ Porta IN2 ponte H;
int M2 = 11; //Pino_Velocidade 2º Motor ( 0 a 255) _ Porta IN4 ponte H;
int dir1 = 8; //Pino_Direção do 1º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN1 ponte H;
int dir2 = 10; //Pino_Direção do 2º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN3 ponte H;

//variável responsável por controlar a velocidade dos motores
int velocidade = 155;

void setup(){
  Serial.begin(9600);
  
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);

  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW); 
}

void loop(){
  Valor_Sensor1 = analogRead(Sensor1); 
  Valor_Sensor2 = analogRead(Sensor2); 
  Serial.print("Sensor 1 = ");
  Serial.print(Valor_Sensor1);
  Serial.print(" | ");
  Serial.print("Sensor 2 = ");
  Serial.println(Valor_Sensor2);
  delay(250);

  if((Valor_Sensor1 > Valor_Corte) && (Valor_Sensor2 > Valor_Corte)){
    analogWrite(M1, 150); 
    analogWrite(M2, 150);
  }
  
  if((Valor_Sensor1 < Valor_Corte) && (Valor_Sensor2 > Valor_Corte)){
    analogWrite(M1, 0); 
    analogWrite(M2, 200);
  }
  
  if((Valor_Sensor1 > Valor_Corte) && (Valor_Sensor2 < Valor_Corte)){
    analogWrite(M1, 200); 
    analogWrite(M2, 0);
  }  

  if((Valor_Sensor1 < Valor_Corte) && (Valor_Sensor2 < Valor_Corte)){
    analogWrite(M1, 0); 
    analogWrite(M2, 0);
  } 
  } 
}
