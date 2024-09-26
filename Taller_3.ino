/*
    Arduino Sketch: Traffic Light
    Developer: Cristian Hernandez
    Date: 25/09/2024
 */

//Semaforo 1
const int red1 = 13;
const int yellow1 = 12;
const int green1 = 11;

// Semáforo 2
const int red2 = 10;
const int yellow2 = 9;
const int green2 = 8;

// Semáforo 3
const int red3 = 7;
const int yellow3 = 6;
const int green3 = 5;

// Semáforo 4
const int red4 = 4;
const int yellow4 = 3;
const int green4 = 2;


// Configuramos todos los pines como salida
void setup() {
  
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);

  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);

  pinMode(red3, OUTPUT);
  pinMode(yellow3, OUTPUT);
  pinMode(green3, OUTPUT);

  pinMode(red4, OUTPUT);
  pinMode(yellow4, OUTPUT);
  pinMode(green4, OUTPUT);
}

void loop() {
  // Fase 1: Semáforo 1 en verde, los demás en rojo
  digitalWrite(green1, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(red3, HIGH);
  digitalWrite(red4, HIGH);
  delay(5000);

  // Semáforo 1 en amarillo
  digitalWrite(green1, LOW);
  digitalWrite(yellow1, HIGH);
  delay(2000);

  // Fase 2: Semáforo 1 en rojo, semáforo 2 en verde
  digitalWrite(yellow1, LOW);
  digitalWrite(red1, HIGH);
  digitalWrite(red2, LOW);
  digitalWrite(green2, HIGH);
  delay(5000); 

  // Semáforo 2 en amarillo
  digitalWrite(green2, LOW);
  digitalWrite(yellow2, HIGH);
  delay(2000); 

  // Fase 3: Semáforo 2 en rojo, semáforo 3 en verde
  digitalWrite(yellow2, LOW);
  digitalWrite(red2, HIGH);
  digitalWrite(red3, LOW);
  digitalWrite(green3, HIGH);
  delay(5000); 

  // Semáforo 3 en amarillo
  digitalWrite(green3, LOW);
  digitalWrite(yellow3, HIGH);
  delay(2000); 

  // Fase 4: Semáforo 3 en rojo, semáforo 4 en verde
  digitalWrite(yellow3, LOW);
  digitalWrite(red3, HIGH);
  digitalWrite(red4, LOW);
  digitalWrite(green4, HIGH);
  delay(5000); 

  // Semáforo 4 en amarillo
  digitalWrite(green4, LOW);
  digitalWrite(yellow4, HIGH);
  delay(2000); 

  // Fase final: Semáforo 4 en rojo, reiniciar ciclo
  digitalWrite(yellow4, LOW);
  digitalWrite(red4, HIGH);
  digitalWrite(red1, LOW);
}
