#include "Carte.hpp"

using namespace std;

Carte::Carte(ifstream& inputFile) {
  // parse file to get the Parcelle objects

  const string regZAU = R"(?<type>ZAU) (?<number>[0-9]+) (?<proprietaire>[\w']+) (?<constructible>[0-9]+) (?<surface>[0-9]+)";
  const string regZU = R"(?<type>ZU) (?<n<proprietaire>[\w']+) (?<constructible>[0-9]+) (?<tible>[0-9]+) (?<surface>[0-9]+)";
  const string regZA = R"(?<type>ZA) (?<number>[0-9]+) (?<proprietaire>[\w']+) (?<culture>[\wéï]+)";    
  const string regZN = R"(?<type>ZN) (?<number>[0-9]+) (?<proprietaire>[\w']+) (?<surface>[0-9]+)";

  //(?<polygone>\[[[\d\W ]+\])[ ]?       AVANT
  const string regPolygon = R"(\[([\d\s;,]+)\])";
  
  string fileString;

  while (getline(inputFile, fileString)) {
    smatch match;

    if (regex_search(fileString, match, regex(regZAU))) {
      // Create a new Parcelle object using the values from the match and add it to the vector
      ZAU p(stoi(match[2]), match[3], stoi(match[4]), stoi(match[5]), stoi(match[6]), match[7]);
      this->parcelles.push_back(p);
    }
    else if (regex_search(fileString, match, regex(regZU))) {
      // Create a new Parcelle object using the values from the match and add it to the vector
      ZU p(stoi(match[2]), match[3], stoi(match[4]), stoi(match[5]), stoi(match[6]), match[7]);
      this->parcelles.push_back(p);
    }
    else if (regex_search(fileString, match, regex(regZA))) {
      // Create a new Parcelle object using the values from the match and add it to the vector
      ZA p(stoi(match[2]), match[3], match[4], match[5]);
      this->parcelles.push_back(p);
    }
    else if (regex_search(fileString, match, regex(regZN))) {
      // Create a new Parcelle object using the values from the match and add it to the vector
      ZN p(stoi(match[2]), match[3], stoi(match[4]), match[5]);
      this->parcelles.push_back(p);
    }
  }

  // calculate surfaceTotale by adding the surface of every Parcelle object
  this->surfaceTotale=0;
  vector<Parcelle>::iterator it = this->parcelles.begin();
  for(it; it < this->parcelles.end(); it++){
    this->surfaceTotale+=it->getSurface();
  }
}


void Carte::saveCarte(string savePath){
  ofstream saveFile (savePath);
  string fileContent;

  // mettre les attributs des parcelles dans la string fileContent
  vector<Parcelle>::iterator it = this->parcelles.begin();
  for(it; it < this->parcelles.end(); it++){
    fileContent+= ; //type
    fileContent+=" ";
    fileContent+=to_string(it->getNumero());
    fileContent+=" ";
    fileContent+=it->getProprietaire();
    
    if(){ //ZU
      fileContent+=" ";
      fileContent+=to_string(it->getPConstructible());
    }
    else if(){ //ZAU
      fileContent+=" ";
      fileContent+=to_string(it->getPConstructible());
      fileContent+=" ";
      fileContent+=; // surface construite
    }
    else if(){ //ZA
      fileContent+=" ";
      fileContent+=; // culture
    }

    fileContent+="\n";
    fileContent+= ; //points
  }
  
  saveFile << fileContent;
  saveFile.close();
}