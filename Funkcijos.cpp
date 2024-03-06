#include "Funkcijos.h"
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <chrono>
#include "Studentas.h"

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
    auto start_write = std::chrono::high_resolution_clock::now();
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
    auto end_write = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff_write = end_write - start_write;
    std::cout << "Failo kurimas " << diff_write.count() << " seconds" << std::endl;
}

void irasytiStudentus(const std::vector<Studentas> &studentai, const std::string &failoVardas)
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
