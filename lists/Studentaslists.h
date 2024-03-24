#ifndef STUDENTASLISTS_H
#define STUDENTASLISTS_H

#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <chrono>
#include <algorithm>
#include <bits/stdc++.h>

struct Studentas
{
    std::string vardas, pavarde;
    int egzaminorez;
    std::list<int> pazymiai;
    double galutinis, mediana;
};

#endif
