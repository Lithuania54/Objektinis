#ifndef FUNKCIJOSDEQUE_H
#define FUNKCIJOSDEQUE_H

#include <string>
#include <deque>
#include "Studentasdeque.h"

bool tinkami(const std::string &name);
std::string RandomString(int ilgis);
void yrafailas(const std::string& fileName);
void generuotiFaila(int zmoniusk, const std::string &failopavadinimas, int ndkiekis);
void irasytiStudentus(const std::deque<Studentas>& students, const std::string& fileName);

#endif
