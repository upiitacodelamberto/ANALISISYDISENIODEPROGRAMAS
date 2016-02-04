/** archivo integracion.h
 * Se desea escribir una biblioteca que permita el calculo de integrales 
 * definidas de expresiones. La biblioteca debe escribirse de tal forma 
 * que si se desea calcular la siguiente integral:
<latex>
\int_{0}^{2}\frac{(1+x)(1-x)}{1+x^{3}}dx
</latex>
 * Se pueda hacer escribiendo un programa principal com el siguiente:
<latex>
\begin{verbatim}
#include <iostream>
using namespace std;

int main() {
  variable x;
  double y=integral(
  (1+x)*(1-x)/(1+pow(x,3)),    // expresion a integrar
  0,                           // limite inferior
  2,                           // limite superior
  10000);                      // numero de intervalos
  cout<<"y="<<y<<endl;
  return 0;
}
\end{verbatim}
</latex>
 */

#ifndef INTEGRACION_H
#define INTEGRACION_H

#include <cmath>

//namespace integracion{
  //clase que representa una constante
  class constante{
  public:
    constante(double c):c_(c){}
    //funcion de evaluacion. Se ignira el parametro porque
    //una constante vale siempre igual.
    double valor(double) const {return c_;}
  private:
    double c_;    //valor de la constante
  };//end class constante

  //Estructura con la definicion del tipo de una expresion.
  //En principio, el tipo para  cualquier clase de expresion es 
  //dicha clase.
  template <class E>
  struct tipo_expresion { typedef E tipo;};

  //Especializacion. El tipo para una expresion de tipo double 
  //es una constante.
  template <>
  struct tipo_expresion<double> { typedef constante tipo;};

  //Especializacion. El tipo para una expresion de tipo int 
  //es una constante.
  template <>
  struct tipo_expresion<int> { typedef constante tipo;};

  //clase que representa una variable de una integral.
  class variable{
  public:
    variable(){}
    //La evaluacion de la variable devuelve en cada punto el 
    //valor de el valor evaluado.
    double valor(double x) const {return x;}
  };//end class variable

  //Clases que envuelven los operadores. Son necesarias para 
  //poder pasar los operadores como parametros a una plantilla.

  //Clase envoltorio para el operador suma
  class operador_suma{
  public:
    double operator()(double x,double y) const {return x+y;}
  };//end class operador_suma

  class operador_resta{
  public:
    double operator()(double x,double y) const {return x-y;}
  };//end class operador_resta

  //Clase envoltorio para el operador producto.
  class operador_producto{
  public:
    double operator()(double x,double y) const {return x*y;}
  };//end class operador_producto

  //Clase envoltorio para el operador division.
  class operador_division{
  public:
    double operator()(double x,double y) const {return x/y;}
  };//end class operador_division

  //Clase envoltorio para la operacion potencia.
  class operador_potencia{
  public:
    double operator()(double x,double y) const {return std::pow(x,y);}
  };//end class operador_potencia

  //Clase que representa una expresion binaria.
  template <class E1,class E2, class OP>
  class expresion_binaria{
  public:
    expresion_binaria(const E1&e1,const E2&e2):e1_(e1),e2_(e2){}
    double valor(double x) const {return OP()(e1_.valor(x),e2_.valor(x));}
  private:
    typename tipo_expresion<E1>::tipo e1_;
    typename tipo_expresion<E2>::tipo e2_;
  };//end class expresion_binaria

  //Creacion de una expresion suma.
  template <class E1,class E2>
    expresion_binaria<E1,E2,operador_suma>
    operator+(const E1&e1,const E2&e2){
      return expresion_binaria<E1,E2,operador_suma>(e1,e2);
    }

  //Creacion de una expresion resta.
  template <class E1,class E2>
  expresion_binaria<E1,E2,operador_resta>
  operator-(const E1&e1,const E2&e2){
    return expresion_binaria<E1,E2,operador_resta>(e1,e2);
  }

  //Creacion de una expresion producto.
  template <class E1,class E2>
  expresion_binaria<E1,E2,operador_producto>
  operator*(const E1&e1,const E2&e2){
    return expresion_binaria<E1,E2,operador_producto>(e1,e2);
  }

  //Creacion de una expresion division.
  template <class E1,class E2>
  expresion_binaria<E1,E2,operador_division>
  operator/(const E1&e1,const E2&e2){
    return expresion_binaria<E1,E2,operador_division>(e1,e2);
  }

  //Creacion de una expresion potencia.
  template <class E1,class E2>
  expresion_binaria<E1,E2,operador_potencia>
  pow(const E1&e1,const E2&e2){
    return expresion_binaria<E1,E2,operador_potencia>(e1,e2);
  }

  //Funcion de integracion. Toma una expresion como primer parametro,
  //el limite inferior (un double) como segundo parametro, el limite 
  //superior (un double) como tercer parametro y un int sin signo 
  //como cuarto parametro.
  template <class E>
  double integral(E e,double i,double s,unsigned d){
    double inc=(s-i)/d;
    double r=(e.valor(i)+e.valor(s))/2;
    for(double x=i+inc;x<s;x=x+inc){
      r=r+e.valor(x);
    }
    return r*inc;
  }
//};//end namespace integracion

#endif /*INTEGRACION_H*/
