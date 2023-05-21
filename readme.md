## Prepoznavanja aktivnosti in izračun porabljenih kalorij z mikrokrmilnikom ESP8266

**Seminar pri predmetu Računalniški sistemi 2022/23.**

*Fakulteta za Računalništvo in Informatiko, Univerza v Ljubljani*

### Poročilo je v mapi report v datoteki report.pdf.

### Podatki uporabljeni za učenje modela naključnega gozda so v mapi data.

### Datoteke v src direktoriju vsebujejo:
- arduino
    - temp_gather_data: koda za pošiljanje podatkov za učenje modela naključnega gozda
    - track: koda za osnovo rešitve (branje senzorjev, klasifikacija z modelom, štetje korakov...)
- python
    - gather_data: koda za shranjevanje podatkov za učenje modela na računalnik
    - ml: koda za učenje modela naključnega gozda
    - server: koda za pošiljanje zgodovinskih podaktov iz strežnika


## Navodila za Uporabo Aplikacije

### Namestitev Lokalnega Strežnika

1. Naredite dostopno točko s *ssid* imenom *Mi Phone* in geslom *6a2ce2f58db9*.
2. Zaženite strežnik lokalno tako, da napravo povežete na računalnik in zaženete datoteko *track.ino*.
3.Iz ukazne vrstice pridobite IP naslov s pomočjo ukazne vrstice.

### Prijava

1. Uporabite naslednje poverilnice za prijavo na prvi strani aplikacije:
   - Uporabniško ime: "Mi Phone"
   - Geslo: "Mi Phone"
   brez uporabe narekovajev.

### Začetek Aktivnosti

1. Na glavni strani kliknite gumb "Start Activity".
   - S tem boste začeli aktivnost.
   - Aplikacija bo sledila vaši hoji, teku ali kolesarjenju, kjer bo pri zadnjem prikazovala število vrtljejev, ki ste jih naredili.

### Zaključek Aktivnosti

1. Po končani aktivnosti kliknite gumb "End Activity". To bo sprožilo klic na zaledje, kamor se bodo shranili podatki aktivnosti, na glavni strani aplikacije pa se bodo števci ponastavili.

### Pregled Prejšnjih Podatkov

1. Za ogled podatkov prejšnjega dne kliknite gumb "Go to Yesterday".
    - Tu imate na pregled podatke prejšnjega dneva s številom porabljenih kalorij.
    - poleg tega se prikazuje tudi razlika med današnjo aktivnostjo in včerajšnjo.
    
2. Za iskanje podatkov za določen datum sledite naslednjim korakom:
   - Vnesite želeni datum v iskalno polje.
   - Kliknite gumb "Search".
   - Preusmerjeni boste na novo stran, kjer boste imeli podatke za aktivnosti tisti dan.