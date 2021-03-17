//
// Created by hamro on 14/03/2021.
//


#include "../Libraries/Tanh.h"

double Tanh::prim(double x) {
    Tanh tanh=Tanh();
    return  (1 - tanh(x)) ;
}

double  Tanh::operator()(double x) {
   return  ((double)exp(x)-(double)exp(-x))/((double)exp(x)+(double)exp(-x))  ;

}

Tanh::Tanh() = default;

Tanh::~Tanh() = default;
