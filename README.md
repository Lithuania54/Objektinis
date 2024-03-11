# Projekto README.md

## Aprašymas

Programa skirta studentų duomenų apdorojimui: **įvedimui, generavimui, skaitymui iš failo, failo generavimui ir rezultatų išvedimui į failą**. Vartotojas gali pasirinkti, kaip nori pateikti studentų duomenis: įvesti ranka, generuoti atsitiktinai, skaityti iš failo, ar sukurti naują failą su atsitiktiniais duomenimis. Programa leidžia nuspręsti, kurio tipo konteinerį naudoti duomenų saugojimui: **vector, list, ar deque**. Po duomenų surinkimo, studentai yra skirstomi į dvi grupes pagal galutinį balą, o tada rezultatai išvedami į atitinkamus failus: `pazenge.txt` arba `nepazenge.txt`. Pasirinkus, rezultatai gali būti išrikiuoti pagal vardą, pavardę, galutinį vidurkį, ar medianą. Programa pateikia informaciją apie įvairių operacijų vykdymo laiką, leidžiant įvertinti efektyvumą.

## Testavimo sistemos parametrai

- **CPU**: 11th Gen Intel(R) Core(TM) i7-11800H 2.30GHz / 16 logical processors / 8 cores
- **RAM**: 16GB / speed 3200MHz
- **HDD**: SSD / 500GB

# Spartos analizės

## Spartos analizė be papildomų algoritmų

### Spartos analizės rezultatai VECTOR (Po 10 nd)

| Failo dydis | Duomenų skaitymas (s) | Rūšiavimas (s) | Išvedimas į du failus (s)|
|-------------|----------------|----------------------|---------------------------|
| failas1000    |     0.003  |         0.0004     |      0.002   |
| failas10000    |    0.03    |        0.005    |          0.01       |
| failas100000    |   0.31     |        0.09     |          0.11     |
| failas1000000    |    3.01    |         1.19     |          1.25        |
| failas10000000    |    30.45    |        14.71     |           11.57       |

### Spartos analizės rezultatai LIST (Po 10 nd)

| Failo dydis | Duomenų skaitymas (s) | Rūšiavimas (s) | Išvedimas į du failus (s)|
|-------------|----------------|----------------------|---------------------------|
| failas1000    |     0.005  |          0.0001    |     0.003    |
| failas10000    |     5.54   |       0.002     |          0.02       |
| failas100000    |     952.03   |       0.04      |         0.24      |
| failas1000000    |    ----    |       ----       |        ----          |
| failas10000000    |    ----    |       ----      |         ----          |

### Spartos analizės rezultatai DEQUE (Po 10 nd)

| Failo dydis | Duomenų skaitymas (s) | Rūšiavimas (s) | Išvedimas į du failus (s)|
|-------------|----------------|----------------------|---------------------------|
| failas1000    |    0.003   |         0.0004     |      0.001   |
| failas10000    |    0.003    |       0.0004    |         0.001        |
| failas100000    |     0.02   |        0.006     |        0.016       |
| failas1000000    |    2.9    |        1.06      |         1.25         |
| failas10000000    |     32.92   |       42.29      |          30.63         |

## Spartos analizė su copy_if, erase, remove_if, back_inserter algoritmais

### Spartos analizės rezultatai VECTOR (Po 10 nd)

| Failo dydis | Duomenų skaitymas (s) | Rūšiavimas (s) | Išvedimas į du failus (s)|
|-------------|----------------|----------------------|---------------------------|
| failas1000    |     0.003  |         0.0004     |      0.002   |
| failas10000    |    0.03    |        0.005    |          0.01       |
| failas100000    |   0.31     |        0.09     |          0.11     |
| failas1000000    |    3.01    |         1.19     |          1.25        |
| failas10000000    |    29.93    |        14.15     |           11.82       |

### Spartos analizės rezultatai LIST (Po 10 nd)

| Failo dydis | Duomenų skaitymas (s) | Rūšiavimas (s) | Išvedimas į du failus (s)|
|-------------|----------------|----------------------|---------------------------|
| failas1000    |     0.004  |          0.0001    |     0.003    |
| failas10000    |     5.63   |       0.001     |          0.01       |
| failas100000    |     802.4   |       0.03      |         0.11      |
| failas1000000    |    ----    |       ----       |        ----          |
| failas10000000    |    ----    |       ----      |         ----          |

### Spartos analizės rezultatai DEQUE (Po 10 nd)

| Failo dydis | Duomenų skaitymas (s) | Rūšiavimas (s) | Išvedimas į du failus (s)|
|-------------|----------------|----------------------|---------------------------|
| failas1000    |    0.003   |         0.001     |      0.002   |
| failas10000    |    0.003    |       0.001    |         0.003        |
| failas100000    |     0.02   |        0.15     |        0.20       |
| failas1000000    |    3.4    |        3.31      |         1.5         |
| failas10000000    |     32.53   |       39.17      |          36.06         |

## Išvados

Algoritmų pagalba nežymiai pagreitėjo duomenų nuskaitymas, rūšiavimas ir išvedimas į du failus **vektorių** ir **deque** konteineriuose, tačiau **list** konteineryje duomenys buvo nuskaitomi daug greičiau. Verta pridurti, kad algoritmų pagalba programa veikia efektyviau atminties atžvilgiu.

# Releasai ir paleidimas

## Releasų istorija

- **V.pradine**: Sukurta preliminari programa, kurioje vartotojui įvedus studentų kiekį ir studentų duomenis (vardą, pavardę, pažymius) apskaičiuoja ir atspausdina studento duomenis su galutiniu rezultatu ir mediana. 
- **V0.1**: Programa papildyta taip, kad iš anksto nėra žinomas nei namų darbų kiekis, nei mokinių. Pridėta galimybė, jog mokinio gautieji balai už namų darbus bei egzaminą būtų generuojami atsitiktinai. Programa suskirstyta į du failus: **Masyvai.cpp** ir **Vektoriai.cpp**. **Masyvai.cpp** faile duomenys yra saugomi C masyve, o **Vektoriai.cpp** faile std::vector konteineryje. Sukurtas meniu.
- **V0.2**: Pridėta galimybė nuskaityti duomenis iš failo ir patobulintas atspausdinimo metodas.
- **V0.3**: Atliktas kodo reorganizavimas: struktūros perkeltos į atraštinius failus, o funkcijos į **Funkcijos.cpp** failą. Pridėtas išimčių valdymas.
- **V0.4**: Sukurta failų generatoriaus funkcija. Studentai surūšiuojami į dvi kategorijas pagal pažymius ir išvedami į du naujus failus ( **nepazenge.txt** ir **pazenge.txt**). Atlikta programos veikimo greičio analizė.
- **V1.0**: Atliktas konteinerių testavimas su **std::vector**, **std::list** ir **deque** konteineriais. Optimizuota programa su **copy_if, erase, remove_if, back_inserter** algoritmais. 

## Paleidimas
- Programą galite paleisti iš komandinės eilutės, nurodant reikiamus parametrus:
*g++ -o vektoriai Vektoriai.cpp Funkcijos.cpp* ir *.\vektoriai.exe*
*g++ -o lists Lists.cpp Funkcijos.cpp* ir *.\lists.exe*
*g++ -o deque Deque.cpp Funkcijos.cpp* ir *.\deque.exe*