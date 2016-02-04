#include <iostream>
#include "integracion.h"
using namespace std;

int main() {
  variable x;
  double y=integral(
  (1+x)*(1-x)/(1+pow(x,3)),    // expresion a integrar
  0,                           // limite inferior
  2,                           // limite superior
  10000);                      // numero de intervalos
  cout<<"y=\\int_{0}^{2}\\frac{(1+x)*(1-x)}{1+pow(x,3)}dx"<<endl;
  cout<<"y="<<y<<endl;
  return 0;
}

