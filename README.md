# Projekto README.md

## Aprašymas

Ši sistema skirta efektyviam studentų duomenų apdorojimui: duomenų skaitymui iš failo, studentų rūšiavimui į skirtingas kategorijas pagal jų pasiekimus, ir galiausiai, surūšiuotų studentų išvedimui į naujus failus. Projektas leidžia išmatuoti ir analizuoti kiekvieno šių žingsnių veikimo laiką, taip užtikrinant sistemos veiksmingumą. Yra matuojamas failų kūrimo laikas, duomenų nuskaitymas iš failo, studentų rūšiavimas, surūšiuotų studentų išvedimas į du naujus failus, visos programos veikimo laikas. Mokiniai, kurių galutinis balas yra >= 5, patenka į `pazenge.txt` failą, o visi likę į `nepazenge.txt`.

## Spartos analizės rezultatai VECTOR (Po 10 nd)

| Failo dydis | Duomenų skaitymas (s) | Rūšiavimas (s) | Išvedimas į du failus (s)|
|-------------|----------------|----------------------|---------------------------|
| failas1000    | 0.002      | 0.0002             | 0.002        |
| failas10000    | 0.03       | 0.002           | 0.01                |
| failas100000    | 0.2       | 0.03            | 0.14              |
| failas1000000    | 2.1       | 0.25             | 1.1                 |
| failas10000000    | 20.1       | 2.3            | 10.1                  |

## Spartos analizės rezultatai LIST (Po 10 nd)

| Failo dydis | Duomenų skaitymas (s) | Rūšiavimas (s) | Išvedimas į du failus (s)|
|-------------|----------------|----------------------|---------------------------|
| failas1000    | 0.002      | 0.0002             | 0.002        |
| failas10000    | 0.03       | 0.002           | 0.01                |
| failas100000    | 0.2       | 0.03            | 0.14              |
| failas1000000    | 2.1       | 0.25             | 1.1                 |
| failas10000000    | 20.1       | 2.3            | 10.1                  |

## Spartos analizės rezultatai DEQUE (Po 10 nd)

| Failo dydis | Duomenų skaitymas (s) | Rūšiavimas (s) | Išvedimas į du failus (s)|
|-------------|----------------|----------------------|---------------------------|
| failas1000    | 0.002      | 0.0002             | 0.002        |
| failas10000    | 0.03       | 0.002           | 0.01                |
| failas100000    | 0.2       | 0.03            | 0.14              |
| failas1000000    | 2.1       | 0.25             | 1.1                 |
| failas10000000    | 20.1       | 2.3            | 10.1                  |

## Sistemos parametrai

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