#include <Servo.h>

//DEKLARACJA ZMIENNYCH
int emg = A0;
int i = 0;
int odczyt;
int odczytMin = 1023;
int odczytMax = 0;
int pierwotny;
int odczytM;
Servo servoPoziom; //UTWORZENIE OBIEKTU TYPU SERVO

void setup() {
  servoPoziom.attach(3);
  Serial.begin(9600); //OTWARCIE PORTU SZEREGOWEGO
  pinMode(A0, INPUT); // WEJŚCIE EMG
  pinMode(2, OUTPUT); //WYJŚCIE DIODY LEWEJ
  pinMode(4, OUTPUT); // WYJŚCIE DIODY PRAWEJ

  /// **ROZPOCZĘCIE PROCEDURY KALIBRACJI**

  // WŁĄCZENIE DIOD LED
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);

  //SZUKANIE WARTOŚCI PROGOWYCH ODCZYTÓW
  while (millis() < 10000) {
    odczyt = analogRead(emg);

    if (odczyt > odczytMax) {
      odczytMax = odczyt;
    }

    if (odczyt < odczytMin) {
      odczytMin = odczyt;
    }
  }

  // WYŁĄCZENIE DIOD LED
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);

  // WYSŁANIE DO MONITORA SZEREGOWEGO WARTOŚCI ZAKRESU KALIBRACJI
  Serial.println("Wartosci zakresu kalibracji: ");
  Serial.println("Wartosc minimalna: ");
  Serial.println(odczytMin);
  Serial.println("Wartosc maksymalna: ");
  Serial.println(odczytMax);

  /// ** KONIEC PROCEDURY KALIBRACJI **

  servoPoziom.write(80); //USTAWIENIE SERWOMECHANIZMU W ŚRODKOWEJ POZYCJI
}

void loop() {
  /// PROCEDURA ODCZYTU WARTOŚCI I JEJ RÓŻNICOWANIA
  odczyt = analogRead(emg);
  pierwotny = odczyt;
  odczyt = map(odczyt, odczytMin, odczytMax, 0, 2);
  odczyt = constrain (odczyt, 0, 2);
  Serial.println(odczyt);

  // BADANIE 30 KOLEJNYCH WARTOŚCI CELEM ZNALEZIENIA WARTOŚCI MAKSYMALNEJ
  for (i = 0; i < 30; i++)
  {
    if (odczyt > odczytM) {
      odczytM = odczyt;
    }
  }

  // PROCEDURA USTAWIANIA SERWOMECHANIZMU
  if (odczytM == 0)
  {
    delay(10);
  }
  else
  {
    if (odczytM == 2)
    {
      servoPoziom.write(10);
      digitalWrite(4, HIGH);
      digitalWrite(2, LOW);
      delay(500);
    }
    else
    {
        servoPoziom.write(170);
        digitalWrite(2, HIGH);
        digitalWrite(4, LOW);
        delay(500);
      }
    }
  delay(100); // CZASOWE OPÓŹNIENIE
  odczytM = 0; //ZEROWANIE ZMIENNEJ POMIAROWEJ
}
