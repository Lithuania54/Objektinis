#ifndef FUNKCIJOSDEQUE_H
#define FUNKCIJOSDEQUE_H

#include "Studentasdeque.h"

bool tinkami(const std::string &name);
std::string RandomString(int ilgis);
void yrafailas(const std::string& fileName);
void generuotiFaila(int zmoniusk, const std::string &failopavadinimas, int ndkiekis);
void irasytiStudentus(const std::deque<Studentas>& students, const std::string& fileName);
void Strategija3(std::deque<Studentas> &studentai);
void Strategija1(std::deque<Studentas> &studentai);
void Strategija2(std::deque<Studentas> &studentai);

#endif
