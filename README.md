# Projekto README.md

## Aprašymas

Ši sistema skirta efektyviam studentų duomenų apdorojimui: duomenų skaitymui iš failo, studentų rūšiavimui į skirtingas kategorijas pagal jų pasiekimus, ir galiausiai, surūšiuotų studentų išvedimui į naujus failus. Projektas leidžia išmatuoti ir analizuoti kiekvieno šių žingsnių veikimo laiką, taip užtikrinant sistemos veiksmingumą. Yra matuojamas failų kūrimo laikas, duomenų nuskaitymas iš failo, studentų rūšiavimas, surūšiuotų studentų išvedimas į du naujus failus, visos programos veikimo laikas. Mokiniai, kurių galutinis balas yra >= 5, patenka į `pazenge.txt` failą, o visi likę į `nepazenge.txt`.

## Spartos analizės rezultatai VECTOR (Po 10 nd)

| Failo dydis | Duomenų skaitymas (s) | Rūšiavimas (s) | Išvedimas į du failus (s)|
|-------------|----------------|----------------------|---------------------------|
| failas1000    |     0.003  |         0.0004     |      0.002   |
| failas10000    |    0.03    |        0.005    |          0.01       |
| failas100000    |   0.31     |        0.09     |          0.11     |
| failas1000000    |    3.01    |         1.19     |          1.25        |
| failas10000000    |    30.45    |        14.71     |           11.57       |

## Spartos analizės rezultatai LIST (Po 10 nd)

| Failo dydis | Duomenų skaitymas (s) | Rūšiavimas (s) | Išvedimas į du failus (s)|
|-------------|----------------|----------------------|---------------------------|
| failas1000    |     0.005  |          0.0001    |     0.003    |
| failas10000    |     5.54   |       0.002     |          0.02       |
| failas100000    |     952.03   |       0.04      |         0.24      |
| failas1000000    |    ----    |       ----       |        ----          |
| failas10000000    |    ----    |       ----      |         ----          |

## Spartos analizės rezultatai DEQUE (Po 10 nd)

| Failo dydis | Duomenų skaitymas (s) | Rūšiavimas (s) | Išvedimas į du failus (s)|
|-------------|----------------|----------------------|---------------------------|
| failas1000    |    0.003   |         0.001     |      0.003   |
| failas10000    |    0.031    |       0.001    |         0.016        |
| failas100000    |     0.34   |        0.21     |        0.16       |
| failas1000000    |    3.5    |        3.26      |         1.7         |
| failas10000000    |     32.92   |       42.29      |          30.63         |

## Testavimo sistemos parametrai

- **CPU**: 11th Gen Intel(R) Core(TM) i7-11800H 2.30GHz / 16 logical processors / 8 cores
- **RAM**: 16GB / speed 3200MHz
- **HDD**: SSD / 500GB

## Paleidimas
- Programą galite paleisti iš komandinės eilutės, nurodant reikiamus parametrus:
*g++ -o vektoriai Vektoriai.cpp Funkcijos.cpp* ir *.\vektoriai.exe*

## Nuotraukos
![failas1000](/images/failas1000.png)
![failas10000](/images/failas10000.png)
![failas100000](/images/failas100000.png)
![failas1000000](/images/failas1000000.png)
![failas10000000](/images/failas10000000.png)