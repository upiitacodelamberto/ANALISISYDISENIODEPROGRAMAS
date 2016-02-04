#include <iostream>
#include "integracion.h"
using namespace std;

int main() {
  variable x;
  double y=integral(
  pow(x,2),    // expresion a integrar
  0,                           // limite inferior
  1,                           // limite superior
  10000);                      // numero de intervalos
  cout<<"y=\\int_{0}^{1}pow(x,2)dx"<<endl;
  cout<<"y="<<y<<endl;
  return 0;
}

