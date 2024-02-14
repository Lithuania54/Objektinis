#include <bits/stdc++.h>
#include <numeric>
using namespace std;

struct Studentas
{
    string vardas, pavarde;
    int kiekis, egzaminorez, pazymiai[100];
    double galutinis, mediana;
};

int main()
{
    int n, vidurkis, minusiukai = 80;
    cout << "Irasykite mokiniu skaiciu: ";
    cin >> n;
    Studentas Masyvas[n];

    if (n > 0)
    {

        for (int i = 0; i < n; i++)
        {
            cout << "Iveskite varda: ";
            cin >> Masyvas[i].vardas;
            cout << "Iveskite pavarde: ";
            cin >> Masyvas[i].pavarde;

            do
            {
                cout << "Iveskite pazymiu kieki: ";
                cin >> Masyvas[i].kiekis;
                if (Masyvas[i].kiekis == 0)
                {
                    cout << "Pazymiu kiekis negali buti nulis. Bandykite dar karta." << endl;
                }
            } while (Masyvas[i].kiekis <= 0);

            for (int j = 0; j < Masyvas[i].kiekis; j++)
            {
                do
                {
                    cout << "Iveskite pazymius: ";
                    cin >> Masyvas[i].pazymiai[j];
                    if (Masyvas[i].pazymiai[j] < 0 || Masyvas[i].pazymiai[j] > 10)
                    {
                        cout << "Neatitinka desimbales sistemos. Bandykite dar karta." << endl;
                    }
                } while (Masyvas[i].pazymiai[j] > 10 || Masyvas[i].pazymiai[j] < 0);
            }

            do
            {
                cout << "Iveskite egzamino rezultata: ";

                cin >> Masyvas[i].egzaminorez;
                if (Masyvas[i].egzaminorez < 0 || Masyvas[i].egzaminorez > 10)
                {
                    cout << "Neatitinka desimbales sistemos. Bandykite dar karta." << endl;
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

        cout.width(15);
        cout << left << "Pavarde";
        cout.width(15);
        cout << left << "Vardas";
        cout.width(23);
        cout << left << "Galutinis (Vid.)";
        cout.width(23);
        cout << left << "Galutinis (med.)" << endl;
        for (int i = 0; i < minusiukai; i++)
        {
            cout << "-";
        }
        cout << endl;

        for (int i = 0; i < n; i++)
        {
            cout.width(15);
            cout << left << Masyvas[i].pavarde;
            cout.width(15);
            cout << left << Masyvas[i].vardas;
            cout.width(23);
            cout << left << fixed << setprecision(2) << Masyvas[i].galutinis;
            cout.width(23);
            cout << left << fixed << setprecision(2) << Masyvas[i].mediana << endl;
        }
    }

    else
    {
        cout << "Nera mokiniu" << endl;
    }
}