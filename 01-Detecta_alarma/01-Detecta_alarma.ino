#define PIN_FOTOCELULA 2
#define PIN_BUZZER 13

boolean estado_anterior;
boolean estado_alarma;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_FOTOCELULA, INPUT); //LOW = puerta cerrada, HIGH = puerta abierta
  pinMode(PIN_BUZZER, OUTPUT);

  Serial.println("Arduino reseteado");

  estado_anterior = digitalRead(PIN_FOTOCELULA);
  estado_alarma = estado_anterior;  //si está abierta la puerta alerta inicialmente
  digitalWrite(PIN_BUZZER, estado_alarma);
  if (estado_alarma == true)
    Serial.println(String(millis()/1000.0) + " seg - ALARMA EN PUERTA!!");
}

void loop() {
  boolean estado_actual = digitalRead(PIN_FOTOCELULA);
  if (estado_actual != estado_anterior) {
    if (estado_actual == HIGH) {  //Flanco Ascendente y alarma detectada, linea blanca
      estado_alarma = true;
      digitalWrite(PIN_BUZZER, HIGH);
      Serial.println(String(millis()/1000.0) + " seg - ALARMA EN PUERTA!!");
    }
    else {  //Flanco descendente y alarma recuperada, linea negra
      estado_alarma = false;
      digitalWrite(PIN_BUZZER, LOW);
      Serial.println(String(millis()/1000.0) + " seg - ALARMA RECUPERADA");
    }
    estado_anterior = estado_actual;
  }
  delay(20);  //Solo para demo
}
