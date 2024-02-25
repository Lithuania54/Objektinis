# Efektyvumo Tyrimai (Refactoring and exception handling)

## Kaip naudotis
1. Paleidus programą, pasirinkite veiksmą iš meniu.
2. Jeigu pasirinkote duomenų įvedimą ranka, sekite programos nurodymus.
3. Jeigu pasirinkote automatinį duomenų generavimą, nurodykite norimą studentų skaičių.
4. Duomenų nuskaitymui iš failo, įsitikinkite, kad failas `studentai10000.txt` yra projekto aplanke.
5. Rezultatų peržiūrai, pasirinkite atitinkamą meniu punktą.

## Programos struktūra
Projektas susideda iš šių failų:
- `main.cpp`: pagrindinis programos failas.
- `Studentas.h`: apibrėžia `Studentas` struktūrą.
- `Funkcijos.h` ir `Funkcijos.cpp`: apibrėžia pagalbines funkcijas, tokias kaip duomenų nuskaitymas ir generavimas.
- `Vektoriai.cpp`: pavyzdinis failas, demonstruojantis veiksmus su vektoriais.

## Paleidimas
*g++ -o vektoriai Vektoriai.cpp Funkcijos.cpp* ir *.\vektoriai.exe*
