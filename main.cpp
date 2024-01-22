#include <iostream>
#include "Point2D.hpp"
#include "Polygone.hpp"
#include "za.hpp"
#include "zau.hpp"
#include "zn.hpp"
#include "zu.hpp"

using namespace std;

void testPolygone();
void testPoint();
void testZAD();

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
  testZAD();
}

void testPoint()
{
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
  Point2D<int> pointA(2, 2);
  Point2D<float> pointB(2.5, 0.5);
  Point2D<int> pointC;
  Point2D<int> pointD(pointA);

  Polygone<int> polygone(vector<Point2D<int>>{pointA, pointD, pointC});

  ZN zn = ZN(1, string("Henry"), polygone, 0);
  cout << zn;

  ZA za = ZA(1, string("Henry"), polygone, "Blé", 0);
  cout << za;

  ZAU zau = ZAU(1, string("Henry"), polygone, 10);
  cout << zau;

  ZU zu = ZU(1, string("Henry"), polygone, 0, 10.0);
  cout << zu;
}