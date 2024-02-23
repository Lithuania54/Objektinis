#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

struct Studentas
{
    std::string vardas, pavarde;
    int egzaminorez;
    std::vector<int> pazymiai;
    double galutinis, mediana;
};

#endif
