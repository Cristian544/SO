//dev: Cristian Hernandez
//variables

int led1_red = 5;
int led1_green = 6;
int led1_blue = 7;

int led2_red = 8;
int led2_green = 9;
int led2_blue = 10;

int led3_red = 11;
int led3_green = 12;
int led3_blue = 13;

#define switch_1 2



void setup() {
    pinMode(led1_red, OUTPUT);
    pinMode(led1_green, OUTPUT);
    pinMode(led1_blue, OUTPUT);

    pinMode(led2_red, OUTPUT);
    pinMode(led2_green, OUTPUT);
    pinMode(led2_blue, OUTPUT);

    pinMode(led3_red, OUTPUT);
    pinMode(led3_green, OUTPUT);
    pinMode(led3_blue, OUTPUT);
  
    pinMode(switch_1, INPUT);
  
   Serial.begin(9600);
}



//funciones

void led1_colors(int r, int g, int b) {
    analogWrite(led1_red, r);
    analogWrite(led1_green, g);
    analogWrite(led1_blue, b);
}

void led2_colors(int r, int g, int b) {
    analogWrite(led2_red, r);
    analogWrite(led2_green, g);
    analogWrite(led2_blue, b);
}

void led3_colors(int r, int g, int b) {
    analogWrite(led3_red, r);
    analogWrite(led3_green, g);
    analogWrite(led3_blue, b);
}

void trafic_1() {
    led1_colors(255, 0, 0);
    delay(1500);
    led1_colors(255, 0, 255);
    delay(1500);
    led1_colors(0, 0, 255);
}

void trafic_2() {
    led2_colors(255, 0, 0);
    delay(1500);
    led2_colors(255, 0, 255);
    delay(1500);
    led2_colors(0, 0, 255);
}

void trafic_3() {
    led3_colors(255, 0, 0);
    delay(1500);
    led3_colors(255, 0, 255);
    delay(1500);
    led3_colors(0, 0, 255);
}

void estrover() {
    for (int i = 0; i < 2; i++) { 
        led1_colors(255, 0, 255);
        led2_colors(255, 0, 255);
        led3_colors(255, 0, 255);
        delay(500);
        led1_colors(0, 0, 0);
        led2_colors(0, 0, 0);
        led3_colors(0, 0, 0);
        delay(500);
    }
}



void loop() {
    int statu = digitalRead(switch_1);

    if (statu == HIGH) {
        while (digitalRead(switch_1) == HIGH) {
            if (digitalRead(switch_1) == LOW) break;
          
            Serial.println("semaforo 1 esta en verde, semaforos 2 y 3 en rojo.");
            trafic_1(); 
            led2_colors(255, 0, 0); 
            led3_colors(255, 0, 0); 
            delay(500);

            // Verificar si el interruptor se apagao
            if (digitalRead(switch_1) == LOW) break;

            Serial.println("semaforo 2 en verde, semaforos 1 y 3 en rojo.");
            trafic_2(); 
            led1_colors(255, 0, 0); 
            led3_colors(255, 0, 0); 
            delay(500);

            // Verificar si el interruptor se apago
            if (digitalRead(switch_1) == LOW) break;

            Serial.println("semaforo 3 en verde, semaforos 1 y 2 en rojo.");
            trafic_3(); 
            led1_colors(255, 0, 0); 
            led2_colors(255, 0, 0); 
            delay(500);

            // Verificar si el interruptor se apago
            if (digitalRead(switch_1) == LOW) break;
        }
    } else {
        Serial.println("Interruptor apagado. Los LEDS parpadean de color amarillo.");
        estrover();
    }
}
