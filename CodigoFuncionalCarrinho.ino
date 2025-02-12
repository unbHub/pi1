#include <Arduino.h>

// Pinos do sensor infravermelho
const int digitalPin1 = 4; //esquerda
const int digitalPin =5; //direita


// Pinos do HC-SR04
const int trigPin = 3; // Trigger conectado ao pino digital 3
const int echoPin = 2; // Echo conectado ao pino digital 4

#define ENABLE_A 6     
#define MOTOR_A_IN1 7  
#define MOTOR_A_IN2 8  
#define MOTOR_B_IN3 9
#define MOTOR_B_IN4 10
#define ENABLE_B 11

const unsigned long TEMPO_ROTACAO_MAX = 10;


void setup() {
  // Configuração dos pinos
  pinMode(digitalPin1, INPUT);
  pinMode(digitalPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
    pinMode(ENABLE_A, OUTPUT);
    pinMode(MOTOR_A_IN1, OUTPUT);
    pinMode(MOTOR_A_IN2, OUTPUT);
    pinMode(MOTOR_B_IN3, OUTPUT);
    pinMode(MOTOR_B_IN4, OUTPUT);
    
    // Inicializa os pinos
    digitalWrite(MOTOR_A_IN1, LOW);
    digitalWrite(MOTOR_A_IN2, LOW);
    digitalWrite(MOTOR_B_IN3, LOW);
    digitalWrite(MOTOR_B_IN4, LOW);

  // Inicializar comunicação serial
  Serial.begin(9600);
}

void loop() {
  bool flag = false;

  // Leitura do sensor infravermelho
  int digitalValue1 = digitalRead(digitalPin1);
  int digitalValue = digitalRead(digitalPin);
  // Leitura do sensor HC-SR04
  float duration;
  float distance;

  // Enviar pulso para o Trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Ler o tempo do Echo
  duration = pulseIn(echoPin, HIGH);

  // Calcular distância em centímetros
  distance = duration * 0.034 / 2;

    if(digitalValue1 && digitalValue){
      stop();
      re();
      re();
      Serial.print("Entrei no primeiro if\n");

    }

    //Serial.print(digitalValue);
    //Serial.print(digitalValue1);

    if(digitalValue1 && (flag == false)) {
      flag = true;
      unsigned long inicio = millis();

      do {
        esquerda();
        Serial.print("loop da esquerda\n");
        Serial.print(digitalValue);
        Serial.print("\n");
        digitalValue = digitalRead(digitalPin);
      } while(!digitalValue && millis() - inicio < TEMPO_ROTACAO_MAX);
      re();
      re();

    }

     if(digitalValue && (flag == false)) {
      flag = true;
      unsigned long inicio = millis();

      do {
        direita();
        Serial.print("loop da direita aaaaaa\n");
        Serial.print(digitalValue1);
        Serial.print("\n");
        digitalValue1 = digitalRead(digitalPin1);
      } while(!digitalValue1 && millis() - inicio < TEMPO_ROTACAO_MAX);
      re();
      re();
    }  
    if(distance < 70 && !digitalValue && !digitalValue1){
      andarprafrente();
    }
    else {
      direita();
    }
    
    
  // Exibir os resultados no monitor serial
  Serial.print("infravermelho esquerda: ");
  Serial.print(digitalValue1);
  Serial.print("infravermelho direita: ");
  Serial.print(digitalValue);
  Serial.print(" | distancia objeto: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1); // Aguardar meio segundo entre leituras
}

void andarprafrente() {
    // Teste motor: sentido horário
    digitalWrite(MOTOR_A_IN1, HIGH);
    digitalWrite(MOTOR_A_IN2, LOW);
    analogWrite(ENABLE_A, 255); // Velocidade máxima

    digitalWrite(MOTOR_B_IN3, LOW);
    digitalWrite(MOTOR_B_IN4, HIGH);
    analogWrite(ENABLE_B, 255); // Velocidade máxima  
}

void stop(){
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, LOW);
  delay(1);
}

void re(){
    digitalWrite(MOTOR_A_IN1, LOW);
    digitalWrite(MOTOR_A_IN2, HIGH);
    analogWrite(ENABLE_A, 255);

    digitalWrite(MOTOR_B_IN3, HIGH);
    digitalWrite(MOTOR_B_IN4, LOW);
    analogWrite(ENABLE_B, 255);
    delay(1500);
}

void direita(){
    digitalWrite(MOTOR_A_IN1, HIGH);
    digitalWrite(MOTOR_A_IN2, LOW);
    analogWrite(ENABLE_A, 255); // Velocidade máxima

    digitalWrite(MOTOR_B_IN3,HIGH);
    digitalWrite(MOTOR_B_IN4, LOW);
    analogWrite(ENABLE_B, 255); // Velocidade máxima
    delay(1); // Motor gira por 10 segundos

}
void esquerda(){
    digitalWrite(MOTOR_A_IN1, LOW);
    digitalWrite(MOTOR_A_IN2, HIGH);
    analogWrite(ENABLE_A, 255); // Velocidade máxima

    digitalWrite(MOTOR_B_IN3,LOW);
    digitalWrite(MOTOR_B_IN4, HIGH);
    analogWrite(ENABLE_B, 255); // Velocidade máxima
    delay(1); // Motor gira por 10 segundos

}