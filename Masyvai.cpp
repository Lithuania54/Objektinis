#include <bits/stdc++.h>
#include <random>

using namespace std;

struct Studentas
{
    string vardas, pavarde;
    int egzaminorez, *pazymiai;
    double galutinis, mediana;
};

bool tinkami(const string &name)
{
    for (char ch : name)
    {
        if (!isalpha(ch))
        {
            return false;
        }
    }
    return true;
}

void resizeArray(Studentas *&array, int &capacity)
{
    Studentas *temp = new Studentas[capacity * 2];
    for (int i = 0; i < capacity; i++)
    {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    capacity *= 2;
}

string generateRandomString(int length)
{
    string possibleCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string randomString = "";
    srand(time(0)); // seed the random number generator
    for (int i = 0; i < length; i++)
    {
        randomString += possibleCharacters[rand() % possibleCharacters.size()];
    }
    return randomString;
}

int main()
{
    double vidurkis = 0;
    int minusiukai = 80, stop, kiekis = 0, capacity = 10;
    Studentas *Masyvas = new Studentas[capacity];

    while (true)
    {
        std::cout << "1. - ranka\n2. - generuoti pazymius\n3. - generuoti ir pazymius ir studentu vardus, pavardes\n4. - baigti darba" << endl;
        std::cin >> stop;
        if (stop < 4)
        {
            if (stop == 1)
            {
                if (kiekis == capacity)
                {
                    resizeArray(Masyvas, capacity);
                }
                do
                {

                    do
                    {
                        std::cout << "Iveskite varda (arba 'done', jei norite baigti): ";
                        cin >> Masyvas[kiekis].vardas;
                        if (!tinkami(Masyvas[kiekis].vardas))
                        {
                            std::cout << "Vardas turi buti sudarytas tik is raidziu. Bandykite dar karta." << endl;
                        }
                    } while (!tinkami(Masyvas[kiekis].vardas));
                    if (Masyvas[kiekis].vardas == "done")
                        break;

                    do
                    {
                        std::cout << "Iveskite pavarde: ";
                        cin >> Masyvas[kiekis].pavarde;
                        if (!tinkami(Masyvas[kiekis].pavarde))
                        {
                            std::cout << "Pavarde turi buti sudaryta tik is raidziu. Bandykite dar karta." << endl;
                        }
                    } while (!tinkami(Masyvas[kiekis].pavarde));

                    int j = 0;
                    int pazymiukiekis = 1;
                    Masyvas[kiekis].pazymiai = new int[pazymiukiekis];

                    do
                    {
                        std::cout << "Iveskite pazymius (kai baigsite, parasykite -1): ";
                        int x;
                        cin >> x;
                        if (x == -1)
                            break;
                        if (x < 0 || x > 10)
                        {
                            std::cout << "Neatitinka desimbales sistemos. Bandykite dar karta." << endl;
                        }
                        else
                        {
                            Masyvas[kiekis].pazymiai[j] = x;
                            j++;
                        }
                        if (j == pazymiukiekis)
                        {
                            pazymiukiekis += 1;
                            int *laikinas = new int[pazymiukiekis];
                            for (int i = 0; i < j; i++)
                            {
                                laikinas[i] = Masyvas[kiekis].pazymiai[i];
                            }
                            delete[] Masyvas[kiekis].pazymiai;
                            Masyvas[kiekis].pazymiai = laikinas;
                        }

                    } while (true);

                    do
                    {
                        std::cout << "Iveskite egzamino rezultata: ";

                        cin >> Masyvas[kiekis].egzaminorez;
                        if (Masyvas[kiekis].egzaminorez < 0 || Masyvas[kiekis].egzaminorez > 10)
                        {
                            std::cout << "Neatitinka desimbales sistemos. Bandykite dar karta." << endl;
                        }
                    } while (Masyvas[kiekis].egzaminorez > 10 || Masyvas[kiekis].egzaminorez < 0);

                    vidurkis = 1.0 * accumulate(Masyvas[kiekis].pazymiai, Masyvas[kiekis].pazymiai + j, 0) / j;
                    Masyvas[kiekis].galutinis = 0.4 * vidurkis + 0.6 * Masyvas[kiekis].egzaminorez;

                    sort(Masyvas[kiekis].pazymiai, Masyvas[kiekis].pazymiai + j);

                    if (j % 2 == 0)
                    {
                        Masyvas[kiekis].mediana = (Masyvas[kiekis].pazymiai[j / 2] + Masyvas[kiekis].pazymiai[(j / 2) - 1]) / 2.0;
                    }
                    else
                    {
                        Masyvas[kiekis].mediana = Masyvas[kiekis].pazymiai[j / 2];
                    }

                    kiekis++;
                } while (Masyvas[kiekis].vardas != "done");
            }
            else if (stop == 3)
            {
                if (kiekis == capacity)
                {
                    resizeArray(Masyvas, capacity);
                }
                Masyvas[kiekis].vardas = generateRandomString(10);
                Masyvas[kiekis].pavarde = generateRandomString(10);
                int j = 0;
                int pazymiukiekis = 1;
                Masyvas[kiekis].pazymiai = new int[pazymiukiekis];
                for (int i = 0; i < 10; i++)
                {
                    Masyvas[kiekis].pazymiai[j] = rand() % 11;
                    j++;
                    if (j == pazymiukiekis)
                    {
                        pazymiukiekis += 1;
                        int *laikinas = new int[pazymiukiekis];
                        for (int i = 0; i < j; i++)
                        {
                            laikinas[i] = Masyvas[kiekis].pazymiai[i];
                        }
                        delete[] Masyvas[kiekis].pazymiai;
                        Masyvas[kiekis].pazymiai = laikinas;
                    }
                }
                Masyvas[kiekis].egzaminorez = rand() % 11;
                vidurkis = 1.0 * accumulate(Masyvas[kiekis].pazymiai, Masyvas[kiekis].pazymiai + j, 0) / j;
                Masyvas[kiekis].galutinis = 0.4 * vidurkis + 0.6 * Masyvas[kiekis].egzaminorez;
                sort(Masyvas[kiekis].pazymiai, Masyvas[kiekis].pazymiai + j);
                if (j % 2 == 0)
                {
                    Masyvas[kiekis].mediana = (Masyvas[kiekis].pazymiai[j / 2] + Masyvas[kiekis].pazymiai[(j / 2) - 1]) / 2.0;
                }
                else
                {
                    Masyvas[kiekis].mediana = Masyvas[kiekis].pazymiai[j / 2];
                }
                kiekis++;
            }
        }
        else
        {
            break;
        }
    }

    std::cout.width(15);
    std::cout << left << "Pavarde";
    std::cout.width(15);
    std::cout << left << "Vardas";
    std::cout.width(23);
    std::cout << left << "Galutinis (Vid.)";
    std::cout.width(23);
    std::cout << left << "Galutinis (med.)" << endl;
    for (int i = 0; i < minusiukai; i++)
    {
        std::cout << "-";
    }
    std::cout << endl;

    for (int i = 0; i < kiekis; i++)
    {
        std::cout.width(15);
        std::cout << left << Masyvas[i].pavarde;
        std::cout.width(15);
        std::cout << left << Masyvas[i].vardas;
        std::cout.width(23);
        std::cout << left << fixed << setprecision(2) << Masyvas[i].galutinis;
        std::cout.width(23);
        std::cout << left << fixed << setprecision(2) << Masyvas[i].mediana << endl;
    }

    for (int i = 0; i < kiekis; ++i)
    {
        delete[] Masyvas[i].pazymiai;
    }

    delete[] Masyvas;

    return 0;
}
