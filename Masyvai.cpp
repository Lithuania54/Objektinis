#include <bits/stdc++.h>

using namespace std;

struct Studentas
{
    string vardas, pavarde;
    int kiekis, egzaminorez, *pazymiai;
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

int main()
{
    int n, vidurkis, minusiukai = 80, stop;
    Studentas Masyvas[n];

    std::cout << "1. - ranka\n2. - generuoti pazymius\n3. - generuoti ir pazymius ir studentu vardus, pavardes\n4. - baigti darba";
    std::cin >> stop;

    if (n > 0)
    {
        while (true)
        {

            if (stop < 4)
            {
               // cout << "Irasykite mokiniu skaiciu: ";
                //cin >> n;

                for (int i = 0; i < n; i++)
                {
                    do
                    {
                        std::cout << "Iveskite varda: ";
                        cin >> Masyvas[i].vardas;
                        if (!tinkami(Masyvas[i].vardas))
                        {
                            std::cout << "Vardas turi buti sudarytas tik is raidziu. Bandykite dar karta." << endl;
                        }
                    } while (!tinkami(Masyvas[i].vardas));

                    do
                    {
                        std::cout << "Iveskite pavarde: ";
                        cin >> Masyvas[i].pavarde;
                        if (!tinkami(Masyvas[i].pavarde))
                        {
                            std::cout << "Pavarde turi buti sudaryta tik is raidziu. Bandykite dar karta." << endl;
                        }
                    } while (!tinkami(Masyvas[i].pavarde));

                    do
                    {
                        std::cout << "Iveskite pazymiu kieki: ";
                        cin >> Masyvas[i].kiekis;
                        if (Masyvas[i].kiekis == 0)
                        {
                            std::cout << "Pazymiu kiekis negali buti nulis. Bandykite dar karta." << endl;
                        }
                    } while (Masyvas[i].kiekis <= 0);

                    for (int j = 0; j < Masyvas[i].kiekis; j++)
                    {
                        do
                        {
                            std::cout << "Iveskite pazymius: ";
                            cin >> Masyvas[i].pazymiai[j];
                            if (Masyvas[i].pazymiai[j] < 0 || Masyvas[i].pazymiai[j] > 10)
                            {
                                std::cout << "Neatitinka desimbales sistemos. Bandykite dar karta." << endl;
                            }
                        } while (Masyvas[i].pazymiai[j] > 10 || Masyvas[i].pazymiai[j] < 0);
                    }

                    do
                    {
                        std::cout << "Iveskite egzamino rezultata: ";

                        cin >> Masyvas[i].egzaminorez;
                        if (Masyvas[i].egzaminorez < 0 || Masyvas[i].egzaminorez > 10)
                        {
                            std::cout << "Neatitinka desimbales sistemos. Bandykite dar karta." << endl;
                        }
                    } while (Masyvas[i].egzaminorez > 10 || Masyvas[i].egzaminorez < 0);

                    vidurkis = accumulate(Masyvas[i].pazymiai, Masyvas[i].pazymiai + Masyvas[i].kiekis, 0) / Masyvas[i].kiekis;
                    Masyvas[i].galutinis = 0.4 * vidurkis + 0.6 * Masyvas[i].egzaminorez;

                    sort(Masyvas[i].pazymiai, Masyvas[i].pazymiai + Masyvas[i].kiekis);

                    if (Masyvas[i].kiekis % 2 == 0)
                    {
                        Masyvas[i].mediana = (Masyvas[i].pazymiai[Masyvas[i].kiekis / 2] + Masyvas[i].pazymiai[(Masyvas[i].kiekis / 2) - 1]) / 2;
                    }

                    else
                    {
                        Masyvas[i].mediana = Masyvas[i].pazymiai[Masyvas[i].kiekis / 2];
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

                for (int i = 0; i < n; i++)
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
            }
            else
            {
                break;
            }
        }
    }

    else
    {
        std::cout << "Nera mokiniu" << endl;
    }
}