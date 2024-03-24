#ifndef STUDENTASDEQUE_H
#define STUDENTASDEQUE_H

#include <deque>
#include <string>
#include <bits/stdc++.h>
#include <chrono>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <chrono>

struct Studentas
{
    std::string vardas, pavarde;
    int egzaminorez;
    std::deque<int> pazymiai;
    double galutinis, mediana;
};

#endif
