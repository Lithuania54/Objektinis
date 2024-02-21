#include <bits/stdc++.h>

using namespace std;

struct Studentas
{
    string vardas, pavarde;
    int egzaminorez;
    vector<int> pazymiai;
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

string RandomString(int ilgis)
{
    string possibleCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string randomString = "";
    srand(time(0));
    for (int i = 0; i < ilgis; i++)
    {
        randomString += possibleCharacters[rand() % possibleCharacters.size()];
    }
    return randomString;
}

int main()
{
    srand(time(0));
    double vidurkis = 0;
    int minusiukai = 80, stop, kiekis = 0;
    vector<Studentas> studentai;

    while (true)
    {
        Studentas s;
        std::cout << "1. - ranka\n2. - generuoti pazymius\n3. - generuoti ir pazymius ir studentu vardus, pavardes\n4. - skaityti is failo\n5. - baigti darba" << endl;
        std::cin >> stop;
        if (stop < 5)
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Iveskite skaiciu. Pasirinkite skaiciu nuo 1 iki 5." << endl;
                continue;
            }
            if (stop == 1)
            {
                do
                {

                    do
                    {
                        std::cout << "Iveskite varda (arba 'done', jei norite baigti): ";
                        cin >> s.vardas;
                        if (!tinkami(s.vardas))
                        {
                            std::cout << "Vardas turi buti sudarytas tik is raidziu. Bandykite dar karta." << endl;
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    } while (!tinkami(s.vardas));
                    if (s.vardas == "done")
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }

                    do
                    {
                        std::cout << "Iveskite pavarde: ";
                        cin >> s.pavarde;
                        if (!tinkami(s.pavarde))
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Pavarde turi buti sudaryta tik is raidziu. Bandykite dar karta." << endl;
                        }
                    } while (!tinkami(s.pavarde));

                    int j = 0;

                    int counter = 0;

                    do
                    {
                        std::cout << "Iveskite pazymius (kai baigsite, parasykite -1): ";
                        int x;
                        if (cin >> x && ((x > 0 && x <= 10) || (x == -1 && counter > 0)))
                        {
                            if (x == -1)
                            {
                                break;
                            }
                            s.pazymiai.push_back(x);
                            counter++;
                            j++;
                        }
                        else
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Neatitinka desimbales sistemos. Bandykite dar karta." << endl;
                        }
                    } while (true);

                    do
                    {
                        std::cout << "Iveskite egzamino rezultata: ";

                        if (cin >> s.egzaminorez && (s.egzaminorez > 0 && s.egzaminorez <= 10))
                        {
                            if (s.egzaminorez < 0 || s.egzaminorez > 10)
                            {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                std::cout << "Neatitinka desimbales sistemos. Bandykite dar karta." << endl;
                            }
                            else
                            {
                                break;
                            }
                        }
                        else
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Neatitinka desimbales sistemos. Bandykite dar karta." << endl;
                        }
                    } while (true);

                    vidurkis = 1.0 * std::accumulate(s.pazymiai.begin(), s.pazymiai.begin() + j, 0) / j;
                    s.galutinis = 0.4 * vidurkis + 0.6 * s.egzaminorez;

                    std::sort(s.pazymiai.begin(), s.pazymiai.begin() + j);

                    if (j % 2 == 0)
                    {
                        s.mediana = (s.pazymiai[j / 2] + s.pazymiai[(j / 2) - 1]) / 2.0;
                    }
                    else
                    {
                        s.mediana = s.pazymiai[j / 2];
                    }

