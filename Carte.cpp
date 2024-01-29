#include "Carte.hpp"

using namespace std;

// Je modifie ça de mon côté
Carte::Carte(ifstream& inputFile) {
  // parse file to get the Parcelle objects

  const string regZAU = R"(?<type>ZAU) (?<number>[0-9]+) (?<proprietaire>[\w']+)
(?<constructible>[0-9]+) (?<surface>[0-9]+)"; 
  const string regZU = R"(?<type>ZU)
(?<n<proprietaire>[\w']+) (?<constructible>[0-9]+) (?<tible>[0-9]+)
(?<surface>[0-9]+)"; 
  const string regZA = R"(?<type>ZA) (?<number>[0-9]+)
(?<proprietaire>[\w']+) (?<culture>[\wéï]+)"; 
  const string regZN = R"(?<type>ZN)
(?<number>[0-9]+) (?<proprietaire>[\w']+) (?<surface>[0-9]+)";

  //(?<polygone>\[[[\d\W ]+\])[ ]?       AVANT
  const string regPolygon = R"(\[([\d\s;,]+)\])";

  string fileString;

  while (getline(inputFile, fileString)) {
    smatch match;

    if (regex_search(fileString, match, regex(regZAU))) {
      // Create a new Parcelle object using the values from the match and add it to the vector 
      ZAU p(stoi(match[2]), match[3], stoi(match[4]), stoi(match[5]), stoi(match[6]), match[7]); this->parcelles.push_back(p);
    }
    else if (regex_search(fileString, match, regex(regZU))) {
      // Create a new Parcelle object using the values from the match and add it to the vector 
      ZU p(stoi(match[2]), match[3], stoi(match[4]), stoi(match[5]), stoi(match[6]), match[7]); this->parcelles.push_back(p);
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

void Carte::saveCarte(string savePath) {
  ofstream saveFile(savePath);
  string fileContent;

  // mettre les attributs des parcelles dans la string fileContent
  vector<Parcelle>::iterator it = this->parcelles.begin();
  for (it; it < this->parcelles.end(); it++) {
    fileContent += it->getType();
    fileContent += " ";
    fileContent += to_string(it->getNumero());
    fileContent += " ";
    fileContent += it->getProprietaire();

    if (it->getType() == "ZU") {
      fileContent += " ";
      fileContent += to_string(it->getPConstructible());
      fileContent += " ";
      fileContent += dynamic_cast<ZU &>(*it).getSurfaceConstruite();
    } else if (it->getType() == "ZAU") {
      fileContent += " ";
      fileContent += to_string(it->getPConstructible());
    } else if (it->getType() == "ZA") {
      fileContent += " ";
      fileContent += (dynamic_cast<ZA &>(*it)).getCulture();
    }

    fileContent += "\n\r";
    saveFile << fileContent; // puts the content into the file
    for(int i=0; i<4; i++){ // points
      saveFile << it->getForme().getSommets()[i]; // put the output of Point2D's << operator straight into the file
      fileContent += " "; // add space and put it into the file
      saveFile << fileContent;
    }
  }
  saveFile.close();
}