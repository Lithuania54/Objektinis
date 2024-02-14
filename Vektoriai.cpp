#include <bits/stdc++.h>
#include <random>

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

void resize_vector(vector<Studentas> &vec, int new_capacity) {
    vector<Studentas> temp(new_capacity);
    copy(vec.begin(), vec.end(), temp.begin());
    vec.swap(temp);
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
    int minusiukai = 80, stop, capacity = 10;
    unsigned int kiekis;
    vector<Studentas> studentai(static_cast<std::vector<Studentas>::size_type>(capacity));

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
                    resize_vector(studentai, capacity * 2);
                }
                do
                {

                    do
                    {
                        std::cout << "Iveskite varda (arba 'done', jei norite baigti): ";
                        cin >> studentai[kiekis].vardas;
                        if (!tinkami(studentai[kiekis].vardas))
                        {
                            std::cout << "Vardas turi buti sudarytas tik is raidziu. Bandykite dar karta." << endl;
                        }
                    } while (!tinkami(studentai[kiekis].vardas));
                    if (studentai[kiekis].vardas == "done")
                        break;

                    do
                    {
                        std::cout << "Iveskite pavarde: ";
                        cin >> studentai[kiekis].pavarde;
                        if (!tinkami(studentai[kiekis].pavarde))
                        {
                            std::cout << "Pavarde turi buti sudaryta tik is raidziu. Bandykite dar karta." << endl;
                        }
                    } while (!tinkami(studentai[kiekis].pavarde));

                    int j = 0;

                    do
                    {
                        std::cout << "Iveskite pazymius (kai baigsite, parasykite -1): ";
                        int x;
                        if (cin >> x && ((x > 0 && x <= 10) || x == -1))
                        {
                            if (x == -1)
                            {
                                break;
                            }
                            studentai[kiekis].pazymiai.push_back(x);
                            j++;
                        }
                        else
                        {
                            std::cout << "Neatitinka desimbales sistemos. Bandykite dar karta." << endl;
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    } while (true);

                    do
                    {
                        std::cout << "Iveskite egzamino rezultata: ";

                        if (cin >> studentai[kiekis].egzaminorez && (studentai[kiekis].egzaminorez > 0 && studentai[kiekis].egzaminorez <= 10))
                        {
                            if (studentai[kiekis].egzaminorez < 0 || studentai[kiekis].egzaminorez > 10)
                            {
                                std::cout << "Neatitinka desimbales sistemos. Bandykite dar karta." << endl;
                            }
                        }
                        else
                        {
                            std::cout << "Neatitinka desimbales sistemos. Bandykite dar karta." << endl;
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    } while (true);

                    vidurkis = 1.0 * std::accumulate(studentai[kiekis].pazymiai.begin(), studentai[kiekis].pazymiai.begin() + j, 0) / j;
                    studentai[kiekis].galutinis = 0.4 * vidurkis + 0.6 * studentai[kiekis].egzaminorez;

                    std::sort(studentai[kiekis].pazymiai.begin(), studentai[kiekis].pazymiai.begin() + j);

                    if (j % 2 == 0)
                    {
                        studentai[kiekis].mediana = (studentai[kiekis].pazymiai[j / 2] + studentai[kiekis].pazymiai[(j / 2) - 1]) / 2.0;
                    }
                    else
                    {
                        studentai[kiekis].mediana = studentai[kiekis].pazymiai[j / 2];
                    }

                    kiekis++;
                } while (studentai[kiekis].vardas != "done");
            }

            else if (stop == 2)
            {
                if (kiekis == capacity) {
                    resize_vector(studentai, capacity * 2);
                }

                do
                {
                    std::cout << "Iveskite varda (arba 'done', jei norite baigti): ";
                    cin >> studentai[kiekis].vardas;
                    if (!tinkami(studentai[kiekis].vardas))
                    {
                        std::cout << "Vardas turi buti sudarytas tik is raidziu. Bandykite dar karta." << endl;
                    }
                } while (!tinkami(studentai[kiekis].vardas));
                if (studentai[kiekis].vardas == "done")
                    break;

                do
                {
                    std::cout << "Iveskite pavarde: ";
                    cin >> studentai[kiekis].pavarde;
                    if (!tinkami(studentai[kiekis].pavarde))
                    {
                        std::cout << "Pavarde turi buti sudaryta tik is raidziu. Bandykite dar karta." << endl;
                    }
                } while (!tinkami(studentai[kiekis].pavarde));

                std::vector<int>::size_type j = 0;

                for (int i = 0; i < 10; i++)
                {
                    studentai[kiekis].pazymiai.push_back(rand() % 11);
                    j++;
                }
                studentai[kiekis].egzaminorez = rand() % 11;
                vidurkis = 1.0 * std::accumulate(studentai[kiekis].pazymiai.begin(), studentai[kiekis].pazymiai.begin() + j, 0) / j;
                studentai[kiekis].galutinis = 0.4 * vidurkis + 0.6 * studentai[kiekis].egzaminorez;
                std::sort(studentai[kiekis].pazymiai.begin(), studentai[kiekis].pazymiai.begin() + j);
                if (j % 2 == 0)
                {
                    studentai[kiekis].mediana = (studentai[kiekis].pazymiai[j / 2] + studentai[kiekis].pazymiai[(j / 2) - 1]) / 2.0;
                }
                else
                {
                    studentai[kiekis].mediana = studentai[kiekis].pazymiai[j / 2];
                }
                kiekis++;
            }

            else if (stop == 3)
            {
                if (kiekis == capacity) {
                    resize_vector(studentai, capacity * 2);
                }
                studentai[kiekis].vardas = generateRandomString(10);
                studentai[kiekis].pavarde = generateRandomString(10);
                int j = 0;
                for (int i = 0; i < 10; i++)
                {
                    studentai[kiekis].pazymiai[j] = rand() % 11;
                    j++;
                }
                studentai[kiekis].egzaminorez = rand() % 11;
                vidurkis = 1.0 * std::accumulate(studentai[kiekis].pazymiai.begin(), studentai[kiekis].pazymiai.begin() + j, 0) / j;
                studentai[kiekis].galutinis = 0.4 * vidurkis + 0.6 * studentai[kiekis].egzaminorez;
                std::sort(studentai[kiekis].pazymiai.begin(), studentai[kiekis].pazymiai.begin() + j);
                if (j % 2 == 0)
                {
                    studentai[kiekis].mediana = (studentai[kiekis].pazymiai[j / 2] + studentai[kiekis].pazymiai[(j / 2) - 1]) / 2.0;
                }
                else
                {
                    studentai[kiekis].mediana = studentai[kiekis].pazymiai[j / 2];
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