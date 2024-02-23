#include "Utilities.h"
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdexcept>

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

void checkFileExists(const std::string& fileName)
{
    std::ifstream infile(fileName);
    if (!infile.good())
    {
        throw std::runtime_error("Failas " + fileName + " nerastas.");
    }
}
