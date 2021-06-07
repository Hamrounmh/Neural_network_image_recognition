//
// Created by hamro on 14/03/2021.
//

#ifndef IMAGES_CLASSIFICATION_IA_TANH_H
#define IMAGES_CLASSIFICATION_IA_TANH_H
#include "Fonction_activation.h"

class Tanh : public Fonction_activation{
public:
    Tanh();
    double  prim(double);
    double operator ()(double);
    virtual ~Tanh();
};


#endif //IMAGES_CLASSIFICATION_IA_TANH_H
