#include "Funkcijos.h"
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include <string>
#include <iomanip>

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
    outFile << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde";
    for (int i = 1; i <= ndkiekis; i++)
    {
        outFile << std::left << std::setw(2) << "ND" << std::setw(2) << i << " ";
    }
    outFile << std::left << std::setw(5) << "Egz." << "\n";

    for (int i = 0; i < zmoniusk; i++)
    {
        std::string v = "Vardas" + std::to_string(i);
        std::string p = "Pavarde" + std::to_string(i);
        outFile << std::setw(15) << v << std::setw(15) << p;
        for (int j = 0; j < ndkiekis; ++j)
        {
            outFile << std::left << std::setw(4) << rand() % 10 + 1 << " ";
        }
        outFile << std::left << std::setw(5) << rand() % 10 + 1 << "\n";
    }
    outFile.close();
}