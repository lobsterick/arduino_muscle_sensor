int emgL = A0, emgP = A5; //piny czujników EMG
int odczytL, odczytP; //zmienna odczytowa
int stara_wartoscL, stara_wartoscP, nowa_wartoscP, nowa_wartoscL, polowaEKGL = 0, polowaEKGP = 0;
int odczytMinL = 1023, odczytMinP = 1023, odczytMaxL = 0, odczytMaxP = 0; //zmienne kalibracyjne
long timeNow = 0; // zmienna do przechowywania czasu
int punkty = 0; // do przechowywania liczby punktów pomiędzy przejsciem BOMBY
int zapalona_dioda = 0; // przechowywanie miejsca zapalonej bomby

int zapalona_dioda_poczatek = 6;
int points4move = 5;

void odliczanie(int liczebnik, int czas) {
  for (int p = liczebnik; p > -1; p--) {
    Serial.println(p);
    delay(czas);
  }
}

void mrugaj (int dioda, int ilosc, int dlugosc) {
  for (int i = 0; i < ilosc + 1; i++) {
    digitalWrite(dioda, HIGH);
    delay(dlugosc);
    digitalWrite(dioda, LOW);
    delay(dlugosc);
  }
}

void zapal_wszystkie_diody(int czas) {
  for (int i = 2; i < 11; i++) {
    digitalWrite(i, HIGH);
    delay(czas);
    digitalWrite(i, LOW);
  }
}


void setup() {
  // ustawienie trybu OUTPUT dla wszystkich diod
  for (int i = 2; i < 11; i++) {
    pinMode(i, OUTPUT);
  }

  //ustawienie trybu INPUT dla sensorów EMG
  pinMode(emgL, INPUT);
  pinMode(emgP, INPUT);

  //rozpoczęcie komunikacji z komputerem
  Serial.begin(9600);

  delay(5000); // potrzebny, bu zdążyć uruchomić Monitor Szeregowy
  Serial.println("Witajcie w GRZE 'BOMBA!'. Za chwile nastąpi kalibracja układu");
  delay(3000);

  /// PROCEDURA KALIBRACJI STAR
  Serial.println("Procedura kalibracji polega na kilkukrotnym napięciu mięśnia, by program mógł znaleźć wartości graniczne jego działania. Macie na to 10 sekund.");
  delay(1000);
  Serial.println("Gotowi?");
  delay(1000);
  Serial.println("KALIBRACJA START");
  digitalWrite(3, HIGH);
  digitalWrite(9, HIGH);

  float timeNow = millis();
  while (millis() < timeNow + 10000)
  {
    odczytL = analogRead(emgL);
    odczytP = analogRead(emgP);

    if (odczytL > odczytMaxL) {
      odczytMaxL = odczytL;
    }

    if (odczytP > odczytMaxP) {
      odczytMaxP = odczytP;
    }

    if (odczytL < odczytMinL) {
      odczytMinL = odczytL;
    }

    if (odczytP < odczytMinP) {
      odczytMinP = odczytP;
    }

    delay(50);
  }

  polowaEKGL = odczytMinL + ((odczytMaxL - odczytMinL) / 2);
  polowaEKGP = odczytMinP + ((odczytMaxP - odczytMinP) / 2);

  Serial.println("Kalibracja ZAKOŃCZONA");
  Serial.print("Wartości Lewy i Prawy MIN: ");
  Serial.print(odczytMinL);
  Serial.print(" oraz ");
  Serial.println(odczytMinP);
  delay(200);
  Serial.print("Wartości Lewy i Prawy MAX: ");
  Serial.print(odczytMaxL);
  Serial.print(" oraz ");
  Serial.println(odczytMaxP);
  delay(200);
  Serial.print("Wartości Lewy i Prawy polowaEKG ");
  Serial.print(polowaEKGL);
  Serial.print(" oraz ");
  Serial.println(polowaEKGP);
  delay(200);

  digitalWrite(3, LOW);
  digitalWrite(9, LOW);
  delay(3000);

  Serial.println("Gra polega na powodowaniu jak najszybszego i najmocniejszego skurczu w zadanym mięśniu, by przepchnąć bombę (reprezentowaną przez szereg diód) w stronę Rywala.");
  delay(500);
  Serial.println("Osoba, u której bomba wybuchnie ... przegrywa.");
  delay(500);
  Serial.println("Pamiętaj - znajdź swój własny sposób najefektywniejszego przepychania bomby w stronę rywala!");
  delay(5000);

  Serial.println("Gra rozpocznie się za...");
  odliczanie(10, 1000);
  Serial.println("START");
  zapal_wszystkie_diody(200);

  zapalona_dioda = zapalona_dioda_poczatek;
  digitalWrite(zapalona_dioda, HIGH);
}

void loop() {

  stara_wartoscL = nowa_wartoscL;
  stara_wartoscP = nowa_wartoscP;
  nowa_wartoscL = analogRead(emgL);
  nowa_wartoscP = analogRead(emgP);
  if (stara_wartoscL < polowaEKGL && nowa_wartoscL >= polowaEKGL) {
    punkty++;
    Serial.println("Punkt dla LEWEGO");
    delay(30);
  }
  if (stara_wartoscP < polowaEKGP && nowa_wartoscP >= polowaEKGP) {
    punkty--;
    Serial.println("Punkt dla PRAWEGO");
    delay(30);
  }
  if (punkty < -points4move) {
    digitalWrite(zapalona_dioda, LOW);
    zapalona_dioda++;
    Serial.println("Bomba W LEWO!");
    digitalWrite(zapalona_dioda, HIGH);
    punkty = 0;
    if (zapalona_dioda == 10)
    {
      mrugaj(zapalona_dioda, 4, 500);
      Serial.println("Wygrał PRAWY");
    }
  }
  if (punkty > points4move) {
    digitalWrite(zapalona_dioda, LOW);
    zapalona_dioda--;
    Serial.println("Bomba W PRAWO!");
    digitalWrite(zapalona_dioda, HIGH);
    punkty = 0;
    if (zapalona_dioda == 2)
    {
      mrugaj(zapalona_dioda, 4, 500);
      Serial.println("Wygrał LEWY");
    }
  }
}
