# Efektyvumo Tyrimai: Masyvai vs. Vektoriai C++

# Apžvalga
Projektas skirtas efektyvumo lyginimui tarp masyvų ir vektorių C++ programavimo kalboje, atliekant pagrindines operacijas su studentų duomenimis. Tyrimu siekiama identifikuoti, kuri duomenų struktūra yra efektyvesnė skirtingose situacijose.

# Rezultatai
Masyvai **(Masyvai.cpp)**: Demonstruoja greitesnę duomenų prieigos laiką, tačiau prastesnę dinamiškumo ir atminties valdymo efektyvumą.
Vektoriai **(Vektoriai.cpp)**: Pasižymi lankstesne atminties valdymo sistema ir efektyvesniu elementų įterpimu bei šalinimu, dėl galimybės dinamiškai keisti dydį.

# Išvados
Vektorius yra pranašesnis pasirinkimas situacijose, kai reikalingas dinamiškas duomenų kiekio keitimas, o masyvai - kai prioritetas teikiamas greitai prieigai prie nesikeičiančio duomenų kiekio.

# Paleidimas
1. *g++ -o vektoriai Vektoriai.cpp* ir *.\vektoriai.exe*
2. *g++ -o masyvai Masyvai.cpp* ir *.\masyvai.exe*
