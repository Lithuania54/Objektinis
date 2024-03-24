#include "Funkcijoslists.h"
#include "Studentaslists.h"

bool tinkami(const std::string &name)
{
    for (char ch : name)
    {
        if (!std::isalpha(ch))
        {
            return false;
        }
    }
    return true;
}

std::string RandomString(int ilgis)
{
    std::string possibleCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string randomString = "";
    srand(time(0));
    for (int i = 0; i < ilgis; i++)
    {
        randomString += possibleCharacters[rand() % possibleCharacters.size()];
    }
    return randomString;
}

void yrafailas(const std::string &fileName)
{
    std::ifstream infile(fileName);
    if (!infile.good())
    {
        throw std::runtime_error(fileName);
    }
}

void generuotiFaila(int zmoniusk, const std::string &failopavadinimas, int ndkiekis)
{
    std::ofstream outFile(failopavadinimas);
    outFile << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
    for (int i = 1; i <= ndkiekis; i++)
    {
        outFile << std::left << std::setw(2) << "ND" << std::setw(2) << i << " ";
    }
    outFile << std::left << std::setw(5) << "Egz."
            << "\n";

    for (int i = 0; i < zmoniusk; i++)
    {
        std::string v = "Vardas" + std::to_string(i);
        std::string p = "Pavarde" + std::to_string(i);
        outFile << std::setw(20) << v << std::setw(20) << p;
        for (int j = 0; j < ndkiekis; j++)
        {
            outFile << std::left << std::setw(4) << rand() % 10 + 1 << " ";
        }
        outFile << std::left << std::setw(5) << rand() % 10 + 1 << "\n";
    }
    outFile.close();
}

void irasytiStudentus(const std::list<Studentas> &studentai, const std::string &failoVardas)
{
    std::ofstream outFile(failoVardas);
    outFile << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis"
            << "\n";
    for (const auto &studentas : studentai)
    {
        outFile << std::left << std::setw(20) << studentas.vardas
                << std::left << std::setw(20) << studentas.pavarde
                << std::left << std::setw(10) << std::fixed << std::setprecision(2) << studentas.galutinis << "\n";
    }
    outFile.close();
}

void Strategija1(std::list<Studentas> &studentai)
{
    std::list<Studentas> pazenge, nepazenge;

    auto starta = std::chrono::high_resolution_clock::now();
    for (Studentas &student : studentai)
    {
        if (student.galutinis < 5)
        {
            nepazenge.push_back(student);
        }
        else
        {
            pazenge.push_back(student);
        }
    }
    auto ending = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> differ = ending - starta;
    std::cout << "Skirstymas (Strategija1): " << differ.count() << " sekundes" << std::endl;

    irasytiStudentus(nepazenge, "nepazenge.txt");
    irasytiStudentus(pazenge, "pazenge.txt");
}

void Strategija2(std::list<Studentas> &studentai) {
    std::list<Studentas> nepazenge;

    auto starta = std::chrono::high_resolution_clock::now();
    for (const Studentas &student : studentai) {
        if (student.galutinis < 5) {
            nepazenge.push_back(student);
        }
    }

    studentai.remove_if([](const Studentas &s) { return s.galutinis < 5; });

    auto ending = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> differ = ending - starta;
    std::cout << "Skirstymas (Strategija2): " << differ.count() << "sekundes" << std::endl;

    irasytiStudentus(nepazenge, "nepazenge.txt");
    irasytiStudentus(studentai, "studentai.txt");
}

void Strategija3(std::list<Studentas> &studentai)
{
    std::list<Studentas> nepazenge;
    auto startas = std::chrono::high_resolution_clock::now();

    for (auto it = studentai.begin(); it != studentai.end();)
    {
        if (it->galutinis < 5)
        {
            nepazenge.push_back(std::move(*it));
            it = studentai.erase(it);
        }
        else
        {
            ++it;
        }
    }

    auto endas = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = endas - startas;
    std::cout << "Surusiavimas ir skirstymas: " << diff.count() << " sekundes" << std::endl;
    irasytiStudentus(nepazenge, "nepazenge.txt");
    irasytiStudentus(studentai, "studentai.txt");
}
