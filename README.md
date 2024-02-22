# Efektyvumo Tyrimai

## Tyrimo Metodika
Atlikome tyrimus su trimis skirtingais duomenų rinkiniais: 10000, 100000 ir 1000000 įrašų.

## Rezultatai
Rezultatai parodė, kad veikimo laikas didėja eksponentiškai didinant įrašų skaičių. Pavyzdžiui, skaitymas iš failo su 10000 įrašų užtruko apie 36 milisekundes, su 100000 įrašų apie 525 milisekundes, o su 1000000 įrašų apie 2520 milisekundžių.

## Išvados
Išvada, kad veikimo laikas stipriai priklauso nuo apdorojamų duomenų kiekio.

## Paleidimas
*g++ -o vektoriai Vektoriai.cpp* ir *.\vektoriai.exe*