                    kiekis++;
                    studentai.push_back(s);
                } while (s.vardas != "done");
            }

            else if (stop == 2)
            {

                do
                {
                    std::cout << "Iveskite varda (arba 'done', jei norite baigti): ";
                    cin >> s.vardas;
                    if (!tinkami(s.vardas))
                    {
                        std::cout << "Vardas turi buti sudarytas tik is raidziu. Bandykite dar karta." << endl;
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                } while (!tinkami(s.vardas));
                if (s.vardas == "done")
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }

                do
                {
                    std::cout << "Iveskite pavarde: ";
                    cin >> s.pavarde;
                    if (!tinkami(s.pavarde))
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Pavarde turi buti sudaryta tik is raidziu. Bandykite dar karta." << endl;
                    }
                } while (!tinkami(s.pavarde));

                std::vector<int>::size_type j = 0;

                for (int i = 0; i < 10; i++)
                {
                    s.pazymiai.push_back(rand() % 11);
                    j++;
                }

                s.egzaminorez = rand() % 11;

                vidurkis = 1.0 * std::accumulate(s.pazymiai.begin(), s.pazymiai.begin() + j, 0) / j;
                s.galutinis = 0.4 * vidurkis + 0.6 * s.egzaminorez;

                std::sort(s.pazymiai.begin(), s.pazymiai.begin() + j);
                if (j % 2 == 0)
                {
                    s.mediana = (s.pazymiai[j / 2] + s.pazymiai[(j / 2) - 1]) / 2.0;
                }
                else
                {
                    s.mediana = s.pazymiai[j / 2];
                }
                kiekis++;
            }

            else if (stop == 3)
            {
                s.vardas = RandomString(10);
                s.pavarde = RandomString(10);

                for (int i = 0; i < 10; i++)
                {
                    s.pazymiai.push_back(rand() % 10 + 1);
                }

                s.egzaminorez = rand() % 10 + 1;

                vidurkis = accumulate(s.pazymiai.begin(), s.pazymiai.end(), 0.0) / s.pazymiai.size();
                s.galutinis = 0.4 * vidurkis + 0.6 * s.egzaminorez;

                sort(s.pazymiai.begin(), s.pazymiai.end());
                if (s.pazymiai.size() % 2 == 0)
                {
                    s.mediana = (s.pazymiai[s.pazymiai.size() / 2] + s.pazymiai[(s.pazymiai.size() / 2) - 1]) / 2.0;
                }
                else
                {
                    s.mediana = s.pazymiai[s.pazymiai.size() / 2];
                }

                kiekis++;
            }

            if (stop == 4)
            {
                std::ifstream fd("studentai10000.txt");
                string line;
                std::stringstream buffer;
                buffer << fd.rdbuf();

                getline(buffer, line);

                while (getline(buffer, line))
                {
                    stringstream ss(line);
                    Studentas s;
                    ss >> s.vardas >> s.pavarde;
                    int pazymys;
                    kiekis++;
                    while (ss >> pazymys)
                    {
                        if (pazymys >= 1 && pazymys <= 10)
                            s.pazymiai.push_back(pazymys);
                    }
                    s.egzaminorez = s.pazymiai.back();
                    s.pazymiai.pop_back();

                    double vidurkis = accumulate(s.pazymiai.begin(), s.pazymiai.end(), 0.0) / s.pazymiai.size();
                    s.galutinis = 0.4 * vidurkis + 0.6 * s.egzaminorez;

                    sort(s.pazymiai.begin(), s.pazymiai.end());
                    int j = s.pazymiai.size();
                    if (j % 2 == 0)
                    {
                        s.mediana = (s.pazymiai[j / 2 - 1] + s.pazymiai[j / 2]) / 2.0;
                    }
                    else
                    {
                        s.mediana = s.pazymiai[j / 2];
                    }

                    studentai.push_back(s);
                }
                fd.close();
            }
        }
        if (stop != 5)
        {
            studentai.push_back(s);
        }
        if (stop == 5)
        {
            if (kiekis > 0)
            {
                int pasirinkimas;
                cout << "Rusiavimas: 1 - Vardas, 2 - Pavarde, 3 - Galutinis vidurkis, 4 - Galutinis mediana" << endl;
                while (!(cin >> pasirinkimas) || pasirinkimas < 1 || pasirinkimas > 5)
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Pasirinkti is: 1 - Vardas, 2 - Pavarde, 3 - Galutinis vidurkis, 4 - Galutinis mediana\n";
                }
                switch (pasirinkimas)
                {
                case 1:
                    sort(studentai.begin(), studentai.end(), [](Studentas &a, Studentas &b)
                         { return a.vardas < b.vardas; });
                    break;
                case 2:
                    sort(studentai.begin(), studentai.end(), [](Studentas &a, Studentas &b)
                         { return a.pavarde < b.pavarde; });
                    break;
                case 3:
                    sort(studentai.begin(), studentai.end(), [](Studentas &a, Studentas &b)
                         { return a.galutinis < b.galutinis; });
                    break;
                case 4:
                    sort(studentai.begin(), studentai.end(), [](Studentas &a, Studentas &b)
                         { return a.mediana < b.mediana; });
                    break;
                }
                break;
            }
            else
            {
                break;
            }
        }
        if (stop > 5 || stop < 1)
        {
            cout << "Pasirinkite nuo 1 iki 5" << endl;
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
        std::cout << left << studentai[i].pavarde;
        std::cout.width(15);
        std::cout << left << studentai[i].vardas;
        std::cout.width(23);
        std::cout << left << fixed << setprecision(2) << studentai[i].galutinis;
        std::cout.width(23);
        std::cout << left << fixed << setprecision(2) << studentai[i].mediana << endl;
    }

    return 0;
}
