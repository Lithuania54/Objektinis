# Projekto README.md

## Aprašymas

Ši sistema skirta efektyviam studentų duomenų apdorojimui: duomenų skaitymui iš failo, studentų rūšiavimui į skirtingas kategorijas pagal jų pasiekimus, ir galiausiai, surūšiuotų studentų išvedimui į naujus failus. Projektas leidžia išmatuoti ir analizuoti kiekvieno šių žingsnių veikimo laiką, taip užtikrinant sistemos veiksmingumą. Yra matuojamas failų kūrimo laikas, duomenų nuskaitymas iš failo, studentų rūšiavimas, surūšiuotų studentų išvedimas į du naujus failus, visos programos veikimo laikas. Mokiniai, kurių galutinis balas yra >= 5, patenka į `pazenge.txt` failą, o visi likę į `nepazenge.txt`.

## Spartos analizės rezultatai

| Failo dydis | Failo kūrimas (s) | Duomenų skaitymas (s) | Rūšiavimas (s) | Išvedimas į du failus (s)|
|-------------|-----------------------|----------------|----------------------|---------------------------|
| failas1000    |  0.002   | 0.002      | 0.0002             | 0.002        |
| failas10000    | 0.01             | 0.03       | 0.002           | 0.01                |
| failas100000    | 0.12             | 0.2       | 0.03            | 0.14              |
| failas1000000    | 1.2              | 2.1       | 0.25             | 1.1                 |
| failas10000000    | 10.1              | 20.1       | 2.3            | 10.1                  |


## Paleidimas
- Programą galite paleisti iš komandinės eilutės, nurodant reikiamus parametrus:
*g++ -o vektoriai Vektoriai.cpp Funkcijos.cpp* ir *.\vektoriai.exe*