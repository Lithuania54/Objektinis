#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <string>
#include <list>
#include "Studentas.h"

bool tinkami(const std::string &name);
std::string RandomString(int ilgis);
void yrafailas(const std::string& fileName);
void generuotiFaila(int zmoniusk, const std::string &failopavadinimas, int ndkiekis);
void irasytiStudentus(const std::list<Studentas>& students, const std::string& fileName);

#endif
