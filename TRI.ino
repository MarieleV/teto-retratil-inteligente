#include <Servo.h>

Servo meuServo;
int pinoSensor = 8; // O fio roxo está no pino 8 (Sinal do Sensor de Chuva)
int pinoServo = 6;  // O fio laranja está no pino 6 (Sinal do Servo)

void setup() {
  pinMode(pinoSensor, INPUT);

  meuServo.attach(pinoServo);
  
  Serial.begin(9600);
}

void loop() {

  int estadoChuva = digitalRead(pinoSensor);
  
  if (estadoChuva == LOW) {
    Serial.println("Chuva detectada! (Sinal LOW) -> Fechando Teto...");
    meuServo.write(90); // Move o servo para 90 graus (simulando fechar)
  } else {
    Serial.println("Seco... (Sinal HIGH) -> Mantendo Aberto");
    meuServo.write(0);  // Retorna o servo para 0 graus (simulando abrir)
  }
  
  delay(500);
}