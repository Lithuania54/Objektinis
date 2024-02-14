#include <bits/stdc++.h>

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

int main()
{
    double vidurkis = 0;
    int minusiukai = 80, stop, kiekis = 0;
    Studentas Masyvas[1000];



    while (true)
    {
        std::cout << "1. - ranka\n2. - generuoti pazymius\n3. - generuoti ir pazymius ir studentu vardus, pavardes\n4. - baigti darba" << endl;
        std::cin >> stop;
        if (stop < 4)
        {
            if (stop == 1)
            {
                int kelintas = 0;
                do
                {

                    do
                    {
                        std::cout << "Iveskite varda (arba 'done', jei norite baigti): ";
                        cin >> Masyvas[kelintas].vardas;
                        if (!tinkami(Masyvas[kelintas].vardas))
                        {
                            std::cout << "Vardas turi buti sudarytas tik is raidziu. Bandykite dar karta." << endl;
                        }
                    } while (!tinkami(Masyvas[kelintas].vardas));
                    if(Masyvas[kelintas].vardas=="done") break;

                    kiekis++;

                    do
                    {
                        std::cout << "Iveskite pavarde: ";
                        cin >> Masyvas[kelintas].pavarde;
                        if (!tinkami(Masyvas[kelintas].pavarde))
                        {
                            std::cout << "Pavarde turi buti sudaryta tik is raidziu. Bandykite dar karta." << endl;
                        }
                    } while (!tinkami(Masyvas[kelintas].pavarde));

                    int j = 0;
                    int pazymiukiekis = 1;
                    Masyvas[kelintas].pazymiai = new int[pazymiukiekis];

                    do
                    {
                        std::cout << "Iveskite pazymius (kai baigsite, parasykite -1): ";
                        int x; 
                        cin >> x;
                        if(x==-1) break; 
                        if (x< 0 || x > 10)
                        {
                            std::cout << "Neatitinka desimbales sistemos. Bandykite dar karta." << endl;
                        }
                        else{
                            Masyvas[kelintas].pazymiai[j]=x;
                            j++;
                        }
                        if(j==pazymiukiekis){
                            pazymiukiekis +=1; 
                            int * laikinas = new int[pazymiukiekis];
                            for(int i=0;i<j; i++){
                                laikinas[i] = Masyvas[kelintas].pazymiai[i];
                            }
                            delete [] Masyvas[kelintas].pazymiai;
                            Masyvas[kelintas].pazymiai = laikinas; 
                        }
                        
                    } while (true);

                    do
                    {
                        std::cout << "Iveskite egzamino rezultata: ";

                        cin >> Masyvas[kelintas].egzaminorez;
                        if (Masyvas[kelintas].egzaminorez < 0 || Masyvas[kelintas].egzaminorez > 10)
                        {
                            std::cout << "Neatitinka desimbales sistemos. Bandykite dar karta." << endl;
                        }
                    } while (Masyvas[kelintas].egzaminorez > 10 || Masyvas[kelintas].egzaminorez < 0);

                    vidurkis = 1.0* accumulate(Masyvas[kelintas].pazymiai, Masyvas[kelintas].pazymiai + pazymiukiekis, 0) / pazymiukiekis;
                    Masyvas[kelintas].galutinis = 0.4 * vidurkis + 0.6 * Masyvas[kelintas].egzaminorez;

                    sort(Masyvas[kelintas].pazymiai, Masyvas[kelintas].pazymiai + pazymiukiekis);

                    if (pazymiukiekis % 2 == 0)
                    {
                        Masyvas[kelintas].mediana = (Masyvas[kelintas].pazymiai[pazymiukiekis / 2] + Masyvas[kelintas].pazymiai[(pazymiukiekis / 2) - 1]) / 2.0;
                    }
                    else
                    {
                        Masyvas[kelintas].mediana = Masyvas[kelintas].pazymiai[pazymiukiekis / 2];
                    }

                    kelintas++;
                } while (Masyvas[kelintas].vardas != "done");
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
    return 0; 
}
