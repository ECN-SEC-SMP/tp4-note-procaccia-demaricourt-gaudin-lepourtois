#include <iostream>
#include "Point2D.hpp"
#include "Polygone.hpp"

using namespace std;

int main() {

  /*================================================================*/
  /*================================================================*/
  /*                          JEU DE TESTS                          */
  /*================================================================*/
  /*================================================================*/

  
  /*==========================*/
  /*    TESTING DE POINT2D    */
  /*==========================*/
  Point2D<int> pointA(2, 2);
  Point2D<float> pointB(2.5, 0.5);
  Point2D<int> pointC;
  cout << "Point A : " << pointA << endl << "Point B : " << pointB << endl << "Point C : " << pointC << endl;
  pointB.translate(pointA.getX(), pointA.getY());
  cout << "Point B translaté de point A : " << pointB << endl;
  Point2D<int> pointD(pointA); 
  cout << "Point D construit par recopie de point A : " << pointD << endl;

  /*==========================*/
  /*     TESTING POLYGONE     */
  /*==========================*/
  Polygone<float> polygoneA;
  Polygone<int> polygoneB(vector<Point2D<int>>{pointA, pointD, pointC});
  cout << "Polygone A construit par défaut : "<< polygoneA << endl;
  cout << "Polygone B vecteur de point A, C et D : " << polygoneB << endl;
  polygoneA.addPoint(pointB);
  polygoneA.addPoint(Point2D<float>(1.2, 3.0));
  polygoneA.addPoint(Point2D<float>(3.7, 2.0));
  cout << "Polygone A avec ajout de points : " << polygoneA << endl;
  polygoneA.translate(1.5, 0.5);
  cout << "Polygone A translaté de (1.5; 0.5) : " << polygoneA << endl;
  Polygone<float> polygoneC(polygoneA);
  polygoneA.translate(0.5, 0.5);
  cout << "Polygone C construit par recopie de Polygone A : " << polygoneC;
}
