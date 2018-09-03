<p align="center"> 
<img src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/Logo.png>
</p>

---

To repozytorium zawiera projekty wykonane z użyciem czujnika elektromiograficznego **Muscle Sensor v3** firmy *Advencer Technology*, wykorzystanego we współpracy z **Arduino Leonardo**.

# Spis treści
[//]: # (TOC Begin)
* [Wstęp teoretyczny](#wstęp-teoretyczny)
	* [Rys historyczny](#rys-historyczny)
	* [Budowa i działanie mięśni](#budowa-i-działanie-mięśni)
* [Elektromiografia](#elektromiografia)
	* [Opis badania](#opis-badania)
	* [Czynniki zakłócające](#czynniki-zakłócające)
	* [Wymagania sprzętowe oraz pomiarowe](#wymagania-sprzętowe-oraz-pomiarowe)
	* [Przygotowanie skóry do badania](#przygotowanie-skóry-do-badania)
	* [Dobór oraz umieszczenie elektrod](#dobór-oraz-umieszczenie-elektrod)
	* [Sensor elektromiograficzny firmy AT](#sensor-elektromiograficzny-firmy-at)
* [Projekty](#projekty)
	* [Układ sterowania serwomechanizmem](#układ-sterowania-serwomechanizmem)
		* [Podłączenie układu](#podłączenie-układu)
		* [Algorytm programu](#algorytm-programu)
		* [Opis działania](#opis-działania)
		* [Przykładowe odpowiedzi czujnika](#przykładowe-odpowiedzi-czujnika)
	* [EKG](#ekg)
	* [Czujnik pulsu](#czujnik-pulsu)
	* [Gra zręcznościowa EMG_BOMB](#gra-zręcznościowa-emg_bomb)

[//]: # (TOC End)


# Wstęp teoretyczny
W tej części opisane zostały podstawy naukowe działania elektromiografii. Jeśli jesteś zaznajomiony z tematem - możesz śmiało odpuścić tę część, chociaż brak znajomości zaprezentowanych poniżej zagadnień może uniemożliwić Ci zrozumienie niektórych z konceptów zaprezentowanych w późniejszych punktach tej dokumentacji.
## Rys historyczny
Nowożytne badania elektromiografii mają swój początek w XVII wieku, kiedy przyrodnik  Francesco Redi zauważył, że źródło sygnału elektrycznego pojawia się z tkanki mięśniowej, co zostało udowodnione ponad 100 lat później przez włoskiego fizyka, Luigiego Galvaniego. Od tej pory, kilkukrotnie prowadzone były badania na temat tego dziwnego zjawiska, ale dopiero DuBoisowi przypisuje się naukowe udowodnienie istnienia sygnału elektromiograficznego towarzyszącemu pracy mięśnia w roku 1849. Oczywiście, na ówczesne warunki wręcz niemożliwe było wykorzystanie tej wiedzy ze względu na brak właściwych przyrządów pomiarowych. Dopiero wynalezienie m.in. lampy katodowej, wzmacniacza lampowego oraz metalowych elektrod dało szansę na wyraźnie odczytanie sygnałów EMG pochodzących z mięśni. 
Naukowcami, którym udało się połączyć całą zdobytą wiedzę i od których zaczęło się poszukiwanie dróg na wykorzystanie całości dostępnej ówcześnie wiedzy na temat elektromiografii, byli Adrian oraz Bronk w 1929 roku. Nieocenionym i wartym uwagi wpływem były również prace Buchthala i jego współpracowników.

We wczesnych latach czterdziestych i pięćdziesiątych, kilka prac naukowych wskazywało na mocne powiązania pomiędzy amplitudą sygnału EMG oraz szybkością i siłą skurczu mięśniowego. Dopiero prace Inmana spowodowały większy i szerszy zakres badań skojarzonych nad kinezjologią i naukami pokrewnymi, pozwalając przy tym rozwinąć się mocno w latach sześćdziesiątych innej specjalizacji – protetyce. 
Naukowcom udało się zaprojektować górną kończynę sterowaną mioelektrycznie, co stało się możliwe dzięki postępującej miniaturyzacji komponentów elektronicznych oraz zmniejszaniu rozmiarów baterii zasilających układy. 
W następnym dziesięcioleciu zaczęły kształtować się podwaliny teoretyczne pod działanie elektromiografii w oparciu o wszelkie eksperymenty i obserwacje. W polu matematyki zarówno prace De Luca, opisujące właściwości czasowych parametrów sygnałów elektromiograficznych, jak i prace Lindstorma, zajmujące się częstotliwościowym odpowiednikiem sygnału, pozwoliły skupić się na bardziej technicznych aspektach projektowania sensorów EMG. Warto wspomnieć tutaj także o pracy Graupego i Clinego, którzy pracowali nad zastosowaniem średnie ruchomej w badaniach nt. wykorzystania informacji z sygnału EMG.

Okolice lat 1970-1980 były czasem prób zaciągnięcia najbardziej wyrafinowanych technik i algorytmów komputerowych, by wydobyć jak najwięcej przydatnych informacji z sygnału mięśniowego. Dzięki temu stało się możliwe badanie nawet pojedynczych włókien mięśniowych oraz badanie powierzchniowej czynności elektromiograficznej, głównie do opisu stanu funkcjonalnego mięśnia. Od 1990 roku rozwinęły się również zastosowania nowoczesnego przetwarzania sygnałów dla analizy i użytkowania sygnału mięśniowego. Dobrym przykładem może być tutaj analiza powierzchniowa czasowo-częstotliwościowa przy badaniu bólów w dolnych odcinkach pleców czy nawet analiza sygnału EMG w laryngologii.

## Budowa i działanie mięśni
Mięśnie są podstawowymi strukturalno-funkcjonalnymi elementami motorycznymi wyższych kręgowców i bezkręgowców, pozwalającymi wykonywać skoordynowane ruchy. Odpowiedzialne są również za pracę serca oraz utrzymanie wymaganej postawy ciała. Zbudowane są z tzw. <u>tkanki mięśniowej</u>, która wraz z układem szkieletowym inicjują ruch poprzez zmniejszanie i zwiększanie długości mięśnia (odpowiednio skurcz i rozkurcz) przy wykorzystaniu energii, której głównym źródłem jest **ATP** powstające w procesie oksydacji tłuszczy i cukrów lub w procesach beztlenowych. U człowieka, liczba mięśni waha się w granicach 450 do 500, co stanowi około 40% masy ciała męskiego lub 35% masy ciała damskiego. Wyróżniamy 3 rodzaje mięśni: <u>szkieletowe</u>, <u>sercowe</u> oraz <u>
gładkie</u>. Budowa przekrojowa mięśnia została przedstawiona poniżej.
</br></br>

<p align="center">
  <img width="700" height="400" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/ModelMiesnia.jpg>
</p>

Komórka mięśniowa posiada nieco odmienną budowę od reszty komórek ciała ludzkiego. **Różnicami, które nadają jej właściwości pozwalające na spełnianie swojej roli są m.in** cylindryczny,  mocno wydłużony kształt (przez co komórki mięśniowe nazywane są potocznie włóknami mięśniowymi), obecność w cytoplazmie mioglobiny (stanowiącej rezerwuar tlenowy dla mięśnia), wielojądrowość (w wyniku zespolenia się wielu komórek) oraz duży stopień wypełnienia komórki przez struktury zwane miofibrylami. Miofibryle, które stanowią o charakterze komórek mięśniowych, zbudowane są z dwóch rodzajów filamentów białkowych: aktynowych (cienkich) oraz miozynowych (grubych). Swoje nazwy natomiast zawdzięczają białkom, z których są zbudowane – odpowiednio aktyny oraz miozyny.
</br></br>

<p align="center">
  <img width="600" height="300" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/PrzekrojPoprzeczny.jpg>
</p>

Filamenty aktyny i miozyny są rozmieszczone naprzemiennie, lekko zachodząc na siebie, co widoczne jest w postaci grubszych i ciemniejszych filamentów miozynowych oraz jasnych i cienkich filamentów aktynowych.
</br></br>

<p align="center">
  <img width="700" height="300" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/Sarkomer.jpg>
</p>
</br></br>

**Ogólnie przyjętym modelem ruchu mięśniowego jest model ślizgowy, zaproponowany przez Hodgkina oraz Huxleya.** Podstawą ruchu jest w nim wzajemne „slizgowe” przemieszczanie się względem siebie w sarkomerze miozyny i aktyny, bez zmiany ich długości. <u>Możliwy jest on dzięki charakterystycznej budowie obydwu typów filamentów - więcej na ten temat można odnaleźć w [Wikipedii](https://pl.wikipedia.org/wiki/Skurcz_mi%C4%99%C5%9Bnia).</u>

**Wychodząc od powyższego modelu, można zauważyć iż biorą w nim udział cząstki nieobojętne elektrycznie oraz impulsy pochodzące z układu nerwowego.**

Pobudliwość włókien mięśniowych można wytłumaczyć na modelowym schemacie błony półprzepuszczalnej – poprzez badania właściwości elektrycznych. Potencjał spoczynkowy, tworzony przez równowagę jonową między częścią zewnętrzną i wewnętrzną komórki, wynosi około **-90mV**. Spowodowany jest on ciągłym podtrzymywaniem, na przekór siły wyrównywania gradientu oraz ładunku, przez pracę pompy sodowo-potasowej. W związku z ciągłą wymianą jonów, wewnątrz komórki nerwowej istnieje duże nagromadzenie jonów potasu, natomiast na zewnątrz od błony, istnieje duże stężenie jonów sodu. 
</br></br>

<p align="center">
  <img width="600" height="400" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/FazyPotencjaluCzynnosciowego.jpg>
</p>
</br></br>

Sytuacja ta zmienia się w momencie przekroczenia wartości potencjału **-55mV** – wtedy to otwierają się kanały bramkowane napięciem, umożliwiając napływ jonów sodowych do wnętrza komórki i podwyższenie potencjału na błonie komórkowej (etap depolaryzacji i wyładowania). Należy tutaj też wspomnieć, że wartość **-55mV** jest wartością ściśle graniczną, tj. dopiero jej przekroczenie uruchomi depolaryzację, natomiast zmiany mniejsze mogą spowodować jedynie małą, już nie tak gwałtowną zmianę, po której układ bardzo szybko powraca do stanu równowagi.  Sytuacja trwa do momentu osiągnięcia szczytu potencjału (jest to bardzo szybki proces, trwający nawet *0,5ms*), w którym kanał sodowy zamyka się, nie pozwalając wniknąć większej ilości jonów sodowych do komórki. Otwiera się natomiast inny kanał - również bramkowany napięciem - potasowy, który przeciwdziała efektowi polaryzacji, pozwalając na transport jonów potasu na zewnątrz komórki, zgodnie z gradientem stężeń oraz nowymi wartościami potencjałów. Jest to faza repolaryzacji. Wartości progowe obydwu kanałów bramkowych są podobne – różnica wynika z różnej dynamiki pracy. Cykl został przedstawiony schematycznie poniżej.
</br></br>

<p align="center">
  <img width="500" height="250" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/DepoRepo.jpg>
</p>
</br></br>

Powyższy sposób działania komórek nerwowych pokazuje podstawową drogę przekazywania informacji w organizmie – falę depolaryzacji. Jedna komórka ulegająca depolaryzacji może być przyczyną depolaryzacji komórki sąsiadującej (przy spełnieniu założenia przekroczenia progu **-55mV**), lecz nie jest to obligatoryjne. **Informacja przekazywana jest w przeważającej większości właśnie w powyższy sposób - czynnikiem różnicującym typ bodźca oraz przenoszoną informację jest częstotliwość**. 

# Elektromiografia
## Opis badania
Ideą badania elektromiograficznego jest badanie czynnościowe mięśni. Pomimo możliwości mierzenia impulsów czynnościowych każdej komórki, przedmiotem zainteresowania elektromiografii są wyłącznie mięśnie poprzecznie prążkowane.

Sygnał EMG powstaje w skutek procesów depolaryzacji i repolaryzacji. Szerokość strefy depolaryzacji, poruszającej się wzdłuż mięśnia, to około 1-3mm2, a jej prędkość to 2-5 m/s. Poniżej przedstawiono strefę depolaryzacji na błonie komórkowej mięśnia.
</br></br>

<p align="center">
  <img width="500" height="300" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/StrefaDepolaryzacji.jpg>
</p>
</br>

Fala depolaryzacyjna, formowana przez cykliczne depolaryzacje i repolaryzacje, przemieszcza się wzdłuż powierzchni mięśnia. Możemy ją zarejestrować poprzez użycie elektrod dwubiegunowych oraz wzmocnienie różnicowe.

</br>
<p align="center">
  <img width="500" height="300" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/PrzesuwanieDipola.jpg>
</p>

Zgodnie ze schematem, w punkcie T1 pojawia się potencjał czynnościowy przemieszczający się w kierunku pary elektrod, natomiast różnica potencjałów między elektrodami osiąga najwyższą wartość w punkcie T2. W momencie dotarcia dipola do punktu T3, nastąpi przecięcie przez potencjał linii zerowej i osiągnięcie maksimum w punkcje T2, który jest najbliżej drugiej elektrody. Na podstawie powyższego można stwierdzić, że jednobiegunowy potencjał czynnościowy tworzy dwubiegunowy sygnał podczas wzmocnienia różnicowego. Para elektrod rejestruje wszystkie unerwione włókna w pojedynczej jednostce motorycznej, a suma tych włókien z kolei składa się na trójfazowy **MUAP** (z ang. *„Motor Unit Action Potential”*) o różnym kształcie zależnym od miejsca przyłożenia elektrody. Przy użyciu elektrod powierzchniowych, w miejscu rejestracji sygnału MUAP nakładają się, tworząc zapis interferencyjny.

**Wynik sygnałowy otrzymywany z nakładania się sygnałów MUAP, nazywamy surowym sygnałem EMG (*przykładowa zaprezentowana poniżej*).**

<p align="center">
  <img width="500" height="300" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/SurowyEMG.jpg>
</p>

Rozluźniony mięsień podczas badania elektromiograficznego daje sygnał lekko zakłóconej linii podstawowej – zakłócenia te są wynikiem działania wielu czynników zmiennych, takich jak szumy otoczenia, zmienne warunki pracy układu oraz jakości samego wzmacniacza EMG, co powoduje losowy charakter kształtu wyładowań. Fakt ten wynika też z możliwości umieszczenia elektrody w miejscu, w którym wyładowaniom mogą podlegać więcej niż jedna jednostka motoryczna. **Zakłócenia te nie powinny jednak przekraczać 3-5mV. Zakres surowego sygnału EMG powinien mieścić się w zakresie +/- 5000 uV, a typowa częstotliwość wyładowań 5 – 500Hz z nasileniem w częstotliwościach 20-150Hz.**

## Czynniki zakłócające

W związku z charakterem pomiarów elektromiograficznych, ich wyniki mogą być zakłócane przez wiele czynników. Są to m.in.:
* szumy zewnętrzne – zakłócenia elektromagnetyczne oraz nieprawidłowe uziemienie urządzeń;
* zakłócenia fizjologiczne – tzw. *„Cross Talk”*, nieprzekraczający zazwyczaj 15% całkowitego sygnału, powodowany przez sąsiadujące mięśnie;
* zmiany geometrii pomiędzy przyłożeniem elektrody a brzuścem mięśnia – zmiany na skutek napięcia mięśni, przejawiające się przemieszczaniem elektrody względem punktu pomiarowego;
* różnice w przewodnictwie tkankowym – zmiany parametrów przewodnictwa tkanek pod wpływem różnych czynników, uniemożliwiające dokładny pomiar;
* jakość elementów elektronicznych – szumy generowanie na układach i obwodach elektronicznych.

## Wymagania sprzętowe oraz pomiarowe

Urządzenia służące do odczytu sygnału EMG powinny spełniać pewne założenia pozwalające im na prawidłowe funkcjonowanie. 

Sygnał niewzmocniony rejestrowany na powierzchni skóry zawiera się zazwyczaj w granicach 2-3 mV. Oznacza to, że do jego poprawnego odczytania potrzeba **wzmocnienia od 500x** (przy zastosowaniu przedwzmacniaczy wbudowanych w elektrody) **do nawet 1000x** (przy zastosowaniu biernych układów elektrod). Zalecana impedancja wzmacniacza względem skóry wynosić powinna natomiast co najmniej dziesięciokrotność impedancji skóry (zaleca się 1-10 MΩ). Ustawienia filtra zakresu częstotliwości wzmacniacza do układów elektromiografii powinny zawierać się od 10Hz dla zakresów górnych do 500Hz dla zakresów dolnych. Niezalecane jest stosowanie filtrów wycinających, gdyż mogą one negatywnie wpływać na jakość sygnału.

Przechodząc do przetwornika analogowo-cyfrowego, należy pamiętać o **prawidłowych zakresie konwersji amplitudy** (w tym przypadku +/- 5V). Do różnicowania sygnału wystarczającym jest zakres 12-bitowy, dający w praktyce 4096 poziomów napięć.

Jednym z najważniejszych problemów napotykanych podczas doboru parametrów technicznych układów EMG jest **częstotliwość próbkowania przetwornika A/D**, która pozwala „przetłumaczyć” pełne spektrum częstotliwości sygnału. Zgodnie z teorią próbkowania Nyquista, częstotliwość próbkowania powinna być minimum dwukrotnie wyższa od maksymalnej częstotliwości sygnału. Niedotrzymanie tej zasady może powodować efekt aliasowania.

</br>
<p align="center">
  <img width="400" height="500" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/Nyquist.jpg>
</p>

**W przypadku badania elektromiograficznego, częstotliwość zawiera się w granicach 10Hz i 250Hz (dla prac naukowych nawet do 500Hz), więc odpowiednia częstotliwość próbkowania to co najmniej 1000Hz (dwukrotność pasma EMG).**

## Przygotowanie skóry do badania

Jakość otrzymanego sygnału przy badaniu elektromiograficznym w znacznej mierze zależy od poprawnego przygotowania skóry i umiejscowienia elektrod. Nie istnieje jedyny słuszny sposób przygotowania do badania – jest to kwestia arbitralna. Zalecane jest sprawdzenie impedancji skórnej i dobranie właściwych do niej warunków. 

Ważną zmienną w przygotowaniach skóry jest też charakter badania – przy badaniach statycznych wystarczającym może okazać się jedynie oczyszczenie skóry roztworem alkoholowym, natomiast przy badaniach dynamicznych, konieczne mogą się okazać bardziej specjalistyczne metody.

Zalecane jest również usunięcie włosów ze skóry mającej kontakt z elektrodą. Oczyszczanie skóry można przeprowadzić za pomocą wielu metod, m.in. czyszczących past abrazyjnych, powodujących usuwanie martwych komórek skóry (które z kolei powodują wzrost oporności), drobnoziarnistym papierem ściernym (przy zachowaniu odpowiedniej ostrożności, by nie uszkodzić badanego fragmentu skóry) bądź opisanym wcześniej obmyciem badanego miejsca alkoholem. Wskaźnikiem dobrze przygotowanej skóry powinno być lekkie zaczerwienienie.

## Dobór oraz umieszczenie elektrod

Najczęściej stosowanym typem elektrod są **elektrody powierzchniowe** ze względu na swój nieinwazyjny charakter, okupiony jednak rejestrowaniem potencjałów z mięśni powierzchniowych. Najpopularniejsze są preżelowane elektrody srebro/chlorek srebra, które posiadają szereg zalet, m.in. higieniczność elektrod jednorazowych. Średnica obszaru przewodzenia dobrych jakościowo elektrod powinna wynosić poniżej 1cm (zmniejsza to zjawisko *„Cross-talk”*). Najpowszechniejsze są elektrody z żelem mokrym (o lepszym przewodnictwie i niższej odporności) oraz z żelem lepkim (o prostej wymianie przy błędnej aplikacji elektrody).

Przy wybieraniu miejsca umieszczenia elektrod, należy pamiętać o **jak najmniejszej odległości dzielącej dwie elektrody** (zwiększającej selektywność badanych mięśni), u**mieszczaniu ich w najwyraźniejszej części środkowej brzuśca mięśniowego ze zwróceniem szczególnej uwagi na położenie elektrody w masie aktywnej bez względu na skurcz i rozkurcz mięśnia** oraz **stosowaniu standaryzowanych map ze zmierzonymi odległościami i pozycjami elektrod**. Na pacjencie należy także umieścić przynajmniej jedną **elektrodę referencyjną** w miejscach nieaktywnych, znajdujących się w pobliżu badanego mięśnia np. łokieć, czoło.

</br>
<p align="center">
  <img width="500" height="700" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/ElektrodyPunkty.jpg>
</p>

## Sensor elektromiograficzny firmy AT

Układem, który będzie pełnił rolę sensora elektromiograficznego jest **„Muscle Sensor”** firmy *Advencer Technologies* w wersji trzeciej (2013), przedstawiony poniżej. Jest to moduł o wymiarach 2,4cm x 2,4cm, posiadający 5 pinów 2,54mm oraz wejście miniJack, za pomocą którego odbywa się podłączenie trzech elektrod pomiarowych.


<p align="center">
  <img width="300" height="300" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/MuscleSensor.jpg>
</p>

Piny *„+Vs”*, *„GND”* oraz *„-Vs”* służą do podpięcia napięcia **symetrycznego** o wartości między ±3V a ±30V. Komunikacja z mikrokontrolerem odbywa się za pomocą pinów *„SIG”* oraz *„GND”*. Układ posiada możliwość wzmocnienia sygnału od 0,002x do nawet 20700x przy typowym wzmocnieniu oscylującym w granicach 10350x. Wzmocnienie regulowane jest za pomocą potencjometru umieszczonego w centralnej części układu. Sygnał wyjściowy może przybierać wartości maksymalne dla dołączonego do układu zasilania, natomiast rozdzielczość sygnałowa może wynosić w warunkach typowych 2-5mV i zmieniać się w zależności od ustawionego wzmocnienia sygnału. Stosowanie w układzie wzmacniacza różnicowego dwóch elektrod pomiarowych pozwala na skuteczne eliminowanie szumów.

**Układ Muscle Sensor v3 na wyjściu sygnałowym przesyła wzmocniony, wyprostowany oraz wygładzony sygnał, co pozwala na prostszą współpracę z mikrokontrolerem i jego układem przetwarzania A/C.**

</br>
<p align="center">
  <img width="300" height="250" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/SensorSygnaly.jpg>
</p>
</br>

**Więcej informacji na temat samego czujnika, jak i sposobu jego podłączenia, można znaleźć m.in. [na stronie przedmiotu](https://www.sparkfun.com/products/retired/11776) czy w [dokumentacji produktu](https://cdn.sparkfun.com/datasheets/Sensors/Biometric/Muscle%20Sensor%20v3%20Users%20Manual.pdf). Pomimo, że układ ten został już wycofany z produkcji, jest on dalej możliwy do zakupu m.in na Aliexpress :)**

# Projekty
W tej sekcji przedstawione zostaną przykładowe projekty wykonane z użyciem tego układu oraz Arduino (jak i innych podzespołów). By zachować lepszą czytelność oraz umożliwić rozbudowywanie bazy projektów, **szczegółowy** opis podłączeń został zrealizoway jedynie w pierwszym projekcie.
## Układ sterowania serwomechanizmem
<u>**Kod programu sterującego wraz z komentarzem został zamieszczony w pliku: [EMG_servo.ino](https://github.com/lobsterick/arduino_muscle_sensor/blob/master/EMG_servo/EMG_servo.ino)**</u>
### Podłączenie układu
* czujnik EMG podłączony został do źródła zasilania złożonego z układu dwóch baterii 9V połączonych szeregowo, a następnie przyłączonych odpowiednio dodatnim biegunem baterii do wejścia „+V”, ujemnym biegunem baterii do wejścia „V-” oraz miejscem połączenia dwóch baterii do wejścia „GND”.

* tak przygotowany układ został podłączony do płytki Arduino
 poprzez połączenie pinu „SIG” na układzie czujnika do portu 
analogowego A0 w Arduino oraz zwarcie masy czujnika z masą Arduino;

* serwomechanizm został podłączony wyjściem sterującym pod port sygnałowy 3, natomiast zasilony odpowiednio poprzez przyłączenie do wyjścia 5V oraz GND;

* dwie diody podłączone zostały do wyjść 2 oraz 4, a następnie do masy płytki GND;

* płytka Arduino została podpięta zarówno pod źródło zasilania (pojedyncza bateria 9V), jak i do komputera (w celu komunikowania się z układem);

</br>
<p align="center">
  <img width="1200" height="700" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/WidokUkladu.jpg>
</p>
</br>

* elektrody podłączone zostały do Muscle Sensor v3 oraz do mięśni przedramienia.

</br>
<p align="center">
  <img width="800" height="600" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/UmiejscowienieElektrod.jpg>
</p>
</br>

### Algorytm programu

</br>
<p align="center">
  <img width="800" height="700" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/Algorytm.jpg>
</p>
</br>

### Opis działania

* po podłączeniu układu, przechodzi on w tryb dziesięciosekundowej kalibracji, podczas której należy kilkukrotnie napiąć odpowiedni mięsień, a następnie go zrelaksować. Program ustala wtedy wartości minimalne (dla spoczynku) i maksymalne (dla napięcia), które będą potrzebne w późniejszym czasie do  różnicowania stanów napięcia mięśniowego. W tym trybie zapalone są obie diody LED do momentu zakończenia kalibracji. Uruchamiany jest także interfejs szeregowy do połączenia z komputerem. Po kalibracji, serwo ustawia się na pozycji wyjściowej;

</br>
<p align="center">
  <img width="500" height="400" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/EtapKalibracji.jpg>
</p>
</br>

* po wstępnej kalibracji, układ na bieżąco bada odczyty czujnika EMG. W momencie wykrycia napięcia, różnicuje on jego siłę na mniejszą oraz większą i – w zależności od odczytanej wartości – wykonuje odpowiednio ruch w stronę prawą z zapaleniem diody prawej oraz w stronę lewą z zapaleniem diody lewej;

</br>
<p align="center">
  <img width="500" height="400" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/LekkieNapiecie.jpg>
</p>

</br>
<p align="center">
  <img width="500" height="400" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/ZdecydowaneNapiecie.jpg>
</p>
</br>

### Przykładowe odpowiedzi czujnika

Efekty działania programu można też obserwować w narzędziu 
dostępnym bezpośrednio w ArduinoIDE, czyli **„Kreślarce”**. 

</br>
<p align="center">
  <img width="800" height="400" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/ParametrOdczyt.jpg>
</p>
</br>

Jak widać na powyższym wykresie, opisany sygnał odpowiada wzorowi wartości „odczyt” kolejno 2,1,2,2,1,2,2,1,2.  Odczyt 2 świadczy o wykonaniu akcji powiązanej z mocniejszą reakcją mięśniową, natomiast odczyt 1 świadczy o wykonaniu akcji powiązanej ze słabszą odpowiedzią mięśniową. Pozwala to bezpośrednio stwierdzić prawidłowość działania programu sterowania.

Możliwe jest także wysyłanie do Monitora Szeregowego wartości bezpośredniego odczytu z Muscle Sensor – by tego dokonać, należy zmienić zmienną w linii 61 z „odczyt” na  „pierwotny”. Wynikiem takiego działania scenariusz przedstawiony będzie w dwóch poniższych rysunkach.

</br>
<p align="center">
  <img width="800" height="500" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/SpoczynekMiesnia.jpg>
</p>
</br>

Jak widać na wykresie, wartość napięcia oscyluje w granicach 10-12 jednostek. Niejednorodny wynik spowodowany jest niedoskonałością układu pomiarowego. Dla porównania, wykres podczas pracy mięśnia przedstawiony jest poniżej.

</br>
<p align="center">
  <img width="800" height="500" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/AktywnoscMiesnia.jpg>
</p>
</br>

Z racji domyślnego autoskalowania wykresu, można zauważyć tu dużą różnicę, sięgającą nawet trzykrotności sygnału spoczynkowego podczas napięcia mięśnia. Także różnice w wysokości „pików” na wykresie dają podstawy do sterowania w większej ilości zakresów niż jedynie pomiędzy stanem wysokim i niskim.

## EKG
<u>**Kod programu sterującego wraz z komentarzem został zamieszczony w pliku: [EMG_ekg.ino](https://github.com/lobsterick/arduino_muscle_sensor/blob/master/EMG_ekg/EMG_ekg.ino)**</u>

Działanie tego programu polega na sygnalizowaniu dźwiękowym (za pomocą buzzera) wykrycia uderzenia serca. Uderzenie to jest rozumiane jako przekroczenie wartości połowy zakresu pomiarowego, wyznaczonego za pomocą kalibracji odbywającej się przed pomiarem. Kalibracja polega na 5 sekundowym  poszukiwaniu wartości granicznych, zarejestrowanych przez układ, a jej rozpoczęcie i zakończenie jest oznaczane za pomocą wbudowanej diody L (odpowiednio jej uruchomienie i wyłączenie).
Schemat podłączenia zamieszczono poniżej - zgodnie z kodem programu buzzer powinien zostać podpięty pod port 11 (należy zwrócić szczególną uwagę na kierunek umieszczenia).

</br>
<p align="center">
  <img width="800" height="500" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/SchematEKG.jpg>
</p>
</br>

Rozmieszczenie elektrod powinno być tożsame z podłączeniem Trójkąta Einthovena, np. tak jak poniżej.

</br>
<p align="center">
  <img width="300" height="250" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/EKGelectrodes.jpg>
</p>
</br>

## Czujnik pulsu
<u>**Kod programu sterującego wraz z komentarzem został zamieszczony w pliku: [EMG_puls.ino](https://github.com/lobsterick/arduino_muscle_sensor/blob/master/EMG_puls/EMG_puls.ino)**</u>

Działanie tego programu polega na sygnalizowaniu świetlnym wykrycia uderzenia serca oraz podawaniu - poprzez *Monitor Szeregowy* - zmierzonej wartości pulsu w ciagu ostatnich 10 sekund. Uderzenie to jest rozumiane jako przekroczenie wartości połowy zakresu pomiarowego, wyznaczonego za pomocą kalibracji odbywającej się przed pomiarem. Kalibracja polega na 5 sekundowym  poszukiwaniu wartości granicznych, zarejestrowanych przez układ, a jej rozpoczęcie i zakończenie jest oznaczane za pomocą wbudowanej diody L (odpowiednio jej uruchomienie i wyłączenie).
Schemat podłączenia zamieszczono poniżej.

</br>
<p align="center">
  <img width="800" height="500" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/SchematPuls.jpg>
</p>
</br>

Rozmieszczenie elektrod powinno być tożsame z podłączeniem Trójkąta Einthovena, np. tak jak poniżej.

</br>
<p align="center">
  <img width="300" height="250" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/EKGelectrodes.jpg>
</p>
</br>

## Gra zręcznościowa EMG_BOMB

<u>**Kod programu sterującego wraz z komentarzem został zamieszczony w pliku: [EMG_game.ino](https://github.com/lobsterick/arduino_muscle_sensor/blob/master/EMG_game/EMG_game.ino)**</u>

***EMG_BOMB*** to gra dwuosobowa, w której zadaniem grających jest posłanie bomby (reprezentowanej przez szereg świecących diod) w kierunku przeciwnika, powodując jej wybuch z dala od własnego pola. Osoby grające podłączają się do dwóch osobnych układów EMG poprzez układ trzech elektrod, umieszczonych na konkretnej grupie mięśniowej (np. bicepsie) i poprzez szybkie napinanie mięśni, starają się spowodować *"wybuch"* (sygnalizowany migotaniem skrajnej diody) po stronie przeciwnika. Grę i jej postępy można na bieżąco śledzić w *Monitorze Szeregowym*. Poniżej przedstawiono schemat podłączenia układu.

</br>
<p align="center">
  <img width="800" height="800" src=https://raw.githubusercontent.com/lobsterick/arduino_muscle_sensor/master/Pictures/SchematGame.jpg>
</p>
</br>

Gra rozpoczyna się kalibracją, sygnalizowaną świeceniem dwóch diod, w której gracy muszą kilkukrotnie napiąć mięsień, do którego podłączone są elektrody - jest ona sygnalizowana poniższym komunikatem:

> Procedura kalibracji polega na kilkukrotnym napięciu mięśnia, by program mógł znaleźć wartości graniczne jego działania. Macie na to 10 sekund.

Po 10 sekundach diody wyłączają się, a na Monitorze Szeregowym ukazują się zasady gry:

> Gra polega na powodowaniu jak najszybszego i najmocniejszego skurczu w zadanym mięśniu, by przepchnąć bombę (reprezentowaną przez szereg diód) w stronę Rywala. Osoba, u której bomba wybuchnie ... przegrywa. Pamiętaj - znajdź swój własny sposób najefektywniejszego przepychania bomby w stronę rywala!

Następnie zaczyna się odliczanie od 10, a po jego zakończeniu rozpoczyna się gra - jest to sygnalizowane przejściem *"fali światła"* przez diody. Przyznawane punkty są sygnalizowane poprzed komunikat:

> **Punkt dla** *lewego / prawego*

Przesunięcie bomby również powoduje pojawienie się stosownej informacji:

> **Bomba w** *lewo / prawo*

W momencie wygranej, ukazuje się komunikat:

> **Wygrał** *LEWY / PRAWY*

Przykładowa gra w formie wideo została zaprezentowana poniżej (ze względu na brak drugiego układu *Muscle Sensor*, gra toczy się jednostronnie):

</br>

<div style=text-align:center;"> <a href="https://youtu.be/TTjXHsss3ng"> <img src=https://raw.githubusercontent.com/lobsterick/raspberry_pupilometr_se/master/Pictures/MiniaturkaVideo.jpg style="height: 400px"/> </a> </div> 
</br></br>

**<u>Ponowna gra możliwa jest po restarcie urządzenia.</u>**
