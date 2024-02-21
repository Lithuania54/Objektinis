# Studentų Pažymių Skaičiavimo Programa

Ši programa skirta studentų pažymių ir galutinio balo (sudarant iš vidurkio ir mediano) skaičiavimui.

## Programos Veikimas

1. **Studentų Skaičiaus Įvedimas**: Pirmiausia, vartotojas įveda, kiek studentų nori įtraukti į skaičiavimą.
2. **Duomenų Įvedimas**: Vartotojas įveda kiekvieno studento vardą, pavardę, pažymius ir egzamino rezultatą. Programa tikrina, ar įvesti duomenys yra tinkami (t.y., ar vardas ir pavardė sudaryti tik iš raidžių, ar pažymiai ir egzamino rezultatas atitinka dešimtainę sistemą).
3. **Galutinio Balų Skaičiavimas**: Kiekvienam studentui skaičiuojamas galutinis balas, naudojant tiek vidurkio, tiek medianos metodą.
4. **Rezultatų Išvedimas**: Programa išveda studentų pavardes, vardus ir abu galutinius balus į ekraną.

## Programos Struktūra

Programa susideda iš vieno šaltinio failo, kuriame apibrėžta `Studentas` struktūra ir pagrindinės programos logikos vykdymo blokas.

### Struktūra `Studentas`

- `vardas`, `pavarde` - studento vardas ir pavardė;
- `kiekis` - pažymių kiekis;
- `egzaminorez` - egzamino rezultatas;
- `pazymiai[100]` - masyvas saugoti studento pažymiams;
- `galutinis`, `mediana` - skaičiuojami studento galutiniai balai.

## Naudojimo Instrukcija

1. Paleiskite programą.
2. Įveskite norimą studentų skaičių.
3. Sekite programos nurodymais, įvedinėdami kiekvieno studento duomenis.
4. Po visų duomenų įvedimo, programa išves galutinius rezultatus.
