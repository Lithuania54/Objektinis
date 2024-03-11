# Projekto README.md

## Aprašymas

Programa skirta studentų duomenų apdorojimui: **įvedimui, generavimui, skaitymui iš failo, failo generavimui ir rezultatų išvedimui į failą**. Vartotojas gali pasirinkti, kaip nori pateikti studentų duomenis: įvesti ranka, generuoti atsitiktinai, skaityti iš failo, ar sukurti naują failą su atsitiktiniais duomenimis. Programa leidžia nuspręsti, kurio tipo konteinerį naudoti duomenų saugojimui: **vector, list, ar deque**. Po duomenų surinkimo, studentai yra skirstomi į dvi grupes pagal galutinį balą, o tada rezultatai išvedami į atitinkamus failus: `pazenge.txt` arba `nepazenge.txt`. Pasirinkus, rezultatai gali būti išrikiuoti pagal vardą, pavardę, galutinį vidurkį, ar medianą. Programa pateikia informaciją apie įvairių operacijų vykdymo laiką, leidžiant įvertinti efektyvumą.

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
*g++ -o lists Lists.cpp Funkcijos.cpp* ir *.\lists.exe*
*g++ -o deque Deque.cpp Funkcijos.cpp* ir *.\deque.exe*