#ifndef STUDENTASDEQUE_H
#define STUDENTASDEQUE_H

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
