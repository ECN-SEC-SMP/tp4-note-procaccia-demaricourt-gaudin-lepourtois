#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>  // Pour std::unique_ptr

#include "Point2D.hpp"
#include "Polygone.hpp"
#include "za.hpp"
#include "zau.hpp"
#include "zn.hpp"
#include "zu.hpp"

#include "Carte.hpp"

using namespace std;

void testPolygone();
void testPoint();
void testZAD();
void testCarte();

int main()
{
  /*================================================================*/
  /*================================================================*/
  /*                          JEU DE TESTS                          */
  /*================================================================*/
  /*================================================================*/

  /*==========================*/
  /*    TESTING DE POINT2D    */
  /*==========================*/
  testPoint();
  /*==========================*/
  /*     TESTING POLYGONE     */
  /*==========================*/
  testPolygone();
  /*==========================*/
  /* TESTING Specific PARCELLE*/
  /*==========================*/
  testZAD();
  /*==========================*/
  /*       TESTING CARTE      */
  /*==========================*/
  testCarte();
}

void testPoint()
{
  cout  << "--------------------------" << endl
        << "      TESTING POINT2D     " << endl
        << "--------------------------" << endl << endl;
  // CREATE POINT
  Point2D<int> pointA(2, 2);
  Point2D<float> pointB(2.5, 0.5);
  Point2D<int> pointC;
  cout << "Point A : " << pointA << endl
       << "Point B : " << pointB << endl
       << "Point C : " << pointC << endl;

  // TRANSLATE
  pointB.translate(pointA.getX(), pointA.getY());
  cout << "Point B translaté de point A : " << pointB << endl;

  // COPY
  Point2D<int> pointD(pointA);
  cout << "Point D construit par recopie de point A : " << pointD << endl;
}

void testPolygone()
{
  cout  << endl
        << "--------------------------" << endl
        << "     TESTING POLYGONE     " << endl
        << "--------------------------" << endl << endl;
  Point2D<int> pointA(2, 2);
  Point2D<float> pointB(2.5, 0.5);
  Point2D<int> pointC;
  Point2D<int> pointD(pointA);

  // DEFAULT
  Polygone<float> polygoneA;

  // CONSTRUCTOR
  Polygone<int> polygoneB(vector<Point2D<int>>{pointA, pointD, pointC});
  cout << "Polygone A construit par défaut : " << polygoneA << endl;
  cout << "Polygone B vecteur de point A, C et D : " << polygoneB << endl;

  Polygone<int> polygoneForGui("[128;100] [146;171] [102;194] [55;100] [111;50]");
  cout << "Polygone pour Gui avec ajout de points : " << polygoneForGui << endl;

  // ADD
  polygoneA.addPoint(pointB);
  polygoneA.addPoint(Point2D<float>(1.2, 3.0));
  polygoneA.addPoint(Point2D<float>(3.7, 2.0));
  cout << "Polygone A avec ajout de points : " << polygoneA << endl;

  // TRANSLATE
  polygoneA.translate(1.5, 0.5);
  cout << "Polygone A translaté de (1.5; 0.5) : " << polygoneA << endl;

  // COPY & RESET PEAKS OF POLY A
  Polygone<float> polygoneC(polygoneA);
  polygoneA.setSommets(vector<Point2D<float>>{pointB, Point2D<float>(1.0, 3.0), Point2D<float>(10.0, 10.0)});
  cout << "Polygone C construit par recopie de Polygone A : " << polygoneC << endl;
  cout << "Polygone A redef des sommets : " << polygoneA << endl;
}

void testZAD()
{
  cout  << endl
        << "--------------------------" << endl
        << "TESTING Specific PARCELLE " << endl
        << "--------------------------" << endl << endl;
  Point2D<int> pointA(2, 2);
  Point2D<float> pointB(2.5, 0.5);
  Point2D<int> pointC;
  Point2D<int> pointD(pointA);

  Polygone<int> polygone(vector<Point2D<int>>{pointA, pointD, pointC});

  ZN zn(1, string("Gui"), polygone, 4);
  ZA za(2, string("Polo"), polygone, "Blé", 8);
  ZAU zau(3, string("Simzer"), polygone, 10);
  ZU zu(4, string("Jiben"), polygone, 16, 10.0);
  
  cout << zn << endl << za << endl << zau << endl << zu << endl << endl;
}

void testCarte() 
{
  cout  << endl
        << "--------------------------" << endl
        << "       TESTING CARTE      " << endl
        << "--------------------------" << endl << endl;
  // Test surcharge << de ZA
  ZA za(10, "Jiben", Polygone<int>("[0;0] [10;0] [10;10] [0;10]"), "Blé", 50);
  cout << za << endl;

  ifstream inputFile("Parcelles.txt");
  if (inputFile.is_open()) {
    Carte maCarte(inputFile);
    inputFile.close();

    /// Afficher les propriétés de chaque Parcelle spécifique dans le vecteur
    for (const auto& parcelle : maCarte.getParcelles()) {
      if (parcelle->getType() == "ZU") {
        cout << dynamic_cast<ZU &>(*parcelle) << endl;  // Utilise l'opérateur << surchargé de la classe spécifique
      } else if (parcelle->getType() == "ZAU") {
        cout << dynamic_cast<ZAU &>(*parcelle) << endl;  // Utilise l'opérateur << surchargé de la classe spécifique
      } else if (parcelle->getType() == "ZA") {
        cout << dynamic_cast<ZA &>(*parcelle) << endl;  // Utilise l'opérateur << surchargé de la classe spécifique
      } else if (parcelle->getType() == "ZAU") {
        cout << dynamic_cast<ZN &>(*parcelle) << endl;  // Utilise l'opérateur << surchargé de la classe spécifique
      }
    }

    cout << endl << "Surface totale de la carte : " << maCarte.getSurfaceTotale() << endl;

    maCarte.saveCarte("saveFile.txt");

  } else {
    cerr << "Impossible d'ouvrir le fichier." << endl;
  }
}