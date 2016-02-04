#include <iostream>
#include "integracion.h"
using namespace std;

int main() {
  variable x;
  double y=integral(
  x,                           // expresion a integrar
  0,                           // limite inferior
  1,                           // limite superior
  10000);                      // numero de intervalos
  cout<<"y=\\int_{0}^{1}xdx"<<endl;
  cout<<"y="<<y<<endl;
  return 0;
}


