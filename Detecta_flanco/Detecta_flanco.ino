#define PIN_MICRORRUPTOR 2
#define PIN_RELE 13

boolean estado_anterior;
boolean estado_rele = LOW;  //Empieza Apagado

void setup() {
  Serial.begin(9600);
  pinMode(PIN_MICRORRUPTOR, INPUT_PULLUP); //Conectado pin al común y NC a GND. Abierto lee 0, cerrado lee 1 Arduino con esta configuración
  pinMode(PIN_RELE, OUTPUT);

  estado_anterior = digitalRead(PIN_MICRORRUPTOR);
  digitalWrite(PIN_RELE, estado_rele);
}

void loop() {
  boolean estado_actual = digitalRead(PIN_MICRORRUPTOR);
  Serial.print(String(estado_anterior) + "," + String(estado_actual) + ",");
  if (estado_actual != estado_anterior) {
    if (estado_actual == HIGH) {  //Flanco Ascendente
      estado_rele = !estado_rele;
      digitalWrite(PIN_RELE, estado_rele);
    }
    estado_anterior = estado_actual;
  }
  Serial.println(estado_rele*3);
  delay(20);
}
