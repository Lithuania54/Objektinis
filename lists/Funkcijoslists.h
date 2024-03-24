#ifndef FUNKCIJOSLISTS_H
#define FUNKCIJOSLISTS_H

#include <string>
#include <list>
#include "Studentaslists.h"

bool tinkami(const std::string &name);
std::string RandomString(int ilgis);
void yrafailas(const std::string& fileName);
void generuotiFaila(int zmoniusk, const std::string &failopavadinimas, int ndkiekis);
void irasytiStudentus(const std::list<Studentas>& students, const std::string& fileName);
void Strategija3(std::list<Studentas> &studentai);
void Strategija1(std::list<Studentas> &studentai);
void Strategija2(std::list<Studentas> &studentai);

#endif
