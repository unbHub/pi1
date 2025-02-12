### **1. Testes Unitários**

#### **1.1. Sensores Infravermelhos**

```cpp
void testSensorInfravermelho() {
  Serial.println("Teste Sensor Infravermelho");

  bool detection = digitalRead(digitalPin1);
  if (detection) {
    Serial.println("Detecção de borda bem-sucedida.");
  } else {
    Serial.println("Falha na detecção de borda.");
  }

  delay(100); // Tempo para simular diferentes condições
}
```

- **Procedimentos:**
  1. Coloque o sensor sobre as superfícies especificadas.
  2. Leia os valores de `digitalPin1` e `digitalPin`.
  3. Documente se o valor do sensor corresponde ao esperado (HIGH para bordas).

---

#### **1.2. Sensor Ultrassônico**

```cpp
void testUltrasonicSensor() {
  Serial.println("Teste Sensor Ultrassônico");

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  Serial.print("Distância medida: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= 30) {
    Serial.println("Distância dentro do intervalo aceitável.");
  } else {
    Serial.println("Distância fora do intervalo.");
  }
}
```

- **Procedimentos:**
  1. Meça distâncias conhecidas (10cm, 20cm, 30cm) e verifique o erro.
  2. Teste materiais diferentes para verificar a consistência da detecção.

---

#### **1.3. Motores**

```cpp
void testMotors() {
  Serial.println("Teste de Motores");

  analogWrite(ENABLE_A, 150);
  analogWrite(ENABLE_B, 150);

  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);

  digitalWrite(MOTOR_B_IN3, LOW);
  digitalWrite(MOTOR_B_IN4, HIGH);

  delay(2000); // Testa movimento por 2 segundos

  stop(); // Verifica se o motor para corretamente

  Serial.println("Teste concluído.");
}
```

- **Procedimentos:**
  1. Teste diferentes valores de PWM (50, 100, 150, 255) e observe os resultados.
  2. Meça a capacidade de torque com peso adicional.

---

### **2. Testes de Integração**

#### **2.1. Sistema de Movimentação**

```cpp
void testMovement() {
  Serial.println("Teste de Movimentação");

  andarprafrente();
  delay(2000);

  direita();
  delay(2000);

  esquerda();
  delay(2000);

  stop();
  Serial.println("Teste de movimentação concluído.");
}
```

- **Procedimentos:**
  1. Verifique o movimento em linha reta por 2 metros e meça o desvio.
  2. Teste a precisão da rotação em 90° e 180°.

---

#### **2.2. Sistema de Detecção**

```cpp
void testDetectionIntegration() {
  Serial.println("Teste de Integração: Detecção");

  int irLeft = digitalRead(digitalPin1);
  int irRight = digitalRead(digitalPin);
  float distance;

  // Testa bordas
  if (irLeft || irRight) {
    Serial.println("Borda detectada!");
    stop();
  } else {
    Serial.println("Nenhuma borda detectada.");
  }

  // Testa o ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 30) {
    Serial.println("Oponente detectado!");
    andarprafrente();
  } else {
    Serial.println("Nenhum oponente detectado.");
  }
}
```

- **Procedimentos:**
  1. Simule bordas com superfícies pretas.
  2. Coloque objetos a diferentes distâncias para simular oponentes.

---

### **3. Testes Funcionais**

```cpp
void testStrategy() {
  Serial.println("Teste de Estratégia");

  // Simula bordas e oponentes
  int irLeft = digitalRead(digitalPin1);
  int irRight = digitalRead(digitalPin);
  float distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (irLeft || irRight) {
    Serial.println("Borda detectada, recuando...");
    re();
  } else if (distance < 30) {
    Serial.println("Oponente detectado, avançando...");
    andarprafrente();
  } else {
    Serial.println("Procurando oponente...");
    direita();
  }
}
```

- **Procedimentos:**
  1. Coloque o robô em uma arena com bordas e obstáculos simulando oponentes.
  2. Teste se ele reage conforme esperado para empurrar oponentes.

---

### **4. Roteiro de Testes**
1. Execute os testes unitários (1.1, 1.2, 1.3).
2. Realize os testes de integração (2.1, 2.2).
3. Teste a estratégia completa em um cenário realista.
4. Documente os resultados e ajuste o código conforme necessário.