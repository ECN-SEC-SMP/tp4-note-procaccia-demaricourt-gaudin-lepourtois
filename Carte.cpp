/*#include "Carte.hpp"

using namespace std;

Carte::Carte(ofstream file){
  surfaceTotale=0;

  // parse file to get the Parcelle objects
 
  string fileString;

  file >> fileString;

  cout << fileString << endl;
  file.close();

  const string regZAU = "(?<type>ZAU) (?<number>[0-9]+) (?<proprietaire>[\w']+) (?<constructible>[0-9]+)\n(?<polygone>\[[[\d\W ]+\])[\n]?";
  const string regZU = "(?<type>ZU) (?<number>[0-9]+) (?<proprietaire>[\w']+) (?<constructible>[0-9]+) (?<tible>[0-9]+)\n(?<polygone>\[[[\d\W ]+\])[\n]?";
  const string regZA = "(?<type>ZA) (?<number>[0-9]+) (?<proprietaire>[\w']+) (?<culture>[\wéï]+)\n(?<polygone>\[[[\d\W ]+\])[\n]?";
  const string regZN = "(?<type>ZN) (?<number>[0-9]+) (?<proprietaire>[\w']+)\n(?<polygone>\[[[\d\W ]+\])[\n]?";

  // calculate surfaceTotale by adding the surface of every Parcelle object
  vector<Parcelle>::iterator it = parcelles.begin();
  for(it; it < parcelles.end(); it++){
    surfaceTotale+=it->getSurface();
  }
}

void Carte::saveCarte(string fileName){
  
}*/