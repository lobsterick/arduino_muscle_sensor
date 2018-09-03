int emg = A0;
int dioda = 13;
int odczyt;
int odczytMin = 1023;
int odczytMax = 0;
int polowaEKG = 0;
int stara_wartosc = 0;
int nowa_wartosc = 0;
int pik = 0;
int tetno = 0;
long startTime = 0;

void setup() {
  pinMode(dioda, OUTPUT);
  pinMode(emg, INPUT);
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
 
 startTime = millis();
 while (millis() < startTime + 10000){
  stara_wartosc = nowa_wartosc;
  nowa_wartosc = analogRead(emg);
  if(stara_wartosc<polowaEKG && nowa_wartosc>=polowaEKG){
    pik=pik+1;
    digitalWrite(dioda,HIGH);
    delay(2);
    digitalWrite(dioda,LOW);
    //Serial.println("PYK");
  }
 }
tetno = pik*6/2;
Serial.print("Twoje tętno wynosi: ");
Serial.print(tetno);
Serial.println(" uderzeń na minutę");
pik = 0;
startTime = 0;
delay(1000);
  }
