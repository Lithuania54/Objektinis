#ifndef FUNKCIJOSVECTOR_H
#define FUNKCIJOSVECOTR_H

#include <string>
#include <vector>
#include "Studentasvector.h"

bool tinkami(const std::string &name);
std::string RandomString(int ilgis);
void yrafailas(const std::string& fileName);
void generuotiFaila(int zmoniusk, const std::string &failopavadinimas, int ndkiekis);
void irasytiStudentus(const std::vector<Studentas>& students, const std::string& fileName);

#endif
