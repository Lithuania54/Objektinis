#include <bits/stdc++.h>
using namespace std;

struct {
  string vardas;
  string pavarde;
  int rezultatai;
  int egzorezultatai;
  double Galutinis;
  int suma;
} Struktura;

int main()
{
  // ifstream fd("duota.txt");
  // ofstream fr("rezultatai.txt");

  int n, mokiniuSK = 0;
  cin>>mokiniuSK;
  for (int j = 0; j < mokiniuSK; j++){
  cin>>Struktura.vardas>>Struktura.pavarde>>n;

  for (int i = 0; i < n; i++){
    cin>>Struktura.rezultatai;
    Struktura.suma = Struktura.suma + Struktura.rezultatai;
  }

  Struktura.suma = Struktura.suma / n;

  Struktura.Galutinis = 0.4 * Struktura.suma + 0.6 * Struktura.rezultatai;
  }

  cout<<"Pavardė        "<<"Vardas        "<<"Galutinis (Vid.)"<<endl;
  cout<<"-----------------------------------------------------"<<endl;

  for (int j = 0; j < mokiniuSK; j++){
  cout<<Struktura.pavarde<<Struktura.vardas<<Struktura.Galutinis<<endl;}
}
