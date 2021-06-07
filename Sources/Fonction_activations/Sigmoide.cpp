//
// Created by hamro on 14/03/2021.
//

#include "../../Libraries/Sigmoide.h"

Sigmoide::Sigmoide() = default;

double Sigmoide::prim(double x) {
    Sigmoide sg = Sigmoide();
    return sg(x)*(1.-sg(x));
}

double Sigmoide::operator()(double x) {
    double y = 1./(1.+(double)exp(-x));
    return y;
}

Sigmoide::~Sigmoide() {

}
