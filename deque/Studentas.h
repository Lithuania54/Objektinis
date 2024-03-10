#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <deque>
#include <string>

struct Studentas
{
    std::string vardas, pavarde;
    int egzaminorez;
    std::deque<int> pazymiai;
    double galutinis, mediana;
};

#endif
