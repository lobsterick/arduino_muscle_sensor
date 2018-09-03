int emg = A0;
int dioda = 8;
int buzzer = 11;
int odczyt;
int odczytMin = 1023;
int odczytMax = 0;
int polowaEKG = 0;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);

  /// PROCEDURA KALIBRACJI

  digitalWrite(dioda, HIGH);
  while (millis() < 5000) {
    odczyt = analogRead(emg);

    if (odczyt > odczytMax) {
      odczytMax = odczyt;
    }

    if (odczyt < odczytMin) {
      odczytMin = odczyt;
    }
  }

  digitalWrite(dioda, LOW);
  polowaEKG = odczytMin + ((odczytMax - odczytMin) / 2);
}

void loop() {
 
  odczyt = analogRead(emg);
  if (odczyt > polowaEKG) {
      digitalWrite(dioda, HIGH);
      tone(buzzer, 1000);
    }
    else
    {
      digitalWrite(dioda, LOW);
      noTone(buzzer);
    }
    Serial.println(odczyt);
    delay(1);

  }
